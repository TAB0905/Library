---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Graph/SCCD.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n#include <set>\n\nstd::vector<int> scc_decompose(const\
    \ std::vector<std::vector<int>>& G){\n  int n = G.size();\n  std::vector<int>\
    \ P;\n  {\n    std::vector<int> visited(n,false);\n    auto dfs = [&](auto dfs,\
    \ int v) -> void {\n      visited[v] = true;\n      for(auto v_ : G[v]){\n   \
    \     if(visited[v_]) continue;\n        dfs(dfs,v_);\n      }\n      P.push_back(v);\n\
    \    };\n    for(int i = 0; i < n; ++i){\n      if(visited[i]) continue;\n   \
    \   dfs(dfs,i);\n    }\n    reverse(P.begin(), P.end());\n  }\n  std::vector<std::vector<int>>\
    \ G_rev(n);\n  for(int i = 0; i < n; ++i){\n    for(auto j : G[i])\n      G_rev[j].push_back(i);\n\
    \  }\n  std::vector<int> A(n,-1);\n  int t = 0;\n  auto dfs = [&](auto dfs, int\
    \ v) -> void {\n    A[v] = t;\n    for(auto v_ : G_rev[v]){\n      if(A[v_] >=\
    \ 0) continue;\n      dfs(dfs,v_);\n    }\n  };\n  for(auto v : P){\n    if(A[v]\
    \ >= 0) continue;\n    dfs(dfs,v);\n    ++t;\n  }\n  return A;\n}\n\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    #include <set>\n\nstd::vector<int> scc_decompose(const std::vector<std::vector<int>>&\
    \ G){\n  int n = G.size();\n  std::vector<int> P;\n  {\n    std::vector<int> visited(n,false);\n\
    \    auto dfs = [&](auto dfs, int v) -> void {\n      visited[v] = true;\n   \
    \   for(auto v_ : G[v]){\n        if(visited[v_]) continue;\n        dfs(dfs,v_);\n\
    \      }\n      P.push_back(v);\n    };\n    for(int i = 0; i < n; ++i){\n   \
    \   if(visited[i]) continue;\n      dfs(dfs,i);\n    }\n    reverse(P.begin(),\
    \ P.end());\n  }\n  std::vector<std::vector<int>> G_rev(n);\n  for(int i = 0;\
    \ i < n; ++i){\n    for(auto j : G[i])\n      G_rev[j].push_back(i);\n  }\n  std::vector<int>\
    \ A(n,-1);\n  int t = 0;\n  auto dfs = [&](auto dfs, int v) -> void {\n    A[v]\
    \ = t;\n    for(auto v_ : G_rev[v]){\n      if(A[v_] >= 0) continue;\n      dfs(dfs,v_);\n\
    \    }\n  };\n  for(auto v : P){\n    if(A[v] >= 0) continue;\n    dfs(dfs,v);\n\
    \    ++t;\n  }\n  return A;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/SCCD.cpp
  requiredBy: []
  timestamp: '2020-08-30 04:56:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/SCCD.cpp
layout: document
redirect_from:
- /library/Graph/SCCD.cpp
- /library/Graph/SCCD.cpp.html
title: Graph/SCCD.cpp
---
