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
#include "APorts.h"

#include <limits>
#include <cmath>

#define _TxCON_ON_POSITION          0x0000000F
#define _TxCON_ON_MASK              0x00008000
#define _TxCON_ON_LENGTH            0x00000001

#define _TxCON_SIDL_POSITION        0x0000000D
#define _TxCON_SIDL_MASK            0x00002000
#define _TxCON_SIDL_LENGTH          0x00000001

#define _TxCON_TWDIS_POSITION       0x0000000C
#define _TxCON_TWDIS_MASK           0x00001000
#define _TxCON_TWDIS_LENGTH         0x00000001

#define _TxCON_TWIP_POSITION        0x0000000B
#define _TxCON_TWIP_MASK            0x00000800
#define _TxCON_TWIP_LENGTH          0x00000001

#define _TxCON_TGATE_POSITION       0x00000007
#define _TxCON_TGATE_MASK           0x00000080
#define _TxCON_TGATE_LENGTH         0x00000001

#define _TxCON_16_TCKPS_POSITION    0x00000004
#define _TxCON_16_TCKPS_MASK        0x00000030
#define _TxCON_16_TCKPS_LENGTH      0x00000002

#define _TxCON_32_TCKPS_POSITION    0x00000004
#define _TxCON_32_TCKPS_MASK        0x00000070
#define _TxCON_32_TCKPS_LENGTH      0x00000003

#define _TxCON_T32_POSITION         0x00000003
#define _TxCON_T32_MASK             0x00000008
#define _TxCON_T32_LENGTH           0x00000001

#define _TxCON_TSYNC_POSITION       0x00000002
#define _TxCON_TSYNC_MASK           0x00000004
#define _TxCON_TSYNC_LENGTH         0x00000001

#define _TxCON_TCS_POSITION         0x00000001
#define _TxCON_TCS_MASK             0x00000002
#define _TxCON_TCS_LENGTH           0x00000001

#define ZERO

class AFramework::AAbstract16bitTimer::ATMR_w{
    public:
        volatile uint32 m_TxCON;
        volatile uint32 m_TxCON_CLR;
        volatile uint32 m_TxCON_SET;
        volatile uint32 m_TxCON_INV;
        volatile uint32 m_TMRx;
        volatile uint32 m_TMRx_CLR;
        volatile uint32 m_TMRx_SET;
        volatile uint32 m_TMRx_INV;
        volatile uint32 m_PRx;
        volatile uint32 m_PRx_CLR;
        volatile uint32 m_PRx_SET;
        volatile uint32 m_PRx_INV;
};

extern volatile AFramework::AAbstract16bitTimer::ATMR_w TMR1_w __asm__("TMR1_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::ATMR_w TMR2_w __asm__("TMR2_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::ATMR_w TMR3_w __asm__("TMR3_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::ATMR_w TMR4_w __asm__("TMR4_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::ATMR_w TMR5_w __asm__("TMR5_w") __attribute__((section("sfrs")));

volatile AFramework::ATimer1 AFramework::Timer1(&TMR1_w);
//    volatile AFramework::ATimer2 AFramework::Timer2;
//    volatile AFramework::ATimer3 AFramework::Timer3;
//    volatile AFramework::ATimer4 AFramework::Timer4;
//    volatile AFramework::ATimer5 AFramework::Timer5;


AFramework::AAbstract16bitTimer::AAbstract16bitTimer(volatile ATMR_w * w) : m_treg(w), m_base(0), m_terr(0){
    close();
}

double AFramework::AAbstract16bitTimer::setSynchronousInternal16(const double baseTime, const bool idleStop) volatile{
    /*  uso rawcfg con l'eventuale bit di idle                                  */
    rawcfg((idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  uso la funzione virtuale che setta i parametri e ritorna l'errore       */
    return setpar(baseTime, System::busFrequency());
}

bool AFramework::AAbstract16bitTimer::open() volatile{
    /*  se il timer è aperto                                                    */
    if(isOpen()){
        /*  ritorno false                                                       */
        return false;
    }
    /*  altrimenti apro il timer tramite il registro set                        */
    m_treg->m_TxCON_SET = _TxCON_ON_MASK;
    /*  e verifico che l'operazione sia andata a buon fine                      */
    return isOpen();
}

void AFramework::AAbstract16bitTimer::close() volatile{
    /*  spengo il timer                                                         */
    m_treg->m_TxCON_CLR = _TxCON_ON_MASK;
}

void AFramework::AAbstract16bitTimer::clear() volatile{
    /*  azzero il registro TMRx                                                 */
    m_treg->m_TMRx_CLR = Quick::All;
}

void AFramework::AAbstract16bitTimer::reset() volatile{
    /*  spengo il timer e cancello tutti i bit                                  */
    m_treg->m_TxCON_CLR = Quick::All;
    /*  pulisco il registro TMRx                                                */
    m_treg->m_TMRx_CLR  = Quick::All;
    /*  pulisco il registro PRx                                                 */
    m_treg->m_PRx_CLR   = Quick::All;
}

bool AFramework::AAbstract16bitTimer::isOpen() const volatile{
    /*  ritorno l'and con il bit on                                             */
    return (m_treg->m_TxCON & _TxCON_ON_MASK);
}

AFramework::uint32 AFramework::AAbstract16bitTimer::rawTime() const volatile{
    /*  ritorno il contenuto del registro TMRx                                  */
    return m_treg->m_TMRx;
}

double AFramework::AAbstract16bitTimer::elapsedTime() const volatile{
    /*  ritorno il tempo grezzo (contenuto del registro TMRx) moltiplicato il   */
    /*  tempo base                                                              */
    return (m_treg->m_TMRx * m_base);
}

double AFramework::AAbstract16bitTimer::error() const volatile{
    /*  ritorno l'errore                                                        */
    return m_terr;
}

double AFramework::AAbstract16bitTimer::resolution() const volatile{
    /*  ritorno il tempo base                                                   */
    return m_base;
}

void AFramework::AAbstract16bitTimer::rawcfg(const volatile uint32 b) volatile{
    /*  resetto il timer                                                        */
    reset();
    /*  configuro per come mi vengono dati i bit                                */
    m_treg->m_TxCON_SET = b;
}

AFramework::AAbstract32bitTimer::AAbstract32bitTimer(volatile ATMR_w * w) : AAbstract16bitTimer(w), m_flag(false){
    
}

double AFramework::AAbstract32bitTimer::setpar(const double t, const double f, const bool w) volatile{
    double per   = std::fabs(t);                              //  valore assoluto del periodo (non si sa mai...)
    double fre   = std::fabs(f);                              //  valore assoluto della frequenza (non si sa mai...) per il periodo
    double val   = fre * per;                                 //  frequenza per periodo (evito di fare una moltiplicazione ogni iterazione)
    double er1   = std::numeric_limits<double>::max();        //  errore iniziale (dovendo cercare il minimo metto a +inf)
    double er2   = 0;                                         //  errore temporaneo (zero va benissimo)
    uint8  PSv   = 0;                                         //  valore prescaler
    uint8  PSt   = 0;                                         //  prescaler temporaneo
    uint16 PSn[] = {0x0001, 0x0002, 0x0004, 0x0008,           //  prescaler per calcoli
                    0x0010, 0x0020, 0x0040, 0x0100};
    uint32 max   = (w ? std::numeric_limits<unsigned int>::max() : std::numeric_limits<unsigned short>::max()); //  massimo
    uint32 PRv   = 0;                                         //  valore periodo
    uint32 PRt   = 0;                                         //  periodo temporaneo
    /*  inizio a cercare il minimo errore                                       */
    for(PSt = 0; PSt < 0x08; PSt++){
        /*  setto il valore del periodo temporaneo evitando di sfondarlo        */
        PRt = ((val / PSn[PSt]) > max ? max : (val / PSn[PSt]));
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
    m_treg->m_PRx_SET = PRv;
    /*  configuro il prescaler                                                  */
    m_treg->m_TxCON_SET = (PSv << _TxCON_32_TCKPS_POSITION);
    /*  imposto il tempo base                                                   */
    m_base = PSn[PSv] / fre;
    /*  salvo l'errore                                                          */
    m_terr = er1;
    /*  ritorno l'errore                                                        */
    return er1;
}


/*--------------------------------------------------------------------------------------------------------------*/
/*  TIMER 1                                                                                                     */
/*--------------------------------------------------------------------------------------------------------------*/

AFramework::ATimer1::ATimer1(volatile ATMR_w * w) : AAbstract16bitTimer(w){
    /*  Nulla da commentare                                                     */
}

double AFramework::ATimer1::setSynchronousExternal16(const double extFreq, const double baseTime, const bool idleStop) volatile{
    /*  uso rawcfg impostando la sorgente di clock esterna, il bit di sync e    */
    /*  l'eventuale bit di idle                                                 */
    rawcfg(_TxCON_TSYNC_MASK | _TxCON_TCS_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    
    #if defined(ANTIPODE32MR)

        /*  setto come ingresso il gpio T1CK                                    */
        PortA.setInput(A4);
        
    #elif defined(__32MX270F256B__)

        /*  setto come ingresso il gpio T1CK                                    */
        PortA.setInput(A4);
        
    #elif defined(__32MX270F256D__)

        /*  setto come ingresso il gpio T1CK                                    */
        PortA.setInput(A4);
        
    #else
    
    #error UNDEFINED BOARD OR PROCESSOR
    
    #endif

    /*  setto i parametri e ritorno l'errore                                    */
    return setpar(baseTime, extFreq);
}

double AFramework::ATimer1::setAsynchronousExternal16(const double baseTime, const bool idleStop) volatile{

    #if defined(ANTIPODE32MR)
    
    #warning "Su ANTiPoDE<32MR> non e' presente l'oscillatore esterno!"
        return std::numeric_limits<double>::min();
        
    #else

    #warning "Abilitazione oscillatore secondario non implementata!"

    #if defined(__32MX270F256B__)

            /*  Abilito gli ingressi per il quarzo                              */
            PortA.setInput(A4);
            PortB.setInput(B4);
            
    #elif defined(__32MX270F256D__)

            /*  Abilito gli ingressi per il quarzo                              */
            PortA.setInput(A4);
            PortB.setInput(B4);
            
    #else
    
    #error UNDEFINED BOARD OR PROCESSOR
    
    #endif

        /*  uso rawcfg impostando la sorgente di clock esterna e l'eventuale    */
        /* bit di idle                                                          */
        rawcfg(TCS_BIT | (idleStop ? SIDL_BIT : Quick::NoOne));
        /*  setto i parametri e ritorno l'errore                                */
        return setpar(baseTime, System::secFrequency());
        
    #endif
}

double AFramework::ATimer1::setGated16(const double baseTime, bool idleStop) volatile{
    #warning "Bisogna sistemare le porte in modo migliore"

    #if defined(ANTIPODE32MR)

        /*  setto come ingresso il gpio T1CK                                    */
        PortA.setInput(A4);
        
    #elif defined(__32MX270F256B__)

        /*  setto come ingresso il gpio T1CK                                    */
        PortA.setInput(A4);
        
    #elif defined(__32MX270F256D__)

        /*  setto come ingresso il gpio T1CK                                    */
        PortA.setInput(A4);
        
    #else
    
    #error UNDEFINED BOARD OR PROCESSOR
    
    #endif
    /*  uso rawcfg impostando la modalita' gated, il bit di sync e l'eventuale  */
    /*  bit di idle                                                             */
    rawcfg(_TxCON_TGATE_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  setto i parametri e ritorno l'errore                                    */
    return setpar(baseTime, System::busFrequency());
}

double AFramework::ATimer1::setpar(const double t, const double f, const bool w) volatile{
    double per   = std::fabs(t);                              //  valore assoluto del periodo (non si sa mai...)
    double fre   = std::fabs(f);                              //  valore assoluto della frequenza (non si sa mai...) per il periodo
    double val   = fre * per;                                 //  frequenza per periodo (evito di fare una moltiplicazione ogni iterazione)
    double er1   = std::numeric_limits<double>::max();        //  errore iniziale (dovendo cercare il minimo metto a +inf)
    double er2   = 0;                                         //  errore temporaneo (zero va benissimo)
    uint8  PSv   = 0;                                         //  valore prescaler
    uint8  PSt   = 0;                                         //  prescaler temporaneo
    uint16 PRv   = 0;                                         //  valore periodo
    uint16 PRt   = 0;                                         //  periodo temporaneo
    uint16 PSn[] = {0x0001, 0x0008, 0x0040, 0x0100};          //  prescaler per calcoli
    /*  inizio a cercare il minimo errore                                       */
    for(PSt = 0; PSt < 0x04; PSt++){
        /*  setto il valore del periodo temporaneo evitando di sfondarlo        */
        PRt = ((val / PSn[PSt]) > std::numeric_limits<unsigned short>::max() ? std::numeric_limits<unsigned short>::max() : (val / PSn[PSt]));
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
    m_treg->m_PRx_SET = PRv;
    /*  configuro il prescaler                                                  */
    m_treg->m_TxCON_SET = (PSv << _TxCON_16_TCKPS_POSITION);
    /*  imposto il tempo base                                                   */
    m_base = PSn[PSv] / fre;
    /*  salvo l'errore                                                          */
    m_terr = er1;
    /*  ritorno l'errore                                                        */
    return er1;
}

/*--------------------------------------------------------------------------------------------------------------*/
/*  TIMER 2                                                                                                     */
/*--------------------------------------------------------------------------------------------------------------*/