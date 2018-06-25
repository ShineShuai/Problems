#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/********************************************************************
 Given an array a[1..n], construct an array b[1..n] in O(n) time and
 O(1) space, so that b[i]=a[1]*a[2]*..*a[n]/a[i].
 The division operator is not available.
********************************************************************/


int main() {
    /* initialize random seed: */
    srand(time(NULL));

    const int N = 10; // the number of elements in an array, with N>0

    bool once = false; // test the computation only once or multiple times.
    int test_num = once ? 1 : 1000; // the number of computation tests.

    for (int j=0; j<test_num; j++) {

        long int in[N];  // an array initilized with [0..N-1].
        for (int i=0; i<N; i++) {
            in[i] = rand() % 80 + 1;
        }

        //long int in[] = {81, 98, 90, 94, 78, 96, 70, 92, 98, 83}; // overflow if average > 80 in the case of N=10.
        long int out[N];

        // cumulative product from the left. left[i]=a[1]*..*a[i-1]
        out[0] = in[0];
        for (int i=1; i<N-1; i++) {
            out[i] = out[i-1] * in[i];
        }
        out[N-1] = N > 1 ? out[N-2] : 1;

        // cumulative product from the right. right[i]=a[i+1]*..*a[n]
        // multiple both terms to get b[i]=left[i]*right[i]
        long int tmp = in[N-1];
        for (int i=N-2; i>0; i--) {
            out[i] = out[i-1] * tmp;
            tmp *= in[i];
        }
        out[0] = tmp;

        // output results or check results.
        tmp *= in[0];

        if (once) { // test the computation only once.
            // display the results using the division operator.
            std::cout << "input : ";
            for (int i=0; i<N; i++) {
                std::cout << in[i] << " ";
            }
            std::cout <<  "\n";

            std::cout << "w. div : ";
            for (int i=0; i<N; i++) {
                std::cout << tmp / in[i] << " ";
            }
            std::cout <<  "\n";

            // display the results without using division.
            std::cout << "w/o div : ";
            for (int i=0; i<N; i++) {
                std::cout << out[i] << " ";
            }
            std::cout <<  "\n";

        } else {    // test the compuatation multiple times
            bool wrong = false;

            for (int i=0; i<N; i++) {
                if (tmp / in[i] != out[i]) {
                    wrong = true;
                }
            }

            if (wrong) {
                std::cout << "input : ";
                for (int i=0; i<N; i++) {
                    std::cout << in[i] << " ";
                }
                std::cout <<  "==> " << tmp << "\n";

                tmp = 1;
                std::cout << "multiple : ";
                for (int i=0; i<N; i++) {
                    tmp *= in[i];
                    std::cout << tmp << " ";
                }
                std::cout <<  "==> " << tmp << "\n";
            }

        }
    }
}
