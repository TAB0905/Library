---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/TopologicalSort.cpp
    title: Graph/TopologicalSort.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
  bundledCode: "#line 1 \"test/AOJ/GRL_4_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Graph/TopologicalSort.cpp\"\
    \n#include <queue>\n\nstd::vector<int> toposort(std::vector<std::vector<int>>\
    \ &G){\n  size_t N = G.size();\n  std::vector<int> ret, d_in(N,0);\n  for(size_t\
    \ i = 0; i < N; ++i)\n    for(size_t j = 0; j < G[i].size(); ++j)\n      ++d_in[G[i][j]];\n\
    \  // std::queue<int> wait;\n  std::vector<int> wait;\n  for(size_t i = 0; i <\
    \ N; ++i)\n    if(!d_in[i]) wait.emplace_back(i);\n  while(!wait.empty()){\n \
    \   int v = wait.back();\n    wait.pop_back();\n    ret.emplace_back(v);\n   \
    \ for(size_t i = 0; i < G[v].size(); ++i){\n      int v_ = G[v][i];\n      --d_in[v_];\n\
    \      if(!d_in[v_]) wait.emplace_back(v_);\n    }\n  }\n  return ret;\n}\n\n\
    #line 6 \"test/AOJ/GRL_4_B.test.cpp\"\n\nusing namespace std;\n\nint main(){\n\
    \  int N, M;\n  cin >> N >> M;\n  vector< vector<int> > G(N);\n  for(int i = 0;\
    \ i < M; ++i){\n    int s, t;\n    cin >> s >> t;\n    G[s].emplace_back(t);\n\
    \  }\n  vector<int> order = toposort(G);\n  for(int i = 0; i < N; ++i)\n    cout\
    \ << order[i] << endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Graph/TopologicalSort.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  int N, M;\n  cin >> N >> M;\n  vector<\
    \ vector<int> > G(N);\n  for(int i = 0; i < M; ++i){\n    int s, t;\n    cin >>\
    \ s >> t;\n    G[s].emplace_back(t);\n  }\n  vector<int> order = toposort(G);\n\
    \  for(int i = 0; i < N; ++i)\n    cout << order[i] << endl;\n  return 0;\n}\n"
  dependsOn:
  - Graph/TopologicalSort.cpp
  isVerificationFile: true
  path: test/AOJ/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2021-05-01 20:44:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_4_B.test.cpp
- /verify/test/AOJ/GRL_4_B.test.cpp.html
title: test/AOJ/GRL_4_B.test.cpp
---
