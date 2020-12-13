---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/UnionFind.cpp
    title: DataStructure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/LibraryChecker/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"DataStructure/UnionFind.cpp\"\
    \n#include <vector>\n\nstruct UnionFind{\n  std::vector<int> data;\n  UnionFind(int\
    \ n) : data(n, -1) {}\n  bool unite(int x, int y){\n    x = find(x);\n    y =\
    \ find(y);\n    if(x != y){\n      if(data[y] < data[x]) std::swap(x,y);\n   \
    \   data[x] += data[y];//\u9AD8\u3055\u3092\u66F4\u65B0\n      data[y] = x;//\u89AA\
    \u3092\u66F4\u65B0\n    }\n    return x != y;\n  }\n  bool same(int x, int y){\
    \ return find(x) == find(y); }\n  int find(int x){\n    if(data[x] < 0) return\
    \ x;\n    return data[x] = find(data[x]);\n  }\n};\n\n#line 4 \"test/LibraryChecker/unionfind.test.cpp\"\
    \n#include <iostream>\n#include <iomanip>\n#line 7 \"test/LibraryChecker/unionfind.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  UnionFind uf(N);\n  while(Q--){\n    int t,\
    \ u, v;\n    cin >> t >> u >> v;\n    if(t){\n      cout << uf.same(u,v) << '\\\
    n';\n    }else{\n      uf.unite(u,v);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"DataStructure/UnionFind.cpp\"\n#include <iostream>\n#include <iomanip>\n#include\
    \ <vector>\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  UnionFind uf(N);\n  while(Q--){\n    int t,\
    \ u, v;\n    cin >> t >> u >> v;\n    if(t){\n      cout << uf.same(u,v) << '\\\
    n';\n    }else{\n      uf.unite(u,v);\n    }\n  }\n}\n"
  dependsOn:
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: test/LibraryChecker/unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 21:55:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/unionfind.test.cpp
- /verify/test/LibraryChecker/unionfind.test.cpp.html
title: test/LibraryChecker/unionfind.test.cpp
---
