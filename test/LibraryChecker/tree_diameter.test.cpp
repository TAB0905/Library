#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include <vector>

#include "Graph/TreeDiameter.cpp"

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<pair<long long,int>>> G(n);
  for(int i = 0; i+1 < n; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    G[a].emplace_back(c,b);
    G[b].emplace_back(c,a);
  }
  auto [diam,path] = tree_diameter(G);
  cout << diam << ' ' << path.size() << '\n';
  for(auto e : path){
    cout << e << ' ';
  }
  cout << '\n';
}
