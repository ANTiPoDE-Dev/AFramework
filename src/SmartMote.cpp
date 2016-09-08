#include "SmartMote.h"

#define _SSID_ADDRESS   0x0000
#define _KEY_ADDRESS    0x0100
#define _HOST_ADDRESS   0x0200

#define _PHP_CHUNK1 "POST /smartmote.php HTTP/1.0\r\nHost: "
/*  tra chunk1 e chunk2 inserire l'hostname                                     */
#define _PHP_CHUNK2 "\r\nAccept: */*\r\nContent-Length: "
/*  tra chunk2 e chunk3 inserire la lunghezza della stringa dati                */
#define _PHP_CHUNK3 "\r\nContent-Type: application/x-www-form-urlencoded\r\n\r\n"
/*  ed infine la stringa dati                                                   */

SmartMote::SmartMote(         AUARTDriver   *          uartDrv   , 
                     volatile AI2CDriver    *          i2cDrv    , 
                              AOneWire      *          ds18b20Drv,
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
                              const    uint32          buttonGpio) : m_ser(uartDrv),
                                                                     m_bus(i2cDrv),
                                                                     m_net(uartDrv),
                                                                     m_mem(i2cDrv),
                                                                     m_gTmp(ds18b20Drv),
                                                                     m_aT_H(dhtPort, dhtGpio),
                                                                     m_aLumChan(ldrCh),
                                                                     m_gHumChan(groundCh),
                                                                     m_vBatChan(vbatCh),
                                                                     m_redPort(ledRedPort),
                                                                     m_redGpio(ledRedGpio),
                                                                     m_grnPort(ledGrnPort),
                                                                     m_grnGpio(ledGrnGpio),
                                                                     m_btnPort(buttonPort),
                                                                     m_btnGpio(buttonGpio){
    /*  imposto le porte dei led come uscite                                    */
    m_redPort->setOutput(m_redGpio);
    m_grnPort->setOutput(m_grnGpio);
    /*  e li metto bassi                                                        */
    m_redPort->write(m_redGpio, Lo);
    m_grnPort->write(m_grnGpio, Lo);
    /*  imposto la porta del bottone come ingresso                              */
    m_btnPort->setInput(m_btnGpio);
    /*  accendo l'orologio                                                      */
    RTCC.open();
    /*  abilito l'interrupt dell'orologio                                       */
    RTCC.enableInterrupt(Ip2, Isp0);
}

void SmartMote::config(){
    AString conf;
    AStringList * param = NULL;
    bool flag;
    /*  se il bottone non è premuto                                             */
    if(!checkButton()){
        /*  ritorno                                                             */
        return;
    }
    /*  accendo l'uart                                                          */
    openUART();
    /*  inizializzo il modulo come AP                                           */
    if(!m_net.initialize(AESP07::APMode)){
        /*  se fallisce notifico l'errore                                       */
        error();
    }
    /*  setto il nome come SmartMote e password admin                           */
    if(!m_net.configureAP("SmartMote", "smartmote")){
        /*  se fallisce notifico l'errore                                       */
        error();        
    }
    /*  imposto l'ip a 192.168.1.1                                              */
    if(!m_net.setIp(AESP07::APMode, "192.168.1.1")){
        /*  se fallisce notifico l'errore                                       */
        error();        
    }
    /*  disabilito le connessioni multiple                                      */
    if(!m_net.setMultipleConnections(false)){
        /*  se fallisce notifico l'errore                                       */
        error();                
    }
    /*  apro il server sulla porta 8000                                         */
    if(!m_net.listen(8000)){
        /*  se fallisce notifico l'errore                                       */
        error();
    }
    /*  aspetto di ricevere la stringa                                          */
    while(conf.isEmpty()){
        
        m_net.waitForData(conf);
    }
    /*  prendo i parametri                                                      */
    param = conf.split(' ');
    /*  se la stringlist è allocata correttamente                               */
    if(param){
        saveSSID(param->at(0));
        saveKey(param->at(1));
        saveHost(param->at(2));
        RTCC.setHours(static_cast<uint32>(param->at(3).toInt32(flag)));
        RTCC.setMinutes(static_cast<uint32>(param->at(3).toInt32(flag)));
        RTCC.setSeconds(static_cast<uint32>(param->at(3).toInt32(flag)));
    }else{
        /*  altrimenti notifico l'errore                                        */
        error();
    }
    /*  spengo i led                                                            */
    turnOffRed();
    turnOffGreen();
}

void SmartMote::work(){
    while(1){
        /*  se l'ora corrente è di scansione                                    */
        if(!(RTCC.hours() % 6) && (RTCC.minutes() >= 0x00 && RTCC.minutes() <= 0x05)){
            AString data;
            AString message;
            AString answer;
            /*  abilito il core timer (la prima volta è già abilitato)          */
            System::wakeCoreTimer();
            /*  accendo il led verde                                            */
            turnOnGreen();
            /*  accendo la seriale                                              */
            openUART();
            /*  accendo l'i2c                                                   */
            openI2C();
            /*  prendo le misure                                                */
            data += mac();
            data += luminosity();
            data += ambientTempAndHum();
            data += groundTemp();
            data += groundHum();
            data += battey();
            /*  compongo la stringa                                             */
            message += _PHP_CHUNK1;
            /*  inserisco l'hostname                                            */
            message += getHost();
            /*  inserisco la seconda parte di richiesta http                    */
            message += _PHP_CHUNK2;
            /*  inserisco la lunghezza dei dati                                 */
            message += AString(static_cast<sint32>(data.size()));
            /*  inserisco la terza parte di richiesta http                      */
            message += _PHP_CHUNK3;
            /*  inserisco i dati                                                */
            message += data;

            /*  se fallisce l'inizializzazione dell'esp                         */
            if(!m_net.initialize()){
                /*  notifico l'errore                                           */
                error();
            }
            /*  se fallisce l'avvio del dhcp                                    */
            if(!m_net.setDhcp(true)){
                /*  notifico l'errore                                           */
                error();
            }
            /*  se fallisce la connessione alla rete                            */
            if(!m_net.joinAP(getSSID(), getKey())){
                /*  notifico l'errore                                           */
                error();
            }
            /*  se fallisce la connessione al server                            */
            if(!m_net.connectToHost(getHost(), 80)){
                /*  notifico l'errore                                           */
                error();
            }
            /*  invio i dati                                                    */
            m_net.send(message);
            /*  aspetto l'ok                                                    */
            m_net.waitForData(answer);
            /*  notifico l'ok o lerrore dell'invio                              */
            wasSuccess(answer);
            /*  lascio l'ap                                                     */
            m_net.leaveAP();
            /*  libero la memoria occupata dalle stringhe                       */
            message.clear();
            data.clear();
            answer.clear();
        }
        /*  calcolo del tempo di sleep per il wifi                              */
        m_net.sleep(getSleepTime());
        /*  punto la prossima sveglia                                           */
        setNextAlarm();
        /*  spengo il led verde                                                 */
        turnOffGreen();
        /*  spengo l'uart                                                       */
        closeUART();
        /*  chiudo l'i2c                                                        */
        closeI2C();
        /*  spengo il core timer                                                */
        System::stopCoreTimer();
        /*  vado a dormire                                                      */
        System::sleep();
            
    }
}

bool SmartMote::checkButton(){
    
    /*  controllo che il bottone sia premuto                                    */
    if(m_btnPort->read(m_btnGpio) == Lo){
        /*  aspetto 500 ms*/
        System::delay(250);
        /*  controllo che il bottone sia ancora premuto                         */
        if(m_btnPort->read(m_btnGpio) == Lo){
            /*  accendo i led per far capire all'utente che può lasciare        */
            turnOnRed();
            turnOnGreen();
            /*  aspetto che l'utente lo rilasci                                 */
            while(m_btnPort->read(m_btnGpio) == Lo);
            /*  ritorno true                                                    */
            return true;
        }
    }
    /*  altrimenti ritorno false                                                */
    return false;
}

void SmartMote::turnOnRed(){
    m_redPort->write(m_redGpio, Hi);
}

void SmartMote::turnOnGreen(){
    m_grnPort->write(m_grnGpio, Hi);
}

void SmartMote::turnOffRed(){
    m_redPort->write(m_redGpio, Lo);
}

void SmartMote::turnOffGreen(){
    m_grnPort->write(m_grnGpio, Lo);
}

void SmartMote::error(){
    /*  per tutta la vita                                                       */
    while(1){
        /*  accendo i led                                                       */
        turnOnRed();
        turnOnGreen();
        /*  aspetto 500 ms                                                      */
        System::delay(500);
        /*  spengo i led                                                        */
        turnOffRed();
        turnOffGreen();
        /*  aspetto 500 ms                                                      */
        System::delay(500);
    }
}

void SmartMote::openUART(){
    /*  aabilito l'interrupt                                                    */
    m_ser->getReceiverEventController()->enableInterrupt(Ip1, Isp0);
    /*  se l'uart è spenta                                                      */
    if(!m_ser->isOpen()){
        m_ser->open(AUARTDriver::Baud115200, AUARTDriver::Data8bitNoParity, AUARTDriver::Stop1bit);
    }
}

void SmartMote::closeUART(){
    /*  chiudo l'uart                                                           */
    m_ser->close();
    /*  disabilito gli interrupt                                                */
    m_ser->getReceiverEventController()->disableInterrupt();
}

void SmartMote::openI2C(){
    /*  se l'i2c è spento                                                       */
    if(!m_bus->isOpen()){
        /*  provo ad aprirlo a frequenza 100KHz                                 */
        if(!m_bus->open(AI2CDriver::Freq100KHz)){
            /*  se fallisce errore                                              */
            error();
        }
    }
}

void SmartMote::closeI2C(){
    /*  chiudo il bus                                                           */
    m_bus->close();
}

AFramework::AString SmartMote::mac(){
    AString str("mAdd=");
    /*  se l'esp è morto                                                        */
    if(!m_net.isOk()){
        /*  notifico l'errore                                                   */
        error();
    }
    str += m_net.MAC();
    str += "&";
    return str;
}

AFramework::AString SmartMote::luminosity(){
    uint32  lum = ADC.read(m_aLumChan);
    double  num = (static_cast<double>(lum) / 1023.0) * 100;
    AString str(num, 2);
    str.prepend("aLum=");
    str += "&";
    return str;
}

AFramework::AString SmartMote::ambientTempAndHum(){
    /*  se il dht22 è morto                                                     */
    if(!m_aT_H.read()){
        /*  notifico l'errore                                                   */
        error();
    }
    /*  prendo la temperatura                                                   */
    AString tmp(m_aT_H.temperature(), 2);
    /*  prendo l'umidità                                                        */
    AString hum(m_aT_H.humidity(), 2);
    /*  compongo la stringa                                                     */
    AString str("aTmp=");
    str += tmp;
    str += "&aHum=";
    str += hum;
    str += "&";
    return str;
}

AFramework::AString SmartMote::groundTemp(){
    /*  se il ds18 è morto                                                      */
    if(!m_gTmp.read()){
        /*  notifico l'errore                                                   */
        error();
    }
    /*  prendo la temperatura                                                   */
    AString tmp(m_gTmp.temperature(), 2);
    /*  inserisco gTmp                                                          */
    tmp.prepend("gTmp=");
    tmp += "&";
    return tmp;
    
}

AFramework::AString SmartMote::groundHum(){
    uint32 hum = ADC.read(m_gHumChan);
    double num = ((1023.0 - static_cast<double>(hum)) / 1023.0) * 100;
    AString str(num, 2);
    str.prepend("gHum=");
    str += "&";
    return str;
}

AFramework::AString SmartMote::battey(){
    uint32  bat = ADC.read(m_vBatChan);
    double  num = (((((static_cast<double>(bat) * 3.3) / 1023) * 2) / 4.7) * 100);
    AString str(num, 2);
    str.prepend("vBat=");
    return str; 
}

void SmartMote::saveSSID(const AString & str){
    
    m_mem.write(_SSID_ADDRESS, str);
}

void SmartMote::saveKey(const AString & str){
    m_mem.write(_KEY_ADDRESS, str);
}

void SmartMote::saveHost(const AString & str){
    m_mem.write(_HOST_ADDRESS, str);
}

AString SmartMote::getSSID(){
    AString str;
    m_mem.read(_SSID_ADDRESS, str);
    return str;
}

AString SmartMote::getKey(){
    AString str;
    m_mem.read(_KEY_ADDRESS, str);
    return str;
}

AString SmartMote::getHost(){
    AString str;
    m_mem.read(_HOST_ADDRESS, str);
    return str;
}

void SmartMote::wasSuccess(const AString & str){
    if(str.contains("OK")){
        for(uint8 i = 0; i < 4; i++){
            turnOffGreen();
            System::delay(125);
            turnOnGreen();
            System::delay(125);
        }
    }else{
        for(uint8 i = 0; i < 4; i++){
            turnOnRed();
            System::delay(125);
            turnOffRed();
            System::delay(125);
        }
    }
}

uint32 SmartMote::getSleepTime(){
    
    uint32 raw = 0;
    uint32 slp = 0;
    /*  converto tutto il tempo in millisecondi                                 */
    raw += (RTCC.hours()   * 0x0036EE80);
    raw += (RTCC.minutes() * 0x0000EA60);
    raw += (RTCC.seconds() * 0x000003E8);
  
    /*  se l'orario è minore delle 6                                            */
    if(raw < 0x01499700){
        slp = 0x01499700;
    /*  se l'orario è minore delle 12                                           */
    }else if(raw < 0x02932E00){
        slp = 0x02932E00;
    /*  se l'orario è minore delle 18                                           */
    }else if(raw < 0x03DCC500){
        slp = 0x02932E00;
    /*  altirmenti siamo dopo le 18 per cui sveglia a mezzanotte                */
    }else{
        slp = 0x05265C00;
    }
    /*  calcolo la differenza                                                   */
    slp -= raw;
    /*  tolgo altri 500 ms                                                      */
    slp -= 500;
    
    return slp;
}

void SmartMote::setNextAlarm(){
    
    uint8 hh = RTCC.hours();
    if(hh < 6){
        RTCC.setAlarm(6,  0);
    }else if(hh < 12){
        RTCC.setAlarm(12, 0);
    }else if(hh < 18){
        RTCC.setAlarm(18, 0);
    }else{
        RTCC.setAlarm(0,  0);
    }
}
        