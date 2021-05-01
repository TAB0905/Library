---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_A.test.cpp
    title: test/AOJ/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/static_rmq.test.cpp
    title: test/LibraryChecker/static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <climits>\n#include <functional>\n\ntemplate <typename\
    \ T, typename F>\nstruct SegmentTree{\nprivate:\n  // using F = std::function<T(T,T)>;\n\
    \  int n;\n  F f;\n  T ti;\n  std::vector<T> dat;\npublic:\n  SegmentTree(){};\n\
    \  SegmentTree(F f,T ti) : f(f), ti(ti) {}\n  void build(int n_){\n    n = n_;\n\
    \    dat.assign(2*n,ti);\n  }\n  void build(const std::vector<T> &v){\n    int\
    \ n_ = v.size();\n    build(n_);\n    for(int i = 0; i < n; ++i) dat[n+i] = v[i];\n\
    \    for(int i = n-1; i >= 0; --i)\n      dat[i] = f(dat[2*i+0], dat[2*i+1]);\n\
    \  }\n  void set_val(int k, T x){\n    dat[k+=n] = x;\n    while(k > 0){\n   \
    \   k = k/2;\n      dat[k] = f(dat[2*k+0], dat[2*k+1]);\n    }\n  }\n  T query(int\
    \ a, int b){\n    if(a == b) return ti;\n    T vl = ti, vr = ti;\n    for(int\
    \ l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){\n      if(l&1) vl = f(vl, dat[l++]);\n\
    \      if(r&1) vr = f(dat[--r], vr);\n    }\n    return f(vl, vr);\n  }\n};\n\n"
  code: "#include <vector>\n#include <iostream>\n#include <climits>\n#include <functional>\n\
    \ntemplate <typename T, typename F>\nstruct SegmentTree{\nprivate:\n  // using\
    \ F = std::function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  std::vector<T> dat;\n\
    public:\n  SegmentTree(){};\n  SegmentTree(F f,T ti) : f(f), ti(ti) {}\n  void\
    \ build(int n_){\n    n = n_;\n    dat.assign(2*n,ti);\n  }\n  void build(const\
    \ std::vector<T> &v){\n    int n_ = v.size();\n    build(n_);\n    for(int i =\
    \ 0; i < n; ++i) dat[n+i] = v[i];\n    for(int i = n-1; i >= 0; --i)\n      dat[i]\
    \ = f(dat[2*i+0], dat[2*i+1]);\n  }\n  void set_val(int k, T x){\n    dat[k+=n]\
    \ = x;\n    while(k > 0){\n      k = k/2;\n      dat[k] = f(dat[2*k+0], dat[2*k+1]);\n\
    \    }\n  }\n  T query(int a, int b){\n    if(a == b) return ti;\n    T vl = ti,\
    \ vr = ti;\n    for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){\n      if(l&1)\
    \ vl = f(vl, dat[l++]);\n      if(r&1) vr = f(dat[--r], vr);\n    }\n    return\
    \ f(vl, vr);\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-12-13 17:06:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_A.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/LibraryChecker/static_rmq.test.cpp
documentation_of: DataStructure/SegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cpp
- /library/DataStructure/SegmentTree.cpp.html
title: DataStructure/SegmentTree.cpp
---
