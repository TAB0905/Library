#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include <iostream>
#include "Math/PrimeCount.cpp"
using namespace std;

int main(){
  long long n;
  cin >> n;
  cout << prime_count(n) << '\n';
}
