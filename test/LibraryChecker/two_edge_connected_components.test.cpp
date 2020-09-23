#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <cstdio>
#include <vector>
#include <utility>
#include "Graph/Lowlink.cpp"
using namespace std;

int main(){
  int n, m;
  scanf("%d %d",&n,&m);

  vector<pair<int,int>> E;
  for(int i = 0; i < m; ++i){
    int x, y;
    scanf("%d %d",&x,&y);
    E.emplace_back(x,y);
  }

  auto G = TwoEdgeConnectedComponentsDeconposition(E,n);

  printf("%zu\n",G.components.size());
  for(auto c : G.components){
    printf("%zu ",c.size());
    for(size_t i = 0; i < c.size(); ++i)
      printf("%d%c",c[i],(i+1 < c.size() ? ' ' : '\n'));
  }
}
