/**
* Title: Sorting and Algorithm Efficiency
* Author: Deniz Sun
* ID: 22003981
* Section: 1
* Assignment: 1
* Description: header file for the sorting algorithm
*/

using namespace std;
#include <string>
#include <iostream>
class sorting {
public:
    void bubbleSort(int *arr, const int size, long long &compCount, long long &moveCount);
    void mergeSort(int *arr, const int size, long long &compCount, long long &moveCount);
    void quickSort(int *arr, const int size, long long &compCount, long long &moveCount);

    void swap(int &a, int &b);
    void mergeSort(int *arr, int first, int last, long long &compCount, long long &moveCount, int size);
    void merge(int *arr, int first, int mid, int last, int maxArraySize, long long &compCount, long long &moveCount);
    void quickSort(int *arr, int first, int last,  long long &compCount, long long &moveCount);

    void partition(int *arr, int first, int last, int &pivotIndex, long long &compCount, long long &moveCount);
    void displayArray(const int *arr, const int size);

    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
    void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
    void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);

    void performanceAnalysis();

};
