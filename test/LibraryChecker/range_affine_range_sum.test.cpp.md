---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.cpp
    title: DataStructure/LazySegmentTree.cpp
  - icon: ':heavy_check_mark:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/LibraryChecker/range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #include <iostream>\n#include <iomanip>\n#include <vector>\n\n#line 1 \"DataStructure/LazySegmentTree.cpp\"\
    \n#include <algorithm>\n#line 4 \"DataStructure/LazySegmentTree.cpp\"\n#include\
    \ <functional>\n#include <utility>\n\ntemplate <typename T, typename E, typename\
    \ F, typename G, typename H>\nstruct LazySegmentTree{\nprivate:\n  // using F\
    \ = std::function<T(T,T)>;\n  // using G = std::function<T(T,E)>;\n  // using\
    \ H = std::function<E(E,E)>;\n  int n, height;\n  F f;\n  G g;\n  H h;\n  T ti;\n\
    \  E ei;\n  std::vector<T> dat;\n  std::vector<E> laz;\n  T reflect(int k){\n\
    \    return laz[k] == ei ? dat[k] : g(dat[k],laz[k]);\n  }\n  void propagate(int\
    \ k){\n    if(laz[k] == ei) return;\n    if(k >= n){\n      dat[k] = reflect(k);\n\
    \      laz[k] = ei;\n      return;\n    }\n    laz[k<<1|0] = h(laz[k<<1|0],laz[k]);\n\
    \    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);\n    dat[k] = reflect(k);\n    laz[k]\
    \ = ei;\n  }\n  void thrust(int k){\n    for(int i = height; i >= 0; --i)\n  \
    \    propagate(k>>i);\n  }\n  void recalc(int k){\n    while(k >>= 1){\n     \
    \ dat[k] = f(reflect(k<<1|0),reflect(k<<1|1));\n    }\n  }\npublic:\n  LazySegmentTree(F\
    \ f, G g, H h, T ti, E ei) :\n    f(f), g(g), h(h), ti(ti), ei(ei) {}\n  void\
    \ build(int n_){\n    n = n_;\n    height = 2;\n    while(n_ >>= 1) ++height;\n\
    \    dat.assign(2*n,ti);\n    laz.assign(2*n,ei);\n  }\n  void build(const std::vector<T>\
    \ &v){\n    int n_ = v.size();\n    build(n_);\n    for(int i = 0; i < n; ++i)\
    \ dat[n+i]=v[i];\n    for(int i = n-1; i >= 0; --i)\n      dat[i]=f(dat[i<<1|0],dat[i<<1|1]);\n\
    \  }\n  void update(int l_, int r_, E x){\n    if(l_ >= r_) return;\n    l_ +=\
    \ n, r_ += n;\n    thrust(l_);\n    thrust(r_-1);\n    for(int l = l_, r = r_;l\
    \ < r; l >>= 1, r >>= 1){\n      if(l&1) laz[l] = h(laz[l],x), ++l;\n      if(r&1)\
    \ --r, laz[r] = h(laz[r],x);\n    }\n    recalc(l_);\n    recalc(r_-1);\n  }\n\
    \  void set_val(int a, T x){\n    thrust(a+=n);\n    dat[a] = x;\n    laz[a] =\
    \ ei;\n    recalc(a);\n  }\n  T query(int l, int r){\n    if(l >= r) return ti;\n\
    \    l += n;\n    r += n;\n    thrust(l);\n    thrust(r-1);\n    T vl = ti, vr\
    \ = ti;\n    for(; l < r; l >>= 1, r >>= 1){\n      if(l&1) vl = f(vl,reflect(l++));\n\
    \      if(r&1) vr = f(reflect(--r),vr);\n    }\n    return f(vl,vr);\n  }\n};\n\
    \n#line 2 \"Math/modint.cpp\"\n#include <cassert>\n\ntemplate<long long mod>\n\
    class modint{\nprivate:\n  using T = long long;\n  T a;\npublic:\n  constexpr\
    \ modint(const long long x = 0) noexcept : a((x%mod+mod)%mod) {}\n  constexpr\
    \ T& value() noexcept { return a; }\n  constexpr const T& value() const noexcept\
    \ { return a; }\n  constexpr modint operator-() const noexcept {\n    return modint(0)\
    \ -= *this;\n  }\n  constexpr modint operator+(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) += rhs;\n  }\n  constexpr modint operator-(const\
    \ modint& rhs) const noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr\
    \ modint operator*(const modint& rhs) const noexcept {\n    return modint(*this)\
    \ *= rhs;\n  }\n  constexpr modint operator/(const modint& rhs) const noexcept\
    \ {\n    return modint(*this) /= rhs;\n  }\n  constexpr modint& operator+=(const\
    \ modint& rhs) noexcept {\n    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return\
    \ *this;\n  }\n  constexpr modint &operator-=(const modint& rhs) noexcept {\n\
    \    if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return *this;\n  }\n  constexpr\
    \ modint& operator*=(const modint& rhs) noexcept {\n    a = a*rhs.a%mod;\n   \
    \ return *this;\n  }\n  constexpr modint& operator/=(const modint& rhs) noexcept\
    \ {\n    return *this *= rhs.inv();\n  }\n  constexpr bool operator==(const modint&\
    \ rhs) const noexcept {\n    return a == rhs.a;\n  }\n  constexpr bool operator!=(const\
    \ modint& rhs) const noexcept {\n    return not (*this == rhs);\n  }\n  constexpr\
    \ modint pow(long long k) const noexcept {\n    modint ret(1);\n    modint x =\
    \ k > 0 ? *this : this->inv();\n    k = abs(k);\n    while(k > 0){\n      if(k&1)\
    \ ret *= x;\n      x *= x;\n      k >>= 1;\n    }\n    return ret;\n  }\n  constexpr\
    \ modint inv() const noexcept {\n    return pow(mod-2);\n  }\n  friend std::ostream&\
    \ operator<<(std::ostream &os, const modint &X) noexcept {\n    return os << X.a;\n\
    \  }\n  friend std::istream& operator>>(std::istream &is, modint &X) noexcept\
    \ {\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n    return\
    \ is;\n  }\n};\n#line 9 \"test/LibraryChecker/range_affine_range_sum.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  using mint = modint<998244353>;\n  using T = pair<mint,mint>;\n  using\
    \ E = pair<mint,mint>;\n\n  auto f = [](T a, T b) -> T {\n    return {a.first+b.first,a.second+b.second};\n\
    \  };\n  auto g = [](T a, E b) -> T {\n    return {a.first*b.first+a.second*b.second,a.second};\n\
    \  };\n  auto h = [](E a, E b) -> E {\n    return {a.first*b.first,a.second*b.first+b.second};\n\
    \  };\n\n  T ti(0,0);\n  E ei(1,0);\n  \n  int n, q;\n  cin >> n >> q;\n  \n \
    \ vector<T> A(n);\n  for(int i = 0; i < n; ++i){\n    int a;\n    cin >> a;\n\
    \    A[i] = {a,1};\n  }\n\n  LazySegmentTree st(f,g,h,ti,ei);\n  st.build(A);\n\
    \  \n  while(q--){\n    int t, l, r;\n    cin >> t >> l >> r;\n    if(t){\n  \
    \    auto p = st.query(l,r);\n      cout << p.first << '\\n';\n    }else{\n  \
    \    mint b, c;\n      cin >> b >> c;\n      st.update(l,r,E(b,c));\n    }\n \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n\n#include \"\
    DataStructure/LazySegmentTree.cpp\"\n#include \"Math/modint.cpp\"\n\nusing namespace\
    \ std;\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n \
    \ \n  using mint = modint<998244353>;\n  using T = pair<mint,mint>;\n  using E\
    \ = pair<mint,mint>;\n\n  auto f = [](T a, T b) -> T {\n    return {a.first+b.first,a.second+b.second};\n\
    \  };\n  auto g = [](T a, E b) -> T {\n    return {a.first*b.first+a.second*b.second,a.second};\n\
    \  };\n  auto h = [](E a, E b) -> E {\n    return {a.first*b.first,a.second*b.first+b.second};\n\
    \  };\n\n  T ti(0,0);\n  E ei(1,0);\n  \n  int n, q;\n  cin >> n >> q;\n  \n \
    \ vector<T> A(n);\n  for(int i = 0; i < n; ++i){\n    int a;\n    cin >> a;\n\
    \    A[i] = {a,1};\n  }\n\n  LazySegmentTree st(f,g,h,ti,ei);\n  st.build(A);\n\
    \  \n  while(q--){\n    int t, l, r;\n    cin >> t >> l >> r;\n    if(t){\n  \
    \    auto p = st.query(l,r);\n      cout << p.first << '\\n';\n    }else{\n  \
    \    mint b, c;\n      cin >> b >> c;\n      st.update(l,r,E(b,c));\n    }\n \
    \ }\n}\n"
  dependsOn:
  - DataStructure/LazySegmentTree.cpp
  - Math/modint.cpp
  isVerificationFile: true
  path: test/LibraryChecker/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-05-02 22:46:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/range_affine_range_sum.test.cpp
- /verify/test/LibraryChecker/range_affine_range_sum.test.cpp.html
title: test/LibraryChecker/range_affine_range_sum.test.cpp
---
