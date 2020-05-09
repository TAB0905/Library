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


# :heavy_check_mark: test/aoj_DSL_2_G.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj_DSL_2_G.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 14:54:10+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/LazySegmentTree.cpp.html">DataStructure/LazySegmentTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include <iostream>
#include "DataStructure/LazySegmentTree.cpp"
using namespace std;

int main(){
  using T = pair<long long, long long>;
  using E = long long;
  T ti(0,0);
  E ei = 0;
  function<T(T,T)> f = [](T a, T b) -> T { return {a.first+b.first,a.second+b.second};};
  function<T(T,E)> g = [](T a, E b) -> T { return {a.first+b*a.second,a.second};};
  function<E(E,E)> h = [](E a, E b) -> E { return a+b;};
  LazySegmentTree<T,E> st(f,g,h,ti,ei);
  int n, q;
  cin >> n >> q;
  vector<T> v(n,T(0,1));
  st.build(v);
  while(q--){
    int t;
    cin >> t;
    if(t){
      int s, t;
      cin >> s >> t;
      cout << st.query(s-1,t).first << "\n";
    }else{
      int s, t, x;
      cin >> s >> t >> x;
      st.update(s-1,t,x);
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj_DSL_2_G.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include <iostream>
#line 1 "DataStructure/LazySegmentTree.cpp"
#include <algorithm>
#line 3 "DataStructure/LazySegmentTree.cpp"
#include <vector>
#include <functional>
#include <utility>

template <typename T, typename E>
struct LazySegmentTree{
private:
  using F = std::function<T(T,T)>;
  using G = std::function<T(T,E)>;
  using H = std::function<E(E,E)>;
  int n, height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  std::vector<T> dat;
  std::vector<E> laz;
  T reflect(int k){
    return laz[k] == ei ? dat[k] : g(dat[k],laz[k]);
  }
  void propagate(int k){
    if(laz[k] == ei) return;
    if(k >= n){
      dat[k] = reflect(k);
      laz[k] = ei;
      return;
    }
    laz[k<<1|0] = h(laz[k<<1|0],laz[k]);
    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }
  void thrust(int k){
    for(int i = height; i >= 0; --i)
      propagate(k>>i);
  }
  void recalc(int k){
    while(k >>= 1){
      dat[k] = f(reflect(k<<1|0),reflect(k<<1|1));
    }
  }
public:
  LazySegmentTree(F f,G g, H h, T ti, E ei) :
    f(f), g(g), h(h), ti(ti), ei(ei) {}
  void build(int n_){
    n = n_;
    height = 2;
    while(n_ >>= 1) ++height;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const std::vector<T> &v){
    int n_ = v.size();
    build(n_);
    for(int i = 0; i < n; ++i) dat[n+i]=v[i];
    for(int i = n-1; i >= 0; --i)
      dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
  }
  void update(int l_, int r_, E x){
    if(l_ >= r_) return;
    l_ += n, r_ += n;
    thrust(l_);
    thrust(r_-1);
    for(int l = l_, r = r_;l < r; l >>= 1, r >>= 1){
      if(l&1) laz[l] = h(laz[l],x), ++l;
      if(r&1) --r, laz[r] = h(laz[r],x);
    }
    recalc(l_);
    recalc(r_-1);
  }
  void set_val(int a, T x){
    thrust(a+=n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }
  T query(int l, int r){
    if(l >= r) return ti;
    l += n;
    r += n;
    thrust(l);
    thrust(r-1);
    T vl = ti, vr = ti;
    for(; l < r; l >>= 1, r >>= 1){
      if(l&1) vl = f(vl,reflect(l++));
      if(r&1) vr = f(reflect(--r),vr);
    }
    return f(vl,vr);
  }
};

#line 5 "test/aoj_DSL_2_G.test.cpp"
using namespace std;

int main(){
  using T = pair<long long, long long>;
  using E = long long;
  T ti(0,0);
  E ei = 0;
  function<T(T,T)> f = [](T a, T b) -> T { return {a.first+b.first,a.second+b.second};};
  function<T(T,E)> g = [](T a, E b) -> T { return {a.first+b*a.second,a.second};};
  function<E(E,E)> h = [](E a, E b) -> E { return a+b;};
  LazySegmentTree<T,E> st(f,g,h,ti,ei);
  int n, q;
  cin >> n >> q;
  vector<T> v(n,T(0,1));
  st.build(v);
  while(q--){
    int t;
    cin >> t;
    if(t){
      int s, t;
      cin >> s >> t;
      cout << st.query(s-1,t).first << "\n";
    }else{
      int s, t, x;
      cin >> s >> t >> x;
      st.update(s-1,t,x);
    }
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

