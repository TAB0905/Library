---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/0009.test.cpp
    title: test/AOJ/0009.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Math/EratosthenesSieve.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#include <utility>\n\ntemplate<typename T>\nstruct PrimeSieve {\n\
    \  T sz;\n  std::vector<T> min_div;\n  std::vector<T> primes;\n\npublic:\n  constexpr\
    \ PrimeSieve(T sz) : sz(sz), min_div(sz+1,-1) {\n    for(T i = 2; i*i <= sz; ++i){\n\
    \      if(min_div[i] > 0) continue;\n      for(T j = i; i*j <= sz; ++j){\n   \
    \     min_div[i*j] = i;\n      }\n    }\n    for(T i = 2; i <= sz; ++i){\n   \
    \   if(min_div[i] < 0)\n        primes.emplace_back(i);\n    }\n  }\n  \n  constexpr\
    \ bool is_prime(T x) const noexcept {\n    if(x <= 1) return false;\n    if(x\
    \ <= sz) min_div[x] < 0;\n    for(auto p : primes){\n      if(x%p == 0) return\
    \ false;\n      if(p*p > x) break;\n    }\n    return true;\n  }\n\n  constexpr\
    \ int count(T x) const noexcept { // count p < x\n    return std::lower_bound(primes.begin(),\
    \ primes.end(), x) - primes.begin();\n  }\n\n  constexpr std::vector<std::pair<T,T>>\
    \ factorize(T x) const noexcept {\n    std::vector<std::pair<T,T>> factor;\n \
    \   while(x > 1){\n      T p = min_div[x];\n      x /= p;\n      if(factor.empty()\
    \ or factor.back().first != p){\n        factor.emplace_back(p,T(1));\n      }else{\n\
    \        ++factor.back().first;\n      }\n    }\n    return factor;\n  }\n};\n"
  code: "#include <algorithm>\n#include <vector>\n#include <utility>\n\ntemplate<typename\
    \ T>\nstruct PrimeSieve {\n  T sz;\n  std::vector<T> min_div;\n  std::vector<T>\
    \ primes;\n\npublic:\n  constexpr PrimeSieve(T sz) : sz(sz), min_div(sz+1,-1)\
    \ {\n    for(T i = 2; i*i <= sz; ++i){\n      if(min_div[i] > 0) continue;\n \
    \     for(T j = i; i*j <= sz; ++j){\n        min_div[i*j] = i;\n      }\n    }\n\
    \    for(T i = 2; i <= sz; ++i){\n      if(min_div[i] < 0)\n        primes.emplace_back(i);\n\
    \    }\n  }\n  \n  constexpr bool is_prime(T x) const noexcept {\n    if(x <=\
    \ 1) return false;\n    if(x <= sz) min_div[x] < 0;\n    for(auto p : primes){\n\
    \      if(x%p == 0) return false;\n      if(p*p > x) break;\n    }\n    return\
    \ true;\n  }\n\n  constexpr int count(T x) const noexcept { // count p < x\n \
    \   return std::lower_bound(primes.begin(), primes.end(), x) - primes.begin();\n\
    \  }\n\n  constexpr std::vector<std::pair<T,T>> factorize(T x) const noexcept\
    \ {\n    std::vector<std::pair<T,T>> factor;\n    while(x > 1){\n      T p = min_div[x];\n\
    \      x /= p;\n      if(factor.empty() or factor.back().first != p){\n      \
    \  factor.emplace_back(p,T(1));\n      }else{\n        ++factor.back().first;\n\
    \      }\n    }\n    return factor;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/EratosthenesSieve.cpp
  requiredBy: []
  timestamp: '2020-09-27 02:13:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/0009.test.cpp
documentation_of: Math/EratosthenesSieve.cpp
layout: document
redirect_from:
- /library/Math/EratosthenesSieve.cpp
- /library/Math/EratosthenesSieve.cpp.html
title: Math/EratosthenesSieve.cpp
---
