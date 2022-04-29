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
  bundledCode: "#line 1 \"Math/mebius.cpp\"\n#include <vector>\n\n// O(n*log(n))\n\
    std::vector<int> mebius(int n){\n  std::vector<int> m(n+1,1);\n  std::vector<bool>\
    \ is_prime(n+1,true);\n  for(long long i = 2; i <= n; ++i){\n    if(!is_prime[i])\
    \ continue;\n    m[i] *= -1;\n    for(int j = 2; j*i <= n; ++j){\n      is_prime[i*j]\
    \ = false;\n      m[i*j] *= -1;\n    }\n    for(int j = 1; j*i*i <= n; ++j)\n\
    \      m[i*i*j] = 0;\n  }\n  return m;\n}\n"
  code: "#include <vector>\n\n// O(n*log(n))\nstd::vector<int> mebius(int n){\n  std::vector<int>\
    \ m(n+1,1);\n  std::vector<bool> is_prime(n+1,true);\n  for(long long i = 2; i\
    \ <= n; ++i){\n    if(!is_prime[i]) continue;\n    m[i] *= -1;\n    for(int j\
    \ = 2; j*i <= n; ++j){\n      is_prime[i*j] = false;\n      m[i*j] *= -1;\n  \
    \  }\n    for(int j = 1; j*i*i <= n; ++j)\n      m[i*i*j] = 0;\n  }\n  return\
    \ m;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/mebius.cpp
  requiredBy: []
  timestamp: '2022-04-29 19:09:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/mebius.cpp
layout: document
redirect_from:
- /library/Math/mebius.cpp
- /library/Math/mebius.cpp.html
title: Math/mebius.cpp
---
