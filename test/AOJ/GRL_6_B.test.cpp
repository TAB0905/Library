#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"

#include <iostream>
#include <iomanip>
#include "Graph/MinCostFlow.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, f;
  cin >> n >> m >> f;
  MinCostFlowGraph<long long, long long> G(n);
  for(int i = 0; i < m; ++i){
    long long u, v, c, d;
    cin >> u >> v >> c >> d;
    G.add_edge(u,v,c,d);
  }
  cout << G.min_cost_flow(0,n-1,f) << endl;
}
