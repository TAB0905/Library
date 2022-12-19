---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/LibraryChecker/vertex_add_subtree_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n\
    #include <iostream>\n#include <vector>\n#include <utility>\n\ntemplate<typename\
    \ Tree>\nclass QueryOnRootedTree {\n  Tree T;\n  int r;\n  std::vector<int> L,\
    \ R;\n  void build(){\n    int t = 0;\n    dfs(r,-1,t);\n  }\n  void dfs(int v,\
    \ int p, int& t){\n    L[v] = t++;\n    for(auto u : T[v]){\n      if(u == p)\
    \ continue;\n      dfs(u,v,t);\n    }\n    R[v] = t;\n  }\npublic:\n  QueryOnRootedTree(Tree\
    \ T, int r=0) : T(T), r(r), L(T.size()), R(T.size()) {\n    build();\n  }\n  std::vector<int>\
    \ idx(){\n    std::vector<int> ret(T.size());\n    for(size_t i = 0; i < T.size();\
    \ ++i){\n      ret[L[i]] = i;\n    }\n    return ret;\n  }\n  std::pair<int,int>\
    \ subtree_of(int v){\n    return std::pair(L[v],R[v]);\n  }\n};\n\n#line 41 \"\
    test/LibraryChecker/vertex_add_subtree_sum.test.cpp\"\n#include <cassert>\n\n\
    template<typename T>\nstruct BIT{//0-indexed\nprivate:\n  std::vector<T> data;\n\
    \  const int n;\npublic:\n  BIT(int sz) : data(sz+1,0), n(sz) {}\n\n  T sum(size_t\
    \ i) const noexcept {//sum[0,i)\n    //++i;\n    T s = 0;\n    while(i > 0){\n\
    \      s += data[i];\n      i -= i&(-i);\n    }\n    return s;\n  }\n\n  T sum(size_t\
    \ i, size_t j) const noexcept {// sum[i,j)\n    return sum(j) - sum(i);\n  }\n\
    \n  void add(int i, T x) noexcept {\n    ++i;\n    assert(i > 0);\n    while(i\
    \ <= n){\n      data[i] += x;\n      i += i&(-i);\n    }\n  }\n};\n\n\nusing namespace\
    \ std;\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n \
    \ \n  int n, q;\n  cin >> n >> q;\n  vector<long long> A(n);\n  for(int i = 0;\
    \ i < n; ++i)\n    cin >> A[i];\n  vector<vector<int>> G(n);\n  for(int i = 1;\
    \ i < n; ++i){\n    int p;\n    cin >> p;\n    G[p].emplace_back(i);\n  }\n  QueryOnRootedTree\
    \ Q(G,0);\n  BIT<long long> bit(n);\n  auto idx = Q.idx();\n  for(int i = 0; i\
    \ < n; ++i){\n    bit.add(i,A[idx[i]]);\n  }\n  while(q--){\n    int t, u;\n \
    \   cin >> t >> u;\n    auto [l,r] = Q.subtree_of(u);\n    if(t){\n      cout\
    \ << bit.sum(l,r) << '\\n';\n    }else{\n      long long x;\n      cin >> x;\n\
    \      bit.add(l,x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n\ntemplate<typename\
    \ Tree>\nclass QueryOnRootedTree {\n  Tree T;\n  int r;\n  std::vector<int> L,\
    \ R;\n  void build(){\n    int t = 0;\n    dfs(r,-1,t);\n  }\n  void dfs(int v,\
    \ int p, int& t){\n    L[v] = t++;\n    for(auto u : T[v]){\n      if(u == p)\
    \ continue;\n      dfs(u,v,t);\n    }\n    R[v] = t;\n  }\npublic:\n  QueryOnRootedTree(Tree\
    \ T, int r=0) : T(T), r(r), L(T.size()), R(T.size()) {\n    build();\n  }\n  std::vector<int>\
    \ idx(){\n    std::vector<int> ret(T.size());\n    for(size_t i = 0; i < T.size();\
    \ ++i){\n      ret[L[i]] = i;\n    }\n    return ret;\n  }\n  std::pair<int,int>\
    \ subtree_of(int v){\n    return std::pair(L[v],R[v]);\n  }\n};\n\n#include <vector>\n\
    #include <cassert>\n\ntemplate<typename T>\nstruct BIT{//0-indexed\nprivate:\n\
    \  std::vector<T> data;\n  const int n;\npublic:\n  BIT(int sz) : data(sz+1,0),\
    \ n(sz) {}\n\n  T sum(size_t i) const noexcept {//sum[0,i)\n    //++i;\n    T\
    \ s = 0;\n    while(i > 0){\n      s += data[i];\n      i -= i&(-i);\n    }\n\
    \    return s;\n  }\n\n  T sum(size_t i, size_t j) const noexcept {// sum[i,j)\n\
    \    return sum(j) - sum(i);\n  }\n\n  void add(int i, T x) noexcept {\n    ++i;\n\
    \    assert(i > 0);\n    while(i <= n){\n      data[i] += x;\n      i += i&(-i);\n\
    \    }\n  }\n};\n\n\nusing namespace std;\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  \n  int n, q;\n  cin >> n >> q;\n  vector<long long> A(n);\n\
    \  for(int i = 0; i < n; ++i)\n    cin >> A[i];\n  vector<vector<int>> G(n);\n\
    \  for(int i = 1; i < n; ++i){\n    int p;\n    cin >> p;\n    G[p].emplace_back(i);\n\
    \  }\n  QueryOnRootedTree Q(G,0);\n  BIT<long long> bit(n);\n  auto idx = Q.idx();\n\
    \  for(int i = 0; i < n; ++i){\n    bit.add(i,A[idx[i]]);\n  }\n  while(q--){\n\
    \    int t, u;\n    cin >> t >> u;\n    auto [l,r] = Q.subtree_of(u);\n    if(t){\n\
    \      cout << bit.sum(l,r) << '\\n';\n    }else{\n      long long x;\n      cin\
    \ >> x;\n      bit.add(l,x);\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2022-12-19 15:30:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/vertex_add_subtree_sum.test.cpp
- /verify/test/LibraryChecker/vertex_add_subtree_sum.test.cpp.html
title: test/LibraryChecker/vertex_add_subtree_sum.test.cpp
---
