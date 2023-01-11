---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/LibraryChecker/static_rmq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <iostream>\n#include\
    \ <vector>\n#line 3 \"DataStructure/SegmentTree.cpp\"\n#include <climits>\n#include\
    \ <functional>\n\ntemplate <typename T, typename F>\nstruct SegmentTree{\nprivate:\n\
    \  // using F = std::function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n  std::vector<T>\
    \ dat;\npublic:\n  SegmentTree(){};\n  SegmentTree(F f,T ti) : f(f), ti(ti) {}\n\
    \  void build(int n_){\n    n = n_;\n    dat.assign(2*n,ti);\n  }\n  void build(const\
    \ std::vector<T> &v){\n    int n_ = v.size();\n    build(n_);\n    for(int i =\
    \ 0; i < n; ++i) dat[n+i] = v[i];\n    for(int i = n-1; i >= 0; --i)\n      dat[i]\
    \ = f(dat[2*i+0], dat[2*i+1]);\n  }\n  void set_val(int k, T x){\n    dat[k+=n]\
    \ = x;\n    while(k > 0){\n      k = k/2;\n      dat[k] = f(dat[2*k+0], dat[2*k+1]);\n\
    \    }\n  }\n  T query(int a, int b){ // [l,r)\n    if(a == b) return ti;\n  \
    \  T vl = ti, vr = ti;\n    for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){\n\
    \      if(l&1) vl = f(vl, dat[l++]);\n      if(r&1) vr = f(dat[--r], vr);\n  \
    \  }\n    return f(vl, vr);\n  }\n};\n\n#line 6 \"test/LibraryChecker/static_rmq.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int N, Q;\n  cin >> N >> Q;\n  vector<int> A(N);\n  for(int i = 0; i <\
    \ N; ++i){\n    cin >> A[i];\n  }\n  const int INF = 1e9;\n  SegmentTree rmq([](int\
    \ a, int b){return min(a,b);},INF);\n  rmq.build(A);\n  while(Q--){\n    int l,\
    \ r;\n    cin >> l >> r;\n    cout << rmq.query(l,r) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"DataStructure/SegmentTree.cpp\"\n\
    using namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int N, Q;\n  cin >> N >> Q;\n  vector<int> A(N);\n  for(int i = 0; i <\
    \ N; ++i){\n    cin >> A[i];\n  }\n  const int INF = 1e9;\n  SegmentTree rmq([](int\
    \ a, int b){return min(a,b);},INF);\n  rmq.build(A);\n  while(Q--){\n    int l,\
    \ r;\n    cin >> l >> r;\n    cout << rmq.query(l,r) << '\\n';\n  }\n}\n"
  dependsOn:
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: test/LibraryChecker/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2022-04-08 13:37:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/static_rmq.test.cpp
- /verify/test/LibraryChecker/static_rmq.test.cpp.html
title: test/LibraryChecker/static_rmq.test.cpp
---
