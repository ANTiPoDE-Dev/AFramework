#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"
#include "ATimers.h"
#include "ARegisterDefs.h"

extern volatile AFramework::AADC_w ADC_w __asm__("ADC_w") __attribute__((section("sfrs")));

using namespace AFramework;

int main(){
    
    System::init(16392);

    int i = 0;
    
    for(i = 0; i < 1; i++){
    
    }
    while(1){

    }
    return 0;
}