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

#ifndef APORTS_H
#define APORTS_H

#include "ACore.h"

namespace AFramework{
    
    class APORT_w;
    
    class AHardwarePort{
        public:
            AHardwarePort(volatile APORT_w * w, const volatile uint32 id);     
            
            uint32 adcStatus() const volatile;
            bool isAnalog(const uint32 gpio) const volatile;
            bool setDigital(const uint32 gpio) volatile;
            bool setAnalog(const uint32 gpio) volatile;
            
            uint32 ioStatus() const volatile;
            bool isInput(const uint32 gpio) const volatile;
            bool setInput(const uint32 gpio) volatile;
            bool setOutput(const uint32 gpio) volatile;
            
            uint32 read() const volatile;
            LogicLevel read(const uint32 gpio) const volatile;
            bool portWrite(const uint32 value) volatile;
            bool portWrite(const uint32 gpio, const LogicLevel value) volatile;
            bool portInvert(const uint32 gpio) volatile;
            
            uint32 latchRead() const volatile;
            LogicLevel latchRead(const uint32 gpio) const volatile;
            bool write(const uint32 value) volatile;
            bool write(const uint32 gpio, const LogicLevel value) volatile;
            bool latchInvert(const uint32 gpio) volatile;
            
            uint32 openDrainStatus() const volatile;
            bool isOpenDrain(const uint32 gpio) const volatile;
            bool setOpenDrain(const uint32 gpio) volatile;
            bool setStandard(const uint32 gpio) volatile;
            
            uint32 pullUpStatus() const volatile;
            bool isPullUpEnabled(const uint32 gpio) const volatile;
            bool enablePullUp(const uint32 gpio) volatile;
            bool disablePullUp(const uint32 gpio) volatile;
            
            uint32 pullDownStatus() const volatile;
            bool isPullDownEnabled(const uint32 gpio) const volatile;
            bool enablePullDown(const uint32 gpio) volatile;
            bool disablePullDown(const uint32 gpio) volatile;
            
            bool isInterrutptEnabled() const volatile;
            void enableInterrupt(const uint32 gpio, const Priority pri, const SubPriority sub = Isp0, const bool idleStop = false) volatile;
            void disableInterrupt() volatile;
            uint32 changeNoticeStatus() const volatile;
            bool hasInterruptOccurred(const uint32 gpio) const volatile;
            void resetInterruptFlag(const uint32 gpio = Quick::All) volatile;
        private:
            volatile APORT_w * m_preg;
            volatile uint32    m_prid;
    };
    
#if (__HAS__PORTA__)
    extern volatile AHardwarePort PortA;
#   if(__PORTA_BITS__ & __BIT_0__)
    extern const volatile uint32 A0;
#   endif
#   if(__PORTA_BITS__ & __BIT_1__)
    extern const volatile uint32 A1;
#   endif
#   if(__PORTA_BITS__ & __BIT_2__)
    extern const volatile uint32 A2;
#   endif
#   if(__PORTA_BITS__ & __BIT_3__)
    extern const volatile uint32 A3;
#   endif
#   if(__PORTA_BITS__ & __BIT_4__)
    extern const volatile uint32 A4;
#   endif
#   if(__PORTA_BITS__ & __BIT_5__)
    extern const volatile uint32 A5;
#   endif
#   if(__PORTA_BITS__ & __BIT_6__)
    extern const volatile uint32 A6;
#   endif
#   if(__PORTA_BITS__ & __BIT_7__)
    extern const volatile uint32 A7;
#   endif
#   if(__PORTA_BITS__ & __BIT_8__)
    extern const volatile uint32 A8;
#   endif
#   if(__PORTA_BITS__ & __BIT_9__)
    extern const volatile uint32 A9;
#   endif
#   if(__PORTA_BITS__ & __BIT_A__)
    extern const volatile uint32 A10;
#   endif
#   if(__PORTA_BITS__ & __BIT_B__)
    extern const volatile uint32 A11;
#   endif
#   if(__PORTA_BITS__ & __BIT_C__)
    extern const volatile uint32 A12;
#   endif
#   if(__PORTA_BITS__ & __BIT_D__)
    extern const volatile uint32 A13;
#   endif
#   if(__PORTA_BITS__ & __BIT_E__)
    extern const volatile uint32 A14;
#   endif
#   if(__PORTA_BITS__ & __BIT_F__)
    extern const volatile uint32 A15;
#   endif
#endif
    
#if (__HAS__PORTB__)
    extern volatile AHardwarePort PortB;
#   if(__PORTB_BITS__ & __BIT_0__)
    extern const volatile uint32 B0;
#   endif
#   if(__PORTB_BITS__ & __BIT_1__)
    extern const volatile uint32 B1;
#   endif
#   if(__PORTB_BITS__ & __BIT_2__)
    extern const volatile uint32 B2;
#   endif
#   if(__PORTB_BITS__ & __BIT_3__)
    extern const volatile uint32 B3;
#   endif
#   if(__PORTB_BITS__ & __BIT_4__)
    extern const volatile uint32 B4;
#   endif
#   if(__PORTB_BITS__ & __BIT_5__)
    extern const volatile uint32 B5;
#   endif
#   if(__PORTB_BITS__ & __BIT_6__)
    extern const volatile uint32 B6;
#   endif
#   if(__PORTB_BITS__ & __BIT_7__)
    extern const volatile uint32 B7;
#   endif
#   if(__PORTB_BITS__ & __BIT_8__)
    extern const volatile uint32 B8;
#   endif
#   if(__PORTB_BITS__ & __BIT_9__)
    extern const volatile uint32 B9;
#   endif
#   if(__PORTB_BITS__ & __BIT_A__)
    extern const volatile uint32 B10;
#   endif
#   if(__PORTB_BITS__ & __BIT_B__)
    extern const volatile uint32 B11;
#   endif
#   if(__PORTB_BITS__ & __BIT_C__)
    extern const volatile uint32 B12;
#   endif
#   if(__PORTB_BITS__ & __BIT_D__)
    extern const volatile uint32 B13;
#   endif
#   if(__PORTB_BITS__ & __BIT_E__)
    extern const volatile uint32 B14;
#   endif
#   if(__PORTB_BITS__ & __BIT_F__)
    extern const volatile uint32 B15;
#   endif
#endif

#if (__HAS__PORTC__)
    extern volatile AHardwarePort PortC;
#   if(__PORTC_BITS__ & __BIT_0__)
    extern const volatile uint32 C0;
#   endif
#   if(__PORTC_BITS__ & __BIT_1__)
    extern const volatile uint32 C1;
#   endif
#   if(__PORTC_BITS__ & __BIT_2__)
    extern const volatile uint32 C2;
#   endif
#   if(__PORTC_BITS__ & __BIT_3__)
    extern const volatile uint32 C3;
#   endif
#   if(__PORTC_BITS__ & __BIT_4__)
    extern const volatile uint32 C4;
#   endif
#   if(__PORTC_BITS__ & __BIT_5__)
    extern const volatile uint32 C5;
#   endif
#   if(__PORTC_BITS__ & __BIT_6__)
    extern const volatile uint32 C6;
#   endif
#   if(__PORTC_BITS__ & __BIT_7__)
    extern const volatile uint32 C7;
#   endif
#   if(__PORTC_BITS__ & __BIT_8__)
    extern const volatile uint32 C8;
#   endif
#   if(__PORTC_BITS__ & __BIT_9__)
    extern const volatile uint32 C9;
#   endif
#   if(__PORTC_BITS__ & __BIT_A__)
    extern const volatile uint32 C10;
#   endif
#   if(__PORTC_BITS__ & __BIT_B__)
    extern const volatile uint32 C11;
#   endif
#   if(__PORTC_BITS__ & __BIT_C__)
    extern const volatile uint32 C12;
#   endif
#   if(__PORTC_BITS__ & __BIT_D__)
    extern const volatile uint32 C13;
#   endif
#   if(__PORTC_BITS__ & __BIT_E__)
    extern const volatile uint32 C14;
#   endif
#   if(__PORTC_BITS__ & __BIT_F__)
    extern const volatile uint32 C15;
#   endif
#endif

#if (__HAS__PORTD__)
    extern volatile AHardwarePort PortD;
#   if(__PORTD_BITS__ & __BIT_0__)
    extern const volatile uint32 D0;
#   endif
#   if(__PORTD_BITS__ & __BIT_1__)
    extern const volatile uint32 D1;
#   endif
#   if(__PORTD_BITS__ & __BIT_2__)
    extern const volatile uint32 D2;
#   endif
#   if(__PORTD_BITS__ & __BIT_3__)
    extern const volatile uint32 D3;
#   endif
#   if(__PORTD_BITS__ & __BIT_4__)
    extern const volatile uint32 D4;
#   endif
#   if(__PORTD_BITS__ & __BIT_5__)
    extern const volatile uint32 D5;
#   endif
#   if(__PORTD_BITS__ & __BIT_6__)
    extern const volatile uint32 D6;
#   endif
#   if(__PORTD_BITS__ & __BIT_7__)
    extern const volatile uint32 D7;
#   endif
#   if(__PORTD_BITS__ & __BIT_8__)
    extern const volatile uint32 D8;
#   endif
#   if(__PORTD_BITS__ & __BIT_9__)
    extern const volatile uint32 D9;
#   endif
#   if(__PORTD_BITS__ & __BIT_A__)
    extern const volatile uint32 D10;
#   endif
#   if(__PORTD_BITS__ & __BIT_B__)
    extern const volatile uint32 D11;
#   endif
#   if(__PORTD_BITS__ & __BIT_C__)
    extern const volatile uint32 D12;
#   endif
#   if(__PORTD_BITS__ & __BIT_D__)
    extern const volatile uint32 D13;
#   endif
#   if(__PORTD_BITS__ & __BIT_E__)
    extern const volatile uint32 D14;
#   endif
#   if(__PORTD_BITS__ & __BIT_F__)
    extern const volatile uint32 D15;
#   endif
#endif

#if (__HAS__PORTE__)
    extern volatile AHardwarePort PortE;
#   if(__PORTE_BITS__ & __BIT_0__)
    extern const volatile uint32 E0;
#   endif
#   if(__PORTE_BITS__ & __BIT_1__)
    extern const volatile uint32 E1;
#   endif
#   if(__PORTE_BITS__ & __BIT_2__)
    extern const volatile uint32 E2;
#   endif
#   if(__PORTE_BITS__ & __BIT_3__)
    extern const volatile uint32 E3;
#   endif
#   if(__PORTE_BITS__ & __BIT_4__)
    extern const volatile uint32 E4;
#   endif
#   if(__PORTE_BITS__ & __BIT_5__)
    extern const volatile uint32 E5;
#   endif
#   if(__PORTE_BITS__ & __BIT_6__)
    extern const volatile uint32 E6;
#   endif
#   if(__PORTE_BITS__ & __BIT_7__)
    extern const volatile uint32 E7;
#   endif
#   if(__PORTE_BITS__ & __BIT_8__)
    extern const volatile uint32 E8;
#   endif
#   if(__PORTE_BITS__ & __BIT_9__)
    extern const volatile uint32 E9;
#   endif
#   if(__PORTE_BITS__ & __BIT_A__)
    extern const volatile uint32 E10;
#   endif
#   if(__PORTE_BITS__ & __BIT_B__)
    extern const volatile uint32 E11;
#   endif
#   if(__PORTE_BITS__ & __BIT_C__)
    extern const volatile uint32 E12;
#   endif
#   if(__PORTE_BITS__ & __BIT_D__)
    extern const volatile uint32 E13;
#   endif
#   if(__PORTE_BITS__ & __BIT_E__)
    extern const volatile uint32 E14;
#   endif
#   if(__PORTE_BITS__ & __BIT_F__)
    extern const volatile uint32 E15;
#   endif
#endif
    
#if (__HAS__PORTF__)
    extern volatile AHardwarePort PortF;
#   if(__PORTF_BITS__ & __BIT_0__)
    extern const volatile uint32 F0;
#   endif
#   if(__PORTF_BITS__ & __BIT_1__)
    extern const volatile uint32 F1;
#   endif
#   if(__PORTF_BITS__ & __BIT_2__)
    extern const volatile uint32 F2;
#   endif
#   if(__PORTF_BITS__ & __BIT_3__)
    extern const volatile uint32 F3;
#   endif
#   if(__PORTF_BITS__ & __BIT_4__)
    extern const volatile uint32 F4;
#   endif
#   if(__PORTF_BITS__ & __BIT_5__)
    extern const volatile uint32 F5;
#   endif
#   if(__PORTF_BITS__ & __BIT_6__)
    extern const volatile uint32 F6;
#   endif
#   if(__PORTF_BITS__ & __BIT_7__)
    extern const volatile uint32 F7;
#   endif
#   if(__PORTF_BITS__ & __BIT_8__)
    extern const volatile uint32 F8;
#   endif
#   if(__PORTF_BITS__ & __BIT_9__)
    extern const volatile uint32 F9;
#   endif
#   if(__PORTF_BITS__ & __BIT_A__)
    extern const volatile uint32 F10;
#   endif
#   if(__PORTF_BITS__ & __BIT_B__)
    extern const volatile uint32 F11;
#   endif
#   if(__PORTF_BITS__ & __BIT_C__)
    extern const volatile uint32 F12;
#   endif
#   if(__PORTF_BITS__ & __BIT_D__)
    extern const volatile uint32 F13;
#   endif
#   if(__PORTF_BITS__ & __BIT_E__)
    extern const volatile uint32 F14;
#   endif
#   if(__PORTF_BITS__ & __BIT_F__)
    extern const volatile uint32 F15;
#   endif
#endif
    
#if (__HAS__PORTG__)
    extern volatile AHardwarePort PortG;
#   if(__PORTG_BITS__ & __BIT_0__)
    extern const volatile uint32 G0;
#   endif
#   if(__PORTG_BITS__ & __BIT_1__)
    extern const volatile uint32 G1;
#   endif
#   if(__PORTG_BITS__ & __BIT_2__)
    extern const volatile uint32 G2;
#   endif
#   if(__PORTG_BITS__ & __BIT_3__)
    extern const volatile uint32 G3;
#   endif
#   if(__PORTG_BITS__ & __BIT_4__)
    extern const volatile uint32 G4;
#   endif
#   if(__PORTG_BITS__ & __BIT_5__)
    extern const volatile uint32 G5;
#   endif
#   if(__PORTG_BITS__ & __BIT_6__)
    extern const volatile uint32 G6;
#   endif
#   if(__PORTG_BITS__ & __BIT_7__)
    extern const volatile uint32 G7;
#   endif
#   if(__PORTG_BITS__ & __BIT_8__)
    extern const volatile uint32 G8;
#   endif
#   if(__PORTG_BITS__ & __BIT_9__)
    extern const volatile uint32 G9;
#   endif
#   if(__PORTG_BITS__ & __BIT_A__)
    extern const volatile uint32 G10;
#   endif
#   if(__PORTG_BITS__ & __BIT_B__)
    extern const volatile uint32 G11;
#   endif
#   if(__PORTG_BITS__ & __BIT_C__)
    extern const volatile uint32 G12;
#   endif
#   if(__PORTG_BITS__ & __BIT_D__)
    extern const volatile uint32 G13;
#   endif
#   if(__PORTG_BITS__ & __BIT_E__)
    extern const volatile uint32 G14;
#   endif
#   if(__PORTG_BITS__ & __BIT_F__)
    extern const volatile uint32 G15;
#   endif
#endif

#if (__HAS__PORTH__)
    extern volatile AHardwarePort PortH;
#   if(__PORTH_BITS__ & __BIT_0__)
    extern const volatile uint32 H0;
#   endif
#   if(__PORTH_BITS__ & __BIT_1__)
    extern const volatile uint32 H1;
#   endif
#   if(__PORTH_BITS__ & __BIT_2__)
    extern const volatile uint32 H2;
#   endif
#   if(__PORTH_BITS__ & __BIT_3__)
    extern const volatile uint32 H3;
#   endif
#   if(__PORTH_BITS__ & __BIT_4__)
    extern const volatile uint32 H4;
#   endif
#   if(__PORTH_BITS__ & __BIT_5__)
    extern const volatile uint32 H5;
#   endif
#   if(__PORTH_BITS__ & __BIT_6__)
    extern const volatile uint32 H6;
#   endif
#   if(__PORTH_BITS__ & __BIT_7__)
    extern const volatile uint32 H7;
#   endif
#   if(__PORTH_BITS__ & __BIT_8__)
    extern const volatile uint32 H8;
#   endif
#   if(__PORTH_BITS__ & __BIT_9__)
    extern const volatile uint32 H9;
#   endif
#   if(__PORTH_BITS__ & __BIT_A__)
    extern const volatile uint32 H10;
#   endif
#   if(__PORTH_BITS__ & __BIT_B__)
    extern const volatile uint32 H11;
#   endif
#   if(__PORTH_BITS__ & __BIT_C__)
    extern const volatile uint32 H12;
#   endif
#   if(__PORTH_BITS__ & __BIT_D__)
    extern const volatile uint32 H13;
#   endif
#   if(__PORTH_BITS__ & __BIT_E__)
    extern const volatile uint32 H14;
#   endif
#   if(__PORTH_BITS__ & __BIT_F__)
    extern const volatile uint32 H15;
#   endif
#endif
    
#if (__HAS__PORTJ__)
    extern volatile AHardwarePort PortJ;
#   if(__PORTJ_BITS__ & __BIT_0__)
    extern const volatile uint32 J0;
#   endif
#   if(__PORTJ_BITS__ & __BIT_1__)
    extern const volatile uint32 J1;
#   endif
#   if(__PORTJ_BITS__ & __BIT_2__)
    extern const volatile uint32 J2;
#   endif
#   if(__PORTJ_BITS__ & __BIT_3__)
    extern const volatile uint32 J3;
#   endif
#   if(__PORTJ_BITS__ & __BIT_4__)
    extern const volatile uint32 J4;
#   endif
#   if(__PORTJ_BITS__ & __BIT_5__)
    extern const volatile uint32 J5;
#   endif
#   if(__PORTJ_BITS__ & __BIT_6__)
    extern const volatile uint32 J6;
#   endif
#   if(__PORTJ_BITS__ & __BIT_7__)
    extern const volatile uint32 J7;
#   endif
#   if(__PORTJ_BITS__ & __BIT_8__)
    extern const volatile uint32 J8;
#   endif
#   if(__PORTJ_BITS__ & __BIT_9__)
    extern const volatile uint32 J9;
#   endif
#   if(__PORTJ_BITS__ & __BIT_A__)
    extern const volatile uint32 J10;
#   endif
#   if(__PORTJ_BITS__ & __BIT_B__)
    extern const volatile uint32 J11;
#   endif
#   if(__PORTJ_BITS__ & __BIT_C__)
    extern const volatile uint32 J12;
#   endif
#   if(__PORTJ_BITS__ & __BIT_D__)
    extern const volatile uint32 J13;
#   endif
#   if(__PORTJ_BITS__ & __BIT_E__)
    extern const volatile uint32 J14;
#   endif
#   if(__PORTJ_BITS__ & __BIT_F__)
    extern const volatile uint32 J15;
#   endif
#endif
    
#if (__HAS__PORTK__)
    extern volatile AHardwarePort PortK;
#   if(__PORTK_BITS__ & __BIT_0__)
    extern const volatile uint32 K0;
#   endif
#   if(__PORTK_BITS__ & __BIT_1__)
    extern const volatile uint32 K1;
#   endif
#   if(__PORTK_BITS__ & __BIT_2__)
    extern const volatile uint32 K2;
#   endif
#   if(__PORTK_BITS__ & __BIT_3__)
    extern const volatile uint32 K3;
#   endif
#   if(__PORTK_BITS__ & __BIT_4__)
    extern const volatile uint32 K4;
#   endif
#   if(__PORTK_BITS__ & __BIT_5__)
    extern const volatile uint32 K5;
#   endif
#   if(__PORTK_BITS__ & __BIT_6__)
    extern const volatile uint32 K6;
#   endif
#   if(__PORTK_BITS__ & __BIT_7__)
    extern const volatile uint32 K7;
#   endif
#   if(__PORTK_BITS__ & __BIT_8__)
    extern const volatile uint32 K8;
#   endif
#   if(__PORTK_BITS__ & __BIT_9__)
    extern const volatile uint32 K9;
#   endif
#   if(__PORTK_BITS__ & __BIT_A__)
    extern const volatile uint32 K10;
#   endif
#   if(__PORTK_BITS__ & __BIT_B__)
    extern const volatile uint32 K11;
#   endif
#   if(__PORTK_BITS__ & __BIT_C__)
    extern const volatile uint32 K12;
#   endif
#   if(__PORTK_BITS__ & __BIT_D__)
    extern const volatile uint32 K13;
#   endif
#   if(__PORTK_BITS__ & __BIT_E__)
    extern const volatile uint32 K14;
#   endif
#   if(__PORTK_BITS__ & __BIT_F__)
    extern const volatile uint32 K15;
#   endif
#endif

}
#endif // APORTS_H
