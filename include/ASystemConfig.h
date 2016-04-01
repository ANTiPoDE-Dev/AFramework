#ifndef ASYSTEMCONFIG_H
#define ASYSTEMCONFIG_H


/*
 *	
 */

#include <xc.h>

#ifdef	ANTIPODE32MR

#pragma config PMDL1WAY		= OFF		//Peripheral Module Disable Configuration (Allow multiple reconfigurations)
#pragma config IOL1WAY		= OFF		//Peripheral Pin Select Configuration (Allow multiple reconfigurations)
#pragma config FUSBIDIO		= ON		//USB USID Selection (Controlled by the USB Module)
#pragma config FVBUSONIO	= ON		//USB VBUS ON Selection (Controlled by USB Module)
#pragma config FPLLIDIV		= DIV_6		//PLL Input Divider (6x Divider)					24MHz /  6 =  4MHz
#pragma config FPLLMUL		= MUL_20	//PLL Multiplier (20x Multiplier)					 4MHz * 20 = 80MHz
#pragma config UPLLIDIV		= DIV_6		//USB PLL Input Divider (6x Divider)				24MHz /  6 =  4MHz
#pragma config UPLLEN		= ON		//USB PLL Enable (Enabled)
#pragma config FPLLODIV		= DIV_2		//System PLL Output Clock Divider (PLL Divide by 2)	80MHz /  2 = 40MHz
#pragma config FNOSC		= PRIPLL	//Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
#pragma config FSOSCEN		= OFF		//Secondary Oscillator Enable (Disabled)
#pragma config IESO			= ON		//Internal/External Switch Over (Enabled)
#pragma config POSCMOD		= HS		//Primary Oscillator Configuration (HS osc mode)
#pragma config OSCIOFNC		= OFF		//CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV		= DIV_1		//Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
#pragma config FCKSM		= CSDCMD	//Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS		= PS1048576	//Watchdog Timer Postscaler (1:1048576)
#pragma config WINDIS		= OFF		//Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
#pragma config FWDTEN		= OFF		//Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
#pragma config FWDTWINSZ	= WINSZ_25	//Watchdog Timer Window Size (Window Size is 25%)
#pragma config JTAGEN		= OFF		//JTAG Enable (JTAG Disabled)
#pragma config ICESEL		= ICS_PGx1	//ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config PWP			= OFF		//Program Flash Write Protect (Disable)
#pragma config BWP			= OFF		//Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP			= OFF		//Code Protect (Protection Disabled)

#endif

#endif	//	ASYSTEMCONFIG_H