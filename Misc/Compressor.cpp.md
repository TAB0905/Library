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
  bundledCode: "#line 1 \"Misc/Compressor.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate<typename T>\nclass Complessor {\n  std::vector<T> m_val;\npublic:\n\
    \  Complessor(const std::vector<T> dat) : m_val(dat) {\n    std::sort(m_val.begin(),m_val.end());\n\
    \    m_val.erase(std::unique(m_val.begin(),m_val.end()),m_val.end());\n  }\n \
    \ int idx(T x){\n    return std::lower_bound(m_val.begin(),m_val.end(), x) - m_val.begin();\n\
    \  }\n  int val(int i){\n    return m_val[i];\n  }\n};\n"
  code: "#include <algorithm>\n#include <vector>\n\ntemplate<typename T>\nclass Complessor\
    \ {\n  std::vector<T> m_val;\npublic:\n  Complessor(const std::vector<T> dat)\
    \ : m_val(dat) {\n    std::sort(m_val.begin(),m_val.end());\n    m_val.erase(std::unique(m_val.begin(),m_val.end()),m_val.end());\n\
    \  }\n  int idx(T x){\n    return std::lower_bound(m_val.begin(),m_val.end(),\
    \ x) - m_val.begin();\n  }\n  int val(int i){\n    return m_val[i];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/Compressor.cpp
  requiredBy: []
  timestamp: '2022-05-12 15:18:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/Compressor.cpp
layout: document
redirect_from:
- /library/Misc/Compressor.cpp
- /library/Misc/Compressor.cpp.html
title: Misc/Compressor.cpp
---
