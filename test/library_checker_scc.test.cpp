#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>

#include "../Graph/SCCD.cpp"
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
  }
  vector<int> C = scc_decompose(G);
  int n = *max_element(C.begin(), C.end()) + 1;
  vector<vector<int>> V(n);
  for(int i = 0; i < N; ++i){
    V[C[i]].emplace_back(i);
  }
  cout << n << '\n';
  for(auto v : V){
    cout << v.size();
    for(auto e : v)
      cout << ' ' << e;
    cout << '\n';
  }
}
