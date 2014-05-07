//
//  main.cpp
//  algo-cpp
//
//  Created by Valeriy Chevtaev on 20/04/2014.
//  Copyright (c) 2014 Valeriy Chevtaev. All rights reserved.
//

#include <iostream>
#include <vector>
#include "sort/bubble_sort.h"

template<class _Collection>
void print_collection(const char * prefix, _Collection& collection)
{
    std::cout << prefix << "[";
    for (auto e : collection)
    {
        std::cout << e << ", ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, const char * argv[])
{
    std::vector<int> data(10);
    data.push_back(1);
    data.push_back(5);
    data.push_back(3);
    data.push_back(7);
    data.push_back(10);
    data.push_back(8);
    data.push_back(2);
    data.push_back(4);
    data.push_back(6);
    data.push_back(9);

    print_collection("Unsorted:\t", data);
    _7bit::algorithm::sort::bubble_sort(data.begin(), data.end());
    print_collection("Sorted:  \t", data);

    return 0;
}
