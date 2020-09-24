---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_B.test.cpp
    title: test/AOJ/GRL_6_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Graph/MinCostFlow.cpp\"\n#include <cassert>\n#include <cstdio>\n\
    #include <vector>\n#include <queue>\n#include <utility>\n#include <tuple>\n#include\
    \ <limits>\nusing namespace std;\n\nstruct MinCostFlowGraph {\nprivate:\n  using\
    \ ll = long long;\n  struct edge {\n    int to;\n    ll cap, cost;\n    int r_idx;\n\
    \    edge(int t, ll cap, ll cost, int r) :\n      to(t), cap(cap), cost(cost),\
    \ r_idx(r) {}\n  };\n  vector<vector<edge>> G;\n  int sz;\n\npublic:\n  MinCostFlowGraph(int\
    \ n) : G(n), sz(n) {}\n\n  void add_edge(int from, int to, ll cap, ll cost){\n\
    \    int i = G[to].size(), i_ = G[from].size();\n    G[from].emplace_back(to,cap,cost,i);\n\
    \    G[to].emplace_back(from,0,-cost,i_);\n  }\n  \n  ll min_cost_flow(int from,\
    \ int to, ll f){\n    ll ans = 0;\n    const ll INF = numeric_limits<ll>::max();\n\
    \    vector<ll> potential(sz);\n    while(f > 0){\n      vector<ll> dist(sz,INF);\n\
    \      dist[from] = 0;\n      vector<int> prev_v(sz,-1);\n      vector<int> prev_e(sz,-1);\n\
    \      priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;\n   \
    \   pq.emplace(0,from);\n      while(pq.size()){\n        auto [d, v] = pq.top();\n\
    \        // d *= -1;\n        pq.pop();\n        if(dist[v] < d) continue;\n \
    \       for(size_t i = 0; i < G[v].size(); ++i){\n          const auto& e = G[v][i];\n\
    \          if(e.cap == 0) continue;\n          int v_ = e.to;\n          ll d_\
    \ = d + e.cost + potential[v] - potential[v_];\n          if(dist[v_] <= d_)\n\
    \            continue;\n          dist[v_] = d_;\n          prev_v[v_] = v;\n\
    \          prev_e[v_] = i;\n          // pq.emplace(-d_,e.to);\n          pq.emplace(d_,e.to);\n\
    \        }\n      }\n      if(dist[to] >= INF) return -1;\n      for(int i = 0;\
    \ i < sz; ++i)\n        potential[i] += dist[i];\n      int v = to;\n      ll\
    \ flow = f;\n      while(v != from){\n        int v_ = prev_v[v];\n        flow\
    \ = min(flow,G[v_][prev_e[v]].cap);\n        v = v_;\n      }\n      v = to;\n\
    \      while(v != from){\n        int v_ = prev_v[v];\n        auto& e = G[v_][prev_e[v]];\n\
    \        e.cap -= flow;\n        ans += flow*e.cost;\n        G[v][e.r_idx].cap\
    \ += flow;\n        v = v_;\n      }\n      f -= flow;\n    }\n    return ans;\n\
    \  }\n};\n"
  code: "#include <cassert>\n#include <cstdio>\n#include <vector>\n#include <queue>\n\
    #include <utility>\n#include <tuple>\n#include <limits>\nusing namespace std;\n\
    \nstruct MinCostFlowGraph {\nprivate:\n  using ll = long long;\n  struct edge\
    \ {\n    int to;\n    ll cap, cost;\n    int r_idx;\n    edge(int t, ll cap, ll\
    \ cost, int r) :\n      to(t), cap(cap), cost(cost), r_idx(r) {}\n  };\n  vector<vector<edge>>\
    \ G;\n  int sz;\n\npublic:\n  MinCostFlowGraph(int n) : G(n), sz(n) {}\n\n  void\
    \ add_edge(int from, int to, ll cap, ll cost){\n    int i = G[to].size(), i_ =\
    \ G[from].size();\n    G[from].emplace_back(to,cap,cost,i);\n    G[to].emplace_back(from,0,-cost,i_);\n\
    \  }\n  \n  ll min_cost_flow(int from, int to, ll f){\n    ll ans = 0;\n    const\
    \ ll INF = numeric_limits<ll>::max();\n    vector<ll> potential(sz);\n    while(f\
    \ > 0){\n      vector<ll> dist(sz,INF);\n      dist[from] = 0;\n      vector<int>\
    \ prev_v(sz,-1);\n      vector<int> prev_e(sz,-1);\n      priority_queue<pair<ll,int>,\
    \ vector<pair<ll,int>>, greater<>> pq;\n      pq.emplace(0,from);\n      while(pq.size()){\n\
    \        auto [d, v] = pq.top();\n        // d *= -1;\n        pq.pop();\n   \
    \     if(dist[v] < d) continue;\n        for(size_t i = 0; i < G[v].size(); ++i){\n\
    \          const auto& e = G[v][i];\n          if(e.cap == 0) continue;\n    \
    \      int v_ = e.to;\n          ll d_ = d + e.cost + potential[v] - potential[v_];\n\
    \          if(dist[v_] <= d_)\n            continue;\n          dist[v_] = d_;\n\
    \          prev_v[v_] = v;\n          prev_e[v_] = i;\n          // pq.emplace(-d_,e.to);\n\
    \          pq.emplace(d_,e.to);\n        }\n      }\n      if(dist[to] >= INF)\
    \ return -1;\n      for(int i = 0; i < sz; ++i)\n        potential[i] += dist[i];\n\
    \      int v = to;\n      ll flow = f;\n      while(v != from){\n        int v_\
    \ = prev_v[v];\n        flow = min(flow,G[v_][prev_e[v]].cap);\n        v = v_;\n\
    \      }\n      v = to;\n      while(v != from){\n        int v_ = prev_v[v];\n\
    \        auto& e = G[v_][prev_e[v]];\n        e.cap -= flow;\n        ans += flow*e.cost;\n\
    \        G[v][e.r_idx].cap += flow;\n        v = v_;\n      }\n      f -= flow;\n\
    \    }\n    return ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/MinCostFlow.cpp
  requiredBy: []
  timestamp: '2020-05-14 11:55:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_6_B.test.cpp
documentation_of: Graph/MinCostFlow.cpp
layout: document
redirect_from:
- /library/Graph/MinCostFlow.cpp
- /library/Graph/MinCostFlow.cpp.html
title: Graph/MinCostFlow.cpp
---
