#include <vector>

// O(n*log(n))
std::vector<int> mebius(int n){
  std::vector<int> m(n+1,1);
  std::vector<bool> is_prime(n+1,true);
  for(long long i = 2; i <= n; ++i){
    if(!is_prime[i]) continue;
    m[i] *= -1;
    for(int j = 2; j*i <= n; ++j){
      is_prime[i*j] = false;
      m[i*j] *= -1;
    }
    for(int j = 1; j*i*i <= n; ++j)
      m[i*i*j] = 0;
  }
  return m;
}
