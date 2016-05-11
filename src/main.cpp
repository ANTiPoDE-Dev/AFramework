#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"

using namespace AFramework;


int main(){
    
    System::init(16392);
    
    PortA.setDigital(A0 | A1);
    PortA.setOutput(A0 | A1);
    
    bool p = PortA.write(A0 | A1, Hi);
    
    p = false;
    
    while(1){
    
    }
    
    
    
    return 0;
}