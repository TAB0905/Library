#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <iomanip>

#include "DataStructure/BIT.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int n, q;
  cin >> n >> q;
  BIT<long long> bit(n);
  for(int i = 0; i < n; ++i){
    long long a;
    cin >> a;
    bit.add(i,a);
  }
  while(q--){
    int t;
    cin >> t;
    if(t){
      int l, r;
      cin >> l >> r;
      cout << bit.sum(l,r) << '\n';
    }else{
      int p, x;
      cin >> p >> x;
      bit.add(p,x);
    }
  }
}
