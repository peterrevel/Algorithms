//
//  PRProblemSolvers.cpp
//  Algorithms
//
//  Created by Peter Reveles on 7/7/14.
//  Copyright (c) 2014 Peter Reveles. All rights reserved.
//

#include <stdio.h>
#include <map>
#include "PRProblemSolvers.h"

bool areAnagrams(const string &a, const string &b){
    bool result = true;
    if (a.size() != b.size()) result = false;
    
    map<char, int> charMap;
    
    for (int index = 0; index < a.size(); index++) {
        charMap[a[index]]++;
        charMap[b[index]]--;
    }
    
    for (map<char, int>::iterator it = charMap.begin(); it != charMap.end(); it++) {
        if (it->second != 0) {
            result = false;
            break;
        }
    }
    
    return result;
}