#ifndef ACOMMONS_H
#define ACOMMONS_H

/*
 *
 */
namespace AFramework{
	/*	Enum per la politica di gestione dei duplicati nelle collezioni			*/
	typedef enum CollectionPolicy{
		/*	Consente elementi duplicati nelle collezioni						*/
		AllowDuplicates,
		/*	Non consente elementi duplicati nelle collezioni					*/
		NotAllowDuplicates
	}CollectionPolicy;
}

#endif	//	ACOMMONS_H