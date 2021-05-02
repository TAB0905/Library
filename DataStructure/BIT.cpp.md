---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/point_add_range_sum.test.cpp
    title: test/LibraryChecker/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BIT.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate<typename T>\nstruct BIT{//0-indexed\nprivate:\n  std::vector<T> data;\n\
    \  const int n;\npublic:\n  BIT(int sz) : data(sz+1,0), n(sz) {}\n\n  T sum(size_t\
    \ i) const noexcept {//sum[0,i)\n    //++i;\n    T s = 0;\n    while(i > 0){\n\
    \      s += data[i];\n      i -= i&(-i);\n    }\n    return s;\n  }\n\n  T sum(size_t\
    \ i, size_t j) const noexcept {// sum[i,j)\n    return sum(j) - sum(i);\n  }\n\
    \n  void add(int i, T x) noexcept {\n    ++i;\n    assert(i > 0);\n    while(i\
    \ <= n){\n      data[i] += x;\n      i += i&(-i);\n    }\n  }\n};\n"
  code: "#include <vector>\n#include <cassert>\n\ntemplate<typename T>\nstruct BIT{//0-indexed\n\
    private:\n  std::vector<T> data;\n  const int n;\npublic:\n  BIT(int sz) : data(sz+1,0),\
    \ n(sz) {}\n\n  T sum(size_t i) const noexcept {//sum[0,i)\n    //++i;\n    T\
    \ s = 0;\n    while(i > 0){\n      s += data[i];\n      i -= i&(-i);\n    }\n\
    \    return s;\n  }\n\n  T sum(size_t i, size_t j) const noexcept {// sum[i,j)\n\
    \    return sum(j) - sum(i);\n  }\n\n  void add(int i, T x) noexcept {\n    ++i;\n\
    \    assert(i > 0);\n    while(i <= n){\n      data[i] += x;\n      i += i&(-i);\n\
    \    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BIT.cpp
  requiredBy: []
  timestamp: '2021-05-02 22:46:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/point_add_range_sum.test.cpp
documentation_of: DataStructure/BIT.cpp
layout: document
redirect_from:
- /library/DataStructure/BIT.cpp
- /library/DataStructure/BIT.cpp.html
title: DataStructure/BIT.cpp
---
