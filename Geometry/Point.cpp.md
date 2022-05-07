---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Geometry/Point.cpp\"\ntemplate<typename T>\nstruct Point\
    \ {\n  T x, y;\n  Point(T x, T y) : x(x), y(y) {}\n  Point operator+(Point rhs)\
    \ const {\n    return Point(*this) += rhs;\n  }\n  Point operator-(Point rhs)\
    \ const {\n    return Point(*this) -= rhs;\n  }\n  Point operator*(T c) const\
    \ {\n    return Point(*this) *= c;\n  }\n  Point operator/(T c) const {\n    return\
    \ Point(*this) /= c;\n  }\n  Point operator+=(Point rhs){\n    x += rhs.x;\n \
    \   y += rhs.y;\n    return *this;\n  }\n  Point operator-=(Point rhs){\n    x\
    \ -= rhs.x;\n    y -= rhs.y;\n    return *this;\n  }\n  Point operator*=(T c){\n\
    \    x *= c;\n    y *= c;\n    return *this;\n  }\n  Point operator/=(T c){\n\
    \    x /= c;\n    y /= c;\n    return *this;\n  }\n};\n\ntemplate<typename T>\n\
    T dot(Point<T> a, Point<T> b){\n  return a.x*b.x + a.y*b.y;\n}\n\ntemplate<typename\
    \ T>\nT cross(Point<T> a, Point<T> b){\n  return a.x*b.y - a.y*b.x;\n}\n\ntemplate<typename\
    \ T>\nT norm(Point<T> a){\n  return dot(a,a);\n}\n\ntemplate<typename P>\nint\
    \ ccw(P a, P b, P c){\n  b -= a; c -= a;\n  if(cross(b,c) > 0) return +1;\n  if(cross(b,c)\
    \ < 0) return -1;\n  if(dot(b,c) < 0) return +2;\n  if(norm(b) < norm(c)) return\
    \ -2;\n  return 0;\n}\n\n"
  code: "template<typename T>\nstruct Point {\n  T x, y;\n  Point(T x, T y) : x(x),\
    \ y(y) {}\n  Point operator+(Point rhs) const {\n    return Point(*this) += rhs;\n\
    \  }\n  Point operator-(Point rhs) const {\n    return Point(*this) -= rhs;\n\
    \  }\n  Point operator*(T c) const {\n    return Point(*this) *= c;\n  }\n  Point\
    \ operator/(T c) const {\n    return Point(*this) /= c;\n  }\n  Point operator+=(Point\
    \ rhs){\n    x += rhs.x;\n    y += rhs.y;\n    return *this;\n  }\n  Point operator-=(Point\
    \ rhs){\n    x -= rhs.x;\n    y -= rhs.y;\n    return *this;\n  }\n  Point operator*=(T\
    \ c){\n    x *= c;\n    y *= c;\n    return *this;\n  }\n  Point operator/=(T\
    \ c){\n    x /= c;\n    y /= c;\n    return *this;\n  }\n};\n\ntemplate<typename\
    \ T>\nT dot(Point<T> a, Point<T> b){\n  return a.x*b.x + a.y*b.y;\n}\n\ntemplate<typename\
    \ T>\nT cross(Point<T> a, Point<T> b){\n  return a.x*b.y - a.y*b.x;\n}\n\ntemplate<typename\
    \ T>\nT norm(Point<T> a){\n  return dot(a,a);\n}\n\ntemplate<typename P>\nint\
    \ ccw(P a, P b, P c){\n  b -= a; c -= a;\n  if(cross(b,c) > 0) return +1;\n  if(cross(b,c)\
    \ < 0) return -1;\n  if(dot(b,c) < 0) return +2;\n  if(norm(b) < norm(c)) return\
    \ -2;\n  return 0;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/Point.cpp
  requiredBy: []
  timestamp: '2022-05-07 14:28:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/Point.cpp
layout: document
redirect_from:
- /library/Geometry/Point.cpp
- /library/Geometry/Point.cpp.html
title: Geometry/Point.cpp
---
