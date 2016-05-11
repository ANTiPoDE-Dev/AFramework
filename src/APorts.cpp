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

#include "APorts.h"


#define PORTMASK 0x000F0000U
#define GPIOMASK 0x0000FFFFU
#define GENERICM 0xAFC00000U

#define _BIT_0_  0x00000001U
#define _BIT_1_  0x00000002U
#define _BIT_2_  0x00000004U
#define _BIT_3_  0x00000008U
#define _BIT_4_  0x00000010U
#define _BIT_5_  0x00000020U
#define _BIT_6_  0x00000040U
#define _BIT_7_  0x00000080U
#define _BIT_8_  0x00000100U
#define _BIT_9_  0x00000200U
#define _BIT_A_  0x00000400U
#define _BIT_B_  0x00000800U
#define _BIT_C_  0x00001000U
#define _BIT_D_  0x00002000U
#define _BIT_E_  0x00004000U
#define _BIT_F_  0x00008000U

const volatile AFramework::uint32 AFramework::All   = 0xAFC0FFFFU;
const volatile AFramework::uint32 AFramework::NoOne = 0xAFC00000U;

#ifdef ANTIPODE32MR

    #define _PORTA_ 0x00010000U
    #define _PORTB_ 0x00020000U
    #define _PORTC_ 0x00040000U
    #define PORTAAD 0xBF886000U
    #define PORTBAD 0xBF886100U
    #define PORTCAD 0xBF886200U

    const volatile AFramework::uint32 AFramework::A0  = (_PORTA_ | _BIT_0_);
    const volatile AFramework::uint32 AFramework::A1  = (_PORTA_ | _BIT_1_);
    const volatile AFramework::uint32 AFramework::A4  = (_PORTA_ | _BIT_4_);
    const volatile AFramework::uint32 AFramework::A7  = (_PORTA_ | _BIT_7_);
    const volatile AFramework::uint32 AFramework::A8  = (_PORTA_ | _BIT_8_);
    const volatile AFramework::uint32 AFramework::A9  = (_PORTA_ | _BIT_9_);
    const volatile AFramework::uint32 AFramework::A10 = (_PORTA_ | _BIT_A_);

    const volatile AFramework::uint32 AFramework::B0  = (_PORTB_ | _BIT_0_);
    const volatile AFramework::uint32 AFramework::B1  = (_PORTB_ | _BIT_1_);
    const volatile AFramework::uint32 AFramework::B2  = (_PORTB_ | _BIT_2_);
    const volatile AFramework::uint32 AFramework::B3  = (_PORTB_ | _BIT_3_);
    const volatile AFramework::uint32 AFramework::B4  = (_PORTB_ | _BIT_4_);
    const volatile AFramework::uint32 AFramework::B5  = (_PORTB_ | _BIT_5_);
    const volatile AFramework::uint32 AFramework::B7  = (_PORTB_ | _BIT_7_);
    const volatile AFramework::uint32 AFramework::B8  = (_PORTB_ | _BIT_8_);
    const volatile AFramework::uint32 AFramework::B9  = (_PORTB_ | _BIT_9_);
    const volatile AFramework::uint32 AFramework::B10 = (_PORTB_ | _BIT_A_);
    const volatile AFramework::uint32 AFramework::B11 = (_PORTB_ | _BIT_B_);
    const volatile AFramework::uint32 AFramework::B13 = (_PORTB_ | _BIT_D_);
    const volatile AFramework::uint32 AFramework::B14 = (_PORTB_ | _BIT_E_);
    const volatile AFramework::uint32 AFramework::B15 = (_PORTB_ | _BIT_F_);

    const volatile AFramework::uint32 AFramework::C0  = (_PORTC_ | _BIT_0_);
    const volatile AFramework::uint32 AFramework::C1  = (_PORTC_ | _BIT_1_);
    const volatile AFramework::uint32 AFramework::C2  = (_PORTC_ | _BIT_2_);
    const volatile AFramework::uint32 AFramework::C3  = (_PORTC_ | _BIT_3_);
    const volatile AFramework::uint32 AFramework::C4  = (_PORTC_ | _BIT_4_);
    const volatile AFramework::uint32 AFramework::C5  = (_PORTC_ | _BIT_5_);
    const volatile AFramework::uint32 AFramework::C6  = (_PORTC_ | _BIT_6_);
    const volatile AFramework::uint32 AFramework::C7  = (_PORTC_ | _BIT_7_);
    const volatile AFramework::uint32 AFramework::C8  = (_PORTC_ | _BIT_8_);
    const volatile AFramework::uint32 AFramework::C9  = (_PORTC_ | _BIT_9_);

//    volatile AFramework::AHardwarePort::AErrors m_PORTA_ERR = AFramework::AHardwarePort::NoError;
//    volatile AFramework::AHardwarePort::AErrors m_PORTB_ERR = AFramework::AHardwarePort::NoError;
//    volatile AFramework::AHardwarePort::AErrors m_PORTC_ERR = AFramework::AHardwarePort::NoError;
    
    volatile AFramework::AHardwarePort AFramework::PortA __attribute__((address(PORTAAD)));
    volatile AFramework::AHardwarePort AFramework::PortB __attribute__((address(PORTAAD)));
    volatile AFramework::AHardwarePort AFramework::PortC __attribute__((address(PORTAAD)));

#elif defined PIC32MX270F256B
    
    #define _PORTA_ 0x00010000U
    #define _PORTB_ 0x00020000U
    #define PORTAAD 0xBF886000U
    #define PORTBAD 0xBF886100U

    const volatile AFramework::uint32 AFramework::A0  = (_PORTA_ | _BIT_0_);
    const volatile AFramework::uint32 AFramework::A1  = (_PORTA_ | _BIT_1_);
    const volatile AFramework::uint32 AFramework::A2  = (_PORTA_ | _BIT_1_);
    const volatile AFramework::uint32 AFramework::A3  = (_PORTA_ | _BIT_1_);
    const volatile AFramework::uint32 AFramework::A4  = (_PORTA_ | _BIT_4_);

    const volatile AFramework::uint32 AFramework::B0  = (_PORTB_ | _BIT_0_);
    const volatile AFramework::uint32 AFramework::B1  = (_PORTB_ | _BIT_1_);
    const volatile AFramework::uint32 AFramework::B2  = (_PORTB_ | _BIT_2_);
    const volatile AFramework::uint32 AFramework::B3  = (_PORTB_ | _BIT_3_);
    const volatile AFramework::uint32 AFramework::B4  = (_PORTB_ | _BIT_4_);
    const volatile AFramework::uint32 AFramework::B5  = (_PORTB_ | _BIT_5_);
    const volatile AFramework::uint32 AFramework::B7  = (_PORTB_ | _BIT_7_);
    const volatile AFramework::uint32 AFramework::B8  = (_PORTB_ | _BIT_8_);
    const volatile AFramework::uint32 AFramework::B9  = (_PORTB_ | _BIT_9_);
    const volatile AFramework::uint32 AFramework::B10 = (_PORTB_ | _BIT_A_);
    const volatile AFramework::uint32 AFramework::B11 = (_PORTB_ | _BIT_B_);
    const volatile AFramework::uint32 AFramework::B13 = (_PORTB_ | _BIT_D_);
    const volatile AFramework::uint32 AFramework::B14 = (_PORTB_ | _BIT_E_);
    const volatile AFramework::uint32 AFramework::B15 = (_PORTB_ | _BIT_F_);

//    volatile AFramework::AHardwarePort::AErrors m_PORTA_ERR = AFramework::AHardwarePort::NoError;
//    volatile AFramework::AHardwarePort::AErrors m_PORTB_ERR = AFramework::AHardwarePort::NoError;
    
    volatile AFramework::AHardwarePort AFramework::PortA __attribute__((address(PORTAAD)));
    volatile AFramework::AHardwarePort AFramework::PortB __attribute__((address(PORTAAD)));
    
#endif

AFramework::AHardwarePort::AHardwarePort() : m_ANSELx_CLR(All), 
                                             m_TRISx_SET(All), 
                                             m_LATx_CLR(All), 
                                             m_ODCx_CLR(All), 
                                             m_CNPUx_CLR(All), 
                                             m_CNPDx_CLR(All), 
                                             m_CNCONx_CLR(All), 
                                             m_CNENx_CLR(All), 
                                             m_CNSTATx_CLR(All){

}
       
AFramework::uint32 AFramework::AHardwarePort::adcStatus() const volatile{
    /*  ritorno il contenuto del registro ANSEL                                 */
    return m_ANSELx;
}

bool AFramework::AHardwarePort::isAnalog(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_ANSELx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::setDigital(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_ANSELx_CLR = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_ANSELx & (gpio & GPIOMASK));
    
}

bool AFramework::AHardwarePort::setAnalog(const uint32 gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_ANSELx_SET = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_ANSELx & (gpio & GPIOMASK));
}

AFramework::uint32 AFramework::AHardwarePort::ioStatus() const volatile{
    /*  ritorno il contenuto del registro TRIS                                  */
    return m_TRISx;
}

bool AFramework::AHardwarePort::isInput(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_TRISx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::setInput(const uint32 gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_TRISx_SET = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_TRISx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::setOutput(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_TRISx_CLR = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_TRISx & (gpio & GPIOMASK));
}

AFramework::uint32 AFramework::AHardwarePort::read() const volatile{
    /*  ritorno il contenuto del registro port                                  */
    return m_PORTx;
}

AFramework::LogicLevel AFramework::AHardwarePort::read(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_PORTx & (gpio & GPIOMASK)) ? Hi : Lo);
}

bool AFramework::AHardwarePort::portWrite(const uint32 value) volatile{
    /*  utilizzo il registro clr associato per azzerare la il registro PORT     */
    m_PORTx_CLR = All;
    /*  utilizzo il registro set per scrivere il valore                         */
    m_PORTx_SET = value;
    /*  controllo che il valore sia stato scritto correttamente                 */
    return (m_PORTx == value);
}

bool AFramework::AHardwarePort::portWrite(const uint32 gpios, const LogicLevel value) volatile{
    /*  se devo mettere alto                                                    */
    if(value == Hi){
        /*  utilizzo il registro set associato                                  */
        m_PORTx_SET = gpios & GPIOMASK;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
        return (m_PORTx & (gpios & GPIOMASK));
    /*  se invece devo mettere basso                                            */
    }else if(value == Lo){
        /*  utilizzo il registro clr associato                                  */
        m_PORTx_CLR = gpios & GPIOMASK;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
        return !(m_PORTx & (gpios & GPIOMASK));       
    }
}

bool AFramework::AHardwarePort::portInvert(const uint32 & gpios) volatile{
    uint32 tmp = m_PORTx;
    /*  utilizzo il registro inv associato                                      */
    m_PORTx_INV = gpios & GPIOMASK;
    /*  utilizzando il valore salvato prima restituisco l'and negato            */
    return !(tmp & m_PORTx & (gpios & GPIOMASK));
}

AFramework::uint32 AFramework::AHardwarePort::latchRead() const volatile{
    /*  ritorno il contenuto del registro LAT                                   */
    return m_LATx;
}

AFramework::LogicLevel AFramework::AHardwarePort::latchRead(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_LATx & (gpio & GPIOMASK)) ? Hi : Lo);
}

bool AFramework::AHardwarePort::write(const uint32 value) volatile{
    /*  utilizzo il registro clr per azzerare il registro LAT                   */
    m_LATx_CLR = All;
    /*  utilizzo il registro set per scrivere il valore                         */
    m_LATx_SET = value;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_LATx == value);
}

bool AFramework::AHardwarePort::write(const uint32 gpios, const LogicLevel value) volatile{
    /*  se devo mettere alto                                                    */
    if(value == Hi){
        /*  utilizzo il registro set associato                                  */
        m_LATx_SET = gpios & GPIOMASK;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */        
        return (m_LATx & (gpios & GPIOMASK));
    /*  se invece devo mettere basso                                            */
    }else if(value == Lo){
        /*  utilizzo il registro clr associato                                  */
        m_LATx_CLR = gpios & GPIOMASK;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
        return !(m_LATx & (gpios & GPIOMASK));
    }
}

bool AFramework::AHardwarePort::latchInvert(const uint32 gpios) volatile{
    uint32 tmp = m_LATx;
    /*  utilizzo il registro inv associato                                      */
    m_LATx_INV = gpios & GPIOMASK;
    /*  utilizzando il valore salvato prima restituisco l'and negato            */
    return !(tmp & m_LATx & (gpios & GPIOMASK));
}

AFramework::uint32 AFramework::AHardwarePort::openDrainStatus() const volatile{
    /*  ritorno il contenuto del registro odc                                   */
    return m_ODCx;
}

bool AFramework::AHardwarePort::isOpenDrain(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_ODCx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::setOpenDrain(const uint32 gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_ODCx_SET = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_ODCx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::setStandard(const uint32 gpio) volatile{
    /* utilizzo il registro clr associato                                       */
    m_ODCx_CLR = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_ODCx & (gpio & GPIOMASK));
}

AFramework::uint32 AFramework::AHardwarePort::pullUpStatus() const volatile{
    /*  ritorno il contenuto del registro cnpu                                  */
    return m_CNPUx;
}

bool AFramework::AHardwarePort::isPullUpEnabled(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_CNPUx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::enablePullUp(const uint32 gpio) volatile{
    /*  disabilito i pull down sui gpio passati                                 */
    m_CNPDx_CLR = gpio & GPIOMASK;
    /*  abilito i pull up sui gpio passati                                      */
    m_CNPUx_SET = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_CNPUx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::disablePullUp(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNPUx_CLR = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_CNPUx & (gpio & GPIOMASK));
}

AFramework::uint32 AFramework::AHardwarePort::pullDownStatus() const volatile{
    /*  ritorno il contenuto del registro cnpd                                  */
    return m_CNPDx;
}

bool AFramework::AHardwarePort::isPullDownEnabled(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_CNPDx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::enablePullDown(const uint32 gpio) volatile{
    /*  disabilito i pull up sui gpio passati                                   */
    m_CNPUx_CLR = gpio & GPIOMASK;
    /*  abilito i pull down sui gpio passati                                    */
    m_CNPDx_SET = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_CNPDx & (gpio & GPIOMASK));
}

bool AFramework::AHardwarePort::disablePullDown(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNPDx_CLR = gpio & GPIOMASK;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_CNPDx & (gpio & GPIOMASK));
}

//bool AFramework::AHardwarePort::isInterrutptEnabled() const volatile{
//    
//    /*  dovrebbe venire qualcosa tipo l'and con CNCON (bit ON) e l'enable del   */
//    /*  controller dell'interrupt                                               */
//    #warning "bool AFramework::AHardwarePort::isInterrutptEnabled() A_CONST_COHERENT non ancora implementata"
//    return false;
//}
//
//void AFramework::AHardwarePort::enableInterrupt(const uint32 gpios, const Priority pri, const SubPriority, const bool idleStop) volatile{
//    #warning "void AFramework::AHardwarePort::enableInterrupt(const uint32 gpios, const Priority pri, const SubPriority, const bool idleStop) A_COHERENT non ancora implementata"
//}
//
//void AFramework::AHardwarePort::disableInterrupt() volatile{
//    /*  utilizzo il registro clr associato                                      */
//    m_CNCONx_CLR = All;
//    #warning "void AFramework::AHardwarePort::disableInterrupt() A_COHERENT bisogna ancora disabilitare dal controller dell'interrupt"
//}
//
//AFramework::uint32 AFramework::AHardwarePort::changeNoticeStatus() const volatile{
//    /*  ritorno il contenuto del registro cnstat                                */
//    return m_CNSTATx;
//}
//
//bool AFramework::AHardwarePort::hasInterruptOccurred(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return m_CNSTATx & gpio;
//}
//
//void AFramework::AHardwarePort::resetInterruptFlag(const uint32 gpios) volatile{
//    /*  azzero i flag di change notice sui gpio richiesti (generalmente tutti)  */
//    /*  ma non sapendo cosa la gente ha in testa devo dare questa possibilità   */
//    m_CNSTATx_CLR = gpios;
//    #warning "void AFramework::AHardwarePort::resetInterruptFlag() A_CONST_COHERENT manca da pulire il flag dal controller dell'interrupt"
//}
//
//bool AFramework::AHardwarePort::good() const volatile{
//    /*  sempre per gli errori... so che può sembrare una porcata ma per         */
//    /*  come sono messi i registri devo per forza fare in questo modo, se       */
//    /*  metto altri dati membro, per come è mappata la memoria andrei a         */
//    /*  scrivere o su altre porte o su altre periferiche...                     */
//    #ifdef ANTIPODE32MR
//
//        switch(devnum()){
//            case _PORTA_:
//                return m_PORTA_ERR == NoError;
//                break;
//            case _PORTB_:
//                return m_PORTB_ERR == NoError;
//                break;
//            case _PORTC_:
//                return m_PORTC_ERR == NoError;
//                break;
//            default:
//                return false;
//                break;
//        }
//        
//    #elif defined PIC32MX270F256B
//
//        switch(devnum()){
//            case _PORTA_:
//                return m_PORTA_ERR == NoError;
//                break;
//            case _PORTB_:
//                return m_PORTB_ERR == NoError;
//                break;
//            default:
//                return false;
//                break;
//        }
//        
//    #endif
//}
//
//AFramework::AHardwarePort::AErrors AFramework::AHardwarePort::lastError() const volatile{
//    /*  sempre per gli errori... so che può sembrare una porcata ma per         */
//    /*  come sono messi i registri devo per forza fare in questo modo, se       */
//    /*  metto altri dati membro, per come è mappata la memoria andrei a         */
//    /*  scrivere o su altre porte o su altre periferiche...                     */    
//    #ifdef ANTIPODE32MR
//
//        switch(devnum()){
//            case _PORTA_:
//                return m_PORTA_ERR;
//                break;
//            case _PORTB_:
//                return m_PORTB_ERR;
//                break;
//            case _PORTC_:
//                return m_PORTC_ERR;
//                break;
//            default:
//                return NoError;
//                break;
//        }
//        
//    #elif defined PIC32MX270F256B
//
//        switch(devnum()){
//            case _PORTA_:
//                return m_PORTA_ERR;
//                break;
//            case _PORTB_:
//                return m_PORTB_ERR;
//                break;
//            default:
//                return NoError;
//                break;
//        }
//        
//    #endif
//}
//
//AFramework::uint32 AFramework::AHardwarePort::devnum() const volatile{
//    /*  Nulla di che, in base alla mappatura in memoria distinguo quale oggetto */
//    /*  sono... Ripeto, può sembrare una porcheria, ma è l'unico modo per poter */
//    /*  far funzionare tutto...                                                 */
//    #ifdef ANTIPODE32MR
//
//        if(this == reinterpret_cast<AHardwarePort *>(PORTAAD)){
//            return _PORTA_;
//        }
//        if(this == reinterpret_cast<AHardwarePort *>(PORTAAD)){
//            return _PORTB_;
//        }
//        if(this == reinterpret_cast<AHardwarePort *>(PORTAAD)){
//            return _PORTC_;
//        }
//        return All;
//        
//    #elif defined PIC32MX270F256B
//        
//        if(this == reinterpret_cast<AHardwarePort *>(PORTAAD)){
//            return _PORTA_;
//        }
//        if(this == reinterpret_cast<AHardwarePort *>(PORTAAD)){
//            return _PORTB_;
//        }
//        return All;
//        
//    #endif
//}
//
//bool AFramework::AHardwarePort::chkown(const uint32 & val) const volatile{
//
//    /*  se il valore passato è una valore generico tipo All o NoOne che         */
//    /*  rispettivamente valgono 0xAFC0FFFF e 0xAFC00000 faccio l'and bit a      */
//    /*  bit con la maschera generica che val 0xAFC00000                         */
//    if(val & GENERICM == GENERICM){
//        /*  se si verifica la condizione il filtro lascia passare               */
//        return true;
//    }
//    /*  altrimenti mi assicuro che il gpio passato appartenga alla porta        */
//    /*  infatti per come sono messe le costanti supponiamo di chiamare          */
//    /*  PortB.write(A0, Lo)... la costante A0 vale 0x00010001,                  */
//    /*  PortB.devnum() ritorna 0x00020000, per cui facendo l'and di A0 con      */
//    /*  PORTMASK, che vale 0xFFFF0000, ottengo 0x00010000. Adesso facendo       */
//    /*  xor tra quest'ultimo valore e devnum si ottiene 0x00030000 che dal      */
//    /*  momento che è un numero se lo nego con con not fa false... Se           */
//    /*  invece si chiama PortB.write(B0, Lo) la costante B0 vale 0x00020001     */
//    /*  per cui l'and con PORTMASK da 0x00020000, lo xor con PortB.devnum()     */
//    /*  da 0x00000000 che negato logicamente da true. Materialmente serve       */
//    /*  solo per evitare errori mentre si cerca di scrivere su una porta...     */
//    /*  Ovvero se troviamo scritto PortB.write(A0, Lo) l'utente voleva          */
//    /*  scrivere su PortB il bit zero oppure scrivere su PortA lo stesso        */
//    /*  bit? Così si ritorna false è si può debuggare meglio...                 */
//    return !(devnum() ^ (val & PORTMASK));
//}
//
//void AFramework::AHardwarePort::errset(const AErrors &err) const volatile{
//    /*  sempre per gli errori... so che può sembrare una porcata ma per     */
//    /*  come sono messi i registri devo per forza fare in questo modo, se   */
//    /*  metto altri dati membro, per come è mappata la memoria andrei a     */
//    /*  scrivere o su altre porte o su altre periferiche...                 */
//    #ifdef ANTIPODE32MR
//
//        switch(devnum()){
//            case _PORTA_:
//                m_PORTA_ERR = err;
//                break;
//            case _PORTB_:
//                m_PORTB_ERR = err;
//                break;
//            case _PORTC_:
//                m_PORTC_ERR = err;
//                break;
//            default:
//                break;
//        }
//        
//    #elif defined PIC32MX270F256B
//
//        switch(devnum()){
//            case _PORTA_:
//                m_PORTA_ERR = err;
//                break;
//            case _PORTB_:
//                m_PORTB_ERR = err;
//                break;
//            default:
//                break;
//        }
//                
//    #endif
//}