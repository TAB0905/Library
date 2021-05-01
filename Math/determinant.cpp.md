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
  bundledCode: "#line 1 \"Math/determinant.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\n#line 6 \"Math/determinant.cpp\"\n#include <cassert>\n\
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
    \ a -= mod;\n    return *this;\n  }\n  constexpr modint &operator-=(const modint&\
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
    \ is;\n  }\n};\n\ntemplate<typename T>\nT determinant(vector<vector<T>> mat){\n\
    \  int n = mat.size();\n  T ret = 1;\n  for(int i = 0; i < n; ++i){\n    if(mat[i][i]\
    \ == T(0)){\n      for(int j = i+1; j < n; ++j){\n        if(mat[j][i] != T(0)){\n\
    \          ret *= -1;\n          swap(mat[j],mat[i]);\n          break;\n    \
    \    }\n      }\n    }\n    if(mat[i][i] == T(0))\n      return 0;\n\n    ret\
    \ *= mat[i][i];\n    const T tmp = mat[i][i];\n    for(int j = i; j < n; ++j)\n\
    \      mat[i][j] /= tmp;\n\n    for(int j = i+1; j < n; ++j){\n      T x = mat[j][i];\n\
    \      for(int k = i; k < n; ++k){\n        mat[j][k] -= mat[i][k]*x;\n      }\n\
    \    }\n  }\n  return ret;\n}\n\nint main(){\n  using mint = modint<998244353>;\n\
    \  int n;\n  cin >> n;\n  vector<vector<mint>> A(n,vector<mint>(n));\n  for(int\
    \ i = 0; i < n; ++i){\n    for(int j = 0; j < n; ++j){\n      cin >> A[i][j];\n\
    \    }\n  }\n  cout << determinant(A) << endl;\n}\n"
  code: "#include <iostream>\n#include <vector>\nusing namespace std;\n\n#include\
    \ <iostream>\n#include <cassert>\n\ntemplate<long long mod>\nclass modint{\nprivate:\n\
    \  using T = long long;\n  T a;\npublic:\n  constexpr modint(const long long x\
    \ = 0) noexcept : a((x%mod+mod)%mod) {}\n  constexpr T& value() noexcept { return\
    \ a; }\n  constexpr const T& value() const noexcept { return a; }\n  constexpr\
    \ modint operator-() const noexcept {\n    return modint(0) -= *this;\n  }\n \
    \ constexpr modint operator+(const modint& rhs) const noexcept {\n    return modint(*this)\
    \ += rhs;\n  }\n  constexpr modint operator-(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) -= rhs;\n  }\n  constexpr modint operator*(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) *= rhs;\n  }\n  constexpr\
    \ modint operator/(const modint& rhs) const noexcept {\n    return modint(*this)\
    \ /= rhs;\n  }\n  constexpr modint& operator+=(const modint& rhs) noexcept {\n\
    \    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return *this;\n  }\n  constexpr\
    \ modint &operator-=(const modint& rhs) noexcept {\n    if(a < rhs.a) a += mod;\n\
    \    a -= rhs.a;\n    return *this;\n  }\n  constexpr modint& operator*=(const\
    \ modint& rhs) noexcept {\n    a = a*rhs.a%mod;\n    return *this;\n  }\n  constexpr\
    \ modint& operator/=(const modint& rhs) noexcept {\n    return *this *= rhs.inv();\n\
    \  }\n  constexpr bool operator==(const modint& rhs) const noexcept {\n    return\
    \ a == rhs.a;\n  }\n  constexpr bool operator!=(const modint& rhs) const noexcept\
    \ {\n    return not (*this == rhs);\n  }\n  constexpr modint pow(long long k)\
    \ const noexcept {\n    modint ret(1);\n    modint x = k > 0 ? *this : this->inv();\n\
    \    k = abs(k);\n    while(k > 0){\n      if(k&1) ret *= x;\n      x *= x;\n\
    \      k >>= 1;\n    }\n    return ret;\n  }\n  constexpr modint inv() const noexcept\
    \ {\n    return pow(mod-2);\n  }\n  friend std::ostream& operator<<(std::ostream\
    \ &os, const modint &X) noexcept {\n    return os << X.a;\n  }\n  friend std::istream&\
    \ operator>>(std::istream &is, modint &X) noexcept {\n    is >> X.a;\n    X.a\
    \ %= mod;\n    if(X.a < 0) X.a += mod;\n    return is;\n  }\n};\n\ntemplate<typename\
    \ T>\nT determinant(vector<vector<T>> mat){\n  int n = mat.size();\n  T ret =\
    \ 1;\n  for(int i = 0; i < n; ++i){\n    if(mat[i][i] == T(0)){\n      for(int\
    \ j = i+1; j < n; ++j){\n        if(mat[j][i] != T(0)){\n          ret *= -1;\n\
    \          swap(mat[j],mat[i]);\n          break;\n        }\n      }\n    }\n\
    \    if(mat[i][i] == T(0))\n      return 0;\n\n    ret *= mat[i][i];\n    const\
    \ T tmp = mat[i][i];\n    for(int j = i; j < n; ++j)\n      mat[i][j] /= tmp;\n\
    \n    for(int j = i+1; j < n; ++j){\n      T x = mat[j][i];\n      for(int k =\
    \ i; k < n; ++k){\n        mat[j][k] -= mat[i][k]*x;\n      }\n    }\n  }\n  return\
    \ ret;\n}\n\nint main(){\n  using mint = modint<998244353>;\n  int n;\n  cin >>\
    \ n;\n  vector<vector<mint>> A(n,vector<mint>(n));\n  for(int i = 0; i < n; ++i){\n\
    \    for(int j = 0; j < n; ++j){\n      cin >> A[i][j];\n    }\n  }\n  cout <<\
    \ determinant(A) << endl;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/determinant.cpp
  requiredBy: []
  timestamp: '2021-05-01 20:44:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/determinant.cpp
layout: document
redirect_from:
- /library/Math/determinant.cpp
- /library/Math/determinant.cpp.html
title: Math/determinant.cpp
---
