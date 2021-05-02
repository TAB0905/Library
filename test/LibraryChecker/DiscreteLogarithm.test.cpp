#define IGNORE
#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include <iomanip>

#include "Math/DiscreteLog.cpp"
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  while(t--){
    long long x, y, m;
    cin >> x >> y >> m;
    cout << discrete_log<100000>(x,y,m) << '\n';
  }
}
