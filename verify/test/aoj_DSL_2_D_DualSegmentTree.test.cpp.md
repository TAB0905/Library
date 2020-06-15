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


# :heavy_check_mark: test/aoj_DSL_2_D_DualSegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj_DSL_2_D_DualSegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 02:17:44+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/DualSegmentTree.cpp.html">DataStructure/DualSegmentTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"

#include <array>
#include <vector>
#include <cstdio>
#include <climits>

#include "DataStructure/DualSegmentTree.cpp"

using namespace std;

int main(){
  using E = int;
  E ei = numeric_limits<E>::max();

  auto f = [&](E a, E b){
             if(b == ei) return a;
             return b;
           };
  
  int n, q;
  scanf("%d %d",&n,&q);

  DualSegmentTree st(f,ei);
  st.build(n);
  
  while(q--){
    int t;
    scanf("%d",&t);
    if(t){
      int i;
      scanf("%d",&i);
      printf("%d\n",st[i]);
    }else{
      int l, r;
      E x;
      scanf("%d %d %d",&l,&r,&x);
      ++r;
      st.update(l,r,x);
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj_DSL_2_D_DualSegmentTree.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"

#include <array>
#include <vector>
#include <cstdio>
#include <climits>

#line 1 "DataStructure/DualSegmentTree.cpp"
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#line 6 "DataStructure/DualSegmentTree.cpp"
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
#line 9 "test/aoj_DSL_2_D_DualSegmentTree.test.cpp"

using namespace std;

int main(){
  using E = int;
  E ei = numeric_limits<E>::max();

  auto f = [&](E a, E b){
             if(b == ei) return a;
             return b;
           };
  
  int n, q;
  scanf("%d %d",&n,&q);

  DualSegmentTree st(f,ei);
  st.build(n);
  
  while(q--){
    int t;
    scanf("%d",&t);
    if(t){
      int i;
      scanf("%d",&i);
      printf("%d\n",st[i]);
    }else{
      int l, r;
      E x;
      scanf("%d %d %d",&l,&r,&x);
      ++r;
      st.update(l,r,x);
    }
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

