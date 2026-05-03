#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

#include "CumProdWoTerm.hpp"

/********************************************************************
 Given an array a[1..n], construct an array b[1..n] in O(n) time and
 O(1) space, so that b[i]=a[1]*a[2]*..*a[n]/a[i].
 The division operator is not available.
********************************************************************/

auto
main() -> int {  // NOLINT(bugprone-exception-escape)
  // the number of elements in an array, with N>0
  constexpr int N = 10;
  // test the computation only once or multiple times.
  constexpr bool Once = true;
  constexpr int  Num  = Once ? 1 : 1000;  // the number of computation tests.

  std::mt19937 rng(std::random_device {}());
  // random int [1, 80], overflow if average > 80 in the case of N=10.
  std::uniform_int_distribution<long long> dist(1, 80);

  for (int j = 0; j < Num; j++) {
    // an array initilized with [0..N-1].
    std::vector<long long> in(N);
    std::ranges::generate(in, [&]() -> long long { return dist(rng); });

    std::vector<long long> out { CumProdWoTerm(in) };

    long long tmp = 1;
    for (int i = 0; i < N; i++) {
      tmp *= in[i];
    }

    if (Once) {  // test the computation only once.
      // display the results using the division operator.
      std::cout << "input : ";
      for (int i = 0; i < N; i++) {
        std::cout << in[i] << " ";
      }
      std::cout << "\n";

      std::cout << "w. div : ";
      for (int i = 0; i < N; i++) {
        std::cout << tmp / in[i] << " ";
      }
      std::cout << "\n";

      // display the results without using division.
      std::cout << "w/o div : ";
      for (int i = 0; i < N; i++) {
        std::cout << out[i] << " ";
      }
      std::cout << "\n";

    } else {  // test the compuatation multiple times
      bool wrong = false;

      for (int i = 0; i < N; i++) {
        if (tmp / in[i] != out[i]) {
          wrong = true;
        }
      }

      if (wrong) {
        std::cout << "input : ";
        for (int i = 0; i < N; i++) {
          std::cout << in[i] << " ";
        }
        std::cout << "==> " << tmp << "\n";

        tmp = 1;
        std::cout << "multiple : ";
        for (int i = 0; i < N; i++) {
          tmp *= in[i];
          std::cout << tmp << " ";
        }
        std::cout << "==> " << tmp << "\n";
      }
    }
  }
}
