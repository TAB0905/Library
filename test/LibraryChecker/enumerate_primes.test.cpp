#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include <iostream>
#include <vector>
#include "Math/prime_list.cpp"

int main(){
  long long n, a, b;
  cin >> n >> a >> b;
  auto P = prime_list(n);
  vector<long long> Q;
  for(size_t i = b; i < P.size(); i += a){
    Q.emplace_back(P[i]);
  }
  cout << P.size() << " " << Q.size() << endl;
  for(size_t i = 0; i < Q.size(); ++i){
    cout << Q[i] << (i+1 < Q.size() ? ' ' : '\n');
  }
}
