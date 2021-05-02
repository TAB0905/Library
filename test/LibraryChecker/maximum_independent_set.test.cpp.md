---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/MaximumIndependentSet.cpp
    title: Graph/MaximumIndependentSet.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/LibraryChecker/maximum_independent_set.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\n\
    #include <vector>\n#line 1 \"Graph/MaximumIndependentSet.cpp\"\n#include <utility>\n\
    #include <iostream>\n#line 4 \"Graph/MaximumIndependentSet.cpp\"\n\n// n = G.size()\
    \ <= 63 \u3058\u3083\u306A\u3044\u3068\u58CA\u308C\u308B\n// \u7AF6\u30D7\u30ED\
    \ TL 2sec \u304F\u3089\u3044\u306A\u3089\u56F0\u308B\u3053\u3068\u306F\u306A\u3044\
    \u306F\u305A\nlong long maximum_independent_set_size(const std::vector<long long>&\
    \ G, int v, long long int t=0){\n  const int n = G.size();\n  if(v >= n or t ==\
    \ (1LL<<n) - 1LL) return 0;\n\n  long long ret = 0;\n  if(!(t>>v & 1)){\n    long\
    \ long t_ = t | (1LL<<v);\n    t_ |= G[v];\n    int v_ = v + 1;\n    while(t_>>v_\
    \ & 1) ++v_;\n    ret = maximum_independent_set_size(G,v_,t_)|1LL<<v;\n    if(__builtin_popcountll(t^t_)\
    \ <= 2) return ret; // d(v) <= 1\n  }\n  int v_ = v + 1;\n  while(t>>v_ & 1) ++v_;\n\
    \  t |= 1LL<<v;\n  long long ret_ = maximum_independent_set_size(G,v_,t);\n  if(__builtin_popcountll(ret)\
    \ < __builtin_popcountll(ret_))\n    std::swap(ret,ret_);\n  return ret;\n}\n\
    #line 5 \"test/LibraryChecker/maximum_independent_set.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  int n, m;\n  cin >> n >> m;\n  vector<long long> G(n);\n\
    \  for(int i = 0; i < m; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a] |=\
    \ 1LL<<b;\n    G[b] |= 1LL<<a;\n  }\n  long long ans = maximum_independent_set_size(G,0,0);\n\
    \  int a = __builtin_popcountll(ans);\n  cout << a << endl;\n  for(int i = 0;\
    \ i < n; ++i){\n    if(ans>>i&1) cout << i << (--a ? ' ' : '\\n');\n  }\n  cout\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include <vector>\n#include \"Graph/MaximumIndependentSet.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  int n, m;\n  cin >> n >> m;\n  vector<long long> G(n);\n\
    \  for(int i = 0; i < m; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a] |=\
    \ 1LL<<b;\n    G[b] |= 1LL<<a;\n  }\n  long long ans = maximum_independent_set_size(G,0,0);\n\
    \  int a = __builtin_popcountll(ans);\n  cout << a << endl;\n  for(int i = 0;\
    \ i < n; ++i){\n    if(ans>>i&1) cout << i << (--a ? ' ' : '\\n');\n  }\n  cout\
    \ << endl;\n}\n"
  dependsOn:
  - Graph/MaximumIndependentSet.cpp
  isVerificationFile: true
  path: test/LibraryChecker/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2021-05-02 20:29:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/maximum_independent_set.test.cpp
- /verify/test/LibraryChecker/maximum_independent_set.test.cpp.html
title: test/LibraryChecker/maximum_independent_set.test.cpp
---
