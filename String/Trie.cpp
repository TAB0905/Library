#include <algorithm>
#include <array>
#include <vector>

template<typename T, int alphabetSize, T min_element>
class Trie {

  struct node {
    std::array<int,alphabetSize> nxt;
    const int parent;
    node(int p) : nxt(), parent(p) {
      std::fill(nxt.begin(),nxt.end(),-1);
    }
    int operator[](int i) const {
      return nxt[i];
    }
  };

  const int root_idx;
  std::vector<node> nodes;
  
public:

  Trie() : root_idx(0), nodes(1,node(-1)) {}

  int add(const std::string& s){
    int v_id = root_idx;
    for(const char& c : s){
      if(nodes[v_id][c-min_element] == -1){
        nodes[v_id].nxt[c-min_element] = nodes.size();
        nodes.emplace_back(v_id);
      }
      v_id = nodes[v_id][c-min_element];
    }
    return v_id;
  }

  node& operator[](size_t i){
    return nodes[i];
  }

  int size(){
    return nodes.size();
  }
};

