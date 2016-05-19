/* 
 * File:   ATimers.h
 * Author: Giuseppe
 *
 * Created on 7 maggio 2016, 19.10
 */

#ifndef ATIMERS_H
#define	ATIMERS_H

#include "ACore.h"
#include "ARemappablePeripheral.h"

namespace AFramework{
    
    class ATMR_w;
    
    class AAbstract16bitTimer{
        public:
            AAbstract16bitTimer(volatile ATMR_w * w);
            double setSynchronousInternal16(const double baseTime, const bool idleStop = false) volatile;
            double setSynchronousExternal16(const double extFreq, const double baseTime, const bool idleStop = false) volatile;
            double setGated16(const double baseTime, bool idleStop = false);
            bool open() volatile;
            void close() volatile;
            void clear() volatile;
            void reset() volatile;
            bool isOpen() const volatile;
            uint32 rawTime() const volatile;
            double elapsedTime() const volatile;
            double error() const volatile;
            double resolution() const volatile;
        protected:
            virtual double setpar(const double t, const double f, const bool w = false) volatile = 0;
            void rawcfg(const volatile uint32 b) volatile;
            volatile ATMR_w * m_treg;
            volatile double   m_base;
            volatile double   m_terr;
    };
    
    class A16bitTimer : public AAbstract16bitTimer{
        public:
            A16bitTimer(volatile ATMR_w * w);
            double setAsynchronousExternal16(const double baseTime, const bool idleStop = false) volatile;
        private:
            double setpar(const double t, const double f, const bool w = false) volatile;
    };
    
    class A32bitSlaveTimer : public AAbstract16bitTimer, public ARemappablePeripheral{
        public:
            A32bitSlaveTimer(volatile ATMR_w * w);
            virtual bool isMaster() const volatile;
        protected:
            double setpar(const double t, const double f, const bool w = false) volatile;
    };
    
    class A32bitMasterTimer : public A32bitSlaveTimer{
        public:
            A32bitMasterTimer(volatile ATMR_w * w, volatile A32bitSlaveTimer * slave);
            double setSynchronousInternal32(const double baseTime, const bool idleStop = false) volatile;
            double setSynchronousExternal32(const double extFreq, const double baseTime, const bool idleStop = false) volatile;
            double setGated32(const double baseTime, bool idleStop = false) volatile;
            bool isMaster() const volatile;
        private:
            volatile A32bitSlaveTimer * m_slave;
    };
    
#if (__HAS_TIMER1__)
    
    extern volatile A16bitTimer       Timer1;
    
#endif
    
#if (__HAS_TIMER2__)
    
    extern volatile A32bitMasterTimer Timer2;
    
#endif
    
#if (__HAS_TIMER3__)
    
    extern volatile A32bitSlaveTimer  Timer3;
    
#endif
    
#if (__HAS_TIMER4__)
    
    extern volatile A32bitMasterTimer Timer4;
    
#endif
    
#if (__HAS_TIMER5__)
    
    extern volatile A32bitSlaveTimer  Timer5;
    
#endif
    
}
#endif	/* ATIMERS_H */

