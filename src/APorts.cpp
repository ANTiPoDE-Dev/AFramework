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
#define PORTAADD 0xBF886000U
#define PORTBADD 0xBF886100U
#define PORTCADD 0xBF886200U

volatile AFramework::AHardwarePort::AErrors m_PORTA_ERR = AFramework::AHardwarePort::NoError;

volatile AFramework::AHardwarePort AFramework::PortA __attribute__((address(PORTAADD)));


AFramework::AHardwarePort::AHardwarePort() {

}

/*************************************************************************************************/
bool AFramework::AHardwarePort::chkown(const uint32 & val) const volatile{
    uint32 devid = 0;
    switch(this){
        case PORTAADD:
            devid = 0x00010000U;
        case PORTBADD:
            devid = 0x00020000U;
        case PORTCADD:
            devid = 0x00030000U;
        default:
            devid = 0x00000000U;
    }
    return !(devid ^ (val & PORTMASK));
}