#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja"

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include "Graph/LowLink.cpp"
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> E;
  for(int i = 0; i < m; ++i){
    int u, v;
    cin >> u >> v;
    E.emplace_back(u,v);
  }
  auto ans = TwoEdgeConnectedComponentsDeconposition(E,n).articulationPoints;
  sort(ans.begin(),ans.end());
  // ans.erase(unique(ans.begin(),ans.end()),ans.end());
  for(size_t i = 0; i < ans.size(); ++i){
    // cout << ans[i] << (i+1 < ans.size() ? ' ' : '\n');
    cout << ans[i] << '\n';
  }
}
