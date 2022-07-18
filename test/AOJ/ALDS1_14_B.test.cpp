#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp"

#include <iostream>
#include "String/RollingHash.cpp"
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;
  RollingHash rh_s(s), rh_t(t);
  for(size_t i = 0; i+t.length() <= s.length(); ++i){
    if(rh_s.get(i,i+t.length()) == rh_t.get(0,t.length()))
      cout << i << '\n';
  }
}
