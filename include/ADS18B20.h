/* 
 * File:   ADS18B20.h
 * Author: Giuseppe Milazzo
 *
 * Created on 4 settembre 2016, 16.48
 */

#ifndef ADS18B20_H
#define	ADS18B20_H

#include "AOneWire.h"

namespace AFramework{
    
    class ADS18B20{
        
        public:
            ADS18B20(AOneWire * driver);
            double temperature();
            bool read();
            
        private:
            AOneWire * m_drv;
            bool       m_flag;
            uint32     m_temp;
    };
}

#endif	/* ADS18B20_H */
