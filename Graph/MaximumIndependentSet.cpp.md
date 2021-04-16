---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/MaximumIndependentSet.test.cpp
    title: test/LibraryChecker/MaximumIndependentSet.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/MaximumIndependentSet.cpp\"\n#include <utility>\n\
    #include <iostream>\n#include <vector>\n\n// n = G.size() <= 63 \u3058\u3083\u306A\
    \u3044\u3068\u58CA\u308C\u308B\n// \u7AF6\u30D7\u30ED TL 2sec \u304F\u3089\u3044\
    \u306A\u3089\u56F0\u308B\u3053\u3068\u306F\u306A\u3044\u306F\u305A\nlong long\
    \ maximum_independent_set_size(const std::vector<long long>& G, int v, long long\
    \ int t=0){\n  const int n = G.size();\n  if(v >= n or t == (1LL<<n) - 1LL) return\
    \ 0;\n\n  long long ret = 0;\n  if(!(t>>v & 1)){\n    long long t_ = t | (1LL<<v);\n\
    \    t_ |= G[v];\n    int v_ = v + 1;\n    while(t_>>v_ & 1) ++v_;\n    ret =\
    \ maximum_independent_set_size(G,v_,t_)|1LL<<v;\n    if(__builtin_popcountll(t^t_)\
    \ <= 2) return ret; // d(v) <= 1\n  }\n  int v_ = v + 1;\n  while(t>>v_ & 1) ++v_;\n\
    \  t |= 1LL<<v;\n  long long ret_ = maximum_independent_set_size(G,v_,t);\n  if(__builtin_popcountll(ret)\
    \ < __builtin_popcountll(ret_))\n    std::swap(ret,ret_);\n  return ret;\n}\n"
  code: "#include <utility>\n#include <iostream>\n#include <vector>\n\n// n = G.size()\
    \ <= 63 \u3058\u3083\u306A\u3044\u3068\u58CA\u308C\u308B\n// \u7AF6\u30D7\u30ED\
    \ TL 2sec \u304F\u3089\u3044\u306A\u3089\u56F0\u308B\u3053\u3068\u306F\u306A\u3044\
    \u306F\u305A\nlong long maximum_independent_set_size(const std::vector<long long>&\
    \ G, int v, long long int t=0){\n  const int n = G.size();\n  if(v >= n or t ==\
    \ (1LL<<n) - 1LL) return 0;\n\n  long long ret = 0;\n  if(!(t>>v & 1)){\n    long\
    \ long t_ = t | (1LL<<v);\n    t_ |= G[v];\n    int v_ = v + 1;\n    while(t_>>v_\
    \ & 1) ++v_;\n    ret = maximum_independent_set_size(G,v_,t_)|1LL<<v;\n    if(__builtin_popcountll(t^t_)\
    \ <= 2) return ret; // d(v) <= 1\n  }\n  int v_ = v + 1;\n  while(t>>v_ & 1) ++v_;\n\
    \  t |= 1LL<<v;\n  long long ret_ = maximum_independent_set_size(G,v_,t);\n  if(__builtin_popcountll(ret)\
    \ < __builtin_popcountll(ret_))\n    std::swap(ret,ret_);\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MaximumIndependentSet.cpp
  requiredBy: []
  timestamp: '2021-04-16 16:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/MaximumIndependentSet.test.cpp
documentation_of: Graph/MaximumIndependentSet.cpp
layout: document
redirect_from:
- /library/Graph/MaximumIndependentSet.cpp
- /library/Graph/MaximumIndependentSet.cpp.html
title: Graph/MaximumIndependentSet.cpp
---
