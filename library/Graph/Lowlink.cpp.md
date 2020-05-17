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


# :heavy_check_mark: Graph/Lowlink.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/Lowlink.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-17 17:03:21+09:00




## Depends on

* :heavy_check_mark: <a href="../DataStructure/UnionFind.cpp.html">DataStructure/UnionFind.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/library_checker_two_edge_connected_components.test.cpp.html">test/library_checker_two_edge_connected_components.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include "DataStructure/UnionFind.cpp"

struct DecomposedGraph {
  std::vector<std::vector<int>> graph;
  std::vector<std::pair<int,int>> bridge;
  std::vector<std::vector<int>> components;
};

DecomposedGraph TwoEdgeConnectedComponentsDeconposition(const std::vector<std::pair<int,int>>& E, int n){
  int m = E.size();
  
  struct edge {
    int to, idx;
    edge(int to, int idx) : to(to), idx(idx) {}
  };

  std::vector<std::vector<edge>> G(n);
  for(int i = 0; i < m; ++i){
    const auto& e = E[i];
    G[e.first].emplace_back(e.second,i);
    G[e.second].emplace_back(e.first,i);
  }

  std::vector<int> low(n), ord(n,-1);
  int t = 0;
  auto lowlink = [&](auto lowlink, int v, int edge_idx, int& t) -> void {
                   ord[v] = t++;
                   low[v] = ord[v];
                   for(const auto& e : G[v]){
                     if(e.idx == edge_idx) continue;
                     int v_ = e.to, idx = e.idx;
                     if(ord[v_] >= 0){
                       low[v] = std::min(low[v],ord[v_]);
                     }else{
                       lowlink(lowlink,v_,idx,t);
                       low[v] = std::min(low[v],low[v_]);
                     }
                   }
                 };
  
  for(int i = 0; i < n; ++i){
    if(ord[i] >= 0) continue;
    lowlink(lowlink,i,-1,t);
  }
  
  DecomposedGraph ret;

  UnionFind uf(n);
  for(auto [u, v] : E){
    if(ord[u] > ord[v]) std::swap(u,v);
    if(ord[u] < low[v]){
      ret.bridge.emplace_back(u,v);
    }else{
      uf.unite(u,v);
    }
  }

  std::vector<int> P(n);
  for(int i = 0; i < n; ++i)
    P[i] = uf.find(i);

  std::sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());

  int n_ = P.size();
  std::map<int,int> M;

  for(int i = 0; i < n_; ++i){
    M[P[i]] = i;
  }

  ret.components.resize(n_);
  for(int i = 0; i < n; ++i){
    ret.components[M[uf.find(i)]].push_back(i);
  }
  
  ret.graph.resize(n_);
  for(auto b : ret.bridge){
    int u = M[uf.find(b.first)], v = M[uf.find(b.second)];
    ret.graph[u].emplace_back(v);
    ret.graph[v].emplace_back(u);
  }
  return ret;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/Lowlink.cpp"
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#line 2 "DataStructure/UnionFind.cpp"

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

#line 8 "Graph/Lowlink.cpp"

struct DecomposedGraph {
  std::vector<std::vector<int>> graph;
  std::vector<std::pair<int,int>> bridge;
  std::vector<std::vector<int>> components;
};

DecomposedGraph TwoEdgeConnectedComponentsDeconposition(const std::vector<std::pair<int,int>>& E, int n){
  int m = E.size();
  
  struct edge {
    int to, idx;
    edge(int to, int idx) : to(to), idx(idx) {}
  };

  std::vector<std::vector<edge>> G(n);
  for(int i = 0; i < m; ++i){
    const auto& e = E[i];
    G[e.first].emplace_back(e.second,i);
    G[e.second].emplace_back(e.first,i);
  }

  std::vector<int> low(n), ord(n,-1);
  int t = 0;
  auto lowlink = [&](auto lowlink, int v, int edge_idx, int& t) -> void {
                   ord[v] = t++;
                   low[v] = ord[v];
                   for(const auto& e : G[v]){
                     if(e.idx == edge_idx) continue;
                     int v_ = e.to, idx = e.idx;
                     if(ord[v_] >= 0){
                       low[v] = std::min(low[v],ord[v_]);
                     }else{
                       lowlink(lowlink,v_,idx,t);
                       low[v] = std::min(low[v],low[v_]);
                     }
                   }
                 };
  
  for(int i = 0; i < n; ++i){
    if(ord[i] >= 0) continue;
    lowlink(lowlink,i,-1,t);
  }
  
  DecomposedGraph ret;

  UnionFind uf(n);
  for(auto [u, v] : E){
    if(ord[u] > ord[v]) std::swap(u,v);
    if(ord[u] < low[v]){
      ret.bridge.emplace_back(u,v);
    }else{
      uf.unite(u,v);
    }
  }

  std::vector<int> P(n);
  for(int i = 0; i < n; ++i)
    P[i] = uf.find(i);

  std::sort(P.begin(), P.end());
  P.erase(unique(P.begin(), P.end()), P.end());

  int n_ = P.size();
  std::map<int,int> M;

  for(int i = 0; i < n_; ++i){
    M[P[i]] = i;
  }

  ret.components.resize(n_);
  for(int i = 0; i < n; ++i){
    ret.components[M[uf.find(i)]].push_back(i);
  }
  
  ret.graph.resize(n_);
  for(auto b : ret.bridge){
    int u = M[uf.find(b.first)], v = M[uf.find(b.second)];
    ret.graph[u].emplace_back(v);
    ret.graph[v].emplace_back(u);
  }
  return ret;
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

