---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/SCCD.cpp
    title: Graph/SCCD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/LibraryChecker/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"Graph/SCCD.cpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#line 5 \"Graph/SCCD.cpp\"\n#include <set>\n\
    \nstd::vector<int> scc_decompose(const std::vector<std::vector<int>>& G){\n  int\
    \ n = G.size();\n  std::vector<int> P;\n  {\n    std::vector<int> visited(n,false);\n\
    \    auto dfs = [&](auto dfs, int v) -> void {\n      visited[v] = true;\n   \
    \   for(auto v_ : G[v]){\n        if(visited[v_]) continue;\n        dfs(dfs,v_);\n\
    \      }\n      P.push_back(v);\n    };\n    for(int i = 0; i < n; ++i){\n   \
    \   if(visited[i]) continue;\n      dfs(dfs,i);\n    }\n    reverse(P.begin(),\
    \ P.end());\n  }\n  std::vector<std::vector<int>> G_rev(n);\n  for(int i = 0;\
    \ i < n; ++i){\n    for(auto j : G[i])\n      G_rev[j].push_back(i);\n  }\n  std::vector<int>\
    \ A(n,-1);\n  int t = 0;\n  auto dfs = [&](auto dfs, int v) -> void {\n    A[v]\
    \ = t;\n    for(auto v_ : G_rev[v]){\n      if(A[v_] >= 0) continue;\n      dfs(dfs,v_);\n\
    \    }\n  };\n  for(auto v : P){\n    if(A[v] >= 0) continue;\n    dfs(dfs,v);\n\
    \    ++t;\n  }\n  return A;\n}\n\n#line 7 \"test/LibraryChecker/scc.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>>\
    \ G(N);\n  for(int i = 0; i < M; ++i){\n    int a, b;\n    cin >> a >> b;\n  \
    \  G[a].emplace_back(b);\n  }\n  vector<int> C = scc_decompose(G);\n  int n =\
    \ *max_element(C.begin(), C.end()) + 1;\n  vector<vector<int>> V(n);\n  for(int\
    \ i = 0; i < N; ++i){\n    V[C[i]].emplace_back(i);\n  }\n  cout << n << '\\n';\n\
    \  for(auto v : V){\n    cout << v.size();\n    for(auto e : v)\n      cout <<\
    \ ' ' << e;\n    cout << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"Graph/SCCD.cpp\"\nusing namespace std;\n\nint\
    \ main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> G(N);\n  for(int\
    \ i = 0; i < M; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a].emplace_back(b);\n\
    \  }\n  vector<int> C = scc_decompose(G);\n  int n = *max_element(C.begin(), C.end())\
    \ + 1;\n  vector<vector<int>> V(n);\n  for(int i = 0; i < N; ++i){\n    V[C[i]].emplace_back(i);\n\
    \  }\n  cout << n << '\\n';\n  for(auto v : V){\n    cout << v.size();\n    for(auto\
    \ e : v)\n      cout << ' ' << e;\n    cout << '\\n';\n  }\n}\n"
  dependsOn:
  - Graph/SCCD.cpp
  isVerificationFile: true
  path: test/LibraryChecker/scc.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 02:45:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/scc.test.cpp
- /verify/test/LibraryChecker/scc.test.cpp.html
title: test/LibraryChecker/scc.test.cpp
---
