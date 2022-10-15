/*
* Title: Sorting and Algorithm Efficiency
* Author: Deniz Sun
* ID: 22003981
* Section: 1
* Assignment: 1
* Description: main class for the sorting algorithms
*/

#include "sorting.h"
int main() {
    sorting s;
    long long comp, move;
    int arr[16] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,
                   33, 26};

    int arr2[16] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,
                   33, 26};
    int arr3[16] = {40, 25, 29, 56, 37, 27, 24, 32, 79, 12, 35, 38, 23, 31,
                   33, 26};
    s.displayArray(arr, 16);
    cout << "Bubble sort with the sample array: " << endl;
    s.bubbleSort(arr, 16, comp, move);
    s.displayArray(arr, 16);

//    s.performanceAnalysis();

    return 0;

}
