---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/FoldableQueue.cpp
    title: DataStructure/FoldableQueue.cpp
  - icon: ':heavy_check_mark:'
    path: Math/modint.cpp
    title: Math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/LibraryChecker/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <array>\n#include <cstdio>\n\n#line 1 \"DataStructure/FoldableQueue.cpp\"\
    \n#include <algorithm>\n#include <vector>\n\ntemplate<typename T, typename F>\n\
    struct FoldableQueue {\nprivate:\n  const F f;\n  const T ti;\n  T v;\n  std::vector<T>\
    \ L, R;\npublic:\n  FoldableQueue(F f, T ti) : f(f), ti(ti), v(ti) {}\n  void\
    \ push_back(T x){\n    R.push_back(x);\n    v = f(v,x);\n  }\n  void pop_front(){\n\
    \    if(L.size()){\n      L.pop_back();\n      return;\n    }\n    std::swap(L,R);\n\
    \    std::reverse(L.begin(), L.end());\n    for(size_t i = 0; i+1 < L.size();\
    \ ++i)\n      L[i+1] = f(L[i+1],L[i]);\n    v = ti;\n    L.pop_back();\n  }\n\
    \  T fold(){\n    if(L.size()) return f(L.back(),v);\n    return v;\n  }\n};\n\
    #line 1 \"Math/modint.cpp\"\n#include <iostream>\n\ntemplate<long long mod>\n\
    class modint{\nprivate:\n  long long a;\npublic:\n  constexpr modint(const long\
    \ long x = 0) noexcept : a((x%mod+mod)%mod) {}\n  constexpr long long& value()\
    \ noexcept { return a; }\n  constexpr const long long& value() const noexcept\
    \ { return a; }\n  constexpr modint operator+(const modint rhs) const noexcept\
    \ {\n    return modint(*this) += rhs;\n  }\n  constexpr modint operator-(const\
    \ modint rhs) const noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr\
    \ modint operator*(const modint rhs) const noexcept {\n    return modint(*this)\
    \ *= rhs;\n  }\n  constexpr modint operator/(const modint rhs) const noexcept\
    \ {\n    return modint(*this) /= rhs;\n  }\n  constexpr modint& operator+=(const\
    \ modint rhs) noexcept {\n    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return\
    \ *this;\n  }\n  constexpr modint &operator-=(const modint rhs) noexcept {\n \
    \   if(a < rhs.a) a += mod;\n    a -= rhs.a;\n    return *this;\n  }\n  constexpr\
    \ modint& operator*=(const modint rhs) noexcept {\n    a = a*rhs.a%mod;\n    return\
    \ *this;\n  }\n  constexpr modint& operator/=(modint rhs) noexcept {\n    long\
    \ long k = mod-2;\n    while(k > 0){\n      if(k&1){\n        *this *= rhs;\n\
    \      }\n      rhs *= rhs;\n      k /= 2;\n    }\n    return *this;\n  }\n  friend\
    \ std::ostream& operator<<(std::ostream &os, const modint &X){\n    return os\
    \ << X.a;\n  }\n  friend std::istream& operator>>(std::istream &is, modint &X){\n\
    \    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n    return is;\n\
    \  }\n};\n#line 8 \"test/LibraryChecker/queue_operate_all_composite.test.cpp\"\
    \n\nusing namespace std;\n\nint main(){\n  using mint = modint<998244353>;\n \
    \ using T = array<mint,2>;\n  \n  auto f = [](const T& a, const T& b) -> T {\n\
    \             return {b[0]*a[0],b[0]*a[1]+b[1]};\n           };\n  \n  T ti =\
    \ {1,0};\n  \n  FoldableQueue Q(f,ti);\n\n  int q;\n  scanf(\"%d\",&q);\n  while(q--){\n\
    \    int t;\n    scanf(\"%d\",&t);\n    if(t == 0){\n      int a, b;\n      scanf(\"\
    %d %d\",&a,&b);\n      T g = {a,b};\n      Q.push_back(g);\n    }\n    if(t ==\
    \ 1){\n      Q.pop_front();\n    }\n    if(t == 2){\n      long long x;\n    \
    \  scanf(\"%lld\",&x);\n      auto t = Q.fold();\n      // cerr << t[0] << \"\
    \ \" << t[1] << \"\\n\";\n      printf(\"%lld\\n\",(t[0]*x+t[1]).value());\n \
    \   }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <array>\n#include <cstdio>\n\n#include \"DataStructure/FoldableQueue.cpp\"\
    \n#include \"Math/modint.cpp\"\n\nusing namespace std;\n\nint main(){\n  using\
    \ mint = modint<998244353>;\n  using T = array<mint,2>;\n  \n  auto f = [](const\
    \ T& a, const T& b) -> T {\n             return {b[0]*a[0],b[0]*a[1]+b[1]};\n\
    \           };\n  \n  T ti = {1,0};\n  \n  FoldableQueue Q(f,ti);\n\n  int q;\n\
    \  scanf(\"%d\",&q);\n  while(q--){\n    int t;\n    scanf(\"%d\",&t);\n    if(t\
    \ == 0){\n      int a, b;\n      scanf(\"%d %d\",&a,&b);\n      T g = {a,b};\n\
    \      Q.push_back(g);\n    }\n    if(t == 1){\n      Q.pop_front();\n    }\n\
    \    if(t == 2){\n      long long x;\n      scanf(\"%lld\",&x);\n      auto t\
    \ = Q.fold();\n      // cerr << t[0] << \" \" << t[1] << \"\\n\";\n      printf(\"\
    %lld\\n\",(t[0]*x+t[1]).value());\n    }\n  }\n}\n"
  dependsOn:
  - DataStructure/FoldableQueue.cpp
  - Math/modint.cpp
  isVerificationFile: true
  path: test/LibraryChecker/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 02:37:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LibraryChecker/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/queue_operate_all_composite.test.cpp
- /verify/test/LibraryChecker/queue_operate_all_composite.test.cpp.html
title: test/LibraryChecker/queue_operate_all_composite.test.cpp
---
