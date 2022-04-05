---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/PartiallyPersistentUnionFind.cpp
    title: DataStructure/PartiallyPersistentUnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc002/tasks/agc002_d
  bundledCode: "#line 1 \"test/AtCoder/AGC002D.cpp\"\n// problem https://atcoder.jp/contests/agc002/tasks/agc002_d\n\
    \n#include <iostream>\n\n#line 1 \"DataStructure/PartiallyPersistentUnionFind.cpp\"\
    \n#include <algorithm>\n#include <vector>\n#include <utility>\n\nclass PartiallyPersistentUnionFind{\n\
    \  std::vector<int> data;\n  std::vector<int> time;\n  int now;\n  std::vector<std::vector<std::pair<int,int>>>\
    \ size_;\n  std::vector<int> num_connected_components_;\npublic:\n  PartiallyPersistentUnionFind(int\
    \ n) :\n    data(n, -1), time(n,-1), now(0), size_(n,std::vector<std::pair<int,int>>(1,{0,1})),\n\
    \    num_connected_components_(n,0) {}\n  bool unite(int x, int y) noexcept {\n\
    \    ++now;\n    x = find(now,x);\n    y = find(now,y);\n    if(x != y){\n   \
    \   if(data[y] < data[x]) std::swap(x,y);\n      data[x] += data[y];\n      size_[x].emplace_back(now,-data[x]);\n\
    \      data[y] = x;\n      time[y] = now;\n    }\n    return x != y;\n  }\n  bool\
    \ same(int t, int x, int y) noexcept {\n    return find(t,x) == find(t,y);\n \
    \ }\n  int find(int t, int x) noexcept {\n    if(t < time[x]) return x;\n    if(data[x]\
    \ < 0) return x;\n    return find(t,data[x]);\n  }\n  int size(int t, int x) noexcept\
    \ {\n    const int n = data.size();\n    x = find(t,x);\n    return std::prev(std::upper_bound(size_[x].begin(),size_[x].end(),std::make_pair(t,n+1)))->second;\n\
    \  }\n  int num_connected_components(int t) noexcept {\n    return *std::prev(std::upper_bound(num_connected_components_.begin(),num_connected_components_.end(),t));\n\
    \  }\n};\n\n#line 6 \"test/AtCoder/AGC002D.cpp\"\n\nusing namespace std;\n\nint\
    \ main(){\n  int n, m;\n  cin >> n >> m;\n  PartiallyPersistentUnionFind uf(n);\n\
    \  for(int i = 0; i < m; ++i){\n    int a, b;\n    cin >> a >> b;\n    --a,--b;\n\
    \    uf.unite(a,b);\n  }\n  int q;\n  cin >> q;\n  while(q--){\n    int x, y,\
    \ z;\n    cin >> x >> y >> z;\n    --x,--y;\n    int ok = m+1, ng = 0;\n    while(abs(ok-ng)\
    \ > 1){\n      int t = (ok+ng)/2;\n      int s = uf.size(t,x) + uf.size(t,y) -\
    \ (uf.same(t,x,y) ? uf.size(t,x) : 0);\n      if(s >= z) ok = t;\n      else ng\
    \ = t;\n    }\n    cout << ok << '\\n';\n  }\n}\n"
  code: "// problem https://atcoder.jp/contests/agc002/tasks/agc002_d\n\n#include\
    \ <iostream>\n\n#include \"DataStructure/PartiallyPersistentUnionFind.cpp\"\n\n\
    using namespace std;\n\nint main(){\n  int n, m;\n  cin >> n >> m;\n  PartiallyPersistentUnionFind\
    \ uf(n);\n  for(int i = 0; i < m; ++i){\n    int a, b;\n    cin >> a >> b;\n \
    \   --a,--b;\n    uf.unite(a,b);\n  }\n  int q;\n  cin >> q;\n  while(q--){\n\
    \    int x, y, z;\n    cin >> x >> y >> z;\n    --x,--y;\n    int ok = m+1, ng\
    \ = 0;\n    while(abs(ok-ng) > 1){\n      int t = (ok+ng)/2;\n      int s = uf.size(t,x)\
    \ + uf.size(t,y) - (uf.same(t,x,y) ? uf.size(t,x) : 0);\n      if(s >= z) ok =\
    \ t;\n      else ng = t;\n    }\n    cout << ok << '\\n';\n  }\n}\n"
  dependsOn:
  - DataStructure/PartiallyPersistentUnionFind.cpp
  isVerificationFile: false
  path: test/AtCoder/AGC002D.cpp
  requiredBy: []
  timestamp: '2022-04-05 23:28:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/AtCoder/AGC002D.cpp
layout: document
redirect_from:
- /library/test/AtCoder/AGC002D.cpp
- /library/test/AtCoder/AGC002D.cpp.html
title: test/AtCoder/AGC002D.cpp
---
