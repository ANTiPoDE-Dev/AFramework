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
#include "APortDefs.h"

namespace AFramework{

    class APort{
        friend class System;        
        public:
            APort();
            uint32 adcStatus() A_CONST_COHERENT;
            bool isAnalog(const uint32 gpio) A_CONST_COHERENT;
            void setDigital(const uint32 gpio) A_COHERENT;
            void setAnalog(const uint32 gpio) A_COHERENT;
            uint32 ioStatus() A_CONST_COHERENT;
            bool isInput(const uint32 gpio) A_CONST_COHERENT;
            void setInput(const uint32 gpio) A_COHERENT;
            void setOutput(const uint32 gpio) A_COHERENT;
            uint32 portRead() A_CONST_COHERENT;
            LogicLevel portRead(const uint32 gpio) A_CONST_COHERENT;
            void portWrite(const uint32 value) A_COHERENT;
            void portWrite(const uint32 gpios, const LogicLevel value) A_COHERENT;
            void portInvert(const uint32 & gpios) A_COHERENT;
            uint32 latchRead() A_CONST_COHERENT;
            LogicLevel latchRead(const uint32 gpio) A_CONST_COHERENT;
            void latchWrite(const uint32 value) A_COHERENT;
            void latchWrite(const uint32 gpios, const LogicLevel value) A_COHERENT;
            void latchInvert(const uint32 gpios) A_COHERENT;
            uint32 openDrainStatus() A_CONST_COHERENT;
            bool isOpenDrain(const uint32 gpio) A_CONST_COHERENT;
            void setOpenDrain(const uint32 gpio) A_COHERENT;
            void setStandard(const uint32 gpio) A_COHERENT;
            uint32 pullUpStatus() A_CONST_COHERENT;
            bool isPullUpEnabled(const uint32 gpio) A_CONST_COHERENT;
            void enablePullUp(const uint32 gpio) A_COHERENT;
            void disablePullUp(const uint32 gpio) A_COHERENT;
            uint32 pullDownStatus() A_CONST_COHERENT;
            bool isPullDownEnabled(const uint32 gpio) A_CONST_COHERENT;
            void enablePullDown(const uint32 gpio) A_COHERENT;
            void disablePullDown(const uint32 gpio) A_COHERENT;
            bool isInterrutptEnabled() A_CONST_COHERENT;
            void enableInterrupt(const uint32 gpios, const Priority pri, const SubPriority = SubPriority::Isp0, const bool idleStop = false) A_COHERENT;
            void disableInterrupt() A_COHERENT;
            uint32 changeNoticeStatus() A_CONST_COHERENT;
            bool hasInterruptOccurred(const uint32 gpio) A_CONST_COHERENT;
            void resetInterruptFlag(const uint32 gpios = ALL) A_COHERENT;
        private:
            A_COHERENT uint32 m_ANSEL;         //registro per impostare gli ingressi analogici
            A_COHERENT uint32 m_ANSEL_CLR;     //      CLR associato
            A_COHERENT uint32 m_ANSEL_SET;     //      SET associato
            A_COHERENT uint32 m_ANSEL_INV;     //      INV associato
            A_COHERENT uint32 m_TRIS;          //registro per impostare la direzione (1 ingresso - 0 uscita)
            A_COHERENT uint32 m_TRIS_CLR;      //      CLR associato
            A_COHERENT uint32 m_TRIS_SET;      //      SET associato
            A_COHERENT uint32 m_TRIS_INV;      //      INV associato
            A_COHERENT uint32 m_PORT;          //registro per lettura del pin fisico
            A_COHERENT uint32 m_PORT_CLR;      //      CLR associato
            A_COHERENT uint32 m_PORT_SET;      //      SET associato
            A_COHERENT uint32 m_PORT_INV;      //      INV associato
            A_COHERENT uint32 m_LAT;           //registro per controllare il latch
            A_COHERENT uint32 m_LAT_CLR;       //      CLR associato
            A_COHERENT uint32 m_LAT_SET;       //      SET associato
            A_COHERENT uint32 m_LAT_INV;       //      INV associato
            A_COHERENT uint32 m_ODC;           //registro per configurare l'open drain collecton (tensioni di ~5v anche con alimentazione a 3.3v)
            A_COHERENT uint32 m_ODC_CLR;       //      CLR associato
            A_COHERENT uint32 m_ODC_SET;       //      SET associato
            A_COHERENT uint32 m_ODC_INV;       //      INV associato
            A_COHERENT uint32 m_CNPU;          //registro per i resistori di pull-up (periferica change notice)
            A_COHERENT uint32 m_CNPU_CLR;      //      CLR associato
            A_COHERENT uint32 m_CNPU_SET;      //      SET associato
            A_COHERENT uint32 m_CNPU_INV;      //      INV associato
            A_COHERENT uint32 m_CNPD;          //registro per i resitori di pull-down (periferica change notice)
            A_COHERENT uint32 m_CNPD_CLR;      //      CLR associato
            A_COHERENT uint32 m_CNPD_SET;      //      SET associato
            A_COHERENT uint32 m_CNPD_INV;      //      INV associato
            A_COHERENT uint32 m_CNCON;         //registro per abilitare la periferica change notice
            A_COHERENT uint32 m_CNCON_CLR;     //      CLR associato
            A_COHERENT uint32 m_CNCON_SET;     //      SET associato
            A_COHERENT uint32 m_CNCON_INV;     //      INV associato
            A_COHERENT uint32 m_CNEN;          //registro per abilitare i pin da configurare con il change notice
            A_COHERENT uint32 m_CNEN_CLR;      //      CLR associato
            A_COHERENT uint32 m_CNEN_SET;      //      SET associato
            A_COHERENT uint32 m_CNEN_INV;      //      INV associato
            A_COHERENT uint32 m_CNSTAT;        //registro per controllare quale pin è cambiato di stato (periferica change notice)
            A_COHERENT uint32 m_CNSTAT_CLR;    //      CLR associato
            A_COHERENT uint32 m_CNSTAT_SET;    //      SET associato
            A_COHERENT uint32 m_CNSTAT_INV;    //      INV associato
    };
    
    extern A_COHERENT APort PortA;
    extern A_COHERENT APort PortB;
    extern A_COHERENT APort PortC;
    
}
#endif // APORT_A
