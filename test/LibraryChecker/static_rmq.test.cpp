#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>
#include "DataStructure/SegmentTree.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for(int i = 0; i < N; ++i){
    cin >> A[i];
  }
  const int INF = 1e9;
  SegmentTree rmq([](int a, int b){return min(a,b);},INF);
  rmq.build(A);
  while(Q--){
    int l, r;
    cin >> l >> r;
    cout << rmq.query(l,r) << '\n';
  }
}
