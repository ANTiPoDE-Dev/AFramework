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

#ifndef ARTCC_H
#define	ARTCC_H

#include "ARegisterDefs.h"
#include "ADateTime.h"
#include "AInterruptSource.h"

namespace AFramework{
    
    class ARTCC : public AInterruptSource{
        
        public:
            
            ARTCC(volatile ARTCC_w * reg);
            
            void open();
            void close();
            
            uint8 seconds() const;
            uint8 minutes() const;
            uint8 hours() const;
            uint8 days() const;
            ADateTime::Weekdays weekday() const;
            ADateTime::Months month() const;
            uint8 years() const;
            bool setDateTime(ADateTime tm);
            bool setHours(const uint8 hh);
            bool setMinutes(const uint8 mm);
            bool setSeconds(const uint8 ss);
            ATime currentTime() const;
            bool setAlarm(const uint8 hours, const uint8 minutes);
            bool stopAlarm();

        private:
            uint8 bcddec(const uint8 val) const;
            uint8 decbcd(const uint8 val) const;
            void unlock();
            void lock();
            volatile ARTCC_w * m_reg;
            
    };
    
    extern ARTCC RTCC;
}

#endif	/* ARTCC_H */

