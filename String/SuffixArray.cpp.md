---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/number_of_substrings.test.cpp
    title: test/LibraryChecker/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/suffix_array.test.cpp
    title: test/LibraryChecker/suffix_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/SuffixArray.cpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <vector>\n\n//\u69CB\u7BC9 : O(|S|log|S|)\nstruct SuffixArray {\nprivate:\n\
    \  std::string s;\n  int size;\n  void constructLCPArray(){\n    for(int i = 0;\
    \ i < size; ++i){\n      rank[SA[i]] = i;\n    }\n    int l = 0;\n    for(int\
    \ i = 0; i < size; ++i){\n      int idx = rank[i];\n      int p1 = SA[idx];\n\
    \      if(idx+1 == size){\n        l = 0;\n        LCP[idx] = l;\n        continue;\n\
    \      }\n      int p2 = SA[idx+1];\n      while(std::max(p1,p2)+l < size and\
    \ s[p1+l] == s[p2+l]) ++l;\n      LCP[idx] = l;\n      --l;\n      l = std::max(l,0);\n\
    \    }\n  }\npublic:\n  std::vector<int> SA, LCP, rank;\n  SuffixArray(std::string\
    \ s_) : s(s_), size(s_.length()+1), SA(size+1), LCP(size+1), rank(size+1) {\n\
    \    s += \"$\";\n  }\n  void construct(){\n    std::vector<int> cnt(std::max(256,size),0);\n\
    \    for(auto e : s){\n      ++cnt[e];\n    }\n    for(size_t i = 1; i < cnt.size();\
    \ ++i)\n      cnt[i] += cnt[i-1];\n    std::vector<int> p(size);\n    for(int\
    \ i = 0; i < size; ++i){\n      p[--cnt[s[i]]] = i;\n    }\n    std::vector<int>\
    \ c(size);\n    c[p[0]] = 0;\n    for(int i = 1; i < size; ++i){\n      c[p[i]]\
    \ = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);\n    }\n\n    for(int k = 1; k < size;\
    \ k *= 2){\n      std::vector<int> p_(size), c_(size);\n      for(int j = 0; j\
    \ < size; ++j){\n        p_[j] = p[j] - k;\n        if(p_[j] < 0) p_[j] += size;\n\
    \      }\n      std::fill(cnt.begin(),cnt.end(),0);\n      \n      int max_e =\
    \ 0;\n      for(auto e : c){\n        ++cnt[e], max_e = std::max(max_e,e);\n \
    \     }\n      for(int i = 0; i < max_e; ++i){\n        cnt[i+1] += cnt[i];\n\
    \      }\n      \n      for(int i = size-1; i >= 0; --i){\n        p[--cnt[c[p_[i]]]]\
    \ = p_[i];\n      }\n      \n      c_[p[0]] = 0;\n      int classes = 1;\n   \
    \   for(int i = 1; i < size; ++i){\n        if((c[p[i]] != c[p[i-1]]) or (c[(p[i]+k)%size]\
    \ != c[(p[i-1]+k)%size]))\n          ++classes;\n        c_[p[i]] = classes-1;\n\
    \      }\n      std::swap(c,c_);\n    }\n\n    SA = p;\n    constructLCPArray();\n\
    \  }\n};\n\n"
  code: "#include <cassert>\n#include <iostream>\n#include <vector>\n\n//\u69CB\u7BC9\
    \ : O(|S|log|S|)\nstruct SuffixArray {\nprivate:\n  std::string s;\n  int size;\n\
    \  void constructLCPArray(){\n    for(int i = 0; i < size; ++i){\n      rank[SA[i]]\
    \ = i;\n    }\n    int l = 0;\n    for(int i = 0; i < size; ++i){\n      int idx\
    \ = rank[i];\n      int p1 = SA[idx];\n      if(idx+1 == size){\n        l = 0;\n\
    \        LCP[idx] = l;\n        continue;\n      }\n      int p2 = SA[idx+1];\n\
    \      while(std::max(p1,p2)+l < size and s[p1+l] == s[p2+l]) ++l;\n      LCP[idx]\
    \ = l;\n      --l;\n      l = std::max(l,0);\n    }\n  }\npublic:\n  std::vector<int>\
    \ SA, LCP, rank;\n  SuffixArray(std::string s_) : s(s_), size(s_.length()+1),\
    \ SA(size+1), LCP(size+1), rank(size+1) {\n    s += \"$\";\n  }\n  void construct(){\n\
    \    std::vector<int> cnt(std::max(256,size),0);\n    for(auto e : s){\n     \
    \ ++cnt[e];\n    }\n    for(size_t i = 1; i < cnt.size(); ++i)\n      cnt[i] +=\
    \ cnt[i-1];\n    std::vector<int> p(size);\n    for(int i = 0; i < size; ++i){\n\
    \      p[--cnt[s[i]]] = i;\n    }\n    std::vector<int> c(size);\n    c[p[0]]\
    \ = 0;\n    for(int i = 1; i < size; ++i){\n      c[p[i]] = c[p[i-1]] + (s[p[i]]\
    \ != s[p[i-1]]);\n    }\n\n    for(int k = 1; k < size; k *= 2){\n      std::vector<int>\
    \ p_(size), c_(size);\n      for(int j = 0; j < size; ++j){\n        p_[j] = p[j]\
    \ - k;\n        if(p_[j] < 0) p_[j] += size;\n      }\n      std::fill(cnt.begin(),cnt.end(),0);\n\
    \      \n      int max_e = 0;\n      for(auto e : c){\n        ++cnt[e], max_e\
    \ = std::max(max_e,e);\n      }\n      for(int i = 0; i < max_e; ++i){\n     \
    \   cnt[i+1] += cnt[i];\n      }\n      \n      for(int i = size-1; i >= 0; --i){\n\
    \        p[--cnt[c[p_[i]]]] = p_[i];\n      }\n      \n      c_[p[0]] = 0;\n \
    \     int classes = 1;\n      for(int i = 1; i < size; ++i){\n        if((c[p[i]]\
    \ != c[p[i-1]]) or (c[(p[i]+k)%size] != c[(p[i-1]+k)%size]))\n          ++classes;\n\
    \        c_[p[i]] = classes-1;\n      }\n      std::swap(c,c_);\n    }\n\n   \
    \ SA = p;\n    constructLCPArray();\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: String/SuffixArray.cpp
  requiredBy: []
  timestamp: '2020-05-23 18:04:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/number_of_substrings.test.cpp
  - test/LibraryChecker/suffix_array.test.cpp
documentation_of: String/SuffixArray.cpp
layout: document
redirect_from:
- /library/String/SuffixArray.cpp
- /library/String/SuffixArray.cpp.html
title: String/SuffixArray.cpp
---
