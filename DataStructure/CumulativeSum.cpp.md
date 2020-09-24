---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"DataStructure/CumulativeSum.cpp\"\n#include <vector>\n\n\
    template<typename T>\nstruct CumSum{\nprivate:\n  size_t size;\n  std::vector<T>\
    \ data;\npublic:\n  CumSum(std::vector<T> dat){\n    size = dat.size();\n    data.resize(size+1,0);\n\
    \    for(size_t i = 0; i < size; ++i)\n      data[i+1] = data[i] + dat[i];\n \
    \ }\n  T getsum(size_t l, size_t r){//0-indexed, [l,r)\n    return data[r] - data[l];\n\
    \  }\n  T getsum(size_t r){//0-indexed, [0,r)\n    return data[r];\n  }\n};\n"
  code: "#include <vector>\n\ntemplate<typename T>\nstruct CumSum{\nprivate:\n  size_t\
    \ size;\n  std::vector<T> data;\npublic:\n  CumSum(std::vector<T> dat){\n    size\
    \ = dat.size();\n    data.resize(size+1,0);\n    for(size_t i = 0; i < size; ++i)\n\
    \      data[i+1] = data[i] + dat[i];\n  }\n  T getsum(size_t l, size_t r){//0-indexed,\
    \ [l,r)\n    return data[r] - data[l];\n  }\n  T getsum(size_t r){//0-indexed,\
    \ [0,r)\n    return data[r];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2020-09-24 20:16:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/CumulativeSum.cpp
layout: document
redirect_from:
- /library/DataStructure/CumulativeSum.cpp
- /library/DataStructure/CumulativeSum.cpp.html
title: DataStructure/CumulativeSum.cpp
---
