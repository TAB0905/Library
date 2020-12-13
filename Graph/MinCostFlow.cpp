#include <cassert>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <limits>

template<typename capacity_t, typename cost_t>
struct MinCostFlowGraph {
    
private:

  struct edge {
    int to;
    capacity_t cap;
    cost_t cost;
    int r_idx;
    edge(int t, capacity_t cap, cost_t cost, int r) :
      to(t), cap(cap), cost(cost), r_idx(r) {}
  };

  std::vector<std::vector<edge>> G;
  int sz;

  std::vector<cost_t> calc_dag_potential(int from){
    std::queue<int> Q;
    Q.emplace(from);
    std::vector<cost_t> ret(sz, std::numeric_limits<cost_t>::max()/2);
    ret[from] = 0;
    std::vector<int> d_in(sz,0);
    for(int i = 0; i < sz; ++i){
      for(auto e : G[i]){
        if(e.cap <= 0) continue;
        ++d_in[e.to];
      }
    }
    while(Q.size()){
      auto v = Q.front();
      Q.pop();
      for(auto e : G[v]){
        if(!e.cap) continue;
        int v_ = e.to;
        ret[v_] = std::min(ret[v_],ret[v]+e.cost);
        --d_in[v_];
        if(!d_in[v_])
          Q.emplace(v_);
      }
    }
    return ret;
  }

public:
  MinCostFlowGraph(int n) : G(n), sz(n) {}

  void add_edge(int from, int to, capacity_t cap, cost_t cost){
    int i = G[to].size(), i_ = G[from].size();
    G[from].emplace_back(to,cap,cost,i);
    G[to].emplace_back(from,0,-cost,i_);
  }
  
  cost_t min_cost_flow(int from, int to, capacity_t f){
    cost_t ans = 0;
    const cost_t INF = std::numeric_limits<cost_t>::max()/2;
    std::vector<cost_t> potential(sz);
    while(f > 0){
      std::vector<cost_t> dist(sz,INF);
      dist[from] = 0;
      std::vector<int> prev_v(sz,-1);
      std::vector<int> prev_e(sz,-1);
      std::priority_queue<std::pair<cost_t,int>, std::vector<std::pair<cost_t,int>>, std::greater<>> pq;
      pq.emplace(0,from);
      while(pq.size()){
        auto [d, v] = pq.top();
        pq.pop();
        if(dist[v] < d) continue;
        for(size_t i = 0; i < G[v].size(); ++i){
          const auto& e = G[v][i];
          if(e.cap == 0) continue;
          int v_ = e.to;
          cost_t d_ = d + e.cost + potential[v] - potential[v_];
          if(dist[v_] <= d_)
            continue;
          dist[v_] = d_;
          prev_v[v_] = v;
          prev_e[v_] = i;
          pq.emplace(d_,e.to);
        }
      }
      if(dist[to] >= INF) return -1;
      for(int i = 0; i < sz; ++i)
        potential[i] += dist[i];
      int v = to;
      capacity_t flow = f;
      while(v != from){
        int v_ = prev_v[v];
        flow = std::min(flow,G[v_][prev_e[v]].cap);
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
