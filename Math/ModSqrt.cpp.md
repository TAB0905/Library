---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/sqrt_mod.test.cpp
    title: test/LibraryChecker/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/ModSqrt.cpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <random>\n#include <utility>\nusing namespace std;\n\ntemplate<typename\
    \ T, typename F>\nT power(T x, long long k, F f, T ti){\n  T ret = ti;\n  while(k\
    \ > 0){\n    if(k&1) ret = f(ret,x);\n    x = f(x,x);\n    k /= 2;\n  }\n  return\
    \ ret;\n}\n\ntemplate<typename T>\nbool is_quadratic_residue(T x, T p){ // p must\
    \ be odd prime\n  T y = power(x,(p-1)/2,[&](T a, T b){ return (a*b)%p; },T(1));\n\
    \  return y == 1;\n}\n\n// Lehmer's algorithm\n// expected O(log p)\ntemplate<typename\
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
    \  return t;\n}\n\n"
  code: "#include <cassert>\n#include <iostream>\n#include <random>\n#include <utility>\n\
    using namespace std;\n\ntemplate<typename T, typename F>\nT power(T x, long long\
    \ k, F f, T ti){\n  T ret = ti;\n  while(k > 0){\n    if(k&1) ret = f(ret,x);\n\
    \    x = f(x,x);\n    k /= 2;\n  }\n  return ret;\n}\n\ntemplate<typename T>\n\
    bool is_quadratic_residue(T x, T p){ // p must be odd prime\n  T y = power(x,(p-1)/2,[&](T\
    \ a, T b){ return (a*b)%p; },T(1));\n  return y == 1;\n}\n\n// Lehmer's algorithm\n\
    // expected O(log p)\ntemplate<typename T>\nT mod_sqrt(T a, T p){ // r*r === a\
    \ mod p\n  // cerr << \"! \" << a << ' ' << p << '\\n';\n  if(a%p == 0){\n   \
    \ return 0;\n  }\n  T c = [&](){\n    static std::random_device seed_gen;\n  \
    \  static std::mt19937 engine(seed_gen());\n    T c = engine()%p;\n    while((c*c%p-a+p)%p\
    \ == 0 or is_quadratic_residue((c*c%p-a+p)%p,p)){\n      c = engine()%p;\n   \
    \ }\n    return c;\n  }(); // expected O(1)\n  auto mul = [&](pair<T,T> A, pair<T,T>\
    \ B){ // mod (x-c)^2 - a = x^2 - 2cx + c^2 - a\n    auto [s,t] = A; // sx + t\n\
    \    auto [u,v] = B; // ux + v\n    // sux^2 + (sv+tu)x + tv\n    T e = (s*v%p+t*u%p\
    \ + 2*c%p*s%p*u%p)%p;\n    T f = (t*v%p - s*u%p*(c*c%p-a)%p + p)%p;\n    return\
    \ pair(e,f);\n  };\n  auto [u,v] = power(pair<T,T>(1,0),(p-1)/2,mul,pair<T,T>(0,1));\n\
    \  v -= 1;\n  T t = (c + (v*power(u,p-2,[&](T x, T y){ return x*y%p; }, T(1)))\
    \ + p)%p;\n  if((t*t)%p == a) return t;\n  t = p-t;\n  assert((t*t)%p == a);\n\
    \  return t;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/ModSqrt.cpp
  requiredBy: []
  timestamp: '2023-01-25 05:15:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/sqrt_mod.test.cpp
documentation_of: Math/ModSqrt.cpp
layout: document
redirect_from:
- /library/Math/ModSqrt.cpp
- /library/Math/ModSqrt.cpp.html
title: Math/ModSqrt.cpp
---
