---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/prime_list.cpp
    title: Math/prime_list.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/LibraryChecker/enumerate_primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include <iostream>\n\
    #include <vector>\n#line 1 \"Math/prime_list.cpp\"\n#include <algorithm>\n#include\
    \ <bitset>\n#line 5 \"Math/prime_list.cpp\"\nusing namespace std;\n\ntemplate<long\
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
    \  }\n  return primes;\n}\n#line 5 \"test/LibraryChecker/enumerate_primes.test.cpp\"\
    \n\nint main(){\n  long long n, a, b;\n  cin >> n >> a >> b;\n  auto P = prime_list(n);\n\
    \  vector<long long> Q;\n  for(size_t i = b; i < P.size(); i += a){\n    Q.emplace_back(P[i]);\n\
    \  }\n  cout << P.size() << \" \" << Q.size() << endl;\n  for(size_t i = 0; i\
    \ < Q.size(); ++i){\n    cout << Q[i] << (i+1 < Q.size() ? ' ' : '\\n');\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"Math/prime_list.cpp\"\n\nint main(){\n\
    \  long long n, a, b;\n  cin >> n >> a >> b;\n  auto P = prime_list(n);\n  vector<long\
    \ long> Q;\n  for(size_t i = b; i < P.size(); i += a){\n    Q.emplace_back(P[i]);\n\
    \  }\n  cout << P.size() << \" \" << Q.size() << endl;\n  for(size_t i = 0; i\
    \ < Q.size(); ++i){\n    cout << Q[i] << (i+1 < Q.size() ? ' ' : '\\n');\n  }\n\
    }\n"
  dependsOn:
  - Math/prime_list.cpp
  isVerificationFile: true
  path: test/LibraryChecker/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2021-01-05 00:20:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/enumerate_primes.test.cpp
- /verify/test/LibraryChecker/enumerate_primes.test.cpp.html
title: test/LibraryChecker/enumerate_primes.test.cpp
---
