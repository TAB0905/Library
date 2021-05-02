---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2292.test.cpp
    title: test/AOJ/2292.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/PalindromicTree.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n#include <array>\n#include <iostream>\n\ntemplate<typename T, int\
    \ alphabetSize, T min_element>\nclass PalindromicTree {\n\n  struct Node {\n \
    \   const int suffix_link;\n    std::array<int,alphabetSize> ch;\n    const int\
    \ len;\n    int cnt;\n\n    Node(int suffix_link, int len) :\n      suffix_link(suffix_link),\
    \ ch(), len(len), cnt(1) {\n      std::fill(ch.begin(), ch.end(), -1);\n    };\n\
    \n    // void dump(){\n    //   std::cerr << \"cnt               : \" << cnt <<\
    \ \"\\n\";\n    //   std::cerr << \"suffix_link       : \" << suffix_link << \"\
    \\n\";\n    //   for(int j = 0; j < alphabetSize; ++j){\n    //     if(ch[j] >=\
    \ 0){\n    //       std::cout << std::string(1,'a'+j) << \" \" << ch[j] << std::endl;\n\
    \    //     }\n    //   }\n    //   std::cerr << \"\\n\";\n    // }\n  };\n\n\
    public:\n\n  std::vector<Node> nodes;\n  std::vector<T> dat;\n  int len;\n  std::vector<int>\
    \ A;\n\n  PalindromicTree() : nodes({Node(-1,-1), Node(0,0)}), dat(), len(0),\
    \ A() {}\n\n  bool push_back(T c){\n    dat.emplace_back(c);\n    ++len;\n   \
    \ int parent_idx = A.empty() ? 0 : A.back();\n    // std::cerr << parent_idx <<\
    \ \" \" << len-2-nodes[parent_idx].len << std::endl;\n    while(len-2-nodes[parent_idx].len\
    \ < 0 or dat[len-2-nodes[parent_idx].len] != c){\n      parent_idx = nodes[parent_idx].suffix_link;\n\
    \    }\n\n    int v_idx = nodes[parent_idx].ch[c-min_element];\n\n    if(v_idx\
    \ != -1){\n      ++nodes[v_idx].cnt;\n      A.emplace_back(v_idx);\n      return\
    \ false;\n    }\n\n    int suffix_link = nodes[parent_idx].suffix_link;\n    while(suffix_link\
    \ >= 0 and (len-2-nodes[suffix_link].len < 0 or dat[len-2-nodes[suffix_link].len]\
    \ != c)){\n      suffix_link = nodes[suffix_link].suffix_link;\n    }\n\n\n  \
    \  if(suffix_link >= 0 and len-2-nodes[suffix_link].len >= 0 and dat[len-2-nodes[suffix_link].len]\
    \ == c){\n      assert(nodes[suffix_link].ch[c-min_element] >= 0);\n      suffix_link\
    \ = nodes[suffix_link].ch[c-min_element];\n    }\n\n    if(suffix_link < 0) suffix_link\
    \ = 1;\n    \n    v_idx = nodes.size();\n    nodes[parent_idx].ch[c-min_element]\
    \ = v_idx;\n    nodes.emplace_back(suffix_link,nodes[parent_idx].len+2);\n   \
    \ A.emplace_back(v_idx);\n    \n    return true;\n  }\n\n  size_t num_unique_palindrome()\
    \ const noexcept {\n    return nodes.size()-2;\n  }\n};\n\n"
  code: "#include <cassert>\n#include <vector>\n#include <array>\n#include <iostream>\n\
    \ntemplate<typename T, int alphabetSize, T min_element>\nclass PalindromicTree\
    \ {\n\n  struct Node {\n    const int suffix_link;\n    std::array<int,alphabetSize>\
    \ ch;\n    const int len;\n    int cnt;\n\n    Node(int suffix_link, int len)\
    \ :\n      suffix_link(suffix_link), ch(), len(len), cnt(1) {\n      std::fill(ch.begin(),\
    \ ch.end(), -1);\n    };\n\n    // void dump(){\n    //   std::cerr << \"cnt \
    \              : \" << cnt << \"\\n\";\n    //   std::cerr << \"suffix_link  \
    \     : \" << suffix_link << \"\\n\";\n    //   for(int j = 0; j < alphabetSize;\
    \ ++j){\n    //     if(ch[j] >= 0){\n    //       std::cout << std::string(1,'a'+j)\
    \ << \" \" << ch[j] << std::endl;\n    //     }\n    //   }\n    //   std::cerr\
    \ << \"\\n\";\n    // }\n  };\n\npublic:\n\n  std::vector<Node> nodes;\n  std::vector<T>\
    \ dat;\n  int len;\n  std::vector<int> A;\n\n  PalindromicTree() : nodes({Node(-1,-1),\
    \ Node(0,0)}), dat(), len(0), A() {}\n\n  bool push_back(T c){\n    dat.emplace_back(c);\n\
    \    ++len;\n    int parent_idx = A.empty() ? 0 : A.back();\n    // std::cerr\
    \ << parent_idx << \" \" << len-2-nodes[parent_idx].len << std::endl;\n    while(len-2-nodes[parent_idx].len\
    \ < 0 or dat[len-2-nodes[parent_idx].len] != c){\n      parent_idx = nodes[parent_idx].suffix_link;\n\
    \    }\n\n    int v_idx = nodes[parent_idx].ch[c-min_element];\n\n    if(v_idx\
    \ != -1){\n      ++nodes[v_idx].cnt;\n      A.emplace_back(v_idx);\n      return\
    \ false;\n    }\n\n    int suffix_link = nodes[parent_idx].suffix_link;\n    while(suffix_link\
    \ >= 0 and (len-2-nodes[suffix_link].len < 0 or dat[len-2-nodes[suffix_link].len]\
    \ != c)){\n      suffix_link = nodes[suffix_link].suffix_link;\n    }\n\n\n  \
    \  if(suffix_link >= 0 and len-2-nodes[suffix_link].len >= 0 and dat[len-2-nodes[suffix_link].len]\
    \ == c){\n      assert(nodes[suffix_link].ch[c-min_element] >= 0);\n      suffix_link\
    \ = nodes[suffix_link].ch[c-min_element];\n    }\n\n    if(suffix_link < 0) suffix_link\
    \ = 1;\n    \n    v_idx = nodes.size();\n    nodes[parent_idx].ch[c-min_element]\
    \ = v_idx;\n    nodes.emplace_back(suffix_link,nodes[parent_idx].len+2);\n   \
    \ A.emplace_back(v_idx);\n    \n    return true;\n  }\n\n  size_t num_unique_palindrome()\
    \ const noexcept {\n    return nodes.size()-2;\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: String/PalindromicTree.cpp
  requiredBy: []
  timestamp: '2021-05-02 23:06:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2292.test.cpp
documentation_of: String/PalindromicTree.cpp
layout: document
redirect_from:
- /library/String/PalindromicTree.cpp
- /library/String/PalindromicTree.cpp.html
title: String/PalindromicTree.cpp
---
