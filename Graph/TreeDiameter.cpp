#include <vector>
#include <utility>

template<typename T>
std::pair<T,std::vector<int>> tree_diameter(const std::vector<std::vector<std::pair<T,int>>>& G){
  const int n = G.size();
  std::vector<T> D(n);
  auto rec = [&](auto&&rec, int v, int p) -> std::pair<T,int> {
    D[v] = 0;
    std::pair<T,int> ret(0,v);
    for(auto [d,u] : G[v]){
      if(u == p) continue;
      auto r = rec(rec,u,v);
      r.first += d;
      ret = std::max(ret,r);
      D[v] = std::max(D[v],D[u]+d);
    }
    return ret;
  };
  int v = 0;
  v = rec(rec,v,-1).second;
  auto [r,u] = rec(rec,v,-1);
  std::vector<int> path(1,u);
  T t = 0;
  while(t < r){
    for(auto [d,w] : G[u]){
      if(D[w] == t+d){
        path.emplace_back(w);
        u = w;
        t += d;
        break;
      }
    }
  }
  return {r,path};
}
