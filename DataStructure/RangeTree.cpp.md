---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/range_kth_smallest.test.cpp
    title: test/LibraryChecker/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LibraryChecker/static_range_frequency.test.cpp
    title: test/LibraryChecker/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/RangeTree.cpp\"\n#include <vector>\n#include\
    \ <iostream>\n#include <climits>\n#include <functional>\n\ntemplate <typename\
    \ data_type, typename ans_type, typename query_type, typename F, typename G, typename\
    \ H>\nstruct RangeTree{\nprivate:\n  // using F = std::function<T(T,T)>;\n  int\
    \ n;\n  F merge_data;\n  G query_;\n  H merge_ans;\n  ans_type ti;\n  std::vector<data_type>\
    \ dat;\npublic:\n  RangeTree(F f, G g, H h, ans_type ti) : merge_data(f), query_(g),\
    \ merge_ans(h), ti(ti) {}\n  void build(const std::vector<data_type> &v){\n  \
    \  n = v.size();\n    dat.resize(2*n);\n    for(int i = 0; i < n; ++i) dat[n+i]\
    \ = v[i];\n    for(int i = n-1; i >= 0; --i)\n      dat[i] = merge_data(dat[2*i+0],\
    \ dat[2*i+1]);\n  }\n  ans_type query(int a, int b, query_type q){\n    if(a ==\
    \ b) return ti;\n    ans_type vl = ti, vr = ti;\n    for(int l = a+n, r = b+n;\
    \ l < r; l >>= 1, r >>= 1){\n      if(l&1) vl = merge_ans(vl, query_(dat[l++],q));\n\
    \      if(r&1) vr = merge_ans(query_(dat[--r],q), vr);\n    }\n    return merge_ans(vl,\
    \ vr);\n  }\n};\n\n"
  code: "#include <vector>\n#include <iostream>\n#include <climits>\n#include <functional>\n\
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
    \ vr);\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/RangeTree.cpp
  requiredBy: []
  timestamp: '2021-03-22 00:01:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LibraryChecker/static_range_frequency.test.cpp
  - test/LibraryChecker/range_kth_smallest.test.cpp
documentation_of: DataStructure/RangeTree.cpp
layout: document
redirect_from:
- /library/DataStructure/RangeTree.cpp
- /library/DataStructure/RangeTree.cpp.html
title: DataStructure/RangeTree.cpp
---
