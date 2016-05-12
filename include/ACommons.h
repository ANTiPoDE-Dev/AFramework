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

#include <cstdlib>

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
    
    enum LogicLevel{
        Lo,
        Hi,
        Unknown
    };
    
    enum Priority{
        IntOff,
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
}
#endif // ACOMMONS_H
