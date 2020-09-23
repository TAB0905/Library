---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/DualSegmentTree.cpp
    title: DataStructure/DualSegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D
  bundledCode: "#line 1 \"test/aoj_DSL_2_D_DualSegmentTree.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D\"\n\n#include\
    \ <array>\n#include <vector>\n#include <cstdio>\n#include <climits>\n\n#line 1\
    \ \"DataStructure/DualSegmentTree.cpp\"\n#include <cassert>\n#include <numeric>\n\
    #include <algorithm>\n#include <iostream>\n#line 6 \"DataStructure/DualSegmentTree.cpp\"\
    \n#include <functional>\n#include <utility>\n\ntemplate <typename E, typename\
    \ H>\nstruct DualSegmentTree{\nprivate:\n  // using H = std::function<E(E,E)>;\n\
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
    \    }\n    return ret;\n  }\n};\n#line 9 \"test/aoj_DSL_2_D_DualSegmentTree.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  using E = int;\n  E ei = numeric_limits<E>::max();\n\
    \n  auto f = [&](E a, E b){\n             if(b == ei) return a;\n            \
    \ return b;\n           };\n  \n  int n, q;\n  scanf(\"%d %d\",&n,&q);\n\n  DualSegmentTree\
    \ st(f,ei);\n  st.build(n);\n  \n  while(q--){\n    int t;\n    scanf(\"%d\",&t);\n\
    \    if(t){\n      int i;\n      scanf(\"%d\",&i);\n      printf(\"%d\\n\",st[i]);\n\
    \    }else{\n      int l, r;\n      E x;\n      scanf(\"%d %d %d\",&l,&r,&x);\n\
    \      ++r;\n      st.update(l,r,x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D\"\
    \n\n#include <array>\n#include <vector>\n#include <cstdio>\n#include <climits>\n\
    \n#include \"DataStructure/DualSegmentTree.cpp\"\n\nusing namespace std;\n\nint\
    \ main(){\n  using E = int;\n  E ei = numeric_limits<E>::max();\n\n  auto f =\
    \ [&](E a, E b){\n             if(b == ei) return a;\n             return b;\n\
    \           };\n  \n  int n, q;\n  scanf(\"%d %d\",&n,&q);\n\n  DualSegmentTree\
    \ st(f,ei);\n  st.build(n);\n  \n  while(q--){\n    int t;\n    scanf(\"%d\",&t);\n\
    \    if(t){\n      int i;\n      scanf(\"%d\",&i);\n      printf(\"%d\\n\",st[i]);\n\
    \    }else{\n      int l, r;\n      E x;\n      scanf(\"%d %d %d\",&l,&r,&x);\n\
    \      ++r;\n      st.update(l,r,x);\n    }\n  }\n}\n"
  dependsOn:
  - DataStructure/DualSegmentTree.cpp
  isVerificationFile: true
  path: test/aoj_DSL_2_D_DualSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-06-16 02:17:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_DSL_2_D_DualSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_DSL_2_D_DualSegmentTree.test.cpp
- /verify/test/aoj_DSL_2_D_DualSegmentTree.test.cpp.html
title: test/aoj_DSL_2_D_DualSegmentTree.test.cpp
---
