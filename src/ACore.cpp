#include "ACore.h"

class AFramework::System::Segment{
	
	public:
		
		void			setBusy	(								);
		void			setFree	(								);
		void			linkPrev(		Segment * prev = NULL	);
		void			linkNext(		Segment	* next = NULL	);
		void			setSize	(const	size_t	& size			);
		bool			isBusy	(								) const;
		bool			isFree	(								) const;
		Segment		*	prev	(								) const;
		Segment		*	next	(								) const;
		size_t			size	(								) const;
		void		*	data	(								) const;
		
	private:
		
		Segment		*	m_prev;
		Segment		*	m_next;
		uint32_t		m_busy	: 0x01;
		uint32_t		m_size	: 0x1F;
};
