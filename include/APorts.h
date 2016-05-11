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

#ifndef APORT_A
#define APORT_A

#include "ACore.h"
#include "AIODevice.h"
#include "AErrorNotifier.h"

namespace AFramework{
    
    extern const volatile uint32 All;
    extern const volatile uint32 NoOne;
    
    class AHardwarePort{
        public:
            AHardwarePort();     
            
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
            bool portWrite(const uint32 gpios, const LogicLevel value) volatile;
            bool portInvert(const uint32 & gpios) volatile;
            
            uint32 latchRead() const volatile;
            LogicLevel latchRead(const uint32 gpio) const volatile;
            bool write(const uint32 value) volatile;
            bool write(const uint32 gpios, const LogicLevel value) volatile;
            bool latchInvert(const uint32 gpios) volatile;
            
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
            void enableInterrupt(const uint32 gpios, const Priority pri, const SubPriority = SubPriority::Isp0, const bool idleStop = false) volatile;
            void disableInterrupt() volatile;
            uint32 changeNoticeStatus() const volatile;
            bool hasInterruptOccurred(const uint32 gpio) const volatile;
            void resetInterruptFlag(const uint32 gpios = All) volatile;
        private:
            volatile uint32 m_ANSELx;
            volatile uint32 m_ANSELx_CLR;
            volatile uint32 m_ANSELx_SET;
            volatile uint32 m_ANSELx_INV;
            volatile uint32 m_TRISx;
            volatile uint32 m_TRISx_CLR;
            volatile uint32 m_TRISx_SET;
            volatile uint32 m_TRISx_INV;
            volatile uint32 m_PORTx;
            volatile uint32 m_PORTx_CLR;
            volatile uint32 m_PORTx_SET;
            volatile uint32 m_PORTx_INV;
            volatile uint32 m_LATx;
            volatile uint32 m_LATx_CLR;
            volatile uint32 m_LATx_SET;
            volatile uint32 m_LATx_INV;
            volatile uint32 m_ODCx;
            volatile uint32 m_ODCx_CLR;
            volatile uint32 m_ODCx_SET;
            volatile uint32 m_ODCx_INV;
            volatile uint32 m_CNPUx;
            volatile uint32 m_CNPUx_CLR;
            volatile uint32 m_CNPUx_SET;
            volatile uint32 m_CNPUx_INV;
            volatile uint32 m_CNPDx;
            volatile uint32 m_CNPDx_CLR;
            volatile uint32 m_CNPDx_SET;
            volatile uint32 m_CNPDx_INV;
            volatile uint32 m_CNCONx;
            volatile uint32 m_CNCONx_CLR;
            volatile uint32 m_CNCONx_SET;
            volatile uint32 m_CNCONx_INV;
            volatile uint32 m_CNENx;
            volatile uint32 m_CNENx_CLR;
            volatile uint32 m_CNENx_SET;
            volatile uint32 m_CNENx_INV;
            volatile uint32 m_CNSTATx;
            volatile uint32 m_CNSTATx_CLR;
            volatile uint32 m_CNSTATx_SET;
            volatile uint32 m_CNSTATx_INV;
    };

    #ifdef ANTIPODE32MR

        extern const volatile uint32 A0;
        extern const volatile uint32 A1;
        extern const volatile uint32 A4;
        extern const volatile uint32 A7;
        extern const volatile uint32 A8;
        extern const volatile uint32 A9;
        extern const volatile uint32 A10;

        extern const volatile uint32 B0;
        extern const volatile uint32 B1;
        extern const volatile uint32 B2;
        extern const volatile uint32 B3;
        extern const volatile uint32 B4;
        extern const volatile uint32 B5;
        extern const volatile uint32 B7;
        extern const volatile uint32 B8;
        extern const volatile uint32 B9;
        extern const volatile uint32 B10;
        extern const volatile uint32 B11;
        extern const volatile uint32 B13;
        extern const volatile uint32 B14;
        extern const volatile uint32 B15;

        extern const volatile uint32 C0;
        extern const volatile uint32 C1;
        extern const volatile uint32 C2;
        extern const volatile uint32 C3;
        extern const volatile uint32 C4;
        extern const volatile uint32 C5;
        extern const volatile uint32 C6;
        extern const volatile uint32 C7;
        extern const volatile uint32 C8;
        extern const volatile uint32 C9;
        
        extern volatile AHardwarePort PortA;
        extern volatile AHardwarePort PortB;
        extern volatile AHardwarePort PortC;
        
    #elif defined PIC32MX270f256B

        extern const volatile uint32 A0;
        extern const volatile uint32 A1;
        extern const volatile uint32 A2;
        extern const volatile uint32 A3;
        extern const volatile uint32 A4;

        extern const volatile uint32 B0;
        extern const volatile uint32 B1;
        extern const volatile uint32 B2;
        extern const volatile uint32 B3;
        extern const volatile uint32 B4;
        extern const volatile uint32 B5;
        extern const volatile uint32 B7;
        extern const volatile uint32 B8;
        extern const volatile uint32 B9;
        extern const volatile uint32 B10;
        extern const volatile uint32 B11;
        extern const volatile uint32 B13;
        extern const volatile uint32 B14;
        extern const volatile uint32 B15;
        
        extern volatile AHardwarePort PortA;
        extern volatile AHardwarePort PortB;
        
    #endif
    

    
}
#endif // APORT_A
