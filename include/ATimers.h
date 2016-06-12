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
    
    class AAbstract16bitTimer{
        public:
            AAbstract16bitTimer(volatile ATMR_w * w);
            void rawConfig(const volatile uint32 b) volatile;
            double setSynchronousInternal16(const volatile double period, const volatile bool idleStop = false) volatile;
            double setSynchronousExternal16(const volatile double extFreq, const volatile double period, const volatile bool idleStop = false) volatile;
            double setGated16(const volatile double period, const volatile bool idleStop = false) volatile;
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
            virtual double setpar(const volatile double t, const volatile double f, const volatile bool w = false) volatile = 0;
            volatile ATMR_w * m_reg;
            volatile double   m_res;
            volatile double   m_err;
    };
    
    class A16bitMasterTimer : public AAbstract16bitTimer{
        public:
            A16bitMasterTimer(volatile ATMR_w * w);
            double setAsynchronousExternal16(const volatile double period, const volatile bool idleStop = false) volatile;
        private:
            double setpar(const volatile double t, const volatile double f, const volatile bool w = false) volatile;
    };
    
    class A16bitSlaveTimer : public AAbstract16bitTimer, public ARemappablePeripheral{
        public:
            A16bitSlaveTimer(volatile ATMR_w * w);
            bool isBusy() const volatile;
        protected:
            double setpar(const volatile double t, const volatile double f, const volatile bool w = false) volatile;
            volatile bool m_flg;
    };
    
    class A32bitMasterTimer : public A16bitSlaveTimer{
        public:
            A32bitMasterTimer(volatile ATMR_w * w, volatile A16bitSlaveTimer * slave);
            double setSynchronousInternal32(const volatile double period, const volatile bool idleStop = false) volatile;
            double setSynchronousExternal32(const volatile double extFreq, const volatile double period, const volatile bool idleStop = false) volatile;
            double setGated32(const volatile double period, const volatile bool idleStop = false) volatile;
        private:
            volatile A16bitSlaveTimer * m_slave;
    };
    
#if (__HAS_TIMER1__)    
    extern volatile A16bitMasterTimer Timer1;
#endif
#if (__HAS_TIMER2__)
    extern volatile A32bitMasterTimer Timer2;
#endif
#if (__HAS_TIMER3__)
    extern volatile A16bitSlaveTimer  Timer3;
#endif
#if (__HAS_TIMER4__)
    extern volatile A32bitMasterTimer Timer4;
#endif
#if (__HAS_TIMER5__)
    extern volatile A16bitSlaveTimer  Timer5;
#endif
}
#endif	/* ATIMERS_H */

