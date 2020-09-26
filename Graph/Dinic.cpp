#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

template<typename T>
struct Dinic {
private:
  struct edge {
    const int to;
    T cap;
    const int r_idx;
    edge(int t, T c, int i) :
      to(t), cap(c), r_idx(i) {}
  };

  std::vector<std::vector<edge>> G;

  std::vector<int> bfs(int source){
    const int INF = 1e9;

    std::vector<int> dist(G.size(),INF);
    dist[source] = 0;
    
    std::queue<int> Q;
    Q.emplace(source);

    while(not Q.empty()){
      int v = Q.front();
      Q.pop();
      int d = dist[v];
      for(auto& e : G[v]){
        if(not e.cap)
          continue;
        if(dist[e.to] <= d+1)
          continue;
        dist[e.to] = d+1;
        Q.emplace(e.to);
      }
    }
    return dist;
  }

  T dfs(int v, int sink, T min_cap, const std::vector<int>& dist, std::vector<size_t>& edge_idx){
    if(v == sink) return min_cap;
    for(size_t& i = edge_idx[v]; i < G[v].size(); ++i){
      auto& e = G[v][i];
      if(e.cap == T()) continue;
      if(dist[e.to] != dist[v]+1) continue;

      T min_cap_ = std::min(min_cap,e.cap);
      T flowed = dfs(e.to,sink,min_cap_,dist,edge_idx);
      if(flowed == T()) continue;
      e.cap -= flowed;
      G[e.to][e.r_idx].cap += flowed;
      return flowed;
    }
    return T();
  }

  T flow;
public:
  Dinic(size_t n) : G(n), flow(0) {}

  void add_edge(int from, int to, T cap){
    int i = G[to].size(), i_ = G[from].size();
    G[from].emplace_back(to,cap,i);
    G[to].emplace_back(from,T(),i_);
  }

  T max_flow(int from, int to){

    while(true){
      std::vector<int> dist = bfs(from);

      if(dist[to] >= (int)G.size())
        break;

      std::vector<size_t> edge_idx(G.size());
      while(true){
        const T INF = std::numeric_limits<T>::max();
        T f = dfs(from,to,INF,dist,edge_idx);
        if(f == T()) break;
        flow += f;
      }
    }
    
    return flow;
  }
};

