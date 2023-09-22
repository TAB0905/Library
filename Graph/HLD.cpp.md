---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/vertex_add_path_sum.test.cpp
    title: test/LibraryChecker/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/vertex_set_path_composite.test.cpp
    title: test/LibraryChecker/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/HLD.cpp\"\n#include <algorithm>\n#include <iostream>\n\
    #include <vector>\n#include <utility>\n\ntemplate<typename Tree>\nclass QueryOnRootedTree\
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
    \ A[i] << ' ';\n    std::cerr << '\\n';\n  }\n};\n"
  code: "#include <algorithm>\n#include <iostream>\n#include <vector>\n#include <utility>\n\
    \ntemplate<typename Tree>\nclass QueryOnRootedTree {\n  const int n;\n  const\
    \ int r;\n  std::vector<int> L, R;\n  std::vector<int> depth, parent, A;\n  void\
    \ build(Tree& T){\n    A[r] = r;\n    reorder(T,r,-1);\n    int t = 0;\n    dfs(T,r,-1,t);\n\
    \  }\n  int reorder(Tree& T, int v, int p){\n    std::vector<int> subtree_size;\n\
    \    int s = 1;\n    parent[v] = p;\n    for(auto u: T[v]){\n      if(u == p){\n\
    \        subtree_size.emplace_back(0);\n        continue;\n      }\n      int\
    \ s_ = reorder(T,u,v);\n      subtree_size.emplace_back(s_);\n      s += s_;\n\
    \    }\n    if(T[v].size() > 1){\n      int heavy = std::max_element(subtree_size.begin(),subtree_size.end())\
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
    \ A[i] << ' ';\n    std::cerr << '\\n';\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/HLD.cpp
  requiredBy: []
  timestamp: '2023-01-12 00:54:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/vertex_set_path_composite.test.cpp
  - test/LibraryChecker/vertex_add_path_sum.test.cpp
documentation_of: Graph/HLD.cpp
layout: document
redirect_from:
- /library/Graph/HLD.cpp
- /library/Graph/HLD.cpp.html
title: Graph/HLD.cpp
---
