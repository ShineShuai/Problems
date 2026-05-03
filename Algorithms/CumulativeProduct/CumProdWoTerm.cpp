#include "CumProdWoTerm.hpp"

/********************************************************************
 Given an array a[1..n], construct an array b[1..n] in O(n) time and
 O(1) space, so that b[i]=a[1]*a[2]*..*a[n]/a[i].
 The division operator is not available.
********************************************************************/

std::vector<long long>
CumProdWoTerm(const std::vector<long long> &in) {
  const int              N = in.size();
  std::vector<long long> out(N);

  if (N == 0) {
    return out;
  } else if (N == 1) {
    out[0] = 1;
    return out;
  }

  // cumulative product from the left. left[i]=a[1]*..*a[i-1]
  out[0] = in[0];
  for (int i = 1; i < N - 1; i++) {
    out[i] = out[i - 1] * in[i];
  }
  out[N - 1] = N > 1 ? out[N - 2] : 1;

  // cumulative product from the right. right[i]=a[i+1]*..*a[n]
  // multiple both terms to get b[i]=left[i]*right[i]
  long long tmp = in[N - 1];
  for (int i = N - 2; i > 0; i--) {
    out[i] = out[i - 1] * tmp;
    tmp *= in[i];
  }
  out[0] = tmp;

  return out;
}