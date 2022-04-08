#define PROBLEM "https://judge.yosupo.jp/problem/k_shortest_walk"

#include <iostream>
#include <vector>

#include "Graph/Eppstein.cpp"

using namespace std;

int main(){
  int n, m, s, t, k;
  cin >> n >> m >> s >> t >> k;
  vector<tuple<long long, int, int>> E;
  for(int i = 0; i < m; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    E.emplace_back(c,u,v);
  }
  const long long INF = 1e18;
  auto ans = Eppstein<long long>(E,n,s,t,k,INF);
  for(int i = 0; i < k; ++i){
    if(i < ans.size()) cout << ans[i] << '\n';
    else cout << -1 << '\n';
  }
}
