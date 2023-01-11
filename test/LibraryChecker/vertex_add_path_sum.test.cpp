#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "Graph/HLD.cpp"
#include "DataStructure/SegmentTree.cpp"

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<long long> A(n);
  for(int i = 0; i < n; ++i)
    cin >> A[i];
  vector<vector<int>> G(n);
  for(int i = 0; i+1 < n; ++i){
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  QueryOnRootedTree hld(G);
  auto idx = hld.idx();
  // for(auto e: idx)
  //   cerr << e << ' ';
  // cerr << endl;
  // hld.debug();
  vector<long long> B(n), R(n);
  for(int i = 0; i < n; ++i){
    B[i] = A[idx[i]];
    R[idx[i]] = i;
  }
  SegmentTree range_sum([](long long a, long long b){return a+b;},0LL);
  range_sum.build(B);

  while(q--){
    int t;
    cin >> t;
    if(t){
      int from, to;
      cin >> from >> to;
      auto ret = hld.path(from,to);
      // cerr << from << " -> " << to << " : ";
      long long ans = 0;
      for(auto [l,r]: ret){
        if(r < l) swap(l,r);
        // cerr << "(" << l << ", " << r << ") ";
        ans += range_sum.query(l,r+1);
      }
      // cerr << " = ";
      cout << ans << '\n';
    }else{
      int p;
      long long x;
      cin >> p >> x;
      p = R[p];
      long long ap = range_sum.query(p,p+1);
      range_sum.set_val(p,ap+x);
    }
  }
}
