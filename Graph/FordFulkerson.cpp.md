---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_GRL_6_A_FordFulkerson.test.cpp
    title: test/aoj_GRL_6_A_FordFulkerson.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Graph/FordFulkerson.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\ntemplate<typename T>\nstruct FlowGraph {\nprivate:\n  struct edge\
    \ {\n    const int to;\n    T cap;\n    const int r_idx;\n    edge(int t, T c,\
    \ int i) :\n      to(t), cap(c), r_idx(i) {}\n  };\n\n  std::vector<std::vector<edge>>\
    \ G;\n\n  T dfs(int v, int sink, T min_cap, std::vector<bool>& visited){\n   \
    \ visited[v] = true;\n    if(v == sink) return min_cap;\n    for(auto& e : G[v]){\n\
    \      if(e.cap == T()) continue;\n      if(visited[e.to]) continue;\n      T\
    \ min_cap_ = std::min(min_cap,e.cap);\n      T flowed = dfs(e.to,sink,min_cap_,\
    \ visited);\n      if(flowed == T()) continue;\n      e.cap -= flowed;\n     \
    \ G[e.to][e.r_idx].cap += flowed;\n      return flowed;\n    }\n    return T();\n\
    \  }\n  \npublic:\n  FlowGraph(size_t n) : G(n) {}\n  void add_edge(int from,\
    \ int to, T cap){\n    int i = G[to].size(), i_ = G[from].size();\n    G[from].emplace_back(to,cap,i);\n\
    \    G[to].emplace_back(from,T(),i_);\n  }\n  T max_flow(int from, int to){\n\
    \    T ret = 0, INF = 1e9;\n    while(true){\n      std::vector<bool> visited(G.size());\n\
    \      T f = dfs(from,to,INF,visited);\n      if(f == T()) break;\n      ret +=\
    \ f;\n    }\n    return ret;\n  }\n};\n"
  code: "#include <algorithm>\n#include <vector>\n\ntemplate<typename T>\nstruct FlowGraph\
    \ {\nprivate:\n  struct edge {\n    const int to;\n    T cap;\n    const int r_idx;\n\
    \    edge(int t, T c, int i) :\n      to(t), cap(c), r_idx(i) {}\n  };\n\n  std::vector<std::vector<edge>>\
    \ G;\n\n  T dfs(int v, int sink, T min_cap, std::vector<bool>& visited){\n   \
    \ visited[v] = true;\n    if(v == sink) return min_cap;\n    for(auto& e : G[v]){\n\
    \      if(e.cap == T()) continue;\n      if(visited[e.to]) continue;\n      T\
    \ min_cap_ = std::min(min_cap,e.cap);\n      T flowed = dfs(e.to,sink,min_cap_,\
    \ visited);\n      if(flowed == T()) continue;\n      e.cap -= flowed;\n     \
    \ G[e.to][e.r_idx].cap += flowed;\n      return flowed;\n    }\n    return T();\n\
    \  }\n  \npublic:\n  FlowGraph(size_t n) : G(n) {}\n  void add_edge(int from,\
    \ int to, T cap){\n    int i = G[to].size(), i_ = G[from].size();\n    G[from].emplace_back(to,cap,i);\n\
    \    G[to].emplace_back(from,T(),i_);\n  }\n  T max_flow(int from, int to){\n\
    \    T ret = 0, INF = 1e9;\n    while(true){\n      std::vector<bool> visited(G.size());\n\
    \      T f = dfs(from,to,INF,visited);\n      if(f == T()) break;\n      ret +=\
    \ f;\n    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/FordFulkerson.cpp
  requiredBy: []
  timestamp: '2020-05-09 17:45:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_GRL_6_A_FordFulkerson.test.cpp
documentation_of: Graph/FordFulkerson.cpp
layout: document
redirect_from:
- /library/Graph/FordFulkerson.cpp
- /library/Graph/FordFulkerson.cpp.html
title: Graph/FordFulkerson.cpp
---
