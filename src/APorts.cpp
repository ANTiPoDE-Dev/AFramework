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

#define _BIT_00_ 0x00000001U
#define _BIT_01_ 0x00000002U
#define _BIT_02_ 0x00000004U
#define _BIT_03_ 0x00000008U
#define _BIT_04_ 0x00000010U
#define _BIT_05_ 0x00000020U
#define _BIT_06_ 0x00000040U
#define _BIT_07_ 0x00000080U
#define _BIT_08_ 0x00000100U
#define _BIT_09_ 0x00000200U
#define _BIT_10_ 0x00000400U
#define _BIT_11_ 0x00000800U
#define _BIT_12_ 0x00001000U
#define _BIT_13_ 0x00002000U
#define _BIT_14_ 0x00004000U
#define _BIT_15_ 0x00008000U

#define _PPS_00_ 0x00000000U
#define _PPS_01_ 0x10000000U
#define _PPS_02_ 0x20000000U
#define _PPS_03_ 0x30000000U
#define _PPS_04_ 0x40000000U
#define _PPS_05_ 0x50000000U
#define _PPS_06_ 0x60000000U
#define _PPS_07_ 0x70000000U
#define _PPS_08_ 0x80000000U
#define _PPS_09_ 0x90000000U
#define _PPS_10_ 0xA0000000U
#define _PPS_11_ 0xB0000000U
#define _PPS_12_ 0xC0000000U
#define _PPS_13_ 0xD0000000U
#define _PPS_14_ 0xE0000000U
#define _PPS_15_ 0xF0000000U

const volatile AFramework::uint32 AFramework::All   = 0xFFFFFFFFU;
const volatile AFramework::uint32 AFramework::NoOne = 0x00000000U;

#ifdef ANTIPODE32MR

    #define _PORTA_ 0x00010000U
    #define _PORTB_ 0x00020000U
    #define _PORTC_ 0x00040000U
    #define PORTAAD 0xBF886000U
    #define PORTBAD 0xBF886100U
    #define PORTCAD 0xBF886200U

    const volatile AFramework::uint32 AFramework::A0  = (_PORTA_ | _BIT_00_);
    const volatile AFramework::uint32 AFramework::A1  = (_PORTA_ | _BIT_01_);
    const volatile AFramework::uint32 AFramework::A4  = (_PORTA_ | _BIT_04_);
    const volatile AFramework::uint32 AFramework::A7  = (_PORTA_ | _BIT_07_);
    const volatile AFramework::uint32 AFramework::A8  = (_PORTA_ | _BIT_08_);
    const volatile AFramework::uint32 AFramework::A9  = (_PORTA_ | _BIT_09_);
    const volatile AFramework::uint32 AFramework::A10 = (_PORTA_ | _BIT_10_);

    const volatile AFramework::uint32 AFramework::B0  = (_PORTB_ | _BIT_00_);
    const volatile AFramework::uint32 AFramework::B1  = (_PORTB_ | _BIT_01_);
    const volatile AFramework::uint32 AFramework::B2  = (_PORTB_ | _BIT_02_);
    const volatile AFramework::uint32 AFramework::B3  = (_PORTB_ | _BIT_03_);
    const volatile AFramework::uint32 AFramework::B4  = (_PORTB_ | _BIT_04_);
    const volatile AFramework::uint32 AFramework::B5  = (_PORTB_ | _BIT_05_);
    const volatile AFramework::uint32 AFramework::B7  = (_PORTB_ | _BIT_07_);
    const volatile AFramework::uint32 AFramework::B8  = (_PORTB_ | _BIT_08_);
    const volatile AFramework::uint32 AFramework::B9  = (_PORTB_ | _BIT_09_);
    const volatile AFramework::uint32 AFramework::B10 = (_PORTB_ | _BIT_10_);
    const volatile AFramework::uint32 AFramework::B11 = (_PORTB_ | _BIT_11_);
    const volatile AFramework::uint32 AFramework::B13 = (_PORTB_ | _BIT_13_);
    const volatile AFramework::uint32 AFramework::B14 = (_PORTB_ | _BIT_14_);
    const volatile AFramework::uint32 AFramework::B15 = (_PORTB_ | _BIT_15_);

    const volatile AFramework::uint32 AFramework::C0  = (_PORTC_ | _BIT_00_);
    const volatile AFramework::uint32 AFramework::C1  = (_PORTC_ | _BIT_01_);
    const volatile AFramework::uint32 AFramework::C2  = (_PORTC_ | _BIT_02_);
    const volatile AFramework::uint32 AFramework::C3  = (_PORTC_ | _BIT_03_);
    const volatile AFramework::uint32 AFramework::C4  = (_PORTC_ | _BIT_04_);
    const volatile AFramework::uint32 AFramework::C5  = (_PORTC_ | _BIT_05_);
    const volatile AFramework::uint32 AFramework::C6  = (_PORTC_ | _BIT_06_);
    const volatile AFramework::uint32 AFramework::C7  = (_PORTC_ | _BIT_07_);
    const volatile AFramework::uint32 AFramework::C8  = (_PORTC_ | _BIT_08_);
    const volatile AFramework::uint32 AFramework::C9  = (_PORTC_ | _BIT_09_);
    
    volatile AFramework::AHardwarePort AFramework::PortA __attribute__((address(PORTAAD)));
    volatile AFramework::AHardwarePort AFramework::PortB __attribute__((address(PORTBAD)));
    volatile AFramework::AHardwarePort AFramework::PortC __attribute__((address(PORTCAD)));

#elif defined PIC32MX270F256B
    
    #define _PORTA_ 0x00010000U
    #define _PORTB_ 0x00020000U
    #define PORTAAD 0xBF886000U
    #define PORTBAD 0xBF886100U

    const volatile AFramework::uint32 AFramework::A0  = (_PORTA_ | _BIT_00_);
    const volatile AFramework::uint32 AFramework::A1  = (_PORTA_ | _BIT_01_);
    const volatile AFramework::uint32 AFramework::A2  = (_PORTA_ | _BIT_02_);
    const volatile AFramework::uint32 AFramework::A3  = (_PORTA_ | _BIT_03_);
    const volatile AFramework::uint32 AFramework::A4  = (_PORTA_ | _BIT_04_);

    const volatile AFramework::uint32 AFramework::B0  = (_PORTB_ | _BIT_00_);
    const volatile AFramework::uint32 AFramework::B1  = (_PORTB_ | _BIT_01_);
    const volatile AFramework::uint32 AFramework::B2  = (_PORTB_ | _BIT_02_);
    const volatile AFramework::uint32 AFramework::B3  = (_PORTB_ | _BIT_03_);
    const volatile AFramework::uint32 AFramework::B4  = (_PORTB_ | _BIT_04_);
    const volatile AFramework::uint32 AFramework::B5  = (_PORTB_ | _BIT_05_);
    const volatile AFramework::uint32 AFramework::B7  = (_PORTB_ | _BIT_07_);
    const volatile AFramework::uint32 AFramework::B8  = (_PORTB_ | _BIT_08_);
    const volatile AFramework::uint32 AFramework::B9  = (_PORTB_ | _BIT_09_);
    const volatile AFramework::uint32 AFramework::B10 = (_PORTB_ | _BIT_10_);
    const volatile AFramework::uint32 AFramework::B11 = (_PORTB_ | _BIT_11_);
    const volatile AFramework::uint32 AFramework::B13 = (_PORTB_ | _BIT_13_);
    const volatile AFramework::uint32 AFramework::B14 = (_PORTB_ | _BIT_14_);
    const volatile AFramework::uint32 AFramework::B15 = (_PORTB_ | _BIT_15_);
    
    volatile AFramework::AHardwarePort AFramework::PortA __attribute__((address(PORTAAD)));
    volatile AFramework::AHardwarePort AFramework::PortB __attribute__((address(PORTBAD)));
    
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
/*  controllo scrittura:
 *      -> Operazione di set
 *          CASO OK
 *          contenuto iniziale          0100 0110
 *          bit da settare              0011 0101
 *          dopo set con successo       0111 0111
 *          and con i bit               0111 0111 & 0011 0101 = 0011 0101
 *          xor con i bit               0011 0101 ^ 0011 0101 = 0000 0000
 *          negato logico               !0x00 = true;
 *          CASO FALLIMENTO
 *          contenuto iniziale          0100 0110
 *          bit da settare              0011 0101
 *          dopo set (fallisce 4)       0110 0111
 *          and con i bit               0110 0111 & 0011 0101 = 0010 0101
 *          xor con i bit               0010 0101 ^ 0011 0101 = 0001 0000
 *          negato logico               !0x10 = false
 *          ## espressione = !((m_REGx & gpios) ^ gpios)
 *      -> Operazione di clear
 *          CASO OK
 *          contenuto iniziale          0100 0110
 *          bit da azzerare             1100 0100
 *          dopo clr con successo       0000 0010
 *          and con i bit               0000 0000
 *          
 * 
 */ 
AFramework::uint32 AFramework::AHardwarePort::adcStatus() const volatile{
    /*  ritorno il contenuto del registro ANSEL                                 */
    return m_ANSELx;
}

bool AFramework::AHardwarePort::isAnalog(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_ANSELx & gpio;
}

bool AFramework::AHardwarePort::setDigital(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */ 
    m_ANSELx_CLR = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_ANSELx & gpio);   
}

bool AFramework::AHardwarePort::setAnalog(const uint32 gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_ANSELx_SET = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_ANSELx & gpio);
}

AFramework::uint32 AFramework::AHardwarePort::ioStatus() const volatile{
    /*  ritorno il contenuto del registro TRIS                                  */
    return m_TRISx;
}

bool AFramework::AHardwarePort::isInput(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_TRISx & gpio);
}

bool AFramework::AHardwarePort::setInput(const uint32 gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_TRISx_SET = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_TRISx & gpio);
    0100 0111 0100 0111 0111
}

bool AFramework::AHardwarePort::setOutput(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_TRISx_CLR = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_TRISx & gpio);
}

AFramework::uint32 AFramework::AHardwarePort::read() const volatile{
    /*  ritorno il contenuto del registro port                                  */
    return m_PORTx;
}

AFramework::LogicLevel AFramework::AHardwarePort::read(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_PORTx & gpio) ? Hi : Lo);
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
        m_PORTx_SET = gpios;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
        return (m_PORTx & gpios);
    /*  se invece devo mettere basso                                            */
    }else if(value == Lo){
        /*  utilizzo il registro clr associato                                  */
        m_PORTx_CLR = gpios;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
        return !(m_PORTx & gpios);       
    }
}

bool AFramework::AHardwarePort::portInvert(const uint32 & gpios) volatile{
    uint32 tmp = m_PORTx;
    /*  utilizzo il registro inv associato                                      */
    m_PORTx_INV = gpios;
    /*  utilizzando il valore salvato prima restituisco l'and negato            */
    return !(tmp & m_PORTx & gpios);
}

AFramework::uint32 AFramework::AHardwarePort::latchRead() const volatile{
    /*  ritorno il contenuto del registro LAT                                   */
    return m_LATx;
}

AFramework::LogicLevel AFramework::AHardwarePort::latchRead(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_LATx & gpio) ? Hi : Lo);
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
        m_LATx_SET = gpios;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */        
        return (m_LATx & gpios == gpios);
    /*  se invece devo mettere basso                                            */
    }else if(value == Lo){
        /*  utilizzo il registro clr associato                                  */
        m_LATx_CLR = gpios;
        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
        return !(m_LATx & gpios);
    }
}

bool AFramework::AHardwarePort::latchInvert(const uint32 gpios) volatile{
    uint32 tmp = m_LATx;
    /*  utilizzo il registro inv associato                                      */
    m_LATx_INV = gpios;
    /*  utilizzando il valore salvato prima restituisco l'and negato            */
    return !(tmp & m_LATx & gpios);
}

AFramework::uint32 AFramework::AHardwarePort::openDrainStatus() const volatile{
    /*  ritorno il contenuto del registro odc                                   */
    return m_ODCx;
}

bool AFramework::AHardwarePort::isOpenDrain(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_ODCx & gpio);
}

bool AFramework::AHardwarePort::setOpenDrain(const uint32 gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_ODCx_SET = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_ODCx & gpio);
}

bool AFramework::AHardwarePort::setStandard(const uint32 gpio) volatile{
    /* utilizzo il registro clr associato                                       */
    m_ODCx_CLR = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_ODCx & gpio);
}

AFramework::uint32 AFramework::AHardwarePort::pullUpStatus() const volatile{
    /*  ritorno il contenuto del registro cnpu                                  */
    return m_CNPUx;
}

bool AFramework::AHardwarePort::isPullUpEnabled(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_CNPUx & gpio);
}

bool AFramework::AHardwarePort::enablePullUp(const uint32 gpio) volatile{
    /*  disabilito i pull down sui gpio passati                                 */
    m_CNPDx_CLR = gpio;
    /*  abilito i pull up sui gpio passati                                      */
    m_CNPUx_SET = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_CNPUx & gpio);
}

bool AFramework::AHardwarePort::disablePullUp(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNPUx_CLR = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_CNPUx & gpio);
}

AFramework::uint32 AFramework::AHardwarePort::pullDownStatus() const volatile{
    /*  ritorno il contenuto del registro cnpd                                  */
    return m_CNPDx;
}

bool AFramework::AHardwarePort::isPullDownEnabled(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return (m_CNPDx & gpio);
}

bool AFramework::AHardwarePort::enablePullDown(const uint32 gpio) volatile{
    /*  disabilito i pull up sui gpio passati                                   */
    m_CNPUx_CLR = gpio;
    /*  abilito i pull down sui gpio passati                                    */
    m_CNPDx_SET = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return (m_CNPDx & gpio);
}

bool AFramework::AHardwarePort::disablePullDown(const uint32 gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNPDx_CLR = gpio;
    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
    return !(m_CNPDx & gpio);
}

bool AFramework::AHardwarePort::isInterrutptEnabled() const volatile{
    
    /*  dovrebbe venire qualcosa tipo l'and con CNCON (bit ON) e l'enable del   */
    /*  controller dell'interrupt                                               */
    #warning "bool AFramework::AHardwarePort::isInterrutptEnabled() const volatile non ancora implementata"
    return false;
}

void AFramework::AHardwarePort::enableInterrupt(const uint32 gpios, const Priority pri, const SubPriority, const bool idleStop) volatile{
    #warning "void AFramework::AHardwarePort::enableInterrupt(const uint32 gpios, const Priority pri, const SubPriority, const bool idleStop) volatile non ancora implementata"
}

void AFramework::AHardwarePort::disableInterrupt() volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNCONx_CLR = All;
    #warning "void AFramework::AHardwarePort::disableInterrupt() volatile bisogna ancora disabilitare dal controller dell'interrupt"
}

AFramework::uint32 AFramework::AHardwarePort::changeNoticeStatus() const volatile{
    /*  ritorno il contenuto del registro cnstat                                */
    return m_CNSTATx;
}

bool AFramework::AHardwarePort::hasInterruptOccurred(const uint32 gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_CNSTATx & gpio;
}

void AFramework::AHardwarePort::resetInterruptFlag(const uint32 gpios) volatile{
    /*  azzero i flag di change notice sui gpio richiesti (generalmente tutti)  */
    /*  ma non sapendo cosa la gente ha in testa devo dare questa possibilità   */
    m_CNSTATx_CLR = gpios;
    #warning "void AFramework::AHardwarePort::resetInterruptFlag() A_CONST_COHERENT manca da pulire il flag dal controller dell'interrupt"
}
