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

