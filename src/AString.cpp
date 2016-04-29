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
#include "AString.h"
#include "ACore.h"

AFramework::AString AFramework::AString::number(const int& val){
    AString m_res;
    /*  nulla da commentare                                                     */
    m_res.m_str = nta(val, 0);
    return m_res;
}

AFramework::AString AFramework::AString::number(const float& val, const uint32_t& prec){
    AString m_res;
    /*  nulla da commentare                                                     */
    m_res.m_str = nta(val, prec);
    return m_res;
}

AFramework::AString AFramework::AString::number(const double& val, const uint32_t& prec){
    AString m_res;
    /*  nulla da commentare                                                     */
    m_res.m_str = nta(val, prec);
    return m_res;
}

uint32_t AFramework::AString::strlen(const char * val){
    uint32_t m_res = 0;
    /*  se la stringa non è vuota                                               */
    if(val){
        /*  fino a che il carattere puntato è diverso da quello di terminazione */
        while(*val != 0x00){
            /*  incremento il contatore                                         */
            m_res++;
            /*  sposto avanti il puntatore                                      */
            val++;
        }
    }
    /*  ritorno il risultato                                                    */
    return m_res;
}

AFramework::AString::AString() : m_str(NULL) {
    /*  Nulla da commentare                                                     */
}

AFramework::AString::AString(const AString& str) : AString(str.m_str){
    /*  nulla da commentare                                                     */
}

AFramework::AString::AString(const char * str) : AString(){
    uint32_t m_dim = 0;
    /*  calcolo la dimnesione della stringa                                     */
    m_dim = 1 + strlen(str);
    /*  se la stringa non è vuota                                               */
    if(m_dim != 1){
        /*  provo ad allocare                                                   */
        m_str = new char[m_dim];
        /*  se l'allocazione è andata a buon fine                               */
        if(m_str){
            /*  scorro tutta la stringa                                         */
            for(uint32_t i = 0; i < m_dim; i++){
                /*  e copio ogni elemento                                       */
                m_str[i] = str[i];
            }
        }
    }
}

AFramework::AString::AString(const int & val) : AString(){
    /*  Nulla da commentare                                                     */
    m_str = nta(val, 0);
}

AFramework::AString::AString(const float & val, const uint32_t & prec) : AString(){
    /*  Nulla da commentare                                                     */
    m_str = nta(val, prec);
}

AFramework::AString::AString(const double & val, const uint32_t & prec) : AString(){
    /*  Nulla da commentare                                                     */
    m_str = nta(val, prec);
}

AFramework::AString::~AString(){
    /*  nulla da commentare                                                     */
    clear();
}

bool AFramework::AString::remove(const AString & str, const bool & cs){
    /*  nulla da commentare                                                     */
    return remove(str.m_str, cs);
}
bool AFramework::AString::remove(const char * str, const bool & cs){
    uint32_t    m_dim = 0;
    uint32_t    m_tmp = 0;
    int32_t     m_ind = 0;
    char    *   m_new = NULL;
    /*  calcolo la dimensione del nuovo vettore                                 */
    m_dim = 1 + size() - strlen(str);
    /*  cerco l'indice della sotto-stringa                                      */
    m_ind = indexOf(str, 0, cs);
    /*  se non ho trovato la stringa da eliminare                               */
    if(m_ind == -1){
        /* ritorno false */
        return false;
    }
    /*  provo ad allocare il nuovo vettore                                      */
    m_new = new char[m_dim];
    /*  se l'allocazione è fallita                                              */
    if(!m_new){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se sono arrivato qui senza intoppi è tutto ok, per cui inizio la rimo-  */
    /*  zione                                                                   */
    for(uint32_t i = 0; i < m_dim - 1; i++){
        /*  se l'indice corrente corrisponde alla posizione che non deve        */
        /*  essere copiata                                                      */
        if(i == m_ind){
            /*  aggiungo l'offset della lunghezza della stringa                 */
            m_tmp += strlen(str);
        }
        /*  copio i caratteri                                                   */
        m_new[i] = m_str[m_tmp++];
    }
    /*  aggiungo la terminazione                                                */
    m_new[m_dim - 1] = 0x00;
    /*  libero la memoria                                                       */
    delete [] m_str;
    /*  riassegno il puntatore                                                  */
    m_str = m_new;
    /*  ritorno true                                                            */
    return true;    
}

bool AFramework::AString::remove(const char & chr, const bool & cs){
    uint32_t    m_dim = 0;
    uint32_t    m_tmp = 0;
    int32_t     m_ind = 0;
    char    *   m_new = NULL;
    /*  calcolo la dimensione della nuova stringa                               */
    m_dim = size();
    /*  cerco l'indice del carattere                                            */
    m_ind = indexOf(chr, 0, cs);
    /*  se non ho trovato il carattere                                          */
    if(m_ind == -1){
        /*  ritorno false                                                       */
        return false;
    }
    /*  provo ad allocare                                                       */
    m_new = new char[m_dim];
    /*  se l'allocazione fallisce                                               */
    if(!m_new){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se sono arrivato qui è andato tutto ok, per cui inizio la copia della   */
    /*  stringa                                                                 */
    for(uint32_t i = 0; i < m_dim - 1; i++){
        /*  se l'indice corrente corrisponde alla posizione che non deve        */
        /*  essere copiata                                                      */
        if(i == m_ind){
            /*  aggiungo l'offeset di 1 carattere                               */
            m_tmp++;
        }
        /*  copio i caratteri                                                   */
        m_new[i] = m_str[m_tmp++];
    }
    /*  aggiungo la terminazione                                                */
    m_new[m_dim - 1] = 0x00;
    /*  libero la memoria                                                       */
    delete [] m_str;
    /*  riassegno il puntatore                                                  */
    m_str = m_new;
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AString::contains(const AString & str, const bool & cs) const{
    /*  nulla da commentare                                                     */
    return (indexOf(str.m_str, 0, cs) != -1);
}

bool AFramework::AString::contains(const char * str, const bool & cs) const{
    /*  nulla da commentare                                                     */
    return (indexOf(str, 0, cs) != -1);
}

bool AFramework::AString::contains(const char & chr, const bool & cs) const{
    /*  nulla da commentare                                                     */
    return (indexOf(chr, 0, cs) != -1);
}

bool AFramework::AString::compare(const AString & str, const bool & cs) const{
    /*  nulla da commentare                                                     */
    return compare(str.m_str, cs);
}

bool AFramework::AString::compare(const char * str, const bool & cs) const{
    /*  nulla da commentare                                                     */
    if(size() != strlen(str)){
        return false;
    }
    return (indexOf(str, 0, cs) == 0);
}

bool AFramework::AString::compare(const char & chr, const bool & cs) const{
    /*  nulla da commentare                                                     */
    if(size() != 1){
        return false;
    }
    return ccm(chr, m_str[0], cs);
}

bool AFramework::AString::replace(const AString & before, const AString & after, const bool & cs){
    /*  nulla da commentare                                                     */
    return replace(before.m_str, after.m_str, cs);
}

bool AFramework::AString::replace(const char * before, const char * after, const bool & cs){
    uint32_t    m_sd1 = 0;
    uint32_t    m_sd2 = 0;
    uint32_t    m_is1 = 0;
    uint32_t    m_is2 = 0;
    int32_t     m_pos = 0;
    char    *   m_new = NULL;
    /*  calcolo la dimensione della stringa dopo la rimozione di before         */
    m_sd1 = 1 + size() - strlen(before);
    /*  calcolo la dimensione della stringa che devo inserire                   */
    m_sd2 = strlen(after);
    /*  cerco l'indice della sottostringa                                       */
    m_pos = indexOf(before, 0, cs);
    /*  se non trovo la sottostringa                                            */
    if(m_pos == -1){
        /*  ritorno false                                                       */
        return false;
    }
    /*  provo ad allocare                                                       */
    m_new = new char[m_sd1 + m_sd2];
    /*  se l'allocazione non è andata a buon fine                               */
    if(!m_new){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se sono arrivato qui è andato tutto bene, per cui copio le stringhe     */
    for(uint32_t i = 0; i < m_sd1 + m_sd2 - 1; i++){
        if(i < m_pos || i > m_pos + m_sd2){
            m_new[i] = m_str[m_is1++];
        }else{
            m_new[i] = after[m_is2++];
        }
    }
    /*  aggiungo la terminazione                                                */
    m_new[m_sd1 + m_sd2 - 1] = 0x00;
    /*  libero la memoria                                                       */
    delete [] m_str;
    /*  riassegno il puntatore                                                  */
    m_str = m_new;
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AString::replace(const char & before, const char & after, const bool & cs){
    int32_t m_pos = indexOf(before, 0, cs);
    /*  se trovo il carattere                                                   */
    if(m_pos != -1){
        /*  lo sostituisco                                                      */
        m_str[m_pos] = after;
        /*  e ritorno true                                                      */
        return true;
    }
    /*  altrimenti false                                                        */
    return false;
}

int32_t AFramework::AString::indexOf(const AString & str, const uint32_t & index, const bool & cs) const{
    /*  nulla da commentare                                                     */
    return indexOf(str.m_str, index, cs);
}

int32_t AFramework::AString::indexOf(const char * str, const uint32_t & index, const bool & cs) const{
    uint32_t m_sd1 = size();
    uint32_t m_sd2 = strlen(str);
    bool m_flg = true;
    /*  se la sottostringa da cercare è più lunga della stringa o l'indice      */
    /*  passato non permette di ricercarla                                      */
    if(!m_sd2 || m_sd2 > m_sd1 || (index + m_sd2 > m_sd1)){
        /*  ritorno -1                                                          */
        return -1;
    }
    /*  inizio a scorrere la stringa fino a quando posso fare l'ultimo confron- */
    /*  to                                                                      */
    for(int32_t i = index; i <= m_sd1 - m_sd2; i++){
        /*  esamino una sottostringa in modo simmetrico                         */
        for(int32_t j = 0; j <= m_sd2 / 2; j++){
            /*  non appena trovo differenze                                     */
            if( !ccm(str[j              ] , m_str[i + j             ] , cs) ||
                !ccm(str[m_sd2 - 1 - j  ] , m_str[m_sd2 - 1 + i - j ] , cs) ){
                /*  metto il flag a false                                       */
                m_flg = false;
                /*  e smetto di scorrere                                        */
                break;
            }
        }
        /*  se il flag è false                                                  */
        if(!m_flg){
            /*  lo metto a true pensando che se questo non viene messo a false  */
            /*  allora ho trovato la sottostringa                               */
            m_flg = true;
        /*  altrimenti se il flag è true                                        */
        }else{
            /*  restituisco l'indice                                            */
            return i;
        }
    }
    /*  altrimenti restituisco -1                                               */
    return -1;
}

int32_t AFramework::AString::indexOf(const char & chr, const uint32_t & index, const bool & cs) const{
    uint32_t m_dim = size();
    /*  inizio a scorrere la stringa dall'indice passato (se l'indice non è va- */
    /*  lido il ciclo neanche parte)                                            */
    for(int32_t i = index; i < m_dim; i++){
        /*  se trovo il carattere                                               */
        if(ccm(chr, m_str[i], cs)){
            /*  ritorno l'indice corrispondete                                  */
            return i;
        }
    }
    /*  altrimenti -1                                                           */
    return -1;
}

bool AFramework::AString::insert(const AString & str, const uint32_t & index){
    /*  nulla da commentare                                                     */
    return insert(str.m_str, index);
}

bool AFramework::AString::insert(const AString & str, const AString & after, const bool & cs){
    /*  nulla da commentare                                                     */
    return insert(str.m_str, after.m_str, cs);
}

bool AFramework::AString::insert(const char * str, const uint32_t & index){
    uint32_t    m_sd1 = size();
    uint32_t    m_sd2 = strlen(str);
    uint32_t    m_si1 = 0;
    uint32_t    m_si2 = 0;
    char    *   m_new = NULL;
    /*  se l'indice passato è maggiore della dimensione attuale                 */
    if(index > m_sd1){
        /*  ritorno false                                                       */
        return false;
    }
    /*  controllo di poter allocare la stringa                                  */
    m_new = new char[m_sd1 + m_sd2 + 1];
    /*  se l'allocazione è andata a buon fine                                   */
    if(m_new){
        /*  inizio la copia della stringhe                                      */
        for(uint32_t i = 0; i < m_sd1 + m_sd2; i++){
            /*  se sono nelle posizioni dove deve essere inserita la nuova      */
            /*  stringa                                                         */
            if(i >= index && i <= index + m_sd2 - 1){
                /*  copio quella da inserire                                    */
                m_new[i] = str[m_si2++];
            /*  altrimenti                                                      */
            }else{
                /*  ricopio la vecchia                                          */
                m_new[i] = m_str[m_si1++];
            }
        }
        /*  aggiungo la terminazione                                            */
        m_new[m_sd1 + m_sd2] = 0x00;
        /*  cancello la vecchia stringa                                         */
        delete [] m_str;
        /*  riassegno la nuova                                                  */
        m_str = m_new;
        /*  ritorno true                                                        */
        return true;
    }
    /*  in questo caso è fallita l'allocazione per cui ritorno false            */
    return false;
}

bool AFramework::AString::insert(const char * str, const char * after, const bool & cs){
    int32_t m_index = indexOf(after, 0, cs);
    /*  se non ho trovato occorrenze della sottostringa                         */
    if(m_index == -1){
        /*  ritorno false                                                       */
        return false;
    }
    /*  aggiungo la posizione corretta                                          */
    m_index += strlen(after);
    return insert(str, m_index);
}

bool AFramework::AString::insert(const char & chr, const uint32_t & index){
    uint32_t    m_dim = 2 + size();
    uint32_t    m_ind = 0;
    char    *   m_new = NULL;
    /*  se l'indice è fuori range                                               */
    if(index > size()){
    /*  ritorno false                                                           */
        return false;
    }
    /*  provo ad allocare un nuovo vettore                                      */
    m_new = new char[m_dim];
    /*  se l'allocazione è andata a buon fine                                   */
    if(m_new){
        /*  inizio la copia                                                     */
        for(uint32_t i = 0; i < m_dim - 1; i++){
            /*  inserisco i vari caratteri a seconda che sia nel posto giusto o */
            /*  no                                                              */
            m_new[i] = (i == index ? chr : m_str[m_ind++]);
        }
        /*  inserirsco il carattere di terminazione                             */
        m_new[m_dim - 1] = 0x00;
        /*  libero la memoria                                                   */
        delete [] m_str;
        /*  riassegno il puntatore                                              */
        m_str = m_new;
        /*  ritorno true                                                        */
        return true;
    }
    /*  altrimenti ritorno false                                                */
    return false;
}

bool AFramework::AString::insert(const char & chr, const char * after, const bool & cs){
    /*  nulla da commentare                                                     */
    return insert(chr, indexOf(after, 0, cs) + strlen(after));
}

bool AFramework::AString::append(const AString & str){
    /*  nulla da commentare                                                     */
    return append(str.m_str);
}

bool AFramework::AString::append(const char * str){
    /*  nulla da commentare                                                     */
    return insert(str, size());
}

bool AFramework::AString::append(const char & chr){
    /*  nulla da commentare                                                     */
    return insert(chr, size());
}

bool AFramework::AString::prepend(const AString & str){
    /*  nulla da commentare                                                     */
    return prepend(str.m_str);
}

bool AFramework::AString::prepend(const char * str){
    /*  nulla da commentare                                                     */
    int i = 0;
    return insert(str, i);
}

bool AFramework::AString::prepend(const char & chr){
    /*  nulla da commentare                                                     */
    int i = 0;
    return insert(chr, i);
}

void AFramework::AString::toLower(){
    char * m_tmp = m_str;
    /*  se la stringa non è vuota                                               */
    if(m_tmp){
        /*  fino a che non trovo il carattere di terminazione                   */
        while(*m_tmp != 0x00){
            /*  se il carattere puntato è compreso tra A e Z                    */
            if(*m_tmp >= 0x41 && *m_tmp <= 0x5A){
                /*  sommo 32 ed ottengo il minuscolo                            */
                *m_tmp += 0x20;
            }
            /*  incremento il puntatore                                         */
            m_tmp++;
        }
    }
}

void AFramework::AString::toUpper(){
    char * m_tmp = m_str;
    /*  se la stringa non è vuota                                               */
    if(m_tmp){
        /*  fino a che non trovo il carattere di terminazione                   */
        while(*m_tmp != 0x00){
            /*  se il carattere puntato è compreso tra a e z                    */
            if(*m_tmp >= 0x61 && *m_tmp <= 0x7A){
                /*  sottraggo 32 ed ottengo il maiuscolo                        */
                *m_tmp -= 0x20;
            }
            /*  incremento il puntatore                                         */
            m_tmp++;
        }
    }
}

void AFramework::AString::reverse(){
    char        m_temp = 0x00;
    uint32_t    m_size = size();
    /*  scorro la stringa fino a metà (se la stringa è vuota non succede nulla) */
    for(uint32_t i = 0; i < m_size / 2; i++){
        /*  copio temporaneamente l'ultimo i-esimo elemento                     */
        m_temp = m_str[m_size - 1 - i];
        /*  sostituisco l'ultimo i-esimo con l'i-esimo                          */
        m_str[m_size - 1 - i] = m_str[i];
        /*  sostituisco l'i-esimo con la copia dell'ultimo i-esimo              */
        m_str[i] = m_temp;
    }
}

uint32_t AFramework::AString::size() const{
    /*  nulla da commentare                                                     */
    return strlen(m_str);
}

bool AFramework::AString::isEmpty() const{
    /*  nulla da commentare                                                     */
    return !size();
}

AFramework::AString * AFramework::AString::clone() const{
    AString     *   m_new = NULL;
    uint32_t        m_dim = 1 + size();
    /*  provo ad allocare una nuova stringa                                     */
    m_new = new AString();
    /*  se l'allocazione è andata a buon fine                                   */
    if(m_new){
        /*  se la stringa non è vuota                                           */
        if(m_str){
            /*  provo ad allocare il vettore                                    */
            m_new->m_str = new char[m_dim];
            /*  se l'allocazione è andata a buon fine                           */
            if(m_new->m_str){
                /*  effettuo la copia                                           */
                for(uint32_t i = 0; i < m_dim; i++){
                    m_new->m_str[i] = m_str[i];
                }
            }else{
                /*  Altrimenti faccio rollback, cancello la nuova stringa       */
                delete m_new;
                /*  e metto a NULL                                              */
                m_new = NULL;
            }
        }
    }
    /*  ritorno il puntatore alla stringa                                       */
    return m_new;
}

bool AFramework::AString::clear(){
    /*  nulla da commentare                                                     */
    if(!m_str){
        return false;
    }
    delete [] m_str;
    return true;
}

char AFramework::AString::at(const uint32_t& index) const{
    /*  se la stringa è vuota oppure sono andato fuori range                    */
    if(!m_str || index > size()){
        /*  ritorno il carattere di terminazione                                */
        return 0x00;
    }
    /*  altrimenti l'indice corrispondete                                       */
    return m_str[index];
}

bool AFramework::AString::startsWith(const AString & str, const bool & cs){
    /*  nulla da commentare                                                     */
    return startsWith(str.m_str, cs);
}

bool AFramework::AString::startsWith(const char * str, const bool & cs){
    /*  nulla da commentare                                                     */
    return (indexOf(str, 0, cs) == 0);
}

bool AFramework::AString::startsWith(const char & chr, const bool & cs){
    /*  nulla da commentare                                                     */
    return (indexOf(chr, 0, cs) == 0);
}

bool AFramework::AString::endsWith(const AString & str, const bool & cs){
    /*  nulla da commentare                                                     */
    return endsWith(str.m_str, cs);
}

bool AFramework::AString::endsWith(const char * str, const bool & cs){
    /*  nulla da commentare                                                     */
    uint32_t m_dim = size() - strlen(str);
    return ((indexOf(str, m_dim, cs) == m_dim));
}

bool AFramework::AString::endsWith(const char & chr, const bool & cs){
    /*  se la stringa è vuota                                                   */
    if(isEmpty()){
        /*  ovviamente ritorno false                                            */
        return false;
    }
    /*  altrimenti confronto l'ultimo carattere                                 */
    return ccm(chr, m_str[size() - 1], cs);
}

int AFramework::AString::toInt(bool & ok) const{
    char    *   m_tmp = m_str;
    int32_t     m_sig = 1;
    int32_t     m_res = 0;
    /*  metto il flag a false                                                   */
    ok = false;
    /*  se la stringa non è vuota                                               */
    if(m_tmp){
        /*  se il primo carattere è un meno o un più                            */
        if(*m_tmp == 0x2D || *m_tmp == 0x2B){
            /*  imposto il segno                                                */
            m_sig = (*m_tmp == 0x2D ? -1 : 1);
            /*  incremento il puntatore                                         */
            m_tmp++;
        }
        /*  fino a che non sono alla fine                                       */
        while(*m_tmp){
            /*  non appena trovo un carattere che non sia numerico              */
            if(*m_tmp < 0x30 || *m_tmp > 0x39){
                /*  ritorno zero con il flag ok a false                         */
                ok = false;
                return 0;
            /*  se invece il carattere è numerico                               */
            }else{
                /*  metto il flag a true e accodo le cifre                      */
                ok = true;
                m_res = (m_res * 10) + static_cast<int>(*m_tmp - 0x30);
            }
            /*  sposto in avanti il puntatore                                   */
            m_tmp++;
        }
    }
    /*  ritorno il valore                                                       */
    return m_sig * m_res;
}

float AFramework::AString::toFloat(bool & ok) const{
    char    *   m_tmp = m_str;
    int32_t     m_sig = 1;
    float       m_res = 0;
    uint32_t    m_dot = 0;
    uint32_t    m_stp = 0;
    /*  metto il flag a false                                                   */
    ok = false;
    /*  se la stringa non è vuota                                               */
    if(m_tmp){
        /*  se il primo carattere è un meno o un più                            */
        if(*m_tmp == 0x2D || *m_tmp == 0x2B){   
            /*  imposto il segno                                                */
            m_sig = (*m_tmp == 0x2D ? -1 : 1);
            /*  incremento il puntatore                                         */
            m_tmp++;
        }
        /*  fino a che non sono alla fine                                       */
        while(*m_tmp){
            /*  incremento il numero di step                                    */
            m_stp++;
            /*  se il carattere non è numerico                                  */
            if((*m_tmp < 0x30 || *m_tmp > 0x39)){
                /*  se è un punto o una virgola e non ne ho trovati altri prima */
                /*  e inoltre non è neanche il primo carattere                  */
                if((*m_tmp == 0x2C || *m_tmp == 0x2E) && (m_stp != 1) && !m_dot){
                    /*  tengo traccia di dove ho trovato il punto               */
                    m_dot = m_stp;
                /*  altrimenti                                                  */
                }else{
                    /*  ritorno zero con il flag ok a false                     */
                    ok = false;
                    return 0;
                }
            /*  se invece il carattere è numerico                               */
            }else{
                /*  metto il flag a true e accodo le cifre                      */
                ok = true;
                m_res = (m_res * 10) + static_cast<int>(*m_tmp - 0x30);
            }
            /*  sposto in avanti il puntatore                                   */
            m_tmp++;
        }
    }
    /*  imposto per quante volte devo dividere per 10                           */
    m_dot = (m_dot ? m_stp - m_dot : 0);
    /*  effettuo la divisione                                                   */
    while(m_dot){
        m_dot--;
        m_res /= 10;
    }
    /*  ritorno il valore                                                       */
    return m_sig * m_res;
}

double AFramework::AString::toDouble(bool & ok) const{
    char    *   m_tmp = m_str;
    int32_t     m_sig = 1;
    double      m_res = 0;
    uint32_t    m_dot = 0;
    uint32_t    m_stp = 0;
    /*  metto il flag a false                                                   */
    ok = false;
    /*  se la stringa non è vuota                                               */
    if(m_tmp){
        /*  se il primo carattere è un meno o un più                            */
        if(*m_tmp == 0x2D || *m_tmp == 0x2B){
            /*  imposto il segno                                                */
            m_sig = (*m_tmp == 0x2D ? -1 : 1);
            /*  incremento il puntatore                                         */
            m_tmp++;
        }
        /*  fino a che non sono alla fine                                       */
        while(*m_tmp){
            /*  incremento il numero di step                                    */
            m_stp++;
            /*  se il carattere non è numerico                                  */
            if((*m_tmp < 0x30 || *m_tmp > 0x39)){
                /*  se è un punto o una virgola e non ne ho trovati altri prima */
                /*  e inoltre non è neanche il primo carattere                  */
                if((*m_tmp == 0x2C || *m_tmp == 0x2E) && (m_stp != 1) && !m_dot){
                    /*  tengo traccia di dove ho trovato il punto               */
                    m_dot = m_stp;
                /*  altrimenti                                                  */
                }else{
                    /*  ritorno zero con il flag ok a false                     */
                    ok = false;
                    return 0;
                }
            /*  se invece il carattere è numerico                               */
            }else{
                /*  metto il flag a true e accodo le cifre                      */
                ok = true;
                m_res = (m_res * 10) + static_cast<int>(*m_tmp - 0x30);
            }
            /*  sposto in avanti il puntatore                                   */
            m_tmp++;
        }
    }
    /*  imposto per quante volte devo dividere per 10                           */
    m_dot = (m_dot ? m_stp - m_dot : 0);
    /*  effettuo la divisione                                                   */
    while(m_dot){
        m_dot--;
        m_res /= 10;
    }
    /*  ritorno il valore                                                       */
    return m_sig * m_res;
}

AFramework::AStringList * AFramework::AString::split(const char & sep, const bool &keepEmpty, const bool & cs) const{
    AStringList * m_list = NULL;
    uint32_t m_tdim = 0;
    uint32_t m_tind = 0;
    int32_t m_prev = 0;
    int32_t m_next = -1;
    int32_t m_temp = 0;
    AString * m_item = NULL;
    /*  provo ad allocare la StringList                                         */
    m_list = new AStringList();
    /*  se la lista è stata allocata correttamente                              */
    if(m_list){
        /*  cerco tutti gli indici dove trovo il separatore indicato            */
        while((m_next = indexOf(sep, m_prev, cs)) != -1){
            /*  se l'indice non è cambiato (nel senso che ho iniziato con un un */
            /*  separatore                                                      */
            if(m_next == m_prev){
                /*  sposto l'indice in avanti                                   */
                m_prev++;
                /*  e continuo a cercare                                        */
                continue;
            }
            /*  per evitare di fare casini con gli indici copio m_next su un    */
            /*  altra variabile posizionandomi una posizione prima del separa-  */
            /*  tore                                                            */
            m_temp = m_next - 1;
            /*  in questo caso quindi m_next e m_prev sono diversi, m_prev è    */
            /*  l'indice dove inizia il token mentre m_next è l'indice del se-  */
            /*  paratore successivo. Adesso la politica dipende da keepEmpty    */
            /*  Se keepEmpty è true copio il token per come lo trovo, mentre    */
            /*  se keepEmpty è false                                            */
            if(!keepEmpty){
                /*  devo riscalare gli indici fino a quando non trovo caratteri */
                /*  per cui porto m_prev in avanti                              */
                while(m_str[m_prev] == 0x20 && m_prev < m_next){
                    m_prev++;
                }
                /*  se sono andato avanti fino a raggiungere m_next vuol dire   */
                /*  che tutto il token è fatto da caratteri non stampabili per  */
                /*  cui va ignorato                                             */
                if(m_next == m_prev){
                    /*  quindi sposto l'indice in avanti                        */
                    m_prev++;
                    /*  e continuo a cercare                                    */
                    continue;
                }
                /*  se sono arrivato qui vuol dire che tra m_prev ed m_next ci  */
                /*  sono caratteri, per cui posso tranquillamente scorrere a    */
                /*  ritroso senza avere paura di bucare l'array                 */
                while(m_str[m_temp] == 0x20){
                    m_temp--;
                }
            }
            /* calcolo la dimensione */
            m_tdim = 2 + m_temp - m_prev;
            /* provo ad allocare la stringa */
            m_item = new AString();
            /* se l'allocazione non è andata a buon fine */
            if(!m_item){
                /* faccio rollback, elimino tutto e purtoppo torno null */
                delete m_list;
                return NULL;
            }
            /* provo ad allocare il vettore per la stringa */
            m_item->m_str = new char[m_tdim];
            /* se l'allocazione non è andata a buon fine */
            if(!(m_item->m_str)){
                /* faccio rollback, elimino tutto e purtroppo torno null */
                delete m_item;
                delete m_list;
                return NULL;
            }
            /* copio il token */
            for(uint32_t i = m_prev; i <= m_temp; i++){
                m_item->m_str[m_tind++] = m_str[i];
            }
            /* aggiungo la terminazione */
            m_item->m_str[m_tdim - 1] = 0x00;
            /* se fallisce l'append */
            if(!(m_list->append(m_item))){
                /* al solito rollback e torno null */
                delete m_item;
                delete m_list;
                return NULL;
            }
            /* azzero l'indice per la copia */
            m_tind = 0;
            /* sposto in avanti l'indice */
            m_prev = 1 + m_next;
        }
    }
    return m_list;
}

char AFramework::AString::operator[](const uint32_t & index) const{
    /*  nulla da commentare                                                     */
    return at(index);
}

bool AFramework::AString::operator==(const AString & str) const{
    /*  nulla da commentare                                                     */
    return compare(str);
}

bool AFramework::AString::operator==(const char * str) const{
    /*  nulla da commentare                                                     */
    return compare(str);
}

bool AFramework::AString::operator==(const char & chr) const{
    /*  nulla da commentare                                                     */
    return compare(chr);
}

bool AFramework::AString::operator!=(const AString & str) const{
    /*  nulla da commentare                                                     */
    return !compare(str);
}

bool AFramework::AString::operator!=(const char * str) const{
    /*  nulla da commentare                                                     */
    return !compare(str);
}

bool AFramework::AString::operator!=(const char & chr) const{
    /*  nulla da commentare                                                     */
    return !compare(chr);
}

bool AFramework::AString::operator+=(const AString & str){
    /*  nulla da commentare                                                     */
    return append(str);
}

bool AFramework::AString::operator+=(const char * str){
    /*  nulla da commentare                                                     */
    return append(str);
}

bool AFramework::AString::operator+=(const char & chr){
    /*  nulla da commentare                                                     */
    return append(chr);
}

bool AFramework::AString::operator-=(const AString & str){
    /*  nulla da commentare                                                     */
    return remove(str);
}

bool AFramework::AString::operator-=(const char * str){
    /*  nulla da commentare                                                     */
    return remove(str);
}

bool AFramework::AString::operator-=(const char & chr){
    /*  nulla da commentare                                                     */
    return remove(chr);
}

AFramework::AString AFramework::AString::operator+(const AString & str){
    /*  nulla da commentare                                                     */
    return operator+(str.m_str);
}

AFramework::AString AFramework::AString::operator+(const char * str){
    AString m_res = *this;
    /*  nulla da commentare                                                     */
    m_res.append(str);
    return m_res;
}

AFramework::AString AFramework::AString::operator+(const char & chr){
    AString m_res = *this;
    /*  nulla da commentare                                                     */
    m_res.append(chr);
    return m_res;
}

AFramework::AString AFramework::AString::operator-(const AString & str){
    /*  nulla da commentare                                                     */
    return operator-(str.m_str);
}

AFramework::AString AFramework::AString::operator-(const char * str){
    AString m_res = *this;
    /*  nulla da commentare                                                     */
    m_res.remove(str);
    return m_res;
}

AFramework::AString AFramework::AString::operator-(const char & chr){
    AString m_res = *this;
    /*  nulla da commentare                                                     */
    m_res.remove(chr);
    return m_res;
}

AFramework::AString & AFramework::AString::operator=(const AString & str){
    /*  nulla da commentare                                                     */
    return operator=(str.m_str);
}

AFramework::AString & AFramework::AString::operator=(const char * str){
    uint32_t m_dim = 1 + strlen(str);
    char * m_new = new char[m_dim];
    /*  se sono riuscito ad allocare la memoria                                 */
    if(m_new){
        /*  cancello la vecchia stringa                                         */
        clear();
        /* per tutta la lunghezza di str                                        */
        for(uint32_t i = 0; i < m_dim; i++){
            /*  ricopio i caratteri                                             */
            m_new[i] = str[i];
        }
        /*  riassegno il puntatore                                              */
        m_str = m_new;
    }
    /*  ritorno l'oggetto corrente                                              */
    return *this;
}

AFramework::AString & AFramework::AString::operator=(const char & chr){
    char * m_new = new char[2];
    /*  se sono riuscito ad allocare la memoria                                 */
    if(m_new){
        /*  cancello la vecchia stringa                                         */
        clear();
        /*  copio il carattere                                                  */
        m_new[0] = chr;
        /*  inserisco la terminazione                                           */
        m_new[1] = 0x00;
        /*  riassegno il puntatore                                              */
        m_str = m_new;
    }
    /*  ritorno l'oggetto corrente                                              */
    return *this;
}

bool AFramework::AString::ccm(const char & ch1, const char & ch2, const bool & cs){
    bool m_ch1 = (ch1 >= 0x41 && ch1 <= 0x5A) || (ch1 >= 0x61 && ch1 <= 0x7A);
    bool m_ch2 = (ch2 >= 0x41 && ch2 <= 0x5A) || (ch2 >= 0x61 && ch2 <= 0x7A);
    bool m_res = (ch1 == ch2);
    /*  se il confronto non è case sensitive e ch1 e ch2 sono caratteri         */
    if(!cs && m_ch1 && m_ch2){
        m_res = (ch1 == ch2) || (ch1 == ch2 + 0x20) || (ch1 == ch2 - 0x20);
    }
    return m_res;
}
