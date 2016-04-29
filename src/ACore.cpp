/*******************************************************************************
*   @author:    Milazzo Giuseppe
*               Università KORE Enna
*   @e-mail:    milazzo.ga@gmail.com
*               info@antipode-dev.org
*******************************************************************************
*   Software Licence:
*******************************************************************************
*
*   This file is part of AFramework.
*
*   AFramework is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   AFramework is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with AFramework. If not, see <http://www.gnu.org/licenses/>.
*
*   Copyright 2015, 2016 Milazzo Giuseppe
*
*/
#include <cstring>
#include "ACore.h"
AFramework::System::Segment *   AFramework::System::m_heap_head(NULL);
size_t                          AFramework::System::m_heap_size(0);
size_t                          AFramework::System::m_heap_busy(0);
size_t                          AFramework::System::m_xc32_offs(8);
bool                            AFramework::System::m_init_flag(false);

void * operator new(size_t size){
    return AFramework::System::malloc(size);
}

void * operator new[](size_t size){
    return AFramework::System::malloc(size);
}

void operator delete(void* addr){
    AFramework::System::free(addr);
}

void operator delete[](void* addr){
    AFramework::System::free(addr);
}

class AFramework::System::Segment{
    public:
        void        *   data    ();
        Segment     *   vNext   ();
        uint32_t        m_stat : 0x01;
        uint32_t        m_size : 0x1F;
        Segment     *   m_next;
};
void * AFramework::System::Segment::data(){
    /*  Per evitare di inserire nella classe un altro campo (il puntatore void  */
    /*  data) ho preferito dare direttamente l'indirizzo calcolandolo in fun-   */
    /*  zione dell'offset di memoria. Sommando 1 all'indirizzo di m_next che è  */
    /*  di tipo void * (4 bytes) mi sposto di 4 bytes in memoria, successiva-   */
    /*  mente restituisco l'indirizzo come void *.                              */
    return (reinterpret_cast<void *>(&m_next + 1));
}
AFramework::System::Segment * AFramework::System::Segment::vNext(){
    /*  Calcolo l'indirizzo virtuale a cui dovrebbe trovarsi ipoteticamente il  */
    /*  prossimo blocco: partendo da data() che fornisce la memoria utile allo  */
    /*  utilizzatore aggiungo un offset di size() bytes.                        */
    return (reinterpret_cast<Segment *>(reinterpret_cast<uint32_t>(data()) + m_size));
}

bool AFramework::System::init(size_t heapSize){
    /*  Controllo che la funzione non sia già stata chiamata                    */
    if(m_init_flag){
        /*  in questo caso restituisco false                                    */
        return false;
    }
    /*  Sottraggo alla dimensione dell'heap passata l'overhead del compilatore  */
    heapSize -= m_xc32_offs;
    /*  Provo ad allocare tutto l'heap alla testa della lista                   */
    m_heap_head = static_cast<Segment *>(std::malloc(heapSize));
    /*  Se la testa è NULL allora l'allocazione è fallita                       */
    if(!m_heap_head){
        /*  Ed in questo caso restituisco false                                 */
        return false;
    }
    /*  Se l'allocazione è riuscita setto la dimensione dell'heap reale         */
    m_heap_size = heapSize;
    /*  e azzero la memoria                                                     */
    memset(m_heap_head, 0x00, heapSize);
    /*  Imposto il blocco come libero                                           */
    m_heap_head->m_stat = 0;
    /*  Imposto la dimensione del blocco                                        */
    m_heap_head->m_size = m_heap_size - sizeof(Segment);
    /*  Aggiorno lo spazio occupato                                             */
    m_heap_busy += sizeof(Segment);
    /*  Imposto il puntatore al blocco successivo a NULL                        */
    m_heap_head->m_next = NULL;
    
    /*
        PARTE RELATIVA ALLA CODA DEI THREAD <ANCORA DA PROGETTARE>
        ...
    */
    #warning "bool AFramework::System::init(size_t heapSize) coda Thread da progettare"
    /*  Imposto il flag di avvenuta inizializzazione                            */
    m_init_flag = true;
    /*  Abilito lo scheduler                                                    */
    enableScheduler();
    /*  e restituisco true                                                      */
    return true;
}

bool AFramework::System::free(void * ptr){
    Segment *   nav = NULL;
    Segment *   pre = NULL;
    bool        flg = false;
    /*  Controllo che il framework sia stato inizializzato correttamente        */
    if(!m_init_flag){
        /*  se non è così non esiste ancora l'heap e quindi non c'è nulla da    */
        /*  liberare per cui restituisco false                                  */
        return false;
    }
    /*  Controllo che l'indirizzo non sia NULL                                  */
    if(!ptr){
        /*  in questo caso setto ritorno false                                  */
        return false;
    }
    /*  se invece tutto è stato inizializzato correttamente, disabilito lo      */
    /*  scheduler,                                                              */
    disableScheduler();
    /*  assegno la testa della lista ad un puntatore temporaneo                 */
    nav = m_heap_head;
    /*  e scorro la lista                                                       */
    while(nav){
        /*  se l'indirizzo passato corrisponde ad un indirizzo di memoria che   */
        /*  risiede nell'heap (scorro cercando una corrispondenza)              */
        if(nav->data() == ptr){
            /*  setto il blocco come libero                                     */
            nav->m_stat = 0;
            /*  aggiorno lo spazio occupato                                     */
            m_heap_busy -= nav->m_size;
            /*  cancello la memoria                                             */
            memset(nav->data(), 0x00, nav->m_size);
            /*  imposto il flag per la deframmentazione a true                  */
            flg = true;
            /*  e smetto di scorrere la lista                                   */
            break;
        }
        /*  altriment sposto il puntatore precedente e continuo a scorrere      */
        pre = nav;
        nav = nav->m_next;
    }
    /*  se ho trovato corrispondenze devo deframmentare la memoria guardando    */
    /*  i blocchi precedente e successivo                                       */
    if(flg){
        /*  per cui se il precedente blocco non è NULL (questo significa che a  */
        /*  sinistra c'è qualcosa) ed inoltre non è occupato (funziona sempre   */
        /*  per lo short-evaluation, ovvero se fallisce la prima condizione     */
        /*  il secondo confronto non viene eseguito)                            */
        if(pre && pre->m_stat == 0){
            /*  sposto il puntatore temporaneo al blocco precedente             */
            nav = pre;
            /*  ricalcolo la dimensione del blocco                              */
            nav->m_size += sizeof(Segment) + nav->m_next->m_size;
            /*  aggiorno lo spazio occupato                                     */
            m_heap_busy -= sizeof(Segment);
            /*  assegno al successivo di nav il successivo del blocco eliminato */
            nav->m_next = nav->m_next->m_next;
            /*  e pulisco la memoria                                            */
            memset(nav->data(), 0x00, nav->m_size);
        }
        /*  sempre per il discorso relativo al primo if sopra adesso devo       */
        /*  controllare a destra, infatti se questo blocco è non NULL e libero  */
        /*  devo ricompattare, per cui                                          */
        if(nav->m_next && nav->m_next->m_stat == 0){
            /*  se è così, setto la dimensione di nav calcolando la nuova       */
            nav->m_size += sizeof(Segment) + nav->m_next->m_size;
            /*  aggiorno lo spazio occupato                                     */
            m_heap_busy -= sizeof(Segment);
            /*  ed al successivo di nav assegno il prossimo successivo          */
            nav->m_next = nav->m_next->m_next;
            /*  pulisco la memoria azzerandola                                  */
            memset(nav->data(), 0x00, nav->m_size);
        }
    }
    /*  riabilito lo scheduler                                                  */
    enableScheduler();
    /*  e restituisco il valore del flag, infatti se non ho trovato corrispon-  */
    /*  denze questo sarà false, altrimenti true                                */
    return flg;
}

size_t AFramework::System::availableMemory(){
    /*  Nulla da commentare                                                     */
    return m_heap_size - m_heap_busy;
}

size_t AFramework::System::heapSize(){
    /*  Nulla da commentare...                                                  */
    return m_heap_size;
}

void * AFramework::System::malloc(size_t size){
    Segment *   nav = NULL;
    Segment *   seg = NULL;
    size_t      max = 0;
    bool        flg = false;
    /*  Controllo che l'heap sia stato inizializzato correttamente e che la di- */
    /*  mensione richiesta non sia zero                                         */
    if(!m_init_flag || !size){
        /*  se così non è restituisco NULL (non ho dove/cosa allocare!)         */
        return NULL;
    }
    /*  se la dimensione richiesta non raggiunge i 4 byte (indirizzamento a     */
    /*  32 bit)                                                                 */
    if(size % 4){
        /*  allineo il blocco al più vicino multiplo di 4 byte                  */
        size += (4 - (size % 4));
    }
    /*  Se invece è tutto ok disabilito lo scheduler                            */
    disableScheduler();
    /*  e assgno un puntatore temporaneo alla testa                             */
    nav = m_heap_head;
    /*  ed inizio a scorrere la lista                                           */
    while(nav){
        /*  se il blocco a cui sto puntando è libero                            */
        if(nav->m_stat == 0){
            /*  controllo se ne esiste uno di dimensione esatta                 */
            if(nav->m_size == size){
                /*  se trovo questo blocco lo imposto come occupato             */
                nav->m_stat = 1;
                /*  aggiorno lo spazio occupato                                 */
                m_heap_busy += size;
                /*  riabilito lo scheduler                                      */
                enableScheduler();
                /*  e restituisco il puntatore ai dati                          */
                return nav->data();
            /*  se invece il blocco ha dimensione maggiore di quella richiesta  */
            /*  ricerco il massimo tra i blocchi liberi (facendo così evito di  */
            /*  scorrere due volte la lista)                                    */
            }else if(nav->m_size > size && nav->m_size > max){
                /*  Se trovo questo blocco, imposto un flag a true              */
                flg = true;
                /*  aggiorno la dimensione del blocco massimo                   */
                max = nav->m_size;
                /*  salvo in un puntatore temporaneo l'indirizzo di detto       */
                /*  blocco                                                      */
                seg = nav;
            }
        }
        /*  altrimenti continuo a scorrere fino a che non finisco la lista      */
        nav = nav->m_next;
    }
    /*  A navigazione ultimata, se il blocco richiesto esiste il flag sarà true */
    /*  il puntatore temporaneo seg conterrà l'indirizzo del massimo, per cui   */
    if(flg){
        /*  (solo per questione di coerenza di stile lavoro di nuovo con nav)   */
        nav = seg;
        /*  imposto la dimensione a quella richiesta                            */
        nav->m_size = size;
        /*  lo imposto come come occupato                                       */
        nav->m_stat = 1;
        /*  aggiorno lo spazio occupato                                         */
        m_heap_busy += size;
        /*  successivamente imposto il blocco successivo assegnando l'indirizzo */
        /*  calcolato a seg                                                     */
        seg = nav->vNext();
        /*  imposto il blocco come libero                                       */
        seg->m_stat = 0;
        /*  imposto il puntatore al blocco successivo al successivo di nav      */
        /*  (questo indirizzo non è stato modificato)                           */
        seg->m_next = nav->m_next;
        /*  imposto la dimensione del nuovo blocco                              */
        seg->m_size = max - size - sizeof(Segment);
        /*  aggiorno lo spazio occupato                                         */
        m_heap_busy += sizeof(Segment);
        /*  imposto il successivo di nav (il blocco allocato) a seg ricostru-   */
        /*  endo la lista                                                       */
        nav->m_next = seg;
        /*  riabilito lo scheduler                                              */
        enableScheduler();
        /*  ed infine restituisco l'indirizzo dei dati                          */
        return nav->data();
    }
    /*  se invece il blocco richiesto non esiste riabilito lo scheduler         */
    enableScheduler();
    /*  e restituisco NULL                                                      */
    return NULL;
}

void AFramework::System::disableScheduler(){
    #warning "void AFramework::System::disableScheduler() non ancora implementata"
}

void AFramework::System::enableScheduler(){
    #warning "void AFramework::System::enableScheduler() non ancora implementata"
}

bool AFramework::System::enoughSpaceFor(const size_t& size, const bool& autoLock){
    Segment * nav = NULL;
    /*  controllo che il framework sia stato inizializzato correttamente        */
    if(!m_init_flag){
        /*  se così non è non ho nulla da controllare e restituisco false       */
        return false;
    }
    /*  se invece tutto è ok disabilito lo scheduler                            */
    disableScheduler();
    /*  assegno la testa della lista ad un puntatore temporanero                */
    nav = m_heap_head;
    /*  ed inizio a navigare la lista alla ricerca di un blocco di dimensione   */
    /*  abbastanza grande (faccio il confronto più lasco per velocizzare)       */
    while(nav){
        /*  se esiste abbastanza spazio                                         */
        if(nav->m_size >= size){
            /*  riabilito lo scheduler se autolock è false                      */
            if(!autoLock){
                enableScheduler();
            }
            /*  e restituisco true                                              */
            return true;
        }
        /*  altrimenti continuo a scorrere                                      */
        nav = nav->m_next;
    }
    /*  se invece il blocco di dimensione richiesta non esiste, riabilito lo    */
    /*  scheduler                                                               */
    enableScheduler();
    /*  e restituisco false                                                     */
    return false;
}
