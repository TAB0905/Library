#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include "String/SuffixArray.cpp"
using namespace std;

int main(){
  string s;
  cin >> s;
  SuffixArray sa(s);
  sa.construct();
  for(size_t i = 1; i <= s.length(); ++i){
    cout << sa.SA[i] << (i+1 <= s.length() ? " " : "\n");
  }
}
