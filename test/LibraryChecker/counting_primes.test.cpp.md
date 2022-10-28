---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/PrimeCount.cpp
    title: Math/PrimeCount.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"test/LibraryChecker/counting_primes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include <iostream>\n\
    #line 1 \"Math/PrimeCount.cpp\"\n#include <cassert>\n#include <vector>\n\ntemplate<typename\
    \ T>\nT integer_sqrt(T x){\n  T r = 1;\n  while(r*r <= x)\n    ++r;\n  return\
    \ r-1;\n}\n\ntemplate<typename T>\nT prime_count(T n){\n  const T sqrt_n = integer_sqrt(n);\n\
    \  assert(sqrt_n*sqrt_n <= n);\n  assert((sqrt_n+1)*(sqrt_n+1) > n);\n  std::vector<T>\
    \ L, R;\n  for(T i = 1; i <= sqrt_n; ++i){\n    R.emplace_back(n/i-1);\n  }\n\
    \  for(T i = 1; i <= n/sqrt_n; ++i){\n    L.emplace_back(i-1);\n  }\n  std::vector<T>\
    \ pi(n/sqrt_n);\n  for(T i = 2; i*i <= n; ++i){\n    if(L[i-1] <= L[i-2]) continue;\n\
    \    pi[i-2] = L[i-2];\n    for(T j = 1; j*j <= n; ++j){\n      if(n/j < i*i)\
    \ break;\n      ((n/j) <= L.size() ? L[n/j-1] : R[j-1]) -= ((n/i/j) <= L.size()\
    \ ? L[n/i/j-1] : R[i*j-1]) - pi[i-2];\n    }\n    for(T j = n/sqrt_n-1; j > 0;\
    \ --j){\n      if(j < i*i) break;\n      L[j-1] -= L[j/i-1] - pi[i-2];\n    }\n\
    \  }\n  return R[0];\n}\n#line 5 \"test/LibraryChecker/counting_primes.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  long long n;\n  cin >> n;\n  cout <<\
    \ prime_count(n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ <iostream>\n#include \"Math/PrimeCount.cpp\"\nusing namespace std;\n\nint main(){\n\
    \  long long n;\n  cin >> n;\n  cout << prime_count(n) << '\\n';\n}\n"
  dependsOn:
  - Math/PrimeCount.cpp
  isVerificationFile: true
  path: test/LibraryChecker/counting_primes.test.cpp
  requiredBy: []
  timestamp: '2022-10-28 23:06:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/counting_primes.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/counting_primes.test.cpp
- /verify/test/LibraryChecker/counting_primes.test.cpp.html
title: test/LibraryChecker/counting_primes.test.cpp
---
