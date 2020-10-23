---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/EratosthenesSieve.cpp
    title: Math/EratosthenesSieve.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja
  bundledCode: "#line 1 \"test/AOJ/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"Math/EratosthenesSieve.cpp\"\
    \n#include <algorithm>\n#line 3 \"Math/EratosthenesSieve.cpp\"\n#include <utility>\n\
    \ntemplate<typename T>\nstruct PrimeSieve {\n  T sz;\n  std::vector<T> min_div;\n\
    \  std::vector<T> primes;\n\npublic:\n  constexpr PrimeSieve(T sz) : sz(sz), min_div(sz+1,-1)\
    \ {\n    for(T i = 2; i*i <= sz; ++i){\n      if(min_div[i] > 0) continue;\n \
    \     for(T j = i; i*j <= sz; ++j){\n        min_div[i*j] = i;\n      }\n    }\n\
    \    for(T i = 2; i <= sz; ++i){\n      if(min_div[i] < 0)\n        primes.emplace_back(i);\n\
    \    }\n  }\n  \n  constexpr bool is_prime(T x) const noexcept {\n    if(x <=\
    \ 1) return false;\n    if(x <= sz) return min_div[x] < 0;\n    assert(x <= sz*sz);\n\
    \    for(auto p : primes){\n      if(x%p == 0) return false;\n      if(p*p > x)\
    \ break;\n    }\n    return true;\n  }\n\n  constexpr int count(T x) const noexcept\
    \ { // count p < x\n    return std::lower_bound(primes.begin(), primes.end(),\
    \ x) - primes.begin();\n  }\n\n  constexpr std::vector<std::pair<T,T>> factorize(T\
    \ x) const noexcept {\n    std::vector<std::pair<T,T>> factor;\n    while(x >\
    \ 1){\n      T p = min_div[x];\n      x /= p;\n      if(factor.empty() or factor.back().first\
    \ != p){\n        factor.emplace_back(p,T(1));\n      }else{\n        ++factor.back().second;\n\
    \      }\n    }\n    return factor;\n  }\n};\n#line 7 \"test/AOJ/ALDS1_1_C.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  const int sz = 10000;\n  // max_a <=\
    \ sz*sz\n  PrimeSieve sieve(sz);\n  int n;\n  cin >> n;\n  int ans = 0;\n  for(int\
    \ i = 0; i < n; ++i){\n    int a;\n    cin >> a;\n    ans += sieve.is_prime(a);\n\
    \  }\n  cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"Math/EratosthenesSieve.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  const int sz = 10000;\n  // max_a <=\
    \ sz*sz\n  PrimeSieve sieve(sz);\n  int n;\n  cin >> n;\n  int ans = 0;\n  for(int\
    \ i = 0; i < n; ++i){\n    int a;\n    cin >> a;\n    ans += sieve.is_prime(a);\n\
    \  }\n  cout << ans << endl;\n}\n"
  dependsOn:
  - Math/EratosthenesSieve.cpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2020-10-23 17:45:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_1_C.test.cpp
- /verify/test/AOJ/ALDS1_1_C.test.cpp.html
title: test/AOJ/ALDS1_1_C.test.cpp
---
