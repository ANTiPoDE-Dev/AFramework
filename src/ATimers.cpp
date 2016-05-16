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

#define ON_BIT          0x00008000U
#define SIDL_BIT        0x00002000U
#define TWDIS_BIT       0x00001000U
#define TWIP_BIT        0x00000800U
#define TGATE_BIT       0x00000080U
#define T32_BIT         0x00000008U
#define TSYNC_BIT       0x00000004U
#define TCS_BIT         0x00000002U
#define T16_PS_MASK     0x00000030U
#define T32_PS_MASK     0x00000070U
#define TxPS_BIT_POS    0x00000004U
#define ZERO            0x00000000U

class AFramework::AAbstract16bitTimer::aTMRx_w{
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

extern volatile AFramework::AAbstract16bitTimer::aTMRx_w TMR1_w __asm__("TMR1_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::aTMRx_w TMR2_w __asm__("TMR2_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::aTMRx_w TMR3_w __asm__("TMR3_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::aTMRx_w TMR4_w __asm__("TMR4_w") __attribute__((section("sfrs")));
extern volatile AFramework::AAbstract16bitTimer::aTMRx_w TMR5_w __asm__("TMR5_w") __attribute__((section("sfrs")));

volatile AFramework::ATimer1 AFramework::Timer1(&TMR1_w);
//    volatile AFramework::ATimer2 AFramework::Timer2;
//    volatile AFramework::ATimer3 AFramework::Timer3;
//    volatile AFramework::ATimer4 AFramework::Timer4;
//    volatile AFramework::ATimer5 AFramework::Timer5;


AFramework::AAbstract16bitTimer::AAbstract16bitTimer(volatile aTMRx_w * w) : m_treg(w), m_base(0), m_terr(0){
    close();
}

double AFramework::AAbstract16bitTimer::setSynchronousInternal16(const double baseTime, const bool idleStop) volatile{
    /*  uso rawcfg con l'eventuale bit di idle                                  */
    rawcfg((idleStop ? SIDL_BIT : Quick::NoOne));
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
    m_treg->m_TxCON_SET = ON_BIT;
    /*  e verifico che l'operazione sia andata a buon fine                      */
    return isOpen();
}

void AFramework::AAbstract16bitTimer::close() volatile{
    /*  spengo il timer                                                         */
    m_treg->m_TxCON_CLR = ON_BIT;
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
    return (m_treg->m_TxCON & ON_BIT);
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

AFramework::AAbstract32bitTimer::AAbstract32bitTimer(volatile aTMRx_w * w) : AAbstract16bitTimer(w), m_flag(false){
    
}

bool AFramework::AAbstract32bitTimer::isAttached() const volatile{
    /*  ritorno il flag di concatenazione                                       */
    return m_flag;
}

double AFramework::AAbstract32bitTimer::setSynchronousInternal32(const double baseTime, const bool idleStop) volatile{
    /*  se il timer è master (timer 2 o 4)                                      */
    if(isMaster()){
        /*  uso rawcfg con l'eventuale bit di idle                              */
        rawcfg((idleStop ? SIDL_BIT : Quick::NoOne));
        /*  uso la funzione virtuale che setta i parametri e ritorna l'errore   */
        return setpar(baseTime, System::busFrequency(), true);        
    }
    /*  altrimenti ritorno errore massimo (timer 3 o 5)                         */
    return std::numeric_limits<double>::max();
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
    m_treg->m_TxCON_SET = (PSv << TxPS_BIT_POS);
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

AFramework::ATimer1::ATimer1(volatile aTMRx_w * w) : AAbstract16bitTimer(w){
    /*  Nulla da commentare                                                     */
}

double AFramework::ATimer1::setSynchronousExternal16(const double extFreq, const double baseTime, const bool idleStop) volatile{
    /*  uso rawcfg impostando la sorgente di clock esterna, il bit di sync e    */
    /*  l'eventuale bit di idle                                                 */
    rawcfg(TSYNC_BIT | TCS_BIT | (idleStop ? SIDL_BIT : Quick::NoOne));
    
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
    rawcfg(TGATE_BIT | (idleStop ? SIDL_BIT : Quick::NoOne));
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
    m_treg->m_TxCON_SET = (PSv << TxPS_BIT_POS);
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