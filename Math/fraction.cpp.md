---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/fraction.cpp\"\n#include <numeric> \n#include <iostream>\n\
    \ntemplate<typename T>\nstruct Fraction{\nprivate:\n  T p, q;// p/q\n  \n  void\
    \ reduce(){\n    T g = std::gcd(p,q);\n    p /= g;\n    q /= g;\n    if(q < 0)\
    \ p *= -1, q *= -1;\n  }\npublic:\n  Fraction(T p, T q) : p(p), q(q) {\n    reduce();\n\
    \  }\n  Fraction(T x) : p(x), q(1) {}\n\n  constexpr Fraction inv(){\n    return\
    \ Fraction(q,p);\n  }\n  constexpr Fraction operator+(const Fraction &rhs) const\
    \ noexcept{\n    return Fraction(*this) += rhs;\n  }\n  constexpr Fraction operator-(const\
    \ Fraction &rhs) const noexcept{\n    return Fraction(*this) -= rhs;\n  }\n  constexpr\
    \ Fraction operator*(const Fraction &rhs) const noexcept{\n    return Fraction(*this)\
    \ *= rhs;\n  }\n  constexpr Fraction operator/(const Fraction &rhs) const noexcept{\n\
    \    return Fraction(*this) /= rhs;\n  }\n  constexpr Fraction& operator*=(const\
    \ T &rhs) noexcept{\n    p *= rhs;\n    reduce();\n    return *this;\n  }\n  constexpr\
    \ Fraction& operator/=(const T &rhs) noexcept{\n    p /= rhs;\n    reduce();\n\
    \    return *this;\n  }\n  constexpr Fraction& operator+=(const Fraction &rhs)\
    \ noexcept{\n    p = p*rhs.q + rhs.p*q;\n    q *= rhs.q;\n    reduce();\n    return\
    \ *this;\n  }\n  constexpr Fraction& operator-=(const Fraction &rhs) noexcept{\n\
    \    p = p*rhs.q - rhs.p*q;\n    q *= rhs.q;\n    reduce();\n    return *this;\n\
    \  }\n  constexpr Fraction& operator*=(const Fraction &rhs) noexcept{\n    q *=\
    \ rhs.q;\n    p *= rhs.p;\n    reduce();\n    return *this;\n  }\n  constexpr\
    \ Fraction& operator/=(const Fraction &rhs) noexcept{\n    q *= rhs.p;\n    p\
    \ *= rhs.q;\n    reduce();\n    return *this;\n  }\n  constexpr bool operator==(const\
    \ Fraction &rhs) const noexcept {\n    return p*rhs.q == q*rhs.p;\n  }\n  constexpr\
    \ bool operator<(const Fraction &rhs) const noexcept {\n    assert(rhs.p != 0\
    \ or rhs.q != 0);\n    return p*rhs.q < q*rhs.p;\n  }\n  constexpr bool operator>(const\
    \ Fraction &rhs) const noexcept {\n    assert(rhs.p != 0 or rhs.q != 0);\n   \
    \ return rhs < *this;\n  }\n  friend std::ostream& operator<<(std::ostream& os,\
    \ const Fraction f){\n    os << \"(\" << f.p << \"/\" << f.q << \")\";\n    return\
    \ os;\n  }\n};\n"
  code: "#include <numeric> \n#include <iostream>\n\ntemplate<typename T>\nstruct\
    \ Fraction{\nprivate:\n  T p, q;// p/q\n  \n  void reduce(){\n    T g = std::gcd(p,q);\n\
    \    p /= g;\n    q /= g;\n    if(q < 0) p *= -1, q *= -1;\n  }\npublic:\n  Fraction(T\
    \ p, T q) : p(p), q(q) {\n    reduce();\n  }\n  Fraction(T x) : p(x), q(1) {}\n\
    \n  constexpr Fraction inv(){\n    return Fraction(q,p);\n  }\n  constexpr Fraction\
    \ operator+(const Fraction &rhs) const noexcept{\n    return Fraction(*this) +=\
    \ rhs;\n  }\n  constexpr Fraction operator-(const Fraction &rhs) const noexcept{\n\
    \    return Fraction(*this) -= rhs;\n  }\n  constexpr Fraction operator*(const\
    \ Fraction &rhs) const noexcept{\n    return Fraction(*this) *= rhs;\n  }\n  constexpr\
    \ Fraction operator/(const Fraction &rhs) const noexcept{\n    return Fraction(*this)\
    \ /= rhs;\n  }\n  constexpr Fraction& operator*=(const T &rhs) noexcept{\n   \
    \ p *= rhs;\n    reduce();\n    return *this;\n  }\n  constexpr Fraction& operator/=(const\
    \ T &rhs) noexcept{\n    p /= rhs;\n    reduce();\n    return *this;\n  }\n  constexpr\
    \ Fraction& operator+=(const Fraction &rhs) noexcept{\n    p = p*rhs.q + rhs.p*q;\n\
    \    q *= rhs.q;\n    reduce();\n    return *this;\n  }\n  constexpr Fraction&\
    \ operator-=(const Fraction &rhs) noexcept{\n    p = p*rhs.q - rhs.p*q;\n    q\
    \ *= rhs.q;\n    reduce();\n    return *this;\n  }\n  constexpr Fraction& operator*=(const\
    \ Fraction &rhs) noexcept{\n    q *= rhs.q;\n    p *= rhs.p;\n    reduce();\n\
    \    return *this;\n  }\n  constexpr Fraction& operator/=(const Fraction &rhs)\
    \ noexcept{\n    q *= rhs.p;\n    p *= rhs.q;\n    reduce();\n    return *this;\n\
    \  }\n  constexpr bool operator==(const Fraction &rhs) const noexcept {\n    return\
    \ p*rhs.q == q*rhs.p;\n  }\n  constexpr bool operator<(const Fraction &rhs) const\
    \ noexcept {\n    assert(rhs.p != 0 or rhs.q != 0);\n    return p*rhs.q < q*rhs.p;\n\
    \  }\n  constexpr bool operator>(const Fraction &rhs) const noexcept {\n    assert(rhs.p\
    \ != 0 or rhs.q != 0);\n    return rhs < *this;\n  }\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const Fraction f){\n    os << \"(\" << f.p << \"/\" << f.q << \")\";\n \
    \   return os;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/fraction.cpp
  requiredBy: []
  timestamp: '2020-12-30 23:12:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/fraction.cpp
layout: document
redirect_from:
- /library/Math/fraction.cpp
- /library/Math/fraction.cpp.html
title: Math/fraction.cpp
---
