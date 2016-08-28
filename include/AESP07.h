#ifndef AESP07_H
#define	AESP07_H

#include "AUARTDriver.h"

namespace AFramework{

    class AESP07{
        public:
            enum ESPMode{
                NoMode,
                StationMode,
                APMode,
                BothMode
            };
            enum ESPSleep{
                Disable,
                Light,
                Deep
            };
            enum ESPEncryption{
                Open,
                WPA_PSK,
                WPA2_PSK,
                WPA_WPA2_PSK
            };
            enum Protocol{
                TCP,
                UDP
            };
            AESP07(AUARTDriver * driver, const AUARTDriver::Baud baud = AUARTDriver::Baud115200);
            
            bool initialize(const ESPMode mode = StationMode) const;
            
            bool isOk(const uint32 ms = 1000) const;
            bool reset(const uint32 ms = 2500) const;
            bool sleep(const uint32 sleepTime, const uint32 ms = 1000) const;
            bool setEcho(const bool echo, const uint32 ms = 1000) const;
            bool factoryReset(const uint32 ms = 2500) const;
            bool setSleepMode(const ESPSleep mode, const uint32 ms = 1000) const;   //da sistemare
            bool setRFPower(const uint8 pwr, const uint32 ms = 1000) const;
            bool setMode(const ESPMode mode = StationMode, const bool rst = false, const bool def = false, const uint32 ms = 2500) const;
            bool joinAP(const AString & ssid, const AString & pwd, const bool def = false, const uint32 ms = 20000) const;
            bool leaveAP(const uint32 ms = 2000) const;            
            bool configureAP(const AString & ssid, const AString & pwd, const ESPEncryption enc = WPA_PSK, const uint8 channel = 7, const bool def = false, const uint32 ms = 2500) const;
            bool setDhcp(const bool en, const bool def = false, const uint32 ms = 1000) const;
            bool setAutoConnect(const bool en = false, const uint32 ms = 1000) const;
            
            AString MAC(ESPMode mode = StationMode, const uint32 ms = 1000);
            
            bool setIp(const ESPMode mode, const AString &addr, const AString &gateway = AString(), const AString &netmask = AString(), const bool def = false, const uint32 ms = 1000) const;
            bool prepareForReceive() const;
            
            bool connectToHost(const AString &addr, const uint16 port, const uint32 ms = 30000) const;
            bool disconnectFromHost(const uint32 ms = 2000) const;
            
            bool waitForData(AString &str, const uint32 ms = 1000) const;
            bool send(const AString &str) const;
            
            ESPMode mode(const bool def = false, const uint32 ms = 500) const;
            
        private:
            bool wdttmr(const char * str, const uint32 ms) const;
            AUARTDriver * m_driver;
            bool          m_flg;
    };
}


#endif	/* AESP07_H */

