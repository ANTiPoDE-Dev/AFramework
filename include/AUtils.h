/* 
 * File:   AUtils.h
 * Author: milaz
 *
 * Created on 19 aprile 2016, 18.17
 */

#ifndef AUTILS_H
#define	AUTILS_H

namespace AFramework{
	
	template <class T> uint32_t howManyDigits(const T & val);
	template <class T> T abs(const T & val);
	template <class T> T pow(const T & val, const int & exp);
	template <class T> T trunc(const T & val, const uint32_t & prec = 3);
	
	template <class T> uint32_t howManyDigits(const T& val){
		T	tmp = abs(val);
	}
	
	template <class T> T abs(const T & val){
		return (val < 0 ? -1 * val : val);
	}
}

#endif	/* AUTILS_H */

