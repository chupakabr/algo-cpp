//
// Created by Valeriy Chevtaev on 07/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//


#ifndef __bubble_sort_H_
#define __bubble_sort_H_

namespace _7bit {
namespace algorithm {
namespace sort {

template<class T>
bool default_comparator(T& v1, T& v2)
{
    return v1 > v2;
}

//template<class _Iterator, class _ElementType>
//void bubble_sort(_Iterator begin, _Iterator end, bool (*cmp)(_ElementType&, _ElementType&) = default_comparator)
template<class _Iterator>
void bubble_sort(_Iterator begin, _Iterator end)
{
    if (begin == end) return;

    // TODO

}

} // sort
} // algorithm
} // _7bit

#endif //__bubble_sort_H_
