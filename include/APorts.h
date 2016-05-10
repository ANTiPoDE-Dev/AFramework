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
#include "ACommons.h"
#include "ASystemConfig.h"
#include "AIODevice.h"

namespace AFramework{
    
    extern const uint32 All;
    extern const uint32 NoOne;

    class AHardwarePort : public AIODevice{
        friend class System;        
        public:
            AHardwarePort();
            bool open() volatile;
            bool close() volatile;
            bool isOpen() const volatile;
            uint32 read() const volatile;
            bool write(const uint32 & val) volatile;
        protected:
            volatile uint32 m_ANSEL;
            volatile uint32 m_ANSEL_CLR;
            volatile uint32 m_ANSEL_SET;
            volatile uint32 m_ANSEL_INV;
            volatile uint32 m_TRIS;
            volatile uint32 m_TRIS_CLR;
            volatile uint32 m_TRIS_SET;
            volatile uint32 m_TRIS_INV;
            volatile uint32 m_PORT;
            volatile uint32 m_PORT_CLR;
            volatile uint32 m_PORT_SET;
            volatile uint32 m_PORT_INV;
            volatile uint32 m_LAT;
            volatile uint32 m_LAT_CLR;
            volatile uint32 m_LAT_SET;
            volatile uint32 m_LAT_INV;
            volatile uint32 m_ODC;
            volatile uint32 m_ODC_CLR;
            volatile uint32 m_ODC_SET;
            volatile uint32 m_ODC_INV;
            volatile uint32 m_CNPU;
            volatile uint32 m_CNPU_CLR;
            volatile uint32 m_CNPU_SET;
            volatile uint32 m_CNPU_INV;
            volatile uint32 m_CNPD;
            volatile uint32 m_CNPD_CLR;
            volatile uint32 m_CNPD_SET;
            volatile uint32 m_CNPD_INV;
            volatile uint32 m_CNCON;
            volatile uint32 m_CNCON_CLR;
            volatile uint32 m_CNCON_SET;
            volatile uint32 m_CNCON_INV;
            volatile uint32 m_CNEN;
            volatile uint32 m_CNEN_CLR;
            volatile uint32 m_CNEN_SET;
            volatile uint32 m_CNEN_INV;
            volatile uint32 m_CNSTAT;
            volatile uint32 m_CNSTAT_CLR;
            volatile uint32 m_CNSTAT_SET;
            volatile uint32 m_CNSTAT_INV;
    };
    
    #ifdef ANTIPODE32MR
        class APortA : public AHardwarePort{
            public:
                enum Gpio{
                            A0  = 0x0001U,
                            A1  = 0x0002U,
                            A4  = 0x0010U,
                            A7  = 0x0080U,
                            A8  = 0x0100U,
                            A9  = 0x0200U,
                            A10 = 0x0400U
                         };
                char getChar() const volatile;
                bool putChar(const char & chr) volatile;
                bool good() const volatile;
                AErrors lastError() const volatile;
            private:
                void errset(const AErrors & err = NoError) const volatile;
                uint32 devnum() const volatile;
        };
    
        class APortB : public AHardwarePort{
            public:
                enum Gpio{
                            B0  = 0x20001U,
                            B1  = 0x20002U,
                            B2  = 0x20004U,
                            B3  = 0x20008U,
                            B4  = 0x20010U,
                            B5  = 0x20020U,
                            B7  = 0x20080U,
                            B8  = 0x20100U,
                            B9  = 0x20200U,
                            B10 = 0x20400U,
                            B11 = 0x20800U,
                            B13 = 0x22000U,
                            B14 = 0x24000U,
                            B15 = 0x28000U,
                         };
                char getChar() const volatile;
                bool putChar(const char & chr) volatile;
                bool good() const volatile;
                AErrors lastError() const volatile;
            private:
                void errset(const AErrors & err = NoError) const volatile;
                uint32 devnum() const volatile;
        };
        
        class APortC : public AHardwarePort{
            public:
                enum Gpio{
                            C0  = 0x40001U,
                            C1  = 0x40002U,
                            C2  = 0x40004U,
                            C3  = 0x40008U,
                            C4  = 0x40010U,
                            C5  = 0x40020U,
                            C6  = 0x40040U,
                            C7  = 0x40080U,
                            C8  = 0x40100U,
                            C9  = 0x40200U
                         };
                char getChar() const volatile;
                bool putChar(const char & chr) volatile;
                bool good() const volatile;
                AErrors lastError() const volatile;
            private:
                void errset(const AErrors & err = NoError) const volatile;
                uint32 devnum() const volatile;
        };
        
        extern volatile APortA PortA;
        extern volatile APortB PortB;
        extern volatile APortC PortC;
        
    #endif

    class AUserPort : public AError{
        
    };
    
}
#endif // APORT_A
