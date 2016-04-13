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
			
			enum Pin{};
			
			APort(){
			
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

	APort	portA __attribute((address(0xBF886000)));
	APort	portB __attribute((address(0xBF886100)));
	APort	portC __attribute((address(0xBF886200)));
	
}

#endif	//	APORT_A