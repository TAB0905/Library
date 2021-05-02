---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/BIT.cpp
    title: DataStructure/BIT.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/LibraryChecker/point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n\n#line 1 \"DataStructure/BIT.cpp\"\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate<typename T>\nstruct BIT{//0-indexed\n\
    private:\n  std::vector<T> data;\n  const int n;\npublic:\n  BIT(int sz) : data(sz+1,0),\
    \ n(sz) {}\n\n  T sum(size_t i) const noexcept {//sum[0,i)\n    //++i;\n    T\
    \ s = 0;\n    while(i > 0){\n      s += data[i];\n      i -= i&(-i);\n    }\n\
    \    return s;\n  }\n\n  T sum(size_t i, size_t j) const noexcept {// sum[i,j)\n\
    \    return sum(j) - sum(i);\n  }\n\n  void add(int i, T x) noexcept {\n    ++i;\n\
    \    assert(i > 0);\n    while(i <= n){\n      data[i] += x;\n      i += i&(-i);\n\
    \    }\n  }\n};\n#line 7 \"test/LibraryChecker/point_add_range_sum.test.cpp\"\n\
    \nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int n, q;\n  cin >> n >> q;\n  BIT<long long> bit(n);\n  for(int i = 0;\
    \ i < n; ++i){\n    long long a;\n    cin >> a;\n    bit.add(i,a);\n  }\n  while(q--){\n\
    \    int t;\n    cin >> t;\n    if(t){\n      int l, r;\n      cin >> l >> r;\n\
    \      cout << bit.sum(l,r) << '\\n';\n    }else{\n      int p, x;\n      cin\
    \ >> p >> x;\n      bit.add(p,x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include <iomanip>\n\n#include \"DataStructure/BIT.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  int n, q;\n  cin >> n >> q;\n  BIT<long long> bit(n);\n  for(int i = 0;\
    \ i < n; ++i){\n    long long a;\n    cin >> a;\n    bit.add(i,a);\n  }\n  while(q--){\n\
    \    int t;\n    cin >> t;\n    if(t){\n      int l, r;\n      cin >> l >> r;\n\
    \      cout << bit.sum(l,r) << '\\n';\n    }else{\n      int p, x;\n      cin\
    \ >> p >> x;\n      bit.add(p,x);\n    }\n  }\n}\n"
  dependsOn:
  - DataStructure/BIT.cpp
  isVerificationFile: true
  path: test/LibraryChecker/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-05-02 22:46:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/point_add_range_sum.test.cpp
- /verify/test/LibraryChecker/point_add_range_sum.test.cpp.html
title: test/LibraryChecker/point_add_range_sum.test.cpp
---
