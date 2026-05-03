#ifndef CUM_PROD_WO_TERM_HPP
#define CUM_PROD_WO_TERM_HPP

#include <vector>

// Returns the product of all elements except the term at each position.
// out[i] = product of all in[0..N-1] except in[i]
std::vector<long long> CumProdWoTerm(const std::vector<long long> &in);

#endif