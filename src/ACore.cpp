#include <cstring>

#include "ACore.h"

#include <cstring>

AFramework::System::Segment	*	AFramework::System::m_heap_head(NULL);
size_t							AFramework::System::m_heap_size(0);
size_t							AFramework::System::m_xc32_offs(8);
bool							AFramework::System::m_init_flag(false);

class AFramework::System::Segment{
	
	public:
		
		void			setSize		(const	size_t	& size	);
		void			setFree		(						);
		void			setBusy		(						);
		void			linkPrev	(		Segment * prev	);
		void			linkNext	(		Segment * next	);
		void		*	data		(						);
		Segment		*	prev		(						) const;
		Segment		*	next		(						) const;
		Segment		*	vNext		(						);
		bool			isBusy		(						) const;
		size_t			size		(						) const;
		
	private:
		
		uint32_t		m_flag	: 0x01;
		uint32_t		m_algn	: 0x1F;
		Segment		*	m_prev;
		Segment		*	m_next;
		size_t			m_size;
};

void AFramework::System::Segment::setSize(const size_t & size){
	/*	Nulla da commentare														*/
	m_size = size;
}

void AFramework::System::Segment::setFree(){
	/*	Politica decisa: se m_flag è 0 allora il segmento è libero				*/
	m_flag = 0;
}

void AFramework::System::Segment::setBusy(){
	/*	Politica decisa: se m_flag è 1 allora il segmento è occupato			*/
	m_flag = 1;
}

void AFramework::System::Segment::linkPrev(Segment * prev){
	/*	Nulla da commentare														*/
	m_prev = prev;
}

void AFramework::System::Segment::linkNext(Segment * next){
	/*	Nulla da commentare														*/
	m_next = next;
}

void * AFramework::System::Segment::data(){
	/*	Per evitare di inserire nella classe un altro campo (il puntatore void	*/
	/*	data) ho preferito dare direttamente l'indirizzo calcolandolo in fun-	*/
	/*	zione dell'offset di memoria. Sommando 1 all'indirizzo di m_size che è	*/
	/*	di tipo size_t (4 bytes) mi sposto di 4 bytes in memoria, successiva-	*/
	/*	mente restituisco l'indirizzo come puntatore void di modo che posso		*/
	/*	spostarmi di 1 byte alla volta.											*/
	return (reinterpret_cast<void *>(&m_size + 1));
}

AFramework::System::Segment * AFramework::System::Segment::prev() const{
	/*	Nulla da commentare														*/
	return m_prev;
}

AFramework::System::Segment * AFramework::System::Segment::next() const{
	/*	Nulla da commentare														*/
	return m_next;
}

AFramework::System::Segment * AFramework::System::Segment::vNext(){
	/*	Calcolo l'indirizzo virtuale a cui dovrebbe trovarsi ipoteticamente il	*/
	/*	prossimo blocco: partendo da data() che fornisce la memoria utile allo	*/
	/*	utilizzatore aggiungo un offset di size() bytes.						*/
	return (reinterpret_cast<Segment *>(reinterpret_cast<uint32_t>(data()) + size()));
}

bool AFramework::System::Segment::isBusy() const{
	/*	Nulla da commentare														*/
	return (m_flag == 1);
}

size_t AFramework::System::Segment::size() const{
	/*	Nulla da commentare														*/
	return m_size;
}

/*
 Class AFramework::System Code
 */

bool AFramework::System::init(size_t heapSize){
		
	/*	Controllo che la funzione non sia già stata chiamata					*/
	if(m_init_flag){
		/*	in questo caso restituisco false									*/
		return false;;
	}
	/*	Sottraggo alla dimensione dell'heap passata l'offset del compilatore	*/
	heapSize -= m_xc32_offs;
	/*	Provo ad allocare tutto l'heap alla testa della lista					*/
	m_heap_head = static_cast<Segment *>(::malloc(heapSize));
	/*	Se la testa è NULL allora l'allocazione è fallita						*/
	if(!m_heap_head){
		#warning "bool AFramework::System::init(size_t heapSize) politica sui codici di errore da decidere"
		/*	Ed in questo caso restituisco false									*/
		return false;
	}
	/*	Se l'allocazione è riuscita setto la dimensione dell'heap reale			*/
	m_heap_size = heapSize;
	/*	e azzero la memoria														*/
	memset(m_heap_head, 0x00, heapSize);
	/*	Imposto il blocco come libero											*/
	m_heap_head->setFree();
	/*	Imposto la dimensione del blocco										*/
	m_heap_head->setSize(m_heap_size - sizeof(Segment));
	/*	Imposto il puntatore al blocco precedente a NULL						*/
	m_heap_head->linkPrev(NULL);
	/*	Imposto il puntatore al blocco successivo a NULL						*/
	m_heap_head->linkNext(NULL);
	
	/*
	 PARTE RELATIVA ALLA CODA DEI THREAD <ANCORA DA PROGETTARE>
		...
	 */
	#warning "bool AFramework::System::init(size_t heapSize) coda Thread da progettare"
	
	/*	Imposto il flag di avvenuta inizializzazione							*/
	m_init_flag = true;
	/*	Abilito lo scheduler													*/
	enableScheduler();
	/*	e restituisco true														*/
	return true;
}

bool AFramework::System::free(void * address){
	
	Segment	*	nav = NULL;
	bool		flg = false;
	/*	Controllo che il framework sia stato inizializzato correttamente		*/
	if(!m_init_flag){
		/*	se non è così non esiste ancora l'heap e quindi non c'è nulla da	*/
		/*	liberare per cui restituisco false									*/
		return false;
	}
	/*	se invece tutto è stato inizializzato correttamente, disabilito lo		*/
	/*	scheduler,																*/
	disableScheduler();
	/*	assegno la testa della lista ad un puntatore temporaneo					*/
	nav = m_heap_head;
	/*	e scorro la lista														*/
	while(nav){
		/*	se l'indirizzo passato corrisponde ad un indirizzo di memoria che	*/
		/*	risiede nell'heap (scorro cercando una corrispondenza)				*/
		if(nav->data() == address){
			/*	setto il blocco come libero										*/
			nav->setFree();
			/*	cancello la memoria												*/
			memset(nav->data(), 0x00, nav->size());
			/*	imposto il flag per la deframmentazione a true					*/
			flg = true;
			/*	e smetto di scorrere la lista									*/
			break;
		}
		/*	altrimenti continuo a scorrere										*/
		nav = nav->next();
	}
	/*	se ho trovato corrispondenze devo deframmentare la memoria guardando	*/
	/*	i blocchi precedente e successivo										*/
	if(flg){
		/*	per cui se il precedente blocco non è NULL (questo significa che a	*/
		/*	sinistra c'è qualcosa) ed inoltre non è occupato (funziona sempre	*/
		/*	per lo short-evaluation, ovvero se fallisce la prima condizione		*/
		/*	il secondo confronto non viene eseguito)							*/
		if(nav->prev() && !(nav->prev()->isBusy())){
			/*	sposto il puntatore temporaneo al blocco precedente				*/
			nav = nav->prev();
			/*	ricalcolo la dimensione del blocco								*/
			nav->setSize(nav->size() + sizeof(Segment) + nav->next()->size());
			/*	se il blocco a destra di quello liberato all'inizio non è NULL	*/
			if(nav->next()->next()){
				/*	assegno nav come precedente (elimino il riferimento al		*/
				/*	blocco liberato)											*/
				nav->next()->next()->linkPrev(nav);
			}
			/*	assegno al successivo di nav il successivo del blocco eliminato	*/
			nav->linkNext(nav->next()->next());
			/*	e pulisco la memoria											*/
			memset(nav->data(), 0x00, nav->size());
		}
		/*	sempre per il discorso relativo al primo if sopra adesso devo		*/
		/*	controllare a destra, infatti se questo blocco è non NULL e libero	*/
		/*	devo ricompattare, per cui											*/
		if(nav->next() && !(nav->next()->isBusy())){
			/*	se è così, setto la dimensione di nav calcolando la nuova		*/
			nav->setSize(nav->size() + sizeof(Segment) + nav->next()->size());
			/*	se il prossimo successivo è un blocco valido					*/
			if(nav->next()->next()){
				/*	collego il precedente di questo a nav						*/
				nav->next()->next()->linkPrev(nav);
			}
			/*	ed al successivo di nav assegno il prossimo successivo			*/
			nav->linkNext(nav->next()->next());
			/*	pulisco la memoria azzerandola									*/
			memset(nav->data(), 0x00, nav->size());
		}
	}
	/*	riabilito lo scheduler													*/
	enableScheduler();
	/*	e restituisco il valore del flag, infatti se non ho trovato corrispon-	*/
	/*	denze questo sarà false, altrimenti true								*/
	return flg;
}

size_t AFramework::System::availableMemory(){
	
	Segment *	nav = NULL;
	size_t		tmp = 0;
	/*	Controllo che il framework sia stato inizializzato						*/
	if(!m_init_flag){
		/*	se così non è allora non esistendo l'heap restituisco 0				*/
		return 0;
	}
	/*	Se invece è stato inizializzato disabilito lo scheduler					*/
	disableScheduler();
	/*	assegno la testa della lista ad un puntatore temporaneo					*/
	nav = m_heap_head;
	/*	ed inizio a scorrere la lista											*/
	while(nav){
		/*	se il blocco su cui mi trovo è libero								*/
		if(!(nav->isBusy())){
			/*	aggiungo la dimensione al totale								*/
			tmp += nav->size();
		}
		/*	e continuo a scorrere (a prescindere)								*/
		nav = nav->next();
	}
	/*	riabilito lo scheduler													*/
	enableScheduler();
	/*	e restituisco il totale													*/
	return tmp;
}

size_t AFramework::System::heapSize(){
	/*	Nulla da commentare...													*/
	return m_heap_size;
}

void * AFramework::System::malloc(const size_t & size){
	
	Segment *	nav = NULL;
	Segment *	seg = NULL;
	size_t		max = 0;
	bool		flg = false;
	/*	Controllo che l'heap sia stato inizializzato correttamente				*/
	if(!m_init_flag){
		/*se così non è restituisco NULL (non ho dove allocare!)				*/
		return NULL;
	}
	/*	Se invece è tutto ok disabilito lo scheduler							*/
	disableScheduler();	
	/*	e assgno un puntatore temporaneo alla testa								*/
	nav = m_heap_head;
	/*	ed inizio a scorrere la lista											*/
	while(nav){
		/*	cercando prima un blocco libero di dimensione esatta				*/
		if(nav->size() == size && !(nav->isBusy())){
			/*	se trovo questo blocco lo imposto come occupato					*/
			nav->setBusy();
			/*	riabilito lo scheduler											*/
			enableScheduler();
			/*	e restituisco il puntatore ai dati								*/
			return nav->data();
		}
		/*	altrimenti continuo a scorrere fino a che non finisco la lista		*/
		nav = nav->next();
	}
	/*	Nel caso in cui non dovesse esistere un blocco di dimensione esatta		*/
	/*	riassegno in puntatore temporaneo alla testa							*/
	nav = m_heap_head;
	/*	e inizio nuovamente a scorrere											*/
	while(nav){
		/*	Cercando il più grande tra i blocchi liberi con dimensione maggiore	*/
		/*	di quella richiesta (in questo modo riduco gli sprechi)				*/
		if(nav->size() > size && !(nav->isBusy()) && nav->size() > max){
			/*	Se trovo questo blocco, imposto un flag a true					*/
			flg = true;
			/*	aggiorno la dimensione del blocco massimo						*/
			max = nav->size();
			/*	salvo in un puntatore temporaneo l'indirizzo di detto blocco	*/
			seg = nav;
		}
		/*	e continuo a scorrere la lista										*/
		nav = nav->next();
	}
	/*	A navigazione ultimata, se il blocco richiesto esiste il flag sarà true	*/
	/*	il puntatore temporaneo seg conterrà l'indirizzo del massimo, per cui	*/
	if(flg){
		/*	solo per questione di coerenza di stile lavoro di nuovo con nav		*/
		nav = seg;
		/*	impostandone la dimensione a quella richiesta						*/
		nav->setSize(size);
		/*	impostandolo come occupato											*/
		nav->setBusy();
		/*	successivamente imposto il blocco successivo assegnando l'indirizzo	*/
		/*	calcolato a seg														*/
		seg = nav->vNext();
		/*	imposto il blocco come libero										*/
		seg->setFree();
		/*	imposto il puntatore al blocco precedente con nav (il blocco		*/
		/*	allocato precedentemente)											*/
		seg->linkPrev(nav);
		/*	imposto il puntatore al blocco successivo al successivo di nav		*/
		/*	(questo indirizzo non è stato modificato)							*/
		seg->linkNext(nav->next());
		/*	imposto la dimensione del nuovo blocco								*/
		seg->setSize(max - size - sizeof(Segment));
		/*	imposto il successivo di nav (il blocco allocato) a seg	ricostru-	*/
		/*	endo la lista														*/
		nav->linkNext(seg);
		/*	riabilito lo scheduler												*/
		enableScheduler();
		/*	ed infine restituisco l'indirizzo dei dati							*/
		return nav->data();
	}
	/*	se invece il blocco richiesto non esiste riabilito lo scheduler			*/
	enableScheduler();
	/*	e restituisco NULL														*/
	return NULL;
}

bool AFramework::System::removeObject(void* address){
	/*	solo un modo alternativo di chiamare la funzione free(void *)	*/
	return free(address);
}

void AFramework::System::disableScheduler(){
	#warning "void AFramework::System::disableScheduler() non ancora implementata"
}

void AFramework::System::enableScheduler(){
	#warning "void AFramework::System::enableScheduler() non ancora implementata"
}

bool AFramework::System::enoughSpaceFor(const size_t& size){
	
	Segment	*	nav = NULL;
	/*	controllo che il framework sia stato inizializzato correttamente		*/
	if(!m_init_flag){
		/*	se così non è non ho nulla da controllare e restituisco false		*/
		return false;
	}
	/*	se invece tutto è ok disabilito lo scheduler							*/
	disableScheduler();
	/*	assegno la testa della lista ad un puntatore temporanero				*/
	nav = m_heap_head;
	/*	ed inizio a navigare la lista alla ricerca di un blocco di dimensione	*/
	/*	abbastanza grande (faccio il confronto più lasco per velocizzare)		*/
	while(nav){
		/*	se esiste abbastanza spazio											*/
		if(nav->size() >= size){
			/*	riabilito lo scheduler											*/
			enableScheduler();
			/*	e restituisco true												*/
			return true;
		}
		/*	altrimenti continuo a scorrere										*/
		nav = nav->next();
	}
	/*	se invece il blocco di dimensione richiesta non esiste, riabilito lo	*/
	/*	scheduler																*/
	enableScheduler();
	/*	e restituisco false														*/
	return false;
}