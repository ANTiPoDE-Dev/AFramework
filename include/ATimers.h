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
    
    class AAbstract16bitTimer{
        public:
            class aTMRx_w;            
            
            AAbstract16bitTimer(volatile aTMRx_w * w);
            double setSynchronousInternal16(const double baseTime, const bool idleStop = false) volatile;
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
            volatile aTMRx_w * m_treg;
            volatile double    m_base;
            volatile double    m_terr;
    };
    
    class ATimer1 : public AAbstract16bitTimer{
        public:
            ATimer1(volatile aTMRx_w * w);
            double setSynchronousExternal16(const double extFreq, const double baseTime, const bool idleStop = false) volatile;
            double setAsynchronousExternal16(const double baseTime, const bool idleStop = false) volatile;
            double setGated16(const double baseTime, bool idleStop = false) volatile;
        private:
            double setpar(const double t, const double f, const bool w = false) volatile;
    };
    
    class AAbstract32bitTimer : public AAbstract16bitTimer{
        public:
            AAbstract32bitTimer(volatile aTMRx_w * w);
            bool isAttached() const volatile;
            double setSynchronousInternal32(const double baseTime, const bool idleStop = false) volatile;
            virtual bool isMaster() const volatile = 0;
        protected:
            double setpar(const double t, const double f, const bool w = false) volatile;
            volatile bool m_flag;
            
    };

    class ATimer2 : public AAbstract32bitTimer{
        public:
            ATimer2(volatile aTMRx_w * w);
            uint32 pid() const volatile;
            bool isMaster() const volatile;
            double setSynchronousExternal16(const RPGroup1 gpio, const double extFreq, const double baseTime, const bool idleStop = false) volatile;
            double setSynchronousExternal32(const RPGroup1 gpio, const double baseTime, const bool idleStop = false) volatile;
            double setGated16(const RPGroup1 gpio, const double baseTime, bool idleStop = false);
            double setGated32(const RPGroup1 gpio, const double baseTime, bool idleStop = false);
    };
    
      extern volatile ATimer1 Timer1;
//    extern volatile ATimer2 Timer2;
//    extern volatile ATimer3 Timer3;
//    extern volatile ATimer4 Timer4;
//    extern volatile ATimer5 Timer5;

}
#endif	/* ATIMERS_H */

