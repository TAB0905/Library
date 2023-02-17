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
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/LibraryChecker/jump_on_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#line 1 \"Graph/LCA.cpp\"\
    \n#include <cassert>\n#include <vector>\n\nstruct LCA {\nprivate:\n  std::vector<std::vector<int>>\
    \ G;\n  int n, m;\n  std::vector<std::vector<int>> A;\n  std::vector<int> D;\n\
    \  void dfs(int v, int p){\n    for(auto v_ : G[v]){\n      if(v_ == p) continue;\n\
    \      A[v_][0] = v;\n      D[v_] = D[v]+1;\n      dfs(v_,v);\n    }\n  }\n  void\
    \ build(int r){\n    dfs(r,-1);\n    A[r][0] = r;\n    for(int i = 1; i < m; ++i){\n\
    \      for(int j = 0; j < n; ++j){\n        A[j][i] = A[A[j][i-1]][i-1];\n   \
    \   }\n    }\n   }\npublic:\n  LCA(const std::vector<std::vector<int>>& Tree,\
    \ int r) : G(Tree), n(Tree.size()), m(1), D(n,0) {\n    int t = 1;\n    while(t\
    \ < n) ++m, t *= 2;\n    A = std::vector<std::vector<int>>(n,std::vector<int>(m,-1));\n\
    \    build(r);\n  }\n  int lca(int u, int v){\n    if(D[u] < D[v]) std::swap(u,v);\n\
    \n    for(int i = m-1; i >= 0; --i){\n      int u_ = A[u][i];\n      if(D[u_]\
    \ < D[v]) continue;\n      u = u_;\n    }\n\n    if(u == v) return u;\n    assert(D[u]\
    \ == D[v]);\n    for(int i = m-1; i >= 0; --i){\n      if(A[u][i] != A[v][i])\n\
    \        u = A[u][i], v = A[v][i];\n    }\n    return A[u][0];\n  }\n  int dist(int\
    \ s, int t){\n    int l = lca(s,t);\n    return D[s] + D[t] - 2*D[l];\n  }\n \
    \ int jump(int s, int t, int i){ // s \u304B\u3089 t \u306B i \u8FBA\u9032\u3093\
    \u3060\u9802\u70B9 (\u306A\u3051\u308C\u3070 -1 )\n    int l = lca(s,t);\n   \
    \ int d = dist(s,t);\n    if(d < i) return -1;\n    if(i > D[s]-D[l]){\n     \
    \ std::swap(s,t);\n      i = d - i;\n    }\n    for(int j = m-1; j >= 0; --j){\n\
    \      if(i>>j&1)\n        s = A[s][j];\n    }\n    return s;\n  }\n};\n#line\
    \ 5 \"test/LibraryChecker/jump_on_tree.test.cpp\"\n#include <iostream>\n#include\
    \ <iomanip>\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int N, Q;\n  cin >> N >> Q;\n  vector<vector<int>> G(N);\n  for(int i =\
    \ 1; i < N; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a].emplace_back(b);\n\
    \    G[b].emplace_back(a);\n  }\n  LCA lca(G,0);\n  while(Q--){\n    int u, v,\
    \ i;\n    cin >> u >> v >> i;\n    cout << lca.jump(u,v,i) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ \"Graph/LCA.cpp\"\n#include <vector>\n#include <iostream>\n#include <iomanip>\n\
    using namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int N, Q;\n  cin >> N >> Q;\n  vector<vector<int>> G(N);\n  for(int i =\
    \ 1; i < N; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a].emplace_back(b);\n\
    \    G[b].emplace_back(a);\n  }\n  LCA lca(G,0);\n  while(Q--){\n    int u, v,\
    \ i;\n    cin >> u >> v >> i;\n    cout << lca.jump(u,v,i) << '\\n';\n  }\n}\n"
  dependsOn:
  - Graph/LCA.cpp
  isVerificationFile: true
  path: test/LibraryChecker/jump_on_tree.test.cpp
  requiredBy: []
  timestamp: '2023-02-17 17:50:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/jump_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/jump_on_tree.test.cpp
- /verify/test/LibraryChecker/jump_on_tree.test.cpp.html
title: test/LibraryChecker/jump_on_tree.test.cpp
---
