#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>
#include <utility>

template<typename Tree>
class QueryOnRootedTree {
  Tree T;
  int r;
  std::vector<int> L, R;
  void build(){
    int t = 0;
    dfs(r,-1,t);
  }
  void dfs(int v, int p, int& t){
    L[v] = t++;
    for(auto u : T[v]){
      if(u == p) continue;
      dfs(u,v,t);
    }
    R[v] = t;
  }
public:
  QueryOnRootedTree(Tree T, int r=0) : T(T), r(r), L(T.size()), R(T.size()) {
    build();
  }
  std::vector<int> idx(){
    std::vector<int> ret(T.size());
    for(size_t i = 0; i < T.size(); ++i){
      ret[L[i]] = i;
    }
    return ret;
  }
  std::pair<int,int> subtree_of(int v){
    return std::pair(L[v],R[v]);
  }
};

#include <vector>
#include <cassert>

template<typename T>
struct BIT{//0-indexed
private:
  std::vector<T> data;
  const int n;
public:
  BIT(int sz) : data(sz+1,0), n(sz) {}

  T sum(size_t i) const noexcept {//sum[0,i)
    //++i;
    T s = 0;
    while(i > 0){
      s += data[i];
      i -= i&(-i);
    }
    return s;
  }

  T sum(size_t i, size_t j) const noexcept {// sum[i,j)
    return sum(j) - sum(i);
  }

  void add(int i, T x) noexcept {
    ++i;
    assert(i > 0);
    while(i <= n){
      data[i] += x;
      i += i&(-i);
    }
  }
};


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
  for(int i = 1; i < n; ++i){
    int p;
    cin >> p;
    G[p].emplace_back(i);
  }
  QueryOnRootedTree Q(G,0);
  BIT<long long> bit(n);
  auto idx = Q.idx();
  for(int i = 0; i < n; ++i){
    bit.add(i,A[idx[i]]);
  }
  while(q--){
    int t, u;
    cin >> t >> u;
    auto [l,r] = Q.subtree_of(u);
    if(t){
      cout << bit.sum(l,r) << '\n';
    }else{
      long long x;
      cin >> x;
      bit.add(l,x);
    }
  }
}
