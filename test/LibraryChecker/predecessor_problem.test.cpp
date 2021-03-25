#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include <iostream>
#include "DataStructure/BinaryTrie.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  BinaryTrie<int,25> binTrie;//2^24 = 16777216 > 1e7 = N_MAX
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for(int i = 0; i < n; ++i){
    if(s[i] == '1')
      binTrie.insert(i);
  }
  while(q--){
    int c, k;
    cin >> c >> k;
    if(c == 0){
      if(binTrie.count(k))
        continue;
      binTrie.insert(k);
    }
    if(c == 1){
      binTrie.erase(k);
    }
    if(c == 2){
      cout << (!!binTrie.count(k)) << '\n';
    }
    if(c == 3){
      if(binTrie.size() == 0){
        cout << -1 << '\n';
        continue;
      }
      int leq_num = binTrie.count_leq(k);
      int max_element = binTrie.kth_element(binTrie.size());
      if(!k){
        cout << binTrie.kth_element(1) << '\n';
      }else if(k > max_element){
        cout << -1 << '\n';
      }else{
        leq_num = binTrie.count_leq(k-1);
        cout << binTrie.kth_element(leq_num+1) << '\n';
      }
    }
    if(c == 4){
      if(binTrie.size() == 0){
        cout << -1 << '\n';
        continue;
      }
      if(binTrie.kth_element(1) > k){
        cout << -1 << '\n';
      }else{
        int leq_num = binTrie.count_leq(k);
        cout << binTrie.kth_element(leq_num) << '\n';
      }
    }
  }
}

