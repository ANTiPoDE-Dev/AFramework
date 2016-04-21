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

#include <cstdint>

#include "AContainers.h"

namespace AFramework{

	class AString;
	
	typedef AList<AString> AStringList;
	
	class AString{
		public:
			
			static		AString		str			(const int		& val															);			//
			static		AString		str			(const float	& val	, const uint32_t	& prec = 3							);			//
			static		AString		str			(const double	& val	, const uint32_t	& prec = 3							);			//
									AString		(																				);			//
									AString		(const AString	& str															);			//
									AString		(const char		* str															);			//
			explicit				AString		(const int		& val															);			//
			explicit				AString		(const float	& val	, const uint32_t	& prec = 3							);			//
			explicit				AString		(const double	& val	, const uint32_t	& prec = 3							);			//
									~AString	(																				);			//
						bool		remove		(const AString	& str	, const bool		& cs = false						);
						bool		remove		(const char		* str	, const bool		& cs = false						);
						bool		remove		(const char		& chr															);
						bool		contains	(const AString	& str	, const bool		& cs = false						) const;
						bool		contains	(const char		* str	, const bool		& cs = false						) const;
						bool		contains	(const char		& chr															) const;
						bool		compare		(const AString	& str	, const bool		& cs = false						) const;
						bool		compare		(const char		* chr	, const bool		& cs = false						) const;
						bool		compare		(const char		& chr	, const bool		& cs = false						) const;
						bool		replace		(const AString	& before, const AString		& after	, const bool & cs = false	);
						bool		replace		(const char		* before, const char		* after	, const bool & cs = false	);
						bool		replace		(const char		& before, const char		& after	, const bool & cs = false	);
						bool		insert		(const AString	& str	, const uint32_t	& index								);
						bool		insert		(const AString	& str	, const AString		& after	, const bool & cs = false	);
						bool		insert		(const char		* str	, const uint32_t	& index								);
						bool		insert		(const char		* str	, const char		* after	, const bool & cs = false	);
						bool		insert		(const char		& chr	, const uint32_t	& index								);
						bool		insert		(const char		& chr	, const char		* after	, const bool & cs = false	);
						void		toLower		(																				);			//
						void		toUpper		(																				);			//
						void		reverse		(																				);			//
						uint32_t	size		(																				) const;	//
						bool		isEmpty		(																				) const;	//
						AString	*	clone		(																				) const;	//					
						bool		clear		(																				);			//
						char		at			(const uint32_t & index															) const;	//
						bool		startsWith	(const AString	& str	, const bool		& cs = false						);
						bool		startsWith	(const char		* str	, const bool		& cs = false						);
						bool		startsWith	(const char		& chr	, const bool		& cs = false						);
						bool		endsWith	(const AString	& str	, const bool		& cs = false						);
						bool		endsWith	(const char		* str	, const bool		& cs = false						);
						bool		endsWith	(const char		& chr	, const bool		& cs = false						);
						int			toInt		(																				) const;
						float		toFloat		(const uint32_t	& prec = 3														) const;
						double		toDouble	(const uint32_t & prec = 3														) const;
						char		operator[]	(const uint32_t	& index															) const;
						bool		operator==	(const AString	& str															) const;
						bool		operator==	(const char		* str															) const;
						bool		operator==	(const char		& str															) const;
						bool		operator!=	(const AString	& str															) const;
						bool		operator!=	(const char		* str															) const;
						bool		operator!=	(const char		& str															) const;
						bool		operator+=	(const AString	& str															);
						bool		operator+=	(const char		* str															);
						bool		operator+=	(const char		& chr															);
						bool		operator-=	(const AString	& str															);
						bool		operator-=	(const char		* str															);
						bool		operator-=	(const char		& chr															);
						AString	&	operator+	(const AString	& str															);
						AString	&	operator+	(const char		* str															);
						AString	&	operator+	(const char		& chr															);
						AString	&	operator-	(const AString	& str															);
						AString	&	operator-	(const char		* str															);
						AString	&	operator-	(const char		& chr															);
		private:
			char	*	m_str;
	};
}

#endif	/* ASTRING_H */
