---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/CumulativeSum.cpp
    title: DataStructure/CumulativeSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/LibraryChecker/static_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"DataStructure/CumulativeSum.cpp\"\n\ntemplate<typename\
    \ T>\nstruct CumSum{\nprivate:\n  size_t size;\n  std::vector<T> data;\npublic:\n\
    \  CumSum(std::vector<T> dat){\n    size = dat.size();\n    data.resize(size+1,0);\n\
    \    for(size_t i = 0; i < size; ++i)\n      data[i+1] = data[i] + dat[i];\n \
    \ }\n  T getsum(size_t l, size_t r){//0-indexed, [l,r)\n    return data[r] - data[l];\n\
    \  }\n  T getsum(size_t r){//0-indexed, [0,r)\n    return data[r];\n  }\n};\n\
    #line 6 \"test/LibraryChecker/static_range_sum.test.cpp\"\nusing namespace std;\n\
    \nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  \n  int\
    \ N, Q;\n  cin >> N >> Q;\n  vector<long long> A(N);\n  for(int i = 0; i < N;\
    \ ++i){\n    cin >> A[i];\n  }\n  CumSum cumSum(A);\n  while(Q--){\n    int l,\
    \ r;\n    cin >> l >> r;\n    cout << cumSum.getsum(l,r) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"DataStructure/CumulativeSum.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int N, Q;\n  cin >> N >> Q;\n  vector<long long> A(N);\n  for(int i = 0;\
    \ i < N; ++i){\n    cin >> A[i];\n  }\n  CumSum cumSum(A);\n  while(Q--){\n  \
    \  int l, r;\n    cin >> l >> r;\n    cout << cumSum.getsum(l,r) << '\\n';\n \
    \ }\n}\n"
  dependsOn:
  - DataStructure/CumulativeSum.cpp
  isVerificationFile: true
  path: test/LibraryChecker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 20:24:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/static_range_sum.test.cpp
- /verify/test/LibraryChecker/static_range_sum.test.cpp.html
title: test/LibraryChecker/static_range_sum.test.cpp
---
