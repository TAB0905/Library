---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/LCA.cpp
    title: Graph/LCA.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/LibraryChecker/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 1 \"Graph/LCA.cpp\"\n#include <cassert>\n#include <vector>\n\nstruct\
    \ LCA {\nprivate:\n  std::vector<std::vector<int>> G;\n  size_t n, m;\n  std::vector<std::vector<int>>\
    \ A;\n  std::vector<int> D;\n  void dfs(int v, int p){\n    for(auto v_ : G[v]){\n\
    \      if(v_ == p) continue;\n      A[v_][0] = v;\n      D[v_] = D[v]+1;\n   \
    \   dfs(v_,v);\n    }\n  }\n  void build(int r){\n    dfs(r,-1);\n    A[r][0]\
    \ = r;\n    for(size_t i = 1; i < m; ++i){\n      for(size_t j = 0; j < n; ++j){\n\
    \        A[j][i] = A[A[j][i-1]][i-1];\n      }\n    }\n   }\npublic:\n  LCA(const\
    \ std::vector<std::vector<int>>& Tree, int r) : G(Tree), n(Tree.size()), m(1),\
    \ D(n,0) {\n    size_t t = 1;\n    while(t < n) ++m, t *= 2;\n    A = std::vector<std::vector<int>>(n,std::vector<int>(m,-1));\n\
    \    build(r);\n  }\n  size_t query(int u, int v){\n    if(D[u] < D[v]) std::swap(u,v);\n\
    \n    for(size_t i = m-1; i < m; --i){\n      size_t u_ = A[u][i];\n      if(D[u_]\
    \ < D[v]) continue;\n      u = u_;\n    }\n\n    if(u == v) return u;\n    assert(D[u]\
    \ == D[v]);\n    for(size_t i = m-1; i < m; --i){\n      if(A[u][i] != A[v][i])\n\
    \        u = A[u][i], v = A[v][i];\n    }\n    return A[u][0];\n  }\n};\n#line\
    \ 5 \"test/LibraryChecker/lca.test.cpp\"\n#include <iostream>\n#include <iomanip>\n\
    using namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int N, Q;\n  cin >> N >> Q;\n  vector<vector<int>> G(N);\n  for(int i =\
    \ 1; i < N; ++i){\n    int p;\n    cin >> p;\n    G[i].emplace_back(p);\n    G[p].emplace_back(i);\n\
    \  }\n  LCA lca(G,0);\n  while(Q--){\n    int u, v;\n    cin >> u >> v;\n    cout\
    \ << lca.query(u,v) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"Graph/LCA.cpp\"\
    \n#include <vector>\n#include <iostream>\n#include <iomanip>\nusing namespace\
    \ std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n \
    \ \n  int N, Q;\n  cin >> N >> Q;\n  vector<vector<int>> G(N);\n  for(int i =\
    \ 1; i < N; ++i){\n    int p;\n    cin >> p;\n    G[i].emplace_back(p);\n    G[p].emplace_back(i);\n\
    \  }\n  LCA lca(G,0);\n  while(Q--){\n    int u, v;\n    cin >> u >> v;\n    cout\
    \ << lca.query(u,v) << '\\n';\n  }\n}\n"
  dependsOn:
  - Graph/LCA.cpp
  isVerificationFile: true
  path: test/LibraryChecker/lca.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 21:55:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/lca.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/lca.test.cpp
- /verify/test/LibraryChecker/lca.test.cpp.html
title: test/LibraryChecker/lca.test.cpp
---
