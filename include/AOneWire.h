/* 
 * File:   AOneWire.h
 * Author: Giuseppe Milazzo
 *
 * Created on 4 settembre 2016, 17.23
 */

#ifndef AONEWIRE_H
#define	AONEWIRE_H

#include "ACore.h"

namespace AFramework{
    
    class AOneWire{
        
        public:
            AOneWire(volatile AHardwarePort * port, const uint32 gpio);
            
            bool  reset();
            
            uint8 readByte();
            bool  writeByte(const uint8 data);
            
            bool waitLow(const uint32 preDelay_us);
            bool waitHigh(const uint32 preDelay_us);
            
        private:
            bool writeBit(const uint8 data);
            bool readBit();
            
            volatile AHardwarePort * m_port;
            uint32 m_gpio;
            bool   m_flag;
            
    };
}

#endif	/* AONEWIRE_H */

