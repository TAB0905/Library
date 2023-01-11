---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/HLD.cpp
    title: Graph/HLD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/LibraryChecker/vertex_add_path_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"\
    Graph/HLD.cpp\"\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\
    #include <utility>\n\ntemplate<typename Tree>\nclass QueryOnRootedTree {\n  const\
    \ int n;\n  const int r;\n  std::vector<int> L, R;\n  std::vector<int> depth,\
    \ parent, A;\n  void build(Tree& T){\n    A[r] = r;\n    reorder(T,r,-1);\n  \
    \  int t = 0;\n    dfs(T,r,-1,t);\n  }\n  int reorder(Tree& T, int v, int p){\n\
    \    std::vector<int> subtree_size;\n    int s = 1;\n    parent[v] = p;\n    for(auto\
    \ u: T[v]){\n      if(u == p){\n        subtree_size.emplace_back(0);\n      \
    \  continue;\n      }\n      int s_ = reorder(T,u,v);\n      subtree_size.emplace_back(s_);\n\
    \      s += s_;\n    }\n    if(T[v].size() > 1){\n      int heavy = std::max_element(subtree_size.begin(),subtree_size.end())\
    \ - subtree_size.begin();\n      std::swap(T[v][0],T[v][heavy]);\n    }\n    return\
    \ s;\n  }\n  void dfs(const Tree& T, int v, int p, int& t){\n    L[v] = t++;\n\
    \    // std::cerr << p << ' ' << v << '\\n';\n    for(auto u: T[v]){\n      if(u\
    \ == p) continue;\n      A[u] = (u == T[v][0] ? A[v] : u);\n      depth[u] = depth[v]\
    \ + 1;\n      dfs(T,u,v,t);\n    }\n    R[v] = t;\n  }\npublic:\n  QueryOnRootedTree(Tree\
    \ T, int r=0) :\n    n(T.size()), r(r), L(n), R(n), depth(n), parent(n), A(n)\
    \ {\n    build(T);\n  }\n  std::vector<int> idx(){\n    std::vector<int> ret(n);\n\
    \    for(size_t i = 0; i < n; ++i){\n      ret[L[i]] = i;\n    }\n    return ret;\n\
    \  }\n  std::pair<int,int> subtree(int v){\n    return std::pair(L[v],R[v]);\n\
    \  }\n  std::vector<std::pair<int,int>> path(int from, int to){ // [li, ri]\n\
    \    std::vector<std::pair<int,int>> up, down;\n    int u = from, v = to;\n  \
    \  // std::cerr << u << ' ' << A[u] << ' ' << v << ' ' << A[v] << '\\n';\n   \
    \ while(A[u] != A[v]){\n      if(depth[A[u]] < depth[A[v]]){\n        down.emplace_back(L[A[v]],\
    \ L[v]);\n        v = parent[A[v]];\n      }else{\n        up.emplace_back(L[u],\
    \ L[A[u]]);\n        u = parent[A[u]];\n      }\n    }\n    // std::cerr << u\
    \ << ' ' << A[u] << ' ' << v << ' ' << A[v] << '\\n';\n    if(depth[u] <= depth[v]){\n\
    \      up.emplace_back(L[u],L[v]);\n    }\n    if(depth[v] < depth[u]){\n    \
    \  up.emplace_back(L[u],L[v]);\n    }\n    up.insert(up.end(),down.rbegin(),down.rend());\n\
    \    return up;\n  }\n  void debug(){\n    std::cerr << \"n: \" << n << '\\n';\n\
    \    std::cerr << \"A: \";\n    for(int i = 0; i < n; ++i)\n      std::cerr <<\
    \ A[i] << ' ';\n    std::cerr << '\\n';\n  }\n};\n#line 3 \"DataStructure/SegmentTree.cpp\"\
    \n#include <climits>\n#include <functional>\n\ntemplate <typename T, typename\
    \ F>\nstruct SegmentTree{\nprivate:\n  // using F = std::function<T(T,T)>;\n \
    \ int n;\n  F f;\n  T ti;\n  std::vector<T> dat;\npublic:\n  SegmentTree(){};\n\
    \  SegmentTree(F f,T ti) : f(f), ti(ti) {}\n  void build(int n_){\n    n = n_;\n\
    \    dat.assign(2*n,ti);\n  }\n  void build(const std::vector<T> &v){\n    int\
    \ n_ = v.size();\n    build(n_);\n    for(int i = 0; i < n; ++i) dat[n+i] = v[i];\n\
    \    for(int i = n-1; i >= 0; --i)\n      dat[i] = f(dat[2*i+0], dat[2*i+1]);\n\
    \  }\n  void set_val(int k, T x){\n    dat[k+=n] = x;\n    while(k > 0){\n   \
    \   k = k/2;\n      dat[k] = f(dat[2*k+0], dat[2*k+1]);\n    }\n  }\n  T query(int\
    \ a, int b){ // [l,r)\n    if(a == b) return ti;\n    T vl = ti, vr = ti;\n  \
    \  for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){\n      if(l&1) vl = f(vl,\
    \ dat[l++]);\n      if(r&1) vr = f(dat[--r], vr);\n    }\n    return f(vl, vr);\n\
    \  }\n};\n\n#line 5 \"test/LibraryChecker/vertex_add_path_sum.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<long long> A(n);\n  for(int i = 0; i\
    \ < n; ++i)\n    cin >> A[i];\n  vector<vector<int>> G(n);\n  for(int i = 0; i+1\
    \ < n; ++i){\n    int u, v;\n    cin >> u >> v;\n    G[u].emplace_back(v);\n \
    \   G[v].emplace_back(u);\n  }\n  QueryOnRootedTree hld(G);\n  auto idx = hld.idx();\n\
    \  // for(auto e: idx)\n  //   cerr << e << ' ';\n  // cerr << endl;\n  // hld.debug();\n\
    \  vector<long long> B(n), R(n);\n  for(int i = 0; i < n; ++i){\n    B[i] = A[idx[i]];\n\
    \    R[idx[i]] = i;\n  }\n  SegmentTree range_sum([](long long a, long long b){return\
    \ a+b;},0LL);\n  range_sum.build(B);\n\n  while(q--){\n    int t;\n    cin >>\
    \ t;\n    if(t){\n      int from, to;\n      cin >> from >> to;\n      auto ret\
    \ = hld.path(from,to);\n      // cerr << from << \" -> \" << to << \" : \";\n\
    \      long long ans = 0;\n      for(auto [l,r]: ret){\n        if(r < l) swap(l,r);\n\
    \        // cerr << \"(\" << l << \", \" << r << \") \";\n        ans += range_sum.query(l,r+1);\n\
    \      }\n      // cerr << \" = \";\n      cout << ans << '\\n';\n    }else{\n\
    \      int p;\n      long long x;\n      cin >> p >> x;\n      p = R[p];\n   \
    \   long long ap = range_sum.query(p,p+1);\n      range_sum.set_val(p,ap+x);\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"Graph/HLD.cpp\"\n#include \"DataStructure/SegmentTree.cpp\"\n\nusing\
    \ namespace std;\n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<long long> A(n);\n  for(int i = 0; i\
    \ < n; ++i)\n    cin >> A[i];\n  vector<vector<int>> G(n);\n  for(int i = 0; i+1\
    \ < n; ++i){\n    int u, v;\n    cin >> u >> v;\n    G[u].emplace_back(v);\n \
    \   G[v].emplace_back(u);\n  }\n  QueryOnRootedTree hld(G);\n  auto idx = hld.idx();\n\
    \  // for(auto e: idx)\n  //   cerr << e << ' ';\n  // cerr << endl;\n  // hld.debug();\n\
    \  vector<long long> B(n), R(n);\n  for(int i = 0; i < n; ++i){\n    B[i] = A[idx[i]];\n\
    \    R[idx[i]] = i;\n  }\n  SegmentTree range_sum([](long long a, long long b){return\
    \ a+b;},0LL);\n  range_sum.build(B);\n\n  while(q--){\n    int t;\n    cin >>\
    \ t;\n    if(t){\n      int from, to;\n      cin >> from >> to;\n      auto ret\
    \ = hld.path(from,to);\n      // cerr << from << \" -> \" << to << \" : \";\n\
    \      long long ans = 0;\n      for(auto [l,r]: ret){\n        if(r < l) swap(l,r);\n\
    \        // cerr << \"(\" << l << \", \" << r << \") \";\n        ans += range_sum.query(l,r+1);\n\
    \      }\n      // cerr << \" = \";\n      cout << ans << '\\n';\n    }else{\n\
    \      int p;\n      long long x;\n      cin >> p >> x;\n      p = R[p];\n   \
    \   long long ap = range_sum.query(p,p+1);\n      range_sum.set_val(p,ap+x);\n\
    \    }\n  }\n}\n"
  dependsOn:
  - Graph/HLD.cpp
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: test/LibraryChecker/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 00:54:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/vertex_add_path_sum.test.cpp
- /verify/test/LibraryChecker/vertex_add_path_sum.test.cpp.html
title: test/LibraryChecker/vertex_add_path_sum.test.cpp
---
