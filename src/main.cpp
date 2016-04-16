#define ANTIPODE32MR

#include "ASystemConfig.h"
#include "ASerial.h"
#include "ACore.h"
#include "APort.h"
#include "AContainers.h"

#include <cstdlib>

using namespace AFramework;

int main(){
	

	unsigned int a = 0xFFFF;
	
	portA.m_TRIS_SET	= a;
	portA.m_ANSEL_CLR	= a;
	portA.m_LAT_CLR		= a;
	portA.m_ODC_CLR		= a;
	
	TRISB	= 0xEFAF;	//1110 1111 1010 1111
	ANSELB	= 0x0000;
	LATB	= 0x0000;
	ODCB	= 0x0000;
	
	TRISC	= 0x0000;	//0000 0001 1111 1110
	ANSELC	= 0x0000;
	LATC	= 0x0000;
	ODCC	= 0x0000;
	
	
	System::init(16392);
	
	return 0;
}