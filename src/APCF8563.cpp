
#include "APCF8563.h"

#define _PCF8563_R_ADDR                                 0xA3
#define _PCF8563_W_ADDR                                 0xA2

#define _PCF8563_CTRLSTAT1                              0x00
#define _PCF8563_CTRLSTAT2                              0x01
#define _PCF8563_VL_SECONDS                             0x02
#define _PCF8563_MINUTES                                0x03
#define _PCF8563_HOURS                                  0x04
#define _PCF8563_DAYS                                   0x05
#define _PCF8563_WEEKDAYS                               0x06
#define _PCF8563_CENTURY_MONTHS                         0x07
#define _PCF8563_YEARS                                  0x08
#define _PCF8563_MINUTE_ALARM                           0x09
#define _PCF8563_HOUR_ALARM                             0x0A
#define _PCF8563_DAY_ALARM                              0x0B
#define _PCF8563_WEEKDAY_ALARM                          0x0C
#define _PCF8563_CLKOUT_CTRL                            0x0D
#define _PCF8563_TIMER_CONTROL                          0x0E
#define _PCF8563_TIMER                                  0x0F


#define _PCF8563_CTRLSTAT1_TEST1_POSITION               0x07
#define _PCF8563_CTRLSTAT1_TEST1_MASK                   0x80
#define _PCF8563_CTRLSTAT1_TEST1_LENGTH                 0x01

#define _PCF8563_CTRLSTAT1_STOP_POSITION                0x05
#define _PCF8563_CTRLSTAT1_STOP_MASK                    0x20
#define _PCF8563_CTRLSTAT1_STOP_LENGTH                  0x01

#define _PCF8563_CTRLSTAT1_TESTC_POSITION               0x03
#define _PCF8563_CTRLSTAT1_TESTC_MASK                   0x08
#define _PCF8563_CTRLSTAT1_TESTC_LENGTH                 0x01

#define _PCF8563_CTRLSTAT2_TI_TP_POSITION               0x04
#define _PCF8563_CTRLSTAT2_TI_TP_MASK                   0x10
#define _PCF8563_CTRLSTAT2_TI_TP_LENGTH                 0x01

#define _PCF8563_CTRLSTAT2_AF_POSITION                  0x03
#define _PCF8563_CTRLSTAT2_AF_MASK                      0x08
#define _PCF8563_CTRLSTAT2_AF_LENGTH                    0x01

#define _PCF8563_CTRLSTAT2_TF_POSITION                  0x02
#define _PCF8563_CTRLSTAT2_TF_MASK                      0x04
#define _PCF8563_CTRLSTAT2_TF_LENGTH                    0x01

#define _PCF8563_CTRLSTAT2_AIE_POSITION                 0x01
#define _PCF8563_CTRLSTAT2_AIE_MASK                     0x02
#define _PCF8563_CTRLSTAT2_AIE_LENGTH                   0x01

#define _PCF8563_CTRLSTAT2_TIE_POSITION                 0x00
#define _PCF8563_CTRLSTAT2_TIE_MASK                     0x01
#define _PCF8563_CTRLSTAT2_TIE_LENGTH                   0x01

#define _PCF8563_VL_SECONDS_VL_POSITION                 0x07
#define _PCF8563_VL_SECONDS_VL_MASK                     0x80
#define _PCF8563_VL_SECONDS_VL_LENGTH                   0x01

#define _PCF8563_VL_SECONDS_SECONDS_POSITION            0x00
#define _PCF8563_VL_SECONDS_SECONDS_MASK                0x7F
#define _PCF8563_VL_SECONDS_SECONDS_LENGTH              0x07

#define _PCF8563_MINUTES_MINUTES_POSITION               0x00
#define _PCF8563_MINUTES_MINUTES_MASK                   0x7F
#define _PCF8563_MINUTES_MINUTES_LENGTH                 0x07

#define _PCF8563_HOURS_HOURS_POSITION                   0x00
#define _PCF8563_HOURS_HOURS_MASK                       0x3F
#define _PCF8563_HOURS_HOURS_LENGTH                     0x06

#define _PCF8563_DAYS_DAYS_POSITION                     0x00
#define _PCF8563_DAYS_DAYS_MASK                         0x3F
#define _PCF8563_DAYS_DAYS_LENGTH                       0x06

#define _PCF8563_WEEKDAYS_WEEKDAYS_POSITION             0x00
#define _PCF8563_WEEKDAYS_WEEKDAYS_MASK                 0x07
#define _PCF8563_WEEKDAYS_WEEKDAYS_LENGTH               0x03

#define _PCF8563_CENTURY_MONTHS_C_POSITION              0x07
#define _PCF8563_CENTURY_MONTHS_C_MASK                  0x80
#define _PCF8563_CENTURY_MONTHS_C_LENGTH                0x01

#define _PCF8563_CENTURY_MONTHS_MONTHS_POSITION         0x00
#define _PCF8563_CENTURY_MONTHS_MONTHS_MASK             0x1F
#define _PCF8563_CENTURY_MONTHS_MONTHS_LENGTH           0x05

#define _PCF8563_MINUTE_ALARM_AE_M_POSITION             0x07
#define _PCF8563_MINUTE_ALARM_AE_M_MASK                 0x80
#define _PCF8563_MINUTE_ALARM_AE_M_LENGTH               0x01

#define _PCF8563_MINUTE_ALARM_MINUTE_ALARM_POSITION     0x00
#define _PCF8563_MINUTE_ALARM_MINUTE_ALARM_MASK         0x7F
#define _PCF8563_MINUTE_ALARM_MINUTE_ALARM_LENGTH       0x07

#define _PCF8563_HOUR_ALARM_AE_H_POSITION               0x07
#define _PCF8563_HOUR_ALARM_AE_H_MASK                   0x80
#define _PCF8563_HOUR_ALARM_AE_H_LENGTH                 0x01

#define _PCF8563_HOUR_ALARM_HOUR_ALARM_POSITION         0x00
#define _PCF8563_HOUR_ALARM_HOUR_ALARM_MASK             0x3F
#define _PCF8563_HOUR_ALARM_HOUR_ALARM_LENGTH           0x06

#define _PCF8563_DAY_ALARM_AE_D_POSITION                0x07
#define _PCF8563_DAY_ALARM_AE_D_MASK                    0x80
#define _PCF8563_DAY_ALARM_AE_D_LENGTH                  0x01

#define _PCF8563_DAY_ALARM_DAY_ALARM_POSITION           0x00
#define _PCF8563_DAY_ALARM_DAY_ALARM_MASK               0x3F
#define _PCF8563_DAY_ALARM_DAY_ALARM_LENGTH             0x06

#define _PCF8563_WEEKDAY_ALARM_AE_W_POSITION            0x07
#define _PCF8563_WEEKDAY_ALARM_AE_W_MASK                0x80
#define _PCF8563_WEEKDAY_ALARM_AE_W_LENGTH              0x01

#define _PCF8563_WEEKDAY_ALARM_WEEKDAY_ALARM_POSITION   0x00
#define _PCF8563_WEEKDAY_ALARM_WEEKDAY_ALARM_MASK       0x07
#define _PCF8563_WEEKDAY_ALARM_WEEKDAY_ALARM_LENGTH     0x03

#define _PCF8563_CLKOUT_CTRL_FE_POSITION                0x07
#define _PCF8563_CLKOUT_CTRL_FE_MASK                    0x80
#define _PCF8563_CLKOUT_CTRL_FE_LENGTH                  0x01

#define _PCF8563_CLKOUT_CTRL_FD_POSITION                0x00
#define _PCF8563_CLKOUT_CTRL_FD_MASK                    0x03
#define _PCF8563_CLKOUT_CTRL_FD_LENGTH                  0x02

#define _PCF8563_TIMER_CONTROL_TE_POSITION              0x07
#define _PCF8563_TIMER_CONTROL_TE_MASK                  0x80
#define _PCF8563_TIMER_CONTROL_TE_LENGTH                0x01

#define _PCF8563_TIMER_CONTROL_TD_POSITION              0x00
#define _PCF8563_TIMER_CONTROL_TD_MASK                  0x03
#define _PCF8563_TIMER_CONTROL_TD_LENGTH                0x02

#define _PCF8563_TIMER_TIMER_POSITION                   0x00
#define _PCF8563_TIMER_TIMER_MASK                       0xFF
#define _PCF8563_TIMER_TIMER_LENGTH                     0x08


AFramework::APCF8563::APCF8563(volatile AI2CDriver * driver) : m_driver(driver){

    if(!driver->isOpen()){
        driver->open(AI2CDriver::Freq100KHz);
    }
}

AFramework::uint8 AFramework::APCF8563::seconds() const{
    

    return (bcddec(readreg(_PCF8563_VL_SECONDS) & _PCF8563_VL_SECONDS_SECONDS_MASK));
}

AFramework::uint8 AFramework::APCF8563::minutes() const{
        
    return (bcddec(readreg(_PCF8563_MINUTES) & _PCF8563_MINUTES_MINUTES_MASK));
}

AFramework::uint8 AFramework::APCF8563::hours() const{

    return (bcddec(readreg(_PCF8563_HOURS) & _PCF8563_HOURS_HOURS_MASK));
}

AFramework::uint8 AFramework::APCF8563::days() const{
    
    return (bcddec(readreg(_PCF8563_DAYS) & _PCF8563_DAYS_DAYS_MASK));
}

AFramework::uint8 AFramework::APCF8563::weekday() const{
    
    return (bcddec(readreg(_PCF8563_WEEKDAYS) & _PCF8563_WEEKDAYS_WEEKDAYS_MASK));
}

AFramework::uint8 AFramework::APCF8563::month() const{
    
    return (bcddec(readreg(_PCF8563_CENTURY_MONTHS) & _PCF8563_CENTURY_MONTHS_MONTHS_MASK));
}

AFramework::uint8 AFramework::APCF8563::years() const{
    
    return bcddec(readreg(_PCF8563_YEARS));
}

bool AFramework::APCF8563::setTime(ADateTime tm) const{
    
    m_driver->start();
    m_driver->write(_PCF8563_W_ADDR);
    m_driver->write(_PCF8563_VL_SECONDS);
    m_driver->write(decbcd(tm.seconds()) & _PCF8563_VL_SECONDS_SECONDS_MASK);
    m_driver->write(decbcd(tm.minutes()) & _PCF8563_MINUTES_MINUTES_MASK);
    m_driver->write(decbcd(tm.hours()) & _PCF8563_HOURS_HOURS_MASK);
    m_driver->write(decbcd(tm.dayOfMonth()) & _PCF8563_DAYS_DAYS_MASK);
    m_driver->write(decbcd(tm.Weekday()) & _PCF8563_WEEKDAYS_WEEKDAYS_MASK);
    m_driver->write(decbcd(tm.month()) & _PCF8563_CENTURY_MONTHS_MONTHS_MASK);
    m_driver->write(decbcd(tm.year()));
    m_driver->stop();
}

AFramework::ADateTime AFramework::APCF8563::currentTime() const{
    
    ADateTime ctime;
    ctime.setSeconds(seconds());
    ctime.setMinutes(minutes());
    ctime.setHours(hours());
    ctime.setYear(years());
    ctime.setMonth(static_cast<ADateTime::Months>(month()));
    ctime.setDayOfMonth(days());
    ctime.setWeekday(static_cast<ADateTime::Weekdays>(weekday()));
    
    return ctime;
}

AFramework::uint8 AFramework::APCF8563::bcddec(const uint8 val) const{
    
    return ((((val & 0xF0) >> 4) * 10) + (val & 0x0F));
}

AFramework::uint8 AFramework::APCF8563::decbcd(const uint8 val) const{

    return (((val / 10) << 4) | (val % 10));
}

AFramework::uint8 AFramework::APCF8563::readreg(const uint8 reg) const{
    
    uint8 val = 0;
    
    m_driver->start();
    m_driver->write(_PCF8563_W_ADDR);
    m_driver->write(reg);
    m_driver->restart();
    m_driver->write(_PCF8563_R_ADDR);
    
    val = m_driver->read();
    
    m_driver->stop();
    
    return val;
}