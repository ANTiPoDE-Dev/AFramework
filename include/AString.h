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

#ifndef ASTRING_H
#define	ASTRING_H

#include "AContainers.h"

namespace AFramework{

	class AString : public AList<char>{
		public:
			explicit AString(const char * str);
			explicit AString(const char & chr);
			explicit AString(const int & val);
			explicit AString(const float & val, const uint32_t & prec = 3);
			explicit AString(const double & val, const uint32_t & prec = 3);
			~AString();
		private:
			
	};
}

#endif	/* ASTRING_H */
