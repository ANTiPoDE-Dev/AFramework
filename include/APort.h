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

#include "ACommons.h"
#include "APortDefs.h"

namespace AFramework{

    class APort{
        public:
//            APort();
//            void config(const uint32 & out, const uint32 & in, const uint32 & odc);
//            void invert(const uint32 & gpios);
//            void write(const uint32 & gpios);
//            bool read(const uint32 & gpios);
            
        private:
            uint32 m_ANSEL;
            uint32 m_ANSEL_CLR;
            uint32 m_ANSEL_SET;
            uint32 m_ANSEL_INV;
            uint32 m_TRIS;
            uint32 m_TRIS_CLR;
            uint32 m_TRIS_SET;
            uint32 m_TRIS_INV;
            uint32 m_PORT;
            uint32 m_PORT_CLR;
            uint32 m_PORT_SET;
            uint32 m_PORT_INV;
            uint32 m_LAT;
            uint32 m_LAT_CLR;
            uint32 m_LAT_SET;
            uint32 m_LAT_INV;
            uint32 m_ODC;
            uint32 m_ODC_CLR;
            uint32 m_ODC_SET;
            uint32 m_ODC_INV;
            uint32 m_CNPU;
            uint32 m_CNPU_CLR;
            uint32 m_CNPU_SET;
            uint32 m_CNPU_INV;
            uint32 m_CNPD;
            uint32 m_CNPD_CLR;
            uint32 m_CNPD_SET;
            uint32 m_CNPD_INV;
            uint32 m_CNCON;
            uint32 m_CNCON_CLR;
            uint32 m_CNCON_SET;
            uint32 m_CNCON_INV;
            uint32 m_CNEN;
            uint32 m_CNEN_CLR;
            uint32 m_CNEN_SET;
            uint32 m_CNEN_INV;
            uint32 m_CNSTAT;
            uint32 m_CNSTAT_CLR;
            uint32 m_CNSTAT_SET;
            uint32 m_CNSTAT_INV;
    };
    
    APort PortA __attribute__((address(0xBF886000)));
    APort PortB __attribute__((address(0xBF886100)));
    APort PortC __attribute__((address(0xBF886200)));
}
#endif // APORT_A
