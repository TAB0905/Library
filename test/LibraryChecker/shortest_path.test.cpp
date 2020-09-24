#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "Graph/Dijkstra.cpp"

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

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
