/*******************************************************************************
*   @author:    Milazzo Giuseppe
*               UniversitÓ KORE Enna
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
    
    class AstdReg{
        public:
            volatile uint32 REG;
    };
    
    class AWDT_w{
        public:
            volatile uint32 WDTCON;
            volatile uint32 WDTCON_CLR;
            volatile uint32 WDTCON_SET;
            volatile uint32 WDTCON_INV;
    };
    
    class ARTCC_w{
        public:
            volatile uint32 RTCCON;
            volatile uint32 RTCCON_CLR;
            volatile uint32 RTCCON_SET;
            volatile uint32 RTCCON_INV;
            volatile uint32 RTCALRM;
            volatile uint32 RTCALRM_CLR;
            volatile uint32 RTCALRM_SET;
            volatile uint32 RTCALRM_INV;
            volatile uint32 RTCTIME;
            volatile uint32 RTCTIME_CLR;
            volatile uint32 RTCTIME_SET;
            volatile uint32 RTCTIME_INV;
            volatile uint32 RTCDATE;
            volatile uint32 RTCDATE_CLR;
            volatile uint32 RTCDATE_SET;
            volatile uint32 RTCDATE_INV;
            volatile uint32 ALRMTIME;
            volatile uint32 ALRMTIME_CLR;
            volatile uint32 ALRMTIME_SET;
            volatile uint32 ALRMTIME_INV;
            volatile uint32 ALRMDATE;
            volatile uint32 ALRMDATE_CLR;
            volatile uint32 ALRMDATE_SET;
            volatile uint32 ALRMDATE_INV;
    };
    
    class ATMR_w{
        public:
            volatile uint32 TxCON;
            volatile uint32 TxCON_CLR;
            volatile uint32 TxCON_SET;
            volatile uint32 TxCON_INV;
            volatile uint32 TMRx;
            volatile uint32 TMRx_CLR;
            volatile uint32 TMRx_SET;
            volatile uint32 TMRx_INV;
            volatile uint32 PRx;
            volatile uint32 PRx_CLR;
            volatile uint32 PRx_SET;
            volatile uint32 PRx_INV;
    };
    
    class AIC_w{
        public:
            volatile uint32 ICxCON;
            volatile uint32 ICxCON_CLR;
            volatile uint32 ICxCON_SET;
            volatile uint32 ICxCON_INV;
            volatile uint32 ICxBUF;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
    };
    
    class AOC_w{
        public:
            volatile uint32 OCxCON;
            volatile uint32 OCxCON_CLR;
            volatile uint32 OCxCON_SET;
            volatile uint32 OCxCON_INV;
            volatile uint32 OCxR;
            volatile uint32 OCxR_CLR;
            volatile uint32 OCxR_SET;
            volatile uint32 OCxR_INV;
            volatile uint32 OCxRS;
            volatile uint32 OCxRS_CLR;
            volatile uint32 OCxRS_SET;
            volatile uint32 OCxRS_INV;
    };
    
    class AI2C_w{
        public:
            volatile uint32 I2CxCON;
            volatile uint32 I2CxCON_CLR;
            volatile uint32 I2CxCON_SET;
            volatile uint32 I2CxCON_INV;
            volatile uint32 I2CxSTAT;
            volatile uint32 I2CxSTAT_CLR;
            volatile uint32 I2CxSTAT_SET;
            volatile uint32 I2CxSTAT_INV;
            volatile uint32 I2CxADD;
            volatile uint32 I2CxADD_CLR;
            volatile uint32 I2CxADD_SET;
            volatile uint32 I2CxADD_INV;
            volatile uint32 I2CxMSK;
            volatile uint32 I2CxMSK_CLR;
            volatile uint32 I2CxMSK_SET;
            volatile uint32 I2CxMSK_INV;
            volatile uint32 I2CxBRG;
            volatile uint32 I2CxBRG_CLR;
            volatile uint32 I2CxBRG_SET;
            volatile uint32 I2CxBRG_INV;
            volatile uint32 I2CxTRN;
            volatile uint32 I2CxTRN_CLR;
            volatile uint32 I2CxTRN_SET;
            volatile uint32 I2CxTRN_INV;
            volatile uint32 I2CxRCV;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
    };
    
    class ASPI_w{
        public:
            volatile uint32 SPIxCON;
            volatile uint32 SPIxCON_CLR;
            volatile uint32 SPIxCON_SET;
            volatile uint32 SPIxCON_INV;
            volatile uint32 SPIxSTAT;
            volatile uint32 SPIxSTAT_CLR;
            volatile uint32 SPIxSTAT_SET;
            volatile uint32 SPIxSTAT_INV;
            volatile uint32 SPIxBUF;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 SPIxBRG;
            volatile uint32 SPIxBRG_CLR;
            volatile uint32 SPIxBRG_SET;
            volatile uint32 SPIxBRG_INV;
            volatile uint32 SPIxCON2;
            volatile uint32 SPIxCON2_CLR;
            volatile uint32 SPIxCON2_SET;
            volatile uint32 SPIxCON2_INV;
    };
    
    class AUART_w{
        public:
            volatile uint32 UxMODE;
            volatile uint32 UxMODE_CLR;
            volatile uint32 UxMODE_SET;
            volatile uint32 UxMODE_INV;
            volatile uint32 UxSTA;
            volatile uint32 UxSTA_CLR;
            volatile uint32 UxSTA_SET;
            volatile uint32 UxSTA_INV;
            volatile uint32 UxTXREG;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 UxRXREG;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 : 0x20;
            volatile uint32 UxBRG;
            volatile uint32 UxBRG_CLR;
            volatile uint32 UxBRG_SET;
            volatile uint32 UxBRG_INV;
    };
    
    class APMP_w{
        public:
            volatile uint32 PMCON;
            volatile uint32 PMCON_CLR;
            volatile uint32 PMCON_SET;
            volatile uint32 PMCON_INV;
            volatile uint32 PMMODE;
            volatile uint32 PMMODE_CLR;
            volatile uint32 PMMODE_SET;
            volatile uint32 PMMODE_INV;
            volatile uint32 PMADDR;
            volatile uint32 PMADDR_CLR;
            volatile uint32 PMADDR_SET;
            volatile uint32 PMADDR_INV;
            volatile uint32 PMDOUT;
            volatile uint32 PMDOUT_CLR;
            volatile uint32 PMDOUT_SET;
            volatile uint32 PMDOUT_INV;
            volatile uint32 PMDIN;
            volatile uint32 PMDIN_CLR;
            volatile uint32 PMDIN_SET;
            volatile uint32 PMDIN_INV;
            volatile uint32 PMAEN;
            volatile uint32 PMAEN_CLR;
            volatile uint32 PMAEN_SET;
            volatile uint32 PMAEN_INV;
            volatile uint32 PMSTAT;
            volatile uint32 PMSTAT_CLR;
            volatile uint32 PMSTAT_SET;
            volatile uint32 PMSTAT_INV;
    };
    
    class AADC_w{
        public:
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
#elif defined (__32MZ__)
#   error   Unknown register types for MZ family.
#else
#   error   Unknown architecture.
#endif


#endif // AREGISTERDEFS_H
