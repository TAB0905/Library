---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/TreeDiameter.cpp
    title: Graph/TreeDiameter.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/LibraryChecker/tree_diameter.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 2 \"Graph/TreeDiameter.cpp\"\n#include <utility>\n\ntemplate<typename\
    \ T>\nstd::pair<T,std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<T,int>>>&\
    \ G){\n  const int n = G.size();\n  std::vector<T> D(n);\n  auto rec = [&](auto&&rec,\
    \ int v, int p) -> std::pair<T,int> {\n    D[v] = 0;\n    std::pair<T,int> ret(0,v);\n\
    \    for(auto [d,u] : G[v]){\n      if(u == p) continue;\n      auto r = rec(rec,u,v);\n\
    \      r.first += d;\n      ret = std::max(ret,r);\n      D[v] = std::max(D[v],D[u]+d);\n\
    \    }\n    return ret;\n  };\n  int v = 0;\n  v = rec(rec,v,-1).second;\n  auto\
    \ [r,u] = rec(rec,v,-1);\n  std::vector<int> path(1,u);\n  T t = 0;\n  while(t\
    \ < r){\n    for(auto [d,w] : G[u]){\n      if(D[w] == t+d){\n        path.emplace_back(w);\n\
    \        u = w;\n        t += d;\n        break;\n      }\n    }\n  }\n  return\
    \ {r,path};\n}\n#line 7 \"test/LibraryChecker/tree_diameter.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main(){\n  int n;\n  cin >> n;\n  vector<vector<pair<long\
    \ long,int>>> G(n);\n  for(int i = 0; i+1 < n; ++i){\n    int a, b, c;\n    cin\
    \ >> a >> b >> c;\n    G[a].emplace_back(c,b);\n    G[b].emplace_back(c,a);\n\
    \  }\n  auto [diam,path] = tree_diameter(G);\n  cout << diam << ' ' << path.size()\
    \ << '\\n';\n  for(auto e : path){\n    cout << e << ' ';\n  }\n  cout << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"Graph/TreeDiameter.cpp\"\n\nusing\
    \ namespace std;\n\nint main(){\n  int n;\n  cin >> n;\n  vector<vector<pair<long\
    \ long,int>>> G(n);\n  for(int i = 0; i+1 < n; ++i){\n    int a, b, c;\n    cin\
    \ >> a >> b >> c;\n    G[a].emplace_back(c,b);\n    G[b].emplace_back(c,a);\n\
    \  }\n  auto [diam,path] = tree_diameter(G);\n  cout << diam << ' ' << path.size()\
    \ << '\\n';\n  for(auto e : path){\n    cout << e << ' ';\n  }\n  cout << '\\\
    n';\n}\n"
  dependsOn:
  - Graph/TreeDiameter.cpp
  isVerificationFile: true
  path: test/LibraryChecker/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2021-05-02 23:43:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/tree_diameter.test.cpp
- /verify/test/LibraryChecker/tree_diameter.test.cpp.html
title: test/LibraryChecker/tree_diameter.test.cpp
---
