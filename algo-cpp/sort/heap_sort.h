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

    // Implementation of dynamic sized priority queue on heap. Zero element is dummy to work with indexes starting from 1.
    // Bad implementation because of vector. TODO Implement using arrays or something else.
    // TODO Make this data structure safe (index overflow, ...)
    template<typename _Element, typename _Comparator>
    class heap_priority_queue
    {
    public:
        heap_priority_queue(_Comparator cmp)
        : comparator_(cmp)
        {
            array_.push_back(0);
        }

        void enqueue(_Element element)
        {
            array_.push_back(element);
            bubble_up(array_.size()-1);
        }

        _Element dequeue_min()
        {
            _Element min = array_[1];

            array_[1] = array_[array_.size()-1];
            array_.pop_back();

            bubble_down(1);

            return min;
        }
    private:
        int parent(int idx)
        {
            if (idx <= 1)
            {
                return -1;
            }

            return idx/2;
        }

        int child(int idx)
        {
            int child_idx = idx*2;
            if (child_idx >= array_.size())
            {
                return -1;
            }

            return child_idx;
        }

        void swap(int idx1, int idx2)
        {
            _Element tmp = array_[idx1];
            array_[idx1] = array_[idx2];
            array_[idx2] = tmp;
        }

        void bubble_up(int idx)
        {
            int parent_idx = parent(idx);
            if (parent_idx >= 1 && comparator_(array_[parent_idx], array_[idx]))
            {
                swap(parent_idx, idx);
                bubble_up(parent_idx);
            }
        }

        void bubble_down(int idx)
        {
            int child_idx = child(idx);
            if (child_idx < 1 || child_idx >= array_.size())
            {
                return;
            }

            int min_idx = idx;
            for (int i = 0; i <= 1; ++i)
            {
                if ((child_idx+i) < array_.size() && comparator_(array_[min_idx], array_[child_idx+i]))
                {
                    min_idx = child_idx+i;
                }
            }

            if (min_idx != idx)
            {
                swap(idx, min_idx);
                bubble_down(min_idx);
            }
        }

        std::vector<_Element> array_;
        _Comparator comparator_;
    };

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

        sort_result_t count = 0;

        // Init heap
        heap_priority_queue< typename std::iterator_traits<_Iterator>::value_type, _Comparator > pqueue(cmp);
        for (_Iterator it = begin; it != end; ++it)
        {
            pqueue.enqueue(*it);
            ++count;
        }

        // Go through all the elements by dequeuing the minimum on each iteration
        for (_Iterator it = begin; it != end; ++it)
        {
            *it = pqueue.dequeue_min();
            ++count;
        }

        return count;
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
