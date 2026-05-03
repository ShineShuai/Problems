#include "CumProdWoTerm.hpp"

#include <boost/ut.hpp>

namespace ut = boost::ut;

// Each algorithm gets its own test suite
ut::suite<"CumProdWoTerm"> cum_prod_wo_term = [] {
  using namespace ut;

  "empty_input"_test = [] {
    std::vector<long long> in {};
    auto                   result = CumProdWoTerm(in);
    expect(result.empty());
  };

  "single_element"_test = [] {
    std::vector<long long> in { 5 };
    auto                   result = CumProdWoTerm(in);
    expect(result.size() == 1_u);
    expect(result[0] == 1_ll);
  };

  "two_elements"_test = [] {
    std::vector<long long> in { 2, 3 };
    auto                   result = CumProdWoTerm(in);
    expect(result[0] == 3_ll);
    expect(result[1] == 2_ll);
  };

  "three_elements"_test = [] {
    std::vector<long long> in { 2, 3, 4 };
    auto                   result = CumProdWoTerm(in);
    expect(result[0] == 12_ll);
    expect(result[1] == 8_ll);
    expect(result[2] == 6_ll);
  };
};