---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/RangeTree.cpp
    title: DataStructure/RangeTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_frequency
    links:
    - https://judge.yosupo.jp/problem/static_range_frequency
  bundledCode: "#line 1 \"test/LibraryChecker/static_range_frequency.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\n\n\
    #include <algorithm>\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\
    #line 3 \"DataStructure/RangeTree.cpp\"\n#include <climits>\n#include <functional>\n\
    \ntemplate <typename data_type, typename ans_type, typename query_type, typename\
    \ F, typename G, typename H>\nstruct RangeTree{\nprivate:\n  // using F = std::function<T(T,T)>;\n\
    \  int n;\n  F merge_data;\n  G query_;\n  H merge_ans;\n  ans_type ti;\n  std::vector<data_type>\
    \ dat;\npublic:\n  RangeTree(F f, G g, H h, ans_type ti) : merge_data(f), query_(g),\
    \ merge_ans(h), ti(ti) {}\n  void build(const std::vector<data_type> &v){\n  \
    \  n = v.size();\n    dat.resize(2*n);\n    for(int i = 0; i < n; ++i) dat[n+i]\
    \ = v[i];\n    for(int i = n-1; i >= 0; --i)\n      dat[i] = merge_data(dat[2*i+0],\
    \ dat[2*i+1]);\n  }\n  ans_type query(int a, int b, query_type q){\n    if(a ==\
    \ b) return ti;\n    ans_type vl = ti, vr = ti;\n    for(int l = a+n, r = b+n;\
    \ l < r; l >>= 1, r >>= 1){\n      if(l&1) vl = merge_ans(vl, query_(dat[l++],q));\n\
    \      if(r&1) vr = merge_ans(query_(dat[--r],q), vr);\n    }\n    return merge_ans(vl,\
    \ vr);\n  }\n};\n\n#line 8 \"test/LibraryChecker/static_range_frequency.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<vector<int>> A(n,vector<int>(1));\n \
    \ for(int i = 0; i < n; ++i)\n    cin >> A[i][0];\n  auto f = [](vector<int> a,\
    \ vector<int> b){\n    int m = a.size();\n    a.insert(a.end(),b.begin(),b.end());\n\
    \    inplace_merge(a.begin(),a.begin()+m,a.end());\n    return a;\n  };\n  auto\
    \ g = [](const vector<int>& a, int x) -> int {\n    auto ub = upper_bound(a.begin(),a.end(),x);\n\
    \    auto lb = lower_bound(a.begin(),a.end(),x);\n    return ub - lb;\n  };\n\
    \  auto h = [](int a, int b){\n    return a+b;\n  };\n  RangeTree<vector<int>,int,int,decltype(f),decltype(g),decltype(h)>\
    \ rt(f,g,h,0);\n  rt.build(A);\n  while(q--){\n    int l, r, x;\n    cin >> l\
    \ >> r >> x;\n    cout << rt.query(l,r,x) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_frequency\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\
    #include \"DataStructure/RangeTree.cpp\"\n\nusing namespace std;\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n, q;\n  cin >> n\
    \ >> q;\n  vector<vector<int>> A(n,vector<int>(1));\n  for(int i = 0; i < n; ++i)\n\
    \    cin >> A[i][0];\n  auto f = [](vector<int> a, vector<int> b){\n    int m\
    \ = a.size();\n    a.insert(a.end(),b.begin(),b.end());\n    inplace_merge(a.begin(),a.begin()+m,a.end());\n\
    \    return a;\n  };\n  auto g = [](const vector<int>& a, int x) -> int {\n  \
    \  auto ub = upper_bound(a.begin(),a.end(),x);\n    auto lb = lower_bound(a.begin(),a.end(),x);\n\
    \    return ub - lb;\n  };\n  auto h = [](int a, int b){\n    return a+b;\n  };\n\
    \  RangeTree<vector<int>,int,int,decltype(f),decltype(g),decltype(h)> rt(f,g,h,0);\n\
    \  rt.build(A);\n  while(q--){\n    int l, r, x;\n    cin >> l >> r >> x;\n  \
    \  cout << rt.query(l,r,x) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - DataStructure/RangeTree.cpp
  isVerificationFile: true
  path: test/LibraryChecker/static_range_frequency.test.cpp
  requiredBy: []
  timestamp: '2022-10-17 23:26:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/static_range_frequency.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/static_range_frequency.test.cpp
- /verify/test/LibraryChecker/static_range_frequency.test.cpp.html
title: test/LibraryChecker/static_range_frequency.test.cpp
---
