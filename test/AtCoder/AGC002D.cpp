// problem https://atcoder.jp/contests/agc002/tasks/agc002_d

#include <iostream>

#include "DataStructure/PartiallyPersistentUnionFind.cpp"

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  PartiallyPersistentUnionFind uf(n);
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    --a,--b;
    uf.unite(a,b);
  }
  int q;
  cin >> q;
  while(q--){
    int x, y, z;
    cin >> x >> y >> z;
    --x,--y;
    int ok = m+1, ng = 0;
    while(abs(ok-ng) > 1){
      int t = (ok+ng)/2;
      int s = uf.size(t,x) + uf.size(t,y) - (uf.same(t,x,y) ? uf.size(t,x) : 0);
      if(s >= z) ok = t;
      else ng = t;
    }
    cout << ok << '\n';
  }
}
