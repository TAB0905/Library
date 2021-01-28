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
  bundledCode: "#line 1 \"Math/PrimitiveRoot.cpp\"\n#include <iostream>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename T>\nT power(T x, long long\
    \ k, long long mod){\n  T ret{1};\n  x %= mod;\n  while(k > 0){\n    if(k&1) ret\
    \ *= x, ret %= mod;\n    x *= x, x %= mod;\n    k /= 2;\n  }\n  return ret;\n\
    }\n\nlong long primitive_root(long long prime){\n  vector<long long> fac;\n  long\
    \ long v = prime-1;\n  for(long long pp = 2; pp*pp <= v; ++pp){\n    long long\
    \ e = 0;\n    while(v%pp == 0){\n      ++e;\n      v /= pp;\n    }\n    if(e)\n\
    \      fac.emplace_back(pp);\n  }\n  if(v > 1)\n    fac.emplace_back(v);\n\n \
    \ for(long long g = 2; g < prime; ++g){\n    if(power(g,(prime-1),prime) != 1){\n\
    \      return -1;\n    }\n    bool ok = true;\n    for(long long pp : fac){\n\
    \      if(power(g,(prime-1)/pp,prime) == 1){\n        ok = false;\n        break;\n\
    \      }\n    }\n    if(ok)\n      return g;\n  }\n  return -1;\n}\n"
  code: "#include <iostream>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nT power(T x, long long k, long long mod){\n  T ret{1};\n  x %= mod;\n  while(k\
    \ > 0){\n    if(k&1) ret *= x, ret %= mod;\n    x *= x, x %= mod;\n    k /= 2;\n\
    \  }\n  return ret;\n}\n\nlong long primitive_root(long long prime){\n  vector<long\
    \ long> fac;\n  long long v = prime-1;\n  for(long long pp = 2; pp*pp <= v; ++pp){\n\
    \    long long e = 0;\n    while(v%pp == 0){\n      ++e;\n      v /= pp;\n   \
    \ }\n    if(e)\n      fac.emplace_back(pp);\n  }\n  if(v > 1)\n    fac.emplace_back(v);\n\
    \n  for(long long g = 2; g < prime; ++g){\n    if(power(g,(prime-1),prime) !=\
    \ 1){\n      return -1;\n    }\n    bool ok = true;\n    for(long long pp : fac){\n\
    \      if(power(g,(prime-1)/pp,prime) == 1){\n        ok = false;\n        break;\n\
    \      }\n    }\n    if(ok)\n      return g;\n  }\n  return -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/PrimitiveRoot.cpp
  requiredBy: []
  timestamp: '2020-10-23 20:46:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/PrimitiveRoot.cpp
layout: document
redirect_from:
- /library/Math/PrimitiveRoot.cpp
- /library/Math/PrimitiveRoot.cpp.html
title: Math/PrimitiveRoot.cpp
---
