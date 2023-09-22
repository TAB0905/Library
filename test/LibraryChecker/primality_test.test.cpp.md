---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/MillerRabin.cpp
    title: Math/MillerRabin.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/LibraryChecker/primality_test.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include <iostream>\n\
    #include <iomanip>\n#line 1 \"Math/MillerRabin.cpp\"\n#include <vector>\n\ntemplate<typename\
    \ T, typename F>\nT power(T x, long long k, F f, T ti){\n  T ret = ti;\n  while(k\
    \ > 0){\n    if(k&1) ret = f(ret,x);\n    x = f(x,x);\n    k /= 2;\n  }\n  return\
    \ ret;\n}\n\nbool miller_rabin(long long n){\n  using int128 = __int128_t;\n \
    \ static const std::vector<long long> A = {2,3,5,7,11,13,17,19,23,29,31,37};\n\
    \  if(n == 1) return false;\n\n  long long m = n-1;\n  m /= m&(-m);\n  \n  for(auto\
    \ a: A){\n    if(a%n == 0) continue;\n    if(a >= n) continue;\n    long long\
    \ e = m;\n    int128 t = power<int128>(a,e,[&](int128 x, long long y){\n     \
    \ return (x*y)%n;\n    }, 1);\n    \n    while(e < n-1){\n      int128 u = t*t%n;\n\
    \      if(u == 1 and t != n-1 and t != 1)\n        return false;\n      t = u;\n\
    \      e *= 2;\n      if(t == 1) break;\n    }\n\n    if(t != 1) return false;\n\
    \  }\n  return true;\n}\n#line 6 \"test/LibraryChecker/primality_test.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int q;\n  cin >> q;\n  while(q--){\n    long long n;\n    cin >> n;\n \
    \   cout << (miller_rabin(n) ? \"Yes\" : \"No\") << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n#include \"Math/MillerRabin.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n \
    \ \n  int q;\n  cin >> q;\n  while(q--){\n    long long n;\n    cin >> n;\n  \
    \  cout << (miller_rabin(n) ? \"Yes\" : \"No\") << '\\n';\n  }\n}\n"
  dependsOn:
  - Math/MillerRabin.cpp
  isVerificationFile: true
  path: test/LibraryChecker/primality_test.test.cpp
  requiredBy: []
  timestamp: '2023-09-22 20:07:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/primality_test.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/primality_test.test.cpp
- /verify/test/LibraryChecker/primality_test.test.cpp.html
title: test/LibraryChecker/primality_test.test.cpp
---
