---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
  bundledCode: "#line 1 \"test/AOJ/DSL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A\"\
    \n\n#include <iostream>\n#include <iomanip>\n#line 1 \"DataStructure/UnionFind.cpp\"\
    \n#include <vector>\n\nclass UnionFind{\n  std::vector<int> data;\npublic:\n \
    \ UnionFind(int n) : data(n, -1) {}\n  bool unite(int x, int y){\n    x = find(x);\n\
    \    y = find(y);\n    if(x != y){\n      if(data[y] < data[x]) std::swap(x,y);\n\
    \      data[x] += data[y];\n      data[y] = x;\n    }\n    return x != y;\n  }\n\
    \  bool same(int x, int y){ return find(x) == find(y); }\n  int find(int x){\n\
    \    if(data[x] < 0) return x;\n    return data[x] = find(data[x]);\n  }\n  int\
    \ size(int x){\n    return -data[find(x)];\n  }\n};\n\n#line 6 \"test/AOJ/DSL_1_A.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \n  int n, q;\n  cin >> n >> q;\n  UnionFind uf(n);\n  while(q--){\n    int c,\
    \ x, y;\n    cin >> c >> x >> y;\n    if(c){\n      cout << uf.same(x,y) << \"\
    \\n\";\n    }else{\n      uf.unite(x,y);\n    }\n  }\n}\n\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include \"DataStructure/UnionFind.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \n  int n, q;\n  cin >> n >> q;\n  UnionFind uf(n);\n  while(q--){\n    int c,\
    \ x, y;\n    cin >> c >> x >> y;\n    if(c){\n      cout << uf.same(x,y) << \"\
    \\n\";\n    }else{\n      uf.unite(x,y);\n    }\n  }\n}\n\n"
  dependsOn:
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-01-15 12:18:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_1_A.test.cpp
- /verify/test/AOJ/DSL_1_A.test.cpp.html
title: test/AOJ/DSL_1_A.test.cpp
---
