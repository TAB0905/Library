#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>
#include "Math/ModSqrt.cpp"
using namespace std;

void solve(){
  long long y, p;
  cin >> y >> p;
  if(p == 2){
    cout << y << '\n';
    return;
  }
  long long x = (y%p == 0 or is_quadratic_residue(y,p) ? mod_sqrt(y,p) : -1);
  cout << x << '\n';
}

int main(){
  int t;
  cin >> t;
  while(t--) solve();
}
