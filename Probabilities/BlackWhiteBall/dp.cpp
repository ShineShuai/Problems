#include <iostream>

/********************************************************************
There are W white balls and B black balls in a bucket.
Repeat the following actions:
    * Randomly take 2 balls out from the bucket every time.
      - Put 1 black ball into the bucket, if their colors are same.
      - Put 1 white ball into the bucket, if their colors are different.
What is the probability of that the only 1 black ball remains in the bucket?

Solution:
If W == even : the probability is one.
If W == odd : the probability is zero.
You can conclude it without programming. Just a cross check.
********************************************************************/

// number of black and white balls
const int B = 100;
const int W = 100;
// array for storing the probability of each possibility
double probs[W + 1][B + W / 2 + W % 2 + 1];


// Under the probability of w white balls and b black balls, to calculate the
// probability of w-2 white balls and b+1 black balls.
// both balls are white: w-2 & b+1
void bInc(int w, int b) {
    if (w > 1 && b >= 0) {
        probs[w-2][b+1] += probs[w][b] * w * (w - 1) / (w + b) / (w + b - 1);
    }
}

// Under the probability of w white balls and b black balls, to calculate the
// probability of w white balls and b-1 black balls.
// both balls are black: w & b-2+1
// one black and one white: w-1+1 & b-1
void bDec(int w, int b) {
    if (b > 0 && w + b > 1) {
        probs[w][b-1] += probs[w][b] * b * (b - 1) / (w + b) / (w + b - 1) + probs[w][b] * 2 * w * b / (w + b) / (w + b - 1);
    }
}

// Given the number of white balls and black balls in the initial state,
// to calculate the probability of each possibility and store them into the array.
void calcProbs(int w, int b) {
    memset(probs, 0, sizeof(probs));
    probs[w][b] = 1.0;  // initial state: the probability of W white balls and B black balls is one.

    // update the probability of each possibility.
    while (w + b > 1) { // continue to take two balls out from the bucket until only one ball remains.

        // Need to update the probability of each possibility from the right to
        // left and from the bottom to the top, because of the conditional probability.
        for (int k = b; k>=0; k--) { // calc the probs along with the decrease of #black.
            int j = k;

            for (int i=w; i>=0; i-=2) { // calc the probs along with the decrease of #white.
                bInc(i, j);
                bDec(i, j);
                j++;
            }
        }

        // Handle the probability of the top left corner. No black balls.
        w -= 2;
        b = 0;
    }
}

int main() {
    calcProbs(W, B);
    std::cout << "0 white 1 black: " << probs[0][1] << "\n1 white 0 black: " << probs[1][0] << "\n1 white 1 black: " << probs[1][1] << "\n";
    if (W > 1 && B > 0) {
      std::cout << W-2 << " white " << B+1 << " black: " << probs[W-2][B+1] << "\n" << W << " white " << B-1 << " black: " << probs[W][B-1] << "\n" << W << " white " << B << " black: " << probs[W][B] << "\n";
    }
}
