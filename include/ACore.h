/*******************************************************************************
*   @author:    Milazzo Giuseppe
*               Università KORE Enna
*   @e-mail:    milazzo.ga@gmail.com
*               info@antipode-dev.org
*******************************************************************************
*   Software Licence:
*******************************************************************************
*
*   This file is part of AFramework.
*
*   AFramework is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   AFramework is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with AFramework. If not, see <http://www.gnu.org/licenses/>.
*
*   Copyright 2015, 2016 Milazzo Giuseppe
*
*/
#ifndef ACORE_H
#define ACORE_H

#include <cstdlib>
#include <cstdint>

namespace AFramework{
    
    class System{
        public:
                                static  bool        init            (       size_t          heapSize                                    );
            template <class T>  static  bool        canCreate       (const  uint32_t    &   objNumber = 1, const bool & autoLock = true );
                                static  size_t      availableMemory (                                                                   );
                                static  size_t      heapSize        (                                                                   );
                                static  void     *  malloc          (       size_t          size                                        );
                                static  bool        free            (       void        *   address                                     );
    private:
                                static  void        disableScheduler(                                                                   );
                                static  void        enableScheduler (                                                                   );
                                static  bool        enoughSpaceFor  (const  size_t      &   size        , const bool & autoLock = true  );
                                class   Segment;
                                static  Segment *   m_heap_head;
                                static  size_t      m_heap_size;
                                static  size_t      m_heap_busy;
                                static  size_t      m_xc32_offs;
                                static  bool        m_init_flag;
    };
    
    template <class T> bool System::canCreate(const uint32_t & objNumber, const bool & autoLock){
        return enoughSpaceFor(objNumber * sizeof(T), autoLock);
    }
}

#endif // ACORE_H
