---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Dijkstra.cpp
    title: Graph/Dijkstra.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/LibraryChecker/shortest_path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <iostream>\n#include\
    \ <iomanip>\n#include <vector>\n#include <utility>\n\n#line 1 \"Graph/Dijkstra.cpp\"\
    \n#include <algorithm>\n#include <queue>\n#line 5 \"Graph/Dijkstra.cpp\"\n\ntemplate<typename\
    \ T>\nstd::pair<std::vector<T>,std::vector<int>> dijkstra(const std::vector<std::vector<std::pair<T,int>>>&\
    \ G, int s, T INF){\n  const int n = G.size();\n  std::vector<T> D(n,INF);\n \
    \ D[s] = 0;\n  std::vector<int> pre(n,-1);\n  std::priority_queue<std::pair<T,int>,\
    \ std::vector<std::pair<T,int>>, std::greater<>> pq;\n  pq.emplace(0,s);\n  while(pq.size()){\n\
    \    auto [d, v] = pq.top();\n    pq.pop();\n    if(D[v] < d) continue;\n    for(auto\
    \ [c, v_] : G[v]){\n      T d_ = d + c;\n      if(D[v_] <= d_) continue;\n   \
    \   D[v_] = d_;\n      pre[v_] = v;\n      pq.emplace(d_,v_);\n    }\n  }\n  return\
    \ {D,pre};\n}\n\nstd::vector<int> restor_shortest_path(const std::vector<int>&\
    \ pre, int s, int t){\n  std::vector<int> P;\n  while(t != s){\n    P.emplace_back(t);\n\
    \    t = pre[t];\n  }\n  P.emplace_back(s);\n  reverse(P.begin(), P.end());\n\
    \  return P;\n}\n\n#line 9 \"test/LibraryChecker/shortest_path.test.cpp\"\n\n\
    using namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  using ll = long long;\n  int N, M, s, t;\n  cin >> N >> M >> s >> t;\n  vector<vector<pair<ll,int>>>\
    \ G(N);\n  for(int i = 0; i < M; ++i){\n    int a, b;\n    ll c;\n    cin >> a\
    \ >> b >> c;\n    G[a].emplace_back(c,b);\n  }\n  const ll INF = 1e18;\n  auto\
    \ [D, pre] = dijkstra(G,s,INF);\n  if(D[t] >= INF){\n    cout << -1 << endl;\n\
    \    return 0;\n  }\n  auto P = restor_shortest_path(pre,s,t);\n  cout << D[t]\
    \ << \" \" << P.size()-1 << endl;\n  for(int i = 0; i+1 < P.size(); ++i)\n   \
    \ cout << P[i] << \" \" << P[i+1] << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n#include <vector>\n#include <utility>\n\n#include\
    \ \"Graph/Dijkstra.cpp\"\n\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  using ll = long long;\n  int N, M, s, t;\n\
    \  cin >> N >> M >> s >> t;\n  vector<vector<pair<ll,int>>> G(N);\n  for(int i\
    \ = 0; i < M; ++i){\n    int a, b;\n    ll c;\n    cin >> a >> b >> c;\n    G[a].emplace_back(c,b);\n\
    \  }\n  const ll INF = 1e18;\n  auto [D, pre] = dijkstra(G,s,INF);\n  if(D[t]\
    \ >= INF){\n    cout << -1 << endl;\n    return 0;\n  }\n  auto P = restor_shortest_path(pre,s,t);\n\
    \  cout << D[t] << \" \" << P.size()-1 << endl;\n  for(int i = 0; i+1 < P.size();\
    \ ++i)\n    cout << P[i] << \" \" << P[i+1] << \"\\n\";\n}\n"
  dependsOn:
  - Graph/Dijkstra.cpp
  isVerificationFile: true
  path: test/LibraryChecker/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2022-04-06 14:42:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/shortest_path.test.cpp
- /verify/test/LibraryChecker/shortest_path.test.cpp.html
title: test/LibraryChecker/shortest_path.test.cpp
---
