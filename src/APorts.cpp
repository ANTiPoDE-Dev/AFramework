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

const AFramework::uint32 AFramework::All   = 0xFFFFU;
const AFramework::uint32 AFramework::NoOne = 0x0000U;

const AFramework::uint32 PORTMASK  = 0x000F0000U;

#ifdef ANTIPODE32MR
    volatile AFramework::APort AFramework::PortA __attribute__((address(0xBF886000)));
    volatile AFramework::APort AFramework::PortB __attribute__((address(0xBF886100)));
    volatile AFramework::APort AFramework::PortC __attribute__((address(0xBF886200)));
    const AFramework::uint32 AFramework::A0  = 0x00010001U;
    const AFramework::uint32 AFramework::A1  = 0x00010002U;
    const AFramework::uint32 AFramework::A4  = 0x00010010U;
    const AFramework::uint32 AFramework::A7  = 0x00010080U;
    const AFramework::uint32 AFramework::A8  = 0x00010100U;
    const AFramework::uint32 AFramework::A9  = 0x00010200U;
    const AFramework::uint32 AFramework::A10 = 0x00010400U;
    const AFramework::uint32 AFramework::B0  = 0x00020001U;
    const AFramework::uint32 AFramework::B1  = 0x00020002U;
    const AFramework::uint32 AFramework::B2  = 0x00020008U;
    const AFramework::uint32 AFramework::B3  = 0x00020008U;
    const AFramework::uint32 AFramework::TW  = 0x00020010U;
    const AFramework::uint32 AFramework::B5  = 0x00020020U;
    const AFramework::uint32 AFramework::B7  = 0x00020080U;
    const AFramework::uint32 AFramework::B8  = 0x00020100U;
    const AFramework::uint32 AFramework::B9  = 0x00020200U;
    const AFramework::uint32 AFramework::B10 = 0x00020400U;
    const AFramework::uint32 AFramework::B11 = 0x00020800U;
    const AFramework::uint32 AFramework::B13 = 0x00022000U;
    const AFramework::uint32 AFramework::B14 = 0x00024000U;
    const AFramework::uint32 AFramework::B15 = 0x00028000U;
    const AFramework::uint32 AFramework::C0  = 0x00040001U;
    const AFramework::uint32 AFramework::C1  = 0x00040002U;
    const AFramework::uint32 AFramework::C2  = 0x00040004U;
    const AFramework::uint32 AFramework::C3  = 0x00040008U;
    const AFramework::uint32 AFramework::C4  = 0x00040010U;
    const AFramework::uint32 AFramework::C5  = 0x00040020U;
    const AFramework::uint32 AFramework::C6  = 0x00040040U;
    const AFramework::uint32 AFramework::C7  = 0x00040080U;
    const AFramework::uint32 AFramework::C8  = 0x00040100U;
    const AFramework::uint32 AFramework::C9  = 0x00040200U;
#endif
    
AFramework::APort::APort() : m_ANSEL_CLR(All), 
                             m_TRIS_SET(All), 
                             m_LAT_CLR(All), 
                             m_ODC_CLR(All), 
                             m_CNPU_CLR(All), 
                             m_CNPD_CLR(All), 
                             m_CNCON_CLR(All), 
                             m_CNEN_CLR(All), 
                             m_CNSTAT_CLR(All){

}
       
AFramework::uint32 AFramework::APort::adcStatus() const volatile{
    /*  ritorno il contenuto del registro ANSEL                                 */
    return m_ANSEL;
}

bool AFramework::APort::isAnalog(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_ANSEL & gpio;
}

void AFramework::APort::setDigital(const uint32 & gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_ANSEL_CLR = gpio;
}

void AFramework::APort::setAnalog(const uint32 & gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_ANSEL_SET = gpio;
}

AFramework::uint32 AFramework::APort::ioStatus() const volatile{
    /*  ritorno il contenuto del registro TRIS                                  */
    return m_TRIS;
}

bool AFramework::APort::isInput(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_TRIS & gpio;
}

void AFramework::APort::setInput(const uint32 & gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_TRIS_SET = gpio;
}

void AFramework::APort::setOutput(const uint32 & gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_TRIS_CLR = gpio;
}

AFramework::uint32 AFramework::APort::portRead() const volatile{
    /*  ritorno il contenuto del registro port                                  */
    return m_PORT;
}

AFramework::LogicLevel AFramework::APort::portRead(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_PORT & gpio) ? Hi : Lo);
}

void AFramework::APort::portWrite(const uint32 & value) volatile{
    /*  utilizzo il registro clr associato per azzerare la il registro PORT     */
    m_PORT_CLR = All;
    /*  utilizzo il registro set per scrivere il valore                         */
    m_PORT_SET = value;
}

void AFramework::APort::portWrite(const uint32 & gpios, const LogicLevel & value) volatile{
    /*  se devo mettere alto                                                    */
    if(value == Hi){
        /*  utilizzo il registro set associato                                  */
        m_PORT_SET = gpios;
    /*  se invece devo mettere basso                                            */
    }else if(value == Lo){
        /*  utilizzo il registro clr associato                                  */
        m_PORT_CLR = gpios;
    }
}

void AFramework::APort::portInvert(const uint32 & gpios) volatile{
    /*  utilizzo il registro inv associato                                      */
    m_PORT_INV = gpios;
}

AFramework::uint32 AFramework::APort::latchRead() const volatile{
    /*  ritorno il contenuto del registro LAT                                   */
    return m_LAT;
}

AFramework::LogicLevel AFramework::APort::latchRead(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_LAT & gpio) ? Hi : Lo);
}

void AFramework::APort::latchWrite(const uint32 & value) volatile{
    /*  utilizzo il registro clr per azzerare il registro LAT                   */
    m_LAT_CLR = All;
    /*  utilizzo il registro set per scrivere il valore                         */
    m_LAT_SET = value;
}

void AFramework::APort::latchWrite(const uint32 & gpios, const LogicLevel & value) volatile{
    /*  se devo mettere alto                                                    */
    if(value == Hi){
        /*  utilizzo il registro set associato                                  */
        m_LAT_SET = gpios;
    /*  se invece devo mettere basso                                            */
    }else if(value == Lo){
        /*  utilizzo il registro clr associato                                  */
        m_LAT_CLR = gpios;
    }
}

void AFramework::APort::latchInvert(const uint32 & gpios) volatile{
    /*  utilizzo il registro inv associato                                      */
    m_LAT_INV = gpios;
}

AFramework::uint32 AFramework::APort::openDrainStatus() const volatile{
    /*  ritorno il contenuto del registro odc                                   */
    return m_ODC;
}

bool AFramework::APort::isOpenDrain(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_ODC & gpio;    
}

void AFramework::APort::setOpenDrain(const uint32 & gpio) volatile{
    /*  utilizzo il registro set associato                                      */
    m_ODC_SET = gpio;
}

void AFramework::APort::setStandard(const uint32 & gpio) volatile{
    /* utilizzo il registro clr associato                                       */
    m_ODC_CLR = gpio;
}

AFramework::uint32 AFramework::APort::pullUpStatus() const volatile{
    /*  ritorno il contenuto del registro cnpu                                  */
    return m_CNPU;
}

bool AFramework::APort::isPullUpEnabled(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_CNPU & gpio;
}

void AFramework::APort::enablePullUp(const uint32 & gpio) volatile{
    /*  disabilito i pull down sui gpio passati                                 */
    m_CNPD_CLR = gpio;
    /*  abilito i pull up sui gpio passati                                      */
    m_CNPU_SET = gpio;
}

void AFramework::APort::disablePullUp(const uint32 & gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNPU_CLR = gpio;
}

AFramework::uint32 AFramework::APort::pullDownStatus() const volatile{
    /*  ritorno il contenuto del registro cnpd                                  */
    return m_CNPD;
}

bool AFramework::APort::isPullDownEnabled(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_CNPD & gpio;
}

void AFramework::APort::enablePullDown(const uint32 & gpio) volatile{
    /*  disabilito i pull up sui gpio passati                                   */
    m_CNPU_CLR = gpio;
    /*  abilito i pull down sui gpio passati                                    */
    m_CNPD_SET = gpio;
}

void AFramework::APort::disablePullDown(const uint32 & gpio) volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNPD_CLR = gpio;
}

bool AFramework::APort::isInterrutptEnabled() const volatile{
    
    /*  dovrebbe venire qualcosa tipo l'and con CNCON (bit ON) e l'enable del   */
    /*  controller dell'interrupt                                               */
    #warning "bool AFramework::APort::isInterrutptEnabled() A_CONST_COHERENT non ancora implementata"
    return false;
}

void AFramework::APort::enableInterrupt(const uint32 & gpios, const Priority & pri, const SubPriority & sub, const bool & idleStop) volatile{
    #warning "void AFramework::APort::enableInterrupt(A_CONST_COHERENT uint32 & gpios, A_CONST_COHERENT Priority pri, A_CONST_COHERENT SubPriority, A_CONST_COHERENT bool idleStop) A_COHERENT non ancora implementata"
}

void AFramework::APort::disableInterrupt() volatile{
    /*  utilizzo il registro clr associato                                      */
    m_CNCON_CLR = All;
    #warning "void AFramework::APort::disableInterrupt() A_COHERENT bisogna ancora disabilitare dal controller dell'interrupt"
}

AFramework::uint32 AFramework::APort::changeNoticeStatus() const volatile{
    /*  ritorno il contenuto del registro cnstat                                */
    return m_CNSTAT;
}

bool AFramework::APort::hasInterruptOccurred(const uint32 & gpio) const volatile{
    /*  ritorno l'and con il gpio passato                                       */
    return m_CNSTAT & gpio;
}

void AFramework::APort::clearInterruptFlag(const uint32 & gpios) volatile{
    /*  azzero i flag di change notice sui gpio richiesti (generalmente tutti)  */
    /*  ma non sapendo cosa la gente ha in testa devo dare questa possibilità   */
    m_CNSTAT_CLR = gpios;
    #warning "void AFramework::APort::resetInterruptFlag() A_CONST_COHERENT manca da pulire il flag dal controller dell'interrupt"
}

AFramework::uint32 AFramework::APort::whois() const volatile{
    #ifdef ANTIPODE32MR
        if(this == reinterpret_cast<APort *>(0xBF886000)){
            return 0x00010000;
        }
        if(this == reinterpret_cast<APort *>(0xBF886100)){
            return 0x00020000;
        }
        if(this == reinterpret_cast<APort *>(0xBF886200)){
            return 0x00040000;
        }
    #endif
}

bool AFramework::APort::chkown(const uint32& val) const volatile{
    /*  per evitare di fare assegnamenti strani... Ad esempio, supponiamo di    */
    /*  trovare scritto nel codice PortA.setDigital(A0 | B3), questa senza con- */
    /*  trollo funziona tranquillamente, il problema diventa l'utente voleva    */
    /*  settare la porta A con A0 e A3 digitali oppure la porta B con B0 e B3   */
    /*  digitali? per fare questo le costanti hanno il padre nei bit più signi- */
    /*  ficativi di modo che l'and con port mask 0x000F0000 restituisce la porta*/
    /*  padre del gpio, facendo lo xor con whois che restituisce di quale porta */
    /*  si sta parlando tramite la mappatura in memoria, se il padre è lo stesso*/
    /*  fa zero che negato da uno, mentre se il padre è diverso come nell'esem- */
    /*  pio A0 = 0x00010001 e B0 = 0x00020001 l'or tra i due risulta 0x00030001 */
    /*  che facendo l'and con port mask da 0x00030000 e in xor con i possibili  */
    /*  valori di whois darà sempre un numero diverso da zero!                  */
    return !((val & PORTMASK) ^ whois());
}
