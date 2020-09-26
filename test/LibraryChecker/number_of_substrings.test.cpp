#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include <iostream>
#include <vector>

#include "String/SuffixArray.cpp"

using namespace std;

int main(){
  using ll = long long;
  string s;
  cin >> s;
  SuffixArray sa(s);
  sa.construct();
  int n = s.length();
  ll ans = 0;
  
  for(int i = 1; i <= n; ++i){
    int l = sa.LCP[i-1] + 1, r = n - sa.SA[i] + 1;
    ans += r-l;
  }
  cout << ans << endl;
}
