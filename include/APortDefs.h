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
#ifndef APORTDEFS_H
#define	APORTDEFS_H

/*
 * su rb4 c'è il led di sistema
 * su ra2 ed ra3 c'è il quarzo
 */

#define ALL     0xFFFFU
#define NO_ONE  0x0000U

#define _BIT_0_ 0x0001U
#define _BIT_1_ 0x0002U
#define _BIT_2_ 0x0004U
#define _BIT_3_ 0x0008U
#define _BIT_4_ 0x0010U
#define _BIT_5_ 0x0020U
#define _BIT_6_ 0x0040U
#define _BIT_7_ 0x0080U
#define _BIT_8_ 0x0100U
#define _BIT_9_ 0x0200U
#define _BIT_A_ 0x0400U
#define _BIT_B_ 0x0800U
#define _BIT_C_ 0x1000U
#define _BIT_D_ 0x2000U
#define _BIT_E_ 0x4000U
#define _BIT_F_ 0x8000U

#define A0  _BIT_0_
#define A1  _BIT_1_
#define A4  _BIT_4_
#define A7  _BIT_7_
#define A8  _BIT_8_
#define A9  _BIT_9_
#define A10 _BIT_A_

#define B0  _BIT_0_
#define B1  _BIT_1_
#define B2  _BIT_2_
#define B3  _BIT_3_
#define B4  _BIT_4_
#define B5  _BIT_5_
#define B7  _BIT_7_
#define B8  _BIT_8_
#define B9  _BIT_9_
#define B10 _BIT_A_
#define B11 _BIT_B_
#define B13 _BIT_D_
#define B14 _BIT_E_
#define B15 _BIT_F_

#define C0  _BIT_0_
#define C1  _BIT_1_
#define C2  _BIT_2_
#define C3  _BIT_3_
#define C4  _BIT_4_
#define C5  _BIT_5_
#define C6  _BIT_6_
#define C7  _BIT_7_
#define C8  _BIT_8_
#define C9  _BIT_9_

#define StatusLed B4

#endif	/* APORTDEFS_H */

