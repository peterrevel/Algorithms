//
//  main.cpp
//  Algorithms
//
//  Created by Peter Reveles on 6/24/14.
//  Copyright (c) 2014 Peter Reveles. All rights reserved.
//

#include <iostream>
#include "Vector"
#include "SkylineSolver.h"
#include "SortAlgorithms.h"

void printVector(vector<int> vector){
    for (int index = 0; index < vector.size(); ++index) {
        cout << vector[index] << " ";
    }
    cout << endl;
}

using namespace std;

int main()
{
    // insert code here...
    cout << "Hello, this is my repo which I'm using to practice solving algorithms." << endl;
    string test = returnTestString();
    cout << test << endl;
    vector<int> vectorOne;
    for (int i = 0; i < 10; ++i) {
        vectorOne.push_back(arc4random() % 20);
    }
    
    vector<int> vectorTwo = vectorOne;
    
    cout << "---\nBubble Sort" << endl;
    cout << "Complexity: O(n^2)" << endl;
    cout << "Original Vector: "; printVector(vectorOne);
    PRBubbleSort(vectorOne);
    cout << "Sorted Vector: "; printVector(vectorOne);
    cout << "---" << endl;
    
    cout << "---\nQuick Sort" << endl;
    cout << "Original Vector: "; printVector(vectorTwo);
    PRBubbleSort(vectorTwo);
    cout << "Sorted Vector: "; printVector(vectorTwo);
    cout << "---" << endl;
    
    return 0;
}

