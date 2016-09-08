#ifndef ADHT22_H
#define	ADHT22_H

#include "ACore.h"

namespace AFramework{

    class ADht22{
        public:
            
            ADht22(volatile AHardwarePort *port, const uint32 gpio);
            double temperature();
            double humidity();
            bool read();
            
        private:
            
            void startSignal();
            bool checkResponse();
            uint8 readByte();
            
            
            volatile AHardwarePort * m_port;
            uint32          m_gpio;
            uint32          m_temp;
            uint32          m_hum;
            bool            m_flag;
    };  
}
#endif	