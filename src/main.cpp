#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"

using namespace AFramework;


int main(){
    
    System::init(16392);
    
    bool r1 = PortA.setDigital(A0 | A1);
    bool r2 = PortA.setOutput(A0 | A1);
    
    bool r3 = PortA.write(A0 | A4, Hi);
    bool r4 = PortA.write(A0 | A4, Lo);
    bool r5 = PortA.write(A0 | A4, Hi);
    
    while(1){
    
    }
    
    
    
    return 0;
}