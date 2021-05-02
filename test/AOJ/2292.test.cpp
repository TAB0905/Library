#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2292"

#include <iostream>

#include "String/PalindromicTree.cpp"

using namespace std;

void solve(){
  string s, t;
  cin >> s >> t;
  const int alphabet_size = 26;
  PalindromicTree<char,alphabet_size,'A'> S, T;

  for(auto c : s)
    S.push_back(c);
  for(auto c : t)
    T.push_back(c);
  
  for(int i = S.nodes.size()-1; i >= 0; --i){
    int sl = S.nodes[i].suffix_link;
    if(sl < 0) continue;
    S.nodes[sl].cnt += S.nodes[i].cnt;
  }
  for(int i = T.nodes.size()-1; i >= 0; --i){
    int sl = T.nodes[i].suffix_link;
    if(sl < 0) continue;
    T.nodes[sl].cnt += T.nodes[i].cnt;
  }
  
  auto solve = [&](auto&& solve, const int& vs, const int& vt) -> long long {
    long long ret = 0;
    if(S.nodes[vs].len > 0){
      long long cnt = (long long)(S.nodes[vs].cnt)*T.nodes[vt].cnt;
      ret += cnt;
    }
    for(int i = 0; i < alphabet_size; ++i){
      int us = S.nodes[vs].ch[i], ut = T.nodes[vt].ch[i];
      if(us < 0 or ut < 0)
        continue;
      ret += solve(solve,us,ut);
    }
    return ret;
  };

  long long ans = solve(solve,0,0) + solve(solve,1,1);
  cout << ans << endl;
}

int main(){
  solve();
}
