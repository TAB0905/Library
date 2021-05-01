#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#include <iostream>
#include <vector>
#include "Graph/TopologicalSort.cpp"

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector< vector<int> > G(N);
  for(int i = 0; i < M; ++i){
    int s, t;
    cin >> s >> t;
    G[s].emplace_back(t);
  }
  vector<int> order = toposort(G);
  for(int i = 0; i < N; ++i)
    cout << order[i] << endl;
  return 0;
}
