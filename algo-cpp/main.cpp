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

template<typename _Collection>
void print_collection(const char * prefix, _7bit::algorithm::sort::sort_result_t sort_count, _Collection& collection)
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
    _7bit::algorithm::sort::sort_result_t sort_count;
    tmp = data;
    sort_count = _7bit::algorithm::sort::bubble_sort(tmp.begin(), tmp.end());
    print_collection("Bubble     \t", sort_count, tmp);

    tmp = data;
    sort_count = _7bit::algorithm::sort::insertion_sort(tmp.begin(), tmp.end());
    print_collection("Insertion  \t", sort_count, tmp);

    tmp = data;
    sort_count = _7bit::algorithm::sort::heap_sort(tmp.begin(), tmp.end());
    print_collection("Heap       \t", sort_count, tmp);

    return 0;
}
