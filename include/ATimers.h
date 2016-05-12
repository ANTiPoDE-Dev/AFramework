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
        public:
            AAbstractTimer();
            virtual bool open(const double period, const Priority pri = IntOff, const SubPriority sub = Isp0) volatile;
            virtual void close() volatile;
            virtual void clear() volatile;
            virtual bool isOpen() const volatile;
            virtual uint32 read() const volatile;
            virtual uint32 msRead() const volatile;
            virtual double period() const volatile;
            virtual double frequency() const volatile;
            //virtual uint8 prescaler() const volatile = 0;
        protected:
            volatile uint32 m_TxCON;
            volatile uint32 m_TxCON_CLR;
            volatile uint32 m_TxCON_SET;
            volatile uint32 m_TxCON_INV;
            volatile uint32 m_TMRx;
            volatile uint32 m_TMRx_CLR;
            volatile uint32 m_TMRx_SET;
            volatile uint32 m_TMRx_INV;
            volatile uint32 m_PRx;
            volatile uint32 m_PRx_CLR;
            volatile uint32 m_PRx_SET;
            volatile uint32 m_PRx_INV;
    };
    
    class AUniqueTimer : public AAbstractTimer{
        friend class System;
        public:
            AUniqueTimer();
            void open() volatile = 0;
            uint8 prescaler() const volatile = 0;
    };
    
    class ACascadedTimer : public AAbstractTimer{
        friend class System;
        public:
            ACascadedTimer();
            void open() volatile;
            uint8 prescaler() const volatile;
    };
    
//    extern volatile AUniqueTimer   Timer1;
//    extern volatile ACascadedTimer Timer2;
//    extern volatile ACascadedTimer Timer3;
//    extern volatile ACascadedTimer Timer4;
//    extern volatile ACascadedTimer Timer5;
}


#endif	/* ATIMERS_H */

