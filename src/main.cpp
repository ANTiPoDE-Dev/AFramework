#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"
#include "ATimers.h"
#include "ARegisterDefs.h"

extern volatile AFramework::AADC_w ADC_w __asm__("ADC_w") __attribute__((section("sfrs")));
extern volatile AFramework::AINT_w INT_w __asm__("INT_w") __attribute__((section("sfrs")));

using namespace AFramework;

int main(){
    
    System::init(16392);


    INT_w.IPC[0].set = Quick::All;
    INT_w.IPC[0].clr = Quick::All;
    INT_w.IPC[1].set = Quick::All;
    INT_w.IPC[1].clr = Quick::All;
    INT_w.IPC[10].set = Quick::All;
    INT_w.IPC[10].clr = Quick::All;
    int i = 0;
    
    for(i = 0; i < 1; i++){
    
    }
    while(1){

    }
    return 0;
}