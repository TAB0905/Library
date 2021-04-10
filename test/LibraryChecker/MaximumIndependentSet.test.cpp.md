---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/MaximumIndependentSet.cpp
    title: Graph/MaximumIndependentSet.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://old.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/LibraryChecker/MaximumIndependentSet.test.cpp\"\n#define\
    \ IGNORE\n#define PROBLEM \"https://old.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include <vector>\n#line 1 \"Graph/MaximumIndependentSet.cpp\"\n#include <utility>\n\
    #include <iostream>\n#line 4 \"Graph/MaximumIndependentSet.cpp\"\n\nlong long\
    \ solve(const std::vector<long long>& G, int v, long long int t=0){\n  const int\
    \ n = G.size();\n  if(v >= n or t == (1LL<<n) - 1LL) return 0;\n\n  long long\
    \ ret = 0;\n  if(!(t>>v & 1)){\n    long long t_ = t | (1LL<<v);\n    t_ |= G[v];\n\
    \    int v_ = v + 1;\n    while(t_>>v_ & 1) ++v_;\n    ret = solve(G,v_,t_)|1LL<<v;\n\
    \    if(__builtin_popcountll(t^t_) <= 2) return ret; // d(v) <= 1\n  }\n  int\
    \ v_ = v + 1;\n  while(t>>v_ & 1) ++v_;\n  t |= 1LL<<v;\n  long long ret_ = solve(G,v_,t);\n\
    \  if(__builtin_popcountll(ret) < __builtin_popcountll(ret_))\n    std::swap(ret,ret_);\n\
    \  return ret;\n}\n#line 6 \"test/LibraryChecker/MaximumIndependentSet.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int n, m;\n  cin >> n >> m;\n  vector<long\
    \ long> G(n);\n  for(int i = 0; i < m; ++i){\n    int a, b;\n    cin >> a >> b;\n\
    \    G[a] |= 1LL<<b;\n    G[b] |= 1LL<<a;\n  }\n  long long ans = solve(G,0,0);\n\
    \  int a = __builtin_popcountll(ans);\n  cout << a << endl;\n  for(int i = 0;\
    \ i < n; ++i){\n    if(ans>>i&1) cout << i << (--a ? ' ' : '\\n');\n  }\n  cout\
    \ << endl;\n}\n"
  code: "#define IGNORE\n#define PROBLEM \"https://old.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include <vector>\n#include \"Graph/MaximumIndependentSet.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  int n, m;\n  cin >> n >> m;\n  vector<long long> G(n);\n\
    \  for(int i = 0; i < m; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a] |=\
    \ 1LL<<b;\n    G[b] |= 1LL<<a;\n  }\n  long long ans = solve(G,0,0);\n  int a\
    \ = __builtin_popcountll(ans);\n  cout << a << endl;\n  for(int i = 0; i < n;\
    \ ++i){\n    if(ans>>i&1) cout << i << (--a ? ' ' : '\\n');\n  }\n  cout << endl;\n\
    }\n"
  dependsOn:
  - Graph/MaximumIndependentSet.cpp
  isVerificationFile: true
  path: test/LibraryChecker/MaximumIndependentSet.test.cpp
  requiredBy: []
  timestamp: '2021-03-21 18:52:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/MaximumIndependentSet.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/MaximumIndependentSet.test.cpp
- /verify/test/LibraryChecker/MaximumIndependentSet.test.cpp.html
title: test/LibraryChecker/MaximumIndependentSet.test.cpp
---
