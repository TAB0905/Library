#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = 1e18;

vector<long long> dijkstra(const vector<vector<pair<long long,int>>>& G, int s){
  const int n = G.size();
  vector<ll> D(n,INF);
  D[s] = 0;
  vector<int> pre(n,-1);
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
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

int main(){
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  vector<vector<pair<ll,int>>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    G[a].emplace_back(c,b);
  }
  auto [D, pre] = dijkstra(G,s);
  if(D[t] >= INF){
    cout << -1 << endl;
    return 0;
  }
  auto P = restor_shortest_path(pre,s,t);
  cout << D[t] << " " << P.size()-1 << endl;
  for(int i = 0; i+1 < P.size(); ++i)
    cout << P[i] << " " << P[i+1] << "\n";
}
