#include "AESP07.h"

#define __ESP_AT_TEST       "AT"
#define __ESP_AT_RST        "AT+RST"
#define __ESP_AT_DEEPSLEEP  "AT+GSLP="
#define __ESP_AT_ECHO       "ATE"
#define __ESP_AT_RESTORE    "AT+RESTORE"
#define __ESP_AT_SLEEP      "AT+SLEEP"
#define __ESP_AT_RADIO_PWR  "AT+RFPOWER="
#define __ESP_AT_WIFIMODE   "AT+CWMODE_"
#define __ESP_AT_JOINAP     "AT+CWJAP_"
#define __ESP_AT_LEAVEAP    "AT+CWQAP"
#define __ESP_AT_APCONF     "AT+CWSAP_"
#define __ESP_AT_DHCPCONF   "AT+CWDHCP_"
#define __ESP_AT_AUTOCONN   "AT+CWAUTOCONN="
#define __ESP_AT_STATIONMAC "AT+CIPSTAMAC_CUR?"
#define __ESP_AT_APMAC      "AT+CIPAPMAC_CUR?"
#define __ESP_AT_IPCONF     "AT+CIPSTA_"
#define __ESP_AT_TCP_CONN   "AT+CIPSTART=\"TCP\","
#define __ESP_AT_UDP_CONN   "AT+CIPSTART=\"UDP\","
#define __ESP_AT_CLOSE_CONN "AT+CIPCLOSE"
#define __ESP_AT_SEND       "AT+CIPSEND="
#define __ESP_AT_DATA       "+IPD,"
#define __ESP_AT_MUX        "AT+CIPMUX="
#define __ESP_AT_SERVER     "AT+CIPSERVER="
#define __ESP_AT_TIMEOUT    "AT+CIPSTO="

#define __ESP_AT_STATION_IP "AT+CIPSTA_"
#define __ESP_AT_AP_IP      "AT+CIPAP_"

#define __ESP_AT_CUR        "CUR"
#define __ESP_AT_DEF        "DEF"
#define __ESP_AT_QUOTE      "\""
#define __ESP_AT_TERM       "\r\n"

#define __ESP_AT_OK         "OK"
#define __ESP_AT_READY      "ready"
#define __ESP_AT_ERROR      "ERROR"
#define __ESP_AT_FAIL       "FAIL"
#define __ESP_AT_DISCONNECT "DISCONNECT"

#define __ESP_AT_Q_MODE_CUR "+CWMODE_CUR:"
#define __ESP_AT_Q_MODE_DEF "+CWMODE_DEF:"
#define __ESP_AT_Q_STAT_MAC "+CIPSTAMAC_CUR:\""
#define __ESP_AT_Q_AP_MAC   "+CIPAPMAC_CUR:\""



AFramework::AESP07::AESP07(AUARTDriver * driver, const AUARTDriver::Baud baud) : m_driver(NULL), m_flg(false){
    /*  se il puntatore al driver è valido                                      */
    if(driver){
        /*  assegno il puntatore                                                */
        m_driver = driver;
        /*  se la seriale è chiusa                                              */
        if(!m_driver->isOpen()){
            /*  la apro ed assegno il risulato della open al flag               */
            m_flg = m_driver->open(baud, AUARTDriver::Data8bitNoParity, AUARTDriver::Stop1bit);
        }else{
            /*  se invece è aperta salvo sul flag il risultato del confronto    */
            /*  tra il baud passato e quello corrente                           */
            m_flg = (m_driver->baud() == baud);
        }
    }
}

bool AFramework::AESP07::initialize(const ESPMode mode) const{
    
    if(!isOk()){
        return false;
    }
    if(!factoryReset()){
        return false;
    }
    if(!setEcho(false)){
        return false;
    }
    if(!setMode(mode)){
        return false;   
    }
    return true;
}

bool AFramework::AESP07::isOk(const uint32 ms) const{
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_TEST);
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::reset(const uint32 ms) const{
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_RST);
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_READY, ms);
}

bool AFramework::AESP07::sleep(const uint32 sleepTime, const uint32 ms) const{
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
    }
    /*  diversamente pulisco il buffer di ricezione                             */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_DEEPSLEEP);
    m_driver->write(sleepTime);
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::setEcho(const bool echo, const uint32 ms) const{
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
    }
    /*  diversamente pulisco il buffer di ricezione                             */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_ECHO);
    m_driver->write(echo ? 1 : 0);
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::factoryReset(const uint32 ms) const{
    bool res = false;
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_RESTORE);
    m_driver->write(__ESP_AT_TERM);
    /*  salvo il risultato del WDT, dal momento che nel restore vengono mandati */
    /*  caratteri strani è possibile che succeda qualcosa di strano durante la  */
    /*  ricezione                                                               */
    res = wdttmr(__ESP_AT_OK, ms);
    /*  se non ho ricevuto l'ok                                                 */
    if(!res){
        /*  ritorno false                                                       */
        return false;
    }
    /*  altrimenti aspetto 500 ms e ritorno true                                */
    System::delay(500);
    return true;
}

bool AFramework::AESP07::setSleepMode(const ESPSleep mode, const uint32 ms) const{
    AString str(__ESP_AT_SLEEP);
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_SLEEP);
    m_driver->write("=");
    m_driver->write(static_cast<uint32>(mode));
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::setRFPower(const uint8 pwr, const uint32 ms) const{
    /*  se la seriale non e' ok o il valore passato supera il limite            */
    if(!m_flg || pwr > 0x52){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_RADIO_PWR);
    m_driver->write(static_cast<uint32>(pwr));
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::setMode(const ESPMode mode, const bool rst, const bool def, const uint32 ms) const{
    bool    res = false;
    /*  se la seriale non e' ok o la modalità è NoMode                          */
    if(!m_flg || mode == NoMode){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo il comando sulla seriale                                         */
    m_driver->write(__ESP_AT_WIFIMODE);
    /*  se l'utente vuole impostare il default                                  */
    if(def){
        /*  accodo la sottostringa "DEF"                                        */
        m_driver->write(__ESP_AT_DEF);
    }else{
        /*  altrimenti accodo la sottostringa "CUR"                             */
        m_driver->write(__ESP_AT_CUR);
    }
    /*  accodo l'uguale                                                         */
    m_driver->write("=");
    /*  accodo la modalità                                                      */
    m_driver->write(static_cast<uint32>(mode));
    /*  e la terminazione                                                       */
    m_driver->write(__ESP_AT_TERM);
    /*  attendo l'ok                                                            */
    res = wdttmr(__ESP_AT_OK, ms);
    /*  se non e' richiesto il reset                                            */
    if(!rst){
        /*  ritorno subito                                                      */
        return res;
    }
    /*  se l'operazione è andata male                                           */
    if(!res){
        /*  ritorno false                                                       */
        return res;
    }
    /*  altrimenti ritorno il risultato di reset                                */
    return reset();
}

bool AFramework::AESP07::joinAP(const AString & ssid, const AString & pwd, const bool def, const uint32 ms) const{
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo il comando sulla seriale                                         */
    m_driver->write(__ESP_AT_JOINAP);
    /*  se l'utente vuole impostare il default                                  */
    if(def){
        /*  accodo la sottostringa "DEF"                                        */
        m_driver->write(__ESP_AT_DEF);
    }else{
        /*  altrimenti accodo la sottostringa "CUR"                             */
        m_driver->write(__ESP_AT_CUR);
    }
    /*  accodo l'uguale                                                         */
    m_driver->write("=");
    /*  accodo il ssid                                                          */
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(ssid.c_str());
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(",");
    /*  accodo la password                                                      */
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(pwd.c_str());
    m_driver->write(__ESP_AT_QUOTE);
    /*  e la terminazione                                                       */
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::leaveAP(const uint32 ms) const{
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->write(__ESP_AT_LEAVEAP);
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_DISCONNECT, ms);
}

bool AFramework::AESP07::configureAP(const AString & ssid, const AString & pwd, const ESPEncryption enc, const uint8 channel, const bool def, const uint32 ms) const{
    /*  se la seriale non e' ok oppure la password e' vuota (o troppo corta) ma */
    /*  e' stata specificata una cifratura oppure la password non e' vuota ma   */
    /*  la rete è aperta                                                        */
    if(!m_flg || ((pwd.size() < 0x08) && enc != Open) || (pwd.isEmpty() && enc == Open)){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo il comando sulla seriale                                         */
    m_driver->write(__ESP_AT_APCONF);
    /*  se il flag di default è true                                            */
    if(def){
        /*  accodo "DEF"                                                        */
        m_driver->write(__ESP_AT_DEF);
    }else{
        /*  altrimenti accodo "CUR"                                             */
        m_driver->write(__ESP_AT_CUR);
    }
    /*  accodo l'uguale                                                         */
    m_driver->write("=");
    /*  accodo il ssid                                                          */
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(ssid.c_str());
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(",");
    /*  accodo la password                                                      */
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(pwd.c_str());
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(",");
    /*  accodo il canale                                                        */
    m_driver->write(static_cast<uint32>(channel));
    m_driver->write(",");
    /*  accodo la cifratura                                                     */
    m_driver->write(static_cast<uint32>(enc));
    /*  e la terminazione                                                       */
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del wdt                                            */
    return wdttmr(__ESP_AT_OK, ms);   
}

bool AFramework::AESP07::setDhcp(const bool en, const bool def, const uint32 ms) const{
    ESPMode tmp = mode();
    /*  se la seriale non e' ok o c'è un problema con il modulo                 */
    if(!m_flg || tmp == NoMode){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo il comando sulla seriale                                         */
    m_driver->write(__ESP_AT_DHCPCONF);
    /*  se il flag di default è true                                            */
    if(def){
        /*  accodo "DEF"                                                        */
        m_driver->write(__ESP_AT_DEF);
    }else{
        /*  altrimenti accodo "CUR"                                             */
        m_driver->write(__ESP_AT_CUR);
    }
    /*  accodo l'uguale                                                         */
    m_driver->write("=");
    /*  accodo la modalità opportunamente castata                               */
    m_driver->write(static_cast<uint32>(tmp));
    /*  accodo la virgola                                                       */
    m_driver->write(",");
    /*  accodo l'enable                                                         */
    m_driver->write(en ? "1" : "0");
    /*  ed inserisco la terminazione                                            */
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del wdt                                            */
    return wdttmr(__ESP_AT_OK, ms);   
}

bool AFramework::AESP07::setAutoConnect(const bool en, const uint32 ms) const{
    /*  se la seriale non e' ok                                                 */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo il comando sulla seriale                                         */
    m_driver->write(__ESP_AT_AUTOCONN);
    /*  scrivo l'enable                                                         */
    m_driver->write(en ? "1" : "0");
    /*  ed inserisco la terminazione                                            */
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del wdt                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

AFramework::AString AFramework::AESP07::MAC(ESPMode mode, const uint32 ms){
    AString str;
    /*  se la seriale non è ok o la modalità non è valida                       */
    if(!m_flg || mode == NoMode || mode == BothMode){
        /*  ritorno una stringa vuota                                           */
        return str;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo la query sulla seriale                                           */
    m_driver->write(mode == StationMode ? __ESP_AT_STATIONMAC : __ESP_AT_APMAC);
    /*  ed accodo la terminazione                                               */
    m_driver->write(__ESP_AT_TERM);
    /*  aspetto l'ok... se questo non arriva                                    */
    if(!wdttmr(__ESP_AT_OK, ms)){
        /*  ritorno una strina vuota                                            */
        return str;
    }
    /*  se invece arriva prendo il contenuto del buffer                         */
    str = m_driver->read();
    /*  rimuovo quello che non interessa                                        */
    str.remove(mode == StationMode ? __ESP_AT_Q_STAT_MAC : __ESP_AT_Q_AP_MAC);
    /*  e ritorno la sottostringa ovvero i primi 17 caratteri (ad esempio:      */
    /*  18:fe:35:98:d3:7b)                                                      */
    return str.left(0x11);
}

bool AFramework::AESP07::setIp(const ESPMode mode, const AString &addr, const AString &gateway, const AString &netmask, const bool def, const uint32 ms) const{
    /*  se la seriale non è ok o la modalità non è valida o l'ip è vuoto        */
    if(!m_flg || mode == NoMode || mode == BothMode || addr.isEmpty()){
        /*  ritorno false                                                       */
        return false;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  se la modalità è stazione                                               */
    if(mode == StationMode){
        /*  scrivo il comando per la stazione                                   */
        m_driver->write(__ESP_AT_STATION_IP);
    }else{
        /*  altrimenti per l'access point                                       */
        m_driver->write(__ESP_AT_AP_IP);
    }
    /*  se il flag di default è true                                            */
    if(def){
        /*  accodo "DEF"                                                        */
        m_driver->write(__ESP_AT_DEF);
    }else{
        /*  altrimenti accodo "CUR"                                             */
        m_driver->write(__ESP_AT_CUR);
    }
    /*  accodo l'uguale                                                         */
    m_driver->write("=");
    /*  accodo l'indirizzo ip                                                   */
    m_driver->write(__ESP_AT_QUOTE);
    m_driver->write(addr.c_str());
    m_driver->write(__ESP_AT_QUOTE);
    /*  se gateway non è vuoto                                                  */
    if(!gateway.isEmpty()){
        /*  accodo la virgola                                                   */
        m_driver->write("=");
        /*  accodo l'indirizzo ip del gateway                                   */
        m_driver->write(__ESP_AT_QUOTE);
        m_driver->write(gateway.c_str());
        m_driver->write(__ESP_AT_QUOTE);
    }
    /*  se la netmask non è vuota                                               */
    if(!netmask.isEmpty()){
        /*  accodo la virgola                                                   */
        m_driver->write("=");
        /*  accodo la netmask                                                   */
        m_driver->write(__ESP_AT_QUOTE);
        m_driver->write(netmask.c_str());
        m_driver->write(__ESP_AT_QUOTE);
    }
    /*  inserisco la terminazione                                               */
    m_driver->write(__ESP_AT_TERM);
    /*  ritorno il risultato del wdt                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::prepareForReceive() const{
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  svuoto il buffer                                                        */
    m_driver->bufferClear();
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AESP07::connectToHost(const AString &addr, const uint16 port, const uint32 ms) const{
    /*  se va tutto bene                                                        */
    if(prepareForReceive()){
        /*  scrivo il comando sulla seriale                                     */
        m_driver->write(__ESP_AT_TCP_CONN);
        /*  accodo le virgolette                                                */
        m_driver->write(__ESP_AT_QUOTE);
        /*  accodo l'ip                                                         */
        m_driver->write(addr.c_str());
        /*  accodo le virgolette                                                */
        m_driver->write(__ESP_AT_QUOTE);
        /*  metto la virgola                                                    */
        m_driver->write(",");
        /*  accodo la porta                                                     */
        m_driver->write(static_cast<uint32>(port));
        /*  ed inserisco la terminazione                                        */
        m_driver->write(__ESP_AT_TERM);
        /*  ritorno il risultato del WDT                                        */
        return wdttmr(__ESP_AT_OK, ms);
    }
    /*  altrimenti ritorno false                                                */
    return false;
}

bool AFramework::AESP07::disconnectFromHost(const uint32 ms) const{
    /*  se va tutto bene                                                        */
    if(prepareForReceive()){
        /*  scrivo il comando sulla seriale                                     */
        m_driver->write(__ESP_AT_CLOSE_CONN);
        /*  ed inserisco la terminazione                                        */
        m_driver->write(__ESP_AT_TERM);
        /*  ritorno il risultato del WDT                                        */
        return wdttmr(__ESP_AT_OK, ms);
    }
    /*  altrimenti ritorno false                                                */
    return false;
}

bool AFramework::AESP07::waitForData(AString &str, const uint32 ms) const{
    
    bool        flg;
    uint32      ind = 0;
    uint32      dim = 0;
    AString     tm1;
    AString     tm2;
    
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  aspetto di ricevere qualcosa                                            */
    if(wdttmr(__ESP_AT_DATA, ms)){
        /*  aspetto che la dimensione sia arrivata                              */
        while(!m_driver->bufferContains(":"));
        /*  prendo l'indice di dove si trovano i due punti di +IPD,xxxx:        */
        ind = m_driver->read().indexOf(":");
        /*  prendo tutto quello che sta a sinistra di ":" (compreso)            */
        tm1 = m_driver->read().left(ind + 1);
        /*  copio la stringa                                                    */
        tm2 = tm1;
        /*  rimuovo i ":"                                                       */
        tm2.remove(":");
        /*  se sono rimasti residui di \r\n di una eventuale send               */
        if(tm2.startsWith(__ESP_AT_TERM)){
            /*  li rimuovo                                                      */
            tm2.remove(__ESP_AT_TERM);
        }
        /*  rimuovo +IPD,                                                       */
        tm2.remove(__ESP_AT_DATA);
        /*  prendo la dimensione del dato in arrivo                             */
        dim = static_cast<uint32>(tm2.toInt32(flg));
        /*  aspetto che sia arrivato tutto                                      */
        while(m_driver->read().size() - tm1.size() < dim);
        /*  rileggo il buffer                                                   */
        str = m_driver->read();
        /*  lo svuoto                                                           */
        m_driver->bufferClear();
        /*  elimino la sottostringa ("\r\n")"+IPD,xxx:"                         */
        str.remove(tm1);
        /*  ritorno true                                                        */
        return true;
    }
    /*  altrimenti false                                                        */
    return false;
}

bool AFramework::AESP07::send(const AString &str) const{
    /*  se va tutto bene                                                        */
    if(prepareForReceive()){
        /*  scrivo il comando sulla seriale                                     */
        m_driver->write(__ESP_AT_SEND);
        /*  accodo la lunghezza della stringa                                   */
        m_driver->write(str.size());
        /*  accodo la terminazione                                              */
        m_driver->write(__ESP_AT_TERM);
        /*  se non arriva l'ok in tempo utile (500ms)                           */
        if(!wdttmr(__ESP_AT_OK, 500)){
            return false;
        }
        /*  pulisco il buffer                                                   */
        m_driver->bufferClear();
        /*  scrivo la stringa                                                   */
        m_driver->write(str.c_str());
        /*  inserisco la terminazione                                           */
        m_driver->write(__ESP_AT_TERM);
        /*  se non arriva l'ok in tempo utile (1s)                              */
        if(!wdttmr(__ESP_AT_OK, 1000)){
            return false;
        }
        /*  pulisco il buffer                                                   */
        m_driver->bufferClear();
        /*  se tutto è filato liscio ritorno true                               */
        return true;
    }
    /*  altrimenti ritorno false                                                */
    return false;
}

bool AFramework::AESP07::setMultipleConnections(const bool en, const uint32 ms) const{
    
    AString str = __ESP_AT_MUX;
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    if(en){
        
        str += "1";
    }else{
        
        str += "0";
    }
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP07::listen(const uint16 port, const uint32 timeout, const uint32 ms){
    
    bool flag = false;
    AString str = __ESP_AT_SERVER;
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    
    str += "1,";
    str += AString(static_cast<sint32>(port));
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    flag = wdttmr(__ESP_AT_OK, ms);
    if(!flag){
        return false;
    }
    str.clear();
    str = __ESP_AT_TIMEOUT;
    str += AString(static_cast<sint32>(timeout));
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

AFramework::AESP07::ESPMode AFramework::AESP07::mode(const bool def, const uint32 ms) const{
    AString str;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return NoMode;
    }
    /*  diversamente, pulisco il buffer di ricezione                            */
    m_driver->bufferClear();
    /*  scrivo il comando sulla seriale                                         */
    m_driver->write(__ESP_AT_WIFIMODE);
    /*  se l'utente vuole sapere la configurazione di default                   */
    if(def){
        /*  scrivo DEF                                                          */
        m_driver->write(__ESP_AT_DEF);
    }else{
        /*  altrimenti cur                                                      */
        m_driver->write(__ESP_AT_CUR);
    }
    /*  scrivo il punto interrogativo                                           */
    m_driver->write("?");
    /*  e la terminazione                                                       */
    m_driver->write(__ESP_AT_TERM);
    /*  aspetto l'ok... se questo non arriva                                    */
    if(!wdttmr(__ESP_AT_OK, ms)){
        /*  ritorno NoMode                                                      */
        return NoMode;
    }
    /*  se invece arriva prendo il contenuto del buffer                         */
    str = m_driver->read();
    /*  rimuovo quello che non interessa                                        */
    str.remove(def ? __ESP_AT_Q_MODE_DEF : __ESP_AT_Q_MODE_CUR);
    /*  e ritorno il primo carattere opportunamente convertito                  */
    return static_cast<ESPMode>(str[0] - 0x30);
}

bool AFramework::AESP07::wdttmr(const char * str, const uint32 ms) const{
    bool res1 = false;
    bool res2 = false;
    /*  prendo il tempo di sistema                                              */
    ATime deadline = System::aliveTime();
    /*  aggiungo il timeout                                                     */
    deadline += ms;
    /*  fino a che il tempo non è scaduto                                       */
    while(System::aliveTime() <= deadline){
        /*  controllo che nel buffer ci sia la stringa cercata                  */
        res1 = m_driver->bufferContains(str);
        /*  controllo che nel buffer ci sia FAIL oppure ERROR                   */
        res2 = (m_driver->bufferContains(__ESP_AT_FAIL) || 
                m_driver->bufferContains(__ESP_AT_ERROR));
        
        /*  se ho trovato il token                                              */
        if(res1){
            /*  esco dal loop                                                   */
            break;
        }
        /*  se il buffer contiene fail o error                                  */
        if(res2){
            /*  ritorno subito false                                            */
            return false;
        }
    }
    /*  ritorno il flag                                                         */
    return res1;
}