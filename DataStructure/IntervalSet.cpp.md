---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2880.test.cpp
    title: test/AOJ/2880.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/IntervalSet.cpp\"\n#include <cassert>\n#include\
    \ <set>\n#include <utility>\n#include <vector>\n\ntemplate<typename T, T INF,\
    \ bool merge=true> // if merge == true then merge [l,m) and [m,r)\nclass IntervalSet\
    \ {\nprivate:\n  using const_iterator = typename std::set<std::pair<T,T>>::const_iterator;\n\
    \  std::set<std::pair<T,T>> data;\npublic:\n  IntervalSet(){\n    data.emplace(INF,INF);\n\
    \    data.emplace(-INF,-INF);\n  }\n  const_iterator begin(){ return data.begin();\
    \ }\n  const_iterator end(){ return data.end(); }\n  const_iterator insert(T l,\
    \ T r){ // [l,r)\n    assert(l <= r);\n    erase(l,r);\n    auto itr = data.lower_bound(std::pair(l,r));//\
    \ *itr == pair(l,r)\n    if(merge and itr->first == r){\n      r = itr->second;\n\
    \      data.erase(itr);\n      itr = data.lower_bound(std::pair(l,r));\n    }\n\
    \    if(merge and std::prev(itr)->second == l){\n      l = std::prev(itr)->first;\n\
    \      data.erase(std::prev(itr));\n    }\n    return data.emplace(l,r).first;\n\
    \  }\n  void erase(T l, T r){ // [l,r)\n    assert(l <= r);\n    auto itr = data.lower_bound(std::pair(l,r));\n\
    \    --itr;\n    std::vector<std::pair<T,T>> d;\n    while(itr != data.end()){\n\
    \      if(itr->first >= r) break;\n      if(itr->second <= l){\n        ++itr;\n\
    \        continue;\n      }\n      d.emplace_back(*itr);\n      ++itr;\n    }\n\
    \    for(auto [li,ri] : d){\n      data.erase(std::pair(li,ri));\n      if(l <=\
    \ li and ri <= r){\n        continue;\n      }\n      if(li < l){\n        data.emplace(li,l);\n\
    \      }\n      if(r < ri){\n        data.emplace(r,ri);\n      }\n    }\n  }\n\
    \  std::pair<T,T> range(T x){\n    auto itr = data.upper_bound(std::pair(x,INF));\n\
    \    --itr;\n    if(itr->second > x) return *itr;\n    return std::pair(x,x);\n\
    \  }\n  bool contained(T x){\n    return x < range(x).second;\n  }\n  bool contained(T\
    \ l, T r){ // [l,r)\n    return r <= range(l).second;\n  }\n};\n\n"
  code: "#include <cassert>\n#include <set>\n#include <utility>\n#include <vector>\n\
    \ntemplate<typename T, T INF, bool merge=true> // if merge == true then merge\
    \ [l,m) and [m,r)\nclass IntervalSet {\nprivate:\n  using const_iterator = typename\
    \ std::set<std::pair<T,T>>::const_iterator;\n  std::set<std::pair<T,T>> data;\n\
    public:\n  IntervalSet(){\n    data.emplace(INF,INF);\n    data.emplace(-INF,-INF);\n\
    \  }\n  const_iterator begin(){ return data.begin(); }\n  const_iterator end(){\
    \ return data.end(); }\n  const_iterator insert(T l, T r){ // [l,r)\n    assert(l\
    \ <= r);\n    erase(l,r);\n    auto itr = data.lower_bound(std::pair(l,r));//\
    \ *itr == pair(l,r)\n    if(merge and itr->first == r){\n      r = itr->second;\n\
    \      data.erase(itr);\n      itr = data.lower_bound(std::pair(l,r));\n    }\n\
    \    if(merge and std::prev(itr)->second == l){\n      l = std::prev(itr)->first;\n\
    \      data.erase(std::prev(itr));\n    }\n    return data.emplace(l,r).first;\n\
    \  }\n  void erase(T l, T r){ // [l,r)\n    assert(l <= r);\n    auto itr = data.lower_bound(std::pair(l,r));\n\
    \    --itr;\n    std::vector<std::pair<T,T>> d;\n    while(itr != data.end()){\n\
    \      if(itr->first >= r) break;\n      if(itr->second <= l){\n        ++itr;\n\
    \        continue;\n      }\n      d.emplace_back(*itr);\n      ++itr;\n    }\n\
    \    for(auto [li,ri] : d){\n      data.erase(std::pair(li,ri));\n      if(l <=\
    \ li and ri <= r){\n        continue;\n      }\n      if(li < l){\n        data.emplace(li,l);\n\
    \      }\n      if(r < ri){\n        data.emplace(r,ri);\n      }\n    }\n  }\n\
    \  std::pair<T,T> range(T x){\n    auto itr = data.upper_bound(std::pair(x,INF));\n\
    \    --itr;\n    if(itr->second > x) return *itr;\n    return std::pair(x,x);\n\
    \  }\n  bool contained(T x){\n    return x < range(x).second;\n  }\n  bool contained(T\
    \ l, T r){ // [l,r)\n    return r <= range(l).second;\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/IntervalSet.cpp
  requiredBy: []
  timestamp: '2022-10-13 18:19:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2880.test.cpp
documentation_of: DataStructure/IntervalSet.cpp
layout: document
redirect_from:
- /library/DataStructure/IntervalSet.cpp
- /library/DataStructure/IntervalSet.cpp.html
title: DataStructure/IntervalSet.cpp
---
