---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/SuffixArray.cpp
    title: String/SuffixArray.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/LibraryChecker/number_of_substrings.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 1 \"String/SuffixArray.cpp\"\n#include\
    \ <cassert>\n#line 4 \"String/SuffixArray.cpp\"\n\n//\u69CB\u7BC9 : O(|S|log|S|)\n\
    struct SuffixArray {\nprivate:\n  std::string s;\n  int size;\n  void constructLCPArray(){\n\
    \    for(int i = 0; i < size; ++i){\n      rank[SA[i]] = i;\n    }\n    int l\
    \ = 0;\n    for(int i = 0; i < size; ++i){\n      int idx = rank[i];\n      int\
    \ p1 = SA[idx];\n      if(idx+1 == size){\n        l = 0;\n        LCP[idx] =\
    \ l;\n        continue;\n      }\n      int p2 = SA[idx+1];\n      while(std::max(p1,p2)+l\
    \ < size and s[p1+l] == s[p2+l]) ++l;\n      LCP[idx] = l;\n      --l;\n     \
    \ l = std::max(l,0);\n    }\n  }\npublic:\n  std::vector<int> SA, LCP, rank;\n\
    \  SuffixArray(std::string s_) : s(s_), size(s_.length()+1), SA(size+1), LCP(size+1),\
    \ rank(size+1) {\n    s += \"$\";\n  }\n  void construct(){\n    std::vector<int>\
    \ cnt(std::max(256,size),0);\n    for(auto e : s){\n      ++cnt[e];\n    }\n \
    \   for(size_t i = 1; i < cnt.size(); ++i)\n      cnt[i] += cnt[i-1];\n    std::vector<int>\
    \ p(size);\n    for(int i = 0; i < size; ++i){\n      p[--cnt[s[i]]] = i;\n  \
    \  }\n    std::vector<int> c(size);\n    c[p[0]] = 0;\n    for(int i = 1; i <\
    \ size; ++i){\n      c[p[i]] = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);\n    }\n\n\
    \    for(int k = 1; k < size; k *= 2){\n      std::vector<int> p_(size), c_(size);\n\
    \      for(int j = 0; j < size; ++j){\n        p_[j] = p[j] - k;\n        if(p_[j]\
    \ < 0) p_[j] += size;\n      }\n      std::fill(cnt.begin(),cnt.end(),0);\n  \
    \    \n      int max_e = 0;\n      for(auto e : c){\n        ++cnt[e], max_e =\
    \ std::max(max_e,e);\n      }\n      for(int i = 0; i < max_e; ++i){\n       \
    \ cnt[i+1] += cnt[i];\n      }\n      \n      for(int i = size-1; i >= 0; --i){\n\
    \        p[--cnt[c[p_[i]]]] = p_[i];\n      }\n      \n      c_[p[0]] = 0;\n \
    \     int classes = 1;\n      for(int i = 1; i < size; ++i){\n        if((c[p[i]]\
    \ != c[p[i-1]]) or (c[(p[i]+k)%size] != c[(p[i-1]+k)%size]))\n          ++classes;\n\
    \        c_[p[i]] = classes-1;\n      }\n      std::swap(c,c_);\n    }\n\n   \
    \ SA = p;\n    constructLCPArray();\n  }\n};\n\n#line 7 \"test/LibraryChecker/number_of_substrings.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  using ll = long long;\n  string s;\n\
    \  cin >> s;\n  SuffixArray sa(s);\n  sa.construct();\n  int n = s.length();\n\
    \  ll ans = 0;\n  \n  for(int i = 1; i <= n; ++i){\n    int l = sa.LCP[i-1] +\
    \ 1, r = n - sa.SA[i] + 1;\n    ans += r-l;\n  }\n  cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"String/SuffixArray.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  using ll = long long;\n  string s;\n\
    \  cin >> s;\n  SuffixArray sa(s);\n  sa.construct();\n  int n = s.length();\n\
    \  ll ans = 0;\n  \n  for(int i = 1; i <= n; ++i){\n    int l = sa.LCP[i-1] +\
    \ 1, r = n - sa.SA[i] + 1;\n    ans += r-l;\n  }\n  cout << ans << endl;\n}\n"
  dependsOn:
  - String/SuffixArray.cpp
  isVerificationFile: true
  path: test/LibraryChecker/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 01:04:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/number_of_substrings.test.cpp
- /verify/test/LibraryChecker/number_of_substrings.test.cpp.html
title: test/LibraryChecker/number_of_substrings.test.cpp
---
