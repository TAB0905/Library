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
  bundledCode: "#line 1 \"Graph/Dijkstra.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    #include <queue>\n#include <vector>\nusing namespace std;\n\nusing ll = long long;\n\
    const ll INF = 1e18;\n\nvector<long long> dijkstra(const vector<vector<pair<long\
    \ long,int>>>& G, int s){\n  const int n = G.size();\n  vector<ll> D(n,INF);\n\
    \  D[s] = 0;\n  vector<int> pre(n,-1);\n  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,\
    \ greater<pair<ll,ll>>> pq;\n  pq.emplace(0,s);\n  while(pq.size()){\n    auto\
    \ [d, v] = pq.top();\n    pq.pop();\n    if(D[v] < d) continue;\n    for(auto\
    \ [c, v_] : G[v]){\n      ll d_ = d + c;\n      if(D[v_] <= d_) continue;\n  \
    \    D[v_] = d_;\n      pre[v_] = v;\n      pq.emplace(d_,v_);\n    }\n  }\n \
    \ return {D,pre};\n}\n\nint main(){\n  int N, M, s, t;\n  cin >> N >> M >> s >>\
    \ t;\n  vector<vector<pair<ll,int>>> G(N);\n  for(int i = 0; i < M; ++i){\n  \
    \  int a, b;\n    ll c;\n    cin >> a >> b >> c;\n    G[a].emplace_back(c,b);\n\
    \  }\n  auto [D, pre] = dijkstra(G,s);\n  if(D[t] >= INF){\n    cout << -1 <<\
    \ endl;\n    return 0;\n  }\n  auto P = restor_shortest_path(pre,s,t);\n  cout\
    \ << D[t] << \" \" << P.size()-1 << endl;\n  for(int i = 0; i+1 < P.size(); ++i)\n\
    \    cout << P[i] << \" \" << P[i+1] << \"\\n\";\n}\n"
  code: "#include <iostream>\n#include <algorithm>\n#include <queue>\n#include <vector>\n\
    using namespace std;\n\nusing ll = long long;\nconst ll INF = 1e18;\n\nvector<long\
    \ long> dijkstra(const vector<vector<pair<long long,int>>>& G, int s){\n  const\
    \ int n = G.size();\n  vector<ll> D(n,INF);\n  D[s] = 0;\n  vector<int> pre(n,-1);\n\
    \  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;\n\
    \  pq.emplace(0,s);\n  while(pq.size()){\n    auto [d, v] = pq.top();\n    pq.pop();\n\
    \    if(D[v] < d) continue;\n    for(auto [c, v_] : G[v]){\n      ll d_ = d +\
    \ c;\n      if(D[v_] <= d_) continue;\n      D[v_] = d_;\n      pre[v_] = v;\n\
    \      pq.emplace(d_,v_);\n    }\n  }\n  return {D,pre};\n}\n\nint main(){\n \
    \ int N, M, s, t;\n  cin >> N >> M >> s >> t;\n  vector<vector<pair<ll,int>>>\
    \ G(N);\n  for(int i = 0; i < M; ++i){\n    int a, b;\n    ll c;\n    cin >> a\
    \ >> b >> c;\n    G[a].emplace_back(c,b);\n  }\n  auto [D, pre] = dijkstra(G,s);\n\
    \  if(D[t] >= INF){\n    cout << -1 << endl;\n    return 0;\n  }\n  auto P = restor_shortest_path(pre,s,t);\n\
    \  cout << D[t] << \" \" << P.size()-1 << endl;\n  for(int i = 0; i+1 < P.size();\
    \ ++i)\n    cout << P[i] << \" \" << P[i+1] << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2020-06-24 13:56:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/Graph/Dijkstra.cpp
- /library/Graph/Dijkstra.cpp.html
title: Graph/Dijkstra.cpp
---
