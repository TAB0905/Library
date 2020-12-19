---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/unionfind.test.cpp
    title: test/LibraryChecker/unionfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\n#include <vector>\n\nstruct\
    \ UnionFind{\n  std::vector<int> data;\n  UnionFind(int n) : data(n, -1) {}\n\
    \  bool unite(int x, int y){\n    x = find(x);\n    y = find(y);\n    if(x !=\
    \ y){\n      if(data[y] < data[x]) std::swap(x,y);\n      data[x] += data[y];//\u9AD8\
    \u3055\u3092\u66F4\u65B0\n      data[y] = x;//\u89AA\u3092\u66F4\u65B0\n    }\n\
    \    return x != y;\n  }\n  bool same(int x, int y){ return find(x) == find(y);\
    \ }\n  int find(int x){\n    if(data[x] < 0) return x;\n    return data[x] = find(data[x]);\n\
    \  }\n};\n\n"
  code: "#include <vector>\n\nstruct UnionFind{\n  std::vector<int> data;\n  UnionFind(int\
    \ n) : data(n, -1) {}\n  bool unite(int x, int y){\n    x = find(x);\n    y =\
    \ find(y);\n    if(x != y){\n      if(data[y] < data[x]) std::swap(x,y);\n   \
    \   data[x] += data[y];//\u9AD8\u3055\u3092\u66F4\u65B0\n      data[y] = x;//\u89AA\
    \u3092\u66F4\u65B0\n    }\n    return x != y;\n  }\n  bool same(int x, int y){\
    \ return find(x) == find(y); }\n  int find(int x){\n    if(data[x] < 0) return\
    \ x;\n    return data[x] = find(data[x]);\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2020-05-09 15:40:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_1_A.test.cpp
  - test/LibraryChecker/unionfind.test.cpp
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: DataStructure/UnionFind.cpp
---
