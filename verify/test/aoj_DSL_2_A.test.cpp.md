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


# :heavy_check_mark: test/aoj_DSL_2_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj_DSL_2_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 14:30:34+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/SegmentTree.cpp.html">DataStructure/SegmentTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <iostream>
#include "DataStructure/SegmentTree.cpp"
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  SegmentTree<int> rmq([](int a, int b){return min(a,b);}, INT_MAX);
  rmq.build(n);
  while(q--){
    int c, x, y;
    cin >> c >> x >> y;
    if(c){
      cout << rmq.query(x,y+1) << endl;
    }else{
      rmq.set_val(x,y);
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj_DSL_2_A.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <iostream>
#line 1 "DataStructure/SegmentTree.cpp"
#include <vector>
#line 3 "DataStructure/SegmentTree.cpp"
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

#line 5 "test/aoj_DSL_2_A.test.cpp"
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  SegmentTree<int> rmq([](int a, int b){return min(a,b);}, INT_MAX);
  rmq.build(n);
  while(q--){
    int c, x, y;
    cin >> c >> x >> y;
    if(c){
      cout << rmq.query(x,y+1) << endl;
    }else{
      rmq.set_val(x,y);
    }
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
