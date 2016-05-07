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
            APort();
            void analCfg();
            void ioCfg();
            void 
            void invert(const uint32 & gpios);
            void write(const uint32 & gpios);
            bool read(const uint32 & gpios);
            
        private:
            uint32 m_ANSEL;         //registro per impostare gli ingressi analogici
            uint32 m_ANSEL_CLR;     //      CLR associato
            uint32 m_ANSEL_SET;     //      SET associato
            uint32 m_ANSEL_INV;     //      INV associato
            uint32 m_TRIS;          //registro per impostare la direzione (1 ingresso - 0 uscita)
            uint32 m_TRIS_CLR;      //      CLR associato
            uint32 m_TRIS_SET;      //      SET associato
            uint32 m_TRIS_INV;      //      INV associato
            uint32 m_PORT;          //registro per lettura del pin fisico
            uint32 m_PORT_CLR;      //      CLR associato
            uint32 m_PORT_SET;      //      SET associato
            uint32 m_PORT_INV;      //      INV associato
            uint32 m_LAT;           //registro per controllare il latch
            uint32 m_LAT_CLR;       //      CLR associato
            uint32 m_LAT_SET;       //      SET associato
            uint32 m_LAT_INV;       //      INV associato
            uint32 m_ODC;           //registro per configurare l'open drain collecton (tensioni di ~5v anche con alimentazione a 3.3v)
            uint32 m_ODC_CLR;       //      CLR associato
            uint32 m_ODC_SET;       //      SET associato
            uint32 m_ODC_INV;       //      INV associato
            uint32 m_CNPU;          //registro per i resistori di pull-up (periferica change notice)
            uint32 m_CNPU_CLR;      //      CLR associato
            uint32 m_CNPU_SET;      //      SET associato
            uint32 m_CNPU_INV;      //      INV associato
            uint32 m_CNPD;          //registro per i resitori di pull-down (periferica change notice)
            uint32 m_CNPD_CLR;      //      CLR associato
            uint32 m_CNPD_SET;      //      SET associato
            uint32 m_CNPD_INV;      //      INV associato
            uint32 m_CNCON;         //registro per abilitare la periferica change notice
            uint32 m_CNCON_CLR;     //      CLR associato
            uint32 m_CNCON_SET;     //      SET associato
            uint32 m_CNCON_INV;     //      INV associato
            uint32 m_CNEN;          //registro per abilitare i pin da configurare con il change notice
            uint32 m_CNEN_CLR;      //      CLR associato
            uint32 m_CNEN_SET;      //      SET associato
            uint32 m_CNEN_INV;      //      INV associato
            uint32 m_CNSTAT;        //registro per controllare quale pin è cambiato di stato (periferica change notice)
            uint32 m_CNSTAT_CLR;    //      CLR associato
            uint32 m_CNSTAT_SET;    //      SET associato
            uint32 m_CNSTAT_INV;    //      INV associato
    };
    
    APort PortA __attribute__((address(0xBF886000)));
    APort PortB __attribute__((address(0xBF886100)));
    APort PortC __attribute__((address(0xBF886200)));
}
#endif // APORT_A
