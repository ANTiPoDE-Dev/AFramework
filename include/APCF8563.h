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


#ifndef APCF8563_H
#define	APCF8563_H

#include "AI2CDriver.h"
#include "ADateTime.h"


namespace AFramework{

    class APCF8563{
        public:
            APCF8563(volatile AI2CDriver * driver);
            uint8 seconds() const;
            uint8 minutes() const;
            uint8 hours() const;
            uint8 days() const;
            uint8 weekday() const;
            uint8 month() const;
            uint8 years() const;
            bool setTime(ADateTime tm) const;
            ADateTime currentTime() const;
            
        private:
            uint8 bcddec(const uint8 val) const;
            uint8 decbcd(const uint8 val) const;
            uint8 readreg(const uint8 reg) const;
            void  writereg(const uint8 reg) const;
            volatile AI2CDriver * m_driver;
    };
}

#endif	/* APCF8563_H */

