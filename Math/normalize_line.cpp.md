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
  bundledCode: "#line 1 \"Math/normalize_line.cpp\"\n#include <numeric>\n#include\
    \ <tuple>\n#include <utility>\n\ntemplate<typename T>\nstd::tuple<T,T,T> normalize_line(std::pair<T,T>\
    \ p, std::pair<T,T> q){\n  T a = q.second - p.second;\n  T b = p.first - q.first;\n\
    \  T c = a*p.first + b*p.second;\n  T g = std::gcd(std::gcd(a,b),c);\n  a /= g,\
    \ b /= g, c /= g;\n  if(a < 0) a *= -1, b *= -1, c *= -1;\n  if(!a and b < 0)\
    \ b *= -1, c *= -1;\n  return std::tuple(a,b,c);\n}\n\n"
  code: "#include <numeric>\n#include <tuple>\n#include <utility>\n\ntemplate<typename\
    \ T>\nstd::tuple<T,T,T> normalize_line(std::pair<T,T> p, std::pair<T,T> q){\n\
    \  T a = q.second - p.second;\n  T b = p.first - q.first;\n  T c = a*p.first +\
    \ b*p.second;\n  T g = std::gcd(std::gcd(a,b),c);\n  a /= g, b /= g, c /= g;\n\
    \  if(a < 0) a *= -1, b *= -1, c *= -1;\n  if(!a and b < 0) b *= -1, c *= -1;\n\
    \  return std::tuple(a,b,c);\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/normalize_line.cpp
  requiredBy: []
  timestamp: '2022-04-29 20:17:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/normalize_line.cpp
layout: document
redirect_from:
- /library/Math/normalize_line.cpp
- /library/Math/normalize_line.cpp.html
title: Math/normalize_line.cpp
---
