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
    PROBLEM: https://old.yosupo.jp/problem/range_kth_smallest
    links:
    - https://old.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/LibraryChecker/range_kth_smallest.test.cpp\"\n#define\
    \ PROBLEM \"https://old.yosupo.jp/problem/range_kth_smallest\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n#line 3 \"DataStructure/RangeTree.cpp\"\
    \n#include <climits>\n#include <functional>\n\ntemplate <typename data_type, typename\
    \ ans_type, typename query_type, typename F, typename G, typename H>\nstruct RangeTree{\n\
    private:\n  // using F = std::function<T(T,T)>;\n  int n;\n  F merge_data;\n \
    \ G query_;\n  H merge_ans;\n  ans_type ti;\n  std::vector<data_type> dat;\npublic:\n\
    \  RangeTree(F f, G g, H h, ans_type ti) : merge_data(f), query_(g), merge_ans(h),\
    \ ti(ti) {}\n  void build(const std::vector<data_type> &v){\n    n = v.size();\n\
    \    dat.resize(2*n);\n    for(int i = 0; i < n; ++i) dat[n+i] = v[i];\n    for(int\
    \ i = n-1; i >= 0; --i)\n      dat[i] = merge_data(dat[2*i+0], dat[2*i+1]);\n\
    \  }\n  ans_type query(int a, int b, query_type q){\n    if(a == b) return ti;\n\
    \    ans_type vl = ti, vr = ti;\n    for(int l = a+n, r = b+n; l < r; l >>= 1,\
    \ r >>= 1){\n      if(l&1) vl = merge_ans(vl, query_(dat[l++],q));\n      if(r&1)\
    \ vr = merge_ans(query_(dat[--r],q), vr);\n    }\n    return merge_ans(vl, vr);\n\
    \  }\n};\n\n#line 7 \"test/LibraryChecker/range_kth_smallest.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main(){\n  int n, q;\n  cin >> n >> q;\n  vector<vector<int>>\
    \ A(n,vector<int>(1));\n  for(int i = 0; i < n; ++i)\n    cin >> A[i][0];\n  auto\
    \ f = [](const vector<int>& a, const vector<int>& b){\n    vector<int> ret = a;\n\
    \    int n = a.size();\n    ret.insert(ret.end(),b.begin(),b.end());\n    inplace_merge(ret.begin(),ret.begin()+n,ret.end());\n\
    \    return ret;\n  };\n\n  auto g = [](const vector<int>& a, int q){\n    return\
    \ upper_bound(a.begin(),a.end(),q) - a.begin();\n  };\n\n  auto h = [](int a,\
    \ int b){\n    return a+b;\n  };\n\n  RangeTree<vector<int>,int,int,decltype(f),decltype(g),decltype(h)>\
    \ rt(f,g,h,0);\n  rt.build(A);\n\n  const int INF = 1e9;\n  while(q--){\n    int\
    \ l, r, k;\n    cin >> l >> r >> k;\n    ++k;\n    int ok = INF, ng = -1;\n  \
    \  while(abs(ok-ng) > 1){\n      int mid = (ok+ng)/2;\n      if(rt.query(l,r,mid)\
    \ >= k) ok = mid;\n      else ng = mid;\n    }\n    cout << ok << '\\n';\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://old.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <algorithm>\n#include <iostream>\n#include <vector>\n#include \"DataStructure/RangeTree.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  int n, q;\n  cin >> n >> q;\n  vector<vector<int>>\
    \ A(n,vector<int>(1));\n  for(int i = 0; i < n; ++i)\n    cin >> A[i][0];\n  auto\
    \ f = [](const vector<int>& a, const vector<int>& b){\n    vector<int> ret = a;\n\
    \    int n = a.size();\n    ret.insert(ret.end(),b.begin(),b.end());\n    inplace_merge(ret.begin(),ret.begin()+n,ret.end());\n\
    \    return ret;\n  };\n\n  auto g = [](const vector<int>& a, int q){\n    return\
    \ upper_bound(a.begin(),a.end(),q) - a.begin();\n  };\n\n  auto h = [](int a,\
    \ int b){\n    return a+b;\n  };\n\n  RangeTree<vector<int>,int,int,decltype(f),decltype(g),decltype(h)>\
    \ rt(f,g,h,0);\n  rt.build(A);\n\n  const int INF = 1e9;\n  while(q--){\n    int\
    \ l, r, k;\n    cin >> l >> r >> k;\n    ++k;\n    int ok = INF, ng = -1;\n  \
    \  while(abs(ok-ng) > 1){\n      int mid = (ok+ng)/2;\n      if(rt.query(l,r,mid)\
    \ >= k) ok = mid;\n      else ng = mid;\n    }\n    cout << ok << '\\n';\n  }\n\
    }\n"
  dependsOn:
  - DataStructure/RangeTree.cpp
  isVerificationFile: true
  path: test/LibraryChecker/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2021-03-22 00:01:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/range_kth_smallest.test.cpp
- /verify/test/LibraryChecker/range_kth_smallest.test.cpp.html
title: test/LibraryChecker/range_kth_smallest.test.cpp
---
