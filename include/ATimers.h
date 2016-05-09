///* 
// * File:   ATimers.h
// * Author: Giuseppe
// *
// * Created on 7 maggio 2016, 19.10
// */
//
//#ifndef ATIMERS_H
//#define	ATIMERS_H
//
//#include "ACore.h"
//
//namespace AFramework{
//    
//    class AAbstractTimer{
//        friend class System;
//        public:
//            ATimer();
//            virtual void open() A_COHERENT = 0;
//            virtual void close() A_COHERENT = 0;
//            virtual void clear() A_COHERENT = 0;
//            virtual bool isOpen() A_CONST_COHERENT = 0;
//            virtual uint32 read() A_CONST_COHERENT = 0;
//            virtual uint32 msRead() A_CONST_COHERENT = 0;
//            virtual uint32 period() A_CONST_COHERENT = 0;
//            virtual uint32 frequency() A_CONST_COHERENT = 0;
//            
//        protected:
//            A_COHERENT uint32 m_TCON;
//            A_COHERENT uint32 m_TCON_CLR;
//            A_COHERENT uint32 m_TCON_SET;
//            A_COHERENT uint32 m_TCON_INV;
//            A_COHERENT uint32 m_TMR;
//            A_COHERENT uint32 m_TMR_CLR;
//            A_COHERENT uint32 m_TMR_SET;
//            A_COHERENT uint32 m_TMR_INV;
//            A_COHERENT uint32 m_PR;
//            A_COHERENT uint32 m_PR_CLR;
//            A_COHERENT uint32 m_PR_SET;
//            A_COHERENT uint32 m_PR_INV;
//    };
//    
//    class AUniqueTimer : public AAbstractTimer{
//        friend class System;
//        public:
//            AUniqueTimer();
//            void open() A_COHERENT = 0;
//            void close() A_COHERENT = 0;
//            void clear() A_COHERENT = 0;
//            bool isOpen() A_CONST_COHERENT = 0;
//            uint32 read() A_CONST_COHERENT = 0;
//            uint32 msRead() A_CONST_COHERENT = 0;
//            uint8 prescaler() A_CONST_COHERENT = 0;
//    };
//    
//    class ACascadedTimer : public AAbstractTimer{
//        friend class System;
//        public:
//            ACascadedTimer();
//            void open() A_COHERENT = 0;
//            void close() A_COHERENT = 0;
//            void clear() A_COHERENT = 0;
//            bool isOpen() A_CONST_COHERENT = 0;
//            uint32 read() A_CONST_COHERENT = 0;
//            uint32 msRead() A_CONST_COHERENT = 0;
//            uint8 prescaler() A_CONST_COHERENT = 0;
//    };
//    
//    class ADelay{
//        public:
//            ADelay(AAbstractTimer * source);
//            bool sleep(uint32 ms);
//    };
//    
//    extern A_COHERENT AUniqueTimer   Timer1;
//    extern A_COHERENT ACascadedTimer Timer2;
//    extern A_COHERENT ACascadedTimer Timer3;
//    extern A_COHERENT ACascadedTimer Timer4;
//    extern A_COHERENT ACascadedTimer Timer5;
//}
//
//
//#endif	/* ATIMERS_H */
//
