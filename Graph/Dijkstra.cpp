#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using ll = long long;
const ll INF = 1e18;

std::pair<std::vector<ll>,std::vector<int>> dijkstra(const std::vector<std::vector<std::pair<ll,int>>>& G, int s){
  const int n = G.size();
  std::vector<ll> D(n,INF);
  D[s] = 0;
  std::vector<int> pre(n,-1);
  std::priority_queue<std::pair<ll,ll>, std::vector<std::pair<ll,ll>>, std::greater<std::pair<ll,ll>>> pq;
  pq.emplace(0,s);
  while(pq.size()){
    auto [d, v] = pq.top();
    pq.pop();
    if(D[v] < d) continue;
    for(auto [c, v_] : G[v]){
      ll d_ = d + c;
      if(D[v_] <= d_) continue;
      D[v_] = d_;
      pre[v_] = v;
      pq.emplace(d_,v_);
    }
  }
  return {D,pre};
}

std::vector<int> restor_shortest_path(const std::vector<int>& pre, int s, int t){
  std::vector<int> P;
  while(t != s){
    P.emplace_back(t);
    t = pre[t];
  }
  P.emplace_back(s);
  reverse(P.begin(), P.end());
  return P;
}

