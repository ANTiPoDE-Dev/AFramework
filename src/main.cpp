
#include <math.h>

#include "ASystemConfig.h"
#include "ACore.h"
#include "SmartMote.h"

#define _SSID_ADDRESS   0x0000
#define _KEY_ADDRESS    0x0100
#define _HOST_ADDRESS   0x0200
#define _MAC_ADDRESS    0x0300

#define _PHP_CHUNK1 "POST /smartmote.php HTTP/1.0\r\nHost: "
/*  tra chunk1 e chunk2 inserire l'hostname                                     */
#define _PHP_CHUNK2 "\r\nAccept: */*\r\nContent-Length: "
/*  tra chunk2 e chunk3 inserire la lunghezza della stringa dati                */
#define _PHP_CHUNK3 "\r\nContent-Type: application/x-www-form-urlencoded\r\n\r\n"
/*  ed infine la stringa dati                                                   */

using namespace std;
using namespace AFramework;

void turnOnRed();
void turnOnGreen();
void turnOffRed();
void turnOffGreen();
void error();

bool checkButton();

void saveSSID(const AString & str);
void saveKey(const AString & str);
void saveHost(const AString & str);
void saveMAC(const AString & str);


AString luminosity();
AString ambientTempAndHum();
AString groundTemp();
AString groundHum();
AString battey();

AString mac();
AString getSSID();
AString getKey();
AString getHost();

void wasSuccess(const AString & str);

uint32 getSleepTime();
void setNextAlarm();
        

extern "C"{    
    void __ISR(_UART_1_VECTOR, IPL1AUTO) UART_1_HANDLER(){
        UART1.rxHandler();
    }
    
    void __ISR(_RTCC_VECTOR, IPL2AUTO) RTCC_HANDLER(){
        if(RTCC.hasInterruptOccurred()){
            RTCC.clearFlag();
        }
    }
}

int main(){
    /*  inizializzo il kernel                                                   */
    System::init(16392, NULL, 0, System::Freq40MHz, System::Freq40MHz, 32768.15);
    
    /*  mappo l'UART1                                                           */
    System::inputMap(RPB2R, U1RXR);
    System::outputMap(RPB3R, U1TXR);
    
    /*  Configurazione GPIO                                                     */
    PortA.setAnalog(bit0 | bit1);
    PortB.setAnalog(bit15);
    PortB.setOutput(bit0 | bit1 | bit5 | bit7 | bit10 | bit13 | bit14);
    PortB.write(bit0 , Lo);
    PortB.write(bit1 , Lo);
    PortB.write(bit5 , Lo);
    PortB.write(bit7 , Lo);
    PortB.write(bit10, Lo);
    PortB.write(bit13, Lo);
    PortB.write(bit14, Lo);
    /*  accendo l'orologio                                                      */
    RTCC.open();
    /*  abilito l'interrupt dell'orologio                                       */
    RTCC.enableInterrupt(Ip2, Isp0);
    /*  abilito l'interrupt                                                     */
    UART1.getReceiverEventController()->enableInterrupt(Ip1, Isp0);
    
    AESP07 net(&UART1);
    
    RTCC.setHours(0);
    RTCC.setMinutes(0);
    RTCC.setSeconds(0);
    
    
    if(checkButton()){
        AString conf;
        AStringList * param = NULL;
        bool flag;
        /*  inizializzo il modulo come AP                                           */
        if(!net.initialize(AESP07::APMode)){
            /*  se fallisce notifico l'errore                                       */
            error();
        }
        /*  setto il nome come SmartMote e password admin                           */
        if(!net.configureAP("SmartMote", "smartmote")){
            /*  se fallisce notifico l'errore                                       */
            error();        
        }
        /*  imposto l'ip a 192.168.1.1                                              */
        if(!net.setIp(AESP07::APMode, "192.168.1.1")){
            /*  se fallisce notifico l'errore                                       */
            error();        
        }
        /*  disabilito le connessioni multiple                                      */
        if(!net.setMultipleConnections(true)){
            /*  se fallisce notifico l'errore                                       */
            error();                
        }
        /*  apro il server sulla porta 8000                                         */
        if(!net.listen(8000)){
            /*  se fallisce notifico l'errore                                       */
            error();
        }
        /*  aspetto di ricevere la stringa                                          */
        while(conf.isEmpty()){

            net.waitForData(conf);
        }
        /*  prendo i parametri                                                      */
        param = conf.split(' ');
        /*  se la stringlist è allocata correttamente                               */
        if(param){
            saveMAC(net.MAC());
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
            UART1.open(AUARTDriver::Baud115200, AUARTDriver::Data8bitNoParity, AUARTDriver::Stop1bit);
            /*  prendo le misure                                                */
            data += mac();
            data += luminosity();
            data += ambientTempAndHum();
            data += groundTemp();
            data += groundHum();
            data += battey();
            /*  compongo la stringa                                             */
            message += _PHP_CHUNK1;
            
//            /*  inserisco l'hostname                                            */
//            message += getHost();
            /*  inserisco l'hostname                                            */
            message += "smartislandwsntesting.altervista.org";
            
            /*  inserisco la seconda parte di richiesta http                    */
            message += _PHP_CHUNK2;
            /*  inserisco la lunghezza dei dati                                 */
            message += AString(static_cast<sint32>(data.size()));
            /*  inserisco la terza parte di richiesta http                      */
            message += _PHP_CHUNK3;
            /*  inserisco i dati                                                */
            message += data;

            /*  provo 5 volte a dialogare con l'esp                             */
            uint8 cnt = 0;
            while(!net.isOk()){
                cnt++;
                if(cnt == 5){
                    break;
                }
            }
            /*  se dopo 5 tentativi non ho avuto risposta                       */
            if(cnt == 5){
                /*  notifico l'errore                                           */
                error();
            }
            /*  se fallisce l'inizializzazione dell'esp                         */
            if(!net.initialize()){
                /*  notifico l'errore                                           */
                error();
            }
            /*  se fallisce l'avvio del dhcp                                    */
            if(!net.setDhcp(true)){
                /*  notifico l'errore                                           */
                error();
            }
            /*  se fallisce la connessione alla rete                            */
            if(!net.joinAP("SmartIsland", "smartisland")){
                /*  notifico l'errore                                           */
                error();
            }
            /*  se fallisce la connessione al server                            */
            if(!net.connectToHost("smartislandwsntesting.altervista.org", 80)){
                /*  notifico l'errore                                           */
                error();
            }
            /*  invio i dati                                                    */
            net.send(message);
            /*  aspetto l'ok                                                    */
            net.waitForData(answer);
            /*  notifico l'ok o lerrore dell'invio                              */
            wasSuccess(answer);
            /*  lascio l'ap                                                     */
            net.leaveAP();
            /*  libero la memoria occupata dalle stringhe                       */
            message.clear();
            data.clear();
            answer.clear();
        }
        RTCC.setHours(0);
        RTCC.setMinutes(0);
        RTCC.setSeconds(0);
        /*  calcolo del tempo di sleep per il wifi                              */
        net.sleep(getSleepTime());
        /*  punto la prossima sveglia                                           */
        setNextAlarm();
        /*  spengo il led verde                                                 */
        turnOffGreen();
        /*  spengo l'uart                                                       */
        UART1.close();
        /*  spengo il core timer                                                */
        System::stopCoreTimer();
        /*  vado a dormire                                                      */
        System::sleep();
            
    }
    
    return 0;
}

void turnOnRed(){
    PortB.write(bit5, Hi);
}

void turnOnGreen(){
    PortB.write(bit7, Hi);
}

void turnOffRed(){
    PortB.write(bit5, Lo);
}

void turnOffGreen(){
    PortB.write(bit7, Lo);
}

void error(){
    while(1){
        turnOnRed();
        turnOnGreen();
        System::delay(500);
        turnOffRed();
        turnOffGreen();
        System::delay(500);
    }
}

bool checkButton(){
        /*  controllo che il bottone sia premuto                                    */
    if(PortB.read(bit11) == Lo){
        /*  aspetto 500 ms*/
        System::delay(250);
        /*  controllo che il bottone sia ancora premuto                         */
        if(PortB.read(bit11) == Lo){
            /*  accendo i led per far capire all'utente che può lasciare        */
            turnOnRed();
            turnOnGreen();
            /*  aspetto che l'utente lo rilasci                                 */
            while(PortB.read(bit11) == Lo);
            /*  ritorno true                                                    */
            return true;
        }
    }
    /*  altrimenti ritorno false                                                */
    return false;
}

void saveSSID(const AString & str){
    A24LC512 mem(&I2C1);
    mem.write(_SSID_ADDRESS, str);
    I2C1.close();
}

void saveKey(const AString & str){
    A24LC512 mem(&I2C1);
    mem.write(_KEY_ADDRESS, str);
    I2C1.close();
}

void saveHost(const AString & str){
    A24LC512 mem(&I2C1);
    mem.write(_HOST_ADDRESS, str);
    I2C1.close();
}

void saveMAC(const AString & str){
    A24LC512 mem(&I2C1);
    mem.write(_MAC_ADDRESS, str);
    I2C1.close();
}

AString luminosity(){
    uint32  lum = ADC.read(AADC::AN0);
    double  num = (static_cast<double>(lum) / 1023.0) * 100;
    AString str(num, 2);
    str.prepend("aLum=");
    str += "&";
    return str;
}

AString ambientTempAndHum(){
    ADht22 aT_H(&PortA, bit2);
    /*  se il dht22 è morto                                                     */
    if(!aT_H.read()){
        /*  notifico l'errore                                                   */
        error();
    }
    /*  prendo la temperatura                                                   */
    AString tmp(aT_H.temperature(), 2);
    /*  prendo l'umidità                                                        */
    AString hum(aT_H.humidity(), 2);
    /*  compongo la stringa                                                     */
    AString str("aTmp=");
    str += tmp;
    str += "&aHum=";
    str += hum;
    str += "&";
    return str;
}

AString groundTemp(){
    AOneWire wire(&PortA, bit3);
    ADS18B20 gTmp(&wire);
    /*  se il ds18 è morto                                                      */
    if(!gTmp.read()){
        /*  notifico l'errore                                                   */
        error();
    }
    System::delay(100);
    gTmp.temperature();
    /*  se il ds18 è morto                                                      */
    if(!gTmp.read()){
        /*  notifico l'errore                                                   */
        error();
    }
    /*  prendo la temperatura                                                   */
    AString tmp(gTmp.temperature(), 2);
    /*  inserisco gTmp                                                          */
    tmp.prepend("gTmp=");
    tmp += "&";
    return tmp;
    
}

AString groundHum(){
    uint32 hum = ADC.read(AADC::AN1);
    double num = ((1023.0 - static_cast<double>(hum)) / 1023.0) * 100;
    AString str(num, 2);
    str.prepend("gHum=");
    str += "&";
    return str;
}

AString battey(){
    uint32  bat = ADC.read(AADC::AN9);
    double  num = (((((static_cast<double>(bat) * 3.3) / 1023) * 2) / 4.7) * 100);
    AString str(num, 2);
    str.prepend("vBat=");
    return str; 
}

AString mac(){
    //A24LC512 mem(&I2C1);
    //AString str;
    //mem.read(_MAC_ADDRESS, str);
    //I2C1.close();
    //return str;
    return "mAdd=f8:32:e4:72:7f:1e&";
}

AString getSSID(){
    A24LC512 mem(&I2C1);
    AString str;
    mem.read(_SSID_ADDRESS, str);
    I2C1.close();
    return str;
}

AString getKey(){
    A24LC512 mem(&I2C1);
    AString str;
    mem.read(_KEY_ADDRESS, str);
    I2C1.close();
    return str;
}

AString getHost(){
    A24LC512 mem(&I2C1);
    AString str;
    mem.read(_HOST_ADDRESS, str);
    I2C1.close();
    return str;
}

void wasSuccess(const AString & str){
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

uint32 getSleepTime(){
        
    ATime curr = RTCC.currentTime();
    ATime next = curr;
    
    next.addMinutes(5);
    next.setSeconds(0);
    
    next -= curr;
    
    return next.raw();
}

void setNextAlarm(){
    ATime curr = RTCC.currentTime();
    curr.addMinutes(5);
    curr.setSeconds(0);
    uint8 hh = curr.hours();
    uint8 mm = curr.minutes();
    RTCC.setAlarm(hh, mm);
}