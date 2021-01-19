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
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\n#include <vector>\n\nclass\
    \ UnionFind{\n  std::vector<int> data;\n  int num_connected_components_;\npublic:\n\
    \  UnionFind(int n) : data(n, -1), num_connected_components_(n) {}\n  bool unite(int\
    \ x, int y) noexcept {\n    x = find(x);\n    y = find(y);\n    if(x != y){\n\
    \      --num_connected_components_;\n      if(data[y] < data[x]) std::swap(x,y);\n\
    \      data[x] += data[y];\n      data[y] = x;\n    }\n    return x != y;\n  }\n\
    \  bool same(int x, int y) noexcept {\n    return find(x) == find(y);\n  }\n \
    \ int find(int x) noexcept {\n    if(data[x] < 0) return x;\n    return data[x]\
    \ = find(data[x]);\n  }\n  int size(int x) noexcept {\n    return -data[find(x)];\n\
    \  }\n  int num_connected_components() const noexcept {\n    return num_connected_components_;\n\
    \  }\n};\n\n"
  code: "#include <vector>\n\nclass UnionFind{\n  std::vector<int> data;\n  int num_connected_components_;\n\
    public:\n  UnionFind(int n) : data(n, -1), num_connected_components_(n) {}\n \
    \ bool unite(int x, int y) noexcept {\n    x = find(x);\n    y = find(y);\n  \
    \  if(x != y){\n      --num_connected_components_;\n      if(data[y] < data[x])\
    \ std::swap(x,y);\n      data[x] += data[y];\n      data[y] = x;\n    }\n    return\
    \ x != y;\n  }\n  bool same(int x, int y) noexcept {\n    return find(x) == find(y);\n\
    \  }\n  int find(int x) noexcept {\n    if(data[x] < 0) return x;\n    return\
    \ data[x] = find(data[x]);\n  }\n  int size(int x) noexcept {\n    return -data[find(x)];\n\
    \  }\n  int num_connected_components() const noexcept {\n    return num_connected_components_;\n\
    \  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-01-19 15:33:43+09:00'
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
