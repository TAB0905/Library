#include <cassert>
#include <vector>
#include <array>
#include <iostream>

template<typename T, int alphabetSize, T min_element>
class PalindromicTree {

  struct Node {
    const int suffix_link;
    std::array<int,alphabetSize> ch;
    const int len;
    int cnt;

    Node(int suffix_link, int len) :
      suffix_link(suffix_link), ch(), len(len), cnt(1) {
      std::fill(ch.begin(), ch.end(), -1);
    };

    // void dump(){
    //   std::cerr << "cnt               : " << cnt << "\n";
    //   std::cerr << "suffix_link       : " << suffix_link << "\n";
    //   for(int j = 0; j < alphabetSize; ++j){
    //     if(ch[j] >= 0){
    //       std::cout << std::string(1,'a'+j) << " " << ch[j] << std::endl;
    //     }
    //   }
    //   std::cerr << "\n";
    // }
  };

public:

  std::vector<Node> nodes;
  std::vector<T> dat;
  int len;
  std::vector<int> A;

  PalindromicTree() : nodes({Node(-1,-1), Node(0,0)}), dat(), len(0), A() {}

  bool push_back(T c){
    dat.emplace_back(c);
    ++len;
    int parent_idx = A.empty() ? 0 : A.back();
    // std::cerr << parent_idx << " " << len-2-nodes[parent_idx].len << std::endl;
    while(len-2-nodes[parent_idx].len < 0 or dat[len-2-nodes[parent_idx].len] != c){
      parent_idx = nodes[parent_idx].suffix_link;
    }

    int v_idx = nodes[parent_idx].ch[c-min_element];

    if(v_idx != -1){
      ++nodes[v_idx].cnt;
      A.emplace_back(v_idx);
      return false;
    }

    int suffix_link = nodes[parent_idx].suffix_link;
    while(suffix_link >= 0 and (len-2-nodes[suffix_link].len < 0 or dat[len-2-nodes[suffix_link].len] != c)){
      suffix_link = nodes[suffix_link].suffix_link;
    }


    if(suffix_link >= 0 and len-2-nodes[suffix_link].len >= 0 and dat[len-2-nodes[suffix_link].len] == c){
      assert(nodes[suffix_link].ch[c-min_element] >= 0);
      suffix_link = nodes[suffix_link].ch[c-min_element];
    }

    if(suffix_link < 0) suffix_link = 1;
    
    v_idx = nodes.size();
    nodes[parent_idx].ch[c-min_element] = v_idx;
    nodes.emplace_back(suffix_link,nodes[parent_idx].len+2);
    A.emplace_back(v_idx);
    
    return true;
  }

  size_t num_unique_palindrome() const noexcept {
    return nodes.size()-2;
  }
};

#include <iostream>
using namespace std;

void solve(){
  string s, t;
  cin >> s >> t;
  const int alphabet_size = 26;
  PalindromicTree<char,alphabet_size,'A'> S, T;

  for(auto c : s)
    S.push_back(c);
  for(auto c : t)
    T.push_back(c);
  
  for(int i = S.nodes.size()-1; i >= 0; --i){
    int sl = S.nodes[i].suffix_link;
    if(sl < 0) continue;
    S.nodes[sl].cnt += S.nodes[i].cnt;
  }
  for(int i = T.nodes.size()-1; i >= 0; --i){
    int sl = T.nodes[i].suffix_link;
    if(sl < 0) continue;
    T.nodes[sl].cnt += T.nodes[i].cnt;
  }
  
  auto solve = [&](auto&& solve, const int& vs, const int& vt) -> long long {
    long long ret = 0;
    if(S.nodes[vs].len > 0){
      long long cnt = (long long)(S.nodes[vs].cnt)*T.nodes[vt].cnt;
      ret += cnt;
    }
    for(int i = 0; i < alphabet_size; ++i){
      int us = S.nodes[vs].ch[i], ut = T.nodes[vt].ch[i];
      if(us < 0 or ut < 0)
        continue;
      ret += solve(solve,us,ut);
    }
    return ret;
  };

  long long ans = solve(solve,0,0) + solve(solve,1,1);
  cout << ans << endl;
}

// void debug(){
//   string s;
//   cin >> s;
//   const int alphabet_size = 26;
//   PalindromicTree<char,alphabet_size,'a'> eerTree;
//   for(auto c : s){
//     eerTree.push_back(c);
//   }
//   for(size_t i = 0; i < eerTree.nodes.size(); ++i){
//     cerr << "Node " << i << "\n";
//     eerTree.nodes[i].dump();
//   }
//   cout << eerTree.num_unique_palindrome() << endl;
// }

int main(){
  solve();
  // debug();
}
