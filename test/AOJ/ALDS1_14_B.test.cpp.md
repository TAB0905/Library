---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/RollingHash.cpp
    title: String/RollingHash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp
  bundledCode: "#line 1 \"test/AOJ/ALDS1_14_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp\"\
    \n\n#include <iostream>\n#line 1 \"String/RollingHash.cpp\"\n#include <array>\n\
    #include <vector>\n#include <string>\n\nclass RollingHash{\n  using ull = unsigned\
    \ long long;\n\n  static constexpr ull mask31 = (1LL<<31)-1;\n  static constexpr\
    \ ull mask30 = (1LL<<30)-1;\n  static constexpr ull mask61 = (1LL<<61)-1;\n  static\
    \ constexpr ull mod = mask61;\n  \n  int n;\n  ull base;\n  std::vector<ull> hash,\
    \ power;\n  \n  ull calc_mod(ull x){\n    ull xu = x>>61;\n    ull xd = x&mask61;\n\
    \    ull ret = xu+xd;\n    return ret < mod ? ret : ret-mod;\n  }\n\n  ull mul(ull\
    \ a, ull b){\n    ull au = a>>31;\n    ull ad = a&mask31;\n    ull bu = b>>31;\n\
    \    ull bd = b&mask31;\n    ull mid = ad*bu + au*bd;\n    ull midu = mid>>30;\n\
    \    ull midd = mid&mask30;\n    return au*bu*2 + midu + (midd<<31) + ad*bd;\n\
    \  }\n\npublic:\n  \n  RollingHash(const std::string& s) :\n    n(s.length()),\n\
    \    base(1e9+7),\n    hash(n+1),\n    power(n+1,1)\n  {\n    for(int i = 0; i\
    \ < n; ++i){\n      hash[i+1] = calc_mod(mul(hash[i],base)+s[i]);\n      power[i+1]\
    \ = calc_mod(mul(power[i],base));\n    }\n  }\n\n  ull get(int l, int r){//[l,r)\n\
    \    return calc_mod(mod*4 + hash[r]-mul(hash[l],power[r-l]));\n  }\n};\n\n#line\
    \ 5 \"test/AOJ/ALDS1_14_B.test.cpp\"\nusing namespace std;\n\nint main(){\n  string\
    \ s, t;\n  cin >> s >> t;\n  RollingHash rh_s(s), rh_t(t);\n  for(size_t i = 0;\
    \ i+t.length() <= s.length(); ++i){\n    if(rh_s.get(i,i+t.length()) == rh_t.get(0,t.length()))\n\
    \      cout << i << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp\"\
    \n\n#include <iostream>\n#include \"String/RollingHash.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n  string s, t;\n  cin >> s >> t;\n  RollingHash rh_s(s),\
    \ rh_t(t);\n  for(size_t i = 0; i+t.length() <= s.length(); ++i){\n    if(rh_s.get(i,i+t.length())\
    \ == rh_t.get(0,t.length()))\n      cout << i << '\\n';\n  }\n}\n"
  dependsOn:
  - String/RollingHash.cpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2022-07-19 01:53:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_14_B.test.cpp
- /verify/test/AOJ/ALDS1_14_B.test.cpp.html
title: test/AOJ/ALDS1_14_B.test.cpp
---
