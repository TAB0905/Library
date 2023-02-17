---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/jump_on_tree.test.cpp
    title: test/LibraryChecker/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/lca.test.cpp
    title: test/LibraryChecker/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/LCA.cpp\"\n#include <cassert>\n#include <vector>\n\
    \nstruct LCA {\nprivate:\n  std::vector<std::vector<int>> G;\n  int n, m;\n  std::vector<std::vector<int>>\
    \ A;\n  std::vector<int> D;\n  void dfs(int v, int p){\n    for(auto v_ : G[v]){\n\
    \      if(v_ == p) continue;\n      A[v_][0] = v;\n      D[v_] = D[v]+1;\n   \
    \   dfs(v_,v);\n    }\n  }\n  void build(int r){\n    dfs(r,-1);\n    A[r][0]\
    \ = r;\n    for(int i = 1; i < m; ++i){\n      for(int j = 0; j < n; ++j){\n \
    \       A[j][i] = A[A[j][i-1]][i-1];\n      }\n    }\n   }\npublic:\n  LCA(const\
    \ std::vector<std::vector<int>>& Tree, int r) : G(Tree), n(Tree.size()), m(1),\
    \ D(n,0) {\n    int t = 1;\n    while(t < n) ++m, t *= 2;\n    A = std::vector<std::vector<int>>(n,std::vector<int>(m,-1));\n\
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
    \      if(i>>j&1)\n        s = A[s][j];\n    }\n    return s;\n  }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\nstruct LCA {\nprivate:\n  std::vector<std::vector<int>>\
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
    \      if(i>>j&1)\n        s = A[s][j];\n    }\n    return s;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/LCA.cpp
  requiredBy: []
  timestamp: '2023-02-17 17:50:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/jump_on_tree.test.cpp
  - test/LibraryChecker/lca.test.cpp
documentation_of: Graph/LCA.cpp
layout: document
redirect_from:
- /library/Graph/LCA.cpp
- /library/Graph/LCA.cpp.html
title: Graph/LCA.cpp
---
