---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Matrix.cpp
    title: Math/Matrix.cpp
  - icon: ':question:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/LibraryChecker/matrix_product.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include <iostream>\n\
    #include <iomanip>\n#line 1 \"Math/Matrix.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate<typename T>\nclass Matrix{\nprivate:\n  using arr = std::vector<T>;\n\
    \  using mat = std::vector<arr>;\n  size_t r, c;\n  mat dat;\n\npublic:\n\n  Matrix()\
    \ : r(0), c(0), dat(r,arr(c,T())) {}\n  Matrix(size_t r, size_t c) : r(r), c(c),\
    \ dat(r,arr(c,T())) {}\n  Matrix(const mat& dat) : r(dat.size()), c(dat[0].size()),\
    \ dat(dat) {}\n  Matrix(const arr& vec) : r(1), c(vec.size()), dat(1,vec) {}\n\
    \  \n  size_t size() const {return dat.size();};\n  bool empty() const {return\
    \ size()==0;};\n  arr& operator[](size_t k){return dat.at(k);};\n  const arr&\
    \ operator[](size_t k) const {return dat.at(k);};\n  \n  Matrix operator*(const\
    \ Matrix &B) const noexcept {\n    return Matrix(*this) *= B;\n  }\n\n  Matrix&\
    \ operator*=(const Matrix &B) noexcept {\n    assert((not dat.empty()) and\n \
    \          (not B.empty()) and\n           (dat[0].size() == B.size()));\n\n \
    \   Matrix Bt = B.transposed();\n    Matrix prod(dat.size(),B[0].size());\n  \
    \  for(size_t i = 0; i < dat.size(); ++i){\n      for(size_t j = 0; j < B[0].size();\
    \ ++j){\n        for(size_t k = 0; k < dat[0].size(); ++k){\n          prod[i][j]\
    \ += dat[i][k]*Bt[j][k];\n        }\n      }\n    }\n\n    *this = std::move(prod);\n\
    \    return *this;\n  };\n\n  Matrix transposed() const noexcept {\n    Matrix\
    \ ret(c,r);\n    for(size_t i = 0; i < c; ++i){\n      for(size_t j = 0; j < r;\
    \ ++j){\n        ret[i][j] = dat[j][i];\n      }\n    }\n    return ret;\n  }\n\
    \n  static Matrix identity(size_t n, T ti){\n    Matrix id(n,n);\n    for(size_t\
    \ i = 0; i < n; ++i)\n      id[i][i] = ti;\n    return id;\n  }\n};\n\n#line 3\
    \ \"Math/modint.cpp\"\n\ntemplate<long long mod>\nclass modint{\nprivate:\n  using\
    \ T = long long;\n  T a;\npublic:\n  constexpr modint(const long long x = 0) noexcept\
    \ : a((x%mod+mod)%mod) {}\n  constexpr T& value() noexcept { return a; }\n  constexpr\
    \ const T& value() const noexcept { return a; }\n  constexpr modint operator-()\
    \ const noexcept {\n    return modint(0) -= *this;\n  }\n  constexpr modint operator+(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) += rhs;\n  }\n  constexpr\
    \ modint operator-(const modint& rhs) const noexcept {\n    return modint(*this)\
    \ -= rhs;\n  }\n  constexpr modint operator*(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) *= rhs;\n  }\n  constexpr modint operator/(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) /= rhs;\n  }\n  constexpr\
    \ modint& operator+=(const modint& rhs) noexcept {\n    a += rhs.a;\n    if(a\
    \ >= mod) a -= mod;\n    return *this;\n  }\n  constexpr modint& operator-=(const\
    \ modint& rhs) noexcept {\n    if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return\
    \ *this;\n  }\n  constexpr modint& operator*=(const modint& rhs) noexcept {\n\
    \    a = a*rhs.a%mod;\n    return *this;\n  }\n  constexpr modint& operator/=(const\
    \ modint& rhs) noexcept {\n    return *this *= rhs.inv();\n  }\n  constexpr bool\
    \ operator==(const modint& rhs) const noexcept {\n    return a == rhs.a;\n  }\n\
    \  constexpr bool operator!=(const modint& rhs) const noexcept {\n    return not\
    \ (*this == rhs);\n  }\n  constexpr modint pow(long long k) const noexcept {\n\
    \    modint ret(1);\n    modint x = k > 0 ? *this : this->inv();\n    k = abs(k);\n\
    \    while(k > 0){\n      if(k&1) ret *= x;\n      x *= x;\n      k >>= 1;\n \
    \   }\n    return ret;\n  }\n  constexpr modint inv() const noexcept {\n    return\
    \ pow(mod-2);\n  }\n  friend std::ostream& operator<<(std::ostream &os, const\
    \ modint &X) noexcept {\n    return os << X.a;\n  }\n  friend std::istream& operator>>(std::istream\
    \ &is, modint &X) noexcept {\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0)\
    \ X.a += mod;\n    return is;\n  }\n};\n#line 7 \"test/LibraryChecker/matrix_product.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  using mint = modint<998244353>;\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  \n  int n, m, k;\n  cin >> n >> m >> k;\n \
    \ Matrix<mint> A(n,m), B(m,k);\n  for(int i = 0; i < n; ++i){\n    for(int j =\
    \ 0; j < m; ++j){\n      cin >> A[i][j];\n    }\n  }\n  for(int i = 0; i < m;\
    \ ++i){\n    for(int j = 0; j < k; ++j){\n      cin >> B[i][j];\n    }\n  }\n\
    \  auto C = A*B;\n  for(int i = 0; i < n; ++i){\n    for(int j = 0; j < k; ++j){\n\
    \      cout << C[i][j] << (j+1 < k ?  \" \" : \"\\n\");\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n#include \"Math/Matrix.cpp\"\n#include \"Math/modint.cpp\"\
    \nusing namespace std;\n\nint main(){\n  using mint = modint<998244353>;\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  \n  int n, m, k;\n  cin >> n >> m >> k;\n \
    \ Matrix<mint> A(n,m), B(m,k);\n  for(int i = 0; i < n; ++i){\n    for(int j =\
    \ 0; j < m; ++j){\n      cin >> A[i][j];\n    }\n  }\n  for(int i = 0; i < m;\
    \ ++i){\n    for(int j = 0; j < k; ++j){\n      cin >> B[i][j];\n    }\n  }\n\
    \  auto C = A*B;\n  for(int i = 0; i < n; ++i){\n    for(int j = 0; j < k; ++j){\n\
    \      cout << C[i][j] << (j+1 < k ?  \" \" : \"\\n\");\n    }\n  }\n}\n"
  dependsOn:
  - Math/Matrix.cpp
  - Math/modint.cpp
  isVerificationFile: true
  path: test/LibraryChecker/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2021-10-15 01:32:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/matrix_product.test.cpp
- /verify/test/LibraryChecker/matrix_product.test.cpp.html
title: test/LibraryChecker/matrix_product.test.cpp
---
