#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/********************************************************************
 Efficiently return a random sample of M elements evenly distributed
 from a very large data stream.
********************************************************************/

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

    const int N = 1000; // the number of data elements contained in a large stream.
    const int M = 10;   // the number of returned elements that are randomly distributed from the stream.
    int stream[N];  // a large data stream contains numbers from 0 to N-1.
    int out[M];     // output random samples.

    // randomly pick M samples from the data stream.
    for (int i=0; i<N; i++) {
        stream[i] = i;

        if (i < M) {
            out[i] = stream[i];
        } else {    // swap a sample with the k-th element with the probability of M/k. (k>=1)
            int j = rand() % (i + 1);
            if (j < M) {
                out[j] = i;
            }
        }
    }

    // display the random samples
    std::cout << "output stream : ";
    for (int i=0; i<M; i++) {
        std::cout << out[i] << " ";
    }
    std::cout <<  "\n";

    quickSort(out, M);

    // display the random samples in a sorting order.
    std::cout << "output sorted : ";
    for (int i=0; i<M; i++) {
        std::cout << out[i] << " ";
    }
    std::cout <<  "\n";


    // Test quickSort()
    int in[M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            out[j] = rand() % M;
            in[j] = out[j];
        }

        quickSort(out, M);

        for (int j=1; j<M; j++) {
            if (out[j] < out[j-1]) {
                std::cout << "in : ";
                for (int k=0; k<M; k++) {
                    std::cout << in[k] << " ";
                }
                std::cout <<  "\n";
                std::cout << "out sorted : ";
                for (int k=0; k<M; k++) {
                    std::cout << out[k] << " ";
                }
                std::cout <<  "\n";
                break;
            }
        }
    }
}
