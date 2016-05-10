#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"

using namespace AFramework;


int main(){
    
    System::init(16392);
    
    PortA.write(0x00010001);
    
    while(1){
    
    }
    
    return 0;
}