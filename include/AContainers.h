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

#include "ACore.h"

namespace AFramework{

	template <class T> class AAbstractList;
	template <class T> class ALinkedList;
	template <class T> class AList;
	
	template <class T> AAbstractList<T> & operator<<(AAbstractList<T> & list, const T & item);
	
	template <class T> class AAbstractList{
		
		public:

											AAbstractList	(														);
			virtual			~				AAbstractList	(														);
			
			virtual	void					indexClear		(														) const = 0;
			virtual uint32_t				removeAll		(const T				& item							)		= 0;
			virtual	bool					contains		(const T				& item							) const = 0;
			virtual	bool					compare			(const AAbstractList<T> & list							) const = 0;
			virtual	bool					replace			(const T				& item, const uint32_t & index	) const = 0;
			virtual	bool					hasNext			(														) const = 0;
			virtual	bool					insert			(const T				& item, const uint32_t & index	)		= 0;
			virtual bool					remove			(const uint32_t			& index							)		= 0;
			virtual bool					clear			(														)		= 0;
			virtual	T						next			(														) const = 0;
			virtual T						at				(const uint32_t			& index							) const = 0;

					bool					isEmpty			(														) const;
					bool					prepend			(const T				& item							);
					bool					append			(const T				& item							);
					uint32_t				size			(														) const;
					
					bool					operator&&		(const T				& item							) const;
					bool					operator==		(const AAbstractList<T> & list							) const;
					bool					operator!=		(const AAbstractList<T> & list							) const;
					T						operator[]		(const uint32_t			& index							) const;
					
		protected:
					uint32_t				m_size;
			mutable	bool					m_flag;
					
		private:
											AAbstractList	(const AAbstractList<T> & list							);
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

	template <class T> bool AAbstractList<T>::operator==(const AAbstractList<T>& list) const{
		/*	Nulla da commentare													*/
		return compare(list);
	}

	template <class T> bool AAbstractList<T>::operator!=(const AAbstractList<T>& list) const{
		/*	Nulla da commentare													*/
		return !compare(list);
	}
	
	template <class T> T	AAbstractList<T>::operator[](const __uint32_t& index) const{
		/*	Nulla da commentare													*/
		return at(index);
	}
	
	template <class T> class AList : public AAbstractList<T>{
		
		public:
									AList();
								~	AList();
										
					void			indexClear	(														) const;
					uint32_t		removeAll	(const T				& item							);
					bool			contains	(const T				& item							) const;
					bool			compare		(const AAbstractList<T> & list							) const;
					bool			replace		(const T				& item, const uint32_t & index	) const;
					bool			hasNext		(														) const;
					bool			insert		(const T				& item, const uint32_t & index	);
					bool			remove		(const uint32_t			& index							);
					AList<T>	*	clone		(														) const;
					bool			clear		(														);
					T				next		(														) const;
					T				at			(const uint32_t			& index							) const;

		private:
									AList(const AList<T> & list);
					T			*	m_list;
			mutable	uint32_t		m_temp;
	};
	
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
		uint32_t		occurences	= 0;
		uint32_t		tempIndex	= 0;
		T			*	newList		= NULL;
		
		/*	come prima cosa controllo le occorrenze								*/
		for(uint32_t i = 0; i < this->m_size; i++){
			if(m_list[i] == item){
				occurences++;
			}
		}
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
	
	template <class T> bool AList<T>::compare(const AAbstractList<T>& list) const{
		/*	se hanno dimensione diversa sono ovviamente diverse					*/
		if(this->m_size != list.size()){
			/*	per cui ritorno false											*/
			return false;
		}
		/*	altrimenti confronto elemento per elemento							*/
		for(uint32_t i = 0; i < this->m_size; i++){
			/*	al primo elemento diverso										*/
			if(m_list[i] != list.at(i)){
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
			/*	e restituisco false												*/
			return true;
		/*	altrimenti se sono nelle interazioni								*/
		}else{
			/*	incremento l'indice												*/
			m_temp++;
		}
		/*	e controllo di non aver sforato la dimensione						*/
		return m_temp < this->m_size;
	}
	
	template <class T> bool AList<T>::insert(const T& item, const uint32_t& index){
		T			*	newLst = NULL;
		uint32_t		tIndex = 0;
		/*	se l'indice passato è più grande della dimensione della lista		*/
		if(index > this->m_size){
			/*	ritorno false													*/
			return false;
		}
		/*	incremento temporaneamente la dimensione, se qualcosa va storto		*/
		/*	la decremento di nuovo												*/
		this->m_size++;
		/*	Controllo che in memoria ci sia spazio sufficiente per allocare un	*/
		/*	nuovo vettore														*/
		if(System::canCreate<T>(this->m_size)){
			/*	alloco il nuovo vettore											*/
			newLst = new T[this->m_size];
			/*	se la lista è vuota												*/
			if(this->m_size == 1){
				m_list		= newLst;
				m_list[0]	= item;
				return true;
			}
			/*	inizio l'inserimento											*/
			for(uint32_t i = 0; i < this->m_size; i++){
				/*	se sono arrivato al punto giusto							*/
				if(i == index){
					/*	inserisco l'elemento									*/
					newLst[i] = item;
				}else{
					/*	altrimenti inserisco l'elemento della vecchia lista		*/
					newLst[i] = m_list[tIndex++];
				}	
			}
			/*	libero la memoria												*/
			delete [] m_list;
			/*	riassegno il puntatore											*/
			m_list = newLst;
			/*	e ritorno true													*/
			return true;
		}
		/*	se non c'è memoria decremento la dimensione							*/
		this->m_size--;
		/*	e ritorno false														*/
		return false;
	}
	
	template <class T> bool AList<T>::remove(const uint32_t& index){
		T			*	newLst = NULL;
		uint32_t		tIndex = 0;
		/*	se l'indice è maggiore o uguale alla dimensione della lista			*/
		if(index >= this->m_size){
			/*	ritorno false													*/
			return false;
		}
		/*	controllo che in memoria ci sia spazio sufficiente per effettuare	*/
		/*	l'operazione														*/
		if(System::canCreate<T>(this->m_size - 1)){
			/*	alloco il nuovo vettore											*/
			newLst = new T[this->m_size - 1];			
			/*	inizio l'inserimento											*/
			for(uint32_t i = 0; i < this->m_size; i++){
				/*	se l'indice corrente è diverso da quello che devo eliminare	*/
				if(i != index){
					/*	effettuo la copia										*/
					newLst[tIndex++] = m_list[i];
				}	
			}
			/*	libero la memoria												*/
			delete [] m_list;
			/*	riassegno il puntatore											*/
			m_list = newLst;
			/*	aggiorno la dimensione											*/
			this->m_size--;
			/*	e ritorno true													*/
			return true;
		}
		/*	se non c'è memoria ritorno false									*/
		return false;
	}
	
	template <class T> AList<T> * AList<T>::clone() const{
		AList<T> * newLst = NULL;
		
		/*	controllo di poter allocare una nuova lista							*/
		if(System::canCreate<AList<T>>()){
			newLst = new AList<T>();
			/*	se la lista è vuota												*/
			if(!this->m_size){
				/*	ho finito per cui ritorno solo la lista allocata			*/
				return newLst;
			}
			/*	se invece non è vuota controllo di avere memoria				*/
			if(System::canCreate<T>(this->m_size - 1)){
				/*	se la memoria c'è alloco il vettore							*/
				newLst->m_list = new T[this->m_size - 1];
				/*	effettuo la copia											*/
				for(uint32_t i = 0; i < this->m_size; i++){
					newLst->m_list[i] = m_list[i];
				}
				/*	setto la dimensione											*/
				newLst->m_size = this->m_size;
				/*	e ritorno la lista											*/
				return newLst;
			}
			/*	Altrimenti faccio rollback e cancello la lista precedentemente	*/
			/*	allocata														*/
			delete newLst;
		}
		/*	se non posso fare nulla ritorno NULL								*/
		return NULL;
	}
	
	template <class T> bool AList<T>::clear(){
		/*	se la lista è già vuota												*/
		if(!this->m_size){
			/*	ritorno false													*/
			return false;
		}
		/*	altrimenti semplicemente, dealloco lo spazio occupato				*/
		delete [] m_list;
		/*	setto la dimensione a zero											*/
		this->m_size = 0;
		/*	e ritorno true														*/
		return true;
	}
	
	template <class T> T AList<T>::next() const{
		/*	nulla da commentare													*/
		return m_list[m_temp];
	}
	
	template <class T> T AList<T>::at(const uint32_t& index) const{
		/*	se la lista è vuota,												*/
		if(!this->m_size){
			/*	per evitare errori strani, ritorno un oggetto al volo			*/
			return T();
		}
		/* se l'indice passato è più grande della dimensione della lista,		*/
		if(index >= this->m_size){
			/*	per evitare errori strani, ritorno l'ultimo elemento			*/
			return m_list[this->m_size - 1];
		}
		/*	altrimenti, se l'utilizzatore non è così idiota, restituisco		*/
		/*	l'oggetto corretto													*/
		return m_list[index];
	}
}

#endif	//	ACONTAINERS_H
