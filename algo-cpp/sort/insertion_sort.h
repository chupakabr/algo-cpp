//
// Created by Valeriy Chevtaev on 07/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#ifndef __insertion_sort_H_
#define __insertion_sort_H_

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
    sort_result_t insertion_sort(_Iterator begin, _Iterator end, _Comparator cmp)
    {
        if (begin == end) return 0;

        sort_result_t count = 0;
        typename std::iterator_traits<_Iterator>::value_type tmp;
        for (_Iterator it = begin+1; it != end; ++it)
        {
            for (_Iterator it2 = it; it2 != begin && cmp(*(it2-1), *it2); --it2)
            {
                tmp = *it2;
                *it2 = *(it2-1);
                *(it2-1) = tmp;

                ++count;
            }
        }

        return count;
    }

    /**
     * Insertion sort implementation
     * @param begin Collection start
     * @param end Collection end
     */
    template<typename _Iterator>
    sort_result_t insertion_sort(_Iterator begin, _Iterator end)
    {
        return insertion_sort(begin, end, default_comparator<typename std::iterator_traits<_Iterator>::value_type>());
    }

} // sort
} // algorithm
} // _7bit

#endif //__insertion_sort_H_
