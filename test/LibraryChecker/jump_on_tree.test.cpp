#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "Graph/LCA.cpp"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> G(N);
  for(int i = 1; i < N; ++i){
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  LCA lca(G,0);
  while(Q--){
    int u, v, i;
    cin >> u >> v >> i;
    cout << lca.jump(u,v,i) << '\n';
  }
}
