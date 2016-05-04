#define ANTIPODE32MR
#include "ASystemConfig.h"
#include "ACore.h"
#include "APort.h"
#include "AString.h"

using namespace AFramework;
using namespace std;

int main(){
    unsigned int a = 0xFFFF;
    
    portA.m_TRIS_SET = a;
    portA.m_ANSEL_CLR = a;
    portA.m_LAT_CLR = a;
    portA.m_ODC_CLR = a;
    
    TRISB = 0xEFAF; //1110 1111 1010 1111
    ANSELB = 0x0000;
    LATB = 0x0000;
    ODCB = 0x0000;
    
    TRISC = 0x0000; //0000 0001 1111 1110
    ANSELC = 0x0000;
    LATC = 0x0000;
    ODCC = 0x0000;
    //System::init(16392);
    System::init(520);
    AString s = "a/b/c";
    s.indexOf("/");
    AStringList *t = s.split('/');
    
    while(1){
    
    }
    
    return 0;
}
