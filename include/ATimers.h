/* 
 * File:   ATimers.h
 * Author: Giuseppe
 *
 * Created on 7 maggio 2016, 19.10
 */

#ifndef ATIMERS_H
#define	ATIMERS_H

#include "ACore.h"

namespace AFramework{
    
    class AAbstractTimer{
        friend class System;
        public:
            ATimer();
            void open() A_COHERENT;
            bool isOpen() A_CONST_COHERENT;
            void close() A_COHERENT;
            uint32 read() A_CONST_COHERENT;
            uint32 msRead() A_CONST_COHERENT;
            
        
    };
    
    class AUniqueTimer : public AAbstractTimer{
        
    };
    
    class ACascadedTimer : public AAbstractTimer{
        
    };
    
    class ADelay{
        public:
            ADelay(AAbstractTimer * source);
            bool sleep(uint32 ms);
    };
    
}


#endif	/* ATIMERS_H */

