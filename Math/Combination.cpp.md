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
  bundledCode: "#line 1 \"Math/Combination.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate<typename T>\nstruct Combination {\nprivate:\n  int sz;\n  vector<T>\
    \ F, F_;\npublic:\n  Combination(int sz) : sz(sz), F(sz+1), F_(sz+1) {\n    F[0]\
    \ = 1;\n    for(int i = 0; i < sz; ++i) F[i+1] = F[i]*(i+1);\n    F_.back() =\
    \ (T)1/F.back();\n    for(int i = sz-1; i >= 0; --i) F_[i] = F_[i+1]*(i+1);\n\
    \  }\n  T C(int n, int k){\n    assert(n <= sz);\n    if(n < 0 or k > n) return\
    \ (T)0;\n    return F[n]*F_[k]*F_[n-k];\n  }\n  T P(int n, int k){\n    assert(n\
    \ <= sz);\n    if(n < 0 or k > n) return (T)0;\n    return F[n]*F_[n-k];\n  }\n\
    };\n\n"
  code: "#include <vector>\n#include <cassert>\n\ntemplate<typename T>\nstruct Combination\
    \ {\nprivate:\n  int sz;\n  vector<T> F, F_;\npublic:\n  Combination(int sz) :\
    \ sz(sz), F(sz+1), F_(sz+1) {\n    F[0] = 1;\n    for(int i = 0; i < sz; ++i)\
    \ F[i+1] = F[i]*(i+1);\n    F_.back() = (T)1/F.back();\n    for(int i = sz-1;\
    \ i >= 0; --i) F_[i] = F_[i+1]*(i+1);\n  }\n  T C(int n, int k){\n    assert(n\
    \ <= sz);\n    if(n < 0 or k > n) return (T)0;\n    return F[n]*F_[k]*F_[n-k];\n\
    \  }\n  T P(int n, int k){\n    assert(n <= sz);\n    if(n < 0 or k > n) return\
    \ (T)0;\n    return F[n]*F_[n-k];\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combination.cpp
  requiredBy: []
  timestamp: '2021-03-11 05:53:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combination.cpp
layout: document
redirect_from:
- /library/Math/Combination.cpp
- /library/Math/Combination.cpp.html
title: Math/Combination.cpp
---
