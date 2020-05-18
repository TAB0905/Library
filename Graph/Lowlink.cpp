#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
#include <stack>

struct DecomposedGraph {
  std::vector<std::vector<int>> graph;
  std::vector<std::pair<int,int>> bridge;
  std::vector<std::vector<int>> components;
  std::vector<int> affiliation;
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

  ret.affiliation = node_idx;
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

