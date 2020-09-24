#include <iostream>
#include <vector>
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for(int i = 0; i < N; ++i){
    cin >> A[i];
  }
  CumSum cumSum(A);
  while(Q--){
    int l, r;
    cin >> l >> r;
    cout << cumSum.getsum(l,r) << '\n';
  }
}
