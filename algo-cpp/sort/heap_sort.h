//
// Created by Valeriy Chevtaev on 07/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#ifndef __heap_sort_H_
#define __heap_sort_H_

#include "sort_common.h"

namespace _7bit {
namespace algorithm {
namespace sort {

    /**
     * Insertion sort implementation
     * @param begin Collection start
     * @param end Collection end
     * @param cmp Comparison functor
     */
    template<typename _Iterator, typename _Comparator>
    sort_result_t heap_sort(_Iterator begin, _Iterator end, _Comparator cmp)
    {
        if (begin == end) return 0;

        // TODO


        return 0;
    }

    /**
     * Insertion sort implementation
     * @param begin Collection start
     * @param end Collection end
     */
    template<typename _Iterator>
    sort_result_t heap_sort(_Iterator begin, _Iterator end)
    {
        return heap_sort(begin, end, default_comparator<typename std::iterator_traits<_Iterator>::value_type>());
    }

} // sort
} // algorithm
} // _7bit

#endif //__heap_sort_H_
