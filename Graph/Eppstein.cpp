#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>

#include "DataStructure/LeftistHeap.cpp"

template<typename T>
bool chmin(T& x, const T y){
  if(x <= y) return false;
  x = y;
  return true;
}

template<typename T>
std::vector<T> Eppstein(const std::vector<std::tuple<T,int,int>>& E, int n, int s, int t, int k, T INF){
  using heap = PersistentLeftistHeap<std::tuple<T,int>>;

  const int m = E.size();
  std::vector R(n,std::vector<std::tuple<T,int,int>>()); // {cost,to,edge_id}
  auto G = R;
  for(int i = 0; i < m; ++i){
    auto [c,from,to] = E[i];
    R[to].emplace_back(c,from,i);
    G[from].emplace_back(c,to,i);
  }
  
  // calculating potential & shortest path tree by Dijkstra algorithm

  std::vector<T> potential(n,INF);
  potential[t] = 0;

  std::vector<int> parent(n,-1), tree_edge(n,-1);
  std::vector<std::vector<int>> child(n);
  
  {
    std::priority_queue<std::tuple<T,int>,std::vector<std::tuple<T,int>>,std::greater<>> Q;
    Q.emplace(T(),t);

    while(Q.size()){
      auto [d,v] = Q.top();
      Q.pop();
      if(potential[v] < d) continue;
      for(auto [c,u,id] : R[v]){
        if(chmin(potential[u],d+c)){
          Q.emplace(d+c,u);
          tree_edge[u] = id;
          potential[u] = d+c;
          parent[u] = v;
        }
      }
    }
  }
  
  for(int i = 0; i < n; ++i){
    if(parent[i] == -1) continue;
    child[parent[i]].emplace_back(i);
  }

  std::vector<heap> H(n); // cost, to
  // bfs for constructing H_g
  {
    std::queue<int> Q;
    Q.emplace(t);
    while(Q.size()){
      auto v = Q.front();
      Q.pop();
      if(parent[v] != -1) H[v] = H[v].meld(H[parent[v]]);
      for(auto [c,u,id] : G[v]){
        if(tree_edge[v] == id) continue;
        H[v] = H[v].insert(std::tuple(c+potential[u]-potential[v],u));
      }
      for(auto u : child[v]){
        Q.emplace(u);
      }
    }
  }

  std::vector<T> ans;
  {
    using node_ptr = typename heap::node_ptr;
    std::priority_queue<std::tuple<T,node_ptr>,std::vector<std::tuple<T,node_ptr>>,std::greater<>> Q;

    heap init;
    init = init.insert(std::tuple(potential[s],s));

    Q.emplace(potential[s],init.root);

    while(Q.size()){
      auto [d,h] = Q.top();
      Q.pop();
      if(d >= INF) break;
      ans.emplace_back(d);
      if(ans.size() == k) break;
      if(h->l != nullptr){
        Q.emplace(d + std::get<0>(h->l->val) - std::get<0>(h->val), h->l);
      }
      if(h->r != nullptr){
        Q.emplace(d + std::get<0>(h->r->val) - std::get<0>(h->val), h->r);
      }
      if(H[std::get<1>(h->val)].root != nullptr){
        auto h_ = H[std::get<1>(h->val)].root;
        Q.emplace(d + std::get<0>(h_->val), h_);
      }
    }
  }
  return ans;
}
