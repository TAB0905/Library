---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/matrix_det.test.cpp
    title: test/LibraryChecker/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/matrix_product.test.cpp
    title: test/LibraryChecker/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/point_set_range_composite.test.cpp
    title: test/LibraryChecker/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/queue_operate_all_composite.test.cpp
    title: test/LibraryChecker/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/range_affine_range_sum.test.cpp
    title: test/LibraryChecker/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/modint.cpp\"\n#include <iostream>\n#include <cassert>\n\
    \ntemplate<long long mod>\nclass modint{\nprivate:\n  using T = long long;\n \
    \ T a;\npublic:\n  constexpr modint(const long long x = 0) noexcept : a((x%mod+mod)%mod)\
    \ {}\n  constexpr T& value() noexcept { return a; }\n  constexpr const T& value()\
    \ const noexcept { return a; }\n  constexpr modint operator-() const noexcept\
    \ {\n    return modint(0) -= *this;\n  }\n  constexpr modint operator+(const modint&\
    \ rhs) const noexcept {\n    return modint(*this) += rhs;\n  }\n  constexpr modint\
    \ operator-(const modint& rhs) const noexcept {\n    return modint(*this) -= rhs;\n\
    \  }\n  constexpr modint operator*(const modint& rhs) const noexcept {\n    return\
    \ modint(*this) *= rhs;\n  }\n  constexpr modint operator/(const modint& rhs)\
    \ const noexcept {\n    return modint(*this) /= rhs;\n  }\n  constexpr modint&\
    \ operator+=(const modint& rhs) noexcept {\n    a += rhs.a;\n    if(a >= mod)\
    \ a -= mod;\n    return *this;\n  }\n  constexpr modint& operator-=(const modint&\
    \ rhs) noexcept {\n    if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return *this;\n\
    \  }\n  constexpr modint& operator*=(const modint& rhs) noexcept {\n    a = a*rhs.a%mod;\n\
    \    return *this;\n  }\n  constexpr modint& operator/=(const modint& rhs) noexcept\
    \ {\n    return *this *= rhs.inv();\n  }\n  constexpr bool operator==(const modint&\
    \ rhs) const noexcept {\n    return a == rhs.a;\n  }\n  constexpr bool operator!=(const\
    \ modint& rhs) const noexcept {\n    return not (*this == rhs);\n  }\n  constexpr\
    \ modint pow(long long k) const noexcept {\n    modint ret(1);\n    modint x =\
    \ k > 0 ? *this : this->inv();\n    k = abs(k);\n    while(k > 0){\n      if(k&1)\
    \ ret *= x;\n      x *= x;\n      k >>= 1;\n    }\n    return ret;\n  }\n  constexpr\
    \ modint inv() const noexcept {\n    return pow(mod-2);\n  }\n  friend std::ostream&\
    \ operator<<(std::ostream &os, const modint &X) noexcept {\n    return os << X.a;\n\
    \  }\n  friend std::istream& operator>>(std::istream &is, modint &X) noexcept\
    \ {\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n    return\
    \ is;\n  }\n};\n"
  code: "#include <iostream>\n#include <cassert>\n\ntemplate<long long mod>\nclass\
    \ modint{\nprivate:\n  using T = long long;\n  T a;\npublic:\n  constexpr modint(const\
    \ long long x = 0) noexcept : a((x%mod+mod)%mod) {}\n  constexpr T& value() noexcept\
    \ { return a; }\n  constexpr const T& value() const noexcept { return a; }\n \
    \ constexpr modint operator-() const noexcept {\n    return modint(0) -= *this;\n\
    \  }\n  constexpr modint operator+(const modint& rhs) const noexcept {\n    return\
    \ modint(*this) += rhs;\n  }\n  constexpr modint operator-(const modint& rhs)\
    \ const noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr modint\
    \ operator*(const modint& rhs) const noexcept {\n    return modint(*this) *= rhs;\n\
    \  }\n  constexpr modint operator/(const modint& rhs) const noexcept {\n    return\
    \ modint(*this) /= rhs;\n  }\n  constexpr modint& operator+=(const modint& rhs)\
    \ noexcept {\n    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return *this;\n\
    \  }\n  constexpr modint& operator-=(const modint& rhs) noexcept {\n    if(a <\
    \ rhs.a) a += mod;\n    a -= rhs.a;\n    return *this;\n  }\n  constexpr modint&\
    \ operator*=(const modint& rhs) noexcept {\n    a = a*rhs.a%mod;\n    return *this;\n\
    \  }\n  constexpr modint& operator/=(const modint& rhs) noexcept {\n    return\
    \ *this *= rhs.inv();\n  }\n  constexpr bool operator==(const modint& rhs) const\
    \ noexcept {\n    return a == rhs.a;\n  }\n  constexpr bool operator!=(const modint&\
    \ rhs) const noexcept {\n    return not (*this == rhs);\n  }\n  constexpr modint\
    \ pow(long long k) const noexcept {\n    modint ret(1);\n    modint x = k > 0\
    \ ? *this : this->inv();\n    k = abs(k);\n    while(k > 0){\n      if(k&1) ret\
    \ *= x;\n      x *= x;\n      k >>= 1;\n    }\n    return ret;\n  }\n  constexpr\
    \ modint inv() const noexcept {\n    return pow(mod-2);\n  }\n  friend std::ostream&\
    \ operator<<(std::ostream &os, const modint &X) noexcept {\n    return os << X.a;\n\
    \  }\n  friend std::istream& operator>>(std::istream &is, modint &X) noexcept\
    \ {\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n    return\
    \ is;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.cpp
  requiredBy: []
  timestamp: '2021-10-15 01:32:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/range_affine_range_sum.test.cpp
  - test/LibraryChecker/point_set_range_composite.test.cpp
  - test/LibraryChecker/matrix_product.test.cpp
  - test/LibraryChecker/queue_operate_all_composite.test.cpp
  - test/LibraryChecker/matrix_det.test.cpp
documentation_of: Math/modint.cpp
layout: document
redirect_from:
- /library/Math/modint.cpp
- /library/Math/modint.cpp.html
title: Math/modint.cpp
---
