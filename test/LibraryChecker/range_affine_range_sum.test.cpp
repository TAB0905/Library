#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <iomanip>
#include <vector>

#include "DataStructure/LazySegmentTree.cpp"
#include "Math/modint.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  using mint = modint<998244353>;
  using T = pair<mint,mint>;
  using E = pair<mint,mint>;

  auto f = [](T a, T b) -> T {
    return {a.first+b.first,a.second+b.second};
  };
  auto g = [](T a, E b) -> T {
    return {a.first*b.first+a.second*b.second,a.second};
  };
  auto h = [](E a, E b) -> E {
    return {a.first*b.first,a.second*b.first+b.second};
  };

  T ti(0,0);
  E ei(1,0);
  
  int n, q;
  cin >> n >> q;
  
  vector<T> A(n);
  for(int i = 0; i < n; ++i){
    int a;
    cin >> a;
    A[i] = {a,1};
  }

  LazySegmentTree st(f,g,h,ti,ei);
  st.build(A);
  
  while(q--){
    int t, l, r;
    cin >> t >> l >> r;
    if(t){
      auto p = st.query(l,r);
      cout << p.first << '\n';
    }else{
      mint b, c;
      cin >> b >> c;
      st.update(l,r,E(b,c));
    }
  }
}
