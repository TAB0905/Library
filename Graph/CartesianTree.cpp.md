---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/cartesian_tree.test.cpp
    title: test/LibraryChecker/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/CartesianTree.cpp\"\n#include <vector>\n\ntemplate<typename\
    \ T>\nstd::vector<int> cartesian_tree(const std::vector<T>& A){\n  const int n\
    \ = A.size();\n  std::vector<int> P(n);\n  P[0] = -1;\n  for(int i = 1; i < n;\
    \ ++i){\n    P[i] = i-1;\n    int p = i-1, l = -1;\n    while(p >= 0 and A[p]\
    \ > A[i]){\n      P[i] = P[p];\n      P[p] = i;\n      if(l >= 0) P[l] = p;\n\
    \      l = p;\n      p = P[i];\n    }\n  }\n  return P;\n}\n\n"
  code: "#include <vector>\n\ntemplate<typename T>\nstd::vector<int> cartesian_tree(const\
    \ std::vector<T>& A){\n  const int n = A.size();\n  std::vector<int> P(n);\n \
    \ P[0] = -1;\n  for(int i = 1; i < n; ++i){\n    P[i] = i-1;\n    int p = i-1,\
    \ l = -1;\n    while(p >= 0 and A[p] > A[i]){\n      P[i] = P[p];\n      P[p]\
    \ = i;\n      if(l >= 0) P[l] = p;\n      l = p;\n      p = P[i];\n    }\n  }\n\
    \  return P;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/CartesianTree.cpp
  requiredBy: []
  timestamp: '2021-10-15 01:32:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/cartesian_tree.test.cpp
documentation_of: Graph/CartesianTree.cpp
layout: document
redirect_from:
- /library/Graph/CartesianTree.cpp
- /library/Graph/CartesianTree.cpp.html
title: Graph/CartesianTree.cpp
---
