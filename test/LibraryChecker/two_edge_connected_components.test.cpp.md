---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Lowlink.cpp
    title: Graph/Lowlink.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/LibraryChecker/two_edge_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <cstdio>\n#include <vector>\n#include <utility>\n#line 1 \"Graph/Lowlink.cpp\"\
    \n#include <algorithm>\n#include <cassert>\n#line 5 \"Graph/Lowlink.cpp\"\n#include\
    \ <stack>\n\nstruct DecomposedGraph {\n  std::vector<std::vector<int>> graph;\n\
    \  std::vector<std::pair<int,int>> bridge;\n  std::vector<std::vector<int>> components;\n\
    \  std::vector<int> affiliation;\n};\n\nDecomposedGraph TwoEdgeConnectedComponentsDeconposition(const\
    \ std::vector<std::pair<int,int>>& E, int n){\n  int m = E.size();\n  \n  struct\
    \ edge {\n    int to, idx;\n    edge(int to, int idx) : to(to), idx(idx) {}\n\
    \  };\n\n  std::vector<std::vector<edge>> G(n);\n  for(int i = 0; i < m; ++i){\n\
    \    const auto& e = E[i];\n    G[e.first].emplace_back(e.second,i);\n    G[e.second].emplace_back(e.first,i);\n\
    \  }\n\n  DecomposedGraph ret;\n  std::vector<int> low(n), ord(n,-1), node_idx(n,-1);\n\
    \  std::stack<int> st;\n  int t = 0;\n  auto lowlink = [&](auto lowlink, int v,\
    \ int edge_idx) -> void {\n                   st.push(v);\n                  \
    \ ord[v] = t++;\n                   low[v] = ord[v];\n                   for(const\
    \ auto& e : G[v]){\n                     if(e.idx == edge_idx) continue;\n   \
    \                  int v_ = e.to, idx = e.idx;\n                     if(ord[v_]\
    \ >= 0){\n                       low[v] = std::min(low[v],ord[v_]);\n        \
    \             }else{\n                       lowlink(lowlink,v_,idx);\n      \
    \                 low[v] = std::min(low[v],low[v_]);\n                     }\n\
    \                     if(ord[v] < low[v_]){// u-v is bridge\n                \
    \       std::vector<int> cc;\n                       int n_idx = ret.components.size();\n\
    \                       while(true){\n                         int tp = st.top();\n\
    \                         cc.push_back(tp);\n                         node_idx[tp]\
    \ = n_idx;\n                         st.pop();\n                         if(tp\
    \ == v_) break;\n                       }\n                       ret.components.push_back(cc);\n\
    \                       ret.bridge.push_back(E[idx]);\n                     }\n\
    \                   }\n                 };\n\n  for(int i = 0; i < n; ++i){\n\
    \    if(ord[i] >= 0) continue;\n    lowlink(lowlink,i,-1);\n\n    std::vector<int>\
    \ cc;\n    int idx = ret.components.size();\n    while(st.size()){\n      cc.push_back(st.top());\n\
    \      node_idx[st.top()] = idx;\n      st.pop();\n    }\n    ret.components.push_back(cc);\n\
    \  }\n\n  ret.affiliation = node_idx;\n  int n_ = ret.components.size();\n  ret.graph.resize(n_);\n\
    \  for(auto b : ret.bridge){\n    int u = node_idx[b.first], v = node_idx[b.second];\n\
    \    assert(u != v);\n    ret.graph[u].emplace_back(v);\n    ret.graph[v].emplace_back(u);\n\
    \  }\n  return ret;\n}\n\n#line 7 \"test/LibraryChecker/two_edge_connected_components.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int n, m;\n  scanf(\"%d %d\",&n,&m);\n\
    \n  vector<pair<int,int>> E;\n  for(int i = 0; i < m; ++i){\n    int x, y;\n \
    \   scanf(\"%d %d\",&x,&y);\n    E.emplace_back(x,y);\n  }\n\n  auto G = TwoEdgeConnectedComponentsDeconposition(E,n);\n\
    \n  printf(\"%zu\\n\",G.components.size());\n  for(auto c : G.components){\n \
    \   printf(\"%zu \",c.size());\n    for(size_t i = 0; i < c.size(); ++i)\n   \
    \   printf(\"%d%c\",c[i],(i+1 < c.size() ? ' ' : '\\n'));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <cstdio>\n#include <vector>\n#include <utility>\n#include \"Graph/Lowlink.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int n, m;\n  scanf(\"%d %d\",&n,&m);\n\
    \n  vector<pair<int,int>> E;\n  for(int i = 0; i < m; ++i){\n    int x, y;\n \
    \   scanf(\"%d %d\",&x,&y);\n    E.emplace_back(x,y);\n  }\n\n  auto G = TwoEdgeConnectedComponentsDeconposition(E,n);\n\
    \n  printf(\"%zu\\n\",G.components.size());\n  for(auto c : G.components){\n \
    \   printf(\"%zu \",c.size());\n    for(size_t i = 0; i < c.size(); ++i)\n   \
    \   printf(\"%d%c\",c[i],(i+1 < c.size() ? ' ' : '\\n'));\n  }\n}\n"
  dependsOn:
  - Graph/Lowlink.cpp
  isVerificationFile: true
  path: test/LibraryChecker/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 02:37:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/two_edge_connected_components.test.cpp
- /verify/test/LibraryChecker/two_edge_connected_components.test.cpp.html
title: test/LibraryChecker/two_edge_connected_components.test.cpp
---
