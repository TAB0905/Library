---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1330.test.cpp
    title: test/AOJ/1330.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/WeightedUnionFind.cpp\"\n#include <vector>\n\
    #include <utility>\n\nstruct WeightedUnionFind{\n  vector<pair<int, long long>>\
    \ data;\n  WeightedUnionFind(int n) : data(n, pair<int,long long>(-1,0LL)) {}\n\
    \  bool unite(int x, int y, long long w){//weight(y)-weight(x) = w;\n    int x_\
    \ = find(x), y_ = find(y);\n    if(x_ == y_) return false;\n    if(data[y_].first\
    \ < data[x_].first){\n      swap(x_,y_);\n      swap(x,y);\n      w *= -1LL;\n\
    \    }\n    data[x_].first += data[y_].first;\n    data[y_].first = x_;\n    //\
    \ data[y_].second += w + rel_weight(x) - rel_weight(y);\n    data[y_].second +=\
    \ w + data[x].second - data[y].second;\n    return true;\n  }\n  bool same(int\
    \ x, int y){ return find(x) == find(y); }\n  int find(int x){\n    if(data[x].first\
    \ < 0) return x;\n    int p = find(data[x].first);\n    data[x].second += data[data[x].first].second;\n\
    \    data[x].first = p;\n    return data[x].first;\n  }\n  long long rel_weight(int\
    \ x){\n    find(x);\n    return data[x].second;\n  }\n};\n"
  code: "#include <vector>\n#include <utility>\n\nstruct WeightedUnionFind{\n  vector<pair<int,\
    \ long long>> data;\n  WeightedUnionFind(int n) : data(n, pair<int,long long>(-1,0LL))\
    \ {}\n  bool unite(int x, int y, long long w){//weight(y)-weight(x) = w;\n   \
    \ int x_ = find(x), y_ = find(y);\n    if(x_ == y_) return false;\n    if(data[y_].first\
    \ < data[x_].first){\n      swap(x_,y_);\n      swap(x,y);\n      w *= -1LL;\n\
    \    }\n    data[x_].first += data[y_].first;\n    data[y_].first = x_;\n    //\
    \ data[y_].second += w + rel_weight(x) - rel_weight(y);\n    data[y_].second +=\
    \ w + data[x].second - data[y].second;\n    return true;\n  }\n  bool same(int\
    \ x, int y){ return find(x) == find(y); }\n  int find(int x){\n    if(data[x].first\
    \ < 0) return x;\n    int p = find(data[x].first);\n    data[x].second += data[data[x].first].second;\n\
    \    data[x].first = p;\n    return data[x].first;\n  }\n  long long rel_weight(int\
    \ x){\n    find(x);\n    return data[x].second;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WeightedUnionFind.cpp
  requiredBy: []
  timestamp: '2022-12-03 23:03:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1330.test.cpp
documentation_of: DataStructure/WeightedUnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/WeightedUnionFind.cpp
- /library/DataStructure/WeightedUnionFind.cpp.html
title: DataStructure/WeightedUnionFind.cpp
---