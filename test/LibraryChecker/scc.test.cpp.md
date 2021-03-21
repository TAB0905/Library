---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/SCCD.cpp
    title: Graph/SCCD.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/LibraryChecker/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\n#line 1 \"Graph/SCCD.cpp\"\
    \n#include <algorithm>\n#include <cassert>\n#line 5 \"Graph/SCCD.cpp\"\n#include\
    \ <set>\n\nstruct SCCDecomposedGraph {\n  std::vector<std::vector<int>> dag;\n\
    \  std::vector<std::vector<int>> scc;\n  std::vector<int> cmp;\n};\n\nSCCDecomposedGraph\
    \ scc_decompose(const std::vector<std::vector<int>>& G){\n  const int n = G.size();\n\
    \  std::vector<int> ord(n,-1), low(n), st;\n  SCCDecomposedGraph ret;\n  int num_scc\
    \ = 0;\n  ret.cmp.resize(n,-1);\n  auto dfs = [&](auto&& dfs, int v, int& tm)\
    \ -> void {\n    low[v] = tm;\n    ord[v] = tm;\n    ++tm;\n    st.emplace_back(v);\n\
    \    for(auto u : G[v]){\n      if(ord[u] < 0){\n        dfs(dfs,u,tm);\n    \
    \    low[v] = std::min(low[v],low[u]);\n      }else if(ret.cmp[u] < 0){\n    \
    \    low[v] = std::min(low[v],ord[u]);\n      }\n    }\n    if(ord[v] == low[v]){\n\
    \      ret.scc.push_back({});\n      while(true){\n        const int u = st.back();\n\
    \        st.pop_back();\n        ret.scc.back().emplace_back(u);\n        ret.cmp[u]\
    \ = num_scc;\n        if(v == u) break;\n      }\n      ++num_scc;\n    }\n  };\n\
    \  int tm = 0;\n  for(int i = 0; i < n; ++i){\n    if(ord[i] < 0) dfs(dfs,i,tm);\n\
    \  }\n  reverse(ret.scc.begin(),ret.scc.end());\n  for(int i = 0; i < n; ++i){\n\
    \    ret.cmp[i] = num_scc - 1 - ret.cmp[i];\n  }\n  ret.dag.resize(num_scc);\n\
    \  for(int i = 0; i < n; ++i){\n    int v = ret.cmp[i];\n    for(auto j : G[i]){\n\
    \      int u = ret.cmp[j];\n      if(v != u){\n        ret.dag[v].emplace_back(u);\n\
    \      }\n    }\n    sort(ret.dag[v].begin(),ret.dag[v].end());\n    ret.dag[v].erase(unique(ret.dag[v].begin(),ret.dag[v].end()),ret.dag[v].end());\n\
    \  }\n  return ret;\n}\n\n#line 8 \"test/LibraryChecker/scc.test.cpp\"\nusing\
    \ namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> G(N);\n  for(int i =\
    \ 0; i < M; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a].emplace_back(b);\n\
    \  }\n  auto ret = scc_decompose(G);\n  cout << ret.scc.size() << '\\n';\n  for(auto\
    \ &scc : ret.scc){\n    cout << scc.size();\n    for(auto e : scc)\n      cout\
    \ << ' ' << e;\n    cout << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include <iomanip>\n#include <vector>\n\n#include \"Graph/SCCD.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n \
    \ \n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> G(N);\n  for(int i =\
    \ 0; i < M; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a].emplace_back(b);\n\
    \  }\n  auto ret = scc_decompose(G);\n  cout << ret.scc.size() << '\\n';\n  for(auto\
    \ &scc : ret.scc){\n    cout << scc.size();\n    for(auto e : scc)\n      cout\
    \ << ' ' << e;\n    cout << '\\n';\n  }\n}\n"
  dependsOn:
  - Graph/SCCD.cpp
  isVerificationFile: true
  path: test/LibraryChecker/scc.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 16:59:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/scc.test.cpp
- /verify/test/LibraryChecker/scc.test.cpp.html
title: test/LibraryChecker/scc.test.cpp
---
