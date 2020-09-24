---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.cpp
    title: DataStructure/LazySegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
  bundledCode: "#line 1 \"test/AOJ/DSL_2_G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\
    \n\n#include <iostream>\n#line 1 \"DataStructure/LazySegmentTree.cpp\"\n#include\
    \ <algorithm>\n#line 3 \"DataStructure/LazySegmentTree.cpp\"\n#include <vector>\n\
    #include <functional>\n#include <utility>\n\ntemplate <typename T, typename E>\n\
    struct LazySegmentTree{\nprivate:\n  using F = std::function<T(T,T)>;\n  using\
    \ G = std::function<T(T,E)>;\n  using H = std::function<E(E,E)>;\n  int n, height;\n\
    \  F f;\n  G g;\n  H h;\n  T ti;\n  E ei;\n  std::vector<T> dat;\n  std::vector<E>\
    \ laz;\n  T reflect(int k){\n    return laz[k] == ei ? dat[k] : g(dat[k],laz[k]);\n\
    \  }\n  void propagate(int k){\n    if(laz[k] == ei) return;\n    if(k >= n){\n\
    \      dat[k] = reflect(k);\n      laz[k] = ei;\n      return;\n    }\n    laz[k<<1|0]\
    \ = h(laz[k<<1|0],laz[k]);\n    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);\n    dat[k]\
    \ = reflect(k);\n    laz[k] = ei;\n  }\n  void thrust(int k){\n    for(int i =\
    \ height; i >= 0; --i)\n      propagate(k>>i);\n  }\n  void recalc(int k){\n \
    \   while(k >>= 1){\n      dat[k] = f(reflect(k<<1|0),reflect(k<<1|1));\n    }\n\
    \  }\npublic:\n  LazySegmentTree(F f,G g, H h, T ti, E ei) :\n    f(f), g(g),\
    \ h(h), ti(ti), ei(ei) {}\n  void build(int n_){\n    n = n_;\n    height = 2;\n\
    \    while(n_ >>= 1) ++height;\n    dat.assign(2*n,ti);\n    laz.assign(2*n,ei);\n\
    \  }\n  void build(const std::vector<T> &v){\n    int n_ = v.size();\n    build(n_);\n\
    \    for(int i = 0; i < n; ++i) dat[n+i]=v[i];\n    for(int i = n-1; i >= 0; --i)\n\
    \      dat[i]=f(dat[i<<1|0],dat[i<<1|1]);\n  }\n  void update(int l_, int r_,\
    \ E x){\n    if(l_ >= r_) return;\n    l_ += n, r_ += n;\n    thrust(l_);\n  \
    \  thrust(r_-1);\n    for(int l = l_, r = r_;l < r; l >>= 1, r >>= 1){\n     \
    \ if(l&1) laz[l] = h(laz[l],x), ++l;\n      if(r&1) --r, laz[r] = h(laz[r],x);\n\
    \    }\n    recalc(l_);\n    recalc(r_-1);\n  }\n  void set_val(int a, T x){\n\
    \    thrust(a+=n);\n    dat[a] = x;\n    laz[a] = ei;\n    recalc(a);\n  }\n \
    \ T query(int l, int r){\n    if(l >= r) return ti;\n    l += n;\n    r += n;\n\
    \    thrust(l);\n    thrust(r-1);\n    T vl = ti, vr = ti;\n    for(; l < r; l\
    \ >>= 1, r >>= 1){\n      if(l&1) vl = f(vl,reflect(l++));\n      if(r&1) vr =\
    \ f(reflect(--r),vr);\n    }\n    return f(vl,vr);\n  }\n};\n\n#line 5 \"test/AOJ/DSL_2_G.test.cpp\"\
    \nusing namespace std;\n\nint main(){\n  using T = pair<long long, long long>;\n\
    \  using E = long long;\n  T ti(0,0);\n  E ei = 0;\n  function<T(T,T)> f = [](T\
    \ a, T b) -> T { return {a.first+b.first,a.second+b.second};};\n  function<T(T,E)>\
    \ g = [](T a, E b) -> T { return {a.first+b*a.second,a.second};};\n  function<E(E,E)>\
    \ h = [](E a, E b) -> E { return a+b;};\n  LazySegmentTree<T,E> st(f,g,h,ti,ei);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<T> v(n,T(0,1));\n  st.build(v);\n  while(q--){\n\
    \    int t;\n    cin >> t;\n    if(t){\n      int s, t;\n      cin >> s >> t;\n\
    \      cout << st.query(s-1,t).first << \"\\n\";\n    }else{\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      st.update(s-1,t,x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\
    \n\n#include <iostream>\n#include \"DataStructure/LazySegmentTree.cpp\"\nusing\
    \ namespace std;\n\nint main(){\n  using T = pair<long long, long long>;\n  using\
    \ E = long long;\n  T ti(0,0);\n  E ei = 0;\n  function<T(T,T)> f = [](T a, T\
    \ b) -> T { return {a.first+b.first,a.second+b.second};};\n  function<T(T,E)>\
    \ g = [](T a, E b) -> T { return {a.first+b*a.second,a.second};};\n  function<E(E,E)>\
    \ h = [](E a, E b) -> E { return a+b;};\n  LazySegmentTree<T,E> st(f,g,h,ti,ei);\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<T> v(n,T(0,1));\n  st.build(v);\n  while(q--){\n\
    \    int t;\n    cin >> t;\n    if(t){\n      int s, t;\n      cin >> s >> t;\n\
    \      cout << st.query(s-1,t).first << \"\\n\";\n    }else{\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      st.update(s-1,t,x);\n    }\n  }\n}\n"
  dependsOn:
  - DataStructure/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 21:15:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_G.test.cpp
- /verify/test/AOJ/DSL_2_G.test.cpp.html
title: test/AOJ/DSL_2_G.test.cpp
---
