---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/set_xor_min.test.cpp
    title: test/LibraryChecker/set_xor_min.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://atcoder.jp/contests/arc033/tasks/arc033_3
    - https://codeforces.com/group/zX1lm3q5cU/contest/665/problem/E
  bundledCode: "#line 1 \"DataStructure/BinaryTrie.cpp\"\n#include <cassert>\n\ntemplate<typename\
    \ T, int len>\nclass BinaryTrie {\nprivate:\n  struct Node {\n    T size;\n  \
    \  Node* parent;\n    Node* children[2];\n    Node() : size(0), parent(nullptr),\
    \ children{nullptr,nullptr} {}\n  };\n  \n  Node* root;\n  T xor_value;\npublic:\n\
    \  BinaryTrie() : root(new Node), xor_value(0) {}\n  constexpr void insert(T x,\
    \ T cnt=1) noexcept {\n    x ^= xor_value;\n    Node* v = root;\n    v->size +=\
    \ cnt;\n    for(int i = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b]\
    \ == nullptr){\n        v->children[b] = new Node;\n        v->children[b]->parent\
    \ = v;\n      }\n      v = v->children[b];\n      v->size += cnt;\n    }\n  }\n\
    \  constexpr void erase(T x, T cnt=1) noexcept {\n    Node* v = root;\n    cnt\
    \ = std::min(cnt,count(x));\n    x ^= xor_value;\n    if(!cnt) return;\n    v->size\
    \ -= cnt;\n    for(int i = len-1; i >= 0; --i){//root -> leaf\n      int b = (x>>i)&1;\n\
    \      assert(v->children[b] != nullptr);\n      v = v->children[b];\n      v->size\
    \ -= cnt;\n    }\n    assert(v->children[0] == nullptr);\n    assert(v->children[1]\
    \ == nullptr);\n    for(int i = 0; i < len; ++i){//leaf -> root\n      if(v->size)\
    \ break;\n      assert(v != root);\n      auto p = v->parent;\n      int b = (x>>i)&1;\n\
    \      p->children[b] = nullptr;\n      v->parent = nullptr;\n      v = p;\n \
    \   }\n  }\n  constexpr T count(T x) const noexcept {\n    Node* v = root;\n \
    \   x ^= xor_value;\n    for(int i = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n\
    \      if(v->children[b] == nullptr)\n        return 0;\n      v = v->children[b];\n\
    \    }\n    return v->size;\n  }\n  constexpr T kth_element(int k) const noexcept\
    \ {// 1-indexed\n    Node* v = root;\n    T ret = 0;\n    for(int i = len-1; i\
    \ >= 0; --i){\n      int b = (xor_value>>i)&1;\n      if(v->children[b] == nullptr\
    \ or\n         v->children[b]->size < k){\n        if(v->children[b] != nullptr)\n\
    \          k -= v->children[b]->size;\n        b ^= 1;\n      }\n      assert(v->children[b]\
    \ != nullptr);\n      ret <<= 1;\n      ret |= b;\n      v = v->children[b];\n\
    \    }\n    assert(v->size >= k);\n\n    return ret^xor_value;\n  }\n  constexpr\
    \ T count_leq(T x) const noexcept {\n    Node* v = root;\n    T ret = 0;\n   \
    \ for(int i = len-1; i >= 0; --i){\n      int b = ((xor_value^x)>>i)&1;\n    \
    \  int t = (x>>i)&1;\n      if((!t) and v->children[b^1] != nullptr)\n       \
    \ ret += v->children[b^1]->size;\n      if(v->children[b] == nullptr){\n     \
    \   return ret;\n      }\n      v = v->children[b];\n    }\n    return ret+v->size;\n\
    \  }\n  constexpr void xor_all(T x) noexcept {\n    xor_value ^= x;\n  }\n};\n\
    \n// ARC033-C\n// https://atcoder.jp/contests/arc033/tasks/arc033_3\n// #include\
    \ <iostream>\n// using namespace std;\n\n// void ARC033C(){\n//   BinaryTrie<32>\
    \ bt;\n//   int Q;\n//   cin >> Q;\n//   while(Q--){\n//     int t, x;\n//   \
    \  cin >> t >> x;\n//     if(t == 1){\n//       bt.insert(x);\n//     }else{\n\
    //       auto y = bt.kth_element(x);\n//       cout << y << \"\\n\";\n//     \
    \  bt.erase(y);\n//     }\n//   }\n// }\n\n\n// Educational Codeforces Round 12\
    \ - E\n// https://codeforces.com/group/zX1lm3q5cU/contest/665/problem/E\n// #include\
    \ <iostream>\n// #include <vector>\n// using namespace std;\n\n// void edu12E(){\n\
    //   int N, K;\n//   cin >> N >> K;\n\n//   BinaryTrie<int,30> binTrie;\n\n//\
    \   vector<int> A(N+1);\n//   for(int i = 0; i < N; ++i){\n//     cin >> A[i+1];\n\
    //     A[i+1] ^= A[i];\n//   }\n\n//   long long ans = 0;\n//   for(int i = 0;\
    \ i <= N; ++i){\n//     binTrie.xor_all(A[i]);\n//     ans += binTrie.count_leq(K);\n\
    //     binTrie.xor_all(A[i]);\n//     binTrie.insert(A[i]);\n//   }\n//   cout\
    \ << ans << endl;\n// }\n"
  code: "#include <cassert>\n\ntemplate<typename T, int len>\nclass BinaryTrie {\n\
    private:\n  struct Node {\n    T size;\n    Node* parent;\n    Node* children[2];\n\
    \    Node() : size(0), parent(nullptr), children{nullptr,nullptr} {}\n  };\n \
    \ \n  Node* root;\n  T xor_value;\npublic:\n  BinaryTrie() : root(new Node), xor_value(0)\
    \ {}\n  constexpr void insert(T x, T cnt=1) noexcept {\n    x ^= xor_value;\n\
    \    Node* v = root;\n    v->size += cnt;\n    for(int i = len-1; i >= 0; --i){\n\
    \      int b = (x>>i)&1;\n      if(v->children[b] == nullptr){\n        v->children[b]\
    \ = new Node;\n        v->children[b]->parent = v;\n      }\n      v = v->children[b];\n\
    \      v->size += cnt;\n    }\n  }\n  constexpr void erase(T x, T cnt=1) noexcept\
    \ {\n    Node* v = root;\n    cnt = std::min(cnt,count(x));\n    x ^= xor_value;\n\
    \    if(!cnt) return;\n    v->size -= cnt;\n    for(int i = len-1; i >= 0; --i){//root\
    \ -> leaf\n      int b = (x>>i)&1;\n      assert(v->children[b] != nullptr);\n\
    \      v = v->children[b];\n      v->size -= cnt;\n    }\n    assert(v->children[0]\
    \ == nullptr);\n    assert(v->children[1] == nullptr);\n    for(int i = 0; i <\
    \ len; ++i){//leaf -> root\n      if(v->size) break;\n      assert(v != root);\n\
    \      auto p = v->parent;\n      int b = (x>>i)&1;\n      p->children[b] = nullptr;\n\
    \      v->parent = nullptr;\n      v = p;\n    }\n  }\n  constexpr T count(T x)\
    \ const noexcept {\n    Node* v = root;\n    x ^= xor_value;\n    for(int i =\
    \ len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b] == nullptr)\n\
    \        return 0;\n      v = v->children[b];\n    }\n    return v->size;\n  }\n\
    \  constexpr T kth_element(int k) const noexcept {// 1-indexed\n    Node* v =\
    \ root;\n    T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n      int b = (xor_value>>i)&1;\n\
    \      if(v->children[b] == nullptr or\n         v->children[b]->size < k){\n\
    \        if(v->children[b] != nullptr)\n          k -= v->children[b]->size;\n\
    \        b ^= 1;\n      }\n      assert(v->children[b] != nullptr);\n      ret\
    \ <<= 1;\n      ret |= b;\n      v = v->children[b];\n    }\n    assert(v->size\
    \ >= k);\n\n    return ret^xor_value;\n  }\n  constexpr T count_leq(T x) const\
    \ noexcept {\n    Node* v = root;\n    T ret = 0;\n    for(int i = len-1; i >=\
    \ 0; --i){\n      int b = ((xor_value^x)>>i)&1;\n      int t = (x>>i)&1;\n   \
    \   if((!t) and v->children[b^1] != nullptr)\n        ret += v->children[b^1]->size;\n\
    \      if(v->children[b] == nullptr){\n        return ret;\n      }\n      v =\
    \ v->children[b];\n    }\n    return ret+v->size;\n  }\n  constexpr void xor_all(T\
    \ x) noexcept {\n    xor_value ^= x;\n  }\n};\n\n// ARC033-C\n// https://atcoder.jp/contests/arc033/tasks/arc033_3\n\
    // #include <iostream>\n// using namespace std;\n\n// void ARC033C(){\n//   BinaryTrie<32>\
    \ bt;\n//   int Q;\n//   cin >> Q;\n//   while(Q--){\n//     int t, x;\n//   \
    \  cin >> t >> x;\n//     if(t == 1){\n//       bt.insert(x);\n//     }else{\n\
    //       auto y = bt.kth_element(x);\n//       cout << y << \"\\n\";\n//     \
    \  bt.erase(y);\n//     }\n//   }\n// }\n\n\n// Educational Codeforces Round 12\
    \ - E\n// https://codeforces.com/group/zX1lm3q5cU/contest/665/problem/E\n// #include\
    \ <iostream>\n// #include <vector>\n// using namespace std;\n\n// void edu12E(){\n\
    //   int N, K;\n//   cin >> N >> K;\n\n//   BinaryTrie<int,30> binTrie;\n\n//\
    \   vector<int> A(N+1);\n//   for(int i = 0; i < N; ++i){\n//     cin >> A[i+1];\n\
    //     A[i+1] ^= A[i];\n//   }\n\n//   long long ans = 0;\n//   for(int i = 0;\
    \ i <= N; ++i){\n//     binTrie.xor_all(A[i]);\n//     ans += binTrie.count_leq(K);\n\
    //     binTrie.xor_all(A[i]);\n//     binTrie.insert(A[i]);\n//   }\n//   cout\
    \ << ans << endl;\n// }\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2020-09-24 02:37:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/set_xor_min.test.cpp
documentation_of: DataStructure/BinaryTrie.cpp
layout: document
redirect_from:
- /library/DataStructure/BinaryTrie.cpp
- /library/DataStructure/BinaryTrie.cpp.html
title: DataStructure/BinaryTrie.cpp
---