#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <iostream>
#include <iomanip>
#include "Math/MillerRabin.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int q;
  cin >> q;
  while(q--){
    long long n;
    cin >> n;
    cout << (miller_rabin(n) ? "Yes" : "No") << '\n';
  }
}
