#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <iomanip>
#include <utility>
#include "DataStructure/Segmenttree.cpp"
#include "Math/modint.cpp"

using namespace std;

int main(){
  using mint = modint<998244353>;
  
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  using T = pair<mint,mint>;
  auto f = [](T a, T b) -> T {
    return {a.first*b.first,a.second*b.first+b.second};
  };
  T ti(1,0);
  
  SegmentTree st(f,ti);

  int n, q;
  cin >> n >> q;
  vector<T> A(n);
  for(int i = 0; i < n; ++i){
    mint a, b;
    cin >> a >> b;
    A[i] = {a,b};
  }
  st.build(A);
  
  while(q--){
    int t;
    cin >> t;
    if(t){
      int l, r, x;
      cin >> l >> r >> x;
      auto p = st.query(l,r);
      cout << p.first*x+p.second << '\n';
    }else{
      int p, c, d;
      cin >> p >> c >> d;
      st.set_val(p,T(c,d));
    }
  }
}
