#ifndef ACORE_H
#define ACORE_H

#include "ACommons.h"

#include <cstdlib>
#include <cstdint>

namespace AFramework{
	
	enum AError{
		NoError,
		SystemNotReady,
		SystemDoubleStart,
		HeapFailure,
		BadPointer,
		MemoryIsFull
	};
	
	class System{
		
		public:
								static	bool		init			(		size_t			heapSize				);
			template <class T>	static	bool		canCreate		(const	uint32_t	&	objNumber = 1			);
//			template <class T>	static	T		*	createObject	(const	uint32_t	&	objNumber = 1			);
//								static	bool		removeObject	(		void		*	address					);
								static	size_t		availableMemory	(												);
								static	size_t		heapSize		(												);
								static	void	*	malloc			(const	size_t		&	size					);
								static	bool		free			(		void		**	address					);
								static	AError		lastError		(												);	//da includere in doc
		private:
								static	void		disableScheduler(												);
								static	void		enableScheduler	(												);
								static	bool		enoughSpaceFor	(const	size_t		&	size					);
								static	void		setError		(const	AError		&	error = AError::NoError	);	//da includere in doc
								
								class	Segment;
			
								static	Segment	*	m_heap_head;
								static	size_t		m_heap_size;
								static	size_t		m_xc32_offs;
								static	bool		m_init_flag;
								static	AError		m_last_fail;
	};
	

/*
	template <class T> T * System::createObject(const uint32_t & objNumber){
		
		return static_cast<T *>(malloc(objNumber * sizeof(T)));
	}
*/		
	template <class T> bool System::canCreate(const __uint32_t & objNumber){
		
		return enoughSpaceFor(objNumber * sizeof(T));
	}
}

#endif	//	ACORE_H
