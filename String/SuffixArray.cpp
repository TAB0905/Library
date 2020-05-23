#include <cassert>
#include <iostream>
#include <vector>

//構築 : O(|S|log|S|)
struct SuffixArray {
private:
  std::string s;
  int size;
  void constructLCPArray(){
    for(int i = 0; i < size; ++i){
      rank[SA[i]] = i;
    }
    int l = 0;
    for(int i = 0; i < size; ++i){
      int idx = rank[i];
      int p1 = SA[idx];
      if(idx+1 == size){
        l = 0;
        LCP[idx] = l;
        continue;
      }
      int p2 = SA[idx+1];
      while(std::max(p1,p2)+l < size and s[p1+l] == s[p2+l]) ++l;
      LCP[idx] = l;
      --l;
      l = std::max(l,0);
    }
  }
public:
  std::vector<int> SA, LCP, rank;
  SuffixArray(std::string s_) : s(s_), size(s_.length()+1), SA(size+1), LCP(size+1), rank(size+1) {
    s += "$";
  }
  void construct(){
    std::vector<int> cnt(std::max(256,size),0);
    for(auto e : s){
      ++cnt[e];
    }
    for(size_t i = 1; i < cnt.size(); ++i)
      cnt[i] += cnt[i-1];
    std::vector<int> p(size);
    for(int i = 0; i < size; ++i){
      p[--cnt[s[i]]] = i;
    }
    std::vector<int> c(size);
    c[p[0]] = 0;
    for(int i = 1; i < size; ++i){
      c[p[i]] = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);
    }

    for(int k = 1; k < size; k *= 2){
      std::vector<int> p_(size), c_(size);
      for(int j = 0; j < size; ++j){
        p_[j] = p[j] - k;
        if(p_[j] < 0) p_[j] += size;
      }
      std::fill(cnt.begin(),cnt.end(),0);
      
      int max_e = 0;
      for(auto e : c){
        ++cnt[e], max_e = std::max(max_e,e);
      }
      for(int i = 0; i < max_e; ++i){
        cnt[i+1] += cnt[i];
      }
      
      for(int i = size-1; i >= 0; --i){
        p[--cnt[c[p_[i]]]] = p_[i];
      }
      
      c_[p[0]] = 0;
      int classes = 1;
      for(int i = 1; i < size; ++i){
        if((c[p[i]] != c[p[i-1]]) or (c[(p[i]+k)%size] != c[(p[i-1]+k)%size]))
          ++classes;
        c_[p[i]] = classes-1;
      }
      std::swap(c,c_);
    }

    SA = p;
    constructLCPArray();
  }
};

