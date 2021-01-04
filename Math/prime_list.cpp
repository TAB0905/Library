#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

template<long long bucket_size=1<<24>
vector<long long> prime_list(long long max){
  ++max;
  vector<long long> primes;
  bitset<bucket_size> is_prime;
  for(long long i = 0; i < (max+bucket_size-1)/bucket_size; ++i){
    const int sz = min(bucket_size,max-bucket_size*i);
    is_prime = ~bitset<bucket_size>(0);
    const long long l = bucket_size*i, r = l + sz;//[l,r)
    for(const auto& p : primes){
      if(p*p >= r) break;
      for(long long j = (l+p-1)/p; j < (r+p-1)/p; ++j){
        is_prime[p*j-l] = false;
      }
    }
    for(long long j = l; j*j < r; ++j){
      if(j <= 1) continue;
      if(!is_prime[j-l]) continue;
      for(long long k = j; j*k < r; ++k)
        is_prime[j*k-l] = false;
    }
    for(long long j = l; j < r; ++j)
      if(j > 1 and is_prime[j-l])
        primes.emplace_back(j);
  }
  return primes;
}
