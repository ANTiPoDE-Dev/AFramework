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

#ifdef ANTIPODE32MR

    #define PORTA_ADDRESS 0xBF886000U
    #define PORTB_ADDRESS 0xBF886100U
    #define PORTC_ADDRESS 0xBF886200U
    #define PORTA         0x00010000U
    #define PORTB         0x00020000U
    #define PORTC         0x00040000U
    #define PORTMASK      0x000F0000U
    #define GPIOMASK      0x0000FFFFU

    volatile AFramework::APortA AFramework::PortA __attribute__((address(PORTA_ADDRESS)));
    volatile AFramework::APortB AFramework::PortB __attribute__((address(PORTB_ADDRESS)));
    volatile AFramework::APortC AFramework::PortC __attribute__((address(PORTC_ADDRESS)));
    volatile AFramework::AErrorNotifier::AErrors m_PortA_Error;
    volatile AFramework::AErrorNotifier::AErrors m_PortB_Error;
    volatile AFramework::AErrorNotifier::AErrors m_PortC_Error;


#endif
    
AFramework::AHardwarePort::AHardwarePort() : m_ANSEL_CLR(All), 
                                             m_TRIS_SET(All), 
                                             m_LAT_CLR(All), 
                                             m_ODC_CLR(All), 
                                             m_CNPU_CLR(All), 
                                             m_CNPD_CLR(All), 
                                             m_CNCON_CLR(All), 
                                             m_CNEN_CLR(All), 
                                             m_CNSTAT_CLR(All){

}

bool AFramework::AHardwarePort::open() volatile{
    /*  le porte hardware sono sempre aperte, per cui, ritorno sempre true      */
    return true;
}

bool AFramework::AHardwarePort::close() volatile{
    /*  le porte hardware sono sempre aperte, per cui, ritorno sempre false     */
    return false;
}

bool AFramework::AHardwarePort::isOpen() const volatile{
    /*  le porte hardware sono sempre aperte, per cui, ritorno sempre true      */
    return true;
}

AFramework::uint32 AFramework::AHardwarePort::read() const volatile{
    /*  ritorno il contenuto del registro m_PORT                                */
    return m_PORT;
}

bool AFramework::AHardwarePort::write(const uint32& val) volatile{
    /*  cancello il contenuto del registro m_LAT tramite m_LAT_CLR che rende    */
    /*  l'operazione atomica                                                    */
    m_LAT_CLR = All;
    /*  scrivo il valore passato su m_LAT tramite il m_LAT_SET che rende        */
    /*  l'operazione atomica                                                    */
    m_LAT_SET = val;
    /*  controllo che il dato sia stato scritto correttamente                   */
    return m_LAT == val;
}


/********************************************************************************/
//  PORTA A
/********************************************************************************/
char AFramework::APortA::getChar() const volatile{
    return static_cast<char>(0x00);
}

bool AFramework::APortA::putChar(const char & chr) volatile{
    return true;
}

bool AFramework::APortA::good() const volatile{
    return m_PortA_Error == NoError;
}

AFramework::AErrorNotifier::AErrors AFramework::APortA::lastError() const volatile{
    return m_PortA_Error;
}

void AFramework::APortA::errset(const AErrors & err) const volatile{
    m_PortA_Error = err;
}

AFramework::uint32 AFramework::APortA::devnum() const volatile{
    return 0x00010000U;
}
/********************************************************************************/
//  PORTA B
/********************************************************************************/
char AFramework::APortB::getChar() const volatile{
    return static_cast<char>(0x00);
}

bool AFramework::APortB::putChar(const char & chr) volatile{
    return true;
}

bool AFramework::APortB::good() const volatile{
    return m_PortB_Error == NoError;
}

AFramework::AErrorNotifier::AErrors AFramework::APortB::lastError() const volatile{
    return m_PortB_Error;
}

void AFramework::APortB::errset(const AErrors & err) const volatile{
    m_PortB_Error = err;
}

AFramework::uint32 AFramework::APortB::devnum() const volatile{
    return 0x00020000U;
}
/********************************************************************************/
//  PORTA C
/********************************************************************************/
char AFramework::APortC::getChar() const volatile{
    return static_cast<char>(0x00);
}

bool AFramework::APortC::putChar(const char & chr) volatile{
    return true;
}

bool AFramework::APortC::good() const volatile{
    return m_PortC_Error == NoError;
}

AFramework::AErrorNotifier::AErrors AFramework::APortC::lastError() const volatile{
    return m_PortC_Error;
}

void AFramework::APortC::errset(const AErrors & err) const volatile{
    m_PortC_Error = err;
}

AFramework::uint32 AFramework::APortC::devnum() const volatile{
    return 0x00040000U;
}