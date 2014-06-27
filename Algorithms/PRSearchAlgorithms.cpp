//
//  PRSearchAlgorithms.cpp
//  Algorithms
//
//  Created by Peter Reveles on 6/27/14.
//  Copyright (c) 2014 Peter Reveles. All rights reserved.
//

#include "PRSearchAlgorithms.h"
#include <stdio.h>
#include <cmath>

using namespace std;

bool binarySearch_helper(const vector<int> &vec, int start, int end, int key){
    int mid = floor((end - start)/2) + start;
    if (end == start) {
        return vec[mid]==key;
    }
    if (vec[mid]==key) {
        return true;
    }
    if (key < vec[mid]) {
        return binarySearch_helper(vec, start, mid, key);
    }
    if (key > vec[mid]) {
        return binarySearch_helper(vec, mid + 1, end, key);
    }
    return false;
}

bool binarySearch(const vector<int> &vec, int key){
    return binarySearch_helper(vec, 0, (int)vec.size() - 1, key);
}