---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/SegmentTree.cpp
    title: DataStructure/SegmentTree.cpp
  - icon: ':question:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/LibraryChecker/point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include <utility>\n#line 1 \"DataStructure/SegmentTree.cpp\"\
    \n#include <vector>\n#line 3 \"DataStructure/SegmentTree.cpp\"\n#include <climits>\n\
    #include <functional>\n\ntemplate <typename T, typename F>\nstruct SegmentTree{\n\
    private:\n  // using F = std::function<T(T,T)>;\n  int n;\n  F f;\n  T ti;\n \
    \ std::vector<T> dat;\npublic:\n  SegmentTree(){};\n  SegmentTree(F f,T ti) :\
    \ f(f), ti(ti) {}\n  void build(int n_){\n    n = n_;\n    dat.assign(2*n,ti);\n\
    \  }\n  void build(const std::vector<T> &v){\n    int n_ = v.size();\n    build(n_);\n\
    \    for(int i = 0; i < n; ++i) dat[n+i] = v[i];\n    for(int i = n-1; i >= 0;\
    \ --i)\n      dat[i] = f(dat[2*i+0], dat[2*i+1]);\n  }\n  void set_val(int k,\
    \ T x){\n    dat[k+=n] = x;\n    while(k > 0){\n      k = k/2;\n      dat[k] =\
    \ f(dat[2*k+0], dat[2*k+1]);\n    }\n  }\n  T query(int a, int b){ // [l,r)\n\
    \    if(a == b) return ti;\n    T vl = ti, vr = ti;\n    for(int l = a+n, r =\
    \ b+n; l < r; l >>= 1, r >>= 1){\n      if(l&1) vl = f(vl, dat[l++]);\n      if(r&1)\
    \ vr = f(dat[--r], vr);\n    }\n    return f(vl, vr);\n  }\n};\n\n#line 2 \"Math/modint.cpp\"\
    \n#include <cassert>\n\ntemplate<long long mod>\nclass modint{\nprivate:\n  using\
    \ T = long long;\n  T a;\npublic:\n  constexpr modint(const long long x = 0) noexcept\
    \ : a((x%mod+mod)%mod) {}\n  constexpr T& value() noexcept { return a; }\n  constexpr\
    \ const T& value() const noexcept { return a; }\n  constexpr modint operator-()\
    \ const noexcept {\n    return modint(0) -= *this;\n  }\n  constexpr modint operator+(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) += rhs;\n  }\n  constexpr\
    \ modint operator-(const modint& rhs) const noexcept {\n    return modint(*this)\
    \ -= rhs;\n  }\n  constexpr modint operator*(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) *= rhs;\n  }\n  constexpr modint operator/(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) /= rhs;\n  }\n  constexpr\
    \ modint& operator+=(const modint& rhs) noexcept {\n    a += rhs.a;\n    if(a\
    \ >= mod) a -= mod;\n    return *this;\n  }\n  constexpr modint& operator-=(const\
    \ modint& rhs) noexcept {\n    if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return\
    \ *this;\n  }\n  constexpr modint& operator*=(const modint& rhs) noexcept {\n\
    \    a = a*rhs.a%mod;\n    return *this;\n  }\n  constexpr modint& operator/=(const\
    \ modint& rhs) noexcept {\n    return *this *= rhs.inv();\n  }\n  constexpr bool\
    \ operator==(const modint& rhs) const noexcept {\n    return a == rhs.a;\n  }\n\
    \  constexpr bool operator!=(const modint& rhs) const noexcept {\n    return not\
    \ (*this == rhs);\n  }\n  constexpr modint pow(long long k) const noexcept {\n\
    \    modint ret(1);\n    modint x = k > 0 ? *this : this->inv();\n    k = abs(k);\n\
    \    while(k > 0){\n      if(k&1) ret *= x;\n      x *= x;\n      k >>= 1;\n \
    \   }\n    return ret;\n  }\n  constexpr modint inv() const noexcept {\n    return\
    \ pow(mod-2);\n  }\n  friend std::ostream& operator<<(std::ostream &os, const\
    \ modint &X) noexcept {\n    return os << X.a;\n  }\n  friend std::istream& operator>>(std::istream\
    \ &is, modint &X) noexcept {\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0)\
    \ X.a += mod;\n    return is;\n  }\n};\n#line 8 \"test/LibraryChecker/point_set_range_composite.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  using mint = modint<998244353>;\n \
    \ \n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  \n  using T = pair<mint,mint>;\n\
    \  auto f = [](T a, T b) -> T {\n    return {a.first*b.first,a.second*b.first+b.second};\n\
    \  };\n  T ti(1,0);\n  \n  SegmentTree st(f,ti);\n\n  int n, q;\n  cin >> n >>\
    \ q;\n  vector<T> A(n);\n  for(int i = 0; i < n; ++i){\n    mint a, b;\n    cin\
    \ >> a >> b;\n    A[i] = {a,b};\n  }\n  st.build(A);\n  \n  while(q--){\n    int\
    \ t;\n    cin >> t;\n    if(t){\n      int l, r, x;\n      cin >> l >> r >> x;\n\
    \      auto p = st.query(l,r);\n      cout << p.first*x+p.second << '\\n';\n \
    \   }else{\n      int p, c, d;\n      cin >> p >> c >> d;\n      st.set_val(p,T(c,d));\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include <utility>\n#include \"DataStructure/SegmentTree.cpp\"\
    \n#include \"Math/modint.cpp\"\n\nusing namespace std;\n\nint main(){\n  using\
    \ mint = modint<998244353>;\n  \n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  using T = pair<mint,mint>;\n  auto f = [](T a, T b) -> T {\n    return\
    \ {a.first*b.first,a.second*b.first+b.second};\n  };\n  T ti(1,0);\n  \n  SegmentTree\
    \ st(f,ti);\n\n  int n, q;\n  cin >> n >> q;\n  vector<T> A(n);\n  for(int i =\
    \ 0; i < n; ++i){\n    mint a, b;\n    cin >> a >> b;\n    A[i] = {a,b};\n  }\n\
    \  st.build(A);\n  \n  while(q--){\n    int t;\n    cin >> t;\n    if(t){\n  \
    \    int l, r, x;\n      cin >> l >> r >> x;\n      auto p = st.query(l,r);\n\
    \      cout << p.first*x+p.second << '\\n';\n    }else{\n      int p, c, d;\n\
    \      cin >> p >> c >> d;\n      st.set_val(p,T(c,d));\n    }\n  }\n}\n"
  dependsOn:
  - DataStructure/SegmentTree.cpp
  - Math/modint.cpp
  isVerificationFile: true
  path: test/LibraryChecker/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2022-04-08 13:37:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/point_set_range_composite.test.cpp
- /verify/test/LibraryChecker/point_set_range_composite.test.cpp.html
title: test/LibraryChecker/point_set_range_composite.test.cpp
---
