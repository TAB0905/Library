---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_DSL_2_D_DualSegmentTree.test.cpp
    title: test/aoj_DSL_2_D_DualSegmentTree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"DataStructure/DualSegmentTree.cpp\"\n#include <cassert>\n\
    #include <numeric>\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\
    #include <functional>\n#include <utility>\n\ntemplate <typename E, typename H>\n\
    struct DualSegmentTree{\nprivate:\n  // using H = std::function<E(E,E)>;\n  int\
    \ n, height;\n  H h;\n  const E ei;\n  std::vector<E> laz;\n  void propagate(int\
    \ k){\n    if(laz[k] == ei) return;\n    if(k >= n){\n      return;\n    }\n \
    \   laz[k<<1|0] = h(laz[k<<1|0],laz[k]);\n    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);\n\
    \    laz[k] = ei;\n  }\n  void thrust(int k){\n    for(int i = height; i >= 0;\
    \ --i)\n      propagate(k>>i);\n  }\npublic:\n  DualSegmentTree(H h, E ei) :\n\
    \    h(h), ei(ei) {}\n  void build(int n_){\n    n = n_;\n    height = 2;\n  \
    \  while(n_ >>= 1) ++height;\n    laz.assign(2*n,ei);\n  }\n  void update(int\
    \ l_, int r_, E x){\n    if(l_ >= r_) return;\n    l_ += n, r_ += n;\n    thrust(l_);\n\
    \    thrust(r_-1);\n    for(int l = l_, r = r_;l < r; l >>= 1, r >>= 1){\n   \
    \   if(l&1) laz[l] = h(laz[l],x), ++l;\n      if(r&1) --r, laz[r] = h(laz[r],x);\n\
    \    }\n  }\n  E operator[](int i){\n    assert(i >= 0 and i < n);\n    i += n;\n\
    \    E ret = laz[i];\n    while(i > 0){\n      i /= 2;\n      ret = h(ret,laz[i]);\n\
    \    }\n    return ret;\n  }\n};\n"
  code: "#include <cassert>\n#include <numeric>\n#include <algorithm>\n#include <iostream>\n\
    #include <vector>\n#include <functional>\n#include <utility>\n\ntemplate <typename\
    \ E, typename H>\nstruct DualSegmentTree{\nprivate:\n  // using H = std::function<E(E,E)>;\n\
    \  int n, height;\n  H h;\n  const E ei;\n  std::vector<E> laz;\n  void propagate(int\
    \ k){\n    if(laz[k] == ei) return;\n    if(k >= n){\n      return;\n    }\n \
    \   laz[k<<1|0] = h(laz[k<<1|0],laz[k]);\n    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);\n\
    \    laz[k] = ei;\n  }\n  void thrust(int k){\n    for(int i = height; i >= 0;\
    \ --i)\n      propagate(k>>i);\n  }\npublic:\n  DualSegmentTree(H h, E ei) :\n\
    \    h(h), ei(ei) {}\n  void build(int n_){\n    n = n_;\n    height = 2;\n  \
    \  while(n_ >>= 1) ++height;\n    laz.assign(2*n,ei);\n  }\n  void update(int\
    \ l_, int r_, E x){\n    if(l_ >= r_) return;\n    l_ += n, r_ += n;\n    thrust(l_);\n\
    \    thrust(r_-1);\n    for(int l = l_, r = r_;l < r; l >>= 1, r >>= 1){\n   \
    \   if(l&1) laz[l] = h(laz[l],x), ++l;\n      if(r&1) --r, laz[r] = h(laz[r],x);\n\
    \    }\n  }\n  E operator[](int i){\n    assert(i >= 0 and i < n);\n    i += n;\n\
    \    E ret = laz[i];\n    while(i > 0){\n      i /= 2;\n      ret = h(ret,laz[i]);\n\
    \    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/DualSegmentTree.cpp
  requiredBy: []
  timestamp: '2020-06-16 02:17:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_DSL_2_D_DualSegmentTree.test.cpp
documentation_of: DataStructure/DualSegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/DualSegmentTree.cpp
- /library/DataStructure/DualSegmentTree.cpp.html
title: DataStructure/DualSegmentTree.cpp
---
