---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/DiscreteLogarithm.test.cpp
    title: test/LibraryChecker/DiscreteLogarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/DiscreteLog.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n#include <utility>\n#include <map>\n#include <numeric>\n\n\
    // ax + by = gcd(a,b)\nlong long extgcd(long long a, long long b, long long &x,\
    \ long long &y){\n  long long d = a;\n  if(b){\n    d = extgcd(b, a%b, y, x);\n\
    \    y -= (a / b)*x;\n  }else{\n    x = 1;\n    y = 0;\n  }\n  assert(a*x + b*y\
    \ == d);\n  return d;    \n}\n\ntemplate<typename T, typename F>\nT power(T x,\
    \ long long k, F f, T ti){\n  T ret = ti;\n  while(k > 0){\n    if(k&1) ret =\
    \ f(ret,x);\n    x = f(x,x);\n    k /= 2;\n  }\n  return ret;\n}\n\n/*\n  x^k\
    \ == y (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E k \u3092\u8FD4\u3059\n  0\
    \ <= k < m\n  \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F -1 \u3092\u8FD4\
    \u3059\n  O(b*log(b))\n  b*b >= m \u3068\u306A\u308B\u3088\u3046\u306A b \u3092\
    \u9078\u3076\u5FC5\u8981\u304C\u3042\u308B\n*/\ntemplate<long long b>\nlong long\
    \ discrete_log_coprime(long long x, long long y, long long m){\n\n  if(y == 1\
    \ or m == 1)\n    return 0;\n  \n  if(x == 0){\n    if(y == 1) return 0;\n   \
    \ if(y == 0) return 1;\n    return -1;\n  }\n\n  std::map<long long,int> bs;\n\
    \  long long xb = 1;\n  for(int i = 0; i < b; ++i){\n    if(xb == y) return i;\n\
    \    if(!bs.count(xb))\n      bs[xb] = i;\n    xb *= x;\n    xb %= m;\n  }\n \
    \   \n  long long x_inv,z;\n  long long g_ = extgcd(x,m,x_inv,z);\n  assert(g_\
    \ == 1);\n  if(x_inv < 0) x_inv %= m, x_inv += m;\n  assert((x*x_inv)%m == 1);\n\
    \  long long x_inv_b = power<long long>(x_inv,b,[&](long long p, long long q){return\
    \ (p*q)%m;},1LL);\n\n  for(int i = 0; i <= b; ++i){\n    if(bs.count(y))\n   \
    \   return bs[y]+i*b;\n    y *= x_inv_b;\n    y %= m;\n  }\n\n  return -1;\n}\n\
    \ntemplate<long long b>\nlong long discrete_log(long long x, long long y, long\
    \ long m){\n  assert(b*b >= m);\n\n  if(y == 1 or m == 1)\n    return 0;\n  \n\
    \  if(x == 0){\n    if(y == 1) return 0;\n    if(y == 0) return 1;\n    return\
    \ -1;\n  }\n\n  int d = 1;\n  while((1<<d) < m) ++d;\n\n  long long xd = 1;\n\
    \  for(int i = 0; i < d; ++i){\n    if(xd == y) return i;\n    xd *= x;\n    xd\
    \ %= m;\n  }\n\n  long long xd_inv,z;\n  long long g = std::gcd(xd,m);\n  xd /=\
    \ g, m /= g;\n  extgcd(xd,m,xd_inv,z);\n  assert(xd*xd_inv+m*z == 1);\n  if(xd_inv\
    \ < 0) xd_inv %= m, xd_inv += m;\n  if(y%g) return -1;\n  y /= g;\n  y *= xd_inv;\n\
    \  y %= m;\n\n  long long t = discrete_log_coprime<b>(x,y,m);\n  \n  return (t\
    \ < 0 ? t : t+d);\n}\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <vector>\n#include <utility>\n\
    #include <map>\n#include <numeric>\n\n// ax + by = gcd(a,b)\nlong long extgcd(long\
    \ long a, long long b, long long &x, long long &y){\n  long long d = a;\n  if(b){\n\
    \    d = extgcd(b, a%b, y, x);\n    y -= (a / b)*x;\n  }else{\n    x = 1;\n  \
    \  y = 0;\n  }\n  assert(a*x + b*y == d);\n  return d;    \n}\n\ntemplate<typename\
    \ T, typename F>\nT power(T x, long long k, F f, T ti){\n  T ret = ti;\n  while(k\
    \ > 0){\n    if(k&1) ret = f(ret,x);\n    x = f(x,x);\n    k /= 2;\n  }\n  return\
    \ ret;\n}\n\n/*\n  x^k == y (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E k \u3092\
    \u8FD4\u3059\n  0 <= k < m\n  \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\u306F\
    \ -1 \u3092\u8FD4\u3059\n  O(b*log(b))\n  b*b >= m \u3068\u306A\u308B\u3088\u3046\
    \u306A b \u3092\u9078\u3076\u5FC5\u8981\u304C\u3042\u308B\n*/\ntemplate<long long\
    \ b>\nlong long discrete_log_coprime(long long x, long long y, long long m){\n\
    \n  if(y == 1 or m == 1)\n    return 0;\n  \n  if(x == 0){\n    if(y == 1) return\
    \ 0;\n    if(y == 0) return 1;\n    return -1;\n  }\n\n  std::map<long long,int>\
    \ bs;\n  long long xb = 1;\n  for(int i = 0; i < b; ++i){\n    if(xb == y) return\
    \ i;\n    if(!bs.count(xb))\n      bs[xb] = i;\n    xb *= x;\n    xb %= m;\n \
    \ }\n    \n  long long x_inv,z;\n  long long g_ = extgcd(x,m,x_inv,z);\n  assert(g_\
    \ == 1);\n  if(x_inv < 0) x_inv %= m, x_inv += m;\n  assert((x*x_inv)%m == 1);\n\
    \  long long x_inv_b = power<long long>(x_inv,b,[&](long long p, long long q){return\
    \ (p*q)%m;},1LL);\n\n  for(int i = 0; i <= b; ++i){\n    if(bs.count(y))\n   \
    \   return bs[y]+i*b;\n    y *= x_inv_b;\n    y %= m;\n  }\n\n  return -1;\n}\n\
    \ntemplate<long long b>\nlong long discrete_log(long long x, long long y, long\
    \ long m){\n  assert(b*b >= m);\n\n  if(y == 1 or m == 1)\n    return 0;\n  \n\
    \  if(x == 0){\n    if(y == 1) return 0;\n    if(y == 0) return 1;\n    return\
    \ -1;\n  }\n\n  int d = 1;\n  while((1<<d) < m) ++d;\n\n  long long xd = 1;\n\
    \  for(int i = 0; i < d; ++i){\n    if(xd == y) return i;\n    xd *= x;\n    xd\
    \ %= m;\n  }\n\n  long long xd_inv,z;\n  long long g = std::gcd(xd,m);\n  xd /=\
    \ g, m /= g;\n  extgcd(xd,m,xd_inv,z);\n  assert(xd*xd_inv+m*z == 1);\n  if(xd_inv\
    \ < 0) xd_inv %= m, xd_inv += m;\n  if(y%g) return -1;\n  y /= g;\n  y *= xd_inv;\n\
    \  y %= m;\n\n  long long t = discrete_log_coprime<b>(x,y,m);\n  \n  return (t\
    \ < 0 ? t : t+d);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/DiscreteLog.cpp
  requiredBy: []
  timestamp: '2022-07-16 00:49:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/DiscreteLogarithm.test.cpp
documentation_of: Math/DiscreteLog.cpp
layout: document
redirect_from:
- /library/Math/DiscreteLog.cpp
- /library/Math/DiscreteLog.cpp.html
title: Math/DiscreteLog.cpp
---
