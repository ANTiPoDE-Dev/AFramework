/*******************************************************************************
 *	@author:	Milazzo Giuseppe
 *				Università KORE Enna
 *	@e-mail:	milazzo.ga@gmail.com
 *				info@antipode-dev.org
 *******************************************************************************
 *	Software Licence:
 *******************************************************************************
 * 
 *	This file is part of AFramework.
 * 
 *	AFramework is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 * 
 *	AFramework is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with AFramework.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *	Copyright 2015, 2016 Milazzo Giuseppe 
 * 
*/

#include <xc.h>
#include "ADevice.h"

void AFramework::ADevice::ppsUnlock(){
	/*	Vedi PIC32 FRM Sect. 6 - 6.3.1.2.1 Enabling the SOSC (pag. 16)			*/
	SYSKEY				= 0x00000000;
	SYSKEY				= 0xAA996655;
	SYSKEY				= 0x556699AA;
	/*	Vedi PIC32 FRM Sect. 12 - 12.3.1.6.1 Control Register Lock (pag. 11)	*/
	CFGCONbits.IOLOCK	= 1;
}

void AFramework::ADevice::ppsRelock(){
	/*	Vedi PIC32 FRM Sect. 12 - 12.3.1.6.1 Control Register Lock (pag. 11)	*/
	CFGCONbits.IOLOCK	= 1;
	/*	Vedi PIC32 FRM Sect. 6 - 6.3.1.2.1 Enabling the SOSC (pag. 16)			*/
	SYSKEY = 0x00000000;
}
