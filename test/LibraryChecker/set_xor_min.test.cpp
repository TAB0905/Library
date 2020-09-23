#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#include "DataStructure/BinaryTrie.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  BinaryTrie<int,31> binTrie;
  int Q;
  cin >> Q;
  while(Q--){
    int t, x;
    cin >> t >> x;
    if(t == 0){
      if(binTrie.count(x)) continue;
      binTrie.insert(x);
    }
    if(t == 1){
      binTrie.erase(x);
    }
    if(t == 2){
      binTrie.xor_all(x);
      cout << binTrie.kth_element(1) << "\n";
      binTrie.xor_all(x);
    }
  }
}
