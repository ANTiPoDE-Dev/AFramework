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

#ifndef AREGISTERDEFS_H
#define AREGISTERDEFS_H

#include "ASystemConfig.h"
#include "ACommons.h"

#if   defined (__32MX__)

#define __IFSVEC_SIZE__ 0x03
#define __IECVEC_SIZE__ 0x03
#define __IPCVEC_SIZE__ 0x0D
#define __RPnVEC_SIZE__ 
namespace AFramework{
    
    namespace ARegTypes{
        
        class ACSIReg{
            public:
                volatile uint32 REG;
                volatile uint32 CLR;
                volatile uint32 SET;
                volatile uint32 INV;
        };
    
        class ACxxReg{
            public:
                volatile uint32 REG;
                volatile uint32 CLR;
                volatile uint32 : 0x20;
                volatile uint32 : 0x20;
        };
    
        class AxxxReg{
            public:
                volatile uint32 REG;
                volatile uint32 : 0x20;
                volatile uint32 : 0x20;
                volatile uint32 : 0x20;
        };
    
        class APad{
            public:
                volatile uint32 : 0x20;
                volatile uint32 : 0x20;
                volatile uint32 : 0x20;
                volatile uint32 : 0x20;
        };
    
        class AStdReg{
            public:
                volatile uint32 REG;
        };
        
    }
    
    /*  OK                                                                      */
    class AWDT_w{
        public:
            volatile ARegTypes::ACSIReg WDTCON;
    };
    /*  OK                                                                      */
    class ARTCC_w{
        public:
            volatile ARegTypes::ACSIReg RTCCON;
            volatile ARegTypes::ACSIReg RTCALRM;
            volatile ARegTypes::ACSIReg RTCTIME;
            volatile ARegTypes::ACSIReg RTCDATE;
            volatile ARegTypes::ACSIReg ALRMTIME;
            volatile ARegTypes::ACSIReg ALRMDATE;
    };
    /*  OK                                                                      */
    class ATMR_w{
        public:
            volatile ARegTypes::ACSIReg TxCON;
            volatile ARegTypes::ACSIReg TMRx;
            volatile ARegTypes::ACSIReg PRx;
    };
    
//    class AIC_w{
//        public:
//    };
    
//    class AOC_w{
//        public:
//    };
    
//    class AI2C_w{
//        public:
//    };
    
//    class ASPI_w{
//        public:
//    };
    
//    class AUART_w{
//        public:
//    };
    
//    class APMP_w{
//        public:
//    };
    
//    class AADC_w{
//        public:
//    };
    
//    class ACVRef_w{
//        public:
//    };
    
//    class ACMP_w{
//        public:
//    };
    
//    class ACMPStat_w{
//        public:
//    };
    
//    class ACMTU_w{
//        public:
//    };
    
//    class AOSC_w{
//        public:
//    };
    
//    class ADEVSPEC_w{
//        public:
//    };
    
//    class APMD_w{
//        public:
//    };
    
//    class ANVM_w{
//        public:
//    };
    
//    class ARST_w{
//        public:
//    };

#   if defined (__DEVCLASS1__) || defined (__DEVCLASS2__) || defined (__DEVCLASS4__)
    class ARPI_w{                                                               
        public:
    };
    
    class ARPO_w{                                                               
        public:
            volatile ARegTypes::AStdReg RPn[];
    };
#   endif
    
    class AINT_w{
        public:
            volatile ARegTypes::ACSIReg INTCON;
            volatile ARegTypes::AxxxReg INTSTAT;
            volatile ARegTypes::ACSIReg IPTMR;
            volatile ARegTypes::ACSIReg IFS[__IFSVEC_SIZE__];
            volatile ARegTypes::ACSIReg IEC[__IECVEC_SIZE__];
            volatile ARegTypes::ACSIReg IPC[__IPCVEC_SIZE__];
    };
    
//    class ABMX_w{
//    };
    
//    class ADMAGlob_w{
//        public:
//    };
    
//    class ADMACrc_w{
//        public:
//    };
    
//    class ADMACh_w{
//        public:
//    };
    
#   warning USB is currently unimplemented
    
#   if defined (__DEVCLASS1__) || defined (__DEVCLASS2__) || defined (__DEVCLASS4__)
    class APORT_w{
        public:
            volatile ARegTypes::ACSIReg ANSELx;
            volatile ARegTypes::ACSIReg TRISx;
            volatile ARegTypes::ACSIReg PORTx;
            volatile ARegTypes::ACSIReg LATx;
            volatile ARegTypes::ACSIReg ODCx;
            volatile ARegTypes::ACSIReg CNPUx;
            volatile ARegTypes::ACSIReg CNPDx;
            volatile ARegTypes::ACSIReg CNENx;
            volatile ARegTypes::ACSIReg CNSTATx;
    };
#   else
    class APORT_w{
        public:
            volatile ARegTypes::ACSIReg TRISx;
            volatile ARegTypes::ACSIReg PORTx;
            volatile ARegTypes::ACSIReg LATx;
            volatile ARegTypes::ACSIReg ODCx;
    };
#   endif
    
//    class ADEVGFG_w{
//        public:
//    };
}

#include <proc/p32mx270f256d.h>
#include <proc/p32mx460f512l.h>

#elif defined (__32MZ__)
#   error   Unknown register types for MZ family.
#else
#   error   Unknown architecture.
#endif


#endif // AREGISTERDEFS_H

#   define ___POSITION  0x
#   define ___MASK      0x
#   define ___LENGTH    0x