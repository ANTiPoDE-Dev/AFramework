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

AFramework::AString AFramework::AString::str(const int& val){
	AString		m_res;
	uint32_t	m_dig = howManyDigits(val);
	uint32_t	m_oth = (	val < 0 ? 2		: 1		);
	bool		m_flg = (	val < 0 ? true	: false	);
	int			m_val =	absolute(val);
	/*	alloco il vettore (m_dig = numero cifre; m_oth = terminazione ed even-	*/
	/*	tuale segno meno														*/
	if(m_res.m_str = new char[m_dig + m_oth]){
		/*	se il numero è minore di zero										*/
		if(m_flg){
			/*	metto il segno meno davanti										*/
			m_res.m_str[0] = '-';
		}
		/*	aggiungo il carattere di terminazione								*/
		m_res.m_str[m_dig + m_oth - 1] = '\0';
		/*	inizio la creazione della stringa									*/
		for(uint32_t i = 0; i < m_dig; i++){
			/*	assegno l'ultima cifra											*/
			m_res.m_str[m_dig + m_oth - 2 - i] = digitToChar(m_val % 10);
			/*	e divido per 10													*/
			m_val /= 10;
		/*	altrimenti															*/
		}
	}
	/*	e ritorno la stringa													*/
	return m_res;
}

AFramework::AString AFramework::AString::str(const float& val, const uint32_t& prec){
	AString		m_res;
	int			m_int = static_cast<int>(absolute(val));
	int			m_dec = power(10, prec) * (static_cast<float>(m_int) - absolute(val));
	uint32_t	m_oth = (val < 0 ? 2	: 1		);
	uint32_t	m_dig = howManyDigits(m_int);
	bool		m_flg = (val < 0 ? true : false	);
	/*	alloco il vettore (m_dig = numero cifre parte intera, m_oth = termina-	*/
	/*	zione ed eventuale segno meno,	prec = parte decimale, 1 per il punto	*/
	if(m_res.m_str = new char[m_dig + m_oth + prec + 1]){
		/*	se il numero è minore di zero										*/
		if(m_flg){
			/*	metto il segno meno davanti										*/
			m_res.m_str[0] = '-';
		}
		/*	aggiungo il carattere di terminazione								*/
		m_res.m_str[m_dig + m_oth + prec] = '\0';
		/*	copio la parte decimale												*/
		for(uint32_t i = 0; i < prec; i++){
			/*	assegno la cifra meno significativa								*/
			m_res.m_str[m_dig + m_oth + prec - 1 - i] = digitToChar(m_dec % 10);
			/*	e divido per 10													*/
			m_dec /= 10;
		}
		/*	aggiungo il punto													*/
		m_res.m_str[m_dig + m_oth - 2] = '.';
		/*	copio la parte intera												*/
		for(uint32_t i = 0; i < ; i++){
			/*	assegno la cifra meno significativa								*/
			m_res.m_str[m_dig + m_oth - 2 - i] = digitToChar(m_int % 10);
			/*	e divido per 10													*/
			m_int /= 10;
		}
	}
	return m_res;
}

AFramework::AString AFramework::AString::str(const double& val, const uint32_t& prec){
	AString s;
	
	return s;
}

char AFramework::AString::digitToChar(const int& val){
	/*	se il numero passato è minore di zero o di più cifre					*/
	if(val < 0x00 || val > 0x09){
		/*	ritorno il carattere di terminazione								*/
		return '\0';
	}
	/*	altrimenti sommo l'offset per la conversione e lo ritorno come char		*/
	return static_cast<char>(val + 0x30);
}

AFramework::AString::AString() : m_str(NULL) {

}

AFramework::AString::AString(const AString& str) : AString(){
	
	if(m_str = new char[str.size()]){
		
	}
}

AFramework::AString::~AString(){
	
	delete [] m_str;
}

uint32_t AFramework::AString::size() const{
	uint32_t		m_res = 0;
	char		*	m_chr = m_str;
	/*	fino a che il carattere puntato è diverso da quello di terminazione		*/
	while(*m_chr != '\0'){
		/*	incremento il contatore												*/
		m_res++;
		/*	sposto avanti il puntatore											*/
		m_chr++;
	}
	/*	ritorno il risultato													*/
	return m_res;
}