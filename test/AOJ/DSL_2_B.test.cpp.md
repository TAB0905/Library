---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
  bundledCode: "#line 1 \"test/AOJ/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n\n#include <iostream>\n#line 1 \"DataStructure/SegmentTree.cpp\"\n#include <vector>\n\
    #line 3 \"DataStructure/SegmentTree.cpp\"\n#include <climits>\n#include <functional>\n\
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
    \ f(vl, vr);\n  }\n};\n\n#line 5 \"test/AOJ/DSL_2_B.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  int n, q;\n  cin >> n >> q;\n  using T = long long;\n\
    \  SegmentTree<T> rsq([](T a, T b){return a+b;},0LL);\n  rsq.build(n);\n  while(q--){\n\
    \    int c, x, y;\n    cin >> c >> x >> y;\n    if(c){\n      --x,--y;\n     \
    \ cout << rsq.query(x,y+1) << endl;\n    }else{\n      --x;\n      long long t\
    \ = rsq.query(x,x+1);\n      rsq.set_val(x,t+y);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n\n#include <iostream>\n#include \"DataStructure/SegmentTree.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  int n, q;\n  cin >> n >> q;\n  using T = long long;\n\
    \  SegmentTree<T> rsq([](T a, T b){return a+b;},0LL);\n  rsq.build(n);\n  while(q--){\n\
    \    int c, x, y;\n    cin >> c >> x >> y;\n    if(c){\n      --x,--y;\n     \
    \ cout << rsq.query(x,y+1) << endl;\n    }else{\n      --x;\n      long long t\
    \ = rsq.query(x,x+1);\n      rsq.set_val(x,t+y);\n    }\n  }\n}\n"
  dependsOn:
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 17:06:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_B.test.cpp
- /verify/test/AOJ/DSL_2_B.test.cpp.html
title: test/AOJ/DSL_2_B.test.cpp
---
