

/**
* Title: Sorting and Algorithm Efficiency
* Author: Deniz Sun
* ID: 22003981
* Section: 1
* Assignment: 1
* Description: the sorting algorithm
*/
#include "sorting.h"
#include <iostream>
// sort in ascending order
// first element is pivot
// add counters for key comparisons and data moves (compcount and movecount)

void sorting::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sorting::bubbleSort(int *arr, const int size, long long &compCount, long long &moveCount) {
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted; pass++) {
        sorted = true;
        for (int i = 0; i < (size - pass); ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                //swap makes 3 moves
                moveCount += 3;
                sorted = false;
            }
            //each iteration is a comparison
            compCount++;
        }
    }
}



void sorting::merge(int *arr, int first, int mid, int last, int maxArraySize, long long &compCount, long long &moveCount) {
    int tempArray[maxArraySize];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
        } else {
            tempArray[index] = arr[first2];
            ++first2;
        }
        compCount++;
        moveCount++;
    }

    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index) {
        tempArray[index] = arr[first1];
        moveCount++;
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = arr[first2];
        moveCount++;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index) {
        arr[index] = tempArray[index];
        moveCount++;
    }
}

void sorting::mergeSort(int *arr, int first, int last,  long long &compCount, long long &moveCount, int size){

        if (first < last) {
            int mid = (last + first ) / 2;

            mergeSort(arr, first, mid, compCount, moveCount, size);
            mergeSort(arr, mid + 1, last, compCount,moveCount, size);

            merge(arr, first, mid, last, size, compCount, moveCount);
        }
    }

void sorting::mergeSort(int *arr, const int size, long long &compCount, long long &moveCount) {
    mergeSort(arr, 0, size - 1, compCount, moveCount, size);

}

void sorting::partition(int *arr, int first, int last, int &pivotIndex, long long &compCount, long long &moveCount){
    int pivot = arr[first];
    moveCount++;

    int lastS1 = first;
    int firstUnknown = first + 1;

    for (; firstUnknown <= last; firstUnknown++) {
        if (arr[firstUnknown] < pivot) {
            lastS1++;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        }
        compCount++;
    }


    swap(arr[first], arr[lastS1]);
    moveCount += 3; // swap moves 3 times
    pivotIndex = lastS1;
}
void sorting::quickSort(int *arr, int first, int last,  long long &compCount, long long &moveCount) {
    int pivot;
    if (first < last) {
        partition(arr, first, last, pivot, compCount, moveCount);
        quickSort(arr, first, pivot - 1, compCount, moveCount);
        quickSort(arr, pivot + 1, last, compCount, moveCount);
    }
}
void sorting::quickSort(int *arr, const int size, long long &compCount, long long &moveCount) {
    quickSort(arr, 0, size - 1, compCount, moveCount);

}

void sorting::displayArray(const int *arr, const int size) {
    if (arr != NULL){
        cout << "[ ";
        for (int i = 0; i < size -1; ++i) {
            cout << arr[i] << ", ";
        }
        cout << arr[size - 1] << " ]" << endl;
    }
    else
        cout << "[]" << endl;

}

void sorting::createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size) {
    srand((int) time(NULL));
    for (int i = 0; i < size; ++i) {
        //create a random number and add it into all arrays, making them random but equal
        int random = rand() % 1000 + 1;  //random number between 1 and 100
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
    }

}

void sorting::createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size) {
    for (int i = 0; i < size; ++i) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;

    }

}

void sorting::createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size) {
    for (int i = 0; i < size; ++i) {
        arr1[i] = size - i;
        arr2[i] = size - i;
        arr3[i] = size - i;
    }
}

void sorting::performanceAnalysis() {
    double duration;
    clock_t startTime;
    long long comp = 0;
    long long move = 0;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" <<
         "Bubble Sort Analysis\n"
         "Algorithm with random elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;


    for (int size = 4000; size <= 48000; size+= 4000) {


        int *arr1 = new int[size];
        int *arr2 = new int[size];;
        int *arr3 = new int[size];;
        createRandomArrays(arr1, arr2, arr3, size);

        startTime = clock();
        cout << size;
        bubbleSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }
    cout << "\nAlgorithm with descending sorted elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;

    for (int size = 4000; size <= 48000; size+= 4000) {

        int *arr1 = new int[size];
        int *arr2 = new int[size];;
        int *arr3 = new int[size];
        createDescendingArrays(arr1, arr2, arr3, size);
        comp = 0;
        move = 0;
        startTime = clock();
        cout << size;
        bubbleSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    cout << "\nAlgorithm with ascending sorted elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;
    for (int size = 4000; size <= 48000; size+= 4000) {

        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];

        createAscendingArrays(arr1, arr2, arr3, size);
        comp = 0;
        move = 0;
        startTime = clock();
        cout << size;
        bubbleSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

    }


    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" <<
         "Merge Sort Analysis\n"
         "Algorithm with random elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;


    for (int size = 4000; size <= 48000; size+= 4000) {


        int *arr1 = new int[size];
        int *arr2 = new int[size];;
        int *arr3 = new int[size];;
        createRandomArrays(arr1, arr2, arr3, size);

        startTime = clock();
        cout << size;
        mergeSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }
    cout << "\nAlgorithm with descending sorted elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;

    for (int size = 4000; size <= 48000; size+= 4000) {

        int *arr1 = new int[size];
        int *arr2 = new int[size];;
        int *arr3 = new int[size];
        createDescendingArrays(arr1, arr2, arr3, size);
        comp = 0;
        move = 0;
        startTime = clock();
        cout << size;
        mergeSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    cout << "\nAlgorithm with ascending sorted elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;
    for (int size = 4000; size <= 48000; size+= 4000) {

        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];

        createAscendingArrays(arr1, arr2, arr3, size);
        comp = 0;
        move = 0;
        startTime = clock();
        cout << size;
        mergeSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" <<
         "Quick Sort Analysis\n"
         "Algorithm with random elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;



    for (int size = 4000; size <= 48000; size+= 4000) {


        int *arr1 = new int[size];
        int *arr2 = new int[size];;
        int *arr3 = new int[size];;
        createRandomArrays(arr1, arr2, arr3, size);

        startTime = clock();
        cout << size;
        quickSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }
    cout << "\nAlgorithm with descending sorted elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;

    for (int size = 4000; size <= 48000; size+= 4000) {

        int *arr1 = new int[size];
        int *arr2 = new int[size];;
        int *arr3 = new int[size];
        createDescendingArrays(arr1, arr2, arr3, size);
        comp = 0;
        move = 0;
        startTime = clock();
        cout << size;
        quickSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }

    cout << "\nAlgorithm with ascending sorted elements:\nArray Size         Elapsed Time                compCount           moveCount" << endl;
    for (int size = 4000; size <= 48000; size+= 4000) {

        int *arr1 = new int[size];
        int *arr2 = new int[size];
        int *arr3 = new int[size];

        createAscendingArrays(arr1, arr2, arr3, size);
        comp = 0;
        move = 0;
        startTime = clock();
        cout << size;
        quickSort(arr1, size, comp, move);

        duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        cout << "               " << duration << " ms.                     " << comp << "           " << move << endl;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

    }

}

