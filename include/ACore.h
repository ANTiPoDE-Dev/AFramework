#ifndef ACORE_H
#define ACORE_H

#include <cstdlib>
#include <cstdint>

/*
 *
 */

namespace AFramework{
	
	class System{
		
		public:
			
			template <class T>	static	bool		canCreate			(const	uint32_t		numbers = 1	);
			template <class T>	static	T		*	createObject		(const	uint32_t		numbers = 1	);
								static	bool		init				(		size_t			heapSize	);
								static	bool		removeObject		(		void		*	object		);
								static	size_t		heapSize			(									);
								static	size_t		heapBytesAvailable	(									);
								
		private:
			
										class		Segment;
										
								static	bool		m_init_flag;
								static	Segment	*	m_heap_head;
								static	size_t		m_heap_size;
								static	size_t		m_xc32_offs;
	};
}

#endif	//	ACORE_H
