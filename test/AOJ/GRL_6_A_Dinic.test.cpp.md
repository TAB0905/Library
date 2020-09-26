---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dinic.cpp
    title: Graph/Dinic.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
  bundledCode: "#line 1 \"test/AOJ/GRL_6_A_Dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#include <iostream>\n#line 2 \"Graph/Dinic.cpp\"\n#include <algorithm>\n#include\
    \ <queue>\n#include <vector>\n\ntemplate<typename T>\nstruct Dinic {\nprivate:\n\
    \  struct edge {\n    const int to;\n    T cap;\n    const int r_idx;\n    edge(int\
    \ t, T c, int i) :\n      to(t), cap(c), r_idx(i) {}\n  };\n\n  std::vector<std::vector<edge>>\
    \ G;\n\n  std::vector<int> bfs(int source){\n    const int INF = 1e9;\n\n    std::vector<int>\
    \ dist(G.size(),INF);\n    dist[source] = 0;\n    \n    std::queue<int> Q;\n \
    \   Q.emplace(source);\n\n    while(not Q.empty()){\n      int v = Q.front();\n\
    \      Q.pop();\n      int d = dist[v];\n      for(auto& e : G[v]){\n        if(not\
    \ e.cap)\n          continue;\n        if(dist[e.to] <= d+1)\n          continue;\n\
    \        dist[e.to] = d+1;\n        Q.emplace(e.to);\n      }\n    }\n    return\
    \ dist;\n  }\n\n  T dfs(int v, int sink, T min_cap, const std::vector<int>& dist,\
    \ std::vector<size_t>& edge_idx){\n    if(v == sink) return min_cap;\n    for(size_t&\
    \ i = edge_idx[v]; i < G[v].size(); ++i){\n      auto& e = G[v][i];\n      if(e.cap\
    \ == T()) continue;\n      if(dist[e.to] != dist[v]+1) continue;\n\n      T min_cap_\
    \ = std::min(min_cap,e.cap);\n      T flowed = dfs(e.to,sink,min_cap_,dist,edge_idx);\n\
    \      if(flowed == T()) continue;\n      e.cap -= flowed;\n      G[e.to][e.r_idx].cap\
    \ += flowed;\n      return flowed;\n    }\n    return T();\n  }\n\n  T flow;\n\
    public:\n  Dinic(size_t n) : G(n), flow(0) {}\n\n  void add_edge(int from, int\
    \ to, T cap){\n    int i = G[to].size(), i_ = G[from].size();\n    G[from].emplace_back(to,cap,i);\n\
    \    G[to].emplace_back(from,T(),i_);\n  }\n\n  T max_flow(int from, int to){\n\
    \n    while(true){\n      std::vector<int> dist = bfs(from);\n\n      if(dist[to]\
    \ >= (int)G.size())\n        break;\n\n      std::vector<size_t> edge_idx(G.size());\n\
    \      while(true){\n        const T INF = std::numeric_limits<T>::max();\n  \
    \      T f = dfs(from,to,INF,dist,edge_idx);\n        if(f == T()) break;\n  \
    \      flow += f;\n      }\n    }\n    \n    return flow;\n  }\n};\n\n#line 5\
    \ \"test/AOJ/GRL_6_A_Dinic.test.cpp\"\nusing namespace std;\n\nint main(){\n \
    \ int V, E;\n  cin >> V >> E;\n  Dinic<long long> G(V);\n  for(int i = 0; i <\
    \ E; ++i){\n    int u, v, c;\n    cin >> u >> v >> c;\n    G.add_edge(u,v,c);\n\
    \  }\n  cout << G.max_flow(0,V-1) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#include <iostream>\n#include \"Graph/Dinic.cpp\"\nusing namespace std;\n\n\
    int main(){\n  int V, E;\n  cin >> V >> E;\n  Dinic<long long> G(V);\n  for(int\
    \ i = 0; i < E; ++i){\n    int u, v, c;\n    cin >> u >> v >> c;\n    G.add_edge(u,v,c);\n\
    \  }\n  cout << G.max_flow(0,V-1) << endl;\n}\n"
  dependsOn:
  - Graph/Dinic.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_6_A_Dinic.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 01:46:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_6_A_Dinic.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_6_A_Dinic.test.cpp
- /verify/test/AOJ/GRL_6_A_Dinic.test.cpp.html
title: test/AOJ/GRL_6_A_Dinic.test.cpp
---
