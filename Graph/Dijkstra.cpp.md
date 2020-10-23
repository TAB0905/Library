---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/shortest_path.test.cpp
    title: test/LibraryChecker/shortest_path.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\n#include <algorithm>\n#include <queue>\n\
    #include <vector>\n\nusing ll = long long;\nconst ll INF = 1e18;\n\nstd::pair<std::vector<ll>,std::vector<int>>\
    \ dijkstra(const std::vector<std::vector<std::pair<ll,int>>>& G, int s){\n  const\
    \ int n = G.size();\n  std::vector<ll> D(n,INF);\n  D[s] = 0;\n  std::vector<int>\
    \ pre(n,-1);\n  std::priority_queue<std::pair<ll,ll>, std::vector<std::pair<ll,ll>>,\
    \ std::greater<std::pair<ll,ll>>> pq;\n  pq.emplace(0,s);\n  while(pq.size()){\n\
    \    auto [d, v] = pq.top();\n    pq.pop();\n    if(D[v] < d) continue;\n    for(auto\
    \ [c, v_] : G[v]){\n      ll d_ = d + c;\n      if(D[v_] <= d_) continue;\n  \
    \    D[v_] = d_;\n      pre[v_] = v;\n      pq.emplace(d_,v_);\n    }\n  }\n \
    \ return {D,pre};\n}\n\nstd::vector<int> restor_shortest_path(const std::vector<int>&\
    \ pre, int s, int t){\n  std::vector<int> P;\n  while(t != s){\n    P.emplace_back(t);\n\
    \    t = pre[t];\n  }\n  P.emplace_back(s);\n  reverse(P.begin(), P.end());\n\
    \  return P;\n}\n\n"
  code: "#include <algorithm>\n#include <queue>\n#include <vector>\n\nusing ll = long\
    \ long;\nconst ll INF = 1e18;\n\nstd::pair<std::vector<ll>,std::vector<int>> dijkstra(const\
    \ std::vector<std::vector<std::pair<ll,int>>>& G, int s){\n  const int n = G.size();\n\
    \  std::vector<ll> D(n,INF);\n  D[s] = 0;\n  std::vector<int> pre(n,-1);\n  std::priority_queue<std::pair<ll,ll>,\
    \ std::vector<std::pair<ll,ll>>, std::greater<std::pair<ll,ll>>> pq;\n  pq.emplace(0,s);\n\
    \  while(pq.size()){\n    auto [d, v] = pq.top();\n    pq.pop();\n    if(D[v]\
    \ < d) continue;\n    for(auto [c, v_] : G[v]){\n      ll d_ = d + c;\n      if(D[v_]\
    \ <= d_) continue;\n      D[v_] = d_;\n      pre[v_] = v;\n      pq.emplace(d_,v_);\n\
    \    }\n  }\n  return {D,pre};\n}\n\nstd::vector<int> restor_shortest_path(const\
    \ std::vector<int>& pre, int s, int t){\n  std::vector<int> P;\n  while(t != s){\n\
    \    P.emplace_back(t);\n    t = pre[t];\n  }\n  P.emplace_back(s);\n  reverse(P.begin(),\
    \ P.end());\n  return P;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2020-09-24 21:12:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/shortest_path.test.cpp
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
