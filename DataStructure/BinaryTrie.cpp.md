---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/predecessor_problem.test.cpp
    title: test/LibraryChecker/predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/set_xor_min.test.cpp
    title: test/LibraryChecker/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryTrie.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n\ntemplate<typename T, int len>\nclass BinaryTrie {\nprivate:\n \
    \ struct Node {\n    T size;\n    Node* parent;\n    Node* children[2];\n    Node()\
    \ : size(0), parent(nullptr), children{nullptr,nullptr} {}\n  };\n  \n  Node*\
    \ const root;\n  T xor_value;\npublic:\n  BinaryTrie() : root(new Node), xor_value(0)\
    \ {}\n  constexpr void insert(T x, T cnt=1) noexcept {\n    x ^= xor_value;\n\
    \    Node* v = root;\n    v->size += cnt;\n    for(int i = len-1; i >= 0; --i){\n\
    \      int b = (x>>i)&1;\n      if(v->children[b] == nullptr){\n        v->children[b]\
    \ = new Node;\n        v->children[b]->parent = v;\n      }\n      v = v->children[b];\n\
    \      v->size += cnt;\n    }\n  }\n  constexpr void erase(T x, T cnt=1) noexcept\
    \ {\n    Node* v = root;\n    cnt = std::min(cnt,count(x));\n    x ^= xor_value;\n\
    \    if(!cnt) return;\n    v->size -= cnt;\n    for(int i = len-1; i >= 0; --i){\n\
    \      int b = (x>>i)&1;\n      v = v->children[b];\n      v->size -= cnt;\n \
    \   }\n    for(int i = 0; i < len; ++i){\n      if(v->size) break;\n      auto\
    \ p = v->parent;\n      int b = (x>>i)&1;\n      p->children[b] = nullptr;\n \
    \     v->parent = nullptr;\n      v = p;\n    }\n  }\n  constexpr T count(T x)\
    \ const noexcept {\n    Node* v = root;\n    x ^= xor_value;\n    for(int i =\
    \ len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b] == nullptr)\n\
    \        return 0;\n      v = v->children[b];\n    }\n    return v->size;\n  }\n\
    \  constexpr T kth_element(int k) const noexcept {// 1-indexed\n    Node* v =\
    \ root;\n    T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n      int b = (xor_value>>i)&1;\n\
    \      if(v->children[b] == nullptr or\n         v->children[b]->size < k){\n\
    \        if(v->children[b] != nullptr)\n          k -= v->children[b]->size;\n\
    \        b ^= 1;\n      }\n      ret <<= 1;\n      ret |= b;\n      v = v->children[b];\n\
    \    }\n\n    return ret^xor_value;\n  }\n  constexpr T count_leq(T x) const noexcept\
    \ {\n    Node* v = root;\n    T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n\
    \      int b = ((xor_value^x)>>i)&1;\n      int t = (x>>i)&1;\n      if(t and\
    \ v->children[b^1] != nullptr)\n        ret += v->children[b^1]->size;\n     \
    \ if(v->children[b] == nullptr){\n        return ret;\n      }\n      v = v->children[b];\n\
    \    }\n    return ret+v->size;\n  }\n  constexpr T count_geq(T x) const noexcept\
    \ {\n    Node* v = root;\n    T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n\
    \      int b = ((xor_value^x)>>i)&1;\n      int t = (x>>i)&1;\n      if((!t) and\
    \ v->children[b^1] != nullptr)\n        ret += v->children[b^1]->size;\n     \
    \ if(v->children[b] == nullptr){\n        return ret;\n      }\n      v = v->children[b];\n\
    \    }\n    return ret+v->size;\n  }\n  constexpr void xor_all(T x) noexcept {\n\
    \    xor_value ^= x;\n  }\n  constexpr T size() const noexcept {\n    return root->size;\n\
    \  }\n};\n"
  code: "#include <algorithm>\n#include <cassert>\n\ntemplate<typename T, int len>\n\
    class BinaryTrie {\nprivate:\n  struct Node {\n    T size;\n    Node* parent;\n\
    \    Node* children[2];\n    Node() : size(0), parent(nullptr), children{nullptr,nullptr}\
    \ {}\n  };\n  \n  Node* const root;\n  T xor_value;\npublic:\n  BinaryTrie() :\
    \ root(new Node), xor_value(0) {}\n  constexpr void insert(T x, T cnt=1) noexcept\
    \ {\n    x ^= xor_value;\n    Node* v = root;\n    v->size += cnt;\n    for(int\
    \ i = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b] ==\
    \ nullptr){\n        v->children[b] = new Node;\n        v->children[b]->parent\
    \ = v;\n      }\n      v = v->children[b];\n      v->size += cnt;\n    }\n  }\n\
    \  constexpr void erase(T x, T cnt=1) noexcept {\n    Node* v = root;\n    cnt\
    \ = std::min(cnt,count(x));\n    x ^= xor_value;\n    if(!cnt) return;\n    v->size\
    \ -= cnt;\n    for(int i = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n   \
    \   v = v->children[b];\n      v->size -= cnt;\n    }\n    for(int i = 0; i <\
    \ len; ++i){\n      if(v->size) break;\n      auto p = v->parent;\n      int b\
    \ = (x>>i)&1;\n      p->children[b] = nullptr;\n      v->parent = nullptr;\n \
    \     v = p;\n    }\n  }\n  constexpr T count(T x) const noexcept {\n    Node*\
    \ v = root;\n    x ^= xor_value;\n    for(int i = len-1; i >= 0; --i){\n     \
    \ int b = (x>>i)&1;\n      if(v->children[b] == nullptr)\n        return 0;\n\
    \      v = v->children[b];\n    }\n    return v->size;\n  }\n  constexpr T kth_element(int\
    \ k) const noexcept {// 1-indexed\n    Node* v = root;\n    T ret = 0;\n    for(int\
    \ i = len-1; i >= 0; --i){\n      int b = (xor_value>>i)&1;\n      if(v->children[b]\
    \ == nullptr or\n         v->children[b]->size < k){\n        if(v->children[b]\
    \ != nullptr)\n          k -= v->children[b]->size;\n        b ^= 1;\n      }\n\
    \      ret <<= 1;\n      ret |= b;\n      v = v->children[b];\n    }\n\n    return\
    \ ret^xor_value;\n  }\n  constexpr T count_leq(T x) const noexcept {\n    Node*\
    \ v = root;\n    T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n      int b\
    \ = ((xor_value^x)>>i)&1;\n      int t = (x>>i)&1;\n      if(t and v->children[b^1]\
    \ != nullptr)\n        ret += v->children[b^1]->size;\n      if(v->children[b]\
    \ == nullptr){\n        return ret;\n      }\n      v = v->children[b];\n    }\n\
    \    return ret+v->size;\n  }\n  constexpr T count_geq(T x) const noexcept {\n\
    \    Node* v = root;\n    T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n \
    \     int b = ((xor_value^x)>>i)&1;\n      int t = (x>>i)&1;\n      if((!t) and\
    \ v->children[b^1] != nullptr)\n        ret += v->children[b^1]->size;\n     \
    \ if(v->children[b] == nullptr){\n        return ret;\n      }\n      v = v->children[b];\n\
    \    }\n    return ret+v->size;\n  }\n  constexpr void xor_all(T x) noexcept {\n\
    \    xor_value ^= x;\n  }\n  constexpr T size() const noexcept {\n    return root->size;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2021-03-25 17:24:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/predecessor_problem.test.cpp
  - test/LibraryChecker/set_xor_min.test.cpp
documentation_of: DataStructure/BinaryTrie.cpp
layout: document
redirect_from:
- /library/DataStructure/BinaryTrie.cpp
- /library/DataStructure/BinaryTrie.cpp.html
title: DataStructure/BinaryTrie.cpp
---
