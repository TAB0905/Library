---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BinaryTrie.cpp
    title: DataStructure/BinaryTrie.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/LibraryChecker/predecessor_problem.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n#include\
    \ <iostream>\n#line 1 \"DataStructure/BinaryTrie.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n\ntemplate<typename T, int len>\nclass BinaryTrie {\nprivate:\n\
    \  struct Node {\n    T size;\n    Node* parent;\n    Node* children[2];\n   \
    \ Node() : size(0), parent(nullptr), children{nullptr,nullptr} {}\n  };\n  \n\
    \  Node* const root;\n  T xor_value;\npublic:\n  BinaryTrie() : root(new Node),\
    \ xor_value(0) {}\n  constexpr void insert(T x, T cnt=1) noexcept {\n    x ^=\
    \ xor_value;\n    Node* v = root;\n    v->size += cnt;\n    for(int i = len-1;\
    \ i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b] == nullptr){\n\
    \        v->children[b] = new Node;\n        v->children[b]->parent = v;\n   \
    \   }\n      v = v->children[b];\n      v->size += cnt;\n    }\n  }\n  constexpr\
    \ void erase(T x, T cnt=1) noexcept {\n    Node* v = root;\n    cnt = std::min(cnt,count(x));\n\
    \    x ^= xor_value;\n    if(!cnt) return;\n    v->size -= cnt;\n    for(int i\
    \ = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n      v = v->children[b];\n\
    \      v->size -= cnt;\n    }\n    for(int i = 0; i < len; ++i){\n      if(v->size)\
    \ break;\n      auto p = v->parent;\n      int b = (x>>i)&1;\n      p->children[b]\
    \ = nullptr;\n      v->parent = nullptr;\n      v = p;\n    }\n  }\n  constexpr\
    \ T count(T x) const noexcept {\n    Node* v = root;\n    x ^= xor_value;\n  \
    \  for(int i = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b]\
    \ == nullptr)\n        return 0;\n      v = v->children[b];\n    }\n    return\
    \ v->size;\n  }\n  constexpr T kth_element(int k) const noexcept {// 1-indexed\n\
    \    Node* v = root;\n    T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n \
    \     int b = (xor_value>>i)&1;\n      if(v->children[b] == nullptr or\n     \
    \    v->children[b]->size < k){\n        if(v->children[b] != nullptr)\n     \
    \     k -= v->children[b]->size;\n        b ^= 1;\n      }\n      ret <<= 1;\n\
    \      ret |= b;\n      v = v->children[b];\n    }\n\n    return ret^xor_value;\n\
    \  }\n  constexpr T count_leq(T x) const noexcept {\n    Node* v = root;\n   \
    \ T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n      int b = ((xor_value^x)>>i)&1;\n\
    \      int t = (x>>i)&1;\n      if(t and v->children[b^1] != nullptr)\n      \
    \  ret += v->children[b^1]->size;\n      if(v->children[b] == nullptr){\n    \
    \    return ret;\n      }\n      v = v->children[b];\n    }\n    return ret+v->size;\n\
    \  }\n  constexpr T count_geq(T x) const noexcept {\n    Node* v = root;\n   \
    \ T ret = 0;\n    for(int i = len-1; i >= 0; --i){\n      int b = ((xor_value^x)>>i)&1;\n\
    \      int t = (x>>i)&1;\n      if((!t) and v->children[b^1] != nullptr)\n   \
    \     ret += v->children[b^1]->size;\n      if(v->children[b] == nullptr){\n \
    \       return ret;\n      }\n      v = v->children[b];\n    }\n    return ret+v->size;\n\
    \  }\n  constexpr void xor_all(T x) noexcept {\n    xor_value ^= x;\n  }\n  constexpr\
    \ T size() const noexcept {\n    return root->size;\n  }\n};\n#line 5 \"test/LibraryChecker/predecessor_problem.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  BinaryTrie<int,25> binTrie;//2^24 = 16777216 > 1e7 = N_MAX\n  int n, q;\n \
    \ cin >> n >> q;\n  string s;\n  cin >> s;\n  for(int i = 0; i < n; ++i){\n  \
    \  if(s[i] == '1')\n      binTrie.insert(i);\n  }\n  while(q--){\n    int c, k;\n\
    \    cin >> c >> k;\n    if(c == 0){\n      if(binTrie.count(k))\n        continue;\n\
    \      binTrie.insert(k);\n    }\n    if(c == 1){\n      binTrie.erase(k);\n \
    \   }\n    if(c == 2){\n      cout << (!!binTrie.count(k)) << '\\n';\n    }\n\
    \    if(c == 3){\n      if(binTrie.size() == 0){\n        cout << -1 << '\\n';\n\
    \        continue;\n      }\n      int leq_num = binTrie.count_leq(k);\n     \
    \ int max_element = binTrie.kth_element(binTrie.size());\n      if(!k){\n    \
    \    cout << binTrie.kth_element(1) << '\\n';\n      }else if(k > max_element){\n\
    \        cout << -1 << '\\n';\n      }else{\n        leq_num = binTrie.count_leq(k-1);\n\
    \        cout << binTrie.kth_element(leq_num+1) << '\\n';\n      }\n    }\n  \
    \  if(c == 4){\n      if(binTrie.size() == 0){\n        cout << -1 << '\\n';\n\
    \        continue;\n      }\n      if(binTrie.kth_element(1) > k){\n        cout\
    \ << -1 << '\\n';\n      }else{\n        int leq_num = binTrie.count_leq(k);\n\
    \        cout << binTrie.kth_element(leq_num) << '\\n';\n      }\n    }\n  }\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include <iostream>\n#include \"DataStructure/BinaryTrie.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n \
    \ BinaryTrie<int,25> binTrie;//2^24 = 16777216 > 1e7 = N_MAX\n  int n, q;\n  cin\
    \ >> n >> q;\n  string s;\n  cin >> s;\n  for(int i = 0; i < n; ++i){\n    if(s[i]\
    \ == '1')\n      binTrie.insert(i);\n  }\n  while(q--){\n    int c, k;\n    cin\
    \ >> c >> k;\n    if(c == 0){\n      if(binTrie.count(k))\n        continue;\n\
    \      binTrie.insert(k);\n    }\n    if(c == 1){\n      binTrie.erase(k);\n \
    \   }\n    if(c == 2){\n      cout << (!!binTrie.count(k)) << '\\n';\n    }\n\
    \    if(c == 3){\n      if(binTrie.size() == 0){\n        cout << -1 << '\\n';\n\
    \        continue;\n      }\n      int leq_num = binTrie.count_leq(k);\n     \
    \ int max_element = binTrie.kth_element(binTrie.size());\n      if(!k){\n    \
    \    cout << binTrie.kth_element(1) << '\\n';\n      }else if(k > max_element){\n\
    \        cout << -1 << '\\n';\n      }else{\n        leq_num = binTrie.count_leq(k-1);\n\
    \        cout << binTrie.kth_element(leq_num+1) << '\\n';\n      }\n    }\n  \
    \  if(c == 4){\n      if(binTrie.size() == 0){\n        cout << -1 << '\\n';\n\
    \        continue;\n      }\n      if(binTrie.kth_element(1) > k){\n        cout\
    \ << -1 << '\\n';\n      }else{\n        int leq_num = binTrie.count_leq(k);\n\
    \        cout << binTrie.kth_element(leq_num) << '\\n';\n      }\n    }\n  }\n\
    }\n\n"
  dependsOn:
  - DataStructure/BinaryTrie.cpp
  isVerificationFile: true
  path: test/LibraryChecker/predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2021-03-25 17:24:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/predecessor_problem.test.cpp
- /verify/test/LibraryChecker/predecessor_problem.test.cpp.html
title: test/LibraryChecker/predecessor_problem.test.cpp
---
