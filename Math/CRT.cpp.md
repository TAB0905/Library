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
  bundledCode: "#line 1 \"Math/CRT.cpp\"\n#include <vector>\n#include <utility>\n\n\
    long long extgcd(long long a, long long b, long long &x, long long &y){\n  long\
    \ long d = a;\n  if(b){\n    d = extgcd(b, a%b, y, x);\n    y -= (a/b)*x;\n  }else{\n\
    \    x = 1;\n    y = 0;\n  }\n  return d;    \n}\n\nstd::pair<long long, long\
    \ long> CRT(const std::vector<std::pair<long long, long long>> &V){\n  //x%V[i].second\
    \ == V[i].first\n  long long a = 0, t = 1;\n  for(size_t i = 0; i < V.size();\
    \ ++i){\n    long long r = V[i].first, m = V[i].second, x, y;\n    long long g\
    \ = extgcd(t,m,x,y);\n    if((r-a)%g) return {-1,-1};\n    a += ((((r-a)/g)%m+m)%m*(x%m+m)%m)*t;\n\
    \    t *= (m/g);\n    a %= t;\n    if(a > 1e12) return {-1,-1};\n  }\n  return\
    \ {a, t};\n}\n"
  code: "#include <vector>\n#include <utility>\n\nlong long extgcd(long long a, long\
    \ long b, long long &x, long long &y){\n  long long d = a;\n  if(b){\n    d =\
    \ extgcd(b, a%b, y, x);\n    y -= (a/b)*x;\n  }else{\n    x = 1;\n    y = 0;\n\
    \  }\n  return d;    \n}\n\nstd::pair<long long, long long> CRT(const std::vector<std::pair<long\
    \ long, long long>> &V){\n  //x%V[i].second == V[i].first\n  long long a = 0,\
    \ t = 1;\n  for(size_t i = 0; i < V.size(); ++i){\n    long long r = V[i].first,\
    \ m = V[i].second, x, y;\n    long long g = extgcd(t,m,x,y);\n    if((r-a)%g)\
    \ return {-1,-1};\n    a += ((((r-a)/g)%m+m)%m*(x%m+m)%m)*t;\n    t *= (m/g);\n\
    \    a %= t;\n    if(a > 1e12) return {-1,-1};\n  }\n  return {a, t};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/CRT.cpp
  requiredBy: []
  timestamp: '2020-10-23 20:40:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/CRT.cpp
layout: document
redirect_from:
- /library/Math/CRT.cpp
- /library/Math/CRT.cpp.html
title: Math/CRT.cpp
---
