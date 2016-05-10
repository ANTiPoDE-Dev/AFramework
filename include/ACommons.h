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

#define A_COHERENT        volatile
#define A_CONST_COHERENT  volatile const

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
        Hi
    };
    
    enum Priority{
        Ip1 = 1,
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
        Isp3
    };
    
//    enum UserPort{
//        A0  = 0x10001U,
//        A1  = 0x10002U,
//        A4  = 0x10010U,
//        A7  = 0x10080U,
//        A8  = 0x10100U,
//        A9  = 0x10200U,
//        A10 = 0x10400U,
//        B0  = 0x20001U,
//        B1  = 0x20002U,
//        B2  = 0x20004U,
//        B3  = 0x20008U,
//        B4  = 0x20010U,
//        B5  = 0x20020U,
//        B7  = 0x20080U,
//        B8  = 0x20100U,
//        B9  = 0x20200U,
//        B10 = 0x20400U,
//        B11 = 0x20800U,
//        B13 = 0x22000U,
//        B14 = 0x24000U,
//        B15 = 0x28000U,
//        C0  = 0x40001U,
//        C1  = 0x40002U,
//        C2  = 0x40004U,
//        C3  = 0x40008U,
//        C4  = 0x40010U,
//        C5  = 0x40020U,
//        C6  = 0x40040U,
//        C7  = 0x40080U,
//        C8  = 0x40100U,
//        C9  = 0x40200U
//    };
    
    enum PortCPins{
        C0  = 0x40001U,
        C1  = 0x40002U,
        C2  = 0x40004U,
        C3  = 0x40008U,
        C4  = 0x40010U,
        C5  = 0x40020U,
        C6  = 0x40040U,
        C7  = 0x40080U,
        C8  = 0x40100U,
        C9  = 0x40200U,
    };

    class AErrorNotifier{
        public:
            enum AErrors{   
                            NoError,
                            NoMemory,
                            OutOfRange
                        };
            virtual bool good() const volatile = 0;
            virtual AErrors lastError() const volatile = 0;
        protected:
            virtual void errset(const AErrors &err = NoError) const volatile = 0;
    };
    
    class AError : public AErrorNotifier{
        public:
            AError(){
                m_err = NoError;
            }
            AErrors lastError() const volatile{
                return m_err;
            }
            bool good() const volatile{
                return m_err == NoError;
            }
        protected:
            mutable volatile AErrors m_err;
            void errset(const AErrors &err = NoError) const volatile{
                m_err = err;
            }
    };
}
#endif // ACOMMONS_H
