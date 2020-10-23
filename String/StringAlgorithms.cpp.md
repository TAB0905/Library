---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/StringAlgorithms.cpp\"\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\n\nvector<int> MP(string S){\n  int l = S.length();\n\
    \  vector<int> A(l+1);\n  A[0] = -1;\n  int j = -1;\n  for(int i = 0; i < l; ++i){\n\
    \    while(j >= 0 && S[i] != S[j]) j = A[j];\n    ++j;\n    A[i+1] = j;\n  }\n\
    \  return A;\n}\n\nvector<int> KMP(string S){\n  int l = S.length();\n  vector<int>\
    \ A(l+1);\n  A[0] = -1;\n  int j = -1;\n  for(int i = 0; i < l; ++i){\n    while(j\
    \ >= 0 && S[i] != S[j]) j = A[j];\n    ++j;\n    if(i < l && S[i+1] == S[j]) A[i+1]\
    \ = A[j];\n    else A[i+1] = j;\n  }\n  return A;\n}\n\nvector<int> Manacher(string\
    \ S){\n  int c = 0, n = S.length();\n  vector<int> R(n,1);\n  for(int i = 0; i\
    \ < n; ++i){\n    int l = c - (i - c);\n    if(i + R[l] < c + R[c]){\n      R[i]\
    \ = R[l];\n    }else{\n      int j = c + R[c] - i;\n      while(i - j >= 0 and\
    \ i + j < n and S[i-j] == S[i+j]) ++j;\n      R[i] = j;\n      c = i;\n    }\n\
    \  }\n  return R;\n}\n\nvector<int> Z_algorithm(string S){\n  int c = 0, n = S.length();\n\
    \  vector<int> Z(n,0);\n  for(int i = 1; i < n; ++i){\n    int l = i - c;\n  \
    \  if(i + Z[l] < c + Z[c]){\n      Z[i] = Z[l];\n    }else{\n      int j = max(0,\
    \ c + Z[c] - i);\n      while(i + j < n && S[j] == S[i+j]) ++j;\n      Z[i] =\
    \ j;\n      c = i;\n    }\n  }\n  Z[0] = n;\n  return Z;\n}\n\nint main(){\n \
    \ string S;\n  cin >> S;\n  vector<int> mp = MP(S), kmp = KMP(S), manacher = Manacher(S),\
    \ Z = Z_algorithm(S);\n  cout << \"MP\" << endl;\n  for(auto &x : mp) cout <<\
    \ x << \" \";cout << endl;\n  cout << \"KMP\" << endl;\n  for(auto &x : kmp) cout\
    \ << x << \" \";cout << endl;\n  cout << \"Manacher\" << endl;\n  for(auto &x\
    \ : manacher) cout << x << \" \";cout << endl;\n  cout << \"Z-algorithm\" << endl;\n\
    \  for(auto &x : Z) cout << x << \" \";cout << endl;\n  return 0;\n}\n"
  code: "#include <iostream>\n#include <vector>\nusing namespace std;\n\nvector<int>\
    \ MP(string S){\n  int l = S.length();\n  vector<int> A(l+1);\n  A[0] = -1;\n\
    \  int j = -1;\n  for(int i = 0; i < l; ++i){\n    while(j >= 0 && S[i] != S[j])\
    \ j = A[j];\n    ++j;\n    A[i+1] = j;\n  }\n  return A;\n}\n\nvector<int> KMP(string\
    \ S){\n  int l = S.length();\n  vector<int> A(l+1);\n  A[0] = -1;\n  int j = -1;\n\
    \  for(int i = 0; i < l; ++i){\n    while(j >= 0 && S[i] != S[j]) j = A[j];\n\
    \    ++j;\n    if(i < l && S[i+1] == S[j]) A[i+1] = A[j];\n    else A[i+1] = j;\n\
    \  }\n  return A;\n}\n\nvector<int> Manacher(string S){\n  int c = 0, n = S.length();\n\
    \  vector<int> R(n,1);\n  for(int i = 0; i < n; ++i){\n    int l = c - (i - c);\n\
    \    if(i + R[l] < c + R[c]){\n      R[i] = R[l];\n    }else{\n      int j = c\
    \ + R[c] - i;\n      while(i - j >= 0 and i + j < n and S[i-j] == S[i+j]) ++j;\n\
    \      R[i] = j;\n      c = i;\n    }\n  }\n  return R;\n}\n\nvector<int> Z_algorithm(string\
    \ S){\n  int c = 0, n = S.length();\n  vector<int> Z(n,0);\n  for(int i = 1; i\
    \ < n; ++i){\n    int l = i - c;\n    if(i + Z[l] < c + Z[c]){\n      Z[i] = Z[l];\n\
    \    }else{\n      int j = max(0, c + Z[c] - i);\n      while(i + j < n && S[j]\
    \ == S[i+j]) ++j;\n      Z[i] = j;\n      c = i;\n    }\n  }\n  Z[0] = n;\n  return\
    \ Z;\n}\n\nint main(){\n  string S;\n  cin >> S;\n  vector<int> mp = MP(S), kmp\
    \ = KMP(S), manacher = Manacher(S), Z = Z_algorithm(S);\n  cout << \"MP\" << endl;\n\
    \  for(auto &x : mp) cout << x << \" \";cout << endl;\n  cout << \"KMP\" << endl;\n\
    \  for(auto &x : kmp) cout << x << \" \";cout << endl;\n  cout << \"Manacher\"\
    \ << endl;\n  for(auto &x : manacher) cout << x << \" \";cout << endl;\n  cout\
    \ << \"Z-algorithm\" << endl;\n  for(auto &x : Z) cout << x << \" \";cout << endl;\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/StringAlgorithms.cpp
  requiredBy: []
  timestamp: '2020-10-23 20:42:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/StringAlgorithms.cpp
layout: document
redirect_from:
- /library/String/StringAlgorithms.cpp
- /library/String/StringAlgorithms.cpp.html
title: String/StringAlgorithms.cpp
---
