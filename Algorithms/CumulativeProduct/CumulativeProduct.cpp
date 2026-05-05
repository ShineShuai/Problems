#include <algorithm>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

#include "CumProdWoTerm.hpp"

/********************************************************************
 Given an array a[1..n], construct an array b[1..n] in O(n) time and
 O(1) space, so that b[i]=a[1]*a[2]*..*a[n]/a[i].
 The division operator is not available.
********************************************************************/

namespace {

  void
  PrintVec(std::string_view label, const std::vector<long long> &v) {
    std::cout << label << " : ";
    for (const auto x : v) {
      std::cout << x << ' ';
    }
    std::cout << '\n';
  }

}  // namespace

auto
main() -> int {               // NOLINT(bugprone-exception-escape)
  constexpr int N    = 10;    // number of elements, N > 0
  constexpr int Runs = 1000;  // set to 1 for single-run display mode

  std::mt19937 rng(std::random_device {}());
  // random int [1, 80], overflow if average > 80 in the case of N=10.
  std::uniform_int_distribution<long long> dist(1, 80);

  for (int j = 0; j < Runs; j++) {
    // an array initilized with [0..N-1].
    std::vector<long long> in(N);
    std::ranges::generate(in, [&]() -> long long { return dist(rng); });

    std::vector<long long> out { CumProdWoTerm(in) };

    long long total =
        std::accumulate(in.begin(), in.end(), 1LL, std::multiplies<>());
    std::vector<long long> expected(N);
    std::ranges::transform(in, expected.begin(),
                           [&](long long x) -> long long { return total / x; });

    const bool correct = std::ranges::equal(out, expected);

    if (Runs == 1 && correct) {
      PrintVec("input  ", in);
      PrintVec("w.  div", expected);
      PrintVec("w/o div", out);
    } else if (!correct) {
      PrintVec("FAIL input   ", in);
      PrintVec("FAIL expected", expected);
      PrintVec("FAIL got     ", out);
    }
  }
}
