#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <iomanip>
#include <vector>

#include "Graph/SCCD.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
  }
  auto ret = scc_decompose(G);
  cout << ret.scc.size() << '\n';
  for(auto &scc : ret.scc){
    cout << scc.size();
    for(auto e : scc)
      cout << ' ' << e;
    cout << '\n';
  }
}
