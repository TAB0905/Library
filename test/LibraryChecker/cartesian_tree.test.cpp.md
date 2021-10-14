---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/CartesianTree.cpp
    title: Graph/CartesianTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/LibraryChecker/cartesian_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"Graph/CartesianTree.cpp\"\n\ntemplate<typename T>\n\
    std::vector<int> cartesian_tree(const std::vector<T>& A){\n  const int n = A.size();\n\
    \  std::vector<int> P(n);\n  P[0] = -1;\n  for(int i = 1; i < n; ++i){\n    P[i]\
    \ = i-1;\n    int p = i-1, l = -1;\n    while(p >= 0 and A[p] > A[i]){\n     \
    \ P[i] = P[p];\n      P[p] = i;\n      if(l >= 0) P[l] = p;\n      l = p;\n  \
    \    p = P[i];\n    }\n  }\n  return P;\n}\n\n#line 6 \"test/LibraryChecker/cartesian_tree.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int n;\n  cin >> n;\n  vector<int> A(n);\n\
    \  for(int i = 0; i < n; ++i)\n    cin >> A[i];\n  auto P = cartesian_tree(A);\n\
    \  for(int i = 0; i < n; ++i){\n    cout << (P[i] >= 0 ? P[i] : i) << (i+1 < n\
    \ ? ' ' : '\\n');\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"Graph/CartesianTree.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  int n;\n  cin >> n;\n  vector<int> A(n);\n  for(int i\
    \ = 0; i < n; ++i)\n    cin >> A[i];\n  auto P = cartesian_tree(A);\n  for(int\
    \ i = 0; i < n; ++i){\n    cout << (P[i] >= 0 ? P[i] : i) << (i+1 < n ? ' ' :\
    \ '\\n');\n  }\n}\n"
  dependsOn:
  - Graph/CartesianTree.cpp
  isVerificationFile: true
  path: test/LibraryChecker/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2021-10-15 01:32:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/cartesian_tree.test.cpp
- /verify/test/LibraryChecker/cartesian_tree.test.cpp.html
title: test/LibraryChecker/cartesian_tree.test.cpp
---
