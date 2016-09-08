#include "ARTCC.h"

extern volatile AFramework::ARTCC_w RTCC_w __asm__("RTCC_w") __attribute__((section("sfrs")));
AFramework::ARTCC AFramework::RTCC(&RTCC_w);

AFramework::ARTCC::ARTCC(volatile ARTCC_w * reg) : m_reg(reg), AInterruptSource(_IFSVEC_RTCCIF_POSITION, 
                                                                                _IECVEC_RTCCIE_POSITION, 
                                                                                _IPCVEC_RTCCIP_POSITION, 
                                                                                _IFS_RTCCIF_MASK,
                                                                                _IEC_RTCCIE_MASK,
                                                                                _IPC_RTCCIP_POSITION,
                                                                                _IPC_RTCCIS_POSITION){
   
}

void AFramework::ARTCC::open(){
    unlock();
    m_reg->RTCCON.CLR = (Quick::All & ~_RTCCON_RTCWREN_MASK);
    m_reg->RTCCON.SET = _RTCCON_ON_MASK;
    lock();
}

void AFramework::ARTCC::close(){
    unlock();
    m_reg->RTCCON.CLR = (Quick::All & ~_RTCCON_RTCWREN_MASK);
    m_reg->RTCCON.CLR = _RTCCON_ON_MASK;
    lock();
}

AFramework::uint8 AFramework::ARTCC::seconds() const{
    /*  nulla da commentare                                                     */
    return bcddec((m_reg->RTCTIME.REG & (_RTCTIME_SEC10_MASK | _RTCTIME_SEC01_MASK)) >> _RTCTIME_SEC01_POSITION);
}

AFramework::uint8 AFramework::ARTCC::minutes() const{
    /*  nulla da commentare                                                     */
    return bcddec((m_reg->RTCTIME.REG & (_RTCTIME_MIN10_MASK | _RTCTIME_MIN01_MASK)) >> _RTCTIME_MIN01_POSITION);
}

AFramework::uint8 AFramework::ARTCC::hours() const{
    /*  nulla da commentare                                                     */
    return bcddec((m_reg->RTCTIME.REG & (_RTCTIME_HR10_MASK | _RTCTIME_HR01_MASK)) >> _RTCTIME_HR01_POSITION);
}

AFramework::uint8 AFramework::ARTCC::days() const{
    /*  nulla da commentare                                                     */
    return bcddec((m_reg->RTCDATE.REG & (_RTCDATE_DAY10_MASK | _RTCDATE_DAY01_MASK)) >> _RTCDATE_DAY01_POSITION);    
}

AFramework::ADateTime::Weekdays AFramework::ARTCC::weekday() const{
    /*  nulla da commentare                                                     */
    return static_cast<ADateTime::Weekdays>(bcddec((m_reg->RTCDATE.REG & _RTCDATE_WDAY01_MASK) >> _RTCDATE_WDAY01_POSITION) + 1);
}

AFramework::ADateTime::Months AFramework::ARTCC::month() const{
    /*  nulla da commentare                                                     */
    return static_cast<ADateTime::Months>(bcddec((m_reg->RTCDATE.REG & (_RTCDATE_MONTH10_MASK | _RTCDATE_MONTH01_MASK)) >> _RTCDATE_MONTH01_POSITION));
}

AFramework::uint8 AFramework::ARTCC::years() const{
    /*  nulla da commentare                                                     */
    return bcddec((m_reg->RTCDATE.REG & (_RTCDATE_YEAR10_MASK | _RTCDATE_YEAR01_MASK)) >> _RTCDATE_YEAR01_POSITION);
}

bool AFramework::ARTCC::setDateTime(ADateTime tm){
    uint32 time = 0;
    uint32 date = 0;
    /*  se il parametro non è valido                                            */
    if(tm.Weekday() == ADateTime::NoWeekday || tm.month() == ADateTime::NoMonth){
        /*  ritorno false                                                       */
        return false;
    }
    /*  sblocco la scrittura dei registri                                       */
    unlock();
    /*  cancello tutto                                                          */
    m_reg->RTCTIME.CLR = Quick::All;
    m_reg->RTCDATE.CLR = Quick::All;
    /*  imposto il tempo                                                        */
    time = ((decbcd(tm.hours())   << _RTCTIME_HR01_POSITION ) | 
            (decbcd(tm.minutes()) << _RTCTIME_MIN01_POSITION) | 
            (decbcd(tm.seconds()) << _RTCTIME_SEC01_POSITION));
    m_reg->RTCTIME.REG = time;
    /*  imposto la data                                                         */
    date = ((decbcd(tm.year())                            << _RTCDATE_YEAR01_POSITION ) |
            (decbcd(static_cast<uint8>(tm.month()))       << _RTCDATE_MONTH01_POSITION) |
            (decbcd(tm.dayOfMonth())                      << _RTCDATE_DAY01_POSITION  ) |
            (decbcd(static_cast<uint8>(tm.Weekday()) - 1) << _RTCDATE_WDAY01_POSITION ));
    m_reg->RTCDATE.REG = date;
    /*  blocco la scrittura dei registri                                        */
    lock();
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ARTCC::setHours(const uint8 hh){
    /*  se le ore sono sballate                                                 */
    if(hh > 23){
        /*  ritorno false                                                       */
        return false;
    }
    /*  sblocco la scrittura dei registri                                       */
    unlock();
    /*  cancello i bit delle ore                                                */
    m_reg->RTCTIME.CLR  = (_RTCTIME_HR10_MASK | _RTCTIME_HR01_MASK);
    /*  vado di |=                                                              */
    m_reg->RTCTIME.REG |= (decbcd(hh) << _RTCTIME_HR01_POSITION);
    /*  blocco i registri                                                       */
    lock();
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ARTCC::setMinutes(const uint8 mm){
    /*  se i minuti sono sballati                                               */
    if(mm > 59){
        /*  ritorno false                                                       */
        return false;
    }
    /*  sblocco la scrittura dei registri                                       */
    unlock();
    /*  cancello i bit dei minuti                                               */
    m_reg->RTCTIME.CLR  = (_RTCTIME_MIN10_MASK | _RTCTIME_MIN01_MASK);
    /*  vado di |=                                                              */
    m_reg->RTCTIME.REG |= (decbcd(mm) << _RTCTIME_MIN01_POSITION);
    /*  blocco i registri                                                       */
    lock();
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ARTCC::setSeconds(const uint8 ss){
    /*  se i secondi sono sballati                                              */
    if(ss > 59){
        /*  ritorno false                                                       */
        return false;
    }
    /*  sblocco la scrittura dei registri                                       */
    unlock();
    /*  cancello i bit dei secondi                                              */
    m_reg->RTCTIME.CLR  = (_RTCTIME_SEC10_MASK | _RTCTIME_SEC01_MASK);
    /*  vado di |=                                                              */
    m_reg->RTCTIME.REG |= (decbcd(ss) << _RTCTIME_SEC01_POSITION);
    /*  blocco i registri                                                       */
    lock();
    /*  ritorno true                                                            */
    return true;    
}

AFramework::ATime AFramework::ARTCC::currentTime() const{
    /*  nulla da commentare                                                     */
    return ATime(days(), hours(), minutes(), seconds(), 0);
}

bool AFramework::ARTCC::setAlarm(const uint8 hours, const uint8 minutes){
    /*  se i parametri non sono validi                                          */
    if((hours > 0x17) || (minutes > 0x3B)){
        /*  ritorno false                                                       */
        return false;
    }
    /*  sblocco la scrittura dei registri                                       */
    unlock();
    /*  aspetto di poter scrivere                                               */
    while(m_reg->RTCALRM.REG & _RTCALRM_ALRMSYNC_MASK);
    /*  cancello tutto                                                          */
    m_reg->RTCALRM.CLR = Quick::All;
    /*  imposto la maschera (un allarme al giorno)                              */
    m_reg->RTCALRM.SET = 0x06 << _RTCALRM_AMASK_POSITION;
    /*  cancello il registro ALRMTIME                                           */
    m_reg->ALRMTIME.CLR = Quick::All;
    /*  imposto l'orario dell'allarme                                           */
    m_reg->ALRMTIME.REG = ((decbcd(hours)   << _ALRMTIME_HR01_POSITION ) | 
                           (decbcd(minutes) << _ALRMTIME_MIN01_POSITION) );
    /*  abilito l'allarme                                                       */
    m_reg->RTCALRM.SET = _RTCALRM_ALRMEN_MASK;
    /*  blocco la scrittura                                                     */
    lock();
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ARTCC::stopAlarm(){
    /*  sblocco la scrittura dei registri                                       */
    unlock();
    /*  aspetto di poter scrivere                                               */
    while(m_reg->RTCALRM.REG & _RTCALRM_ALRMSYNC_MASK);
    /*  cancello tutto                                                          */
    m_reg->RTCALRM.CLR = Quick::All;
    /*  riaccendo l'orologio                                                    */
    m_reg->RTCCON.SET = _RTCCON_ON_MASK;
    /*  blocco la scrittura                                                     */
    lock();
    /*  ritorno true                                                            */
    return true;
}

AFramework::uint8 AFramework::ARTCC::bcddec(const uint8 val) const{
    /*  converte un numero da BCD a decimale                                    */
    return ((((val & 0xF0) >> 0x04) * 0x0A) + (val & 0x0F));
}

AFramework::uint8 AFramework::ARTCC::decbcd(const uint8 val) const{
    /*  converte un numero da decimale a BCD                                    */
    return (((val / 0x0A) << 0x04) | (val % 0x0A));
}

void AFramework::ARTCC::unlock(){
    /*  sequenza di sblocco                                                     */
    System::unlockOscCon();
    /*  abilito la scrittura                                                    */
    m_reg->RTCCON.SET = _RTCCON_RTCWREN_MASK;
    /*  fermo l'orologio                                                        */
    m_reg->RTCCON.CLR = _RTCCON_ON_MASK;
}

void AFramework::ARTCC::lock(){
    /*  riaccendo l'orologio                                                    */
    m_reg->RTCCON.SET = _RTCCON_ON_MASK;
    /*  blocco la scrittura                                                     */
    m_reg->RTCCON.CLR = _RTCCON_RTCWREN_MASK;
    /*  sequenza di blocco                                                      */
    System::lockOscCon();
}
