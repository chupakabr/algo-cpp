//
// Created by Valeriy Chevtaev on 07/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//


#ifndef __bubble_sort_H_
#define __bubble_sort_H_

#include <iterator>

namespace _7bit {
namespace algorithm {
namespace sort {

// Default "whether first if less than second" comparator
template<typename T>
class default_comparator
{
public:
    bool operator()(const T& v1, const T& v2)
    {
        return v1 < v2;
    }
};

// Bubble sort implementation
// @param begin Collection start
// @param end Collection end
// @param cmp Comparison functor
template<typename _Iterator, typename _Comparator>
void bubble_sort(_Iterator begin, _Iterator end, _Comparator cmp)
{
    if (begin == end) return;

    // TODO
    for (_Iterator it = begin; it != end; ++it)
    {
        for (_Iterator it2 = it; it2 != end; ++it2)
        {

        }
    }
}

// Bubble sort implementation
// @param begin Collection start
// @param end Collection end
template<typename _Iterator>
void bubble_sort(_Iterator begin, _Iterator end)
{
    bubble_sort(begin, end, default_comparator<typename std::iterator_traits<_Iterator>::value_type>());
}

} // sort
} // algorithm
} // _7bit

#endif //__bubble_sort_H_
