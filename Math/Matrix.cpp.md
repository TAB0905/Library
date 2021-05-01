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
  bundledCode: "#line 1 \"Math/Matrix.cpp\"\n#include <vector>\n#include <cassert>\n\
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
    \ i = 0; i < n; ++i)\n      id[i][i] = ti;\n    return id;\n  }\n};\n\n"
  code: "#include <vector>\n#include <cassert>\n\ntemplate<typename T>\nclass Matrix{\n\
    private:\n  using arr = std::vector<T>;\n  using mat = std::vector<arr>;\n  size_t\
    \ r, c;\n  mat dat;\n\npublic:\n\n  Matrix() : r(0), c(0), dat(r,arr(c,T())) {}\n\
    \  Matrix(size_t r, size_t c) : r(r), c(c), dat(r,arr(c,T())) {}\n  Matrix(const\
    \ mat& dat) : r(dat.size()), c(dat[0].size()), dat(dat) {}\n  Matrix(const arr&\
    \ vec) : r(1), c(vec.size()), dat(1,vec) {}\n  \n  size_t size() const {return\
    \ dat.size();};\n  bool empty() const {return size()==0;};\n  arr& operator[](size_t\
    \ k){return dat.at(k);};\n  const arr& operator[](size_t k) const {return dat.at(k);};\n\
    \  \n  Matrix operator*(const Matrix &B) const noexcept {\n    return Matrix(*this)\
    \ *= B;\n  }\n\n  Matrix& operator*=(const Matrix &B) noexcept {\n    assert((not\
    \ dat.empty()) and\n           (not B.empty()) and\n           (dat[0].size()\
    \ == B.size()));\n\n    Matrix Bt = B.transposed();\n    Matrix prod(dat.size(),B[0].size());\n\
    \    for(size_t i = 0; i < dat.size(); ++i){\n      for(size_t j = 0; j < B[0].size();\
    \ ++j){\n        for(size_t k = 0; k < dat[0].size(); ++k){\n          prod[i][j]\
    \ += dat[i][k]*Bt[j][k];\n        }\n      }\n    }\n\n    *this = std::move(prod);\n\
    \    return *this;\n  };\n\n  Matrix transposed() const noexcept {\n    Matrix\
    \ ret(c,r);\n    for(size_t i = 0; i < c; ++i){\n      for(size_t j = 0; j < r;\
    \ ++j){\n        ret[i][j] = dat[j][i];\n      }\n    }\n    return ret;\n  }\n\
    \n  static Matrix identity(size_t n, T ti){\n    Matrix id(n,n);\n    for(size_t\
    \ i = 0; i < n; ++i)\n      id[i][i] = ti;\n    return id;\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Matrix.cpp
  requiredBy: []
  timestamp: '2021-05-01 20:44:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Matrix.cpp
layout: document
redirect_from:
- /library/Math/Matrix.cpp
- /library/Math/Matrix.cpp.html
title: Math/Matrix.cpp
---
