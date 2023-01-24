---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/ModSqrt.cpp
    title: Math/ModSqrt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/LibraryChecker/sqrt_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include <iostream>\n#line 1\
    \ \"Math/ModSqrt.cpp\"\n#include <cassert>\n#line 3 \"Math/ModSqrt.cpp\"\n#include\
    \ <random>\n#include <utility>\nusing namespace std;\n\ntemplate<typename T, typename\
    \ F>\nT power(T x, long long k, F f, T ti){\n  T ret = ti;\n  while(k > 0){\n\
    \    if(k&1) ret = f(ret,x);\n    x = f(x,x);\n    k /= 2;\n  }\n  return ret;\n\
    }\n\ntemplate<typename T>\nbool is_quadratic_residue(T x, T p){ // p must be odd\
    \ prime\n  T y = power(x,(p-1)/2,[&](T a, T b){ return (a*b)%p; },T(1));\n  return\
    \ y == 1;\n}\n\n// Lehmer's algorithm\n// expected O(log p)\ntemplate<typename\
    \ T>\nT mod_sqrt(T a, T p){ // r*r === a mod p\n  // cerr << \"! \" << a << '\
    \ ' << p << '\\n';\n  if(a%p == 0){\n    return 0;\n  }\n  T c = [&](){\n    static\
    \ std::random_device seed_gen;\n    static std::mt19937 engine(seed_gen());\n\
    \    T c = engine()%p;\n    while((c*c%p-a+p)%p == 0 or is_quadratic_residue((c*c%p-a+p)%p,p)){\n\
    \      c = engine()%p;\n    }\n    return c;\n  }(); // expected O(1)\n  auto\
    \ mul = [&](pair<T,T> A, pair<T,T> B){ // mod (x-c)^2 - a = x^2 - 2cx + c^2 -\
    \ a\n    auto [s,t] = A; // sx + t\n    auto [u,v] = B; // ux + v\n    // sux^2\
    \ + (sv+tu)x + tv\n    T e = (s*v%p+t*u%p + 2*c%p*s%p*u%p)%p;\n    T f = (t*v%p\
    \ - s*u%p*(c*c%p-a)%p + p)%p;\n    return pair(e,f);\n  };\n  auto [u,v] = power(pair<T,T>(1,0),(p-1)/2,mul,pair<T,T>(0,1));\n\
    \  v -= 1;\n  T t = (c + (v*power(u,p-2,[&](T x, T y){ return x*y%p; }, T(1)))\
    \ + p)%p;\n  if((t*t)%p == a) return t;\n  t = p-t;\n  assert((t*t)%p == a);\n\
    \  return t;\n}\n\n#line 5 \"test/LibraryChecker/sqrt_mod.test.cpp\"\nusing namespace\
    \ std;\n\nvoid solve(){\n  long long y, p;\n  cin >> y >> p;\n  if(p == 2){\n\
    \    cout << y << '\\n';\n    return;\n  }\n  long long x = (y%p == 0 or is_quadratic_residue(y,p)\
    \ ? mod_sqrt(y,p) : -1);\n  cout << x << '\\n';\n}\n\nint main(){\n  int t;\n\
    \  cin >> t;\n  while(t--) solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ <iostream>\n#include \"Math/ModSqrt.cpp\"\nusing namespace std;\n\nvoid solve(){\n\
    \  long long y, p;\n  cin >> y >> p;\n  if(p == 2){\n    cout << y << '\\n';\n\
    \    return;\n  }\n  long long x = (y%p == 0 or is_quadratic_residue(y,p) ? mod_sqrt(y,p)\
    \ : -1);\n  cout << x << '\\n';\n}\n\nint main(){\n  int t;\n  cin >> t;\n  while(t--)\
    \ solve();\n}\n"
  dependsOn:
  - Math/ModSqrt.cpp
  isVerificationFile: true
  path: test/LibraryChecker/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2023-01-25 05:15:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/sqrt_mod.test.cpp
- /verify/test/LibraryChecker/sqrt_mod.test.cpp.html
title: test/LibraryChecker/sqrt_mod.test.cpp
---
