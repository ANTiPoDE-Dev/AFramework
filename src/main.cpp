#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"
#include "ATimers.h"

using namespace AFramework;

int main(){
    
    System::init(16392);

    Timer1.setSynchronousInternal16(0.001);
    
    while(1){

    }
    return 0;
}