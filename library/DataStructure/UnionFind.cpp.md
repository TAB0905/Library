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


# :heavy_check_mark: DataStructure/UnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 15:40:50+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj_DSL_1_A.test.cpp.html">test/aoj_DSL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>

struct UnionFind{
  std::vector<int> data;
  UnionFind(int n) : data(n, -1) {}
  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
      if(data[y] < data[x]) std::swap(x,y);
      data[x] += data[y];//高さを更新
      data[y] = x;//親を更新
    }
    return x != y;
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int find(int x){
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind.cpp"
#include <vector>

struct UnionFind{
  std::vector<int> data;
  UnionFind(int n) : data(n, -1) {}
  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
      if(data[y] < data[x]) std::swap(x,y);
      data[x] += data[y];//高さを更新
      data[y] = x;//親を更新
    }
    return x != y;
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int find(int x){
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

