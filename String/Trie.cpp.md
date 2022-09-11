---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/Trie.cpp\"\n#include <algorithm>\n#include <array>\n\
    #include <vector>\n\ntemplate<typename T, int alphabetSize, T min_element>\nclass\
    \ Trie {\n\n  struct node {\n    std::array<int,alphabetSize> nxt;\n    const\
    \ int parent;\n    node(int p) : nxt(), parent(p) {\n      std::fill(nxt.begin(),nxt.end(),-1);\n\
    \    }\n    int operator[](int i) const {\n      return nxt[i];\n    }\n  };\n\
    \n  const int root_idx;\n  std::vector<node> nodes;\n  \npublic:\n\n  Trie() :\
    \ root_idx(0), nodes(1,node(-1)) {}\n\n  int add(const std::string& s){\n    int\
    \ v_id = root_idx;\n    for(const char& c : s){\n      if(nodes[v_id][c-min_element]\
    \ == -1){\n        nodes[v_id].nxt[c-min_element] = nodes.size();\n        nodes.emplace_back(v_id);\n\
    \      }\n      v_id = nodes[v_id][c-min_element];\n    }\n    return v_id;\n\
    \  }\n\n  node& operator[](size_t i){\n    return nodes[i];\n  }\n\n  int size(){\n\
    \    return nodes.size();\n  }\n};\n\n"
  code: "#include <algorithm>\n#include <array>\n#include <vector>\n\ntemplate<typename\
    \ T, int alphabetSize, T min_element>\nclass Trie {\n\n  struct node {\n    std::array<int,alphabetSize>\
    \ nxt;\n    const int parent;\n    node(int p) : nxt(), parent(p) {\n      std::fill(nxt.begin(),nxt.end(),-1);\n\
    \    }\n    int operator[](int i) const {\n      return nxt[i];\n    }\n  };\n\
    \n  const int root_idx;\n  std::vector<node> nodes;\n  \npublic:\n\n  Trie() :\
    \ root_idx(0), nodes(1,node(-1)) {}\n\n  int add(const std::string& s){\n    int\
    \ v_id = root_idx;\n    for(const char& c : s){\n      if(nodes[v_id][c-min_element]\
    \ == -1){\n        nodes[v_id].nxt[c-min_element] = nodes.size();\n        nodes.emplace_back(v_id);\n\
    \      }\n      v_id = nodes[v_id][c-min_element];\n    }\n    return v_id;\n\
    \  }\n\n  node& operator[](size_t i){\n    return nodes[i];\n  }\n\n  int size(){\n\
    \    return nodes.size();\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: String/Trie.cpp
  requiredBy: []
  timestamp: '2022-09-11 20:12:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Trie.cpp
layout: document
redirect_from:
- /library/String/Trie.cpp
- /library/String/Trie.cpp.html
title: String/Trie.cpp
---
