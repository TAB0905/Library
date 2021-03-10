---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/AOJ/GRL_4_B.cpp
    title: test/AOJ/GRL_4_B.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/TopologicalSort.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <queue>\n\nstd::vector<int> toposort(std::vector<std::vector<int>>\
    \ &G){\n  size_t N = G.size();\n  std::vector<int> ret, d_in(N,0);\n  for(size_t\
    \ i = 0; i < N; ++i)\n    for(size_t j = 0; j < G[i].size(); ++j)\n      ++d_in[G[i][j]];\n\
    \  // std::queue<int> wait;\n  std::vector<int> wait;\n  for(size_t i = 0; i <\
    \ N; ++i)\n    if(!d_in[i]) wait.emplace_back(i);\n  while(!wait.empty()){\n \
    \   int v = wait.back();\n    wait.pop_back();\n    ret.emplace_back(v);\n   \
    \ for(size_t i = 0; i < G[v].size(); ++i){\n      int v_ = G[v][i];\n      --d_in[v_];\n\
    \      if(!d_in[v_]) wait.emplace_back(v_);\n    }\n  }\n  return ret;\n}\n\n"
  code: "#include <iostream>\n#include <vector>\n#include <queue>\n\nstd::vector<int>\
    \ toposort(std::vector<std::vector<int>> &G){\n  size_t N = G.size();\n  std::vector<int>\
    \ ret, d_in(N,0);\n  for(size_t i = 0; i < N; ++i)\n    for(size_t j = 0; j <\
    \ G[i].size(); ++j)\n      ++d_in[G[i][j]];\n  // std::queue<int> wait;\n  std::vector<int>\
    \ wait;\n  for(size_t i = 0; i < N; ++i)\n    if(!d_in[i]) wait.emplace_back(i);\n\
    \  while(!wait.empty()){\n    int v = wait.back();\n    wait.pop_back();\n   \
    \ ret.emplace_back(v);\n    for(size_t i = 0; i < G[v].size(); ++i){\n      int\
    \ v_ = G[v][i];\n      --d_in[v_];\n      if(!d_in[v_]) wait.emplace_back(v_);\n\
    \    }\n  }\n  return ret;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/TopologicalSort.cpp
  requiredBy:
  - test/AOJ/GRL_4_B.cpp
  timestamp: '2021-03-11 05:53:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/TopologicalSort.cpp
layout: document
redirect_from:
- /library/Graph/TopologicalSort.cpp
- /library/Graph/TopologicalSort.cpp.html
title: Graph/TopologicalSort.cpp
---
