#define ANTIPODE32MR

#include "ASystemConfig.h"
#include "ACore.h"

#include <cstdlib>

using namespace AFramework;

int main(){
	
	TRISA	= 0x0793;	//0000 0111 1001 0011
	ANSELA	= 0x0000;
	LATA	= 0x0000;
	ODCA	= 0x0000;
	
	TRISB	= 0xEFAF;	//1110 1111 1010 1111
	ANSELB	= 0x0000;
	LATB	= 0x0000;
	ODCB	= 0x0000;
	
	TRISC	= 0x01FE;	//0000 0001 1111 1110
	ANSELC	= 0x0000;
	LATC	= 0x0000;
	ODCC	= 0x0000;
	
	LATCbits.LATC0 = 1;

	bool x = System::init(16392);
	
	int * a = System::createObject<int>();
	int * b = System::createObject<int>();
	
	*a = 101010;
	*b = 212121;

	while(1){
		
	}
	return 0;
}