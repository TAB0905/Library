#include <utility>
#include <iostream>
#include <vector>

long long solve(const std::vector<long long>& G, int v, long long int t=0){
  const int n = G.size();
  if(v >= n or t == (1LL<<n) - 1LL) return 0;

  long long ret = 0;
  if(!(t>>v & 1)){
    long long t_ = t | (1LL<<v);
    t_ |= G[v];
    int v_ = v + 1;
    while(t_>>v_ & 1) ++v_;
    ret = solve(G,v_,t_)|1LL<<v;
    if(__builtin_popcountll(t^t_) <= 2) return ret; // d(v) <= 1
  }
  int v_ = v + 1;
  while(t>>v_ & 1) ++v_;
  t |= 1LL<<v;
  long long ret_ = solve(G,v_,t);
  if(__builtin_popcountll(ret) < __builtin_popcountll(ret_))
    std::swap(ret,ret_);
  return ret;
}
