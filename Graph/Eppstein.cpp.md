---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LeftistHeap.cpp
    title: DataStructure/LeftistHeap.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/k_shortest_walk.test.cpp
    title: test/LibraryChecker/k_shortest_walk.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/Eppstein.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n#include <tuple>\n#include <utility>\n\
    #include <queue>\n\n#line 1 \"DataStructure/LeftistHeap.cpp\"\n#include <memory>\n\
    \ntemplate<typename T>\nclass PersistentLeftistHeap {\n\n  struct node {\n   \
    \ std::shared_ptr<node> l, r;\n    // node* l;\n    // node* r;\n    int s;\n\
    \    T val;\n    node(T val) : l(nullptr), r(nullptr), s(1), val(val) {}\n  };\n\
    \npublic:\n  using node_ptr = std::shared_ptr<node>;\n  // using node_ptr = node*;\n\
    \nprivate:\n  node_ptr meld(node_ptr a, node_ptr b){\n    if(!a) return (b ? node_ptr(new\
    \ node(*b)) : nullptr);\n    if(!b) return (a ? node_ptr(new node(*a)) : nullptr);\n\
    \n    a = node_ptr(new node(*a));\n    b = node_ptr(new node(*b));\n\n    if(a->val\
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
    \  }\n\n  bool empty(){\n    return !root;\n  }\n};\n\n#line 10 \"Graph/Eppstein.cpp\"\
    \n\ntemplate<typename T>\nbool chmin(T& x, const T y){\n  if(x <= y) return false;\n\
    \  x = y;\n  return true;\n}\n\ntemplate<typename T>\nstd::vector<T> Eppstein(const\
    \ std::vector<std::tuple<T,int,int>>& E, int n, int s, int t, int k, T INF){\n\
    \  using heap = PersistentLeftistHeap<std::tuple<T,int>>;\n\n  const int m = E.size();\n\
    \  std::vector R(n,std::vector<std::tuple<T,int,int>>()); // {cost,to,edge_id}\n\
    \  auto G = R;\n  for(int i = 0; i < m; ++i){\n    auto [c,from,to] = E[i];\n\
    \    R[to].emplace_back(c,from,i);\n    G[from].emplace_back(c,to,i);\n  }\n \
    \ \n  // calculating potential & shortest path tree by Dijkstra algorithm\n\n\
    \  std::vector<T> potential(n,INF);\n  potential[t] = 0;\n\n  std::vector<int>\
    \ parent(n,-1), tree_edge(n,-1);\n  std::vector<std::vector<int>> child(n);\n\
    \  \n  {\n    std::priority_queue<std::tuple<T,int>,std::vector<std::tuple<T,int>>,std::greater<>>\
    \ Q;\n    Q.emplace(T(),t);\n\n    while(Q.size()){\n      auto [d,v] = Q.top();\n\
    \      Q.pop();\n      if(potential[v] < d) continue;\n      for(auto [c,u,id]\
    \ : R[v]){\n        if(chmin(potential[u],d+c)){\n          Q.emplace(d+c,u);\n\
    \          tree_edge[u] = id;\n          potential[u] = d+c;\n          parent[u]\
    \ = v;\n        }\n      }\n    }\n  }\n  \n  for(int i = 0; i < n; ++i){\n  \
    \  if(parent[i] == -1) continue;\n    child[parent[i]].emplace_back(i);\n  }\n\
    \n  std::vector<heap> H(n); // cost, to\n  // bfs for constructing H_g\n  {\n\
    \    std::queue<int> Q;\n    Q.emplace(t);\n    while(Q.size()){\n      auto v\
    \ = Q.front();\n      Q.pop();\n      if(parent[v] != -1) H[v] = H[v].meld(H[parent[v]]);\n\
    \      for(auto [c,u,id] : G[v]){\n        if(tree_edge[v] == id) continue;\n\
    \        H[v] = H[v].insert(std::tuple(c+potential[u]-potential[v],u));\n    \
    \  }\n      for(auto u : child[v]){\n        Q.emplace(u);\n      }\n    }\n \
    \ }\n\n  std::vector<T> ans;\n  {\n    using node_ptr = typename heap::node_ptr;\n\
    \    std::priority_queue<std::tuple<T,node_ptr>,std::vector<std::tuple<T,node_ptr>>,std::greater<>>\
    \ Q;\n\n    heap init;\n    init = init.insert(std::tuple(potential[s],s));\n\n\
    \    Q.emplace(potential[s],init.root);\n\n    while(Q.size()){\n      auto [d,h]\
    \ = Q.top();\n      Q.pop();\n      if(d >= INF) break;\n      ans.emplace_back(d);\n\
    \      if(ans.size() == k) break;\n      if(h->l != nullptr){\n        Q.emplace(d\
    \ + std::get<0>(h->l->val) - std::get<0>(h->val), h->l);\n      }\n      if(h->r\
    \ != nullptr){\n        Q.emplace(d + std::get<0>(h->r->val) - std::get<0>(h->val),\
    \ h->r);\n      }\n      if(H[std::get<1>(h->val)].root != nullptr){\n       \
    \ auto h_ = H[std::get<1>(h->val)].root;\n        Q.emplace(d + std::get<0>(h_->val),\
    \ h_);\n      }\n    }\n  }\n  return ans;\n}\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <vector>\n\
    #include <tuple>\n#include <utility>\n#include <queue>\n\n#include \"DataStructure/LeftistHeap.cpp\"\
    \n\ntemplate<typename T>\nbool chmin(T& x, const T y){\n  if(x <= y) return false;\n\
    \  x = y;\n  return true;\n}\n\ntemplate<typename T>\nstd::vector<T> Eppstein(const\
    \ std::vector<std::tuple<T,int,int>>& E, int n, int s, int t, int k, T INF){\n\
    \  using heap = PersistentLeftistHeap<std::tuple<T,int>>;\n\n  const int m = E.size();\n\
    \  std::vector R(n,std::vector<std::tuple<T,int,int>>()); // {cost,to,edge_id}\n\
    \  auto G = R;\n  for(int i = 0; i < m; ++i){\n    auto [c,from,to] = E[i];\n\
    \    R[to].emplace_back(c,from,i);\n    G[from].emplace_back(c,to,i);\n  }\n \
    \ \n  // calculating potential & shortest path tree by Dijkstra algorithm\n\n\
    \  std::vector<T> potential(n,INF);\n  potential[t] = 0;\n\n  std::vector<int>\
    \ parent(n,-1), tree_edge(n,-1);\n  std::vector<std::vector<int>> child(n);\n\
    \  \n  {\n    std::priority_queue<std::tuple<T,int>,std::vector<std::tuple<T,int>>,std::greater<>>\
    \ Q;\n    Q.emplace(T(),t);\n\n    while(Q.size()){\n      auto [d,v] = Q.top();\n\
    \      Q.pop();\n      if(potential[v] < d) continue;\n      for(auto [c,u,id]\
    \ : R[v]){\n        if(chmin(potential[u],d+c)){\n          Q.emplace(d+c,u);\n\
    \          tree_edge[u] = id;\n          potential[u] = d+c;\n          parent[u]\
    \ = v;\n        }\n      }\n    }\n  }\n  \n  for(int i = 0; i < n; ++i){\n  \
    \  if(parent[i] == -1) continue;\n    child[parent[i]].emplace_back(i);\n  }\n\
    \n  std::vector<heap> H(n); // cost, to\n  // bfs for constructing H_g\n  {\n\
    \    std::queue<int> Q;\n    Q.emplace(t);\n    while(Q.size()){\n      auto v\
    \ = Q.front();\n      Q.pop();\n      if(parent[v] != -1) H[v] = H[v].meld(H[parent[v]]);\n\
    \      for(auto [c,u,id] : G[v]){\n        if(tree_edge[v] == id) continue;\n\
    \        H[v] = H[v].insert(std::tuple(c+potential[u]-potential[v],u));\n    \
    \  }\n      for(auto u : child[v]){\n        Q.emplace(u);\n      }\n    }\n \
    \ }\n\n  std::vector<T> ans;\n  {\n    using node_ptr = typename heap::node_ptr;\n\
    \    std::priority_queue<std::tuple<T,node_ptr>,std::vector<std::tuple<T,node_ptr>>,std::greater<>>\
    \ Q;\n\n    heap init;\n    init = init.insert(std::tuple(potential[s],s));\n\n\
    \    Q.emplace(potential[s],init.root);\n\n    while(Q.size()){\n      auto [d,h]\
    \ = Q.top();\n      Q.pop();\n      if(d >= INF) break;\n      ans.emplace_back(d);\n\
    \      if(ans.size() == k) break;\n      if(h->l != nullptr){\n        Q.emplace(d\
    \ + std::get<0>(h->l->val) - std::get<0>(h->val), h->l);\n      }\n      if(h->r\
    \ != nullptr){\n        Q.emplace(d + std::get<0>(h->r->val) - std::get<0>(h->val),\
    \ h->r);\n      }\n      if(H[std::get<1>(h->val)].root != nullptr){\n       \
    \ auto h_ = H[std::get<1>(h->val)].root;\n        Q.emplace(d + std::get<0>(h_->val),\
    \ h_);\n      }\n    }\n  }\n  return ans;\n}\n"
  dependsOn:
  - DataStructure/LeftistHeap.cpp
  isVerificationFile: false
  path: Graph/Eppstein.cpp
  requiredBy: []
  timestamp: '2022-04-08 21:53:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/k_shortest_walk.test.cpp
documentation_of: Graph/Eppstein.cpp
layout: document
redirect_from:
- /library/Graph/Eppstein.cpp
- /library/Graph/Eppstein.cpp.html
title: Graph/Eppstein.cpp
---
