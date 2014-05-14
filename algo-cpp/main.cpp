//
//  main.cpp
//  algo-cpp
//
//  Created by Valeriy Chevtaev on 20/04/2014.
//  Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#include <iostream>
#include <vector>
#include "sort/sort.h"

using namespace _7bit::algorithm::sort;

#define RUN_SORT(header_, func_) do { \
    tmp = data; \
    timestamp_t t1 = get_timestamp(); \
    sort_result_t sort_count = func_(tmp.begin(), tmp.end()); \
    timestamp_t t2 = get_timestamp(); \
    print_collection(header_, sort_count, tmp); \
    std::cout << "time: " << (t2-t1) << " ms" << std::endl; \
} while(0);

template<typename _Collection>
void print_collection(const char * prefix, sort_result_t sort_count, _Collection& collection)
{
    std::cout << prefix << "\t(" << sort_count << "): [";
    for (auto e : collection)
    {
        std::cout << e << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, const char * argv[])
{
    std::vector<int> data, tmp;
    data.push_back(2);
    data.push_back(3);
    data.push_back(7);
    data.push_back(1);
    data.push_back(10);
    data.push_back(8);
    data.push_back(5);
    data.push_back(4);
    data.push_back(6);
    data.push_back(9);

    print_collection("Unsorted   \t", 0, data);

    // Sort
    RUN_SORT("Bubble     \t", bubble_sort);
    RUN_SORT("Insertion  \t", insertion_sort);
    RUN_SORT("Heap       \t", heap_sort);
    RUN_SORT("Merge      \t", merge_sort);
    RUN_SORT("Quick      \t", quick_sort);

    return 0;
}
