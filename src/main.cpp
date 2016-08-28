
#include "ASystemConfig.h"
#include "ACore.h"
#include "AString.h"
#include "AUARTDriver.h"
#include "AESP07.h"

using namespace std;
using namespace AFramework;

extern "C"{    
    void __ISR(_UART_1_VECTOR, IPL1AUTO) UART_1_HANDLER(){

        UART1.rxHandler();
    }
}

void good(const char * str){
    UART2.write("[+] wlan: ");
    UART2.writeln(str);
}

void fail(const char * str){
    UART2.write("[-] wlan: ");
    UART2.writeln(str);
    while(1);
}

int main(){

    
    /*  inizializzo il kernel                                                   */
    System::init(16392, &PortB, bit4);
    /*  mappo l'ingresso per l'UART1                                            */
    System::inputMap(RPB2R, U1RXR);
    /*  mappo l'ingresso per l'UART2                                            */
    System::inputMap(RPB8R, U2RXR);
    /*  mappo l'uscita per l'UART1                                              */
    System::outputMap(RPB3R, U1TXR);
    /*  mappo l'uscita per l'UART2                                              */
    System::outputMap(RPB9R, U2TXR);
    /*  abilito l'interrupt per l'UART1                                         */
    UART1.getReceiverEventController()->enableInterrupt(Ip1, Isp0);
    /*  apro l'UART2 per debug                                                  */
    UART2.open(AUARTDriver::Baud115200, AUARTDriver::Data8bitNoParity, AUARTDriver::Stop1bit);
    
    AString str;
    
    AESP07 wlan(&UART1);
    
    System::delay(1000);
    
    
    while(1){
        wlan.initialize();
        wlan.setDhcp(true);
        wlan.joinAP("MNet", "MLZGPP88L05G371K");
        wlan.connectToHost("192.168.1.100", 8000);
        wlan.send(wlan.MAC());
        wlan.disconnectFromHost();
        wlan.leaveAP();
        wlan.sleep(600000);
        
        System::delay(603000);
    }
    
    return 0;
}
