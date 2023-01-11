---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/MatrixDeterminant.cpp
    title: Math/MatrixDeterminant.cpp
  - icon: ':heavy_check_mark:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/LibraryChecker/matrix_det.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 2 \"Math/MatrixDeterminant.cpp\"\n\ntemplate<typename T>\n\
    T determinant(std::vector<std::vector<T>> mat){\n  int n = mat.size();\n  T ret\
    \ = 1;\n  for(int i = 0; i < n; ++i){\n    if(mat[i][i] == T(0)){\n      for(int\
    \ j = i+1; j < n; ++j){\n        if(mat[j][i] != T(0)){\n          ret *= -1;\n\
    \          swap(mat[j],mat[i]);\n          break;\n        }\n      }\n    }\n\
    \    if(mat[i][i] == T(0))\n      return 0;\n\n    ret *= mat[i][i];\n    const\
    \ T tmp = mat[i][i];\n    for(int j = i; j < n; ++j)\n      mat[i][j] /= tmp;\n\
    \n    for(int j = i+1; j < n; ++j){\n      T x = mat[j][i];\n      for(int k =\
    \ i; k < n; ++k){\n        mat[j][k] -= mat[i][k]*x;\n      }\n    }\n  }\n  return\
    \ ret;\n}\n#line 2 \"Math/modint.cpp\"\n#include <cassert>\n\ntemplate<long long\
    \ mod>\nclass modint{\nprivate:\n  using T = long long;\n  T a;\npublic:\n  constexpr\
    \ modint(const long long x = 0) noexcept : a((x%mod+mod)%mod) {}\n  constexpr\
    \ T& value() noexcept { return a; }\n  constexpr const T& value() const noexcept\
    \ { return a; }\n  constexpr modint operator-() const noexcept {\n    return modint(0)\
    \ -= *this;\n  }\n  constexpr modint operator+(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) += rhs;\n  }\n  constexpr modint operator-(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr\
    \ modint operator*(const modint& rhs) const noexcept {\n    return modint(*this)\
    \ *= rhs;\n  }\n  constexpr modint operator/(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) /= rhs;\n  }\n  constexpr modint& operator+=(const\
    \ modint& rhs) noexcept {\n    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return\
    \ *this;\n  }\n  constexpr modint& operator-=(const modint& rhs) noexcept {\n\
    \    if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return *this;\n  }\n  constexpr\
    \ modint& operator*=(const modint& rhs) noexcept {\n    a = a*rhs.a%mod;\n   \
    \ return *this;\n  }\n  constexpr modint& operator/=(const modint& rhs) noexcept\
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
    \ is;\n  }\n};\n#line 8 \"test/LibraryChecker/matrix_det.test.cpp\"\n\nusing namespace\
    \ std;\n\nint main(){\n  using mint = modint<998244353>;\n  int n;\n  cin >> n;\n\
    \  vector<vector<mint>> A(n,vector<mint>(n));\n  for(int i = 0; i < n; ++i){\n\
    \    for(int j = 0; j < n; ++j){\n      cin >> A[i][j];\n    }\n  }\n  cout <<\
    \ determinant(A) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"Math/MatrixDeterminant.cpp\"\n#include\
    \ \"Math/modint.cpp\"\n\nusing namespace std;\n\nint main(){\n  using mint = modint<998244353>;\n\
    \  int n;\n  cin >> n;\n  vector<vector<mint>> A(n,vector<mint>(n));\n  for(int\
    \ i = 0; i < n; ++i){\n    for(int j = 0; j < n; ++j){\n      cin >> A[i][j];\n\
    \    }\n  }\n  cout << determinant(A) << endl;\n}\n"
  dependsOn:
  - Math/MatrixDeterminant.cpp
  - Math/modint.cpp
  isVerificationFile: true
  path: test/LibraryChecker/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2021-10-15 01:32:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/matrix_det.test.cpp
- /verify/test/LibraryChecker/matrix_det.test.cpp.html
title: test/LibraryChecker/matrix_det.test.cpp
---
