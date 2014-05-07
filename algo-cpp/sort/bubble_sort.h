//
// Created by Valeriy Chevtaev on 07/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#ifndef __bubble_sort_H_
#define __bubble_sort_H_

#include "sort_common.h"

namespace _7bit {
namespace algorithm {
namespace sort {

// Bubble sort implementation
// @param begin Collection start
// @param end Collection end
// @param cmp Comparison functor
template<typename _Iterator, typename _Comparator>
sort_result_t bubble_sort(_Iterator begin, _Iterator end, _Comparator cmp)
{
    if (begin == end) return 0;

    sort_result_t count = 0;
    typename std::iterator_traits<_Iterator>::value_type tmp;
    for (_Iterator it = begin; it != end; ++it)
    {
        for (_Iterator it2 = it; it2 != end; ++it2)
        {
            if (cmp(*it, *it2))
            {
                tmp = *it;
                *it = *it2;
                *it2 = tmp;
            }

            ++count;
        }
    }

    return count;
}

// Bubble sort implementation
// @param begin Collection start
// @param end Collection end
template<typename _Iterator>
sort_result_t bubble_sort(_Iterator begin, _Iterator end)
{
    return bubble_sort(begin, end, default_comparator<typename std::iterator_traits<_Iterator>::value_type>());
}

} // sort
} // algorithm
} // _7bit

#endif //__bubble_sort_H_
