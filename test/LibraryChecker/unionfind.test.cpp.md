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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/LibraryChecker/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"DataStructure/UnionFind.cpp\"\
    \n#include <vector>\n\nclass UnionFind{\n  std::vector<int> data;\n  int num_connected_components_;\n\
    public:\n  UnionFind(int n) : data(n, -1), num_connected_components_(n) {}\n \
    \ bool unite(int x, int y) noexcept {\n    x = find(x);\n    y = find(y);\n  \
    \  if(x != y){\n      --num_connected_components_;\n      if(data[y] < data[x])\
    \ std::swap(x,y);\n      data[x] += data[y];\n      data[y] = x;\n    }\n    return\
    \ x != y;\n  }\n  bool same(int x, int y) noexcept {\n    return find(x) == find(y);\n\
    \  }\n  int find(int x) noexcept {\n    if(data[x] < 0) return x;\n    return\
    \ data[x] = find(data[x]);\n  }\n  int size(int x) noexcept {\n    return -data[find(x)];\n\
    \  }\n  int num_connected_components() const noexcept {\n    return num_connected_components_;\n\
    \  }\n};\n\n#line 4 \"test/LibraryChecker/unionfind.test.cpp\"\n#include <iostream>\n\
    #include <iomanip>\n#line 7 \"test/LibraryChecker/unionfind.test.cpp\"\nusing\
    \ namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
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
  timestamp: '2021-01-19 15:33:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/unionfind.test.cpp
- /verify/test/LibraryChecker/unionfind.test.cpp.html
title: test/LibraryChecker/unionfind.test.cpp
---
