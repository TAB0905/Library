#include <algorithm>
#include <cassert>

template<typename T, int len>
class BinaryTrie {
private:
  struct Node {
    T size;
    Node* parent;
    Node* children[2];
    Node() : size(0), parent(nullptr), children{nullptr,nullptr} {}
  };
  
  Node* root;
  T xor_value;
public:
  BinaryTrie() : root(new Node), xor_value(0) {}
  constexpr void insert(T x, T cnt=1) noexcept {
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
  constexpr void erase(T x, T cnt=1) noexcept {
    Node* v = root;
    cnt = std::min(cnt,count(x));
    x ^= xor_value;
    if(!cnt) return;
    v->size -= cnt;
    for(int i = len-1; i >= 0; --i){
      int b = (x>>i)&1;
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
  constexpr T count(T x) const noexcept {
    Node* v = root;
    x ^= xor_value;
    for(int i = len-1; i >= 0; --i){
      int b = (x>>i)&1;
      if(v->children[b] == nullptr)
        return 0;
      v = v->children[b];
    }
    return v->size;
  }
  constexpr T kth_element(int k) const noexcept {// 1-indexed
    Node* v = root;
    T ret = 0;
    for(int i = len-1; i >= 0; --i){
      int b = (xor_value>>i)&1;
      if(v->children[b] == nullptr or
         v->children[b]->size < k){
        if(v->children[b] != nullptr)
          k -= v->children[b]->size;
        b ^= 1;
      }
      ret <<= 1;
      ret |= b;
      v = v->children[b];
    }

    return ret^xor_value;
  }
  constexpr T count_leq(T x) const noexcept {
    Node* v = root;
    T ret = 0;
    for(int i = len-1; i >= 0; --i){
      int b = ((xor_value^x)>>i)&1;
      int t = (x>>i)&1;
      if((!t) and v->children[b^1] != nullptr)
        ret += v->children[b^1]->size;
      if(v->children[b] == nullptr){
        return ret;
      }
      v = v->children[b];
    }
    return ret+v->size;
  }
  constexpr void xor_all(T x) noexcept {
    xor_value ^= x;
  }
};
