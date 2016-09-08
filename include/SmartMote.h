/* 
 * File:   SmartMote.h
 * Author: Giuseppe Milazzo
 *
 * Created on 4 settembre 2016, 22.00
 */

#ifndef SMARTMOTE_H
#define	SMARTMOTE_H

#include "ACore.h"
#include "AADC.h"
#include "AString.h"
#include "AESP07.h"
#include "ARTCC.h"
#include "A24LC512.h"
#include "ADht22.h"
#include "ADS18B20.h"

using namespace AFramework;

class SmartMote{
    
    public:
        SmartMote(         AUARTDriver   * uartDrv   , 
                  volatile AI2CDriver    * i2cDrv    , 
                           AOneWire      * ds18b20Drv,
                  volatile AHardwarePort * dhtPort   , 
                  const    uint32          dhtGpio   ,
                  const    AADC::Channel   ldrCh     ,
                  const    AADC::Channel   groundCh  ,
                  const    AADC::Channel   vbatCh    ,
                  volatile AHardwarePort * ledRedPort,
                  const    uint32          ledRedGpio,
                  volatile AHardwarePort * ledGrnPort,
                  const    uint32          ledGrnGpio,
                  volatile AHardwarePort * buttonPort,
                  const    uint32          buttonGpio);
        
        void config();
        void work();
        
    private:
        bool checkButton();
        void turnOnRed();
        void turnOnGreen();
        void turnOffRed();
        void turnOffGreen();
        void error();
        void openUART();
        void closeUART();
        void openI2C();
        void closeI2C();
        
        AString mac();
        AString luminosity();
        AString ambientTempAndHum();
        AString groundTemp();
        AString groundHum();
        AString battey();
        
        void saveSSID(const AString & str);
        void saveKey(const AString & str);
        void saveHost(const AString & str);
        
        AString getSSID();
        AString getKey();
        AString getHost();
        
        void wasSuccess(const AString & str);
        
        uint32 getSleepTime();
        void setNextAlarm();
        
                 AUARTDriver   * m_ser;
        volatile AI2CDriver    * m_bus;
                 AESP07          m_net;
                 A24LC512        m_mem;
                 ADS18B20        m_gTmp;
                 ADht22          m_aT_H;
                 AADC::Channel   m_aLumChan;
                 AADC::Channel   m_gHumChan;
                 AADC::Channel   m_vBatChan;
        volatile AHardwarePort * m_redPort;
                 uint32          m_redGpio;
        volatile AHardwarePort * m_grnPort;
                 uint32          m_grnGpio;
        volatile AHardwarePort * m_btnPort;
                 uint32          m_btnGpio;
        
        
        
};

#endif	/* SMARTMOTE_H */

