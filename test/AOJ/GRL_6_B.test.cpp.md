---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/MinCostFlow.cpp
    title: Graph/MinCostFlow.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
  bundledCode: "#line 1 \"test/AOJ/GRL_6_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#include <iostream>\n#include <iomanip>\n#line 1 \"Graph/MinCostFlow.cpp\"\
    \n#include <cassert>\n#include <cstdio>\n#include <vector>\n#include <queue>\n\
    #include <utility>\n#include <tuple>\n#include <limits>\n\ntemplate<typename capacity_t,\
    \ typename cost_t>\nstruct MinCostFlowGraph {\n    \nprivate:\n\n  struct edge\
    \ {\n    int to;\n    capacity_t cap;\n    cost_t cost;\n    int r_idx;\n    edge(int\
    \ t, capacity_t cap, cost_t cost, int r) :\n      to(t), cap(cap), cost(cost),\
    \ r_idx(r) {}\n  };\n\n  std::vector<std::vector<edge>> G;\n  int sz;\n\n  std::vector<cost_t>\
    \ calc_dag_potential(int from){\n    std::queue<int> Q;\n    Q.emplace(from);\n\
    \    std::vector<cost_t> ret(sz, std::numeric_limits<cost_t>::max()/2);\n    ret[from]\
    \ = 0;\n    std::vector<int> d_in(sz,0);\n    for(int i = 0; i < sz; ++i){\n \
    \     for(auto e : G[i]){\n        if(e.cap <= 0) continue;\n        ++d_in[e.to];\n\
    \      }\n    }\n    while(Q.size()){\n      auto v = Q.front();\n      Q.pop();\n\
    \      for(auto e : G[v]){\n        if(!e.cap) continue;\n        int v_ = e.to;\n\
    \        ret[v_] = std::min(ret[v_],ret[v]+e.cost);\n        --d_in[v_];\n   \
    \     if(!d_in[v_])\n          Q.emplace(v_);\n      }\n    }\n    return ret;\n\
    \  }\n\npublic:\n  MinCostFlowGraph(int n) : G(n), sz(n) {}\n\n  void add_edge(int\
    \ from, int to, capacity_t cap, cost_t cost){\n    int i = G[to].size(), i_ =\
    \ G[from].size();\n    G[from].emplace_back(to,cap,cost,i);\n    G[to].emplace_back(from,0,-cost,i_);\n\
    \  }\n  \n  cost_t min_cost_flow(int from, int to, capacity_t f){\n    cost_t\
    \ ans = 0;\n    const cost_t INF = std::numeric_limits<cost_t>::max()/2;\n   \
    \ std::vector<cost_t> potential(sz);\n    while(f > 0){\n      std::vector<cost_t>\
    \ dist(sz,INF);\n      dist[from] = 0;\n      std::vector<int> prev_v(sz,-1);\n\
    \      std::vector<int> prev_e(sz,-1);\n      std::priority_queue<std::pair<cost_t,int>,\
    \ std::vector<std::pair<cost_t,int>>, std::greater<>> pq;\n      pq.emplace(0,from);\n\
    \      while(pq.size()){\n        auto [d, v] = pq.top();\n        pq.pop();\n\
    \        if(dist[v] < d) continue;\n        for(size_t i = 0; i < G[v].size();\
    \ ++i){\n          const auto& e = G[v][i];\n          if(e.cap == 0) continue;\n\
    \          int v_ = e.to;\n          cost_t d_ = d + e.cost + potential[v] - potential[v_];\n\
    \          if(dist[v_] <= d_)\n            continue;\n          dist[v_] = d_;\n\
    \          prev_v[v_] = v;\n          prev_e[v_] = i;\n          pq.emplace(d_,e.to);\n\
    \        }\n      }\n      if(dist[to] >= INF) return -1;\n      for(int i = 0;\
    \ i < sz; ++i)\n        potential[i] += dist[i];\n      int v = to;\n      capacity_t\
    \ flow = f;\n      while(v != from){\n        int v_ = prev_v[v];\n        flow\
    \ = std::min(flow,G[v_][prev_e[v]].cap);\n        v = v_;\n      }\n      v =\
    \ to;\n      while(v != from){\n        int v_ = prev_v[v];\n        auto& e =\
    \ G[v_][prev_e[v]];\n        e.cap -= flow;\n        ans += flow*e.cost;\n   \
    \     G[v][e.r_idx].cap += flow;\n        v = v_;\n      }\n      f -= flow;\n\
    \    }\n    return ans;\n  }\n};\n#line 6 \"test/AOJ/GRL_6_B.test.cpp\"\nusing\
    \ namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \n  int n, m, f;\n  cin >> n >> m >> f;\n  MinCostFlowGraph<long long, long long>\
    \ G(n);\n  for(int i = 0; i < m; ++i){\n    long long u, v, c, d;\n    cin >>\
    \ u >> v >> c >> d;\n    G.add_edge(u,v,c,d);\n  }\n  cout << G.min_cost_flow(0,n-1,f)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include \"Graph/MinCostFlow.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \n  int n, m, f;\n  cin >> n >> m >> f;\n  MinCostFlowGraph<long long, long long>\
    \ G(n);\n  for(int i = 0; i < m; ++i){\n    long long u, v, c, d;\n    cin >>\
    \ u >> v >> c >> d;\n    G.add_edge(u,v,c,d);\n  }\n  cout << G.min_cost_flow(0,n-1,f)\
    \ << endl;\n}\n"
  dependsOn:
  - Graph/MinCostFlow.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 21:55:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_6_B.test.cpp
- /verify/test/AOJ/GRL_6_B.test.cpp.html
title: test/AOJ/GRL_6_B.test.cpp
---