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

#if defined (__32MX__) || defined(__32MZ__)

#   define _PORTx_BIT_00_MASK   0x00000001
#   define _PORTx_BIT_01_MASK   0x00000002
#   define _PORTx_BIT_02_MASK   0x00000004
#   define _PORTx_BIT_03_MASK   0x00000008
#   define _PORTx_BIT_04_MASK   0x00000010
#   define _PORTx_BIT_05_MASK   0x00000020
#   define _PORTx_BIT_06_MASK   0x00000040
#   define _PORTx_BIT_07_MASK   0x00000080
#   define _PORTx_BIT_08_MASK   0x00000100
#   define _PORTx_BIT_09_MASK   0x00000200
#   define _PORTx_BIT_10_MASK   0x00000400
#   define _PORTx_BIT_11_MASK   0x00000800
#   define _PORTx_BIT_12_MASK   0x00001000
#   define _PORTx_BIT_13_MASK   0x00002000
#   define _PORTx_BIT_14_MASK   0x00004000
#   define _PORTx_BIT_15_MASK   0x00008000

#   define _PORTx_BIT_MASK      0x0000FFFF

#   define _CNCONx_ON_MASK      0x00008000
#   define _CNCONx_SIDL_MASK    0x00002000

#   define _PORTA_ID_VAL        0x00010000
#   define _PORTB_ID_VAL        0x00020000
#   define _PORTC_ID_VAL        0x00040000
#   define _PORTD_ID_VAL        0x00080000
#   define _PORTE_ID_VAL        0x00100000
#   define _PORTF_ID_VAL        0x00200000
#   define _PORTG_ID_VAL        0x00400000
#   define _PORTH_ID_VAL        0x00800000
#   define _PORTJ_ID_VAL        0x01000000
#   define _PORTK_ID_VAL        0x02000000

    class AFramework::APORT_w{
        public:
            volatile AFramework::uint32 ANSELx;
            volatile AFramework::uint32 ANSELx_CLR;
            volatile AFramework::uint32 ANSELx_SET;
            volatile AFramework::uint32 ANSELx_INV;
            volatile AFramework::uint32 TRISx;
            volatile AFramework::uint32 TRISx_CLR;
            volatile AFramework::uint32 TRISx_SET;
            volatile AFramework::uint32 TRISx_INV;
            volatile AFramework::uint32 PORTx;
            volatile AFramework::uint32 PORTx_CLR;
            volatile AFramework::uint32 PORTx_SET;
            volatile AFramework::uint32 PORTx_INV;
            volatile AFramework::uint32 LATx;
            volatile AFramework::uint32 LATx_CLR;
            volatile AFramework::uint32 LATx_SET;
            volatile AFramework::uint32 LATx_INV;
            volatile AFramework::uint32 ODCx;
            volatile AFramework::uint32 ODCx_CLR;
            volatile AFramework::uint32 ODCx_SET;
            volatile AFramework::uint32 ODCx_INV;
            volatile AFramework::uint32 CNPUx;
            volatile AFramework::uint32 CNPUx_CLR;
            volatile AFramework::uint32 CNPUx_SET;
            volatile AFramework::uint32 CNPUx_INV;
            volatile AFramework::uint32 CNPDx;
            volatile AFramework::uint32 CNPDx_CLR;
            volatile AFramework::uint32 CNPDx_SET;
            volatile AFramework::uint32 CNPDx_INV;
            volatile AFramework::uint32 CNCONx;
            volatile AFramework::uint32 CNCONx_CLR;
            volatile AFramework::uint32 CNCONx_SET;
            volatile AFramework::uint32 CNCONx_INV;
            volatile AFramework::uint32 CNENx;
            volatile AFramework::uint32 CNENx_CLR;
            volatile AFramework::uint32 CNENx_SET;
            volatile AFramework::uint32 CNENx_INV;
            volatile AFramework::uint32 CNSTATx;
            volatile AFramework::uint32 CNSTATx_CLR;
            volatile AFramework::uint32 CNSTATx_SET;
            volatile AFramework::uint32 CNSTATx_INV;        
    };

#else
#   error   Unknown architecture.
#endif

#if (__HAS__PORTA__)
    
    extern volatile AFramework::APORT_w PORTA_w __asm__("PORTA_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortA(&PORTA_w, _PORTA_ID_VAL);

#   if(__PORTA_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::A0(_PORTA_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::A1(_PORTA_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::A2(_PORTA_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::A3(_PORTA_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::A4(_PORTA_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::A5(_PORTA_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::A6(_PORTA_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::A7(_PORTA_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::A8(_PORTA_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::A9(_PORTA_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::A10(_PORTA_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::A11(_PORTA_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::A12(_PORTA_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::A13(_PORTA_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::A14(_PORTA_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTA_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::A15(_PORTA_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif
    
#if (__HAS__PORTB__)
    
    extern volatile AFramework::APORT_w PORTB_w __asm__("PORTB_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortB(&PORTB_w, _PORTB_ID_VAL);
    
#   if(__PORTB_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::B0(_PORTB_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::B1(_PORTB_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::B2(_PORTB_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::B3(_PORTB_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::B4(_PORTB_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::B5(_PORTB_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::B6(_PORTB_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::B7(_PORTB_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::B8(_PORTB_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::B9(_PORTB_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::B10(_PORTB_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::B11(_PORTB_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::B12(_PORTB_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::B13(_PORTB_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::B14(_PORTB_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTB_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::B15(_PORTB_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif

#if (__HAS__PORTC__)

    extern volatile AFramework::APORT_w PORTC_w __asm__("PORTC_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortC(&PORTC_w, _PORTC_ID_VAL);

#   if(__PORTC_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::C0(_PORTC_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::C1(_PORTC_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::C2(_PORTC_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::C3(_PORTC_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::C4(_PORTC_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::C5(_PORTC_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::C6(_PORTC_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::C7(_PORTC_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::C8(_PORTC_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::C9(_PORTC_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::C10(_PORTC_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::C11(_PORTC_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::C12(_PORTC_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::C13(_PORTC_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::C14(_PORTC_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTC_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::C15(_PORTC_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif

#if (__HAS__PORTD__)
    
    extern volatile AFramework::APORT_w PORTD_w __asm__("PORTD_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortD(&PORTD_w, _PORTD_ID_VAL);
    
#   if(__PORTD_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::D0(_PORTD_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::D1(_PORTD_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::D2(_PORTD_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::D3(_PORTD_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::D4(_PORTD_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::D5(_PORTD_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::D6(_PORTD_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::D7(_PORTD_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::D8(_PORTD_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::D9(_PORTD_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::D10(_PORTD_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::D11(_PORTD_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::D12(_PORTD_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::D13(_PORTD_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::D14(_PORTD_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTD_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::D15(_PORTD_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif

#if (__HAS__PORTE__)
    
    extern volatile AFramework::APORT_w PORTE_w __asm__("PORTE_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortE(&PORTE_w, _PORTE_ID_VAL);
    
#   if(__PORTE_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::E0(_PORTE_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::E1(_PORTE_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::E2(_PORTE_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::E3(_PORTE_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::E4(_PORTE_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::E5(_PORTE_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::E6(_PORTE_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::E7(_PORTE_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::E8(_PORTE_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::E9(_PORTE_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::E10(_PORTE_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::E11(_PORTE_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::E12(_PORTE_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::E13(_PORTE_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::E14(_PORTE_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTE_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::E15(_PORTE_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif
    
#if (__HAS__PORTF__)
    
    extern volatile AFramework::APORT_w PORTF_w __asm__("PORTF_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortF(&PORTF_w, _PORTF_ID_VAL);
    
#   if(__PORTF_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::F0(_PORTF_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::F1(_PORTF_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::F2(_PORTF_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::F3(_PORTF_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::F4(_PORTF_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::F5(_PORTF_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::F6(_PORTF_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::F7(_PORTF_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::F8(_PORTF_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::F9(_PORTF_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::F10(_PORTF_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::F11(_PORTF_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::F12(_PORTF_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::F13(_PORTF_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::F14(_PORTF_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTF_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::F15(_PORTF_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif
    
#if (__HAS__PORTG__)
    
    extern volatile AFramework::APORT_w PORTG_w __asm__("PORTG_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortG(&PORTG_w, _PORTG_ID_VAL);
    
#   if(__PORTG_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::G0(_PORTG_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::G1(_PORTG_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::G2(_PORTG_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::G3(_PORTG_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::G4(_PORTG_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::G5(_PORTG_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::G6(_PORTG_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::G7(_PORTG_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::G8(_PORTG_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::G9(_PORTG_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::G10(_PORTG_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::G11(_PORTG_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::G12(_PORTG_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::G13(_PORTG_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::G14(_PORTG_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTG_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::G15(_PORTG_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif

#if (__HAS__PORTH__)
    
    extern volatile AFramework::APORT_w PORTH_w __asm__("PORTH_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortH(&PORTH_w, _PORTH_ID_VAL);

#   if(__PORTH_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::H0(_PORTH_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::H1(_PORTH_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::H2(_PORTH_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::H3(_PORTH_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::H4(_PORTH_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::H5(_PORTH_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::H6(_PORTH_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::H7(_PORTH_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::H8(_PORTH_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::H9(_PORTH_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::H10(_PORTH_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::H11(_PORTH_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::H12(_PORTH_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::H13(_PORTH_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::H14(_PORTH_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTH_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::H15(_PORTH_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif
    
#if (__HAS__PORTJ__)
    
    extern volatile AFramework::APORT_w PORTJ_w __asm__("PORTJ_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortJ(&PORTJ_w, _PORTJ_ID_VAL);
    
#   if(__PORTJ_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::J0(_PORTJ_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::J1(_PORTJ_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::J2(_PORTJ_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::J3(_PORTJ_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::J4(_PORTJ_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::J5(_PORTJ_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::J6(_PORTJ_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::J7(_PORTJ_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::J8(_PORTJ_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::J9(_PORTJ_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::J10(_PORTJ_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::J11(_PORTJ_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::J12(_PORTJ_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::J13(_PORTJ_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::J14(_PORTJ_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTJ_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::J15(_PORTJ_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif
    
#if (__HAS__PORTK__)
    
    extern AFramework::APORT_w PORTK_w __asm__("PORTK_w") __attribute__((section("sfrs")));
    volatile AFramework::AHardwarePort AFramework::PortK(&PORTK_w, _PORTK_ID_VAL);
    
#   if(__PORTK_BITS__ & __BIT_0__)
    const volatile AFramework::uint32 AFramework::K0(_PORTK_ID_VAL | _PORTx_BIT_00_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_1__)
    const volatile AFramework::uint32 AFramework::K1(_PORTK_ID_VAL | _PORTx_BIT_01_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_2__)
    const volatile AFramework::uint32 AFramework::K2(_PORTK_ID_VAL | _PORTx_BIT_02_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_3__)
    const volatile AFramework::uint32 AFramework::K3(_PORTK_ID_VAL | _PORTx_BIT_03_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_4__)
    const volatile AFramework::uint32 AFramework::K4(_PORTK_ID_VAL | _PORTx_BIT_04_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_5__)
    const volatile AFramework::uint32 AFramework::K5(_PORTK_ID_VAL | _PORTx_BIT_05_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_6__)
    const volatile AFramework::uint32 AFramework::K6(_PORTK_ID_VAL | _PORTx_BIT_06_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_7__)
    const volatile AFramework::uint32 AFramework::K7(_PORTK_ID_VAL | _PORTx_BIT_07_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_8__)
    const volatile AFramework::uint32 AFramework::K8(_PORTK_ID_VAL | _PORTx_BIT_08_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_9__)
    const volatile AFramework::uint32 AFramework::K9(_PORTK_ID_VAL | _PORTx_BIT_09_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_A__)
    const volatile AFramework::uint32 AFramework::K10(_PORTK_ID_VAL | _PORTx_BIT_10_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_B__)
    const volatile AFramework::uint32 AFramework::K11(_PORTK_ID_VAL | _PORTx_BIT_11_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_C__)
    const volatile AFramework::uint32 AFramework::K12(_PORTK_ID_VAL | _PORTx_BIT_12_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_D__)
    const volatile AFramework::uint32 AFramework::K13(_PORTK_ID_VAL | _PORTx_BIT_13_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_E__)
    const volatile AFramework::uint32 AFramework::K14(_PORTK_ID_VAL | _PORTx_BIT_14_MASK);
#   endif
#   if(__PORTK_BITS__ & __BIT_F__)
    const volatile AFramework::uint32 AFramework::K15(_PORTK_ID_VAL | _PORTx_BIT_15_MASK);
#   endif
#endif
    
AFramework::AHardwarePort::AHardwarePort(volatile APORT_w * w, const uint32 id) : m_preg(w), m_prid(id){
    /*  imposto tutto come ingresso                                             */
    m_preg->TRISx_SET   = Quick::All;
    /*  azzero il registro LATx                                                 */
    m_preg->LATx_CLR    = Quick::All;
    /*  setto tutto con l'open-drain disattivato                                */
    m_preg->ODCx_CLR    = Quick::All;
    /*  disabilito tutti i pull-up                                              */
    m_preg->CNPUx_CLR   = Quick::All;
    /*  disabilito tutti i pull-down                                            */
    m_preg->CNPDx_CLR   = Quick::All;
    /*  disabilito la periferica change-notice                                  */
    m_preg->CNCONx_CLR  = Quick::All;
    /*  azzero il registro dell'enable per la periferica change-notice          */
    m_preg->CNENx_CLR   = Quick::All;
    /*  azzero il registro dei flag per la periferica change-notice             */
    m_preg->CNSTATx_CLR = Quick::All;
}

    
//AFramework::AHardwarePort::AHardwarePort(volatile APORT_w * w) : ANSELx_CLR(Quick::All), 
//                                             TRISx_SET(Quick::All), 
//                                             LATx_CLR(Quick::All), 
//                                             ODCx_CLR(Quick::All), 
//                                             CNPUx_CLR(Quick::All), 
//                                             CNPDx_CLR(Quick::All), 
//                                             CNCONx_CLR(Quick::All), 
//                                             CNENx_CLR(Quick::All), 
//                                             CNSTATx_CLR(Quick::All){
//
//}
//
//AFramework::uint32 AFramework::AHardwarePort::adcStatus() const volatile{
//    /*  ritorno il contenuto del registro ANSEL                                 */
//    return ANSELx;
//}
//
//bool AFramework::AHardwarePort::isAnalog(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return (ANSELx & gpio);
//}
//
//bool AFramework::AHardwarePort::setDigital(const uint32 gpio) volatile{
//    /*  utilizzo il registro clr associato                                      */ 
//    ANSELx_CLR = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(ANSELx & gpio);   
//}
//
//bool AFramework::AHardwarePort::setAnalog(const uint32 gpio) volatile{
//    /*  utilizzo il registro set associato                                      */
//    ANSELx_SET = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(ANSELx & ~gpio);
//}
//
//AFramework::uint32 AFramework::AHardwarePort::ioStatus() const volatile{
//    /*  ritorno il contenuto del registro TRIS                                  */
//    return TRISx;
//}
//
//bool AFramework::AHardwarePort::isInput(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return (TRISx & gpio);
//}
//
//bool AFramework::AHardwarePort::setInput(const uint32 gpio) volatile{
//    /*  utilizzo il registro set associato                                      */
//    TRISx_SET = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(TRISx & ~gpio);
//}
//
//bool AFramework::AHardwarePort::setOutput(const uint32 gpio) volatile{
//    /*  utilizzo il registro clr associato                                      */
//    TRISx_CLR = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(TRISx & gpio);
//}
//
//AFramework::uint32 AFramework::AHardwarePort::read() const volatile{
//    /*  ritorno il contenuto del registro port                                  */
//    return PORTx;
//}
//
//AFramework::LogicLevel AFramework::AHardwarePort::read(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return ((PORTx & gpio) ? Hi : Lo);
//}
//
//bool AFramework::AHardwarePort::portWrite(const uint32 value) volatile{
//    /*  utilizzo il registro clr associato per azzerare la il registro PORT     */
//    PORTx_CLR = Quick::All;
//    /*  utilizzo il registro set per scrivere il valore                         */
//    PORTx_SET = value;
//    /*  controllo che il valore sia stato scritto correttamente                 */
//    return (PORTx == value);
//}
//
//bool AFramework::AHardwarePort::portWrite(const uint32 gpio, const LogicLevel value) volatile{
//    /*  se devo mettere alto                                                    */
//    if(value == Hi){
//        /*  utilizzo il registro set associato                                  */
//        PORTx_SET = gpio;
//        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
//        return !(PORTx & ~gpio);
//    /*  se invece devo mettere basso                                            */
//    }else if(value == Lo){
//        /*  utilizzo il registro clr associato                                  */
//        PORTx_CLR = gpio;
//        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
//        return !(PORTx & gpio);       
//    }
//}
//
//bool AFramework::AHardwarePort::portInvert(const uint32 gpio) volatile{
//    uint32 tmp = PORTx;
//    /*  utilizzo il registro inv associato                                      */
//    PORTx_INV = gpio;
//    /*  utilizzando il valore salvato prima restituisco l'and negato            */
//    return !((tmp ^ PORTx) ^ gpio);
//}
//
//AFramework::uint32 AFramework::AHardwarePort::latchRead() const volatile{
//    /*  ritorno il contenuto del registro LAT                                   */
//    return LATx;
//}
//
//AFramework::LogicLevel AFramework::AHardwarePort::latchRead(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return ((LATx & gpio) ? Hi : Lo);
//}
//
//bool AFramework::AHardwarePort::write(const uint32 value) volatile{
//    /*  utilizzo il registro clr per azzerare il registro LAT                   */
//    LATx_CLR = Quick::All;
//    /*  utilizzo il registro set per scrivere il valore                         */
//    LATx_SET = value;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return (LATx == value);
//}
//
//bool AFramework::AHardwarePort::write(const uint32 gpio, const LogicLevel value) volatile{
//    /*  se devo mettere alto                                                    */
//    if(value == Hi){
//        /*  utilizzo il registro set associato                                  */
//        LATx_SET = gpio;
//        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */        
//        return !(LATx & ~gpio );
//    /*  se invece devo mettere basso                                            */
//    }else if(value == Lo){
//        /*  utilizzo il registro clr associato                                  */
//        LATx_CLR = gpio;
//        /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i   */
//        return !(LATx & gpio);
//    }
//}
//
//bool AFramework::AHardwarePort::latchInvert(const uint32 gpio) volatile{
//    uint32 tmp = LATx;
//    /*  utilizzo il registro inv associato                                      */
//    LATx_INV = gpio;
//    /*  utilizzando il valore salvato prima restituisco l'and negato            */
//    return !((tmp ^ LATx) ^ gpio);
//}
//
//AFramework::uint32 AFramework::AHardwarePort::openDrainStatus() const volatile{
//    /*  ritorno il contenuto del registro odc                                   */
//    return ODCx;
//}
//
//bool AFramework::AHardwarePort::isOpenDrain(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return (ODCx & gpio);
//}
//
//bool AFramework::AHardwarePort::setOpenDrain(const uint32 gpio) volatile{
//    /*  utilizzo il registro set associato                                      */
//    ODCx_SET = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(ODCx & ~gpio);
//}
//
//bool AFramework::AHardwarePort::setStandard(const uint32 gpio) volatile{
//    /* utilizzo il registro clr associato                                       */
//    ODCx_CLR = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(ODCx & gpio);
//}
//
//AFramework::uint32 AFramework::AHardwarePort::pullUpStatus() const volatile{
//    /*  ritorno il contenuto del registro cnpu                                  */
//    return CNPUx;
//}
//
//bool AFramework::AHardwarePort::isPullUpEnabled(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return (CNPUx & gpio);
//}
//
//bool AFramework::AHardwarePort::enablePullUp(const uint32 gpio) volatile{
//    /*  disabilito i pull down sui gpio passati                                 */
//    CNPDx_CLR = gpio;
//    /*  abilito i pull up sui gpio passati                                      */
//    CNPUx_SET = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(CNPUx & ~gpio);
//}
//
//bool AFramework::AHardwarePort::disablePullUp(const uint32 gpio) volatile{
//    /*  utilizzo il registro clr associato                                      */
//    CNPUx_CLR = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(CNPUx & gpio);
//}
//
//AFramework::uint32 AFramework::AHardwarePort::pullDownStatus() const volatile{
//    /*  ritorno il contenuto del registro cnpd                                  */
//    return CNPDx;
//}
//
//bool AFramework::AHardwarePort::isPullDownEnabled(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return (CNPDx & gpio);
//}
//
//bool AFramework::AHardwarePort::enablePullDown(const uint32 gpio) volatile{
//    /*  disabilito i pull up sui gpio passati                                   */
//    CNPUx_CLR = gpio;
//    /*  abilito i pull down sui gpio passati                                    */
//    CNPDx_SET = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(CNPDx & ~gpio);
//}
//
//bool AFramework::AHardwarePort::disablePullDown(const uint32 gpio) volatile{
//    /*  utilizzo il registro clr associato                                      */
//    CNPDx_CLR = gpio;
//    /*  controllo che il/i bit sia/siano stato/i effettivamente settato/i       */
//    return !(CNPDx & gpio);
//}
//
//bool AFramework::AHardwarePort::isInterrutptEnabled() const volatile{
//    
//    /*  dovrebbe venire qualcosa tipo l'and con CNCON (bit ON) e l'enable del   */
//    /*  controller dell'interrupt                                               */
//    #warning "Check dell'interrupt non ancora implementato"
//    return false;
//}
//
//void AFramework::AHardwarePort::enableInterrupt(const uint32 gpio, const Priority pri, const SubPriority, const bool idleStop) volatile{
//    #warning "Abilitazione interrupt non ancora implementata"
//}
//
//void AFramework::AHardwarePort::disableInterrupt() volatile{
//    /*  utilizzo il registro clr associato                                      */
//    CNCONx_CLR = Quick::All;
//    #warning "Disabilitazione da controller dell'interrupt non ancora implementata"
//}
//
//AFramework::uint32 AFramework::AHardwarePort::changeNoticeStatus() const volatile{
//    /*  ritorno il contenuto del registro cnstat                                */
//    return CNSTATx;
//}
//
//bool AFramework::AHardwarePort::hasInterruptOccurred(const uint32 gpio) const volatile{
//    /*  ritorno l'and con il gpio passato                                       */
//    return CNSTATx & gpio;
//}
//
//void AFramework::AHardwarePort::resetInterruptFlag(const uint32 gpio) volatile{
//    /*  azzero i flag di change notice sui gpio richiesti (generalmente tutti)  */
//    /*  ma non sapendo cosa la gente ha in testa devo dare questa possibilità   */
//    CNSTATx_CLR = gpio;
//    #warning "Pulizia flag interrupt da controller dell'interrupt non ancora implementata"
//}
