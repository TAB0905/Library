---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UndoableUnionFind.cpp
    title: DataStructure/UndoableUnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/LibraryChecker/persistent_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <tuple>\n#line 1 \"DataStructure/UndoableUnionFind.cpp\"\
    \n#include <vector>\n#line 3 \"DataStructure/UndoableUnionFind.cpp\"\n\nclass\
    \ UndoableUnionFind{\n  std::vector<int> data;\n  int num_connected_components_;\n\
    \  std::vector<std::tuple<int,int,int,int>> history;\npublic:\n  UndoableUnionFind(int\
    \ n) :\n    data(n, -1), num_connected_components_(n),  history() {}\n  bool unite(int\
    \ x, int y) noexcept {\n    x = find(x);\n    y = find(y);\n    history.emplace_back(x,data[x],y,data[y]);\n\
    \    if(x != y){\n      --num_connected_components_;\n      if(data[y] < data[x])\
    \ std::swap(x,y);\n      data[x] += data[y];\n      data[y] = x;\n    }\n    return\
    \ x != y;\n  }\n  void undo(){\n    auto [x,y,z,w] = history.back();\n    history.pop_back();\n\
    \    data[x] = y;\n    data[z] = w;\n    if(x != z) ++num_connected_components_;\n\
    \  }\n  bool same(int x, int y) noexcept {\n    return find(x) == find(y);\n \
    \ }\n  int find(int x) noexcept {\n    if(data[x] < 0) return x;\n    return find(data[x]);\n\
    \  }\n  int size(int x) noexcept {\n    return -data[find(x)];\n  }\n  int num_connected_components()\
    \ const noexcept {\n    return num_connected_components_;\n  }\n};\n#line 7 \"\
    test/LibraryChecker/persistent_unionfind.test.cpp\"\nusing namespace std;\n\n\
    int main(){\n  int n, q;\n  cin >> n >> q;\n  vector<vector<tuple<int,int,int>>>\
    \ Q(q+1);\n  vector<vector<tuple<int,int,int>>> G(q+1);\n  for(int i = 1; i <=\
    \ q; ++i){\n    int t, k, u, v;\n    cin >> t >> k >> u >> v;\n    ++k;\n    if(t){\n\
    \      Q[k].emplace_back(i,u,v);\n    }else{\n      G[k].emplace_back(i,u,v);\n\
    \    }\n  }\n  vector<tuple<int,int>> ans;\n  UndoableUnionFind uf(n);\n  auto\
    \ rec = [&](auto&& rec, int v) -> void {\n    for(auto [i,a,b]: Q[v]){\n     \
    \ ans.emplace_back(i,uf.same(a,b));\n    }\n    for(auto [u,a,b]: G[v]){\n   \
    \   uf.unite(a,b);\n      rec(rec,u);\n      uf.undo();\n    }\n  };\n  rec(rec,0);\n\
    \  sort(ans.begin(),ans.end());\n  for(auto [i,a]: ans)\n    cout << a << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <algorithm>\n#include <iostream>\n#include <tuple>\n#include \"DataStructure/UndoableUnionFind.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int n, q;\n  cin >> n >> q;\n  vector<vector<tuple<int,int,int>>>\
    \ Q(q+1);\n  vector<vector<tuple<int,int,int>>> G(q+1);\n  for(int i = 1; i <=\
    \ q; ++i){\n    int t, k, u, v;\n    cin >> t >> k >> u >> v;\n    ++k;\n    if(t){\n\
    \      Q[k].emplace_back(i,u,v);\n    }else{\n      G[k].emplace_back(i,u,v);\n\
    \    }\n  }\n  vector<tuple<int,int>> ans;\n  UndoableUnionFind uf(n);\n  auto\
    \ rec = [&](auto&& rec, int v) -> void {\n    for(auto [i,a,b]: Q[v]){\n     \
    \ ans.emplace_back(i,uf.same(a,b));\n    }\n    for(auto [u,a,b]: G[v]){\n   \
    \   uf.unite(a,b);\n      rec(rec,u);\n      uf.undo();\n    }\n  };\n  rec(rec,0);\n\
    \  sort(ans.begin(),ans.end());\n  for(auto [i,a]: ans)\n    cout << a << '\\\
    n';\n}\n"
  dependsOn:
  - DataStructure/UndoableUnionFind.cpp
  isVerificationFile: true
  path: test/LibraryChecker/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-05-21 18:00:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/persistent_unionfind.test.cpp
- /verify/test/LibraryChecker/persistent_unionfind.test.cpp.html
title: test/LibraryChecker/persistent_unionfind.test.cpp
---
