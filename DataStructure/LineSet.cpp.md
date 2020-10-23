---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/line_add_get_min.test.cpp
    title: test/LibraryChecker/line_add_get_min.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/LineSet.cpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#include <map>\n#include <vector>\n\ntemplate<typename T>\nclass\
    \ LineSet {\nprivate:\n  std::map<T,T> L;// \u50BE\u304D\u2192\u5207\u7247\n \
    \ T max_a, min_a;\npublic:\n  LineSet(T ai) : L(), max_a(-ai), min_a(ai) {}\n\
    \  void push(T a, T b){// push ax + b\n    min_a = std::min(min_a,a);\n    max_a\
    \ = std::max(max_a,a);\n    \n    if(L.empty()){\n      L[a] = b;\n      return;\n\
    \    }\n    \n    if(L.size() == 1){\n      if(L.find(a) != L.end())\n       \
    \ L[a] = std::min(L[a],b);\n      else\n        L[a] = b;\n      return;\n   \
    \ }\n\n    if(a == min_a or a == max_a){\n      if(L.find(a) != L.end())\n   \
    \     L[a] = std::min(L[a],b);\n      else\n        L[a] = b;\n    }\n\n    if(L.find(a)\
    \ == L.end()){\n      auto ll = L.lower_bound(a);\n      auto lr = prev(ll);\n\
    \      if((a-lr->first)*(b-ll->second) >= (ll->first-a)*(lr->second-b))\n    \
    \    return;\n      L[a] = b;\n    }else{\n      L[a] = std::min(L[a],b);\n  \
    \  }\n\n    if(L.find(a) == L.end() or L[a] != b){\n      return;\n    }\n   \
    \ \n    while(1){\n      auto ll = L.find(a);\n      if(ll == L.begin()) break;\n\
    \      auto lm = prev(ll);\n      if(lm == L.begin()) break;\n      auto lr =\
    \ prev(lm);\n      if((lm->first-lr->first)*(lm->second-ll->second) < (ll->first-lm->first)*(lr->second-lm->second))\n\
    \        break;\n      L.erase(lm);\n    }\n\n    while(1){\n      auto lr = L.find(a);\n\
    \      auto lm = next(lr);\n      if(lm == L.end()) break;\n      auto ll = next(lm);\n\
    \      if(ll == L.end()) break;\n      if((lm->first-lr->first)*(lm->second-ll->second)\
    \ < (ll->first-lm->first)*(lr->second-lm->second))\n        break;\n      L.erase(lm);\n\
    \    }\n  }\n  T get(T x){\n    // T ans = 2e18;\n    // for(auto [a, b] : L){\n\
    \    //   ans = std::min(ans,a*x+b);\n    // }\n    // return ans;\n    if(L.size()\
    \ == 1){\n      auto [a, b] = *L.begin();\n      return a*x + b;\n    }\n    T\
    \ la = min_a, ra = max_a;\n    while(ra-la > 1){\n      T m = (la+ra)/2;\n   \
    \   auto r = L.upper_bound(m);\n      assert(r != L.begin());\n      assert(r\
    \ != L.end());\n      auto l = prev(r);\n      if(l->first*x+l->second < r->first*x+r->second){\n\
    \        ra = l->first;\n      }else{\n        la = r->first;\n      }\n    }\n\
    \    auto [a, b] = *L.lower_bound(la);\n    T ret = a*x+b;\n    auto itr = L.lower_bound(la);\n\
    \    if(itr != L.end() and next(itr) != L.end()){\n      auto nex = next(itr);\n\
    \      ret = std::min(ret,nex->first*x + nex->second);\n    }\n    if(itr != L.begin()){\n\
    \      auto pre = prev(itr);\n      ret = std::min(ret,pre->first*x + pre->second);\n\
    \    }\n    return ret;\n  }\n};\n\n"
  code: "#include <cassert>\n#include <iostream>\n#include <map>\n#include <vector>\n\
    \ntemplate<typename T>\nclass LineSet {\nprivate:\n  std::map<T,T> L;// \u50BE\
    \u304D\u2192\u5207\u7247\n  T max_a, min_a;\npublic:\n  LineSet(T ai) : L(), max_a(-ai),\
    \ min_a(ai) {}\n  void push(T a, T b){// push ax + b\n    min_a = std::min(min_a,a);\n\
    \    max_a = std::max(max_a,a);\n    \n    if(L.empty()){\n      L[a] = b;\n \
    \     return;\n    }\n    \n    if(L.size() == 1){\n      if(L.find(a) != L.end())\n\
    \        L[a] = std::min(L[a],b);\n      else\n        L[a] = b;\n      return;\n\
    \    }\n\n    if(a == min_a or a == max_a){\n      if(L.find(a) != L.end())\n\
    \        L[a] = std::min(L[a],b);\n      else\n        L[a] = b;\n    }\n\n  \
    \  if(L.find(a) == L.end()){\n      auto ll = L.lower_bound(a);\n      auto lr\
    \ = prev(ll);\n      if((a-lr->first)*(b-ll->second) >= (ll->first-a)*(lr->second-b))\n\
    \        return;\n      L[a] = b;\n    }else{\n      L[a] = std::min(L[a],b);\n\
    \    }\n\n    if(L.find(a) == L.end() or L[a] != b){\n      return;\n    }\n \
    \   \n    while(1){\n      auto ll = L.find(a);\n      if(ll == L.begin()) break;\n\
    \      auto lm = prev(ll);\n      if(lm == L.begin()) break;\n      auto lr =\
    \ prev(lm);\n      if((lm->first-lr->first)*(lm->second-ll->second) < (ll->first-lm->first)*(lr->second-lm->second))\n\
    \        break;\n      L.erase(lm);\n    }\n\n    while(1){\n      auto lr = L.find(a);\n\
    \      auto lm = next(lr);\n      if(lm == L.end()) break;\n      auto ll = next(lm);\n\
    \      if(ll == L.end()) break;\n      if((lm->first-lr->first)*(lm->second-ll->second)\
    \ < (ll->first-lm->first)*(lr->second-lm->second))\n        break;\n      L.erase(lm);\n\
    \    }\n  }\n  T get(T x){\n    // T ans = 2e18;\n    // for(auto [a, b] : L){\n\
    \    //   ans = std::min(ans,a*x+b);\n    // }\n    // return ans;\n    if(L.size()\
    \ == 1){\n      auto [a, b] = *L.begin();\n      return a*x + b;\n    }\n    T\
    \ la = min_a, ra = max_a;\n    while(ra-la > 1){\n      T m = (la+ra)/2;\n   \
    \   auto r = L.upper_bound(m);\n      assert(r != L.begin());\n      assert(r\
    \ != L.end());\n      auto l = prev(r);\n      if(l->first*x+l->second < r->first*x+r->second){\n\
    \        ra = l->first;\n      }else{\n        la = r->first;\n      }\n    }\n\
    \    auto [a, b] = *L.lower_bound(la);\n    T ret = a*x+b;\n    auto itr = L.lower_bound(la);\n\
    \    if(itr != L.end() and next(itr) != L.end()){\n      auto nex = next(itr);\n\
    \      ret = std::min(ret,nex->first*x + nex->second);\n    }\n    if(itr != L.begin()){\n\
    \      auto pre = prev(itr);\n      ret = std::min(ret,pre->first*x + pre->second);\n\
    \    }\n    return ret;\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LineSet.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:06:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/line_add_get_min.test.cpp
documentation_of: DataStructure/LineSet.cpp
layout: document
redirect_from:
- /library/DataStructure/LineSet.cpp
- /library/DataStructure/LineSet.cpp.html
title: DataStructure/LineSet.cpp
---
