---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/scc.test.cpp
    title: test/LibraryChecker/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/SCCD.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n#include <set>\n\nstruct SCCDecomposedGraph\
    \ {\n  std::vector<std::vector<int>> dag;\n  std::vector<std::vector<int>> scc;\n\
    \  std::vector<int> cmp;\n};\n\nSCCDecomposedGraph scc_decompose(const std::vector<std::vector<int>>&\
    \ G){\n  const int n = G.size();\n  std::vector<int> ord(n,-1), low(n), st;\n\
    \  SCCDecomposedGraph ret;\n  int num_scc = 0;\n  ret.cmp.resize(n,-1);\n  auto\
    \ dfs = [&](auto&& dfs, int v, int& tm) -> void {\n    low[v] = tm;\n    ord[v]\
    \ = tm;\n    ++tm;\n    st.emplace_back(v);\n    for(auto u : G[v]){\n      if(ord[u]\
    \ < 0){\n        dfs(dfs,u,tm);\n        low[v] = std::min(low[v],low[u]);\n \
    \     }else if(ret.cmp[u] < 0){\n        low[v] = std::min(low[v],ord[u]);\n \
    \     }\n    }\n    if(ord[v] == low[v]){\n      ret.scc.push_back({});\n    \
    \  while(true){\n        const int u = st.back();\n        st.pop_back();\n  \
    \      ret.scc.back().emplace_back(u);\n        ret.cmp[u] = num_scc;\n      \
    \  if(v == u) break;\n      }\n      ++num_scc;\n    }\n  };\n  int tm = 0;\n\
    \  for(int i = 0; i < n; ++i){\n    if(ord[i] < 0) dfs(dfs,i,tm);\n  }\n  reverse(ret.scc.begin(),ret.scc.end());\n\
    \  for(int i = 0; i < n; ++i){\n    ret.cmp[i] = num_scc - 1 - ret.cmp[i];\n \
    \ }\n  ret.dag.resize(num_scc);\n  for(int i = 0; i < n; ++i){\n    int v = ret.cmp[i];\n\
    \    for(auto j : G[i]){\n      int u = ret.cmp[j];\n      if(v != u){\n     \
    \   ret.dag[v].emplace_back(u);\n      }\n    }\n    sort(ret.dag[v].begin(),ret.dag[v].end());\n\
    \    ret.dag[v].erase(unique(ret.dag[v].begin(),ret.dag[v].end()),ret.dag[v].end());\n\
    \  }\n  return ret;\n}\n\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    #include <set>\n\nstruct SCCDecomposedGraph {\n  std::vector<std::vector<int>>\
    \ dag;\n  std::vector<std::vector<int>> scc;\n  std::vector<int> cmp;\n};\n\n\
    SCCDecomposedGraph scc_decompose(const std::vector<std::vector<int>>& G){\n  const\
    \ int n = G.size();\n  std::vector<int> ord(n,-1), low(n), st;\n  SCCDecomposedGraph\
    \ ret;\n  int num_scc = 0;\n  ret.cmp.resize(n,-1);\n  auto dfs = [&](auto&& dfs,\
    \ int v, int& tm) -> void {\n    low[v] = tm;\n    ord[v] = tm;\n    ++tm;\n \
    \   st.emplace_back(v);\n    for(auto u : G[v]){\n      if(ord[u] < 0){\n    \
    \    dfs(dfs,u,tm);\n        low[v] = std::min(low[v],low[u]);\n      }else if(ret.cmp[u]\
    \ < 0){\n        low[v] = std::min(low[v],ord[u]);\n      }\n    }\n    if(ord[v]\
    \ == low[v]){\n      ret.scc.push_back({});\n      while(true){\n        const\
    \ int u = st.back();\n        st.pop_back();\n        ret.scc.back().emplace_back(u);\n\
    \        ret.cmp[u] = num_scc;\n        if(v == u) break;\n      }\n      ++num_scc;\n\
    \    }\n  };\n  int tm = 0;\n  for(int i = 0; i < n; ++i){\n    if(ord[i] < 0)\
    \ dfs(dfs,i,tm);\n  }\n  reverse(ret.scc.begin(),ret.scc.end());\n  for(int i\
    \ = 0; i < n; ++i){\n    ret.cmp[i] = num_scc - 1 - ret.cmp[i];\n  }\n  ret.dag.resize(num_scc);\n\
    \  for(int i = 0; i < n; ++i){\n    int v = ret.cmp[i];\n    for(auto j : G[i]){\n\
    \      int u = ret.cmp[j];\n      if(v != u){\n        ret.dag[v].emplace_back(u);\n\
    \      }\n    }\n    sort(ret.dag[v].begin(),ret.dag[v].end());\n    ret.dag[v].erase(unique(ret.dag[v].begin(),ret.dag[v].end()),ret.dag[v].end());\n\
    \  }\n  return ret;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/SCCD.cpp
  requiredBy: []
  timestamp: '2021-03-21 16:59:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/scc.test.cpp
documentation_of: Graph/SCCD.cpp
layout: document
redirect_from:
- /library/Graph/SCCD.cpp
- /library/Graph/SCCD.cpp.html
title: Graph/SCCD.cpp
---
