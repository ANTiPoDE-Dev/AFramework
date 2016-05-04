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

#define _vol volatile

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

    class AError{

        public:

            enum AErrors{   NoError,
                            NoMemory,
                            OutOfRange  };

            AError(){

                m_err = NoError;
            }

            AErrors lastError() const{

                return m_err;
            }

            bool good() const{

                return m_err == NoError;
            }

        protected:

            mutable AErrors m_err;

            void errset(const AErrors &err = NoError) const{

                m_err = err;
            }
    };

}
#endif // ACOMMONS_H
