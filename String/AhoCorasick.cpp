#include <array>
#include <cassert>
#include <vector>
#include <queue>
#include <numeric>

#include "Trie.cpp"

template<typename T, int alphabetSize, T min_element>
class AhoCorasick {

  Trie<T,alphabetSize,min_element> trie;
  std::vector<int> suffix_cnt, failure;
  const int root_idx;
  const int num_pattern;

  void construct_failure(){
    std::queue<int> que;
    failure[root_idx] = root_idx;
    for(int i = 0; i < alphabetSize; ++i){
      if(trie[root_idx][i] == -1) continue;
      que.emplace(trie[root_idx][i]);
      failure[trie[root_idx][i]] = root_idx;
    }

    while(que.size()){
      int v = que.front();
      que.pop();
      suffix_cnt[v] += suffix_cnt[failure[v]];
      for(int i = 0; i < alphabetSize; ++i){
        if(trie[v][i] == -1) continue;
        que.push(trie[v][i]);
        int f = failure[v];
        while(f != -1 and trie[f][i] == -1){
          f = failure[f];
          if(f == root_idx) break;
        }
        failure[trie[v][i]] = (f == -1 or trie[f][i] == -1) ? root_idx : trie[f][i];
      }
    }
  }

public:

  AhoCorasick(const std::vector<std::string>& pattern)
    : trie(), suffix_cnt(), failure(), root_idx(0), num_pattern(pattern.size()) {
    vector<int> idx;
    for(const auto& p : pattern){
      idx.emplace_back(trie.add(p));
    }
    failure.resize(trie.size(),-1);
    suffix_cnt.resize(trie.size());
    for(auto e : idx)
      ++suffix_cnt[e];
    construct_failure();
  }

  int root(){ return root_idx; }

  std::pair<int,int> move(int cur, T c){
    int i = c - min_element;
    int nxt = cur;
    while(trie[nxt][i] == -1){
      if(nxt == root_idx) break;
      nxt = failure[nxt];
    }
    if(trie[nxt][i] >= 0) nxt = trie[nxt][i];
    else nxt = failure[nxt];
    return std::pair(suffix_cnt[nxt],nxt);
  }
};

