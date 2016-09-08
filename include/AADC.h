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

#ifndef AADC_H
#define	AADC_H

#include "ACommons.h"
#include "ARegisterDefs.h"

namespace AFramework{
    
    class AADC{
    
        public:
            enum Channel{
                #if (__HAS__ADCCH0__)
                      AN0  = 0x00 
                #endif
                #if (__HAS__ADCCH1__)
                    , AN1  = 0x01
                #endif
                #if (__HAS__ADCCH2__)
                    , AN2  = 0x02
                #endif
                #if (__HAS__ADCCH3__)
                    , AN3  = 0x03
                #endif
                #if (__HAS__ADCCH4__)
                    , AN4  = 0x04
                #endif
                #if (__HAS__ADCCH5__)
                    , AN5  = 0x05
                #endif
                #if (__HAS__ADCCH6__)
                    , AN6  = 0x06
                #endif
                #if (__HAS__ADCCH7__)
                    , AN7  = 0x07
                #endif
                #if (__HAS__ADCCH8__)
                    , AN8  = 0x08
                #endif
                #if (__HAS__ADCCH9__)
                    , AN9  = 0x09
                #endif
                #if (__HAS__ADCCHA__)
                    , AN10 = 0x0A
                #endif
                #if (__HAS__ADCCHB__)
                    , AN11 = 0x0B
                #endif
                #if (__HAS__ADCCHC__)
                    , AN12 = 0x0C
                #endif
                #if (__HAS__ADCCHD__)
                    , AN13 = 0x0D
                #endif
                #if (__HAS__ADCCHE__)
                    , AN14 = 0x0E
                #endif
                #if (__HAS__ADCCHF__)
                    , AN15 = 0x0F
                #endif
            };
            
            AADC(volatile AADC_w * reg);
            
            uint32 read(const Channel ch) volatile;
            
        private:
            volatile AADC_w * m_reg;
    };
    
    extern volatile AADC ADC;
}

#endif	/* AADC_H */

