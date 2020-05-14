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


# :heavy_check_mark: Graph/MinCostFlow.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/MinCostFlow.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 11:55:44+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj_GRL_6_B.test.cpp.html">test/aoj_GRL_6_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cassert>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <limits>
using namespace std;

struct MinCostFlowGraph {
private:
  using ll = long long;
  struct edge {
    int to;
    ll cap, cost;
    int r_idx;
    edge(int t, ll cap, ll cost, int r) :
      to(t), cap(cap), cost(cost), r_idx(r) {}
  };
  vector<vector<edge>> G;
  int sz;

public:
  MinCostFlowGraph(int n) : G(n), sz(n) {}

  void add_edge(int from, int to, ll cap, ll cost){
    int i = G[to].size(), i_ = G[from].size();
    G[from].emplace_back(to,cap,cost,i);
    G[to].emplace_back(from,0,-cost,i_);
  }
  
  ll min_cost_flow(int from, int to, ll f){
    ll ans = 0;
    const ll INF = numeric_limits<ll>::max();
    vector<ll> potential(sz);
    while(f > 0){
      vector<ll> dist(sz,INF);
      dist[from] = 0;
      vector<int> prev_v(sz,-1);
      vector<int> prev_e(sz,-1);
      priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
      pq.emplace(0,from);
      while(pq.size()){
        auto [d, v] = pq.top();
        // d *= -1;
        pq.pop();
        if(dist[v] < d) continue;
        for(size_t i = 0; i < G[v].size(); ++i){
          const auto& e = G[v][i];
          if(e.cap == 0) continue;
          int v_ = e.to;
          ll d_ = d + e.cost + potential[v] - potential[v_];
          if(dist[v_] <= d_)
            continue;
          dist[v_] = d_;
          prev_v[v_] = v;
          prev_e[v_] = i;
          // pq.emplace(-d_,e.to);
          pq.emplace(d_,e.to);
        }
      }
      if(dist[to] >= INF) return -1;
      for(int i = 0; i < sz; ++i)
        potential[i] += dist[i];
      int v = to;
      ll flow = f;
      while(v != from){
        int v_ = prev_v[v];
        flow = min(flow,G[v_][prev_e[v]].cap);
        v = v_;
      }
      v = to;
      while(v != from){
        int v_ = prev_v[v];
        auto& e = G[v_][prev_e[v]];
        e.cap -= flow;
        ans += flow*e.cost;
        G[v][e.r_idx].cap += flow;
        v = v_;
      }
      f -= flow;
    }
    return ans;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/MinCostFlow.cpp"
#include <cassert>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <limits>
using namespace std;

struct MinCostFlowGraph {
private:
  using ll = long long;
  struct edge {
    int to;
    ll cap, cost;
    int r_idx;
    edge(int t, ll cap, ll cost, int r) :
      to(t), cap(cap), cost(cost), r_idx(r) {}
  };
  vector<vector<edge>> G;
  int sz;

public:
  MinCostFlowGraph(int n) : G(n), sz(n) {}

  void add_edge(int from, int to, ll cap, ll cost){
    int i = G[to].size(), i_ = G[from].size();
    G[from].emplace_back(to,cap,cost,i);
    G[to].emplace_back(from,0,-cost,i_);
  }
  
  ll min_cost_flow(int from, int to, ll f){
    ll ans = 0;
    const ll INF = numeric_limits<ll>::max();
    vector<ll> potential(sz);
    while(f > 0){
      vector<ll> dist(sz,INF);
      dist[from] = 0;
      vector<int> prev_v(sz,-1);
      vector<int> prev_e(sz,-1);
      priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
      pq.emplace(0,from);
      while(pq.size()){
        auto [d, v] = pq.top();
        // d *= -1;
        pq.pop();
        if(dist[v] < d) continue;
        for(size_t i = 0; i < G[v].size(); ++i){
          const auto& e = G[v][i];
          if(e.cap == 0) continue;
          int v_ = e.to;
          ll d_ = d + e.cost + potential[v] - potential[v_];
          if(dist[v_] <= d_)
            continue;
          dist[v_] = d_;
          prev_v[v_] = v;
          prev_e[v_] = i;
          // pq.emplace(-d_,e.to);
          pq.emplace(d_,e.to);
        }
      }
      if(dist[to] >= INF) return -1;
      for(int i = 0; i < sz; ++i)
        potential[i] += dist[i];
      int v = to;
      ll flow = f;
      while(v != from){
        int v_ = prev_v[v];
        flow = min(flow,G[v_][prev_e[v]].cap);
        v = v_;
      }
      v = to;
      while(v != from){
        int v_ = prev_v[v];
        auto& e = G[v_][prev_e[v]];
        e.cap -= flow;
        ans += flow*e.cost;
        G[v][e.r_idx].cap += flow;
        v = v_;
      }
      f -= flow;
    }
    return ans;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

