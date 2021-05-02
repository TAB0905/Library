---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/matrix_det.test.cpp
    title: test/LibraryChecker/matrix_det.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/MatrixDeterminant.cpp\"\n#include <vector>\n\ntemplate<typename\
    \ T>\nT determinant(std::vector<std::vector<T>> mat){\n  int n = mat.size();\n\
    \  T ret = 1;\n  for(int i = 0; i < n; ++i){\n    if(mat[i][i] == T(0)){\n   \
    \   for(int j = i+1; j < n; ++j){\n        if(mat[j][i] != T(0)){\n          ret\
    \ *= -1;\n          swap(mat[j],mat[i]);\n          break;\n        }\n      }\n\
    \    }\n    if(mat[i][i] == T(0))\n      return 0;\n\n    ret *= mat[i][i];\n\
    \    const T tmp = mat[i][i];\n    for(int j = i; j < n; ++j)\n      mat[i][j]\
    \ /= tmp;\n\n    for(int j = i+1; j < n; ++j){\n      T x = mat[j][i];\n     \
    \ for(int k = i; k < n; ++k){\n        mat[j][k] -= mat[i][k]*x;\n      }\n  \
    \  }\n  }\n  return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T>\nT determinant(std::vector<std::vector<T>>\
    \ mat){\n  int n = mat.size();\n  T ret = 1;\n  for(int i = 0; i < n; ++i){\n\
    \    if(mat[i][i] == T(0)){\n      for(int j = i+1; j < n; ++j){\n        if(mat[j][i]\
    \ != T(0)){\n          ret *= -1;\n          swap(mat[j],mat[i]);\n          break;\n\
    \        }\n      }\n    }\n    if(mat[i][i] == T(0))\n      return 0;\n\n   \
    \ ret *= mat[i][i];\n    const T tmp = mat[i][i];\n    for(int j = i; j < n; ++j)\n\
    \      mat[i][j] /= tmp;\n\n    for(int j = i+1; j < n; ++j){\n      T x = mat[j][i];\n\
    \      for(int k = i; k < n; ++k){\n        mat[j][k] -= mat[i][k]*x;\n      }\n\
    \    }\n  }\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/MatrixDeterminant.cpp
  requiredBy: []
  timestamp: '2021-05-02 23:57:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/matrix_det.test.cpp
documentation_of: Math/MatrixDeterminant.cpp
layout: document
redirect_from:
- /library/Math/MatrixDeterminant.cpp
- /library/Math/MatrixDeterminant.cpp.html
title: Math/MatrixDeterminant.cpp
---
