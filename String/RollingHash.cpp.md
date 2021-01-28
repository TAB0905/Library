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
  bundledCode: "#line 1 \"String/RollingHash.cpp\"\n#include <array>\n#include <vector>\n\
    \nstruct RollingHash{\n  int n;\n  static constexpr int n_base = 2;\n  static\
    \ constexpr array<long long, n_base> base{1009,9973};\n  static constexpr array<long\
    \ long, n_base> mod{1000000007,1000000009};\n\n  vector<array<long long, n_base>>\
    \ hash, power;\n\n  RollingHash(string s) : n(s.size()), hash(n+1), power(n+1)\
    \ {\n    for(int i = 0; i < n_base; ++i)\n      power[0][i] = 1;\n    for(int\
    \ i = 0; i < n; ++i){\n      for(int j = 0; j < n_base; ++j){\n        hash[i+1][j]\
    \ = (hash[i][j]+s[i])*base[j]%mod[j];\n        power[i+1][j] = power[i][j]*base[j]%mod[j];\n\
    \      }\n    }\n  }\n  array<long long,n_base> get(int l, int r){//[l,r)\n  \
    \  array<long long,n_base> ret;\n    for(int i = 0; i < n_base; ++i)\n      ret[i]\
    \ = ((hash[r][i]-hash[l][i]*power[r-l][i])%mod[i]+mod[i])%mod[i];\n    return\
    \ ret;\n  }\n};\n\n\nstruct RollingHash_64{\n  int n;\n  unsigned long long base;\n\
    \  vector<unsigned long long> hash, power;\n  RollingHash_64(string s){\n    base\
    \ = 1e9 + 7;\n    n = s.size();\n    hash.assign(n+1,0);\n    power.assign(n+1,1);\n\
    \    for(int i = 0; i < n; ++i){\n      hash[i+1] = (hash[i]+s[i])*base;\n   \
    \   power[i+1] = power[i]*base;\n    }\n  }\n  unsigned long long get(int l, int\
    \ r){//[l,r)\n    return hash[r]-hash[l]*power[r-l];\n  }\n};\n"
  code: "#include <array>\n#include <vector>\n\nstruct RollingHash{\n  int n;\n  static\
    \ constexpr int n_base = 2;\n  static constexpr array<long long, n_base> base{1009,9973};\n\
    \  static constexpr array<long long, n_base> mod{1000000007,1000000009};\n\n \
    \ vector<array<long long, n_base>> hash, power;\n\n  RollingHash(string s) : n(s.size()),\
    \ hash(n+1), power(n+1) {\n    for(int i = 0; i < n_base; ++i)\n      power[0][i]\
    \ = 1;\n    for(int i = 0; i < n; ++i){\n      for(int j = 0; j < n_base; ++j){\n\
    \        hash[i+1][j] = (hash[i][j]+s[i])*base[j]%mod[j];\n        power[i+1][j]\
    \ = power[i][j]*base[j]%mod[j];\n      }\n    }\n  }\n  array<long long,n_base>\
    \ get(int l, int r){//[l,r)\n    array<long long,n_base> ret;\n    for(int i =\
    \ 0; i < n_base; ++i)\n      ret[i] = ((hash[r][i]-hash[l][i]*power[r-l][i])%mod[i]+mod[i])%mod[i];\n\
    \    return ret;\n  }\n};\n\n\nstruct RollingHash_64{\n  int n;\n  unsigned long\
    \ long base;\n  vector<unsigned long long> hash, power;\n  RollingHash_64(string\
    \ s){\n    base = 1e9 + 7;\n    n = s.size();\n    hash.assign(n+1,0);\n    power.assign(n+1,1);\n\
    \    for(int i = 0; i < n; ++i){\n      hash[i+1] = (hash[i]+s[i])*base;\n   \
    \   power[i+1] = power[i]*base;\n    }\n  }\n  unsigned long long get(int l, int\
    \ r){//[l,r)\n    return hash[r]-hash[l]*power[r-l];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '2020-12-13 21:55:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RollingHash.cpp
layout: document
redirect_from:
- /library/String/RollingHash.cpp
- /library/String/RollingHash.cpp.html
title: String/RollingHash.cpp
---
