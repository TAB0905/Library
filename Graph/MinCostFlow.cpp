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

  vector<T> calc_dag_potential(int from){
    queue<int> Q;
    Q.emplace(from);
    vector<T> ret(sz,numeric_limits<T>::max());
    ret[from] = 0;
    vector<int> d_in(sz,0);
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
        ret[v_] = min<T>(ret[v_],ret[v]+e.cost);
        --d_in[v_];
        if(!d_in[v_])
          Q.emplace(v_);
      }
    }
    return ret;
  }

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
