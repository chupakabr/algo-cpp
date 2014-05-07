//
// Created by Valeriy Chevtaev on 07/05/2014.
// Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#ifndef __sort_common_H_
#define __sort_common_H_

#include <iterator>

namespace _7bit {
namespace algorithm {
namespace sort {

typedef uint32_t sort_result_t;

// Default "whether first is greater than second" comparator
template<typename T>
class default_comparator
{
public:
    bool operator()(const T& v1, const T& v2)
    {
        return v1 > v2;
    }
};

} // sort
} // algorithm
} // _7bit

#endif //__sort_common_H_
