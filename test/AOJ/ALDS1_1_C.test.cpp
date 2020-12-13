#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"

#include <iostream>
#include <iomanip>
#include <vector>

#include "Math/EratosthenesSieve.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  const int sz = 10000;
  // max_a <= sz*sz
  PrimeSieve<int> sieve(sz);
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 0; i < n; ++i){
    int a;
    cin >> a;
    ans += sieve.is_prime(a);
  }
  cout << ans << endl;
}
