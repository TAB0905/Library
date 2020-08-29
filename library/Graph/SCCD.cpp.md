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


# :heavy_check_mark: Graph/SCCD.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/SCCD.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 04:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/library_checker_scc.test.cpp.html">test/library_checker_scc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>

std::vector<int> scc_decompose(const std::vector<std::vector<int>>& G){
  int n = G.size();
  std::vector<int> P;
  {
    std::vector<int> visited(n,false);
    auto dfs = [&](auto dfs, int v) -> void {
      visited[v] = true;
      for(auto v_ : G[v]){
        if(visited[v_]) continue;
        dfs(dfs,v_);
      }
      P.push_back(v);
    };
    for(int i = 0; i < n; ++i){
      if(visited[i]) continue;
      dfs(dfs,i);
    }
    reverse(P.begin(), P.end());
  }
  std::vector<std::vector<int>> G_rev(n);
  for(int i = 0; i < n; ++i){
    for(auto j : G[i])
      G_rev[j].push_back(i);
  }
  std::vector<int> A(n,-1);
  int t = 0;
  auto dfs = [&](auto dfs, int v) -> void {
    A[v] = t;
    for(auto v_ : G_rev[v]){
      if(A[v_] >= 0) continue;
      dfs(dfs,v_);
    }
  };
  for(auto v : P){
    if(A[v] >= 0) continue;
    dfs(dfs,v);
    ++t;
  }
  return A;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/SCCD.cpp"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>

std::vector<int> scc_decompose(const std::vector<std::vector<int>>& G){
  int n = G.size();
  std::vector<int> P;
  {
    std::vector<int> visited(n,false);
    auto dfs = [&](auto dfs, int v) -> void {
      visited[v] = true;
      for(auto v_ : G[v]){
        if(visited[v_]) continue;
        dfs(dfs,v_);
      }
      P.push_back(v);
    };
    for(int i = 0; i < n; ++i){
      if(visited[i]) continue;
      dfs(dfs,i);
    }
    reverse(P.begin(), P.end());
  }
  std::vector<std::vector<int>> G_rev(n);
  for(int i = 0; i < n; ++i){
    for(auto j : G[i])
      G_rev[j].push_back(i);
  }
  std::vector<int> A(n,-1);
  int t = 0;
  auto dfs = [&](auto dfs, int v) -> void {
    A[v] = t;
    for(auto v_ : G_rev[v]){
      if(A[v_] >= 0) continue;
      dfs(dfs,v_);
    }
  };
  for(auto v : P){
    if(A[v] >= 0) continue;
    dfs(dfs,v);
    ++t;
  }
  return A;
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

