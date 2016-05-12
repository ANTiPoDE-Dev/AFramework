#include "ASystemConfig.h"
#include "ACore.h"
#include "APorts.h"

using namespace AFramework;


int main(){
    
    System::init(16392);
    
    bool r2 = PortA.setOutput(A0 | A1 | A4);
    
        bool r3 = PortA.write(A0 | A1 | A4, Hi);
        bool r4 = PortA.write(A0 | A1 | A4, Lo);
        bool r5 = PortA.write(A0 | A1 | A4, Hi);    
        bool r6 = PortA.enablePullUp(A7 | A8);
        bool r7 = PortA.enablePullUp(A7 | A8);
    while(1){
        if(PortA.read(A7) == Lo){
            PortA.write(A0, Hi);
        }else{
            PortA.write(A0, Lo);
        }
        if(PortA.read(A8) == Lo){
            PortA.write(A1, Hi);
        }else{
            PortA.write(A1, Lo);
        }
    }
    
    
    
    return 0;
}