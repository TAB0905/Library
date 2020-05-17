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


# :heavy_check_mark: test/library_checker_two_edge_connected_components.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/library_checker_two_edge_connected_components.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-17 17:36:08+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_edge_connected_components">https://judge.yosupo.jp/problem/two_edge_connected_components</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/Lowlink.cpp.html">Graph/Lowlink.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <cstdio>
#include <vector>
#include <utility>
#include "Graph/Lowlink.cpp"
using namespace std;

int main(){
  int n, m;
  scanf("%d %d",&n,&m);

  vector<pair<int,int>> E;
  for(int i = 0; i < m; ++i){
    int x, y;
    scanf("%d %d",&x,&y);
    E.emplace_back(x,y);
  }

  auto G = TwoEdgeConnectedComponentsDeconposition(E,n);

  printf("%zu\n",G.components.size());
  for(auto c : G.components){
    printf("%zu ",c.size());
    for(size_t i = 0; i < c.size(); ++i)
      printf("%d%c",c[i],(i+1 < c.size() ? ' ' : '\n'));
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/library_checker_two_edge_connected_components.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <cstdio>
#include <vector>
#include <utility>
#line 1 "Graph/Lowlink.cpp"
#include <algorithm>
#include <cassert>
#line 5 "Graph/Lowlink.cpp"
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
  auto lowlink = [&](auto lowlink, int v, int edge_idx, int& t) -> void {
                   st.push(v);
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
    lowlink(lowlink,i,-1,t);

    std::vector<int> cc;
    int idx = ret.components.size();
    while(st.size()){
      cc.push_back(st.top());
      node_idx[st.top()] = idx;
      st.pop();
    }
    ret.components.push_back(cc);
  }
  
  // fprintf(stderr,"node_idx\n");
  // for(int i = 0; i < n; ++i){
  //   fprintf(stderr,"%d ",node_idx[i]);
  // }
  // fprintf(stderr,"\n");

  // fprintf(stderr,"bridge\n");
  // for(auto b : ret.bridge)
  //   fprintf(stderr,"(%d,%d)\n",b.first,b.second);

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

#line 7 "test/library_checker_two_edge_connected_components.test.cpp"
using namespace std;

int main(){
  int n, m;
  scanf("%d %d",&n,&m);

  vector<pair<int,int>> E;
  for(int i = 0; i < m; ++i){
    int x, y;
    scanf("%d %d",&x,&y);
    E.emplace_back(x,y);
  }

  auto G = TwoEdgeConnectedComponentsDeconposition(E,n);

  printf("%zu\n",G.components.size());
  for(auto c : G.components){
    printf("%zu ",c.size());
    for(size_t i = 0; i < c.size(); ++i)
      printf("%d%c",c[i],(i+1 < c.size() ? ' ' : '\n'));
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

