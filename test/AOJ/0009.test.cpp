#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009"

#include "Math/EratosthenesSieve.cpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  const int max_n = 1e6;
  PrimeSieve<int> sieve(max_n);
  int n;
  while(cin >> n){
    cout << sieve.count(n+1) << '\n';
  }
}
