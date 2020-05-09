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
