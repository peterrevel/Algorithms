//
//  main.cpp
//  Algorithms
//
//  Created by Peter Reveles on 6/24/14.
//  Copyright (c) 2014 Peter Reveles. All rights reserved.
//

#include <iostream>
#include <map>
#include "Vector"
#include "SortAlgorithms.h"
#include "PRSearchAlgorithms.h"
#include "PRProblemSolvers.h"

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
    
    vector<int> vectorOne;
    for (int i = 0; i < 10; ++i) {
        vectorOne.push_back(arc4random() % 20);
    }
    
    vector<int> vectorTwo = vectorOne;
    vector<int> vectorThree = vectorTwo;
    
    cout << "---\nBubble Sort" << endl;
    cout << "Complexity: O(n^2)" << endl;
    cout << "Original Vector: "; printVector(vectorOne);
    PRBubbleSort(vectorOne);
    cout << "Sorted Vector: "; printVector(vectorOne);
    cout << "---" << endl;
    
    cout << "---\nQuick Sort" << endl;
    cout << "Original Vector: "; printVector(vectorTwo);
    PRQuickSort(vectorTwo);
    cout << "Sorted Vector: "; printVector(vectorTwo);
    cout << "---" << endl;
    
    vector<int> vectorFour = {1, 2, 3, 4, 5};
    
    cout << "---\nBinary Search" << endl;
    cout << "Original Vector: "; printVector(vectorFour);
    (binarySearch(vectorFour, 1)) ? cout << "Contains 1." << endl : cout << "Does not contain 1." << endl;
    (binarySearch(vectorFour, 3)) ? cout << "Contains 3." << endl : cout << "Does not contain 3." << endl;
    (binarySearch(vectorFour, 5)) ? cout << "Contains 5." << endl : cout << "Does not contain 5." << endl;
    (binarySearch(vectorFour, -1)) ? cout << "Contains -1." << endl : cout << "Does not contain -1." << endl;
    (binarySearch(vectorFour, 11)) ? cout << "Contains 11." << endl : cout << "Does not contain 11." << endl;
    cout << "---" << endl;
    
    return 0;
}

