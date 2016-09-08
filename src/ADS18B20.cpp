#include "ADS18B20.h"

#define _DS18B20_SKIP_ROM        0x00CC
#define _DS18B20_START_CONVERT   0x0044
#define _DS18B20_READ_SCRATCHPAD 0x00BE
#define _DS18B20_SIGN_MASK       0xF800
#define _DS18B20_TEMP_INT_MASK   0x07F0
#define _DS18B20_TEMP_FLOAT_MASK 0x000F

AFramework::ADS18B20::ADS18B20(AOneWire * driver) : m_drv(driver), m_temp(0){
    /*  se il driver del protocollo non è valido                                */
    if(!m_drv){
        /*  metto il flag a false                                               */
        m_flag = false;
    /*  altrimenti se è tutto ok                                                */
    }else{
        /*  lo metto a true                                                     */
        m_flag = true;
    }
}

double AFramework::ADS18B20::temperature(){
    double res = 0x00;
    /*  intanto sommo la parte intera                                           */
    res += ((m_temp & _DS18B20_TEMP_INT_MASK) >> 0x04);
    /*  per la parte decimale invece                                            */
    for(uint8 i = 0x00; i < 0x04; i++){
        /*  se il bit è 1                                                       */
        if((m_temp >> i) & 0x01){
            /*  aggiungo l'opportuna potenza di due                             */
            res += 1.0 / static_cast<double>(0x01 << (0x04 - i));
        }
    }
    /*  se la temperatura è negativa                                            */
    if(m_temp & _DS18B20_SIGN_MASK){
        /*  moltiplico per -1                                                   */
        res *= -1.0;
    }
    /*  ritorno res                                                             */
    return res;
}

bool AFramework::ADS18B20::read(){
    uint8 sPad[0x09] = {0};
    /*  se il driver non è stato impostato correttamente                        */
    if(!m_drv){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se non rilevo la presenza di nessun sensore sul bus                     */
    if(!m_drv->reset()){
        /*  ritorno subito false                                                */
        return false;
    }
    /*  salto la fase di scrittura rom                                          */
    m_drv->writeByte(_DS18B20_SKIP_ROM);
    /*  inizio la conversione                                                   */
    m_drv->writeByte(_DS18B20_START_CONVERT);
    /*  aspetto che la conversione sia stata fatta                              */
    m_drv->waitLow(10);
    /*  se per assurdo il sensore dovesse morire                                */
    if(!m_drv->reset()){
        /*  ritorno subito false                                                */
        return false;
    }
    /*  salto la fase di scrittura rom                                          */
    m_drv->writeByte(_DS18B20_SKIP_ROM);
    /*  leggo lo scratchpad                                                     */
    m_drv->writeByte(_DS18B20_READ_SCRATCHPAD);
    /*  predo tutti i 9 byte                                                    */
    for(uint8 i = 0; i < 9; i++){
        
        sPad[i] = m_drv->readByte();
    }
    /*  sposto di 8 Th e sommo (faccio l'or) con Tl                             */
    m_temp = ((sPad[0x01] << 0x08) | sPad[0x00]);
    /*  ritorno true                                                            */
    return true;
}
            