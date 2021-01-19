---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/LibraryChecker/static_range_sum.test.cpp
    title: test/LibraryChecker/static_range_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/CumulativeSum.cpp\"\n#include <vector>\n#include\
    \ <numeric>\n\ntemplate<typename T>\nstruct CumSum{\nprivate:\n  const size_t\
    \ size;\n  std::vector<T> data;\npublic:\n  CumSum(const std::vector<T>& dat)\
    \ : size(dat.size()), data(dat) {\n    data.emplace_back(0);\n    exclusive_scan(data.begin(),data.end(),data.begin(),static_cast<T>(0));\n\
    \  }\n  T getsum(size_t l, size_t r) const noexcept {//0-indexed, [l,r)\n    return\
    \ data[r] - data[l];\n  }\n  T getsum(size_t r) const noexcept {//0-indexed, [0,r)\n\
    \    return data[r];\n  }\n};\n"
  code: "#include <vector>\n#include <numeric>\n\ntemplate<typename T>\nstruct CumSum{\n\
    private:\n  const size_t size;\n  std::vector<T> data;\npublic:\n  CumSum(const\
    \ std::vector<T>& dat) : size(dat.size()), data(dat) {\n    data.emplace_back(0);\n\
    \    exclusive_scan(data.begin(),data.end(),data.begin(),static_cast<T>(0));\n\
    \  }\n  T getsum(size_t l, size_t r) const noexcept {//0-indexed, [l,r)\n    return\
    \ data[r] - data[l];\n  }\n  T getsum(size_t r) const noexcept {//0-indexed, [0,r)\n\
    \    return data[r];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2021-01-19 15:33:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/LibraryChecker/static_range_sum.test.cpp
documentation_of: DataStructure/CumulativeSum.cpp
layout: document
redirect_from:
- /library/DataStructure/CumulativeSum.cpp
- /library/DataStructure/CumulativeSum.cpp.html
title: DataStructure/CumulativeSum.cpp
---
