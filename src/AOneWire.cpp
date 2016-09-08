#include "AOneWire.h"


AFramework::AOneWire::AOneWire(volatile AHardwarePort * port, const uint32 gpio) : m_port(port), m_gpio(gpio){
    /*  se la porta è NULL                                                      */
    if(!m_port){
        /*  metto il flag di inizializzazione a falso                           */
        m_flag = false;
    /*  altrimenti                                                              */
    }else{
        /*  dopo aver impostato il pin come digitale                            */
        m_port->setDigital(m_gpio);
        /*  e come ingresso                                                     */
        m_port->setInput(m_gpio);
        /*  metto il flag a true                                                */
        m_flag = true;
    }
}
            
bool  AFramework::AOneWire::reset(){
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno subito false                                                */
        return false;
    }
    /*  metto il gpio come uscita                                               */
    m_port->setOutput(m_gpio);
    /*  metto basso                                                             */
    m_port->write(m_gpio, Lo);
    /*  aspetto 480us (richiesti dal protocollo)                                */
    System::delay_us(480);
    /*  metto il gpio come ingresso                                             */
    m_port->setInput(m_gpio);
    /*  aspetto 60us prima di leggere lo stato del bus                          */
    System::delay_us(60);
    /*  se lo stato del bus è basso allora c'è qualcuno                         */
    if(m_port->read(m_gpio) == Lo){
        /*  per cui aspetto 100us                                               */
        System::delay_us(100);
        /*  e ritorno true                                                      */
        return true;
    }
    /*  altrimenti non c'è nessuno per cui ritorno false                        */
    return false;
}
            
AFramework::uint8 AFramework::AOneWire::readByte(){
    uint8 res = 0;
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno subito 0                                                    */
        return res;
    }
    /*  per 8 bit in totale                                                     */
    for(uint8 i = 0; i < 8; i++){
        /*  sposto a sinistra tutto res di uno                                  */
        res >>= 1;
        /*  se il bit letto è 1                                                 */
        if(readBit()){
            /*  lo accodo come MSB                                              */
            res |= 0x80;
        }
    }
    /*  ritorno il risultato                                                    */
    return res;
}

bool  AFramework::AOneWire::writeByte(const uint8 data){
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno subito false                                                */
        return false;
    }
    /*  per 8 bit in totale                                                     */
    for(uint8 i = 0; i < 8; i++){
        /*  scrivo il bit meno significativo                                    */
        writeBit((data >> i) & 0x01);
    }
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AOneWire::waitLow(const uint32 preDelay_us){
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno subito false                                                */
        return false;
    }
    /*  imposto il gpio come input                                              */
    m_port->setInput(m_gpio);
    /*  aspetto per quanto richiesto                                            */
    System::delay_us(preDelay_us);
    /*  aspetto il cambio di stato                                              */
    while(m_port->read(m_gpio) == Lo);
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AOneWire::waitHigh(const uint32 preDelay_us){
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno subito false                                                */
        return false;
    }
    /*  imposto il gpio come input                                              */
    m_port->setInput(m_gpio);
    /*  aspetto per quanto richiesto                                            */
    System::delay_us(preDelay_us);
    /*  aspetto il cambio di stato                                              */
    while(m_port->read(m_gpio) == Hi);
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AOneWire::writeBit(const uint8 b){
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno subito false                                                */
        return false;
    }
    /*  metto il gpio come uscita                                               */
    m_port->setOutput(m_gpio);
    /*  metto basso                                                             */
    m_port->write(m_gpio, Lo);
    /* per evitare errori faccio l'and con 0x01, se risulta 1                   */
    if(b & 0x0001) {
        /*  vuol dire che dobbiamo scrivere un 1, quindi aspetto 5us            */
        System::delay_us(5);
        /*  metto il gpio come ingresso (riattivo i pull-up)                    */
        m_port->setInput(m_gpio);
        /*  aspetto 60us                                                        */
        System::delay_us(60);
    /*  altrimenti dobbiamo scrivere uno zero                                   */
    }else{
        /*  quindi aspetto 70us                                                 */
        System::delay_us(70);
        /*  metto il gpio come ingresso (riattivo i pull-up)                    */
        m_port->setInput(m_gpio);
        /*  aspetto 2us                                                        */
        System::delay_us(2);;
    }
}

bool AFramework::AOneWire::readBit(){
    bool res = false;
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno subito false                                                */
        return res;
    }
    /*  metto il gpio come uscita                                               */
    m_port->setOutput(m_gpio);
    /*  metto basso                                                             */
    m_port->write(m_gpio, Lo);
    /*  aspetto ius                                                             */
    System::delay_us(1);
    /*  metto il gpio come ingresso                                             */
    m_port->setInput(m_gpio);
    /*  aspetto 5us                                                             */
    System::delay_us(5);
    /*  campiono                                                                */
    res = (m_port->read(m_gpio) == Hi);
    /*  aspetto 55us                                                            */
    System::delay_us(55);
    /*  ritorno il risultato                                                    */
    return res; 
}