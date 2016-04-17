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

#ifndef APORT_A
#define APORT_A

#include <cstdint>

namespace AFramework{

	class APort{
		
		public:
			
			enum Pin{
				
			};
			
			APort(){
				
			}
			
			bool inputMap(uint32_t & map){
				m_TRIS_SET = map;
			}
			bool outputMap(uint32_t & map){
				m_TRIS_CLR = map;
			}
			//	bool		write(const uint32_t & val);
		//		uint32_t	read() const;
	//			bool		pinLevel(const Pin & pin);
				
			
			
		//protected:
			uint32_t	m_ANSEL;
			uint32_t	m_ANSEL_CLR;
			uint32_t	m_ANSEL_SET;
			uint32_t	m_ANSEL_INV;
			uint32_t	m_TRIS;
			uint32_t	m_TRIS_CLR;
			uint32_t	m_TRIS_SET;
			uint32_t	m_TRIS_INV;
			uint32_t	m_PORT;
			uint32_t	m_PORT_CLR;
			uint32_t	m_PORT_SET;
			uint32_t	m_PORT_INV;
			uint32_t	m_LAT;
			uint32_t	m_LAT_CLR;
			uint32_t	m_LAT_SET;
			uint32_t	m_LAT_INV;
			uint32_t	m_ODC;
			uint32_t	m_ODC_CLR;
			uint32_t	m_ODC_SET;
			uint32_t	m_ODC_INV;
			uint32_t	m_CNPU;
			uint32_t	m_CNPU_CLR;
			uint32_t	m_CNPU_SET;
			uint32_t	m_CNPU_INV;
			uint32_t	m_CNPD;
			uint32_t	m_CNPD_CLR;
			uint32_t	m_CNPD_SET;
			uint32_t	m_CNPD_INV;
			uint32_t	m_CNCON;
			uint32_t	m_CNCON_CLR;
			uint32_t	m_CNCON_SET;
			uint32_t	m_CNCON_INV;
			uint32_t	m_CNEN;
			uint32_t	m_CNEN_CLR;
			uint32_t	m_CNEN_SET;
			uint32_t	m_CNEN_INV;
			uint32_t	m_CNSTAT;
			uint32_t	m_CNSTAT_CLR;
			uint32_t	m_CNSTAT_SET;
			uint32_t	m_CNSTAT_INV;
	};

	APort	portA __attribute__((address(0xBF886000)));
	APort	portB __attribute__((address(0xBF886100)));
	APort	portC __attribute__((address(0xBF886200)));
											//FEDCBA98 76543210
	const uint32_t A0	= 0b00000000000000000000000000000001;
	const uint32_t A1	= 0b00000000000000000000000000000010;
	const uint32_t A4	= 0b00000000000000000000000000010000;
	const uint32_t A7	= 0b00000000000000000000000010000000;
	const uint32_t A8	= 0b00000000000000000000000100000000;
	const uint32_t A9	= 0b00000000000000000000001000000000;
	const uint32_t A10	= 0b00000000000000000000010000000000;

											//FEDCBA98 76543210	
	const uint32_t B0	= 0b01000000000000000000000000000001;
	const uint32_t B1	= 0b01000000000000000000000000000010;
	const uint32_t B2	= 0b01000000000000000000000000000100;
	const uint32_t B3	= 0b01000000000000000000000000001000;
	const uint32_t B5	= 0b01000000000000000000000000100000;
	const uint32_t B7	= 0b01000000000000000000000010000000;
	const uint32_t B9	= 0b01000000000000000000001000000000;
	const uint32_t B10	= 0b01000000000000000000010000000000;
	const uint32_t B11	= 0b01000000000000000000100000000000;
	const uint32_t B13	= 0b01000000000000000010000000000000;
	const uint32_t B14	= 0b01000000000000000100000000000000;
	const uint32_t B15	= 0b01000000000000001000000000000000;
											//FEDCBA98 76543210		
	const uint32_t C0	= 0b10000000000000000000000000000001;
	const uint32_t C1	= 0b10000000000000000000000000000010;
	const uint32_t C2	= 0b10000000000000000000000000000100;
	const uint32_t C3	= 0b10000000000000000000000000001000;
	const uint32_t C4	= 0b10000000000000000000000000010000;
	const uint32_t C5	= 0b10000000000000000000000000100000;
	const uint32_t C6	= 0b10000000000000000000000001000000;
	const uint32_t C7	= 0b10000000000000000000000010000000;
	const uint32_t C8	= 0b10000000000000000000000100000000;
	const uint32_t C9	= 0b10000000000000000000001000000000;
}

class AGpio{
	
	public:
	
	private:
		uint32_t m_port : 0x02;
		uint32_t m_ppsO : 0x04;
		uint32_t m_ppsI : 0x04;
		uint32_t m_busy : 0x01;
		uint32_t m_ppsD : 0x01;
		uint32_t m_ppsP : 0x04;
		uint32_t m_gpio : 0x10;
};

#endif	//	APORT_A