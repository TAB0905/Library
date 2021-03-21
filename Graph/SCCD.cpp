#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>

struct SCCDecomposedGraph {
  std::vector<std::vector<int>> dag;
  std::vector<std::vector<int>> scc;
  std::vector<int> cmp;
};

SCCDecomposedGraph scc_decompose(const std::vector<std::vector<int>>& G){
  const int n = G.size();
  std::vector<int> ord(n,-1), low(n), st;
  SCCDecomposedGraph ret;
  int num_scc = 0;
  ret.cmp.resize(n,-1);
  auto dfs = [&](auto&& dfs, int v, int& tm) -> void {
    low[v] = tm;
    ord[v] = tm;
    ++tm;
    st.emplace_back(v);
    for(auto u : G[v]){
      if(ord[u] < 0){
        dfs(dfs,u,tm);
        low[v] = std::min(low[v],low[u]);
      }else if(ret.cmp[u] < 0){
        low[v] = std::min(low[v],ord[u]);
      }
    }
    if(ord[v] == low[v]){
      ret.scc.push_back({});
      while(true){
        const int u = st.back();
        st.pop_back();
        ret.scc.back().emplace_back(u);
        ret.cmp[u] = num_scc;
        if(v == u) break;
      }
      ++num_scc;
    }
  };
  int tm = 0;
  for(int i = 0; i < n; ++i){
    if(ord[i] < 0) dfs(dfs,i,tm);
  }
  reverse(ret.scc.begin(),ret.scc.end());
  for(int i = 0; i < n; ++i){
    ret.cmp[i] = num_scc - 1 - ret.cmp[i];
  }
  ret.dag.resize(num_scc);
  for(int i = 0; i < n; ++i){
    int v = ret.cmp[i];
    for(auto j : G[i]){
      int u = ret.cmp[j];
      if(v != u){
        ret.dag[v].emplace_back(u);
      }
    }
    sort(ret.dag[v].begin(),ret.dag[v].end());
    ret.dag[v].erase(unique(ret.dag[v].begin(),ret.dag[v].end()),ret.dag[v].end());
  }
  return ret;
}

