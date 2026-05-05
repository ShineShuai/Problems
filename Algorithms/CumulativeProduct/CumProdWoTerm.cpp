#include "CumProdWoTerm.hpp"

/********************************************************************
 Given an array a[1..n], construct an array b[1..n] in O(n) time and
 O(1) space, so that b[i]=a[1]*a[2]*..*a[n]/a[i].
 The division operator is not available.
********************************************************************/

auto
CumProdWoTerm(const std::vector<long long> &in) -> std::vector<long long> {
  const auto             N = std::ssize(in);  // ptrdiff_t, signed
  std::vector<long long> out(N, 1);

  if (N == 0) {
    return out;
  }

  // cumulative product from the left. left[i]=a[1]*..*a[i-1]
  for (auto i = 1; i < N; i++) {
    out[i] = out[i - 1] * in[i - 1];
  }

  // cumulative product from the right. right[i]=a[i+1]*..*a[n]
  // multiple both terms to get b[i]=left[i]*right[i]
  long long tmp = 1;
  for (auto i = N - 1; i >= 0; i--) {
    out[i] *= tmp;
    tmp *= in[i];
  }

  return out;
}