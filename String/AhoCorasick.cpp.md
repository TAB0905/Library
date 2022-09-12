---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: String/Trie.cpp
    title: String/Trie.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/AhoCorasick.cpp\"\n#include <array>\n#include <cassert>\n\
    #include <vector>\n#include <queue>\n#include <numeric>\n\n#line 1 \"String/Trie.cpp\"\
    \n#include <algorithm>\n#line 4 \"String/Trie.cpp\"\n\ntemplate<typename T, int\
    \ alphabetSize, T min_element>\nclass Trie {\n\n  struct node {\n    std::array<int,alphabetSize>\
    \ nxt;\n    const int parent;\n    node(int p) : nxt(), parent(p) {\n      std::fill(nxt.begin(),nxt.end(),-1);\n\
    \    }\n    int operator[](int i) const {\n      return nxt[i];\n    }\n  };\n\
    \n  const int root_idx;\n  std::vector<node> nodes;\n  \npublic:\n\n  Trie() :\
    \ root_idx(0), nodes(1,node(-1)) {}\n\n  int add(const std::string& s){\n    int\
    \ v_id = root_idx;\n    for(const char& c : s){\n      if(nodes[v_id][c-min_element]\
    \ == -1){\n        nodes[v_id].nxt[c-min_element] = nodes.size();\n        nodes.emplace_back(v_id);\n\
    \      }\n      v_id = nodes[v_id][c-min_element];\n    }\n    return v_id;\n\
    \  }\n\n  node& operator[](size_t i){\n    return nodes[i];\n  }\n\n  int size(){\n\
    \    return nodes.size();\n  }\n};\n\n#line 8 \"String/AhoCorasick.cpp\"\n\ntemplate<typename\
    \ T, int alphabetSize, T min_element>\nclass AhoCorasick {\n\n  Trie<T,alphabetSize,min_element>\
    \ trie;\n  std::vector<int> suffix_cnt, failure;\n  const int root_idx;\n  const\
    \ int num_pattern;\n\n  void construct_failure(){\n    std::queue<int> que;\n\
    \    failure[root_idx] = root_idx;\n    for(int i = 0; i < alphabetSize; ++i){\n\
    \      if(trie[root_idx][i] == -1) continue;\n      que.emplace(trie[root_idx][i]);\n\
    \      failure[trie[root_idx][i]] = root_idx;\n    }\n\n    while(que.size()){\n\
    \      int v = que.front();\n      que.pop();\n      suffix_cnt[v] += suffix_cnt[failure[v]];\n\
    \      for(int i = 0; i < alphabetSize; ++i){\n        if(trie[v][i] == -1) continue;\n\
    \        que.push(trie[v][i]);\n        int f = failure[v];\n        while(f !=\
    \ -1 and trie[f][i] == -1){\n          f = failure[f];\n          if(f == root_idx)\
    \ break;\n        }\n        failure[trie[v][i]] = (f == -1 or trie[f][i] == -1)\
    \ ? root_idx : trie[f][i];\n      }\n    }\n  }\n\npublic:\n\n  AhoCorasick(const\
    \ std::vector<std::string>& pattern)\n    : trie(), suffix_cnt(), failure(), root_idx(0),\
    \ num_pattern(pattern.size()) {\n    vector<int> idx;\n    for(const auto& p :\
    \ pattern){\n      idx.emplace_back(trie.add(p));\n    }\n    failure.resize(trie.size(),-1);\n\
    \    suffix_cnt.resize(trie.size());\n    for(auto e : idx)\n      ++suffix_cnt[e];\n\
    \    construct_failure();\n  }\n\n  int root(){ return root_idx; }\n\n  std::pair<int,int>\
    \ move(int cur, T c){\n    int i = c - min_element;\n    int nxt = cur;\n    while(trie[nxt][i]\
    \ == -1){\n      if(nxt == root_idx) break;\n      nxt = failure[nxt];\n    }\n\
    \    if(trie[nxt][i] >= 0) nxt = trie[nxt][i];\n    else nxt = failure[nxt];\n\
    \    return std::pair(suffix_cnt[nxt],nxt);\n  }\n};\n\n"
  code: "#include <array>\n#include <cassert>\n#include <vector>\n#include <queue>\n\
    #include <numeric>\n\n#include \"Trie.cpp\"\n\ntemplate<typename T, int alphabetSize,\
    \ T min_element>\nclass AhoCorasick {\n\n  Trie<T,alphabetSize,min_element> trie;\n\
    \  std::vector<int> suffix_cnt, failure;\n  const int root_idx;\n  const int num_pattern;\n\
    \n  void construct_failure(){\n    std::queue<int> que;\n    failure[root_idx]\
    \ = root_idx;\n    for(int i = 0; i < alphabetSize; ++i){\n      if(trie[root_idx][i]\
    \ == -1) continue;\n      que.emplace(trie[root_idx][i]);\n      failure[trie[root_idx][i]]\
    \ = root_idx;\n    }\n\n    while(que.size()){\n      int v = que.front();\n \
    \     que.pop();\n      suffix_cnt[v] += suffix_cnt[failure[v]];\n      for(int\
    \ i = 0; i < alphabetSize; ++i){\n        if(trie[v][i] == -1) continue;\n   \
    \     que.push(trie[v][i]);\n        int f = failure[v];\n        while(f != -1\
    \ and trie[f][i] == -1){\n          f = failure[f];\n          if(f == root_idx)\
    \ break;\n        }\n        failure[trie[v][i]] = (f == -1 or trie[f][i] == -1)\
    \ ? root_idx : trie[f][i];\n      }\n    }\n  }\n\npublic:\n\n  AhoCorasick(const\
    \ std::vector<std::string>& pattern)\n    : trie(), suffix_cnt(), failure(), root_idx(0),\
    \ num_pattern(pattern.size()) {\n    vector<int> idx;\n    for(const auto& p :\
    \ pattern){\n      idx.emplace_back(trie.add(p));\n    }\n    failure.resize(trie.size(),-1);\n\
    \    suffix_cnt.resize(trie.size());\n    for(auto e : idx)\n      ++suffix_cnt[e];\n\
    \    construct_failure();\n  }\n\n  int root(){ return root_idx; }\n\n  std::pair<int,int>\
    \ move(int cur, T c){\n    int i = c - min_element;\n    int nxt = cur;\n    while(trie[nxt][i]\
    \ == -1){\n      if(nxt == root_idx) break;\n      nxt = failure[nxt];\n    }\n\
    \    if(trie[nxt][i] >= 0) nxt = trie[nxt][i];\n    else nxt = failure[nxt];\n\
    \    return std::pair(suffix_cnt[nxt],nxt);\n  }\n};\n\n"
  dependsOn:
  - String/Trie.cpp
  isVerificationFile: false
  path: String/AhoCorasick.cpp
  requiredBy: []
  timestamp: '2022-09-12 14:24:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/AhoCorasick.cpp
layout: document
redirect_from:
- /library/String/AhoCorasick.cpp
- /library/String/AhoCorasick.cpp.html
title: String/AhoCorasick.cpp
---
