#include <math.h>

#include"ADht22.h"

#define _DHT_NEG_MASK 0x8000
#define _DHT_TMP_MASK 0x7FFF

AFramework::ADht22::ADht22(volatile AHardwarePort *port, const uint32 gpio) : m_port(port), m_gpio(gpio), m_temp(0), m_hum(0){
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

double AFramework::ADht22::temperature(){
    /*  ritorno la temperatura                                                  */
    return (m_temp & _DHT_NEG_MASK ? (static_cast<double>(m_temp & _DHT_TMP_MASK) / -10.0) : (static_cast<double>(m_temp & _DHT_TMP_MASK) / 10.0));
}

double AFramework::ADht22::humidity(){
    /*  ritorno l'umidità                                                       */
    return (static_cast<double>(m_hum) / 10.0);
}

bool AFramework::ADht22::read(){
    uint8 humMSB = 0;
    uint8 humLSB = 0;
    uint8 tmpMSB = 0;
    uint8 tmpLSB = 0;
    uint8 chksum = 0;
    
    /*  se la porta non è stata inizializzata correttamente                     */
    if(!m_flag){
        /*  ritorno immediatamente false                                        */
        return false;
    }
    
    /*  aspetto 2 secondi                                                       */
    System::delay(2000);
    /*  mando lo start                                                          */
    startSignal();
    /*  se non arriva risposta                                                  */
    if(!checkResponse()){
        /*  ritorno false                                                       */
        return false;
    }
    /*  leggo i byte                                                            */
    humMSB = readByte();
    humLSB = readByte();
    tmpMSB = readByte();
    tmpLSB = readByte();
    chksum = readByte();
    /*  controllo il checksum                                                   */
    if(humMSB + humLSB + tmpMSB + tmpLSB != chksum){
        /**
         * @todo: controllo errore!
         */
    }
    /*  ricompongo l'umidità                                                    */
    m_hum  = ((humMSB << 0x08) + humLSB);
    /*  ricompongo la temperatura                                               */
    m_temp = ((tmpMSB << 0x08) + tmpLSB);
    /*  ritorno true                                                            */
    return true;
}

void AFramework::ADht22::startSignal(){
    
    /*  imposto il gpio come uscita                                             */
    m_port->setOutput(m_gpio);
    /*  metto basso                                                             */
    m_port->write(m_gpio, Lo);
    /*  aspetto 18 ms                                                           */
    System::delay(18);
    /*  metto alto                                                              */
    m_port->write(m_gpio, Hi);
    /*  aspetto 30 us                                                           */
    System::delay_us(30);
    /*  imposto il gpio come ingresso                                           */
    m_port->setInput(m_gpio);
    /*  aspetto 2 us                                                           */
    System::delay_us(2);
}

bool AFramework::ADht22::checkResponse(){
    
    /*  se l'ingresso è basso                                                   */
    if(m_port->read(m_gpio) == Lo){
        /*  aspetto che il sensore si porti alto                                */
        while(m_port->read(m_gpio) == Lo);
        /*  se arriva il segnale                                                */
        if(m_port->read(m_gpio) == Hi){
            /*  aspetto che il sensore completi la sequenza di risposta         */
            while(m_port->read(m_gpio) == Hi);
            /*  piccolo delay (non fa male)                                     */
            System::delay_us(20);
            /*  ritorno true                                                    */
            return true;
        /*  altrimenti qualcosa è andato storto                                 */
        }else{
            /*  per cui ritorno false                                           */
            return false;
        }
    }
    /*  se non è basso vuol dire che qualcosa è andato storto e quindi ritorno  */
    /*  false                                                                   */
    return false;
}

AFramework::uint8 AFramework::ADht22::readByte(){
    uint8 byte = 0;
    for(uint8 i = 0; i < 0x08; i++){
        /*  aspetto che passi il livello basso                                  */
        while(m_port->read(m_gpio) == Lo);
        /*  aspetto 40 us                                                       */
        System::delay_us(40);
        /*  se dopo 40 us il segnale è ancora alto                              */
        if(m_port->read(m_gpio) == Hi){
            /*  vuol dire che si tratta di un 1 per cui lo accodo               */
            byte |= (1 << (0x07 - i));
        }
        /*  aspetto che finisca il bit (nel caso in cui è già finito non è      */
        /*  un problema)                                                        */
        while(m_port->read(m_gpio) == Hi);
    }
    /*  ritorno il byte                                                         */
    return byte;
}
            