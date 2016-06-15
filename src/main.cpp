
#include "ASystemConfig.h"
#include "ACore.h"
#include "ALcd.h"
#include "APCF8563.h"
#include "ADateTime.h"

using namespace std;
using namespace AFramework;

int main(){

    System::init(16392, &PortB, bit15);

    APCF8563 clock(&I2C2);
    
    ALcd lcd(&PortC, bit0, &PortC, bit1, &PortC, bit2, &PortC, bit3, &PortC, bit4, &PortC, bit5, &PortC, bit6);
    
    ADateTime tm;
    tm.setYear(16);
    tm.setMonth(ADateTime::Months::June);
    tm.setDayOfMonth(29);
    tm.setWeekday(ADateTime::Weekdays::Wednesday);
    tm.setHours(9);
    tm.setMinutes(0);
    tm.setSeconds(0);
    
    lcd.lightOn();
    
    System::delay(1000);
    
    clock.setTime(tm);
    while(1){
        lcd.clear();

        lcd << clock.currentTime().timeToString() << endl;
        lcd << clock.currentTime().dateToString();
        System::delay(1000);        
    }
    return 0;
}