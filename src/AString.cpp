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

#include "AString.h"

/*	funzioni di utilità, non le metto neanche private... Se includo cmath		*/
/*	occupo troppa memoria!														*/
uint32_t		howManyDigits	(		int			val);
uint32_t		strLength		(const	char	*	val);
int				absolute		(const	int		&	val);
float			absolute		(const	float	&	val);
double			absolute		(const	double	&	val);
char			digitToChar		(const	int		&	val);
char		*	numericToASCII	(const	int		&	val);
char		*	numericToASCII	(const	float	&	val, const uint32_t & prec);
char		*	numericToASCII	(const	double	&	val, const uint32_t & prec);


/* vettore per le potenze di 10													*/
uint32_t	m_pow[] = {	0x00000000, 
						0x0000000A, 
						0x00000064, 
						0x000003E8, 
						0x00002710, 
						0x000186A0, 
						0x000F4240	};

AFramework::AString AFramework::AString::str(const int& val){
	AString		m_res;
	/*	nulla da commentare														*/
	m_res.m_str = numericToASCII(val);
	return m_res;
}

AFramework::AString AFramework::AString::str(const float& val, const uint32_t& prec){
	AString		m_res;
	/*	nulla da commentare														*/
	m_res.m_str = numericToASCII(val, prec);
	return m_res;
}

AFramework::AString AFramework::AString::str(const double& val, const uint32_t& prec){
	AString		m_res;
	/*	nulla da commentare														*/
	m_res.m_str = numericToASCII(val, prec);
	return m_res;
}

AFramework::AString::AString() : m_str(NULL) {
	/*	Nulla da commentare														*/
}

AFramework::AString::AString(const AString& str) : AString(str.m_str){
	/*	nulla da commentare														*/
}

AFramework::AString::AString(const char * str) : AString(){
	uint32_t m_dim = 1 + strLength(str);
	/*	se la stringa non è vuota e riesco ad allocare							*/
	if(m_dim && (m_str = new char[m_dim])){
		/*	scorro tutta la stringa												*/
		for(uint32_t i = 0; i < m_dim; i++){
			/*	e copio ogni elemento											*/
			m_str[i] = str[i];
		}
	}
}

AFramework::AString::AString(const int & val) : AString(){
	/*	Nulla da commentare														*/
	m_str = numericToASCII(val);	
}

AFramework::AString::AString(const float & val, const uint32_t & prec) : AString(){
	/*	Nulla da commentare														*/
	m_str = numericToASCII(val, prec);	
}

AFramework::AString::AString(const double & val, const uint32_t & prec) : AString(){
	/*	Nulla da commentare														*/
	m_str = numericToASCII(val, prec);		
}

AFramework::AString::~AString(){
	/*	nulla da commentare														*/
	delete [] m_str;
}

void AFramework::AString::toLower(){
	char *	m_tmp = m_str;
	/*	se la stringa non è vuota												*/
	if(m_tmp){
		/*	fino a che non trovo il carattere di terminazione					*/
		while(*m_tmp != '\0'){
			/*	se il carattere puntato è compreso tra A e Z					*/
			if(*m_tmp >= 0x41 && *m_tmp <= 0x5A){
				/*	sommo 32 ed ottengo il minuscolo							*/
				*m_tmp += 0x20;
			}
		}
	}
}

void AFramework::AString::toUpper(){
		char *	m_tmp = m_str;
	/*	se la stringa non è vuota												*/
	if(m_tmp){
		/*	fino a che non trovo il carattere di terminazione					*/
		while(*m_tmp != '\0'){
			/*	se il carattere puntato è compreso tra a e z					*/
			if(*m_tmp >= 0x61 && *m_tmp <= 0x7A){
				/*	sottraggo 32 ed ottengo il minuscolo						*/
				*m_tmp -= 0x20;
			}
		}
	}
}

void AFramework::AString::reverse() {
	char		m_temp = '\0';
	uint32_t	m_size = size();
	/*	scorro la stringa fino a metà (se la stringa è vuota non succede nulla)	*/
	for(uint32_t i = 0; i < m_size / 2; i++){
		/*	copio temporaneamente l'ultimo i-esimo elemento						*/
		m_temp = m_str[m_size - i];
		/*	sostituisco l'ultimo i-esimo con l'i-esimo							*/
		m_str[m_size - i] = m_str[i];
		/*	sostituisco l'i-esimo con la copia dell'ultimo i-esimo				*/
		m_str[i] = m_temp;
	}
}

uint32_t AFramework::AString::size() const{
	/*	nulla da commentare														*/
	return strLength(m_str);
}

bool AFramework::AString::isEmpty() const{
	/*	nulla da commentare														*/
	return (m_str == NULL);
}

AFramework::AString * AFramework::AString::clone() const{
	AString		*	m_new = NULL;
	uint32_t		m_dim = 1 + size();
		/*	controllo di poter allocare una nuova stringa						*/
		if(m_new = new AString()){
			/*	se la stringa non è vuota										*/
			if(m_str){
				/*	controllo di avere memoria									*/
				if(m_new->m_str = new char[m_dim]){
					/*	effettuo la copia										*/
					for(uint32_t i = 0; i < m_dim; i++){
						m_new->m_str[i] = m_str[i];
					}
				}else{
					/*	Altrimenti faccio rollback e cancello la nuova stringa	*/
					delete m_new;
					/*	e metto a NULL											*/
					m_new = NULL;
				}
			}
		}
		/*	ritorno il puntatore alla stringa									*/
		return m_new;
}

bool AFramework::AString::clear(){
	/*	nulla da commentare														*/
	if(!m_str){
		return false;
	}
	delete [] m_str;
	return true;
}

char AFramework::AString::at(const uint32_t& index) const{
	/*	se la stringa è vuota oppure sono andato fuori range					*/
	if(!m_str || index > size()){
		/*	ritorno il carattere di terminazione								*/
		return '\0';
	}
	/*	altrimenti l'indice corrispondete										*/
	return m_str[index];
}












uint32_t howManyDigits(int val){
	uint32_t res = 0;
	/*	fino a che il numero è diverso da zero									*/
	while(val){
		/*	divido per 10														*/
		val /= 10;
		/*	incremento il numero di cifre										*/
		res++;
	}
	/*	ritorno il risultato													*/
	return (res ? res : 1);
}

uint32_t strLength (const char * val){
	uint32_t		m_res = 0;
	/*	se la stringa è vuota													*/
	if(!val){
		/*	fino a che il carattere puntato è diverso da quello di terminazione	*/
		while(*val != '\0'){
			/*	incremento il contatore											*/
			m_res++;
			/*	sposto avanti il puntatore										*/
			val++;
		}		
	}
	/*	ritorno il risultato													*/
	return m_res;
}

int absolute(const int &val){
	/*	nulla da commentare														*/
	return (val < 0 ? -1 * val : val);
}

float absolute(const float &val){
	/*	nulla da commentare														*/
	return (val < 0 ? -1 * val : val);
}

double absolute(const double &val){
	/*	nulla da commentare														*/
	return (val < 0 ? -1 * val : val);
}

int power(const int &val, int exp){
	int res = 1;
	/*	se l'esponente è maggiore di zero										*/
	if(exp > 0){
		/*	se l'esponente è maggiore di 6 lo riscalo (pena overflow)			*/
		exp = (exp > 6 ? 6 : exp);
		/*	assegno il risultato												*/
		res = val;
		/*	decremento l'esponente												*/
		while(--exp){
			/*	e moltiplico volta per volta									*/
			res *= val;
		}
	}
	return res;
}

char digitToChar(const int & val){
	/*	se il numero passato è minore di zero o di più cifre					*/
	if(val < 0x00 || val > 0x09){
		/*	ritorno il carattere di terminazione								*/
		return '\0';
	}
	/*	altrimenti sommo l'offset per la conversione e lo ritorno come char		*/
	return static_cast<char>(val + 0x30);
}

char * numericToASCII(const	int & val){
	char		*	m_res = NULL;
	uint32_t		m_dig = howManyDigits(val);
	uint32_t		m_oth = (	val < 0 ? 2		: 1		);
	bool			m_flg = (	val < 0 ? true	: false	);
	int				m_val =	absolute(val);
	/*	alloco il vettore (m_dig = numero cifre; m_oth = terminazione ed even-	*/
	/*	tuale segno meno														*/
	if(m_res = new char[m_dig + m_oth]){
		/*	se il numero è minore di zero										*/
		if(m_flg){
			/*	metto il segno meno davanti										*/
			m_res[0] = '-';
		}
		/*	aggiungo il carattere di terminazione								*/
		m_res[m_dig + m_oth - 1] = '\0';
		/*	inizio la creazione della stringa									*/
		for(uint32_t i = 0; i < m_dig; i++){
			/*	assegno l'ultima cifra											*/
			m_res[m_dig + m_oth - 2 - i] = digitToChar(m_val % 10);
			/*	e divido per 10													*/
			m_val /= 10;
		/*	altrimenti															*/
		}
	}
	/*	e ritorno la stringa */
	return m_res;
}

char * numericToASCII(const	float & val, const uint32_t & prec){
	char		*	m_res = NULL;
	uint32_t		m_prc = (prec > 5 ? 6 : prec);
	int				m_int = static_cast<int>(absolute(val));
	int				m_dec = (absolute(val) - static_cast<float>(m_int)) * m_pow[m_prc];
	uint32_t		m_dig = howManyDigits(m_int);
	uint32_t		m_oth = (val < 0 ? 2	: 1		);
	bool			m_flg = (val < 0 ? true : false	);
	/*	se la precisione richiesta è diversa da 0								*/
	if(prec){
		/*	aggiungo 1 per il punto												*/
		m_oth++;
	}
	/*	alloco il vettore (m_dig = numero cifre parte intera, m_oth = termina-	*/
	/*	zione, punto ed eventuale segno meno, prec = parte decimale.			*/
	if(m_res = new char[m_dig + m_oth + m_prc]){
		/*	se il numero è minore di zero										*/
		if(m_flg){
			/*	metto il segno meno davanti										*/
			m_res[0] = '-';
		}
		/*	aggiungo il carattere di terminazione								*/
		m_res[m_dig + m_oth + m_prc - 1] = '\0';
		/*	copio la parte decimale												*/
		for(uint32_t i = 0; i < m_prc; i++){
			/*	assegno la cifra meno significativa								*/
			m_res[m_dig + m_oth + m_prc - 2 - i] = digitToChar(m_dec % 10);
			/*	e divido per 10													*/
			m_dec /= 10;
		}
		/*	se la precisione richiesta è diversa da zero						*/
		if(m_prc){
			/*	aggiungo il punto												*/
			m_res[m_dig + m_oth - 2] = '.';
		}
		/*	copio la parte intera												*/
		for(uint32_t i = 0; i < m_dig; i++){
			/*	assegno la cifra meno significativa								*/
			m_res[m_dig + m_oth - 3 - i] = digitToChar(m_int % 10);
			/*	e divido per 10													*/
			m_int /= 10;
		}
	}
	return m_res;	
}

char * numericToASCII(const	double & val, const uint32_t & prec){
	char		*	m_res = NULL;
	uint32_t		m_prc = (prec > 5 ? 6 : prec);
	int				m_int = static_cast<int>(absolute(val));
	int				m_dec = (absolute(val) - static_cast<float>(m_int)) * m_pow[m_prc];
	uint32_t		m_dig = howManyDigits(m_int);
	uint32_t		m_oth = (val < 0 ? 2	: 1		);
	bool			m_flg = (val < 0 ? true : false	);
	/*	se la precisione richiesta è diversa da 0								*/
	if(prec){
		/*	aggiungo 1 per il punto												*/
		m_oth++;
	}
	/*	alloco il vettore (m_dig = numero cifre parte intera, m_oth = termina-	*/
	/*	zione, punto ed eventuale segno meno, prec = parte decimale.			*/
	if(m_res = new char[m_dig + m_oth + m_prc]){
		/*	se il numero è minore di zero										*/
		if(m_flg){
			/*	metto il segno meno davanti										*/
			m_res[0] = '-';
		}
		/*	aggiungo il carattere di terminazione								*/
		m_res[m_dig + m_oth + m_prc - 1] = '\0';
		/*	copio la parte decimale												*/
		for(uint32_t i = 0; i < m_prc; i++){
			/*	assegno la cifra meno significativa								*/
			m_res[m_dig + m_oth + m_prc - 2 - i] = digitToChar(m_dec % 10);
			/*	e divido per 10													*/
			m_dec /= 10;
		}
		/*	se la precisione richiesta è diversa da zero						*/
		if(m_prc){
			/*	aggiungo il punto												*/
			m_res[m_dig + m_oth - 2] = '.';
		}
		/*	copio la parte intera												*/
		for(uint32_t i = 0; i < m_dig; i++){
			/*	assegno la cifra meno significativa								*/
			m_res[m_dig + m_oth - 3 - i] = digitToChar(m_int % 10);
			/*	e divido per 10													*/
			m_int /= 10;
		}
	}
	return m_res;
}