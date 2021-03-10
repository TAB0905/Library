#include <iostream>
#include <vector>
#include <queue>

std::vector<int> toposort(std::vector<std::vector<int>> &G){
  size_t N = G.size();
  std::vector<int> ret, d_in(N,0);
  for(size_t i = 0; i < N; ++i)
    for(size_t j = 0; j < G[i].size(); ++j)
      ++d_in[G[i][j]];
  // std::queue<int> wait;
  std::vector<int> wait;
  for(size_t i = 0; i < N; ++i)
    if(!d_in[i]) wait.emplace_back(i);
  while(!wait.empty()){
    int v = wait.back();
    wait.pop_back();
    ret.emplace_back(v);
    for(size_t i = 0; i < G[v].size(); ++i){
      int v_ = G[v][i];
      --d_in[v_];
      if(!d_in[v_]) wait.emplace_back(v_);
    }
  }
  return ret;
}

