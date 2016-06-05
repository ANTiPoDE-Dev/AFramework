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
    
    class ATMR_w{
        public:
            volatile ARegTypes::ACSIReg TxCON;
            volatile ARegTypes::ACSIReg TMRx;
            volatile ARegTypes::ACSIReg PRx;
    };
    
    class AIC_w{
        public:
            volatile ARegTypes::ACSIReg ICxCON;
            volatile ARegTypes::AxxxReg ICxBUF;
    };
    
    class AOC_w{
        public:
            volatile ARegTypes::ACSIReg OCxCON;
            volatile ARegTypes::ACSIReg OCxR;
            volatile ARegTypes::ACSIReg OCxRS;
    };
    
    class AI2C_w{
        public:
            volatile ARegTypes::ACSIReg I2CxCON;
            volatile ARegTypes::ACSIReg I2CxSTAT;
            volatile ARegTypes::ACSIReg I2CxADD;
            volatile ARegTypes::ACSIReg I2CxMSK;
            volatile ARegTypes::ACSIReg I2CxBRG;
            volatile ARegTypes::ACSIReg I2CxTRN;
            volatile ARegTypes::AxxxReg I2CxRCV;
    };
    
    class ASPI_w{
        public:
            volatile ARegTypes::ACSIReg SPIxCON;
            volatile ARegTypes::ACSIReg SPIxSTAT;
            volatile ARegTypes::AxxxReg SPIxBUF;
            volatile ARegTypes::ACSIReg SPIxBRG;
            volatile ARegTypes::ACSIReg SPIxCON2;
    };
    
    class AUART_w{
        public:
            volatile ARegTypes::ACSIReg UxMODE;
            volatile ARegTypes::ACSIReg UxSTA;
            volatile ARegTypes::AxxxReg UxTXREG;
            volatile ARegTypes::AxxxReg UxRXREG;
            volatile ARegTypes::ACSIReg UxBRG;
    };
    
    class APMP_w{
        public:
            volatile ARegTypes::ACSIReg PMCON;
            volatile ARegTypes::ACSIReg PMMODE;
            volatile ARegTypes::ACSIReg PMADDR;
            volatile ARegTypes::ACSIReg PMDOUT;
            volatile ARegTypes::ACSIReg PMDIN;
            volatile ARegTypes::ACSIReg PMAEN;
            volatile ARegTypes::ACSIReg PMSTAT;
    };
    
    class AADC_w{
        public:
            volatile ARegTypes::ACSIReg AD1CON[0x03];
            volatile uint32 ADxCON1;
            volatile uint32 ADxCON1_CLR;
            volatile uint32 ADxCON1_SET;
            volatile uint32 ADxCON1_INV;
            volatile uint32 ADxCON2;
            volatile uint32 ADxCON2_CLR;
            volatile uint32 ADxCON2_SET;
            volatile uint32 ADxCON2_INV;
            volatile uint32 ADxCON3;
            volatile uint32 ADxCON3_CLR;
            volatile uint32 ADxCON3_SET;
            volatile uint32 ADxCON3_INV;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADxCHS;
            volatile uint32 ADxCHS_CLR;
            volatile uint32 ADxCHS_SET;
            volatile uint32 ADxCHS_INV;
            volatile uint32 ADxSSL;
            volatile uint32 ADxSSL_CLR;
            volatile uint32 ADxSSL_SET;
            volatile uint32 ADxSSL_INV;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF0;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF1;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF2;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF3;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF4;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF5;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF6;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF7;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF8;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFF9;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFFA;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFFB;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFFC;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFFD;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFFE;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 ADCxBUFFF;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
    };
    
    class ACVRef_w{
        public:
            volatile uint32 CVRCON;
            volatile uint32 CVRCON_CLR;
            volatile uint32 CVRCON_SET;
            volatile uint32 CVRCON_INV;
    };
    
    class ACMP_w{
        public:
            volatile uint32 CMxCON;
            volatile uint32 CMxCON_CLR;
            volatile uint32 CMxCON_SET;
            volatile uint32 CMxCON_INV;
    };
    
    class ACMPStat_w{
        public:
            volatile uint32 CMSTAT;
            volatile uint32 CMSTAT_CLR;
            volatile uint32 CMSTAT_SET;
            volatile uint32 CMSTAT_INV;
    };
    
    class ACMTU_w{
        public:
            volatile uint32 CMTUCON;
            volatile uint32 CMTUCON_CLR;
            volatile uint32 CMTUCON_SET;
            volatile uint32 CMTUCON_INV;
    };
    
    class AOSC_w{
        public:
            volatile uint32 OSCCON;
            volatile uint32 OSCCON_CLR;
            volatile uint32 OSCCON_SET;
            volatile uint32 OSCCON_INV;
            volatile uint32 OSCTUN;
            volatile uint32 OSCTUN_CLR;
            volatile uint32 OSCTUN_SET;
            volatile uint32 OSCTUN_INV;
            volatile uint32 REFOCON;
            volatile uint32 REFOCON_CLR;
            volatile uint32 REFOCON_SET;
            volatile uint32 REFOCON_INV;
            volatile uint32 REFOTRIM;
            volatile uint32 REFOTRIM_CLR;
            volatile uint32 REFOTRIM_SET;
            volatile uint32 REFOTRIM_INV;
    };
    
    class ADEVSPEC_w{
        public:
            volatile uint32 CFGCON;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 DEVID;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 SYSKEY;
            volatile uint32 SYSKEY_CLR;
            volatile uint32 SYSKEY_SET;
            volatile uint32 SYSKEY_INV;
    };
    
    class APMD_w{
        public:
            volatile uint32 PMD1;
            volatile uint32 PMD1_CLR;
            volatile uint32 PMD1_SET;
            volatile uint32 PMD1_INV;
            volatile uint32 PMD2;
            volatile uint32 PMD2_CLR;
            volatile uint32 PMD2_SET;
            volatile uint32 PMD2_INV;
            volatile uint32 PMD3;
            volatile uint32 PMD3_CLR;
            volatile uint32 PMD3_SET;
            volatile uint32 PMD3_INV;
            volatile uint32 PMD4;
            volatile uint32 PMD4_CLR;
            volatile uint32 PMD4_SET;
            volatile uint32 PMD4_INV;
            volatile uint32 PMD5;
            volatile uint32 PMD5_CLR;
            volatile uint32 PMD5_SET;
            volatile uint32 PMD5_INV;
            volatile uint32 PMD6;
            volatile uint32 PMD6_CLR;
            volatile uint32 PMD6_SET;
            volatile uint32 PMD6_INV;
    };
    
    class ANVM_w{                                                               //  OK
        public:
            volatile uint32 NVMCON;
            volatile uint32 NVMCON_CLR;
            volatile uint32 NVMCON_SET;
            volatile uint32 NVMCON_INV;
            volatile uint32 NVMKEY;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 NVMADDR;
            volatile uint32 NVMADDR_CLR;
            volatile uint32 NVMADDR_SET;
            volatile uint32 NVMADDR_INV;
            volatile uint32 NVMDATA;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 NVMSRCADDR;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
    };
    
    class ARST_w{                                                               //  OK
        public:
            volatile uint32 RCON;
            volatile uint32 RCON_CLR;
            volatile uint32 RCON_SET;
            volatile uint32 RCON_INV;
            volatile uint32 RSWRST;
            volatile uint32 RSWRST_CLR;
            volatile uint32 RSWRST_SET;
            volatile uint32 RSWRST_INV;
    };
    
    class ARPI_w{                                                               
        public:
            volatile uint32 INT1R;
            volatile uint32 INT2R;
            volatile uint32 INT3R;
            volatile uint32 INT4R;
            volatile uint32 : 0x20;
            volatile uint32 T2CKR;
            volatile uint32 T3CKR;
            volatile uint32 T4CKR;
            volatile uint32 T5CKR;
            volatile uint32 IC1R;
            volatile uint32 IC2R;
            volatile uint32 IC3R;
            volatile uint32 IC4R;
            volatile uint32 IC5R;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 OCFAR;
            volatile uint32 OCFBR;
            volatile uint32 U1RXR;
            volatile uint32 U1CTSR;
            volatile uint32 U2RXR;
            volatile uint32 U2CTSR;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 SDI1R;
            volatile uint32 SS1R;
            volatile uint32 : 0x20;
            volatile uint32 SDI2R;
            volatile uint32 SS2R;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 REFCLKIR;
    };
    
    class ARPO_w{                                                               
        public:
            volatile uint32 RAP0R;
            volatile uint32 RPA1R;
            volatile uint32 RPA2R;
            volatile uint32 RPA3R;
            volatile uint32 RPA4R;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 RPA8R;
            volatile uint32 RPA9R;
            volatile uint32 : 0x20;
            volatile uint32 RPB0R;
            volatile uint32 RPB1R;
            volatile uint32 RPB2R;
            volatile uint32 RPB3R;
            volatile uint32 RPB4R;
            volatile uint32 RPB5R;
            volatile uint32 RPB6R;
            volatile uint32 RPB7R;
            volatile uint32 RPB8R;
            volatile uint32 RPB9R;
            volatile uint32 RPB10R;
            volatile uint32 RPB11R;
            volatile uint32 : 0x20;
            volatile uint32 RPB13R;
            volatile uint32 RPB14R;
            volatile uint32 RPB15R;
            volatile uint32 RPC0R;
            volatile uint32 RPC1R;
            volatile uint32 RPC2R;
            volatile uint32 RPC3R;
            volatile uint32 RPC4R;
            volatile uint32 RPC5R;
            volatile uint32 RPC6R;
            volatile uint32 RPC7R;
    };
    
    class AINT_w{
        public:
            volatile ACSIReg INTCON;
            volatile AxxxReg INTSTAT;
            volatile ACSIReg IPTMR;
            volatile ACSIReg IFS[0x03];
            volatile ACSIReg IEC[0x03];
            volatile ACSIReg IPC[0x0D];
    };
    
    class ABMX_w{                                                               //  OK
        volatile uint32 BMXCON;
        volatile uint32 BMXCON_CLR;
        volatile uint32 BMXCON_SET;
        volatile uint32 BMXCON_INV;
        volatile uint32 BMXDKPBA;
        volatile uint32 BMXDKPBA_CLR;
        volatile uint32 BMXDKPBA_SET;
        volatile uint32 BMXDKPBA_INV;
        volatile uint32 BMXDUDBA;
        volatile uint32 BMXDUDBA_CLR;
        volatile uint32 BMXDUDBA_SET;
        volatile uint32 BMXDUDBA_INV;
        volatile uint32 BMXDUPBA;
        volatile uint32 BMXDUPBA_CLR;
        volatile uint32 BMXDUPBA_SET;
        volatile uint32 BMXDUPBA_INV;
        volatile uint32 BMXDRMSZ;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
        volatile uint32 BMXPUPBA;
        volatile uint32 BMXPUPBA_CLR;
        volatile uint32 BMXPUPBA_SET;
        volatile uint32 BMXPUPBA_INV;
        volatile uint32 BMXPFMSZ;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
        volatile uint32 BMXBOOTSZ;
    };
    
    class ADMAGlob_w{
        public:
            volatile uint32 DMACON;
            volatile uint32 DMACON_CLR;
            volatile uint32 DMACON_SET;
            volatile uint32 DMACON_INV;
            volatile uint32 DMASTAT;
            volatile uint32 DMASTAT_CLR;
            volatile uint32 DMASTAT_SET;
            volatile uint32 DMASTAT_INV;
            volatile uint32 DMAADDR;
            volatile uint32 DMAADDR_CLR;
            volatile uint32 DMAADDR_SET;
            volatile uint32 DMAADDR_INV;
    };
    
    class ADMACrc_w{
        public:
            volatile uint32 DCRCCON;
            volatile uint32 DCRCCON_CLR;
            volatile uint32 DCRCCON_SET;
            volatile uint32 DCRCCON_INV;
            volatile uint32 DCRCDATA;
            volatile uint32 DCRCDATA_CLR;
            volatile uint32 DCRCDATA_SET;
            volatile uint32 DCRCDATA_INV;
            volatile uint32 DCRCXOR;
            volatile uint32 DCRCXOR_CLR;
            volatile uint32 DCRCXOR_SET;
            volatile uint32 DCRCXOR_INV;
    };
    
    class ADMACh_w{
        public:
            volatile uint32 DCHxCON;
            volatile uint32 DCHxCON_CLR;
            volatile uint32 DCHxCON_SET;
            volatile uint32 DCHxCON_INV;
            volatile uint32 DCHxECON;
            volatile uint32 DCHxECON_CLR;
            volatile uint32 DCHxECON_SET;
            volatile uint32 DCHxECON_INV;
            volatile uint32 DCHxINT;
            volatile uint32 DCHxINT_CLR;
            volatile uint32 DCHxINT_SET;
            volatile uint32 DCHxINT_INV;
            volatile uint32 DCHxSSA;
            volatile uint32 DCHxSSA_CLR;
            volatile uint32 DCHxSSA_SET;
            volatile uint32 DCHxSSA_INV;
            volatile uint32 DCHxDSA;
            volatile uint32 DCHxDSA_CLR;
            volatile uint32 DCHxDSA_SET;
            volatile uint32 DCHxDSA_INV;
            volatile uint32 DCHxSSIZ;
            volatile uint32 DCHxSSIZ_CLR;
            volatile uint32 DCHxSSIZ_SET;
            volatile uint32 DCHxSSIZ_INV;
            volatile uint32 DCHxDSIZ;
            volatile uint32 DCHxDSIZ_CLR;
            volatile uint32 DCHxDSIZ_SET;
            volatile uint32 DCHxDSIZ_INV;
            volatile uint32 DCHxSPTR;
            volatile uint32 DCHxSPTR_CLR;
            volatile uint32 DCHxSPTR_SET;
            volatile uint32 DCHxSPTR_INV;
            volatile uint32 DCHxDPTR;
            volatile uint32 DCHxDPTR_CLR;
            volatile uint32 DCHxDPTR_SET;
            volatile uint32 DCHxDPTR_INV;
            volatile uint32 DCHxCSIZ;
            volatile uint32 DCHxCSIZ_CLR;
            volatile uint32 DCHxCSIZ_SET;
            volatile uint32 DCHxCSIZ_INV;
            volatile uint32 DCHxCPTR;
            volatile uint32 DCHxCPTR_CLR;
            volatile uint32 DCHxCPTR_SET;
            volatile uint32 DCHxCPTR_INV;
            volatile uint32 DCHxDAT;
            volatile uint32 DCHxDAT_CLR;
            volatile uint32 DCHxDAT_SET;
            volatile uint32 DCHxDAT_INV;
    };
    
#   warning USB is currently unimplemented
    
//    class APORT_w{
//        public:
//            volatile uint32 ANSELx;
//            volatile uint32 ANSELx_CLR;
//            volatile uint32 ANSELx_SET;
//            volatile uint32 ANSELx_INV;
//            volatile uint32 TRISx;
//            volatile uint32 TRISx_CLR;
//            volatile uint32 TRISx_SET;
//            volatile uint32 TRISx_INV;
//            volatile uint32 PORTx;
//            volatile uint32 PORTx_CLR;
//            volatile uint32 PORTx_SET;
//            volatile uint32 PORTx_INV;
//            volatile uint32 LATx;
//            volatile uint32 LATx_CLR;
//            volatile uint32 LATx_SET;
//            volatile uint32 LATx_INV;
//            volatile uint32 ODCx;
//            volatile uint32 ODCx_CLR;
//            volatile uint32 ODCx_SET;
//            volatile uint32 ODCx_INV;
//            volatile uint32 CNPUx;
//            volatile uint32 CNPUx_CLR;
//            volatile uint32 CNPUx_SET;
//            volatile uint32 CNPUx_INV;
//            volatile uint32 CNPDx;
//            volatile uint32 CNPDx_CLR;
//            volatile uint32 CNPDx_SET;
//            volatile uint32 CNPDx_INV;
//            volatile uint32 CNENx_;
//            volatile uint32 CNENx_CLR;
//            volatile uint32 CNENx_SET;
//            volatile uint32 CNENx_INV;
//            volatile uint32 CNSTATx;
//            volatile uint32 CNSTATx_CLR;
//            volatile uint32 CNSTATx_SET;
//            volatile uint32 CNSTATx_INV;
//    };
    
    class ADEVGFG_w{
        volatile uint32 DEVCFG3;
        volatile uint32 DEVCFG2;
        volatile uint32 DEVCFG1;
        volatile uint32 DEVCFG0;
    };
    
}

#   define _WDTCON_ON_POSITION                      0x0000000F
#   define _WDTCON_ON_MASK                          0x00008000
#   define _WDTCON_ON_LENGTH                        0x00000001

#   define _WDTCON_SWDTPS_POSITION                  0x00000002
#   define _WDTCON_SWDTPS_MASK                      0x0000007C
#   define _WDTCON_SWDTPS_LENGTH                    0x00000005

#   define _WDTCON_SWDTPS0_POSITION                 0x00000002
#   define _WDTCON_SWDTPS0_MASK                     0x00000004
#   define _WDTCON_SWDTPS0_LENGTH                   0x00000001

#   define _WDTCON_SWDTPS1_POSITION                 0x00000003
#   define _WDTCON_SWDTPS1_MASK                     0x00000008
#   define _WDTCON_SWDTPS1_LENGTH                   0x00000001

#   define _WDTCON_SWDTPS2_POSITION                 0x00000004
#   define _WDTCON_SWDTPS2_MASK                     0x00000010
#   define _WDTCON_SWDTPS2_LENGTH                   0x00000001

#   define _WDTCON_SWDTPS3_POSITION                 0x00000005
#   define _WDTCON_SWDTPS3_MASK                     0x00000020
#   define _WDTCON_SWDTPS3_LENGTH                   0x00000001

#   define _WDTCON_SWDTPS4_POSITION                 0x00000006
#   define _WDTCON_SWDTPS4_MASK                     0x00000040
#   define _WDTCON_SWDTPS4_LENGTH                   0x00000001

#   if !defined (__DEVCLASS3__)
#       define _WDTCON_WDTWINEN_POSITION            0x00000001
#       define _WDTCON_WDTWINEN_MASK                0x00000002
#       define _WDTCON_WDTWINEN_LENGTH              0x00000001
#   endif

#   define _WDTCON_WDTCLR_POSITION                  0x00000000
#   define _WDTCON_WDTCLR_MASK                      0x00000001
#   define _WDTCON_WDTCLR_LENGTH                    0x00000001

#   define _RTCCON_CAL_POSITION                     0x00000010
#   define _RTCCON_CAL_MASK                         0x03FF0000
#   define _RTCCON_CAL_LENGTH                       0x0000000A



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