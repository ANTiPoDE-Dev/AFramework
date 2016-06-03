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

#ifndef ASYSTEMCONFIG_H
#define ASYSTEMCONFIG_H

#define ANTIPODE32MR

#define __BIT_0__ 0x0001
#define __BIT_1__ 0x0002
#define __BIT_2__ 0x0004
#define __BIT_3__ 0x0008
#define __BIT_4__ 0x0010
#define __BIT_5__ 0x0020
#define __BIT_6__ 0x0040
#define __BIT_7__ 0x0080
#define __BIT_8__ 0x0100
#define __BIT_9__ 0x0200
#define __BIT_A__ 0x0400
#define __BIT_B__ 0x0800
#define __BIT_C__ 0x1000
#define __BIT_D__ 0x2000
#define __BIT_E__ 0x4000
#define __BIT_F__ 0x8000

#if   defined (ANTIPODE32MR)
#   define __32MX__
//  TIMERS
#   define __HAS_TIMER1__ 1
#   define __HAS_TIMER2__ 1
#   define __HAS_TIMER3__ 1
#   define __HAS_TIMER4__ 1
#   define __HAS_TIMER5__ 1
//  INPUT CAPTURE
#   define __HAS_IC1__ 1
#   define __HAS_IC2__ 1
#   define __HAS_IC3__ 1
#   define __HAS_IC4__ 1
#   define __HAS_IC5__ 1
//  OUTPUT COMPARE
#   define __HAS_OC1__ 1
#   define __HAS_OC2__ 1
#   define __HAS_OC3__ 1
#   define __HAS_OC4__ 1
#   define __HAS_OC5__ 1
//  I2C
#   define __HAS_I2C1__ 1
#   define __HAS_I2C2__ 1
#   define __HAS_I2C3__ 0
#   define __HAS_I2C4__ 0
#   define __HAS_I2C5__ 0
#   define __I2C_SDA1__
#   define __I2C_SCL1__
#   define __I2C_SDA2__
#   define __I2C_SCL2__
//  SPI
#   define __HAS_SPI1__ 1
#   define __HAS_SPI2__ 1
//  UART
#   define __HAS_UART1__ 1
#   define __HAS_UART2__ 1
//  PORTS
#   define __HAS__PORTA__ 1
#   define __HAS__PORTB__ 1
#   define __HAS__PORTC__ 1
#   define __HAS__PORTD__ 0
#   define __HAS__PORTE__ 0
#   define __HAS__PORTF__ 0
#   define __HAS__PORTG__ 0
#   define __HAS__PORTH__ 0
#   define __HAS__PORTJ__ 0
#   define __HAS__PORTK__ 0
#   define __PORTA_BITS__ 0x0793   //0000 0111 1001 0011
#   define __PORTB_BITS__ 0xEFAF   //1110 1111 1010 1111
#   define __PORTC_BITS__ 0x03FF   //0000 0011 1111 1111
//  BOARD SPECIFIC SETTINGS
#   define __HAS_EXTOSC__ 0
#elif defined (__32MX270F256B__)
#   define __32MX__
//  INPUT CAPTURE
#   define __HAS_INCAP1__ 1
#   define __HAS_INCAP2__ 1
#   define __HAS_INCAP3__ 1
#   define __HAS_INCAP4__ 1
#   define __HAS_INCAP5__ 1
#   define __HAS_INCAP6__ 0
#   define __HAS_INCAP7__ 0
#   define __HAS_INCAP8__ 0
#   define __HAS_INCAP9__ 0
//  TIMERS
#   define __HAS_TIMER1__ 1
#   define __HAS_TIMER2__ 1
#   define __HAS_TIMER3__ 1
#   define __HAS_TIMER4__ 1
#   define __HAS_TIMER5__ 1
#   define __HAS_TIMER6__ 0
#   define __HAS_TIMER7__ 0
#   define __HAS_TIMER8__ 0
#   define __HAS_TIMER9__ 0
//  PORTS
#   define __HAS__PORTA__ 1
#   define __HAS__PORTB__ 1
#   define __HAS__PORTC__ 1
#   define __HAS__PORTD__ 0
#   define __HAS__PORTE__ 0
#   define __HAS__PORTF__ 0
#   define __HAS__PORTG__ 0
#   define __HAS__PORTH__ 0
#   define __HAS__PORTJ__ 0
#   define __HAS__PORTK__ 0
#   define __PORTA_BITS__ 0x001F   //0000 0000 0001 1111
#   define __PORTB_BITS__ 0xEFBF   //1110 1111 1011 1111
#elif defined (__32MX270F256D__)
#   define __32MX__
//  INPUT CAPTURE
#   define __HAS_INCAP1__ 1
#   define __HAS_INCAP2__ 1
#   define __HAS_INCAP3__ 1
#   define __HAS_INCAP4__ 1
#   define __HAS_INCAP5__ 1
#   define __HAS_INCAP6__ 0
#   define __HAS_INCAP7__ 0
#   define __HAS_INCAP8__ 0
#   define __HAS_INCAP9__ 0
//  TIMERS
#   define __HAS_TIMER1__ 1
#   define __HAS_TIMER2__ 1
#   define __HAS_TIMER3__ 1
#   define __HAS_TIMER4__ 1
#   define __HAS_TIMER5__ 1
#   define __HAS_TIMER6__ 0
#   define __HAS_TIMER7__ 0
#   define __HAS_TIMER8__ 0
#   define __HAS_TIMER9__ 0
//  PORTS
#   define __HAS__PORTA__ 1
#   define __HAS__PORTB__ 1
#   define __HAS__PORTC__ 1
#   define __HAS__PORTD__ 0
#   define __HAS__PORTE__ 0
#   define __HAS__PORTF__ 0
#   define __HAS__PORTG__ 0
#   define __HAS__PORTH__ 0
#   define __HAS__PORTJ__ 0
#   define __HAS__PORTK__ 0
#   define __PORTA_BITS__ 0x079F   //0000 0111 1001 1111
#   define __PORTB_BITS__ 0xEFBF   //1110 1111 1011 1111
#   define __PORTC_BITS__ 0x03FF   //0000 0011 1111 1111
#endif

#endif // ASYSTEMCONFIG_H
