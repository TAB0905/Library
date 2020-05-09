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


# :heavy_check_mark: Graph/FordFulkerson.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/FordFulkerson.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 17:45:06+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj_GRL_6_A_FordFulkerson.test.cpp.html">test/aoj_GRL_6_A_FordFulkerson.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <vector>

template<typename T>
struct FlowGraph {
private:
  struct edge {
    const int to;
    T cap;
    const int r_idx;
    edge(int t, T c, int i) :
      to(t), cap(c), r_idx(i) {}
  };

  std::vector<std::vector<edge>> G;

  T dfs(int v, int sink, T min_cap, std::vector<bool>& visited){
    visited[v] = true;
    if(v == sink) return min_cap;
    for(auto& e : G[v]){
      if(e.cap == T()) continue;
      if(visited[e.to]) continue;
      T min_cap_ = std::min(min_cap,e.cap);
      T flowed = dfs(e.to,sink,min_cap_, visited);
      if(flowed == T()) continue;
      e.cap -= flowed;
      G[e.to][e.r_idx].cap += flowed;
      return flowed;
    }
    return T();
  }
  
public:
  FlowGraph(size_t n) : G(n) {}
  void add_edge(int from, int to, T cap){
    int i = G[to].size(), i_ = G[from].size();
    G[from].emplace_back(to,cap,i);
    G[to].emplace_back(from,T(),i_);
  }
  T max_flow(int from, int to){
    T ret = 0, INF = 1e9;
    while(true){
      std::vector<bool> visited(G.size());
      T f = dfs(from,to,INF,visited);
      if(f == T()) break;
      ret += f;
    }
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/FordFulkerson.cpp"
#include <algorithm>
#include <vector>

template<typename T>
struct FlowGraph {
private:
  struct edge {
    const int to;
    T cap;
    const int r_idx;
    edge(int t, T c, int i) :
      to(t), cap(c), r_idx(i) {}
  };

  std::vector<std::vector<edge>> G;

  T dfs(int v, int sink, T min_cap, std::vector<bool>& visited){
    visited[v] = true;
    if(v == sink) return min_cap;
    for(auto& e : G[v]){
      if(e.cap == T()) continue;
      if(visited[e.to]) continue;
      T min_cap_ = std::min(min_cap,e.cap);
      T flowed = dfs(e.to,sink,min_cap_, visited);
      if(flowed == T()) continue;
      e.cap -= flowed;
      G[e.to][e.r_idx].cap += flowed;
      return flowed;
    }
    return T();
  }
  
public:
  FlowGraph(size_t n) : G(n) {}
  void add_edge(int from, int to, T cap){
    int i = G[to].size(), i_ = G[from].size();
    G[from].emplace_back(to,cap,i);
    G[to].emplace_back(from,T(),i_);
  }
  T max_flow(int from, int to){
    T ret = 0, INF = 1e9;
    while(true){
      std::vector<bool> visited(G.size());
      T f = dfs(from,to,INF,visited);
      if(f == T()) break;
      ret += f;
    }
    return ret;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

