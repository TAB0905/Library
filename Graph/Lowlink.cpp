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


  ret.graph.resize(n_);
  for(auto b : ret.bridge){
    int u = M[uf.find(b.first)], v = M[uf.find(b.second)];
    ret.graph[u].emplace_back(v);
    ret.graph[v].emplace_back(u);
  }
  return ret;
}

