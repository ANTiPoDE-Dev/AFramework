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

#ifndef ASTRING_H
#define ASTRING_H

#include <cstdint>

#include "AContainers.h"

namespace AFramework{
    class AString;
    
    typedef ALinkedList<AString *> AStringList;
    
    class AString{
        public:
                                static  AString         number      (const int & val);
                                static  AString         number      (const float & val, const uint32_t & prec = 3);
                                static  AString         number      (const double & val, const uint32_t & prec = 3);
                                static  uint32_t        strlen      (const char * str);
                                                        AString     ();
                                                        AString     (const AString & str);
                                                        AString     (const char * str);
                                                        AString     (const int & val);
                                                        AString     (const float & val, const uint32_t & prec = 3);
                                                        AString     (const double & val, const uint32_t & prec = 3);
                                                    ~   AString     ();
                                        bool            remove      (const AString & str, const bool & cs = false);
//                                        bool            remove      (const char * str, const bool & cs = false);
                                        bool            remove      (const char & chr, const bool & cs = false);
                                        bool            contains    (const AString & str, const bool & cs = false) const;
                                        bool            contains    (const char * str, const bool & cs = false) const;
                                        bool            contains    (const char & chr, const bool & cs = false) const;
                                        bool            compare     (const AString & str, const bool & cs = false) const;
                                        bool            compare     (const char * str, const bool & cs = false) const;
                                        bool            compare     (const char & chr, const bool & cs = false) const;
                                        bool            replace     (const AString & before, const AString & after, const bool & cs = false);
                                        bool            replace     (const char * before, const char * after, const bool & cs = false);
                                        bool            replace     (const char & before, const char & after, const bool & cs = false);
                                        int32_t         indexOf     (const AString & str, const uint32_t & index = 0, const bool & cs = false) const;
                                        int32_t         indexOf     (const char * str, const uint32_t & index = 0, const bool & cs = false) const;
                                        int32_t         indexOf     (const char & chr, const uint32_t & index = 0, const bool & cs = false) const;
                                        bool            insert      (const AString & str, const uint32_t & index);
                                        bool            insert      (const AString & str, const AString & after, const bool & cs = false);
                                        bool            insert      (const char * str, const uint32_t & index);
                                        bool            insert      (const char * str, const char * after, const bool & cs = false);
                                        bool            insert      (const char & chr, const uint32_t & index);
                                        bool            insert      (const char & chr, const char * after, const bool & cs = false);
                                        bool            append      (const AString & str);
                                        bool            append      (const char * str);
                                        bool            append      (const char & chr);
                                        bool            prepend     (const AString & str);
                                        bool            prepend     (const char * str);
                                        bool            prepend     (const char & chr);
                                        void            toLower     ();
                                        void            toUpper     ();
                                        void            reverse     ();
                                        uint32_t        size        () const;
                                        bool            isEmpty     () const;
                                        AString     *   clone       () const;
                                        bool            clear       ();
                                        char            at          (const uint32_t & index) const;
                                        bool            startsWith  (const AString & str, const bool & cs = false);
                                        bool            startsWith  (const char * str, const bool & cs = false);
                                        bool            startsWith  (const char & chr, const bool & cs = false);
                                        bool            endsWith    (const AString & str, const bool & cs = false);
                                        bool            endsWith    (const char * str, const bool & cs = false);
                                        bool            endsWith    (const char & chr, const bool & cs = false);
                                        int             toInt       (bool & ok) const;
                                        float           toFloat     (bool & ok) const;
                                        double          toDouble    (bool & ok) const;
                                        AStringList *   split       (const char & sep, const bool & keepEmpty = false, const bool & cs = false) const;
                                        char            operator[]  (const uint32_t & index) const;
                                        bool            operator==  (const AString & str) const;
                                        bool            operator==  (const char * str) const;
                                        bool            operator==  (const char & chr) const;
                                        bool            operator!=  (const AString & str) const;
                                        bool            operator!=  (const char * str) const;
                                        bool            operator!=  (const char & chr) const;
                                        bool            operator+=  (const AString & str);
                                        bool            operator+=  (const char * str);
                                        bool            operator+=  (const char & chr);
                                        bool            operator-=  (const AString & str);
                                        bool            operator-=  (const char * str);
                                        bool            operator-=  (const char & chr);
                                        AString         operator+   (const AString & str);
                                        AString         operator+   (const char * str);
                                        AString         operator+   (const char & chr);
                                        AString         operator-   (const AString & str);
                                        AString         operator-   (const char * str);
                                        AString         operator-   (const char & chr);
                                        AString     &   operator=   (const AString & str);
                                        AString     &   operator=   (const char * str);
                                        AString     &   operator=   (const char & chr);
        private:
            template <class T>  static  char        *   nta         (const T val, const uint32_t prc);
                                static  bool            ccm         (const char & ch1, const char & ch2, const bool & cs = true );
                                        char        *   m_str;
    };

    template <class T> char * AString::nta(const T val, const uint32_t prc){
        /*  Per questioni di risparmio di memoria ho preferito sviluppare la    */
        /*  funzione per la conversione dei numeri in stringa come template.    */
        /*  Utilizzando questa versione (ovvero richiamando la presente)        */
        /*  l'occupazione in memoria diminuisce del 1% sul totale (25% sulla    */
        /*  classe AString). L'algoritmo che ho sviluppato opera nel seguente   */
        /*  modo: moltiplico il numero passato per una potenza di 10 (tengo     */
        /*  queste in un vettore perchè i passaggi sono tanti, se devo mettermi */
        /*  anche a moltiplicare è finita...) dopo averne fatto il valore       */
        /*  assoluto, dopo di che considero il numero di elementi della stringa */
        /*  tramite la variabile m_dig (m_digits): nel caso il numero sia nega- */
        /*  tivo aggiungo oltre che al carattere di terminazione un elemento    */
        /*  per il segno meno, aggiungo anche se è richiesta precisione supe-   */
        /*  riore a zero un elemento per il carattere '.'. Considero poi un     */
        /*  flag che metto a true se il numero è negativo e mi serve per capire */
        /*  se aggiungere il segno meno o no                                    */
        uint32_t    m_pow[] = {0x00001, 0x0000A, 0x00064, 0x003E8, 0x02710, 0x186A0, 0xF4240 };
        uint32_t    m_raw   = (val < 0 ? -1 * val : val ) * m_pow[prc > 0x5 ? 0x6 : prc ];
        uint32_t    m_dig   = (val < 0 ?        2 : 1   ) +      (prc       ?   1 :   0 );
        uint32_t    m_tmp   =  m_raw;
        bool        m_flg   = (val < 0 ? true : false );
        char    *   m_res   = NULL;
        /*  dopo quanto detto al numero di cifre precedente (carattere termina- */
        /*  zione, eventuali punto e segno meno) il numero di cifre proprie del */
        /*  numero moltiplicato per la potenza di 10, contandole come segue:    */
        /*  fino a che il numero è diverso da zero                              */
        while(m_tmp){
            /*  riassegno al numero la sua divisione per 10                     */
            m_tmp /= 10;
            /*  ed incremento il numero di cifre                                */
            m_dig++;
        }
        /*  provo ad allocare la stringa della dimensione necessaria            */
        m_res = new char[m_dig];
        /*  se l'allocazione è andata a buon fine                               */
        if(m_res){
            /*  aggiungo subito il carattere di terminazione a fine stringa     */
            m_res[m_dig - 1] = 0x00;
            /*  se il numero era negativo                                       */
            if(m_flg){
                /*  aggiungo il segno meno                                      */
                m_res[0] = 0x2D;
            }
            /*  partendo poi dalla coda della stringa e scorrendola all'indie-  */
            /*  tro fino a 0 nel caso sia positivo o ad uno nel caso sia nega-  */
            /*  tivo                                                            */
            for(int32_t i = m_dig - 2; i >= (m_flg ? 1 : 0) ; i--){
                /*  se la precisione richiesta è diversa da zero e sono arriva- */
                /*  to alla posizione dove dovrebbe stare il punto              */
                if(prc && (i == m_dig - 2 - (prc > 0x5 ? 0x6 : prc))){
                    /*  aggiungo in punto                                       */
                    m_res[i] = 0x2E;
                }else{
                    /*  altrimenti assegno il resto della divisione per 10      */
                    /*  sommato a 48 per la conversione                         */
                    m_res[i] = (m_raw % 10) + 0x30;
                    /*  e divido ancora per 10 riassegnando                     */
                    m_raw /= 10;
                }
                /*  praticamente il numero se prima era 134.444 diventa 134444  */
                /*  e tengo traccia delle cifre decimali utilizzando la preci-  */
                /*  sione passata                                               */
            }
        }
        /*  alla fine restituisco il risultato (che può anche essere NULL)      */
        return m_res;
    }
}
#endif /* ASTRING_H */
