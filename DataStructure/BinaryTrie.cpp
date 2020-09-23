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
    for(int i = len-1; i >= 0; --i){//root -> leaf
      int b = (x>>i)&1;
      assert(v->children[b] != nullptr);
      v = v->children[b];
      v->size -= cnt;
    }
    assert(v->children[0] == nullptr);
    assert(v->children[1] == nullptr);
    for(int i = 0; i < len; ++i){//leaf -> root
      if(v->size) break;
      assert(v != root);
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
      assert(v->children[b] != nullptr);
      ret <<= 1;
      ret |= b;
      v = v->children[b];
    }
    assert(v->size >= k);

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

// ARC033-C
// https://atcoder.jp/contests/arc033/tasks/arc033_3
// #include <iostream>
// using namespace std;

// void ARC033C(){
//   BinaryTrie<32> bt;
//   int Q;
//   cin >> Q;
//   while(Q--){
//     int t, x;
//     cin >> t >> x;
//     if(t == 1){
//       bt.insert(x);
//     }else{
//       auto y = bt.kth_element(x);
//       cout << y << "\n";
//       bt.erase(y);
//     }
//   }
// }


// Educational Codeforces Round 12 - E
// https://codeforces.com/group/zX1lm3q5cU/contest/665/problem/E
// #include <iostream>
// #include <vector>
// using namespace std;

// void edu12E(){
//   int N, K;
//   cin >> N >> K;

//   BinaryTrie<int,30> binTrie;

//   vector<int> A(N+1);
//   for(int i = 0; i < N; ++i){
//     cin >> A[i+1];
//     A[i+1] ^= A[i];
//   }

//   long long ans = 0;
//   for(int i = 0; i <= N; ++i){
//     binTrie.xor_all(A[i]);
//     ans += binTrie.count_leq(K);
//     binTrie.xor_all(A[i]);
//     binTrie.insert(A[i]);
//   }
//   cout << ans << endl;
// }
