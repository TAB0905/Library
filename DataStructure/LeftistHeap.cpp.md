---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Eppstein.cpp
    title: Graph/Eppstein.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/k_shortest_walk.test.cpp
    title: test/LibraryChecker/k_shortest_walk.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/LeftistHeap.cpp\"\n#include <memory>\n\ntemplate<typename\
    \ T>\nclass PersistentLeftistHeap {\n\n  struct node {\n    std::shared_ptr<node>\
    \ l, r;\n    // node* l;\n    // node* r;\n    int s;\n    T val;\n    node(T\
    \ val) : l(nullptr), r(nullptr), s(1), val(val) {}\n  };\n\npublic:\n  using node_ptr\
    \ = std::shared_ptr<node>;\n  // using node_ptr = node*;\n\nprivate:\n  node_ptr\
    \ meld(node_ptr a, node_ptr b){\n    if(!a) return (b ? node_ptr(new node(*b))\
    \ : nullptr);\n    if(!b) return (a ? node_ptr(new node(*a)) : nullptr);\n\n \
    \   a = node_ptr(new node(*a));\n    b = node_ptr(new node(*b));\n\n    if(a->val\
    \ > b->val) std::swap(a,b);\n\n    a->r = meld(a->r,b);\n\n    if(!(a->l) or (!(a->r)\
    \ and a->r->s > a->l->s)) std::swap(a->l,a->r);\n    return a;\n  }\n\n  \npublic:\n\
    \  \n  node_ptr root;\n  \n  PersistentLeftistHeap() : root(nullptr) {}\n  PersistentLeftistHeap(node_ptr\
    \ t) : root(t) {}\n  PersistentLeftistHeap(const PersistentLeftistHeap<T>&) =\
    \ default;\n  PersistentLeftistHeap(PersistentLeftistHeap<T>&&) = default;\n \
    \ PersistentLeftistHeap& operator=(PersistentLeftistHeap&&) = default;\n\n  PersistentLeftistHeap\
    \ meld(PersistentLeftistHeap a){\n    return PersistentLeftistHeap(meld(root,a.root));\n\
    \  }\n  \n  PersistentLeftistHeap insert(T x){\n    return PersistentLeftistHeap(meld(root,node_ptr(new\
    \ node(x))));\n  }\n\n  T top(){\n    return root ? root->val : T();\n  }\n  \n\
    \  \n  PersistentLeftistHeap pop(){\n    return PersistentLeftistHeap(meld(root->l,root->r));\n\
    \  }\n\n  bool empty(){\n    return !root;\n  }\n};\n\n"
  code: "#include <memory>\n\ntemplate<typename T>\nclass PersistentLeftistHeap {\n\
    \n  struct node {\n    std::shared_ptr<node> l, r;\n    // node* l;\n    // node*\
    \ r;\n    int s;\n    T val;\n    node(T val) : l(nullptr), r(nullptr), s(1),\
    \ val(val) {}\n  };\n\npublic:\n  using node_ptr = std::shared_ptr<node>;\n  //\
    \ using node_ptr = node*;\n\nprivate:\n  node_ptr meld(node_ptr a, node_ptr b){\n\
    \    if(!a) return (b ? node_ptr(new node(*b)) : nullptr);\n    if(!b) return\
    \ (a ? node_ptr(new node(*a)) : nullptr);\n\n    a = node_ptr(new node(*a));\n\
    \    b = node_ptr(new node(*b));\n\n    if(a->val > b->val) std::swap(a,b);\n\n\
    \    a->r = meld(a->r,b);\n\n    if(!(a->l) or (!(a->r) and a->r->s > a->l->s))\
    \ std::swap(a->l,a->r);\n    return a;\n  }\n\n  \npublic:\n  \n  node_ptr root;\n\
    \  \n  PersistentLeftistHeap() : root(nullptr) {}\n  PersistentLeftistHeap(node_ptr\
    \ t) : root(t) {}\n  PersistentLeftistHeap(const PersistentLeftistHeap<T>&) =\
    \ default;\n  PersistentLeftistHeap(PersistentLeftistHeap<T>&&) = default;\n \
    \ PersistentLeftistHeap& operator=(PersistentLeftistHeap&&) = default;\n\n  PersistentLeftistHeap\
    \ meld(PersistentLeftistHeap a){\n    return PersistentLeftistHeap(meld(root,a.root));\n\
    \  }\n  \n  PersistentLeftistHeap insert(T x){\n    return PersistentLeftistHeap(meld(root,node_ptr(new\
    \ node(x))));\n  }\n\n  T top(){\n    return root ? root->val : T();\n  }\n  \n\
    \  \n  PersistentLeftistHeap pop(){\n    return PersistentLeftistHeap(meld(root->l,root->r));\n\
    \  }\n\n  bool empty(){\n    return !root;\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LeftistHeap.cpp
  requiredBy:
  - Graph/Eppstein.cpp
  timestamp: '2022-04-08 21:53:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/k_shortest_walk.test.cpp
documentation_of: DataStructure/LeftistHeap.cpp
layout: document
redirect_from:
- /library/DataStructure/LeftistHeap.cpp
- /library/DataStructure/LeftistHeap.cpp.html
title: DataStructure/LeftistHeap.cpp
---
