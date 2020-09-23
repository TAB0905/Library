#include <array>
#include <cassert>
#include <memory>

template<int len>
class BinaryTrie {
private:
  struct Node {
    int size;
    Node* parent;
    Node* children[2];
    Node() : size(0), parent(nullptr), children{nullptr,nullptr} {}
  };
  Node* root;
  long long xor_value;
public:
  BinaryTrie() : root(new Node), xor_value(0) {}
  void insert(long long x, long long cnt=1){
    x ^= xor_value;
    Node* v = root;
    v->size += cnt;
    for(int i = len-1; i >= 0; --i){
      int b = (x>>i)&1;
      if(v->children[b] == nullptr){
        v->children[b] = new Node;
        v->children[b]->parent = v;
      }
      v = v->children[b];
      v->size += cnt;
    }
  }
  void erase(long long x, long long cnt=1){
    x ^= xor_value;
    Node* v = root;
    cnt = std::min(cnt,count(x));
    if(!cnt) return;
    for(int i = len-1; i >= 0; --i){
      int b = (x>>i)&1;
      assert(v->children[b] != nullptr);
      v = v->children[b];
      v->size -= cnt;
    }
    for(int i = 0; i < len; ++i){
      if(v->size) break;
      auto p = v->parent;
      int b = (x>>i)&1;
      p->children[b] = nullptr;
      v->parent = nullptr;
      v = p;
    }
  }
  long long count(long long x){
    Node* v = root;
    for(int i = len-1; i >= 0; --i){
      int b = (x>>i)&1;
      if(v->children[b] == nullptr)
        return 0;
      v = v->children[b];
    }
    return v->size;
  }
  // long long lower_bound();
  // long long upper_bound();
  long long kth_element(int k){
    Node* v = root;
    long long ret = 0;
    for(int i = 0; i < len; ++i){
      int b = 0;
      if(v->children[0] == nullptr or
         v->children[0]->size < k){
        b = 1;
        if(v->children[0] != nullptr)
          k -= v->children[0]->size;
      }
      ret *= 2;
      ret += b;
      v = v->children[b];
    }
    return ret;
  }
};

#include <iostream>
using namespace std;

int main(){
  BinaryTrie<32> bt;
  int Q;
  cin >> Q;
  while(Q--){
    int t, x;
    cin >> t >> x;
    if(t == 1){
      bt.insert(x);
    }else{
      auto y = bt.kth_element(x);
      cout << y << "\n";
      bt.erase(y);
    }
  }
}
