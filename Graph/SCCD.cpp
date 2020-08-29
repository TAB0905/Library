#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>

std::vector<int> scc_decompose(const std::vector<std::vector<int>>& G){
  int n = G.size();
  std::vector<int> P;
  {
    std::vector<int> visited(n,false);
    auto dfs = [&](auto dfs, int v) -> void {
      visited[v] = true;
      for(auto v_ : G[v]){
        if(visited[v_]) continue;
        dfs(dfs,v_);
      }
      P.push_back(v);
    };
    for(int i = 0; i < n; ++i){
      if(visited[i]) continue;
      dfs(dfs,i);
    }
    reverse(P.begin(), P.end());
  }
  std::vector<std::vector<int>> G_rev(n);
  for(int i = 0; i < n; ++i){
    for(auto j : G[i])
      G_rev[j].push_back(i);
  }
  std::vector<int> A(n,-1);
  int t = 0;
  auto dfs = [&](auto dfs, int v) -> void {
    A[v] = t;
    for(auto v_ : G_rev[v]){
      if(A[v_] >= 0) continue;
      dfs(dfs,v_);
    }
  };
  for(auto v : P){
    if(A[v] >= 0) continue;
    dfs(dfs,v);
    ++t;
  }
  return A;
}

