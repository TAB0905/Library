---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"test/LibraryChecker/static_range_sum.test.cpp\"\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  \n  int N, Q;\n  cin >> N >> Q;\n  vector<long\
    \ long> A(N);\n  for(int i = 0; i < N; ++i){\n    cin >> A[i];\n  }\n  CumSum\
    \ cumSum(A);\n  while(Q--){\n    int l, r;\n    cin >> l >> r;\n    cout << cumSum.getsum(l,r)\
    \ << '\\n';\n  }\n}\n"
  code: "#include <iostream>\n#include <vector>\nusing namespace std;\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  \n  int N, Q;\n  cin >>\
    \ N >> Q;\n  vector<long long> A(N);\n  for(int i = 0; i < N; ++i){\n    cin >>\
    \ A[i];\n  }\n  CumSum cumSum(A);\n  while(Q--){\n    int l, r;\n    cin >> l\
    \ >> r;\n    cout << cumSum.getsum(l,r) << '\\n';\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 20:16:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/static_range_sum.test.cpp
- /verify/test/LibraryChecker/static_range_sum.test.cpp.html
title: test/LibraryChecker/static_range_sum.test.cpp
---
