#ifndef ACONTAINERS_H
#define ACONTAINERS_H

#include "ACore.h"
#include "ACommons.h"

namespace AFramework{

	/*	Prototipi di classe (servono come forward-declaration					*/
	template <class T> class AAbstractList;
	template <class T> class ALinkedList;
	template <class T> class AList;
	
	template <class T> AAbstractList<T> & operator<<(AAbstractList<T> & list, const T & item);
	
	template <class T> class AAbstractList{
		
		public:
											AAbstractList	(const CollectionPolicy & policy = CollectionPolicy::AllowDuplicates);
											AAbstractList	(const AAbstractList<T> & list										);
			virtual			~				AAbstractList	(																	);
			
			virtual	bool					insert			(const T				& item, const uint32_t & index				) = 0;
			virtual bool					remove			(const uint32_t			& index										) = 0;
			virtual bool					clear			(																	) = 0;
			virtual T						at				(const uint32_t			& index										) = 0;
			
					AList<uint32_t>			find			(const T				& item										);
					bool					removeAll		(const T				& item										);
					bool					contains		(const T				& item										) const;
					bool					isEmpty			(																	) const;
					bool					prepend			(const T				& item										);
					bool					append			(const T				& item										);
					bool					hasNext			(																	) const;
					T						next			(																	) const;
					uint32_t				size			(																	) const;
					
					bool					operator&&		(const T				& item										) const;
					bool					operator+=		(const T				& item										);
					bool					operator-=		(const T				& item										);
					bool					operator==		(const AAbstractList<T> & list										) const;
					bool					operator!=		(const AAbstractList<T> & list										) const;
					T						operator[]		(const uint32_t			& index										) const;
					AAbstractList<T>	&	operator=		(const AAbstractList<T> & list										);
		protected:
			mutable	uint32_t				m_index;
					uint32_t				m_size;
					CollectionPolicy		m_policy;
	};
}

#endif	//	ACONTAINERS_H
