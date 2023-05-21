#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <algorithm>
#include <iostream>
#include <tuple>
#include "Datastructure/UndoableUnionFind.cpp"
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  vector<vector<tuple<int,int,int>>> Q(q+1);
  vector<vector<tuple<int,int,int>>> G(q+1);
  for(int i = 1; i <= q; ++i){
    int t, k, u, v;
    cin >> t >> k >> u >> v;
    ++k;
    if(t){
      Q[k].emplace_back(i,u,v);
    }else{
      G[k].emplace_back(i,u,v);
    }
  }
  vector<tuple<int,int>> ans;
  UndoableUnionFind uf(n);
  auto rec = [&](auto&& rec, int v) -> void {
    for(auto [i,a,b]: Q[v]){
      ans.emplace_back(i,uf.same(a,b));
    }
    for(auto [u,a,b]: G[v]){
      uf.unite(a,b);
      rec(rec,u);
      uf.undo();
    }
  };
  rec(rec,0);
  sort(ans.begin(),ans.end());
  for(auto [i,a]: ans)
    cout << a << '\n';
}
