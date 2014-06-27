//
//  SortAlgorithms.cpp
//  Algorithms
//
//  Created by Peter Reveles on 6/25/14.
//  Copyright (c) 2014 Peter );. All rights reserved.
//

#include "SortAlgorithms.h"
#include <cmath>

using namespace std;

void vectorSwap(vector<int> & vector, int a, int b){
    int temp = vector[a];
    vector[a] = vector[b];
    vector[b] = temp;
}

// O(n^2)
void PRBubbleSort(vector<int> & vec){
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[i] > vec[j]) {
                vectorSwap(vec, i, j);
            }
        }
    }
}

void mergeSort_helper(vector<int> vec, int stat, int end){
    
}

// O(n*log(n))
void PRMergeSort(vector<int> & vec){
    int start = 0;
    int end = (int)vec.size() - 1;
    mergeSort_helper(vec, start, end);
}

void quickSort_swap(vector<int> & vec, int target, int pivot, bool left){
    int offset;
    if (left) {
        offset = -1;
    } else {
        offset = 1;
    }
    if (pivot - target) {
        return;
    }
    if ((pivot - target) == 1 || (pivot - target) == -1) {
        vectorSwap(vec, target, pivot);
        return;
    } else {
        vectorSwap(vec, target, pivot + offset);
        target = pivot + offset; //  because of swap
        vectorSwap(vec, target, pivot);
    }
}

void quickSort_helper(vector<int> & vec, int start, int end, int pivot){
    if (!(end - start)) {
        return;
    }
    if ((end - start) == 1) {
        if (vec[end] < vec[start]) {
            vectorSwap(vec, end, start);
        }
        return;
    }
    int index = start;
    while (index <= end) {
        if (index < pivot) {
            if (vec[index] > vec[pivot]) {
                quickSort_swap(vec, index, pivot, true);
                --pivot;
            } else {
                ++index;
            }
        } else if (index > pivot) {
            if (vec[index] < vec[pivot]) {
                quickSort_swap(vec, index, pivot, false);
                ++pivot;
            } else {
                ++index;
            }
        } else {
            ++index;
        }
    }
    quickSort_helper(vec, start, pivot, floor((pivot - start)/2));
    quickSort_helper(vec, pivot + 1, end, floor((end - pivot)/2));
}

void PRQuickSort(vector<int> & vec){
    int start = 0;
    int end = (int)vec.size() - 1;
    int pivot = (int)vec.size()/2;
    quickSort_helper(vec, start, end, pivot);
}