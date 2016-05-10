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
    
    class AHardwarePort : public AAbstractErrorNotifier{
        public:
            AHardwarePort();
            uint32 read() const volatile;
            bool write(const uint32 & val) volatile;
            bool good() const volatile;
            AErrors lastError() const volatile;
        private:
            bool chkown(const uint32 & val) const volatile;
            void errset(const AErrors &err = NoError) const volatile;
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

    extern volatile AHardwarePort PortA;
    
//    class AUserPort : public AIODevice, public AErrorNotifier{
//
//    };
    
}
#endif // APORT_A
