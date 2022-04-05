---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/AtCoder/AGC002D.cpp
    title: test/AtCoder/AGC002D.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/PartiallyPersistentUnionFind.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n#include <utility>\n\nclass PartiallyPersistentUnionFind{\n\
    \  std::vector<int> data;\n  std::vector<int> time;\n  int now;\n  std::vector<std::vector<std::pair<int,int>>>\
    \ size_;\n  std::vector<int> num_connected_components_;\npublic:\n  PartiallyPersistentUnionFind(int\
    \ n) :\n    data(n, -1), time(n,-1), now(0), size_(n,std::vector<std::pair<int,int>>(1,{0,1})),\n\
    \    num_connected_components_(n,0) {}\n  bool unite(int x, int y) noexcept {\n\
    \    ++now;\n    x = find(now,x);\n    y = find(now,y);\n    if(x != y){\n   \
    \   if(data[y] < data[x]) std::swap(x,y);\n      data[x] += data[y];\n      size_[x].emplace_back(now,-data[x]);\n\
    \      data[y] = x;\n      time[y] = now;\n    }\n    return x != y;\n  }\n  bool\
    \ same(int t, int x, int y) noexcept {\n    return find(t,x) == find(t,y);\n \
    \ }\n  int find(int t, int x) noexcept {\n    if(t < time[x]) return x;\n    if(data[x]\
    \ < 0) return x;\n    return find(t,data[x]);\n  }\n  int size(int t, int x) noexcept\
    \ {\n    const int n = data.size();\n    x = find(t,x);\n    return std::prev(std::upper_bound(size_[x].begin(),size_[x].end(),std::make_pair(t,n+1)))->second;\n\
    \  }\n  int num_connected_components(int t) noexcept {\n    return *std::prev(std::upper_bound(num_connected_components_.begin(),num_connected_components_.end(),t));\n\
    \  }\n};\n\n"
  code: "#include <algorithm>\n#include <vector>\n#include <utility>\n\nclass PartiallyPersistentUnionFind{\n\
    \  std::vector<int> data;\n  std::vector<int> time;\n  int now;\n  std::vector<std::vector<std::pair<int,int>>>\
    \ size_;\n  std::vector<int> num_connected_components_;\npublic:\n  PartiallyPersistentUnionFind(int\
    \ n) :\n    data(n, -1), time(n,-1), now(0), size_(n,std::vector<std::pair<int,int>>(1,{0,1})),\n\
    \    num_connected_components_(n,0) {}\n  bool unite(int x, int y) noexcept {\n\
    \    ++now;\n    x = find(now,x);\n    y = find(now,y);\n    if(x != y){\n   \
    \   if(data[y] < data[x]) std::swap(x,y);\n      data[x] += data[y];\n      size_[x].emplace_back(now,-data[x]);\n\
    \      data[y] = x;\n      time[y] = now;\n    }\n    return x != y;\n  }\n  bool\
    \ same(int t, int x, int y) noexcept {\n    return find(t,x) == find(t,y);\n \
    \ }\n  int find(int t, int x) noexcept {\n    if(t < time[x]) return x;\n    if(data[x]\
    \ < 0) return x;\n    return find(t,data[x]);\n  }\n  int size(int t, int x) noexcept\
    \ {\n    const int n = data.size();\n    x = find(t,x);\n    return std::prev(std::upper_bound(size_[x].begin(),size_[x].end(),std::make_pair(t,n+1)))->second;\n\
    \  }\n  int num_connected_components(int t) noexcept {\n    return *std::prev(std::upper_bound(num_connected_components_.begin(),num_connected_components_.end(),t));\n\
    \  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/PartiallyPersistentUnionFind.cpp
  requiredBy:
  - test/AtCoder/AGC002D.cpp
  timestamp: '2022-04-05 23:28:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/PartiallyPersistentUnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/PartiallyPersistentUnionFind.cpp
- /library/DataStructure/PartiallyPersistentUnionFind.cpp.html
title: DataStructure/PartiallyPersistentUnionFind.cpp
---
