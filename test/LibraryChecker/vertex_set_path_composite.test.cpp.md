---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  - icon: ':question:'
    path: Graph/HLD.cpp
    title: Graph/HLD.cpp
  - icon: ':question:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_add_set_path_composite
  bundledCode: "#line 1 \"test/LibraryChecker/vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_set_path_composite\"\
    \n\n#line 1 \"Graph/HLD.cpp\"\n#include <algorithm>\n#include <iostream>\n#include\
    \ <vector>\n#include <utility>\n\ntemplate<typename Tree>\nclass QueryOnRootedTree\
    \ {\n  const int n;\n  const int r;\n  std::vector<int> L, R;\n  std::vector<int>\
    \ depth, parent, A;\n  void build(Tree& T){\n    A[r] = r;\n    reorder(T,r,-1);\n\
    \    int t = 0;\n    dfs(T,r,-1,t);\n  }\n  int reorder(Tree& T, int v, int p){\n\
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
    \  }\n};\n\n#line 2 \"Math/modint.cpp\"\n#include <cassert>\n\ntemplate<long long\
    \ mod>\nclass modint{\nprivate:\n  using T = long long;\n  T a;\npublic:\n  constexpr\
    \ modint(const long long x = 0) noexcept : a((x%mod+mod)%mod) {}\n  constexpr\
    \ T& value() noexcept { return a; }\n  constexpr const T& value() const noexcept\
    \ { return a; }\n  constexpr modint operator-() const noexcept {\n    return modint(0)\
    \ -= *this;\n  }\n  constexpr modint operator+(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) += rhs;\n  }\n  constexpr modint operator-(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr\
    \ modint operator*(const modint& rhs) const noexcept {\n    return modint(*this)\
    \ *= rhs;\n  }\n  constexpr modint operator/(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) /= rhs;\n  }\n  constexpr modint& operator+=(const\
    \ modint& rhs) noexcept {\n    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return\
    \ *this;\n  }\n  constexpr modint& operator-=(const modint& rhs) noexcept {\n\
    \    if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return *this;\n  }\n  constexpr\
    \ modint& operator*=(const modint& rhs) noexcept {\n    a = a*rhs.a%mod;\n   \
    \ return *this;\n  }\n  constexpr modint& operator/=(const modint& rhs) noexcept\
    \ {\n    return *this *= rhs.inv();\n  }\n  constexpr bool operator==(const modint&\
    \ rhs) const noexcept {\n    return a == rhs.a;\n  }\n  constexpr bool operator!=(const\
    \ modint& rhs) const noexcept {\n    return not (*this == rhs);\n  }\n  constexpr\
    \ modint pow(long long k) const noexcept {\n    modint ret(1);\n    modint x =\
    \ k > 0 ? *this : this->inv();\n    k = abs(k);\n    while(k > 0){\n      if(k&1)\
    \ ret *= x;\n      x *= x;\n      k >>= 1;\n    }\n    return ret;\n  }\n  constexpr\
    \ modint inv() const noexcept {\n    return pow(mod-2);\n  }\n  friend std::ostream&\
    \ operator<<(std::ostream &os, const modint &X) noexcept {\n    return os << X.a;\n\
    \  }\n  friend std::istream& operator>>(std::istream &is, modint &X) noexcept\
    \ {\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n    return\
    \ is;\n  }\n};\n#line 6 \"test/LibraryChecker/vertex_set_path_composite.test.cpp\"\
    \n\n#line 8 \"test/LibraryChecker/vertex_set_path_composite.test.cpp\"\nusing\
    \ namespace std;\n\nint main(){\n  using mint = modint<998244353>;\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n  int n, q;\n  cin >> n >> q;\n  vector<pair<mint, mint>>\
    \ A;\n  for(int i = 0; i < n; ++i){\n    mint a, b;\n    cin >> a >> b;\n    A.emplace_back(a,b);\n\
    \  }\n  vector<vector<int>> G(n);\n  for(int i = 0; i+1 < n; ++i){\n    int u,\
    \ v;\n    cin >> u >> v;\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n  QueryOnRootedTree hld(G);\n  auto idx = hld.idx();\n  vector<pair<mint,\
    \ mint>> B(n);\n  vector<int> inv(n);\n  for(int i = 0; i < n; ++i){\n    B[i]\
    \ = A[idx[i]];\n    inv[idx[i]] = i;\n  }\n\n  auto f = [](pair<mint, mint> a,\
    \ pair<mint, mint> b){\n    auto [x,y] = a;\n    auto [z,w] = b;\n    return pair(z*x,z*y+w);\n\
    \  };\n\n  auto r = [](pair<mint, mint> a, pair<mint, mint> b){\n    auto [x,y]\
    \ = a;\n    auto [z,w] = b;\n    return pair(x*z,x*w+y);\n  };\n\n  pair<mint,mint>\
    \ id(1,0);\n  SegmentTree F(f,id);\n  SegmentTree R(r,id);\n  F.build(B);\n  R.build(B);\n\
    \  \n  while(q--){\n    int t;\n    cin >> t;\n    if(t){\n      int from, to;\n\
    \      mint x;\n      cin >> from >> to >> x;\n      auto ret = hld.path(from,to);\n\
    \      // cerr << from << \" -> \" << to << \" : \";\n      pair<mint,mint> ans(1,0);\n\
    \      for(auto [l,r]: ret){\n        auto t = (l < r ? F.query(l,r+1) : R.query(r,l+1));\n\
    \        ans = f(ans,t);\n      }\n      auto [a,b] = ans;\n      cout << a*x+b\
    \ << '\\n';\n    }else{\n      int p;\n      mint c, d;\n      cin >> p >> c >>\
    \ d;\n      p = inv[p];\n      F.set_val(p,pair(c,d));\n      R.set_val(p,pair(c,d));\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_set_path_composite\"\
    \n\n#include \"Graph/HLD.cpp\"\n#include \"DataStructure/SegmentTree.cpp\"\n#include\
    \ \"Math/modint.cpp\"\n\n#include <utility>\nusing namespace std;\n\nint main(){\n\
    \  using mint = modint<998244353>;\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<pair<mint, mint>> A;\n  for(int i = 0;\
    \ i < n; ++i){\n    mint a, b;\n    cin >> a >> b;\n    A.emplace_back(a,b);\n\
    \  }\n  vector<vector<int>> G(n);\n  for(int i = 0; i+1 < n; ++i){\n    int u,\
    \ v;\n    cin >> u >> v;\n    G[u].emplace_back(v);\n    G[v].emplace_back(u);\n\
    \  }\n  QueryOnRootedTree hld(G);\n  auto idx = hld.idx();\n  vector<pair<mint,\
    \ mint>> B(n);\n  vector<int> inv(n);\n  for(int i = 0; i < n; ++i){\n    B[i]\
    \ = A[idx[i]];\n    inv[idx[i]] = i;\n  }\n\n  auto f = [](pair<mint, mint> a,\
    \ pair<mint, mint> b){\n    auto [x,y] = a;\n    auto [z,w] = b;\n    return pair(z*x,z*y+w);\n\
    \  };\n\n  auto r = [](pair<mint, mint> a, pair<mint, mint> b){\n    auto [x,y]\
    \ = a;\n    auto [z,w] = b;\n    return pair(x*z,x*w+y);\n  };\n\n  pair<mint,mint>\
    \ id(1,0);\n  SegmentTree F(f,id);\n  SegmentTree R(r,id);\n  F.build(B);\n  R.build(B);\n\
    \  \n  while(q--){\n    int t;\n    cin >> t;\n    if(t){\n      int from, to;\n\
    \      mint x;\n      cin >> from >> to >> x;\n      auto ret = hld.path(from,to);\n\
    \      // cerr << from << \" -> \" << to << \" : \";\n      pair<mint,mint> ans(1,0);\n\
    \      for(auto [l,r]: ret){\n        auto t = (l < r ? F.query(l,r+1) : R.query(r,l+1));\n\
    \        ans = f(ans,t);\n      }\n      auto [a,b] = ans;\n      cout << a*x+b\
    \ << '\\n';\n    }else{\n      int p;\n      mint c, d;\n      cin >> p >> c >>\
    \ d;\n      p = inv[p];\n      F.set_val(p,pair(c,d));\n      R.set_val(p,pair(c,d));\n\
    \    }\n  }\n}\n"
  dependsOn:
  - Graph/HLD.cpp
  - DataStructure/SegmentTree.cpp
  - Math/modint.cpp
  isVerificationFile: true
  path: test/LibraryChecker/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 01:31:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/vertex_set_path_composite.test.cpp
- /verify/test/LibraryChecker/vertex_set_path_composite.test.cpp.html
title: test/LibraryChecker/vertex_set_path_composite.test.cpp
---
