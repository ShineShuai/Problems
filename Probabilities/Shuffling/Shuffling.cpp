#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/********************************************************************
 Provide a method that randomly and efficiently shuffles the elements
 in an array.
********************************************************************/

// Randomly shuffle an array with the given size.
void shuffle(int array[], int size) {
    for (int i=size; i>1; ) {
        // Randomly pick one element from the i remaining elements with the probability of 1/i,
        // and assign the element to the i-th position.
        // i.e. swap the i-th element with the i remaining elements with the probability of 1/i.
        int j = rand() % i;
        i--;
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

// Quick sort : an in-place implementation, but not stable sorting.
// pass array by reference to the function.
void quickSort(int array[], int size) {
    if (size < 2) {
        return;
    }
    int lv = 0;
    int rv = size - 1;
    int j = rand() % size;
    int pivot = array[j];

    // Sort the array so that array[0..lv] <= pivot <= array[rv..end].
    while (lv <= rv) {
        if (array[lv] < pivot) {
            lv++;
        } else if (array[rv] > pivot) {
            rv--;
        } else { // left >= pivot && right <= pivot
            int tmp = array[lv];
            array[lv] = array[rv];
            array[rv] = tmp;
            lv++;
            rv--;
        }
    }

    quickSort(array, lv);
    quickSort(&array[lv], size - lv);
}


int main() {
    /* initialize random seed: */
    srand(time(NULL));

    const int N = 10; // the number of elements in an array.
    int array[N];  // an array initilized with [0..N-1].

    for (int i=0; i<N; i++) {
        array[i] = i;
    }

    shuffle(array, N);

    // display the shuffled numbers
    std::cout << "shuffled : ";
    for (int i=0; i<N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout <<  "\n";

    quickSort(array, N);

    // display the shuffled numbers in a sorting order.
    std::cout << "sorted : ";
    for (int i=0; i<N; i++) {
        std::cout << array[i] << " ";
    }
    std::cout <<  "\n";
}
