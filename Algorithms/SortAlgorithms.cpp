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

void quickSort_swap(vector<int> & vec, int target, int pivot, bool left){
    int offset = left ? -1 : 1;
    if ((pivot - target) == 1 || (pivot - target) == -1) {
        vectorSwap(vec, target, pivot);
    } else {
        vectorSwap(vec, target, pivot + offset);
        target = pivot + offset; //  because of swap
        vectorSwap(vec, target, pivot);
    }
}

void quickSort_helper(vector<int> & vec, int start, int end, int pivot){
    if (end - start <= 0) return;
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
    int leftStart = start;
    int leftEnd = pivot - 1;
    int leftPivot = floor((leftEnd - leftStart)/2) + leftStart;
    quickSort_helper(vec, start, leftEnd, leftPivot);
    int rightStart = pivot + 1;
    int rightEnd = end;
    int rightPivot = floor((rightEnd - rightStart)/2) + rightStart;
    quickSort_helper(vec, rightStart, rightEnd, rightPivot);
}

void PRQuickSort(vector<int> & vec){
    int start = 0;
    int end = (int)vec.size() - 1;
    int pivot = (int)vec.size()/2;
    quickSort_helper(vec, start, end, pivot);
}