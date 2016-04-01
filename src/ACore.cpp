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
		void		*	data	(								);
		
	private:
		
		Segment		*	m_prev;
		Segment		*	m_next;
		uint32_t		m_busy	: 0x01;
		uint32_t		m_size	: 0x1F;
};

void AFramework::System::Segment::setBusy(){
	
	m_busy = 1;
}

void AFramework::System::Segment::setFree(){
	
	m_busy = 0;
}

void AFramework::System::Segment::linkPrev(Segment* prev){
	
	m_prev = prev;
}

void AFramework::System::Segment::linkNext(Segment* next){
	
	m_next = next;
}

void AFramework::System::Segment::setSize(const size_t& size){
	
	m_size = static_cast<uint32_t>(size);
}

bool AFramework::System::Segment::isBusy() const{
	
	return (m_busy == 1);
}

bool AFramework::System::Segment::isFree() const{
	
	return (m_busy == 0);
}

AFramework::System::Segment * AFramework::System::Segment::prev() const{
	
	return m_prev;
}

AFramework::System::Segment * AFramework::System::Segment::next() const{
	
	return m_next;
}

size_t AFramework::System::Segment::size() const{
	
	return static_cast<size_t>(m_size);
}

void * AFramework::System::Segment::data(){
	
	return reinterpret_cast<void *>(reinterpret_cast<uint32_t>(&m_next) + 2);
}

bool							AFramework::System::m_init_flag(false);
AFramework::System::Segment *	AFramework::System::m_heap_head(NULL);
size_t							AFramework::System::m_heap_size(0);
size_t							AFramework::System::m_xc32_offs(8);

bool AFramework::System::init(size_t heapSize){
	
	return false;
}

bool AFramework::System::removeObject(void* object){
	
	return false;
}

size_t AFramework::System::heapSize(){
	
	return 0;
}

size_t AFramework::System::heapBytesAvailable(){
	
	return 0;
}