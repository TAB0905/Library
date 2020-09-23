#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#include <iostream>
#include "Graph/FordFulkerson.cpp"
using namespace std;

int main(){
  int V, E;
  cin >> V >> E;
  FlowGraph<long long> G(V);
  for(int i = 0; i < E; ++i){
    int u, v, c;
    cin >> u >> v >> c;
    G.add_edge(u,v,c);
  }
  cout << G.max_flow(0,V-1) << endl;
}
