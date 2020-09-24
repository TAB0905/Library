#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "DataStructure/UnionFind.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(N);
  while(Q--){
    int t, u, v;
    cin >> t >> u >> v;
    if(t){
      cout << uf.same(u,v) << '\n';
    }else{
      uf.unite(u,v);
    }
  }
}
