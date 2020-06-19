---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/library_checker_queue_operate_all_composite.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/library_checker_queue_operate_all_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 16:40:36+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/FoldableQueue.cpp.html">DataStructure/FoldableQueue.cpp</a>
* :heavy_check_mark: <a href="../../library/Math/modint.cpp.html">Math/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <array>
#include <cstdio>

#include "DataStructure/FoldableQueue.cpp"
#include "Math/modint.cpp"

using namespace std;

int main(){
  using mint = modint<998244353>;
  using T = array<mint,2>;
  
  auto f = [](const T& a, const T& b) -> T {
             return {b[0]*a[0],b[0]*a[1]+b[1]};
           };
  
  T ti = {1,0};
  
  FoldableQueue Q(f,ti);

  int q;
  scanf("%d",&q);
  while(q--){
    int t;
    scanf("%d",&t);
    if(t == 0){
      int a, b;
      scanf("%d %d",&a,&b);
      T g = {a,b};
      Q.push_back(g);
    }
    if(t == 1){
      Q.pop_front();
    }
    if(t == 2){
      long long x;
      scanf("%lld",&x);
      auto t = Q.fold();
      // cerr << t[0] << " " << t[1] << "\n";
      printf("%lld\n",(t[0]*x+t[1]).value());
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/library_checker_queue_operate_all_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <array>
#include <cstdio>

#line 1 "DataStructure/FoldableQueue.cpp"
#include <algorithm>
#include <vector>

template<typename T, typename F>
struct FoldableQueue {
private:
  const F f;
  const T ti;
  T v;
  std::vector<T> L, R;
public:
  FoldableQueue(F f, T ti) : f(f), ti(ti), v(ti) {}
  void push_back(T x){
    R.push_back(x);
    v = f(v,x);
  }
  void pop_front(){
    if(L.size()){
      L.pop_back();
      return;
    }
    std::swap(L,R);
    std::reverse(L.begin(), L.end());
    for(size_t i = 0; i+1 < L.size(); ++i)
      L[i+1] = f(L[i+1],L[i]);
    v = ti;
    L.pop_back();
  }
  T fold(){
    if(L.size()) return f(L.back(),v);
    return v;
  }
};
#line 1 "Math/modint.cpp"
#include <iostream>

template<long long mod>
class modint{
private:
  long long a;
public:
  constexpr modint(const long long x = 0) noexcept : a(x%mod) {}
  constexpr long long& value() noexcept { return a; }
  constexpr const long long& value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if(a >= mod) a -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if(a < rhs.a) a += mod;
    a -= rhs.a;
    return *this;
  }
  constexpr modint& operator*=(const modint rhs) noexcept {
    a = a*rhs.a%mod;
    return *this;
  }
  constexpr modint& operator/=(modint rhs) noexcept {
    long long k = mod-2;
    while(k > 0){
      if(k&1){
        *this *= rhs;
      }
      rhs *= rhs;
      k /= 2;
    }
    return *this;
  }
  friend std::ostream& operator<<(std::ostream &os, const modint &X){
    return os << X.a;
  }
  friend std::istream& operator>>(std::istream &is, modint &X){
    is >> X.a;
    X.a %= mod;
    if(X.a < 0) X.a += mod;
    return is;
  }
};
#line 8 "test/library_checker_queue_operate_all_composite.test.cpp"

using namespace std;

int main(){
  using mint = modint<998244353>;
  using T = array<mint,2>;
  
  auto f = [](const T& a, const T& b) -> T {
             return {b[0]*a[0],b[0]*a[1]+b[1]};
           };
  
  T ti = {1,0};
  
  FoldableQueue Q(f,ti);

  int q;
  scanf("%d",&q);
  while(q--){
    int t;
    scanf("%d",&t);
    if(t == 0){
      int a, b;
      scanf("%d %d",&a,&b);
      T g = {a,b};
      Q.push_back(g);
    }
    if(t == 1){
      Q.pop_front();
    }
    if(t == 2){
      long long x;
      scanf("%lld",&x);
      auto t = Q.fold();
      // cerr << t[0] << " " << t[1] << "\n";
      printf("%lld\n",(t[0]*x+t[1]).value());
    }
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

