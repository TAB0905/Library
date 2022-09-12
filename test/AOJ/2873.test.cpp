#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2873&lang=ja"

#include <iostream>
#include <vector>
#include "String/AhoCorasick.cpp"

using namespace std;

int main(){
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> T(n);
  for(int i = 0; i < n; ++i)
    cin >> T[i];
  constexpr int alphabetSize = 26;
  AhoCorasick<char,alphabetSize,'a'> ahocora(T);
  int ans = 0, v = ahocora.root();
  for(auto c : s){
    auto [cnt,nxt] = ahocora.move(v,c);
    if(cnt){
      ++ans;
      nxt = ahocora.root();
    }
    v = nxt;
  }
  cout << ans << "\n";
}
