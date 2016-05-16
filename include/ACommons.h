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
#ifndef ACOMMONS_H
#define ACOMMONS_H

#include "ASystemConfig.h"

namespace AFramework{

    typedef unsigned char       uchar;
    typedef signed char         schar;
    typedef unsigned char       uint8;
    typedef signed char         sint8;
    typedef unsigned short int  uint16;
    typedef signed short int    sint16;
    typedef unsigned int        uint32;
    typedef signed int          sint32;
    typedef unsigned long long  uint64;
    typedef signed long long    sint64;
    
    typedef volatile unsigned char       vuchar;
    typedef volatile char                vschar;
    typedef volatile unsigned char       vuint8;
    typedef volatile signed char         vsint8;
    typedef volatile unsigned short int  vuint16;
    typedef volatile signed short int    vsint16;
    typedef volatile unsigned int        vuint32;
    typedef volatile signed int          vsint32;
    typedef volatile unsigned long long  vuint64;
    typedef volatile signed long long    vsint64;
    typedef volatile double              vdouble;
    typedef volatile float               vfloat;
    typedef volatile bool                vbool;
    
    namespace Quick{
        const volatile uint32 All   = 0xFFFFFFFFU;
        const volatile uint32 NoOne = 0x00000000U;
    }
    
    enum LogicLevel{
        Lo,
        Hi,
        Unknown
    };
    
    enum Priority{
        Ip1,
        Ip2,
        Ip3,
        Ip4,
        Ip5,
        Ip6,
        Ip7
    };
    
    enum SubPriority{
        Isp0,
        Isp1,
        Isp2,
        Isp3,
    };
    
    #if defined(ANTIPODE32MR)
    
        enum RPGroup1{
            RPA0  = 0x0000U,
            RPB3  = 0x0001U,
            RPB15 = 0x0003U,
            RPB7  = 0x0004U,
            RPC7  = 0x0005U,
            RPC0  = 0x0006U,
            RPC5  = 0x0007U
        };
    
        enum RPGroup2{
            RPB5  = 0x0001U,
            RPB1  = 0x0002U,
            RPB11 = 0x0003U,
            RPB8  = 0x0004U,
            RPA8  = 0x0005U,
            RPC8  = 0x0006U,
            RPA9  = 0x0007U
        };
    
        enum RPGroup3{
            RPB6  = 0x0001U,
            RP4A  = 0x0002U,
            RPB13 = 0x0003U,
            RPB2  = 0x0004U,
            RPC6  = 0x0005U,
            RPC1  = 0x0006U,
            RPC3  = 0x0007U
        };
    
        enum RPGroup4{
            RPB14 = 0x0001U,
            RPB0  = 0x0002U,
            RPB10 = 0x0003U,
            RPB9  = 0x0004U,
            RPC9  = 0x0005U,
            RPC2  = 0x0006U,
            RPC4  = 0x0007U        
        };
    
    #elif defined(__32MX270F256B__)
    
        enum RPGroup1{
            RPA0,
            RPB3,
            RPB4,
            RPB15,
            RPB7
        };
    
        enum RPGroup2{
            RPA1,
            RPB5,
            RPB1,
            RPB11,
            RPB8
        };
    
        enum RPGroup3{
            RPA2,
            RPB6,
            RP4A,
            RPB13,
            RPB2
        };
    
        enum RPGroup4{
            RPA3,
            RPB14,
            RPB0,
            RPB10,
            RPB9
        };
    
    #elif defined(__32MX270F256D__)
    
        enum RPGroup1{
            RPA0,
            RPB3,
            RPB4,
            RPB15,
            RPB7,
            RPC7,
            RPC0,
            RPC5
        };
    
        enum RPGroup2{
            RPA1,
            RPB5,
            RPB1,
            RPB11,
            RPB8,
            RPA8,
            RPC8,
            RPA9
        };
    
        enum RPGroup3{
            RPA2,
            RPB6,
            RP4A,
            RPB13,
            RPB2,
            RPC6,
            RPC1,
            RPC3
        };
    
        enum RPGroup4{
            RPA3,
            RPB14,
            RPB0,
            RPB10,
            RPB9,
            RPC9,
            RPC2,
            RPC4
        };
    
    #else

    #error UNDEFINED BOARD OR PROCESSOR

    #endif
}
#endif // ACOMMONS_H
