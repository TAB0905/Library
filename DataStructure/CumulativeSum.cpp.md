---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/static_range_sum.test.cpp
    title: test/LibraryChecker/static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/CumulativeSum.cpp\"\n#include <vector>\n\n\
    template<typename T>\nstruct CumSum{\nprivate:\n  size_t size;\n  std::vector<T>\
    \ data;\npublic:\n  CumSum(std::vector<T> dat) : size(dat.size()), data(size+1)\
    \ {\n    for(size_t i = 0; i < size; ++i)\n      data[i+1] = data[i] + dat[i];\n\
    \  }\n  T getsum(size_t l, size_t r){//0-indexed, [l,r)\n    return data[r] -\
    \ data[l];\n  }\n  T getsum(size_t r){//0-indexed, [0,r)\n    return data[r];\n\
    \  }\n};\n"
  code: "#include <vector>\n\ntemplate<typename T>\nstruct CumSum{\nprivate:\n  size_t\
    \ size;\n  std::vector<T> data;\npublic:\n  CumSum(std::vector<T> dat) : size(dat.size()),\
    \ data(size+1) {\n    for(size_t i = 0; i < size; ++i)\n      data[i+1] = data[i]\
    \ + dat[i];\n  }\n  T getsum(size_t l, size_t r){//0-indexed, [l,r)\n    return\
    \ data[r] - data[l];\n  }\n  T getsum(size_t r){//0-indexed, [0,r)\n    return\
    \ data[r];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2022-04-08 13:37:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/static_range_sum.test.cpp
documentation_of: DataStructure/CumulativeSum.cpp
layout: document
redirect_from:
- /library/DataStructure/CumulativeSum.cpp
- /library/DataStructure/CumulativeSum.cpp.html
title: DataStructure/CumulativeSum.cpp
---
