#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "Graph/LCA.cpp"
#include <vector>
#include <iostream>
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> G(N);
  for(int i = 1; i < N; ++i){
    int p;
    cin >> p;
    G[i].emplace_back(p);
    G[p].emplace_back(i);
  }
  LCA lca(G,0);
  while(Q--){
    int u, v;
    cin >> u >> v;
    cout << lca.query(u,v) << '\n';
  }
}
