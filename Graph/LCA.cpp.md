---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/lca.test.cpp
    title: test/LibraryChecker/lca.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/LCA.cpp\"\n#include <cassert>\n#include <vector>\n\
    \nstruct LCA {\nprivate:\n  std::vector<std::vector<int>> G;\n  size_t n, m;\n\
    \  std::vector<std::vector<int>> A;\n  std::vector<int> D;\n  void dfs(int v,\
    \ int p){\n    for(auto v_ : G[v]){\n      if(v_ == p) continue;\n      A[v_][0]\
    \ = v;\n      D[v_] = D[v]+1;\n      dfs(v_,v);\n    }\n  }\n  void build(int\
    \ r){\n    dfs(r,-1);\n    A[r][0] = r;\n    for(size_t i = 1; i < m; ++i){\n\
    \      for(size_t j = 0; j < n; ++j){\n        A[j][i] = A[A[j][i-1]][i-1];\n\
    \      }\n    }\n   }\npublic:\n  LCA(const std::vector<std::vector<int>>& Tree,\
    \ int r) : G(Tree), n(Tree.size()), m(1), D(n,0) {\n    size_t t = 1;\n    while(t\
    \ < n) ++m, t *= 2;\n    A = std::vector<std::vector<int>>(n,std::vector<int>(m,-1));\n\
    \    build(r);\n  }\n  size_t query(int u, int v){\n    if(D[u] < D[v]) std::swap(u,v);\n\
    \n    for(size_t i = m-1; i < m; --i){\n      size_t u_ = A[u][i];\n      if(D[u_]\
    \ < D[v]) continue;\n      u = u_;\n    }\n\n    if(u == v) return u;\n    assert(D[u]\
    \ == D[v]);\n    for(size_t i = m-1; i < m; --i){\n      if(A[u][i] != A[v][i])\n\
    \        u = A[u][i], v = A[v][i];\n    }\n    return A[u][0];\n  }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\nstruct LCA {\nprivate:\n  std::vector<std::vector<int>>\
    \ G;\n  size_t n, m;\n  std::vector<std::vector<int>> A;\n  std::vector<int> D;\n\
    \  void dfs(int v, int p){\n    for(auto v_ : G[v]){\n      if(v_ == p) continue;\n\
    \      A[v_][0] = v;\n      D[v_] = D[v]+1;\n      dfs(v_,v);\n    }\n  }\n  void\
    \ build(int r){\n    dfs(r,-1);\n    A[r][0] = r;\n    for(size_t i = 1; i < m;\
    \ ++i){\n      for(size_t j = 0; j < n; ++j){\n        A[j][i] = A[A[j][i-1]][i-1];\n\
    \      }\n    }\n   }\npublic:\n  LCA(const std::vector<std::vector<int>>& Tree,\
    \ int r) : G(Tree), n(Tree.size()), m(1), D(n,0) {\n    size_t t = 1;\n    while(t\
    \ < n) ++m, t *= 2;\n    A = std::vector<std::vector<int>>(n,std::vector<int>(m,-1));\n\
    \    build(r);\n  }\n  size_t query(int u, int v){\n    if(D[u] < D[v]) std::swap(u,v);\n\
    \n    for(size_t i = m-1; i < m; --i){\n      size_t u_ = A[u][i];\n      if(D[u_]\
    \ < D[v]) continue;\n      u = u_;\n    }\n\n    if(u == v) return u;\n    assert(D[u]\
    \ == D[v]);\n    for(size_t i = m-1; i < m; --i){\n      if(A[u][i] != A[v][i])\n\
    \        u = A[u][i], v = A[v][i];\n    }\n    return A[u][0];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/LCA.cpp
  requiredBy: []
  timestamp: '2020-09-24 22:06:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/lca.test.cpp
documentation_of: Graph/LCA.cpp
layout: document
redirect_from:
- /library/Graph/LCA.cpp
- /library/Graph/LCA.cpp.html
title: Graph/LCA.cpp
---
