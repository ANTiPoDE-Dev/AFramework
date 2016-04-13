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
	size_t busy = 0;
	System::init(16392);
/*
	Derived * d = new Derived();
	
	delete d;
*/		

	int * p = new int;
	
	delete p;
	
	while(1){
		
	}
	return 0;
}