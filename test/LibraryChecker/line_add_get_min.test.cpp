#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include "DataStructure/LineSet.cpp"

using namespace std;

int main(){
  using int128 = __int128_t;
  int N, Q;
  cin >> N >> Q;
  LineSet<int128> cht(1e18);
  for(int i = 0; i < N; ++i){
    long long a, b;
    cin >> a >> b;
    cht.push(a,b);
  }
  while(Q--){
    int t;
    cin >> t;
    if(t){
      long long p;
      cin >> p;
      long long ans = cht.get(p);
      cout << ans << '\n';
    }else{
      long long a, b;
      cin >> a >> b;
      cht.push(a,b);
    }
  }
}
