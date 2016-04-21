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

#ifndef ACONTAINERS_H
#define ACONTAINERS_H

#include <cstdint>
#include <cstdlib>

namespace AFramework{

	template <class T> class AAbstractList;
	template <class T> class ALinkedList;
	template <class T> class AList;

	template <class T> AAbstractList<T> & operator<<(AAbstractList<T> & list, const T & item);

	template <class T> class AAbstractList{

		public:

										AAbstractList	(														);
			virtual					~	AAbstractList	(														);
			virtual	void				indexClear		(														) const = 0;
			virtual uint32_t			removeAll		(const T				& item							)		= 0;
			virtual	bool				contains		(const T				& item							) const = 0;
			virtual	bool				replace			(const T				& item, const uint32_t & index	) const = 0;
			virtual	bool				hasNext			(														) const = 0;
			virtual	bool				insert			(const T				& item, const uint32_t & index	)		= 0;
			virtual bool				remove			(const uint32_t			& index							)		= 0;
			virtual bool				clear			(														)		= 0;
			virtual	T					next			(														) const = 0;
			virtual T					at				(const uint32_t			& index							) const = 0;
					bool				isEmpty			(														) const;
					bool				prepend			(const T				& item							);
					bool				append			(const T				& item							);
					uint32_t			size			(														) const;
					bool				operator&&		(const T				& item							) const;
					T					operator[]		(const uint32_t			& index							) const;

		protected:
					uint32_t			m_size;
			mutable	bool				m_flag;

		private:
										AAbstractList	(const AAbstractList<T> & list							);
	};

	template <class T> class AList : public AAbstractList<T>{

		public:
										AList		(														);
									~	AList		(														);
					void				indexClear	(														) const;
					uint32_t			removeAll	(const T				& item							);
					bool				contains	(const T				& item							) const;
					bool				compare		(const AList<T>			& list							) const;
					bool				replace		(const T				& item, const uint32_t & index	) const;
					bool				hasNext		(														) const;
					bool				insert		(const T				& item, const uint32_t & index	);
					bool				remove		(const uint32_t			& index							);
					AList<T>		*	clone		(														) const;
					bool				clear		(														);
					T					next		(														) const;
					T					at			(const uint32_t			& index							) const;
					bool				operator==	(const AList<T>			& list							) const;
					bool				operator!=	(const AList<T>			& list							) const;
		protected:
					T				*	m_list;
			mutable	uint32_t			m_temp;
		private:
										AList		(const AList<T>			& list							);
	};

	template <class T> class ALinkedList : public AAbstractList<T>{

		public:
										ALinkedList	(														);
									~	ALinkedList	(														);
					void				indexClear	(														) const;
					uint32_t			removeAll	(const T				& item							);
					bool				contains	(const T				& item							) const;
					bool				compare		(const ALinkedList<T>	& list							) const;
					bool				replace		(const T				& item, const uint32_t & index	) const;
					bool				hasNext		(														) const;
					bool				insert		(const T				& item, const uint32_t & index	);
					bool				remove		(const uint32_t			& index							);
					ALinkedList<T>	*	clone		(														) const;
					bool				clear		(														);
					T					next		(														) const;
					T					at			(const uint32_t			& index							) const;
					bool				operator==	(const ALinkedList<T>	& list							) const;
					bool				operator!=	(const ALinkedList<T>	& list							) const;

		private:
										template <class K> struct ANode{
											ANode<K>	*	m_prev;
											ANode<K>	*	m_next;
											K				m_item;
										};
										ALinkedList	(const ALinkedList<T>	& list							);
					void				seek		(const uint32_t			& index,	ANode<T>	**	cur	) const;

					ANode<T>		*	m_head;
					ANode<T>		*	m_tail;
			mutable	ANode<T>		*	m_temp;
	};

	template <class T> AAbstractList<T>::AAbstractList() : m_size(0), m_flag(false){
		/*	Nulla da commentare													*/
	}

	template <class T> AAbstractList<T>::AAbstractList(const AAbstractList<T>& list){
		/*	Non fa assolutamente nulla e non può essere chiamato (pena possi-	*/
		/*	bile eccezione e quindi blocco della CPU)							*/
	}

	template <class T> AAbstractList<T>::~AAbstractList(){

	}

	template <class T> bool AAbstractList<T>::isEmpty() const{
		/*	Nulla da commentare													*/
		return m_size == 0;
	}

	template <class T> bool AAbstractList<T>::prepend(const T& item){
		/*	Nulla da commentare													*/
		return insert(item, 0);
	}

	template <class T> bool AAbstractList<T>::append(const T& item){
		/*	Nulla da commentare													*/
		return insert(item, m_size);
	}

	template <class T> uint32_t AAbstractList<T>::size() const{
		/*	Nulla da commentare													*/
		return m_size;
	}

	template <class T> bool AAbstractList<T>::operator&&(const T& item) const{
		/*	Nulla da commentare													*/
		return contains(item);
	}

	template <class T> T	AAbstractList<T>::operator[](const uint32_t& index) const{
		/*	Nulla da commentare													*/
		return at(index);
	}

	template <class T> AList<T>::AList() : AAbstractList<T>(), m_list(NULL), m_temp(0){
		/*	Nulla da commentare													*/
	}

	template <class T> AList<T>::AList(const AList<T>& list){
		/*	Non fa assolutamente nulla e non può essere chiamato (pena possi-	*/
		/*	bile eccezione e quindi blocco della CPU)							*/
	}

	template <class T> AList<T>::~AList(){
		/*	nulla da commentare													*/
		clear();
	}

	template <class T> void AList<T>::indexClear() const{
		/*	resetto il flag per hasNext											*/
		this->m_flag = false;
		/*	e resetto l'indice													*/
		m_temp = 0;
	}

	template <class T> uint32_t AList<T>::removeAll(const T& item){
		uint32_t		m_occ = 0;
		uint32_t		m_ind = 0;
		T			*	m_new = NULL;
		/*	come prima cosa scorro la lista										*/
		for(uint32_t i = 0; i < this->m_size; i++){
			/*	se l'i-esimo elemento è uguale al parametro						*/
			if(m_list[i] == item){
				/*	incremento le occorrenze									*/
				m_occ++;
			}
		}
		/* se il numero di occorrenze non è nullo ed ho abbastanza memoria		*/
		if(m_occ && (m_new = new T[this->m_size - m_occ])){
			/*	scorro il vettore												*/
			for(uint32_t i = 0; i < this->m_size; i++){
				/*	se l'i-esimo elemento è diverso dal parametro				*/
				if(m_list[i] != item){
					/*	lo copio incrementando l'indice							*/
					m_new[m_ind++] = m_list[i];
				}
			}
			/*	libero la memoria occupata dal vecchio vettore					*/
			delete [] m_list;
			/*	riassegno il puntatore											*/
			m_list = m_new;
			/*	aggiorno la dimensione											*/
			this->m_size -= m_occ;
			/*	e restituisco il numero di elementi eliminati					*/
			return m_occ;
		}
		/*	se invece non ho occorrenze o non ho abbastanza memoria in ogni		*/
		/*	caso non ho eliminato nulla per cui ritorno 0						*/
		return 0;
	}

	template <class T> bool AList<T>::contains(const T& item) const{
		/*	Scorro la lista														*/
		for(uint32_t i = 0; i < this->m_size; i++){
			/*	alla prima corrispondenza										*/
			if(m_list[i] == item){
				/*	ritorno true												*/
				return true;
			}
		}
		/*	se non ho trovato corrispondenze ritorno false						*/
		return false;
	}

	template <class T> bool AList<T>::compare(const AList<T>& list) const{
		/*	se hanno dimensione diversa sono ovviamente diverse					*/
		if(this->m_size != list.m_size){
			/*	per cui ritorno false											*/
			return false;
		}
		/*	altrimenti confronto elemento per elemento							*/
		for(uint32_t i = 0; i < this->m_size; i++){
			/*	al primo elemento diverso										*/
			if(m_list[i] != list.m_list[i]){
				/*	restituisco false											*/
				return false;
			}
		}
		/*	se siamo arrivati qui vuol dire che le liste sono identiche			*/
		return true;
	}

	template <class T> bool AList<T>::replace(const T& item, const uint32_t& index) const{
		/*	se l'indice passato è maggiore o uguale alla dimensione della lista	*/
		if(index >= this->m_size){
			/*	restituisco false												*/
			return false;
		}
		/*	altrimenti faccio la sostituzione									*/
		m_list[index] = item;
		/*	e ritorno true														*/
		return true;
	}

	template <class T> bool AList<T>::hasNext() const{
		/*	se sto iniziando un nuovo while										*/
		if(!this->m_flag){
			/*	imposto il falg a true											*/
			this->m_flag = true;
			/*	azzero l'indice temporaneo										*/
			m_temp = 0;
		/*	altrimenti se sono nelle interazioni								*/
		}else{
			/*	incremento l'indice												*/
			m_temp++;
		}
		/*	se ho finito gli elementi											*/
		if(m_temp == this->m_size){
			/*	azzero gli indici												*/
			indexClear();
			/*	e ritorno false													*/
			return false;
		}
		/*	altrimenti controllo di non sforare la dimensione					*/
		return m_temp < this->m_size;
	}

	template <class T> bool AList<T>::insert(const T& item, const uint32_t& index){
		T			*	m_new = NULL;
		uint32_t		m_ind = 0;
		/*	se l'indice passato è più grande della dimensione della lista		*/
		if(index > this->m_size){
			/*	ritorno false													*/
			return false;
		}
		/*	Controllo che in memoria ci sia spazio sufficiente per allocare un	*/
		/*	nuovo vettore														*/
		if((m_new = new T[this->m_size + 1])){
			/*	inizio l'inserimento											*/
			for(uint32_t i = 0; i < this->m_size + 1; i++){
				/*	se sono arrivato al punto giusto							*/
				if(i == index){
					/*	inserisco l'elemento									*/
					m_new[i] = item;
				}else{
					/*	altrimenti inserisco l'elemento della vecchia lista		*/
					m_new[i] = m_list[m_ind++];
				}
			}
			/*	libero la memoria												*/
			delete [] m_list;
			/*	riassegno il puntatore											*/
			m_list = m_new;
			/*	incremento la dimensione										*/
			this->m_size++;
			/*	e ritorno true													*/
			return true;
		}
		/*	e ritorno false														*/
		return false;
	}

	template <class T> bool AList<T>::remove(const uint32_t& index){
		T			*	m_new = NULL;
		uint32_t		m_ind = 0;
		/*	se l'indice è maggiore o uguale alla dimensione della lista			*/
		if(index >= this->m_size){
			/*	ritorno false													*/
			return false;
		}
		/*	controllo che in memoria ci sia spazio sufficiente per effettuare	*/
		/*	l'operazione														*/
		if((m_new = new T[this->m_size - 1])){
			/*	inizio l'inserimento											*/
			for(uint32_t i = 0; i < this->m_size; i++){
				/*	se l'indice corrente è diverso da quello che devo eliminare	*/
				if(i != index){
					/*	effettuo la copia										*/
					m_new[m_ind++] = m_list[i];
				}
			}
			/*	libero la memoria												*/
			delete [] m_list;
			/*	riassegno il puntatore											*/
			m_list = m_new;
			/*	aggiorno la dimensione											*/
			this->m_size--;
			/*	e ritorno true													*/
			return true;
		}
		/*	se non c'è memoria ritorno false									*/
		return false;
	}

	template <class T> AList<T> * AList<T>::clone() const{
		AList<T> * m_new = NULL;
		/*	controllo di poter allocare una nuova lista							*/
		if(m_new = new AList<T>()){
			/*	se la lista non è vuota											*/
			if(this->m_size){
				/*	controllo di avere memoria									*/
				if(m_new->m_list = new T[this->m_size - 1]){
					/*	effettuo la copia										*/
					for(uint32_t i = 0; i < this->m_size; i++){
						m_new->m_list[i] = m_list[i];
					}
					/*	setto la dimensione										*/
					m_new->m_size = this->m_size;
				}else{
					/*	Altrimenti faccio rollback e cancello la nuova lista	*/
					delete m_new;
					/*	e metto a NULL											*/
					m_new = NULL;
				}
			}
		}
		/*	ritorno il puntatore alla lista										*/
		return m_new;
	}

	template <class T> bool AList<T>::clear(){
		/*	se la lista è già vuota												*/
		if(!this->m_size){
			/*	ritorno false													*/
			return false;
		}
		/*	altrimenti semplicemente, dealloco lo spazio occupato				*/
		delete [] m_list;
		/*	metto a NULL														*/
		m_list = NULL;
		/*	setto la dimensione a zero											*/
		this->m_size = 0;
		/*	e ritorno true														*/
		return true;
	}

	template <class T> T AList<T>::next() const{
		/*	nulla da commentare													*/
		return at(m_temp);
	}

	template <class T> T AList<T>::at(const uint32_t& index) const{
		/*	se la lista è vuota,												*/
		if(!this->m_size){
			/*	per evitare errori strani, ritorno un oggetto al volo			*/
			return T();
		}
		/*	nulla da commentare													*/
		return m_list[index >= this->m_size ? this->m_size - 1 : index];
	}

	template <class T> bool AList<T>::operator ==(const AList<T>& list) const{
		/*	nulla da commentare													*/
		return compare(list);
	}

	template <class T> bool AList<T>::operator !=(const AList<T>& list) const{
		/*	nulla da commentare													*/
		return !compare(list);
	}

	template <class T> ALinkedList<T>::ALinkedList() : AAbstractList<T>(), m_head(NULL), m_tail(NULL), m_temp(NULL){
		/*	Nulla da commentare													*/
	}

	template <class T> ALinkedList<T>::ALinkedList(const ALinkedList<T>& list){
		/*	Non fa assolutamente nulla e non può essere chiamato (pena possi-	*/
		/*	bile eccezione e quindi blocco della CPU)							*/
	}

	template <class T> ALinkedList<T>::~ALinkedList(){
		/*	Nulla da commentare													*/
		clear();
	}

	template <class T> void ALinkedList<T>::indexClear() const{
		/*	metto a false il flag												*/
		this->m_flag = false;
		/*	metto a NULL il puntatore											*/
		m_temp = NULL;
	}

	template <class T> uint32_t ALinkedList<T>::removeAll(const T& item){
		uint32_t 	m_occ = 0;
		ANode<T> *	m_nav = NULL;
		ANode<T> *	m_tmp = NULL;
		/*	assegno la testa al puntatore di navigazione						*/
		m_nav = m_head;
		/*	inizio a scorrere													*/
		while(m_nav){
			/*	se l'item coincide												*/
			if(m_nav->m_item == item){
				/*	incremento le occorrenze									*/
				m_occ++;
				/*	punto il nodo da eliminare								*/
				m_tmp = m_nav;
				/*	se sono in testa ed in coda (la lista ha un solo elemento)	*/
				if(!m_tmp->m_prev && !m_tmp->m_next){
					/*	imposto testa e coda a NULL								*/
					m_head = m_tail = NULL;
				/*	altrimenti se sono in testa									*/
				}else if(!m_tmp->m_prev){
					/*	sposto in avanti la testa								*/
					m_head = m_nav->m_next;
					/*	rimuovo la connessione con il precedente				*/
					m_head->m_prev = NULL;
				/*	altrimenti se sono in coda									*/
				}else if(!m_tmp->m_next){
					/*	sposto indietro la coda									*/
					m_tail = m_nav->m_prev;
					/*	rimuovo la connessione con il successivo				*/
					m_tail->m_next = NULL;
				/*	altrimenti per qualsiasi altra posizione					*/
				}else{
					/*	collego il successivo al precedente						*/
					m_nav->m_next->m_prev = m_tmp->m_prev;
					/* collego il precedente al successivo						*/
					m_nav->m_prev->m_next = m_tmp->m_next;
				}
			}
			/*	sposto il puntatore di navigazione avanti						*/
			m_nav = m_nav->m_next;
			/*	libero la memoria												*/
			delete m_tmp;
			/*	assegno m_tmp a NULL (evito double free)						*/
			m_tmp = NULL;
		}
		/*	aggiorno la dimensione												*/
		this->m_size -= m_occ;
		/*	ritorno il numero di elementi eliminati								*/
		return m_occ;
	}

	template <class T> bool ALinkedList<T>::contains(const T& item) const{
		ANode<T> * m_nav = m_head;
		/*	inizio a scorrere la lista											*/
		while(m_nav){
			/*	se trovo una corrispondenza										*/
			if(m_nav->m_item == item){
				/*	ritorno true												*/
				return true;
			}
			/*	sposto il puntatore di navigazione al nodo successivo			*/
			m_nav = m_nav->m_next;
		}
		/*	ritorno false														*/
		return false;
	}

	template <class T> bool ALinkedList<T>::compare(const ALinkedList<T>& list) const{
		ANode<T> * m_navT = NULL;
		ANode<T> * m_navL = NULL;
		/*	se le dimensioni sono diverse										*/
		if(this->m_size != list.m_size){
			/*	le liste sono ovviamente diverse per cui ritorno false			*/
			return false;
		}
		/*	assegno al puntatore di navigazione m_navT la testa di questa lista	*/
		m_navT = m_head;
		/*	assegno al puntatore di navigazione m_navL la testa dell'altra		*/
		m_navL = list.m_head;
		/*	inizio a scorrere													*/
		while(m_navT){
			/*	al primo elemento diverso										*/
			if(m_navT->m_item != m_navL->m_item){
				/*	ritorno false												*/
				return false;
			}
			/*	sposto il puntatore di navigazione di questa lista				*/
			m_navT = m_navT->m_next;
			/*	e dell'altra													*/
			m_navL = m_navL->m_next;
		}
		/*	ritorno true														*/
		return true;
	}

	template <class T> bool ALinkedList<T>::replace(const T& item, const uint32_t& index) const{
		ANode<T> * m_nav = NULL;
		/*	controllo che l'indice sia valido									*/
		if(index >= this->m_size){
			/*	se non è così ritorno false*/
			return false;
		}
		/*	mi posiziono														*/
		seek(index, &m_nav);
		/*	sostituisco l'item													*/
		m_nav->m_item = item;
		/*	e ritorno true														*/
		return true;
	}

	template <class T> bool ALinkedList<T>::hasNext() const{
		/*	se sto iniziando un nuovo while										*/
		if(!this->m_flag){
			/*	resetto il puntatore											*/
			m_temp = m_head;
			/*	e metto a true il flag											*/
			this->m_flag = true;
		/*	altrimenti, se sono già dentro un while								*/
		}else{
			/*	sposto il puntatore												*/
			m_temp = m_temp->m_next;
		}
		/*	se il puntatore è NULL												*/
		if(!m_temp){
			/*	resetto il flag per un nuovo while								*/
			indexClear();
		}
		/*	ritorno il confronto												*/
		return m_temp != NULL;
	}

	template <class T> bool ALinkedList<T>::insert(const T& item, const uint32_t& index){
		ANode<T>	*	m_cur = NULL;
		ANode<T>	*	m_new = NULL;
		/*	controllo che l'indice sia valido									*/
		if(index > this->m_size){
			/*	se non è così ritorno subito false								*/
			return false;
		}
		/*	vedo se riesco a creare un nodo										*/
		if((m_new = new ANode<T>)){
			/*	imposto l'item del nuovo nodo lasciando i puntatori prev e next	*/
			/*	per come mi vengono dati da new (sono già a NULL grazie alla	*/
			/*	chiamata interna a memset)										*/
			m_new->m_item = item;
			/*	se la lista è vuota (solo nel caso in cui index sia zero e con-	*/
			/*	temporaneamente la lista è vuota)								*/
			if(!this->m_size){
				/*	assegno i puntatori ed ho finito							*/
				m_head = m_tail = m_new;
			/*	altrimenti se la lista non è vuota ma l'indice è sempre zero	*/
			/*	(operazione di prepend)											*/
			}else if(!index){
				/*	collego la testa al successivo del nuovo nodo				*/
				m_new->m_next = m_head;
				/*	collego il precedente della testa al nuovo nodo				*/
				m_head->m_prev = m_new;
				/*	sposto indietro la testa									*/
				m_head = m_new;
			/*	altrimenti se la lista non è vuota è l'indice è pari alla di-	*/
			/*	mensione della lista (operazione di append)						*/
			}else if(index == this->m_size){
				/*	collego la coda al precedente del nuovo nodo				*/
				m_new->m_prev = m_tail;
				/*	collego il successivo della coda al nuovo nodo				*/
				m_tail->m_next = m_new;
				/*	sposto in avanti la coda									*/
				m_tail = m_new;
			/*	altrimenti per tutti gli altri indici intermedi					*/
			}else{
				/*	mi posiziono correttamente									*/
				seek(index, &m_cur);
				/*	collego il precedente del nuovo nodo al precedente del nodo	*/
				/*	corrente													*/
				m_new->m_prev = m_cur->m_prev;
				/*	collego il successivo del nuovo nodo al nodo corrente		*/
				m_new->m_next = m_cur;
				/*	collego il successivo del nodo precedente al nodo corrente	*/
				/*	al nuovo nodo												*/
				m_cur->m_prev->m_next = m_new;
				/*	collego il precedente del nodo corrente al nuovo nodo		*/
				m_cur->m_prev = m_new;
			}
			/*	incremento la dimensione										*/
			this->m_size++;
			/*	ritorno true													*/
			return true;
		}
		/*	se non sono riuscito ad allocare ritorno false						*/
		return false;
	}

	template <class T> bool ALinkedList<T>::remove(const uint32_t& index){
		ANode<T>	*	m_cur = NULL;
		/*	controllo che l'indice passato sia un indice valido					*/
		if(index >= this->m_size){
			/*	se così non è ritorno false										*/
			return false;
		}
		/*	se c'è un solo elemento												*/
		if(this->m_size == 1){
			/*	elimino la testa												*/
			delete m_head;
			/*	faccio puntare a NULL la testa									*/
			m_head = NULL;
			/*	e la coda														*/
			m_tail = NULL;
		/*	se devo eliminare la testa											*/
		}else if(!index){
			/*	assegno la testa al nodo corrente								*/
			m_cur = m_head;
			/*	sposto in avanti la testa										*/
			m_head = m_head->m_next;
			/*	metto a NULL il puntatore precedente (unlink)					*/
			m_head->m_prev = NULL;
		/*	se devo eliminare la coda											*/
		}else if(index == this->m_size - 1){
			/*	assegno la coda al nodo corrente								*/
			m_cur = m_tail;
			/*	sposto indietro la coda											*/
			m_tail = m_tail->m_prev;
			/*	metto a NULL il puntatore successivo (unlink)					*/
			m_tail->m_next = NULL;
		/*	se l'indice è intermedio											*/
		}else{
			/*	posiziono i puntatori											*/
			seek(index, &m_cur);
			/*	assegno il puntatore successivo									*/
			m_cur->m_prev->m_next = m_cur->m_next;
			/*	collego il successivo del precedente al successivo				*/
			m_cur->m_next->m_prev = m_cur->m_prev;
		}
		/*	cancello il nodo													*/
		delete m_cur;
		/*	decremento la dimensione											*/
		this->m_size--;
		/*	ritorno true														*/
		return true;
	}

	template <class T> ALinkedList<T> * ALinkedList<T>::clone() const{
		ANode<T>		* m_nav = NULL;
		ALinkedList<T>	* m_lst = NULL;

		/*	provo a creare una nuova lista										*/
		if(m_lst = new ALinkedList<T>()){
			/*	assegno al puntatore di navigazione la testa della lista		*/
			m_nav = m_head;
			/*	inizio a scorrere la lista										*/
			while(m_nav){
				/*	se riesco ad inserire i nodi								*/
				if(m_lst->append(m_nav->m_item)){
					/*	sposto il puntatore di navigazione						*/
					m_nav = m_nav->m_next;
				/*	altrimenti faccio rollback									*/
				}else{
					/*	cancellando gli elementi che fino ad ora sono riuscito	*/
					/*	a clonare												*/
					m_lst->clear();
					/*	liberando la memoria occupata dalla nuova lista			*/
					delete m_lst;
					/*	mettendo il puntatore a NULL							*/
					m_lst = NULL;
					/*	ed ovviamente smetto di scorrere						*/
					break;
				}
			}
		}
		return m_lst;
	}

	template <class T> bool ALinkedList<T>::clear(){
		ANode<T> * m_nav = NULL;
		/*	se la lista è già vuota												*/
		if(!this->m_size){
			/*	ritorno false													*/
			return false;
		}
		/*	altrimenti assegno la testa a m_nav									*/
		m_nav = m_head;
		/*	ed inizio a scorre													*/
		while(m_nav){
			/*	sponstando prima il puntatore alla testa						*/
			m_head = m_head->m_next;
			/*	eliminando ogni nodo											*/
			delete m_nav;
			/*	e spostando in puntatore di navigazione							*/
			m_nav = m_head;
		}
		/*	faccio puntare a NULL la coda										*/
		m_tail = NULL;
		/*	azzero la dimensione												*/
		this->m_size = 0;
		/*	ritorno true														*/
		return true;
	}

	template <class T> T ALinkedList<T>::next() const{
		/*	se m_temp non è NULL												*/
		if(m_temp){
			/*	ritorno l'item corretto											*/
			return m_temp->m_item;
		}
		/*	altrimenti uno vuoto												*/
		return T();
	}

	template <class T> T ALinkedList<T>::at(const uint32_t& index) const{
		ANode<T> * m_cur = NULL;
		/*	se la lista è vuota,												*/
		if(!this->m_size){
			/*	per evitare errori strani, ritorno un oggetto al volo			*/
			return T();
		}
		/*	se l'indice è fuori range lo imposto come l'ultimo e mi posiziono	*/
		seek((index > this->m_size - 1 ? this->m_size - 1 : index), &m_cur );
		/*	ritorno l'elemento												*/
		return m_cur->m_item;
	}

	template <class T> bool ALinkedList<T>::operator ==(const ALinkedList<T>& list) const{
		/*	nulla da commentare													*/
		return compare(list);
	}

	template <class T> bool ALinkedList<T>::operator !=(const ALinkedList<T>& list) const{
		/*	nulla da commentare													*/
		return !compare(list);
	}

	template <class T> void ALinkedList<T>::seek(const uint32_t & index, ANode<T> **cur) const{
		uint32_t	cnt = 0;
		uint32_t	jmp = 0;
		bool		var = false;
		/*	stabilisco se conviene partire dalla testa o dalla coda				*/
		var	= (index <= (this->m_size - 1) / 2);
		/*	se conviene partire dalla testa assegno al puntatore di navigazione	*/
		/*	la testa, altrimenti la coda										*/
		*cur = var ? m_head : m_tail;
		/*	riscalo il numero di salti in base a dove conviene partire			*/
		jmp	= var ? index : this->m_size - 1 - index;
		/*	scorro la lista														*/
		while(cnt < jmp){
			/*	muovendomi o avanti o indietro a seconda di dove sono partito	*/
			*cur = var ? (*cur)->m_next : (*cur)->m_prev;
			/*	ed incrementando volta per volta il contatore					*/
			cnt++;
		}
	}

	template <class T> AAbstractList<T> & operator<<(AAbstractList<T> & list, const T & item){
		/*	accodo l'item														*/
		list.append(item);
		/*	ritorno il riferimento												*/
		return list;
	}
}

#endif	//	ACONTAINERS_H
