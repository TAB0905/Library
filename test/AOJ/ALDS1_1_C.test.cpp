#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"

#include <iostream>
#include <vector>

#include "Math/EratosthenesSieve.cpp"

using namespace std;

int main(){
  const int sz = 10000;
  // max_a <= sz*sz
  PrimeSieve sieve(sz);
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
