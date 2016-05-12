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
            virtual bool open(const double period) volatile = 0;
            virtual void close() volatile;
            virtual void clear() volatile;
            virtual bool isOpen() const volatile;
            virtual uint32 rawTime() const volatile;
            virtual double elapsedTime() const volatile;
            virtual double period() const volatile;
            virtual double frequency() const volatile;
            virtual uint8 prescaler() const volatile = 0;
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
    
    #ifdef ANTIPODE32MR
    
    class ATimer1 : public AAbstractTimer{
        friend class System;
        public:
            enum Timer1ClockSource{
                System,
                A4
            };
            ATimer1();
            bool open(const double period) volatile;
            bool open(const double period, const Timer1ClockSource src = System, const bool idleStop = false) volatile;
            uint8 prescaler() const volatile;
    };
    
//    class ATimer2 : public AAbstractTimer{
//        friend class System;
//        public:
//            ACascadedTimer();
//            void open() volatile;
//            uint8 prescaler() const volatile;
//    };
//    
//    class ATimer3 : public AAbstractTimer{
//        friend class System;
//        public:
//            ACascadedTimer();
//            void open() volatile;
//            uint8 prescaler() const volatile;
//    };
//    
//    class ATimer4 : public AAbstractTimer{
//        friend class System;
//        public:
//            ACascadedTimer();
//            void open() volatile;
//            uint8 prescaler() const volatile;
//    };
//    
//    class ATimer5 : public AAbstractTimer{
//        friend class System;
//        public:
//            ACascadedTimer();
//            void open() volatile;
//            uint8 prescaler() const volatile;
//    };
    
//    extern volatile ATimer1 Timer1;
//    extern volatile ATimer2 Timer2;
//    extern volatile ATimer3 Timer3;
//    extern volatile ATimer4 Timer4;
//    extern volatile ATimer5 Timer5;
    
    #elif defined PIC32MX270F256B

    #else

        #error UNDEFINED BOARD OR PROCESSOR

    #endif
}
#endif	/* ATIMERS_H */

