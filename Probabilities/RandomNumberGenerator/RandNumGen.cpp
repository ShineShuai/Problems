#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


// return 1 with the probability of x%; 0 with 1-x%
unsigned int rand2(int x) {
    unsigned y = rand() % 100;
    return static_cast<unsigned int>(y < x);
}

// uniform randomly return 0 or 1
unsigned int rand2() {
    // The probabilities of generating "10" and "01" are same: 0.4*0.6 = 0.6*0.4.
    // So use those to generate 0 and 1, remove the possibilities of "00" and "11".
    while (true) {
        unsigned x = rand2(40);
        unsigned y = rand2(40);

        if (x == 1 && y == 0) { return 1; }
        if (x == 0 && y == 1) { return 0; }
    }
}

// uniformly generate an integer between 0 and 2.
unsigned int rand3() {
    return rand() % 3;
}

// uniformly generate an integer between 0 and 5.
unsigned int rand5() {
    return rand() % 5;
}

// implement rand5() using rand3().
unsigned int rand3to5() {
    unsigned int res = 0;
    while (true) {
        // Use a base of 3 to generate a number which uniformly distribute in a larger range.
        res = 3 * rand3() + rand3();
        if (res < 5) {
            return res;
            // return res % 5; // in case res > multiples of the base.
        }
    }
}

// implement rand3() using rand5().
unsigned int rand5to3() {
    unsigned int res = 0;
    while (true) {
        res = rand5();
        if (res < 3) { return res; }
    }
}

int main() {
    /* initialize random seed: */
    srand(time(NULL));

    // Cross check the experimental probability using a million trails.
    const unsigned int RAND_RANGE = 5;
    const int NUM_TRIALS = 1e6;
    unsigned int nums[RAND_RANGE];
    memset(nums, 0, sizeof(nums));
    unsigned int num = 0;

    for (int i=0; i<NUM_TRIALS; i++) {
        num += rand2();
        nums[rand3to5()]++;
    }

    std::cout << "Prob. of rand2()==1 : " << double(num)/NUM_TRIALS << " RADN_MAX=" << RAND_MAX << "\n";
    std::cout << "rand3to5()\n";
    for (int i=0; i<RAND_RANGE; i++) {
        std::cout << "Prob. of " << i << " : " << double(nums[i])/NUM_TRIALS << "\n";
    }
}
