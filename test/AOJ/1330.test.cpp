#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330&lang=jp"

#include <vector>
#include <iostream>
#include <iomanip>
#define ll long long
using namespace std;

#include "DataStructure/WeightedUnionFind.cpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int N, M;
  while(cin >> N >> M, N){
    WeightedUnionFind wuf(N);
    char q;
    int a, b;
    ll int w;
    for(int i = 0; i < M; ++i){
      cin >> q >> a >> b;
      --a;--b;
      if(q == '!'){
        cin >> w;
        wuf.unite(a,b,w);
      }else{
        //cout << wuf.find(a) << " " << wuf.find(b) << endl;
        if(wuf.same(a,b)){
          cout << wuf.rel_weight(b) - wuf.rel_weight(a) << '\n';
        }else{
          cout << "UNKNOWN" << '\n';
        }
      }
    }
  }
  return 0;
}
