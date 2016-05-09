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

#ifdef ANTIPODE32MR
    A_COHERENT AFramework::APort AFramework::PortA __attribute__((address(0xBF886000)));
    A_COHERENT AFramework::APort AFramework::PortB __attribute__((address(0xBF886100)));
    A_COHERENT AFramework::APort AFramework::PortC __attribute__((address(0xBF886200)));
#endif
    
AFramework::APort::APort() : m_ANSEL_CLR(ALL), 
                             m_TRIS_SET(ALL), 
                             m_LAT_CLR(ALL), 
                             m_ODC_CLR(ALL), 
                             m_CNPU_CLR(ALL), 
                             m_CNPD_CLR(ALL), 
                             m_CNCON_CLR(ALL), 
                             m_CNEN_CLR(ALL), 
                             m_CNSTAT_CLR(ALL){

}
       
AFramework::uint32 AFramework::APort::adcStatus() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro ANSEL                                 */
    return m_ANSEL;
}

bool AFramework::APort::isAnalog(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return m_ANSEL & gpio;
}

void AFramework::APort::setDigital(const uint32 & gpio) A_COHERENT{
    /*  utilizzo il registro clr associato                                      */
    m_ANSEL_CLR = gpio;
}

void AFramework::APort::setAnalog(const uint32 & gpio) A_COHERENT{
    /*  utilizzo il registro set associato                                      */
    m_ANSEL_SET = gpio;
}

AFramework::uint32 AFramework::APort::ioStatus() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro TRIS                                  */
    return m_TRIS;
}

bool AFramework::APort::isInput(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return m_TRIS & gpio;
}

void AFramework::APort::setInput(const uint32 & gpio) A_COHERENT{
    /*  utilizzo il registro set associato                                      */
    m_TRIS_SET = gpio;
}

void AFramework::APort::setOutput(const uint32 & gpio) A_COHERENT{
    /*  utilizzo il registro clr associato                                      */
    m_TRIS_CLR = gpio;
}

AFramework::uint32 AFramework::APort::portRead() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro port                                  */
    return m_PORT;
}

AFramework::LogicLevel AFramework::APort::portRead(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_PORT & gpio) ? Hi : Lo);
}

void AFramework::APort::portWrite(const uint32 & value) A_COHERENT{
    /*  utilizzo il registro clr associato per azzerare la il registro PORT     */
    m_PORT_CLR = ALL;
    /*  utilizzo il registro set per scrivere il valore                         */
    m_PORT_SET = value;
}

void AFramework::APort::portWrite(const uint32 & gpios, const LogicLevel & value) A_COHERENT{
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

void AFramework::APort::portInvert(const uint32 & gpios) A_COHERENT{
    /*  utilizzo il registro inv associato                                      */
    m_PORT_INV = gpios;
}

AFramework::uint32 AFramework::APort::latchRead() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro LAT                                   */
    return m_LAT;
}

AFramework::LogicLevel AFramework::APort::latchRead(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return ((m_LAT & gpio) ? Hi : Lo);
}

void AFramework::APort::latchWrite(const uint32 & value) A_COHERENT{
    /*  utilizzo il registro clr per azzerare il registro LAT                   */
    m_LAT_CLR = ALL;
    /*  utilizzo il registro set per scrivere il valore                         */
    m_LAT_SET = value;
}

void AFramework::APort::latchWrite(const uint32 & gpios, const LogicLevel & value) A_COHERENT{
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

void AFramework::APort::latchInvert(const uint32 & gpios) A_COHERENT{
    /*  utilizzo il registro inv associato                                      */
    m_LAT_INV = gpios;
}

AFramework::uint32 AFramework::APort::openDrainStatus() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro odc                                   */
    return m_ODC;
}

bool AFramework::APort::isOpenDrain(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return m_ODC & gpio;    
}

void AFramework::APort::setOpenDrain(const uint32 & gpio) A_COHERENT{
    /*  utilizzo il registro set associato                                      */
    m_ODC_SET = gpio;
}

void AFramework::APort::setStandard(const uint32 & gpio) A_COHERENT{
    /* utilizzo il registro clr associato                                       */
    m_ODC_CLR = gpio;
}

AFramework::uint32 AFramework::APort::pullUpStatus() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro cnpu                                  */
    return m_CNPU;
}

bool AFramework::APort::isPullUpEnabled(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return m_CNPU & gpio;
}

void AFramework::APort::enablePullUp(const uint32 & gpio) A_COHERENT{
    /*  disabilito i pull down sui gpio passati                                 */
    m_CNPD_CLR = gpio;
    /*  abilito i pull up sui gpio passati                                      */
    m_CNPU_SET = gpio;
}

void AFramework::APort::disablePullUp(const uint32 & gpio) A_COHERENT{
    /*  utilizzo il registro clr associato                                      */
    m_CNPU_CLR = gpio;
}

AFramework::uint32 AFramework::APort::pullDownStatus() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro cnpd                                  */
    return m_CNPD;
}

bool AFramework::APort::isPullDownEnabled(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return m_CNPD & gpio;
}

void AFramework::APort::enablePullDown(const uint32 & gpio) A_COHERENT{
    /*  disabilito i pull up sui gpio passati                                   */
    m_CNPU_CLR = gpio;
    /*  abilito i pull down sui gpio passati                                    */
    m_CNPD_SET = gpio;
}

void AFramework::APort::disablePullDown(const uint32 & gpio) A_COHERENT{
    /*  utilizzo il registro clr associato                                      */
    m_CNPD_CLR = gpio;
}

bool AFramework::APort::isInterrutptEnabled() A_CONST_COHERENT{
    
    /*  dovrebbe venire qualcosa tipo l'and con CNCON (bit ON) e l'enable del   */
    /*  controller dell'interrupt                                               */
    #warning "bool AFramework::APort::isInterrutptEnabled() A_CONST_COHERENT non ancora implementata"
    return false;
}

void AFramework::APort::enableInterrupt(const uint32 & gpios, const Priority & pri, const SubPriority & sub, const bool & idleStop) A_COHERENT{
    #warning "void AFramework::APort::enableInterrupt(const uint32 & gpios, const Priority pri, const SubPriority, const bool idleStop) A_COHERENT non ancora implementata"
}

void AFramework::APort::disableInterrupt() A_COHERENT{
    /*  utilizzo il registro clr associato                                      */
    m_CNCON_CLR = ALL;
    #warning "void AFramework::APort::disableInterrupt() A_COHERENT bisogna ancora disabilitare dal controller dell'interrupt"
}

AFramework::uint32 AFramework::APort::changeNoticeStatus() A_CONST_COHERENT{
    /*  ritorno il contenuto del registro cnstat                                */
    return m_CNSTAT;
}

bool AFramework::APort::hasInterruptOccurred(const uint32 & gpio) A_CONST_COHERENT{
    /*  ritorno l'and con il gpio passato                                       */
    return m_CNSTAT & gpio;
}

void AFramework::APort::clearInterruptFlag(const uint32 & gpios) A_COHERENT{
    /*  azzero i flag di change notice sui gpio richiesti (generalmente tutti)  */
    /*  ma non sapendo cosa la gente ha in testa devo dare questa possibilità   */
    m_CNSTAT_CLR = gpios;
    #warning "void AFramework::APort::resetInterruptFlag() A_CONST_COHERENT manca da pulire il flag dal controller dell'interrupt"
}

AFramework::uint8 AFramework::APort::whois() A_CONST_COHERENT{
    #ifdef ANTIPODE32MR
    if(this == reinterpret_cast<APort *>(0xBF886000)){
        return 1;
    }
    if(this == reinterpret_cast<APort *>(0xBF886100)){
        return 2;
    }
    if(this == reinterpret_cast<APort *>(0xBF886200)){
        return 3;
    }
    #endif
}
