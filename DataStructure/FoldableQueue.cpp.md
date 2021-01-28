---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/queue_operate_all_composite.test.cpp
    title: test/LibraryChecker/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/FoldableQueue.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\ntemplate<typename T, typename F>\nstruct FoldableQueue {\n\
    private:\n  const F f;\n  const T ti;\n  T v;\n  std::vector<T> L, R;\npublic:\n\
    \  FoldableQueue(F f, T ti) : f(f), ti(ti), v(ti) {}\n  void push_back(T x){\n\
    \    R.push_back(x);\n    v = f(v,x);\n  }\n  void pop_front(){\n    if(L.size()){\n\
    \      L.pop_back();\n      return;\n    }\n    std::swap(L,R);\n    std::reverse(L.begin(),\
    \ L.end());\n    for(size_t i = 0; i+1 < L.size(); ++i)\n      L[i+1] = f(L[i+1],L[i]);\n\
    \    v = ti;\n    L.pop_back();\n  }\n  T fold(){\n    if(L.size()) return f(L.back(),v);\n\
    \    return v;\n  }\n};\n"
  code: "#include <algorithm>\n#include <vector>\n\ntemplate<typename T, typename\
    \ F>\nstruct FoldableQueue {\nprivate:\n  const F f;\n  const T ti;\n  T v;\n\
    \  std::vector<T> L, R;\npublic:\n  FoldableQueue(F f, T ti) : f(f), ti(ti), v(ti)\
    \ {}\n  void push_back(T x){\n    R.push_back(x);\n    v = f(v,x);\n  }\n  void\
    \ pop_front(){\n    if(L.size()){\n      L.pop_back();\n      return;\n    }\n\
    \    std::swap(L,R);\n    std::reverse(L.begin(), L.end());\n    for(size_t i\
    \ = 0; i+1 < L.size(); ++i)\n      L[i+1] = f(L[i+1],L[i]);\n    v = ti;\n   \
    \ L.pop_back();\n  }\n  T fold(){\n    if(L.size()) return f(L.back(),v);\n  \
    \  return v;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FoldableQueue.cpp
  requiredBy: []
  timestamp: '2020-06-19 16:23:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/queue_operate_all_composite.test.cpp
documentation_of: DataStructure/FoldableQueue.cpp
layout: document
redirect_from:
- /library/DataStructure/FoldableQueue.cpp
- /library/DataStructure/FoldableQueue.cpp.html
title: DataStructure/FoldableQueue.cpp
---
