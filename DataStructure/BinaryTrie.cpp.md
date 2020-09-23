---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"DataStructure/BinaryTrie.cpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <memory>\n\ntemplate<int len>\nclass BinaryTrie {\nprivate:\n\
    \  struct Node {\n    int size;\n    Node* parent;\n    Node* children[2];\n \
    \   Node() : size(0), parent(nullptr), children{nullptr,nullptr} {}\n  };\n  Node*\
    \ root;\n  long long xor_value;\npublic:\n  BinaryTrie() : root(new Node), xor_value(0)\
    \ {}\n  void insert(long long x, long long cnt=1){\n    x ^= xor_value;\n    Node*\
    \ v = root;\n    v->size += cnt;\n    for(int i = len-1; i >= 0; --i){\n     \
    \ int b = (x>>i)&1;\n      if(v->children[b] == nullptr){\n        v->children[b]\
    \ = new Node;\n        v->children[b]->parent = v;\n      }\n      v = v->children[b];\n\
    \      v->size += cnt;\n    }\n  }\n  void erase(long long x, long long cnt=1){\n\
    \    x ^= xor_value;\n    Node* v = root;\n    cnt = std::min(cnt,count(x));\n\
    \    if(!cnt) return;\n    for(int i = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n\
    \      assert(v->children[b] != nullptr);\n      v = v->children[b];\n      v->size\
    \ -= cnt;\n    }\n    for(int i = 0; i < len; ++i){\n      if(v->size) break;\n\
    \      auto p = v->parent;\n      int b = (x>>i)&1;\n      p->children[b] = nullptr;\n\
    \      v->parent = nullptr;\n      v = p;\n    }\n  }\n  long long count(long\
    \ long x){\n    Node* v = root;\n    for(int i = len-1; i >= 0; --i){\n      int\
    \ b = (x>>i)&1;\n      if(v->children[b] == nullptr)\n        return 0;\n    \
    \  v = v->children[b];\n    }\n    return v->size;\n  }\n  // long long lower_bound();\n\
    \  // long long upper_bound();\n  long long kth_element(int k){\n    Node* v =\
    \ root;\n    long long ret = 0;\n    for(int i = 0; i < len; ++i){\n      int\
    \ b = 0;\n      if(v->children[0] == nullptr or\n         v->children[0]->size\
    \ < k){\n        b = 1;\n        if(v->children[0] != nullptr)\n          k -=\
    \ v->children[0]->size;\n      }\n      ret *= 2;\n      ret += b;\n      v =\
    \ v->children[b];\n    }\n    return ret;\n  }\n};\n\n#include <iostream>\nusing\
    \ namespace std;\n\nint main(){\n  BinaryTrie<32> bt;\n  int Q;\n  cin >> Q;\n\
    \  while(Q--){\n    int t, x;\n    cin >> t >> x;\n    if(t == 1){\n      bt.insert(x);\n\
    \    }else{\n      auto y = bt.kth_element(x);\n      cout << y << \"\\n\";\n\
    \      bt.erase(y);\n    }\n  }\n}\n"
  code: "#include <array>\n#include <cassert>\n#include <memory>\n\ntemplate<int len>\n\
    class BinaryTrie {\nprivate:\n  struct Node {\n    int size;\n    Node* parent;\n\
    \    Node* children[2];\n    Node() : size(0), parent(nullptr), children{nullptr,nullptr}\
    \ {}\n  };\n  Node* root;\n  long long xor_value;\npublic:\n  BinaryTrie() : root(new\
    \ Node), xor_value(0) {}\n  void insert(long long x, long long cnt=1){\n    x\
    \ ^= xor_value;\n    Node* v = root;\n    v->size += cnt;\n    for(int i = len-1;\
    \ i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b] == nullptr){\n\
    \        v->children[b] = new Node;\n        v->children[b]->parent = v;\n   \
    \   }\n      v = v->children[b];\n      v->size += cnt;\n    }\n  }\n  void erase(long\
    \ long x, long long cnt=1){\n    x ^= xor_value;\n    Node* v = root;\n    cnt\
    \ = std::min(cnt,count(x));\n    if(!cnt) return;\n    for(int i = len-1; i >=\
    \ 0; --i){\n      int b = (x>>i)&1;\n      assert(v->children[b] != nullptr);\n\
    \      v = v->children[b];\n      v->size -= cnt;\n    }\n    for(int i = 0; i\
    \ < len; ++i){\n      if(v->size) break;\n      auto p = v->parent;\n      int\
    \ b = (x>>i)&1;\n      p->children[b] = nullptr;\n      v->parent = nullptr;\n\
    \      v = p;\n    }\n  }\n  long long count(long long x){\n    Node* v = root;\n\
    \    for(int i = len-1; i >= 0; --i){\n      int b = (x>>i)&1;\n      if(v->children[b]\
    \ == nullptr)\n        return 0;\n      v = v->children[b];\n    }\n    return\
    \ v->size;\n  }\n  // long long lower_bound();\n  // long long upper_bound();\n\
    \  long long kth_element(int k){\n    Node* v = root;\n    long long ret = 0;\n\
    \    for(int i = 0; i < len; ++i){\n      int b = 0;\n      if(v->children[0]\
    \ == nullptr or\n         v->children[0]->size < k){\n        b = 1;\n       \
    \ if(v->children[0] != nullptr)\n          k -= v->children[0]->size;\n      }\n\
    \      ret *= 2;\n      ret += b;\n      v = v->children[b];\n    }\n    return\
    \ ret;\n  }\n};\n\n#include <iostream>\nusing namespace std;\n\nint main(){\n\
    \  BinaryTrie<32> bt;\n  int Q;\n  cin >> Q;\n  while(Q--){\n    int t, x;\n \
    \   cin >> t >> x;\n    if(t == 1){\n      bt.insert(x);\n    }else{\n      auto\
    \ y = bt.kth_element(x);\n      cout << y << \"\\n\";\n      bt.erase(y);\n  \
    \  }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/BinaryTrie.cpp
  requiredBy: []
  timestamp: '2020-09-23 19:50:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/BinaryTrie.cpp
layout: document
redirect_from:
- /library/DataStructure/BinaryTrie.cpp
- /library/DataStructure/BinaryTrie.cpp.html
title: DataStructure/BinaryTrie.cpp
---
