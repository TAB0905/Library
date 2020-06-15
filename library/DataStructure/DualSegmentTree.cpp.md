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


# :heavy_check_mark: DataStructure/DualSegmentTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/DualSegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 02:17:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj_DSL_2_D_DualSegmentTree.test.cpp.html">test/aoj_DSL_2_D_DualSegmentTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <utility>

template <typename E, typename H>
struct DualSegmentTree{
private:
  // using H = std::function<E(E,E)>;
  int n, height;
  H h;
  const E ei;
  std::vector<E> laz;
  void propagate(int k){
    if(laz[k] == ei) return;
    if(k >= n){
      return;
    }
    laz[k<<1|0] = h(laz[k<<1|0],laz[k]);
    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);
    laz[k] = ei;
  }
  void thrust(int k){
    for(int i = height; i >= 0; --i)
      propagate(k>>i);
  }
public:
  DualSegmentTree(H h, E ei) :
    h(h), ei(ei) {}
  void build(int n_){
    n = n_;
    height = 2;
    while(n_ >>= 1) ++height;
    laz.assign(2*n,ei);
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
  }
  E operator[](int i){
    assert(i >= 0 and i < n);
    i += n;
    E ret = laz[i];
    while(i > 0){
      i /= 2;
      ret = h(ret,laz[i]);
    }
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/DualSegmentTree.cpp"
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <utility>

template <typename E, typename H>
struct DualSegmentTree{
private:
  // using H = std::function<E(E,E)>;
  int n, height;
  H h;
  const E ei;
  std::vector<E> laz;
  void propagate(int k){
    if(laz[k] == ei) return;
    if(k >= n){
      return;
    }
    laz[k<<1|0] = h(laz[k<<1|0],laz[k]);
    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);
    laz[k] = ei;
  }
  void thrust(int k){
    for(int i = height; i >= 0; --i)
      propagate(k>>i);
  }
public:
  DualSegmentTree(H h, E ei) :
    h(h), ei(ei) {}
  void build(int n_){
    n = n_;
    height = 2;
    while(n_ >>= 1) ++height;
    laz.assign(2*n,ei);
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
  }
  E operator[](int i){
    assert(i >= 0 and i < n);
    i += n;
    E ret = laz[i];
    while(i > 0){
      i /= 2;
      ret = h(ret,laz[i]);
    }
    return ret;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

