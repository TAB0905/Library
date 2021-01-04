---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/enumerate_primes.test.cpp
    title: test/LibraryChecker/enumerate_primes.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/prime_list.cpp\"\n#include <algorithm>\n#include <bitset>\n\
    #include <iostream>\n#include <vector>\nusing namespace std;\n\ntemplate<long\
    \ long bucket_size=1<<24>\nvector<long long> prime_list(long long max){\n  ++max;\n\
    \  vector<long long> primes;\n  bitset<bucket_size> is_prime;\n  for(long long\
    \ i = 0; i < (max+bucket_size-1)/bucket_size; ++i){\n    const int sz = min(bucket_size,max-bucket_size*i);\n\
    \    is_prime = ~bitset<bucket_size>(0);\n    const long long l = bucket_size*i,\
    \ r = l + sz;//[l,r)\n    for(const auto& p : primes){\n      if(p*p >= r) break;\n\
    \      for(long long j = (l+p-1)/p; j < (r+p-1)/p; ++j){\n        is_prime[p*j-l]\
    \ = false;\n      }\n    }\n    for(long long j = l; j*j < r; ++j){\n      if(j\
    \ <= 1) continue;\n      if(!is_prime[j-l]) continue;\n      for(long long k =\
    \ j; j*k < r; ++k)\n        is_prime[j*k-l] = false;\n    }\n    for(long long\
    \ j = l; j < r; ++j)\n      if(j > 1 and is_prime[j-l])\n        primes.emplace_back(j);\n\
    \  }\n  return primes;\n}\n"
  code: "#include <algorithm>\n#include <bitset>\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\ntemplate<long long bucket_size=1<<24>\nvector<long long>\
    \ prime_list(long long max){\n  ++max;\n  vector<long long> primes;\n  bitset<bucket_size>\
    \ is_prime;\n  for(long long i = 0; i < (max+bucket_size-1)/bucket_size; ++i){\n\
    \    const int sz = min(bucket_size,max-bucket_size*i);\n    is_prime = ~bitset<bucket_size>(0);\n\
    \    const long long l = bucket_size*i, r = l + sz;//[l,r)\n    for(const auto&\
    \ p : primes){\n      if(p*p >= r) break;\n      for(long long j = (l+p-1)/p;\
    \ j < (r+p-1)/p; ++j){\n        is_prime[p*j-l] = false;\n      }\n    }\n   \
    \ for(long long j = l; j*j < r; ++j){\n      if(j <= 1) continue;\n      if(!is_prime[j-l])\
    \ continue;\n      for(long long k = j; j*k < r; ++k)\n        is_prime[j*k-l]\
    \ = false;\n    }\n    for(long long j = l; j < r; ++j)\n      if(j > 1 and is_prime[j-l])\n\
    \        primes.emplace_back(j);\n  }\n  return primes;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/prime_list.cpp
  requiredBy: []
  timestamp: '2021-01-05 00:20:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/enumerate_primes.test.cpp
documentation_of: Math/prime_list.cpp
layout: document
redirect_from:
- /library/Math/prime_list.cpp
- /library/Math/prime_list.cpp.html
title: Math/prime_list.cpp
---
