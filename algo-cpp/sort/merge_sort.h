//
// Created by Valeriy Chevtaev on 12/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#ifndef __merge_sort_H_
#define __merge_sort_H_

#include "sort_common.h"
#include <deque>
#include <cmath>

namespace _7bit {
namespace algorithm {
namespace sort {

    /**
     * Do actual sort and merge of specified range of elements
     * @param begin Collection start
     * @param low Collection's low index to merge&sort
     * @param high Collection's high index to merge&sort
     * @param cmp Comparison functor
     */
    template<typename _Iterator, typename _Comparator>
    sort_result_t __ms_merge(_Iterator begin, const int low, const int high, _Comparator cmp)
    {
        sort_result_t count = 0;

        // Fill both deques
        std::deque<typename std::iterator_traits<_Iterator>::value_type> dq1, dq2;
        const _Iterator local_end = begin+high+1;
        int mid = std::floor((high+low)/2);
        int cnt = low;
        for (_Iterator it = begin+low; it != local_end; ++it)
        {
            if (cnt++ <= mid)
            {
                dq1.push_back(*it);
            }
            else
            {
                dq2.push_back(*it);
            }
        }

        // Merge utill one of the deques is empty
        _Iterator local_it = begin+low;
        while (!(dq1.empty() || dq2.empty()))
        {
            if (cmp(dq1.front(), dq2.front()))
            {
                *local_it = dq2.front();
                dq2.pop_front();
            }
            else
            {
                *local_it = dq1.front();
                dq1.pop_front();
            }

            ++local_it;
            ++count;
        }

        // Merge the rest
        while (!dq1.empty())
        {
            *local_it = dq1.front();
            dq1.pop_front();
            ++local_it;

            ++count;
        }

        while (!dq2.empty())
        {
            *local_it = dq2.front();
            dq2.pop_front();
            ++local_it;

            ++count;
        }

        return count;
    }

    /**
     * Recursive merge&sort function
     * @param begin Collection start
     * @param low Collection's low index to merge&sort
     * @param high Collection's high index to merge&sort
     * @param cmp Comparison functor
     */
    template<typename _Iterator, typename _Comparator>
    sort_result_t __ms_sort(_Iterator begin, const int low, const int high, _Comparator cmp)
    {
        sort_result_t count = 0;

        if (low < high)
        {
            int mid = std::floor((high+low)/2);
            count += __ms_sort(begin, low, mid, cmp);
            count += __ms_sort(begin, mid+1, high, cmp);
            count += __ms_merge(begin, low, high, cmp);
        }

        return count;
    }

    /**
     * Merge sort implementation
     * @param begin Collection start
     * @param end Collection end
     * @param cmp Comparison functor
     * @param container_size The actual number of elements to sort
     */
    template<typename _Iterator, typename _Comparator>
    sort_result_t merge_sort(_Iterator begin, _Iterator end, _Comparator cmp, int container_size = -1)
    {
        if (begin == end) return 0;

        // Get the size of the container if not specified
        if (container_size <= 0)
        {
            container_size = 0;
            std::for_each(begin, end,
                    [&container_size](typename std::iterator_traits<_Iterator>::value_type v){++container_size;});
        }

        // Sort and merge
        return __ms_sort(begin, 0, container_size-1, cmp);
    }

    /**
     * Merge sort implementation
     * @param begin Collection start
     * @param end Collection end
     * @param container_size The actual number of elements to sort
     */
    template<typename _Iterator>
    sort_result_t merge_sort(_Iterator begin, _Iterator end, int container_size = -1)
    {
        return merge_sort(begin, end, default_comparator<typename std::iterator_traits<_Iterator>::value_type>(), container_size);
    }

} // sort
} // algorithm
} // _7bit

#endif //__merge_sort_H_
