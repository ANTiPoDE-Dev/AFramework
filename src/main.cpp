#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"
#include "ATimers.h"

using namespace AFramework;

int main(){
    
    System::init(16392);

    Timer2.setSynchronousInternal32(1000);
    Timer2.open();
    
    while(1){
        double t = Timer2.elapsedTime();
        double k = t + 1;
    }
    return 0;
}