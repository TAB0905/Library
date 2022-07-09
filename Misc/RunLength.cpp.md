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
  bundledCode: "#line 1 \"Misc/RunLength.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <string>\n\ntemplate<typename T>\nstd::vector<std::pair<T,int>> run_length(const\
    \ std::vector<T>& A){\n  std::vector<std::pair<T,int>> ret;\n  for(auto e : A){\n\
    \    if(ret.empty() or ret.back().first != e)\n      ret.emplace_back(e,1);\n\
    \    else\n      ++ret.back().second;\n  }\n  return ret;\n}\n\nstd::vector<std::pair<char,int>>\
    \ run_length(const std::string& A){\n  std::vector<std::pair<char,int>> ret;\n\
    \  for(auto e : A){\n    if(ret.empty() or ret.back().first != e)\n      ret.emplace_back(e,1);\n\
    \    else\n      ++ret.back().second;\n  }\n  return ret;\n}\n\n"
  code: "#include <vector>\n#include <utility>\n#include <string>\n\ntemplate<typename\
    \ T>\nstd::vector<std::pair<T,int>> run_length(const std::vector<T>& A){\n  std::vector<std::pair<T,int>>\
    \ ret;\n  for(auto e : A){\n    if(ret.empty() or ret.back().first != e)\n   \
    \   ret.emplace_back(e,1);\n    else\n      ++ret.back().second;\n  }\n  return\
    \ ret;\n}\n\nstd::vector<std::pair<char,int>> run_length(const std::string& A){\n\
    \  std::vector<std::pair<char,int>> ret;\n  for(auto e : A){\n    if(ret.empty()\
    \ or ret.back().first != e)\n      ret.emplace_back(e,1);\n    else\n      ++ret.back().second;\n\
    \  }\n  return ret;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Misc/RunLength.cpp
  requiredBy: []
  timestamp: '2022-07-09 23:32:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Misc/RunLength.cpp
layout: document
redirect_from:
- /library/Misc/RunLength.cpp
- /library/Misc/RunLength.cpp.html
title: Misc/RunLength.cpp
---
