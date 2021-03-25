#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#include "DataStructure/BinaryTrie.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  BinaryTrie<int,30> binTrie;
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
//     ans += binTrie.count_geq(K);
//     binTrie.xor_all(A[i]);
//     binTrie.insert(A[i]);
//   }
//   cout << ans << endl;
// }
