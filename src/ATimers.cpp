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

#include <limits>
#include <cmath>

#if   defined (__32MX__)

#   define _TxCON_ON_POSITION          0x0000000F
#   define _TxCON_ON_MASK              0x00008000
#   define _TxCON_ON_LENGTH            0x00000001

#   define _TxCON_SIDL_POSITION        0x0000000D
#   define _TxCON_SIDL_MASK            0x00002000
#   define _TxCON_SIDL_LENGTH          0x00000001

#   define _TxCON_TWDIS_POSITION       0x0000000C
#   define _TxCON_TWDIS_MASK           0x00001000
#   define _TxCON_TWDIS_LENGTH         0x00000001

#   define _TxCON_TWIP_POSITION        0x0000000B
#   define _TxCON_TWIP_MASK            0x00000800
#   define _TxCON_TWIP_LENGTH          0x00000001

#   define _TxCON_TGATE_POSITION       0x00000007
#   define _TxCON_TGATE_MASK           0x00000080
#   define _TxCON_TGATE_LENGTH         0x00000001

#   define _TxCON_16_TCKPS_POSITION    0x00000004
#   define _TxCON_16_TCKPS_MASK        0x00000030
#   define _TxCON_16_TCKPS_LENGTH      0x00000002

#   define _TxCON_32_TCKPS_POSITION    0x00000004
#   define _TxCON_32_TCKPS_MASK        0x00000070
#   define _TxCON_32_TCKPS_LENGTH      0x00000003

#   define _TxCON_T32_POSITION         0x00000003
#   define _TxCON_T32_MASK             0x00000008
#   define _TxCON_T32_LENGTH           0x00000001

#   define _TxCON_TSYNC_POSITION       0x00000002
#   define _TxCON_TSYNC_MASK           0x00000004
#   define _TxCON_TSYNC_LENGTH         0x00000001

#   define _TxCON_TCS_POSITION         0x00000001
#   define _TxCON_TCS_MASK             0x00000002
#   define _TxCON_TCS_LENGTH           0x00000001

    class AFramework::ATMR_w{
        public:
            volatile AFramework::uint32 TxCON;
            volatile AFramework::uint32 TxCON_CLR;
            volatile AFramework::uint32 TxCON_SET;
            volatile AFramework::uint32 TxCON_INV;
            volatile AFramework::uint32 TMRx;
            volatile AFramework::uint32 TMRx_CLR;
            volatile AFramework::uint32 TMRx_SET;
            volatile AFramework::uint32 TMRx_INV;
            volatile AFramework::uint32 PRx;
            volatile AFramework::uint32 PRx_CLR;
            volatile AFramework::uint32 PRx_SET;
            volatile AFramework::uint32 PRx_INV;
    };

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif


#if (__HAS_TIMER1__)
    
    extern volatile AFramework::ATMR_w TMR1_w __asm__("TMR1_w") __attribute__((section("sfrs")));
    volatile AFramework::A16bitTimer AFramework::Timer1(&TMR1_w);
    
#endif
   
#if (__HAS_TIMER3__)
    
    extern volatile AFramework::ATMR_w TMR3_w __asm__("TMR3_w") __attribute__((section("sfrs")));
    volatile AFramework::A32bitSlaveTimer  AFramework::Timer3(&TMR3_w);
    
#endif
    
#if (__HAS_TIMER5__)
    
    extern volatile AFramework::ATMR_w TMR5_w __asm__("TMR5_w") __attribute__((section("sfrs")));
    volatile AFramework::A32bitSlaveTimer  AFramework::Timer5(&TMR5_w);
    
#endif
    
#if (__HAS_TIMER2__)
    
    extern volatile AFramework::ATMR_w TMR2_w __asm__("TMR2_w") __attribute__((section("sfrs")));
    volatile AFramework::A32bitMasterTimer AFramework::Timer2(&TMR2_w, &AFramework::Timer3);
    
#endif

#if (__HAS_TIMER4__)
    
    extern volatile AFramework::ATMR_w TMR4_w __asm__("TMR4_w") __attribute__((section("sfrs")));
    volatile AFramework::A32bitMasterTimer AFramework::Timer4(&TMR4_w, &AFramework::Timer5);
    
#endif

/*
 * class AAbstract16bitTimer 
 */
AFramework::AAbstract16bitTimer::AAbstract16bitTimer(volatile ATMR_w * w) : m_treg(w), m_base(0), m_terr(0){
#if   defined (__32MX__)
    
    close();
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::setSynchronousInternal16(const double baseTime, const bool idleStop) volatile{
#if   defined (__32MX__)

    /*  uso rawcfg con l'eventuale bit di idle                                  */
    rawcfg((idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri              */
    return setpar(baseTime, System::busFrequency());

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::setSynchronousExternal16(const double extFreq, const double baseTime, const bool idleStop) volatile{
#if   defined (__32MX__)

    /*  anche se il timer di tipo b ha il settaggio automatico del bit TSYNC    */
    /*  lo passo ugualmente, alla fine dal datasheet c'e' scritto che nei timer */
    /*  di tipo b questo bit e' non implementato per cui anche se ci scrivo non */
    /*  dovrebbe succedere nulla                                                */
    rawcfg(_TxCON_TSYNC_MASK | _TxCON_TCS_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri              */
    return setpar(baseTime, extFreq);

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::setGated16(const double baseTime, bool idleStop){
#if   defined (__32MX__)
    
    /*  uso rawcfg impostando la modalita' gated, il bit di sync e l'eventuale  */
    /*  bit di idle                                                             */
    rawcfg(_TxCON_TGATE_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  setto i parametri e ritorno l'errore                                    */
    return setpar(baseTime, System::busFrequency());

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

bool AFramework::AAbstract16bitTimer::open() volatile{
#if   defined (__32MX__)
    
    /*  Controllo che il timer non sia già aperto                               */
    if(isOpen()){
        /*  in questo caso ritorno false                                        */
        return false;
    }
    /*  Altrimenti setto il bit on nel registro                                 */
    m_treg->TxCON_SET = _TxCON_ON_MASK;
    /*  ritorno true                                                            */
    return true;
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif

}

void AFramework::AAbstract16bitTimer::close() volatile{
#if   defined (__32MX__)

    /*  spengo il timer                                                         */
    m_treg->TxCON_CLR = _TxCON_ON_MASK;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

void AFramework::AAbstract16bitTimer::clear() volatile{
#if   defined (__32MX__)

    /*  azzero il registro TMRx                                                 */
    m_treg->TMRx_CLR = Quick::All;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

void AFramework::AAbstract16bitTimer::reset() volatile{
#if   defined (__32MX__)
    
    /*  spengo il timer e cancello tutti i bit                                  */
    m_treg->TxCON_CLR = Quick::All;
    /*  pulisco il registro TMRx                                                */
    m_treg->TMRx_CLR  = Quick::All;
    /*  pulisco il registro PRx                                                 */
    m_treg->PRx_CLR   = Quick::All;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

bool AFramework::AAbstract16bitTimer::isOpen() const volatile{
#if   defined (__32MX__)

    /*  ritorno l'and con il bit on                                             */
    return (m_treg->TxCON & _TxCON_ON_MASK);

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

AFramework::uint32 AFramework::AAbstract16bitTimer::rawTime() const volatile{
#if   defined (__32MX__)

    /*  ritorno il contenuto del registro TMRx                                  */
    return m_treg->TMRx;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::elapsedTime() const volatile{
#if   defined (__32MX__)

    /*  ritorno il tempo grezzo (contenuto del registro TMRx) moltiplicato il   */
    /*  tempo base                                                              */
    return (m_treg->TMRx * m_base);

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::error() const volatile{
#if   defined (__32MX__)

    /*  ritorno l'errore                                                        */
    return m_terr;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::resolution() const volatile{
#if   defined (__32MX__)

    /*  ritorno il tempo base                                                   */
    return m_base;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

void AFramework::AAbstract16bitTimer::rawcfg(const volatile uint32 b) volatile{
#if   defined (__32MX__)

    /*  resetto il timer                                                        */
    reset();
    /*  configuro per come mi vengono dati i bit                                */
    m_treg->TxCON_SET = b;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

/*
 * class A16bitTimer 
 */
AFramework::A16bitTimer::A16bitTimer(volatile ATMR_w * w) : AAbstract16bitTimer(w){
#if   defined (__32MX__)
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A16bitTimer::setAsynchronousExternal16(const double baseTime, const bool idleStop) volatile{
#if   defined (__32MX__)
#   if !(__HAS_EXTOSC__)

#       warning This board not have an external oscillator.
    
    return std::numeric_limits<double>::min();
        
#else

#   warning This function is not fully implemented.

    /*  uso rawcfg impostando la sorgente di clock esterna e l'eventuale        */
    /* bit di idle                                                              */
    rawcfg(TCS_BIT | (idleStop ? SIDL_BIT : Quick::NoOne));
    /*  setto i parametri e ritorno l'errore                                    */
    return setpar(baseTime, System::secFrequency());
        
#endif
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A16bitTimer::setpar(const double t, const double f, const bool w) volatile{
#if   defined (__32MX__)
    
    double per   = std::fabs(t);                              //  valore assoluto del periodo (non si sa mai...)
    double fre   = std::fabs(f);                              //  valore assoluto della frequenza (non si sa mai...) per il periodo
    double val   = fre * per;                                 //  frequenza per periodo (evito di fare una moltiplicazione ogni iterazione)
    double er1   = std::numeric_limits<double>::max();        //  errore iniziale (dovendo cercare il minimo metto a +inf)
    double er2   = 0;                                         //  errore temporaneo (zero va benissimo)
    uint8  PSv   = 0;                                         //  valore prescaler
    uint8  PSt   = 0;                                         //  prescaler temporaneo
    uint16 PRv   = 0;                                         //  valore periodo
    double PRt   = 0;                                         //  periodo temporaneo
    uint16 PSn[] = {0x0001, 0x0008, 0x0040, 0x0100};          //  prescaler per calcoli
    /*  inizio a cercare il minimo errore                                       */
    for(PSt = 0; PSt < 0x04; PSt++){
        /*  setto il valore del periodo temporaneo evitando di sfondarlo        */
        PRt = (val / PSn[PSt]);
        /*  controllo che non sia maggiore del limite                           */
        if(PRt > std::numeric_limits<unsigned short>::max()){
            /*  in questo caso lo tronco al massimo                             */
            PRt = std::numeric_limits<unsigned short>::max();
        /*  altrimenti                                                          */
        }else{
            /*  lo riporto ad un intero                                         */
            PRt = static_cast<unsigned short>(PRt);
        }
        /*  calcolo l'errore                                                    */
        er2 = per - (PRt * PSn[PSt] / fre);
        /*  se l'errore calcolato in valore assoluto è minore del precedente    */
        if(std::fabs(er2) < er1){
            /*  aggiorno il valore del prescaler                                */
            PSv = PSt;
            /*  aggiorno il valore del periodo                                  */
            PRv = PRt;
            /*  aggiorno l'errore in valore assoluto                            */
            er1 = std::fabs(er2);
        }
        /*  se non c'è errore (caso ottimo)                                     */
        if(er2 == 0){
            /*  smetto di iterare                                               */
            break;
        }
    }
    /*  setto il registro PR                                                    */
    m_treg->PRx_SET = PRv;
    /*  configuro il prescaler                                                  */
    m_treg->TxCON_SET = (PSv << _TxCON_16_TCKPS_POSITION);
    /*  imposto il tempo base                                                   */
    m_base = PSn[PSv] / fre;
    /*  salvo l'errore                                                          */
    m_terr = er1;
    /*  ritorno l'errore                                                        */
    return er1;
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

/*
 * class A32bitSlaveTimer
 */
AFramework::A32bitSlaveTimer::A32bitSlaveTimer(volatile ATMR_w * w) : AAbstract16bitTimer(w) {
#if   defined (__32MX__)

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

bool AFramework::A32bitSlaveTimer::isMaster() const volatile{
#if   defined (__32MX__)
    
    return false;
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A32bitSlaveTimer::setpar(const double t, const double f, const bool w) volatile{
#if   defined (__32MX__)

    double per   = std::fabs(t);                              //  valore assoluto del periodo (non si sa mai...)
    double fre   = std::fabs(f);                              //  valore assoluto della frequenza (non si sa mai...) per il periodo
    double val   = fre * per;                                 //  frequenza per periodo (evito di fare una moltiplicazione ogni iterazione)
    double er1   = std::numeric_limits<double>::max();        //  errore iniziale (dovendo cercare il minimo metto a +inf)
    double er2   = 0;                                         //  errore temporaneo (zero va benissimo)
    uint8  PSv   = 0;                                         //  valore prescaler
    uint8  PSt   = 0;                                         //  prescaler temporaneo
    uint16 PSn[] = {0x0001, 0x0002, 0x0004, 0x0008,           //  prescaler per calcoli
                    0x0010, 0x0020, 0x0040, 0x0100};
    double max   = (w ? std::numeric_limits<unsigned int>::max() : std::numeric_limits<unsigned short>::max()); //  massimo
    uint32 PRv   = 0;                                         //  valore periodo
    double PRt   = 0;                                         //  periodo temporaneo
    /*  inizio a cercare il minimo errore                                       */
    for(PSt = 0; PSt < 0x08; PSt++){
        /*  setto il valore del periodo temporaneo evitando di sfondarlo        */
        PRt = (val / PSn[PSt]);
        /*  controllo che non sia maggiore del limite                           */
        if(PRt > max){
            /*  in questo caso lo tronco al massimo                             */
            PRt = max;
        /*  altrimenti                                                          */
        }else{
            /*  lo riporto ad un intero                                         */
            PRt = (w ? static_cast<unsigned int>(PRt) : static_cast<unsigned short>(PRt));
        }
        /*  calcolo l'errore                                                    */
        er2 = per - (PRt * PSn[PSt] / fre);
        /*  se l'errore calcolato in valore assoluto è minore del precedente    */
        if(std::fabs(er2) < er1){
            /*  aggiorno il valore del prescaler                                */
            PSv = PSt;
            /*  aggiorno il valore del periodo                                  */
            PRv = PRt;
            /*  aggiorno l'errore in valore assoluto                            */
            er1 = std::fabs(er2);
        }
        /*  se non c'è errore (caso ottimo)                                     */
        if(er2 == 0){
            /*  smetto di iterare                                               */
            break;
        }
    }
    /*  setto il registro PR                                                    */
    m_treg->PRx_SET = PRv;
    /*  configuro il prescaler                                                  */
    m_treg->TxCON_SET = (PSv << _TxCON_32_TCKPS_POSITION);
    /*  imposto il tempo base                                                   */
    m_base = PSn[PSv] / fre;
    /*  salvo l'errore                                                          */
    m_terr = er1;
    /*  ritorno l'errore                                                        */
    return er1;

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

/*
 * class A32bitMasterTimer
 */
AFramework::A32bitMasterTimer::A32bitMasterTimer(volatile ATMR_w * w, volatile A32bitSlaveTimer * slave) : A32bitSlaveTimer(w), m_slave(slave){
#if   defined (__32MX__)

#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A32bitMasterTimer::setSynchronousInternal32(const double baseTime, const bool idleStop) volatile{
#if   defined (__32MX__)
    
    /*  resetto il timer slave associato                                        */
    m_slave->reset();
    /*  uso rawcfg con l'eventuale bit di idle                                  */
    rawcfg(_TxCON_T32_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri in modalità  */
    /*  32-bit                                                                  */
    return setpar(baseTime, System::busFrequency(), true);
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif    
}

double AFramework::A32bitMasterTimer::setSynchronousExternal32(const double extFreq, const double baseTime, const bool idleStop) volatile{
#if   defined (__32MX__)
    
    /*  resetto il timer slave associato                                        */
    m_slave->reset();
    /*  uso rawcfg con l'eventuale bit di idle                                  */
    rawcfg(_TxCON_TCS_MASK | _TxCON_T32_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri in modalità  */
    /*  32-bit                                                                  */
    return setpar(baseTime, System::busFrequency(), true);
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A32bitMasterTimer::setGated32(const double baseTime, bool idleStop) volatile{
#if   defined (__32MX__)

    /*  resetto il timer slave associato                                        */
    m_slave->reset();
    /*  uso rawcfg con l'eventuale bit di idle                                  */
    rawcfg(_TxCON_TGATE_MASK | _TxCON_T32_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri in modalità  */
    /*  32-bit                                                                  */
    return setpar(baseTime, System::busFrequency(), true);
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif   
}

bool AFramework::A32bitMasterTimer::isMaster() const volatile{
#if   defined (__32MX__)

    return true;
    
#elif defined (__32MZ__)
#   error   This module is not currently available.
#else
#   error   Unknown architecture.
#endif
}