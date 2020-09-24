---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/FordFulkerson.cpp
    title: Graph/FordFulkerson.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
  bundledCode: "#line 1 \"test/AOJ/GRL_6_A_FordFulkerson.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\n\n#include\
    \ <iostream>\n#line 1 \"Graph/FordFulkerson.cpp\"\n#include <algorithm>\n#include\
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
    \ f;\n    }\n    return ret;\n  }\n};\n#line 5 \"test/AOJ/GRL_6_A_FordFulkerson.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int V, E;\n  cin >> V >> E;\n  FlowGraph<long\
    \ long> G(V);\n  for(int i = 0; i < E; ++i){\n    int u, v, c;\n    cin >> u >>\
    \ v >> c;\n    G.add_edge(u,v,c);\n  }\n  cout << G.max_flow(0,V-1) << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#include <iostream>\n#include \"Graph/FordFulkerson.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  int V, E;\n  cin >> V >> E;\n  FlowGraph<long long> G(V);\n\
    \  for(int i = 0; i < E; ++i){\n    int u, v, c;\n    cin >> u >> v >> c;\n  \
    \  G.add_edge(u,v,c);\n  }\n  cout << G.max_flow(0,V-1) << endl;\n}\n"
  dependsOn:
  - Graph/FordFulkerson.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_6_A_FordFulkerson.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 21:15:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_6_A_FordFulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_6_A_FordFulkerson.test.cpp
- /verify/test/AOJ/GRL_6_A_FordFulkerson.test.cpp.html
title: test/AOJ/GRL_6_A_FordFulkerson.test.cpp
---
