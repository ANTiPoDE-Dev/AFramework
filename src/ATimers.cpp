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

#include "ATimers.h"
#include "AErrorNotifier.h"

#define ON_BIT  0x00008000U
#define TCS_BIT 0x00000002U

#ifdef ANTIPODE32MR

//volatile AFramework::AUniqueTimer   AFramework::Timer1 __attribute__((address(0xBF800600)));
//volatile AFramework::ACascadedTimer AFramework::Timer2 __attribute__((address(0xBF800800)));
//volatile AFramework::ACascadedTimer AFramework::Timer3 __attribute__((address(0xBF800A00)));
//volatile AFramework::ACascadedTimer AFramework::Timer4 __attribute__((address(0xBF800C00)));
//volatile AFramework::ACascadedTimer AFramework::Timer5 __attribute__((address(0xBF800E00)));

#endif

AFramework::AAbstractTimer::AAbstractTimer() : m_TxCON_CLR(Quick::All),
                                               m_TMRx_CLR(Quick::All),
                                               m_PRx_CLR(Quick::All){

}

void AFramework::AAbstractTimer::close() volatile{
    /*  spengo il timer e cancello tutti i bit                                  */
    m_TxCON_CLR = Quick::All;
    /*  pulisco il registro TMRx                                                */
    m_TMRx_CLR  = Quick::All;
    /*  pulisco il registro PRx                                                 */
    m_PRx_CLR   = Quick::All;
}

void AFramework::AAbstractTimer::clear() volatile{
    /*  azzero il registro TMRx                                                 */
    m_TMRx_CLR = Quick::All;
}

bool AFramework::AAbstractTimer::isOpen() const volatile{
    /*  ritorno l'and con il bit on                                             */
    return (m_TxCON & ON_BIT);
}

AFramework::uint32 AFramework::AAbstractTimer::rawTime() const volatile{
    /*  ritorno il contenuto del registro TMRx                                  */
    return m_TMRx;
}

AFramework::uint32 AFramework::AAbstractTimer::elapsedTime() const volatile{
    /*  ritorno il periodo di sistema moltiplicato il prescaler per il conte-   */
    /*  nuto del registro TMRx                                                  */
    #warning "AFramework::uint32 AFramework::AAbstractTimer::elapsedTime() const volatile FUNZIONA SOLO CON IL CLOCK INTERNO"
    return (System::priPeriod() * prescaler() * m_TMRx);    
}

double AFramework::AAbstractTimer::period() const volatile{
    /*  se il timer ha sorgente di clock esterna                                */
    if(m_TxCON & TCS_BIT){
        return 0;
    }
    /*  altimenti ritorno il periodo di sistema moltiplicato il prescaler per   */
    /*  il contenuto del registro PRx                                           */
    #warning "double AFramework::AAbstractTimer::period() const volatile FUNZIONA SOLO CON IL CLOCK INTERNO"
    return (System::priPeriod() * prescaler() * m_PRx);
}

double AFramework::AAbstractTimer::frequency() const volatile{
    /*  se il timer ha sorgente di clock esterna                                */
    if(m_TxCON & TCS_BIT){
        return 0;
    }
    /*  altimenti ritorno l'inverso del periodo                                 */
    return (1 / period());
}

AFramework::ATimer1::ATimer1() : AAbstractTimer(){
    /*  Nulla da commentare                                                     */
}

bool AFramework::ATimer1::open(const double period) volatile{
    
}

bool AFramework::ATimer1::open(const double period, const Timer1ClockSource src = System, const bool idleStop = false) volatile{
    uint32 prescalers[4] = {0x0001U, 0x0008U, 0x0040U, 0x0100U};
    /*  se il timer è già aperto                                                */
    if(isOpen()){
        /*  lo chiudo                                                           */
        close();
    }
    /*  Il timer funziona che ad ogni colpo di clock incrementa di uno il       */
    /*  registro TMRx, quando TMRx matcha con PRx, TMR viene azzerato e tutto   */
    /*  ricomincia.. Il clock può essere prelevato a dall'oscillatore esterno   */
    /*  o interno o da un segnale esterno, nel caso di clock interno il periodo */
    /*  in secondi è dato da:                                                   */
    /*             1                                                            */
    /*      Ts = ----- x PS x PRx                                               */
    /*            Fpb                                                           */
    /*  dove Ts è il periodo in secondi Fpb la frequenza del bus delle perife-  */
    /*  riche, PS il prescaler e PRx il periodo da matchare. Ricavando PRx e    */
    /*  sostituendo l'inverso di Fpb con il periodo di sistema Tpb si ottiene:  */
    /*            Ts                                                            */
    /*  PRx = ----------                                                        */
    /*         Tpb x PS                                                         */
    /*  per cui calcolo con i vari prescaler e scelgo quello con l'errore più   */
    /*  piccolo                                                                 */
    #warning "QUESTA E' DA testare scrupolosamente!!!"
    /*  se la sorgente di clock è di sistema                                    */
    if(src == System){
        
    }
}