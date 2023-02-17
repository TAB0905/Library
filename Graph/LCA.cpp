#include <cassert>
#include <vector>

struct LCA {
private:
  std::vector<std::vector<int>> G;
  size_t n, m;
  std::vector<std::vector<int>> A;
  std::vector<int> D;
  void dfs(int v, int p){
    for(auto v_ : G[v]){
      if(v_ == p) continue;
      A[v_][0] = v;
      D[v_] = D[v]+1;
      dfs(v_,v);
    }
  }
  void build(int r){
    dfs(r,-1);
    A[r][0] = r;
    for(size_t i = 1; i < m; ++i){
      for(size_t j = 0; j < n; ++j){
        A[j][i] = A[A[j][i-1]][i-1];
      }
    }
   }
public:
  LCA(const std::vector<std::vector<int>>& Tree, int r) : G(Tree), n(Tree.size()), m(1), D(n,0) {
    size_t t = 1;
    while(t < n) ++m, t *= 2;
    A = std::vector<std::vector<int>>(n,std::vector<int>(m,-1));
    build(r);
  }
  size_t lca(int u, int v){
    if(D[u] < D[v]) std::swap(u,v);

    for(size_t i = m-1; i < m; --i){
      size_t u_ = A[u][i];
      if(D[u_] < D[v]) continue;
      u = u_;
    }

    if(u == v) return u;
    assert(D[u] == D[v]);
    for(size_t i = m-1; i < m; --i){
      if(A[u][i] != A[v][i])
        u = A[u][i], v = A[v][i];
    }
    return A[u][0];
  }
  int dist(int s, int t){
    int l = lca(s,t);
    return D[s] + D[t] - 2*D[l];
  }
  int jump(int s, int t, int i){ // s から t に i 辺進んだ頂点 (なければ -1 )
    int l = lca(s,t);
    int d = dist(s,t);
    if(d < i) return -1;
    if(i > D[s]-D[l]){
      std::swap(s,t);
      i = d - i;
    }
    for(size_t j = m-1; j < m; --j){
      if(i>>j&1)
        s = A[s][j];
    }
    return s;
  }
};
