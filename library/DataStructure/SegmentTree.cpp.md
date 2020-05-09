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


# :heavy_check_mark: DataStructure/SegmentTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 14:30:34+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj_DSL_2_A.test.cpp.html">test/aoj_DSL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <iostream>
#include <climits>
#include <functional>

template <typename T>
struct SegmentTree{
private:
  using F = std::function<T(T,T)>;
  int n;
  F f;
  T ti;
  std::vector<T> dat;
public:
  SegmentTree(){};
  SegmentTree(F f,T ti) : f(f),ti(ti) {}
  void build(int n_){
    n = n_;
    dat.assign(2*n,ti);
  }
  void build(const std::vector<T> &v){
    int n_ = v.size();
    build(n_);
    for(int i = 0; i < n; ++i) dat[n+i]=v[i];
    for(int i = n-1; i >= 0; --i)
      dat[i]=f(dat[2*i+0],dat[2*i+1]);
  }
  void set_val(int k,T x){
    dat[k+=n] = x;
    while(k > 0){
      k = k/2;
      dat[k]=f(dat[2*k+0],dat[2*k+1]);
    }
  }
  T query(int a,int b){
    if(a == b) return ti;
    T vl = ti, vr = ti;
    for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){
      if(l&1) vl = f(vl,dat[l++]);
      if(r&1) vr = f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/SegmentTree.cpp"
#include <vector>
#include <iostream>
#include <climits>
#include <functional>

template <typename T>
struct SegmentTree{
private:
  using F = std::function<T(T,T)>;
  int n;
  F f;
  T ti;
  std::vector<T> dat;
public:
  SegmentTree(){};
  SegmentTree(F f,T ti) : f(f),ti(ti) {}
  void build(int n_){
    n = n_;
    dat.assign(2*n,ti);
  }
  void build(const std::vector<T> &v){
    int n_ = v.size();
    build(n_);
    for(int i = 0; i < n; ++i) dat[n+i]=v[i];
    for(int i = n-1; i >= 0; --i)
      dat[i]=f(dat[2*i+0],dat[2*i+1]);
  }
  void set_val(int k,T x){
    dat[k+=n] = x;
    while(k > 0){
      k = k/2;
      dat[k]=f(dat[2*k+0],dat[2*k+1]);
    }
  }
  T query(int a,int b){
    if(a == b) return ti;
    T vl = ti, vr = ti;
    for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){
      if(l&1) vl = f(vl,dat[l++]);
      if(r&1) vr = f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

