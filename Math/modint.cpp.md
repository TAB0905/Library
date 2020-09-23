---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/queue_operate_all_composite.test.cpp
    title: test/LibraryChecker/queue_operate_all_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Math/modint.cpp\"\n#include <iostream>\n\ntemplate<long\
    \ long mod>\nclass modint{\nprivate:\n  long long a;\npublic:\n  constexpr modint(const\
    \ long long x = 0) noexcept : a((x%mod+mod)%mod) {}\n  constexpr long long& value()\
    \ noexcept { return a; }\n  constexpr const long long& value() const noexcept\
    \ { return a; }\n  constexpr modint operator+(const modint rhs) const noexcept\
    \ {\n    return modint(*this) += rhs;\n  }\n  constexpr modint operator-(const\
    \ modint rhs) const noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr\
    \ modint operator*(const modint rhs) const noexcept {\n    return modint(*this)\
    \ *= rhs;\n  }\n  constexpr modint operator/(const modint rhs) const noexcept\
    \ {\n    return modint(*this) /= rhs;\n  }\n  constexpr modint& operator+=(const\
    \ modint rhs) noexcept {\n    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return\
    \ *this;\n  }\n  constexpr modint &operator-=(const modint rhs) noexcept {\n \
    \   if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return *this;\n  }\n  constexpr\
    \ modint& operator*=(const modint rhs) noexcept {\n    a = a*rhs.a%mod;\n    return\
    \ *this;\n  }\n  constexpr modint& operator/=(modint rhs) noexcept {\n    long\
    \ long k = mod-2;\n    while(k > 0){\n      if(k&1){\n        *this *= rhs;\n\
    \      }\n      rhs *= rhs;\n      k /= 2;\n    }\n    return *this;\n  }\n  friend\
    \ std::ostream& operator<<(std::ostream &os, const modint &X){\n    return os\
    \ << X.a;\n  }\n  friend std::istream& operator>>(std::istream &is, modint &X){\n\
    \    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n    return is;\n\
    \  }\n};\n"
  code: "#include <iostream>\n\ntemplate<long long mod>\nclass modint{\nprivate:\n\
    \  long long a;\npublic:\n  constexpr modint(const long long x = 0) noexcept :\
    \ a((x%mod+mod)%mod) {}\n  constexpr long long& value() noexcept { return a; }\n\
    \  constexpr const long long& value() const noexcept { return a; }\n  constexpr\
    \ modint operator+(const modint rhs) const noexcept {\n    return modint(*this)\
    \ += rhs;\n  }\n  constexpr modint operator-(const modint rhs) const noexcept\
    \ {\n    return modint(*this) -= rhs;\n  }\n  constexpr modint operator*(const\
    \ modint rhs) const noexcept {\n    return modint(*this) *= rhs;\n  }\n  constexpr\
    \ modint operator/(const modint rhs) const noexcept {\n    return modint(*this)\
    \ /= rhs;\n  }\n  constexpr modint& operator+=(const modint rhs) noexcept {\n\
    \    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return *this;\n  }\n  constexpr\
    \ modint &operator-=(const modint rhs) noexcept {\n    if(a < rhs.a) a += mod;\n\
    \    a -= rhs.a;\n    return *this;\n  }\n  constexpr modint& operator*=(const\
    \ modint rhs) noexcept {\n    a = a*rhs.a%mod;\n    return *this;\n  }\n  constexpr\
    \ modint& operator/=(modint rhs) noexcept {\n    long long k = mod-2;\n    while(k\
    \ > 0){\n      if(k&1){\n        *this *= rhs;\n      }\n      rhs *= rhs;\n \
    \     k /= 2;\n    }\n    return *this;\n  }\n  friend std::ostream& operator<<(std::ostream\
    \ &os, const modint &X){\n    return os << X.a;\n  }\n  friend std::istream& operator>>(std::istream\
    \ &is, modint &X){\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n\
    \    return is;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.cpp
  requiredBy: []
  timestamp: '2020-07-05 20:33:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/queue_operate_all_composite.test.cpp
documentation_of: Math/modint.cpp
layout: document
redirect_from:
- /library/Math/modint.cpp
- /library/Math/modint.cpp.html
title: Math/modint.cpp
---
