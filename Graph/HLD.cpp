#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

template<typename Tree>
class QueryOnRootedTree {
  const int n;
  const int r;
  std::vector<int> L, R;
  std::vector<int> depth, parent, A;
  void build(Tree& T){
    A[r] = r;
    reorder(T,r,-1);
    int t = 0;
    dfs(T,r,-1,t);
  }
  int reorder(Tree& T, int v, int p){
    std::vector<int> subtree_size;
    int s = 1;
    parent[v] = p;
    for(auto u: T[v]){
      if(u == p){
        subtree_size.emplace_back(0);
        continue;
      }
      int s_ = reorder(T,u,v);
      subtree_size.emplace_back(s_);
      s += s_;
    }
    if(T[v].size() > 1){
      int heavy = std::max_element(subtree_size.begin(),subtree_size.end()) - subtree_size.begin();
      std::swap(T[v][0],T[v][heavy]);
    }
    return s;
  }
  void dfs(const Tree& T, int v, int p, int& t){
    L[v] = t++;
    // std::cerr << p << ' ' << v << '\n';
    for(auto u: T[v]){
      if(u == p) continue;
      A[u] = (u == T[v][0] ? A[v] : u);
      depth[u] = depth[v] + 1;
      dfs(T,u,v,t);
    }
    R[v] = t;
  }
public:
  QueryOnRootedTree(Tree T, int r=0) :
    n(T.size()), r(r), L(n), R(n), depth(n), parent(n), A(n) {
    build(T);
  }
  std::vector<int> idx(){
    std::vector<int> ret(n);
    for(size_t i = 0; i < n; ++i){
      ret[L[i]] = i;
    }
    return ret;
  }
  std::pair<int,int> subtree(int v){
    return std::pair(L[v],R[v]);
  }
  std::vector<std::pair<int,int>> path(int from, int to){ // [li, ri]
    std::vector<std::pair<int,int>> up, down;
    int u = from, v = to;
    // std::cerr << u << ' ' << A[u] << ' ' << v << ' ' << A[v] << '\n';
    while(A[u] != A[v]){
      if(depth[A[u]] < depth[A[v]]){
        down.emplace_back(L[A[v]], L[v]);
        v = parent[A[v]];
      }else{
        up.emplace_back(L[u], L[A[u]]);
        u = parent[A[u]];
      }
    }
    // std::cerr << u << ' ' << A[u] << ' ' << v << ' ' << A[v] << '\n';
    if(depth[u] <= depth[v]){
      up.emplace_back(L[u],L[v]);
    }
    if(depth[v] < depth[u]){
      up.emplace_back(L[u],L[v]);
    }
    up.insert(up.end(),down.rbegin(),down.rend());
    return up;
  }
  void debug(){
    std::cerr << "n: " << n << '\n';
    std::cerr << "A: ";
    for(int i = 0; i < n; ++i)
      std::cerr << A[i] << ' ';
    std::cerr << '\n';
  }
};
