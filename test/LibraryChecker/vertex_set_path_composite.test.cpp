#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "Graph/HLD.cpp"
#include "DataStructure/SegmentTree.cpp"
#include "Math/modint.cpp"

#include <utility>
using namespace std;

int main(){
  using mint = modint<998244353>;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<pair<mint, mint>> A;
  for(int i = 0; i < n; ++i){
    mint a, b;
    cin >> a >> b;
    A.emplace_back(a,b);
  }
  vector<vector<int>> G(n);
  for(int i = 0; i+1 < n; ++i){
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  QueryOnRootedTree hld(G);
  auto idx = hld.idx();
  vector<pair<mint, mint>> B(n);
  vector<int> inv(n);
  for(int i = 0; i < n; ++i){
    B[i] = A[idx[i]];
    inv[idx[i]] = i;
  }

  auto f = [](pair<mint, mint> a, pair<mint, mint> b){
    auto [x,y] = a;
    auto [z,w] = b;
    return pair(z*x,z*y+w);
  };

  auto r = [](pair<mint, mint> a, pair<mint, mint> b){
    auto [x,y] = a;
    auto [z,w] = b;
    return pair(x*z,x*w+y);
  };

  pair<mint,mint> id(1,0);
  SegmentTree F(f,id);
  SegmentTree R(r,id);
  F.build(B);
  R.build(B);
  
  while(q--){
    int t;
    cin >> t;
    if(t){
      int from, to;
      mint x;
      cin >> from >> to >> x;
      auto ret = hld.path(from,to);
      // cerr << from << " -> " << to << " : ";
      pair<mint,mint> ans(1,0);
      for(auto [l,r]: ret){
        auto t = (l < r ? F.query(l,r+1) : R.query(r,l+1));
        ans = f(ans,t);
      }
      auto [a,b] = ans;
      cout << a*x+b << '\n';
    }else{
      int p;
      mint c, d;
      cin >> p >> c >> d;
      p = inv[p];
      F.set_val(p,pair(c,d));
      R.set_val(p,pair(c,d));
    }
  }
}
