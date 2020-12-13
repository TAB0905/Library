#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"

#include <iostream>
#include <iomanip>
#include "DataStructure/UnionFind.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  while(q--){
    int c, x, y;
    cin >> c >> x >> y;
    if(c){
      cout << uf.same(x,y) << "\n";
    }else{
      uf.unite(x,y);
    }
  }
}

