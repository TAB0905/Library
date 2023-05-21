---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/persistent_unionfind.test.cpp
    title: test/LibraryChecker/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UndoableUnionFind.cpp\"\n#include <vector>\n\
    #include <tuple>\n\nclass UndoableUnionFind{\n  std::vector<int> data;\n  int\
    \ num_connected_components_;\n  std::vector<std::tuple<int,int,int,int>> history;\n\
    public:\n  UndoableUnionFind(int n) :\n    data(n, -1), num_connected_components_(n),\
    \  history() {}\n  bool unite(int x, int y) noexcept {\n    x = find(x);\n   \
    \ y = find(y);\n    history.emplace_back(x,data[x],y,data[y]);\n    if(x != y){\n\
    \      --num_connected_components_;\n      if(data[y] < data[x]) std::swap(x,y);\n\
    \      data[x] += data[y];\n      data[y] = x;\n    }\n    return x != y;\n  }\n\
    \  void undo(){\n    auto [x,y,z,w] = history.back();\n    history.pop_back();\n\
    \    data[x] = y;\n    data[z] = w;\n    if(x != z) ++num_connected_components_;\n\
    \  }\n  bool same(int x, int y) noexcept {\n    return find(x) == find(y);\n \
    \ }\n  int find(int x) noexcept {\n    if(data[x] < 0) return x;\n    return find(data[x]);\n\
    \  }\n  int size(int x) noexcept {\n    return -data[find(x)];\n  }\n  int num_connected_components()\
    \ const noexcept {\n    return num_connected_components_;\n  }\n};\n"
  code: "#include <vector>\n#include <tuple>\n\nclass UndoableUnionFind{\n  std::vector<int>\
    \ data;\n  int num_connected_components_;\n  std::vector<std::tuple<int,int,int,int>>\
    \ history;\npublic:\n  UndoableUnionFind(int n) :\n    data(n, -1), num_connected_components_(n),\
    \  history() {}\n  bool unite(int x, int y) noexcept {\n    x = find(x);\n   \
    \ y = find(y);\n    history.emplace_back(x,data[x],y,data[y]);\n    if(x != y){\n\
    \      --num_connected_components_;\n      if(data[y] < data[x]) std::swap(x,y);\n\
    \      data[x] += data[y];\n      data[y] = x;\n    }\n    return x != y;\n  }\n\
    \  void undo(){\n    auto [x,y,z,w] = history.back();\n    history.pop_back();\n\
    \    data[x] = y;\n    data[z] = w;\n    if(x != z) ++num_connected_components_;\n\
    \  }\n  bool same(int x, int y) noexcept {\n    return find(x) == find(y);\n \
    \ }\n  int find(int x) noexcept {\n    if(data[x] < 0) return x;\n    return find(data[x]);\n\
    \  }\n  int size(int x) noexcept {\n    return -data[find(x)];\n  }\n  int num_connected_components()\
    \ const noexcept {\n    return num_connected_components_;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UndoableUnionFind.cpp
  requiredBy: []
  timestamp: '2023-05-21 17:57:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/persistent_unionfind.test.cpp
documentation_of: DataStructure/UndoableUnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UndoableUnionFind.cpp
- /library/DataStructure/UndoableUnionFind.cpp.html
title: DataStructure/UndoableUnionFind.cpp
---
