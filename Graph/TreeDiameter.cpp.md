---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/tree_diameter.test.cpp
    title: test/LibraryChecker/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/TreeDiameter.cpp\"\n#include <vector>\n#include <utility>\n\
    \ntemplate<typename T>\nstd::pair<T,std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<T,int>>>&\
    \ G){\n  const int n = G.size();\n  std::vector<T> D(n);\n  auto rec = [&](auto&&rec,\
    \ int v, int p) -> std::pair<T,int> {\n    D[v] = 0;\n    std::pair<T,int> ret(0,v);\n\
    \    for(auto [d,u] : G[v]){\n      if(u == p) continue;\n      auto r = rec(rec,u,v);\n\
    \      r.first += d;\n      ret = std::max(ret,r);\n      D[v] = std::max(D[v],D[u]+d);\n\
    \    }\n    return ret;\n  };\n  int v = 0;\n  v = rec(rec,v,-1).second;\n  auto\
    \ [r,u] = rec(rec,v,-1);\n  std::vector<int> path(1,u);\n  T t = 0;\n  while(t\
    \ < r){\n    for(auto [d,w] : G[u]){\n      if(D[w] == t+d){\n        path.emplace_back(w);\n\
    \        u = w;\n        t += d;\n        break;\n      }\n    }\n  }\n  return\
    \ {r,path};\n}\n"
  code: "#include <vector>\n#include <utility>\n\ntemplate<typename T>\nstd::pair<T,std::vector<int>>\
    \ tree_diameter(const std::vector<std::vector<std::pair<T,int>>>& G){\n  const\
    \ int n = G.size();\n  std::vector<T> D(n);\n  auto rec = [&](auto&&rec, int v,\
    \ int p) -> std::pair<T,int> {\n    D[v] = 0;\n    std::pair<T,int> ret(0,v);\n\
    \    for(auto [d,u] : G[v]){\n      if(u == p) continue;\n      auto r = rec(rec,u,v);\n\
    \      r.first += d;\n      ret = std::max(ret,r);\n      D[v] = std::max(D[v],D[u]+d);\n\
    \    }\n    return ret;\n  };\n  int v = 0;\n  v = rec(rec,v,-1).second;\n  auto\
    \ [r,u] = rec(rec,v,-1);\n  std::vector<int> path(1,u);\n  T t = 0;\n  while(t\
    \ < r){\n    for(auto [d,w] : G[u]){\n      if(D[w] == t+d){\n        path.emplace_back(w);\n\
    \        u = w;\n        t += d;\n        break;\n      }\n    }\n  }\n  return\
    \ {r,path};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TreeDiameter.cpp
  requiredBy: []
  timestamp: '2021-05-02 23:43:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/tree_diameter.test.cpp
documentation_of: Graph/TreeDiameter.cpp
layout: document
redirect_from:
- /library/Graph/TreeDiameter.cpp
- /library/Graph/TreeDiameter.cpp.html
title: Graph/TreeDiameter.cpp
---
