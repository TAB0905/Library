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
    - Last commit date: 2020-05-17 17:48:02+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/library_checker_two_edge_connected_components.test.cpp.html">test/library_checker_two_edge_connected_components.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
#include <stack>

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

  DecomposedGraph ret;
  std::vector<int> low(n), ord(n,-1), node_idx(n,-1);
  std::stack<int> st;
  int t = 0;
  auto lowlink = [&](auto lowlink, int v, int edge_idx) -> void {
                   st.push(v);
                   ord[v] = t++;
                   low[v] = ord[v];
                   for(const auto& e : G[v]){
                     if(e.idx == edge_idx) continue;
                     int v_ = e.to, idx = e.idx;
                     if(ord[v_] >= 0){
                       low[v] = std::min(low[v],ord[v_]);
                     }else{
                       lowlink(lowlink,v_,idx);
                       low[v] = std::min(low[v],low[v_]);
                     }
                     if(ord[v] < low[v_]){// u-v is bridge
                       std::vector<int> cc;
                       int n_idx = ret.components.size();
                       while(true){
                         int tp = st.top();
                         cc.push_back(tp);
                         node_idx[tp] = n_idx;
                         st.pop();
                         if(tp == v_) break;
                       }
                       ret.components.push_back(cc);
                       ret.bridge.push_back(E[idx]);
                     }
                   }
                 };

  for(int i = 0; i < n; ++i){
    if(ord[i] >= 0) continue;
    lowlink(lowlink,i,-1);

    std::vector<int> cc;
    int idx = ret.components.size();
    while(st.size()){
      cc.push_back(st.top());
      node_idx[st.top()] = idx;
      st.pop();
    }
    ret.components.push_back(cc);
  }

  int n_ = ret.components.size();
  ret.graph.resize(n_);
  for(auto b : ret.bridge){
    int u = node_idx[b.first], v = node_idx[b.second];
    assert(u != v);
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
#include <vector>
#include <stack>

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

  DecomposedGraph ret;
  std::vector<int> low(n), ord(n,-1), node_idx(n,-1);
  std::stack<int> st;
  int t = 0;
  auto lowlink = [&](auto lowlink, int v, int edge_idx) -> void {
                   st.push(v);
                   ord[v] = t++;
                   low[v] = ord[v];
                   for(const auto& e : G[v]){
                     if(e.idx == edge_idx) continue;
                     int v_ = e.to, idx = e.idx;
                     if(ord[v_] >= 0){
                       low[v] = std::min(low[v],ord[v_]);
                     }else{
                       lowlink(lowlink,v_,idx);
                       low[v] = std::min(low[v],low[v_]);
                     }
                     if(ord[v] < low[v_]){// u-v is bridge
                       std::vector<int> cc;
                       int n_idx = ret.components.size();
                       while(true){
                         int tp = st.top();
                         cc.push_back(tp);
                         node_idx[tp] = n_idx;
                         st.pop();
                         if(tp == v_) break;
                       }
                       ret.components.push_back(cc);
                       ret.bridge.push_back(E[idx]);
                     }
                   }
                 };

  for(int i = 0; i < n; ++i){
    if(ord[i] >= 0) continue;
    lowlink(lowlink,i,-1);

    std::vector<int> cc;
    int idx = ret.components.size();
    while(st.size()){
      cc.push_back(st.top());
      node_idx[st.top()] = idx;
      st.pop();
    }
    ret.components.push_back(cc);
  }

  int n_ = ret.components.size();
  ret.graph.resize(n_);
  for(auto b : ret.bridge){
    int u = node_idx[b.first], v = node_idx[b.second];
    assert(u != v);
    ret.graph[u].emplace_back(v);
    ret.graph[v].emplace_back(u);
  }
  return ret;
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

