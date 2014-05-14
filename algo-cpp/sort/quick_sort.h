//
// Created by Valeriy Chevtaev on 14/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#ifndef __quick_sort_H_
#define __quick_sort_H_

#include "sort_common.h"

namespace _7bit {
namespace algorithm {
namespace sort {

    /**
     * Quick sort implementation
     * @param begin Collection start (inclusive)
     * @param end Collection end (exclusive)
     * @param cmp Comparison functor
     */
    template<typename _Iterator, typename _Comparator>
    _Iterator __quick_sort_partition(_Iterator begin, _Iterator end, _Comparator cmp)
    {
        _Iterator first_high = begin;
        _Iterator pivot = end-1;

        while (begin != end)
        {
            if (cmp(*pivot, *begin))
            {
                std::iter_swap(begin, first_high);
                ++first_high;
            }
            ++begin;
        }

        std::iter_swap(first_high, pivot);

        return first_high;
    }

    /**
     * Quick sort implementation
     * @param begin Collection start (inclusive)
     * @param end Collection end (exclusive)
     * @param cmp Comparison functor
     */
    template<typename _Iterator, typename _Comparator>
    sort_result_t quick_sort(_Iterator begin, _Iterator end, _Comparator cmp)
    {
        sort_result_t count = 0;

        if (begin != end && begin != (end-1))
        {
            _Iterator mid = __quick_sort_partition(begin, end, cmp);
            quick_sort(begin, mid, cmp);
            quick_sort(mid, end, cmp);
        }

        return count;
    }

    /**
     * Quick sort implementation
     * @param begin Collection start (inclusive)
     * @param end Collection end (exclusive)
     */
    template<typename _Iterator>
    sort_result_t quick_sort(_Iterator begin, _Iterator end)
    {
        return quick_sort(begin, end, default_comparator<typename std::iterator_traits<_Iterator>::value_type>());
    }

} // sort
} // algorithm
} // _7bit

#endif //__quick_sort_H_
