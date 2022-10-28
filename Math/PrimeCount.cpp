#include <cassert>
#include <vector>

template<typename T>
T integer_sqrt(T x){
  T r = 1;
  while(r*r <= x)
    ++r;
  return r-1;
}

template<typename T>
T prime_count(T n){
  const T sqrt_n = integer_sqrt(n);
  assert(sqrt_n*sqrt_n <= n);
  assert((sqrt_n+1)*(sqrt_n+1) > n);
  std::vector<T> L, R;
  for(T i = 1; i <= sqrt_n; ++i){
    R.emplace_back(n/i-1);
  }
  for(T i = 1; i <= n/sqrt_n; ++i){
    L.emplace_back(i-1);
  }
  std::vector<T> pi(n/sqrt_n);
  for(T i = 2; i*i <= n; ++i){
    if(L[i-1] <= L[i-2]) continue;
    pi[i-2] = L[i-2];
    for(T j = 1; j*j <= n; ++j){
      if(n/j < i*i) break;
      ((n/j) <= L.size() ? L[n/j-1] : R[j-1]) -= ((n/i/j) <= L.size() ? L[n/i/j-1] : R[i*j-1]) - pi[i-2];
    }
    for(T j = n/sqrt_n-1; j > 0; --j){
      if(j < i*i) break;
      L[j-1] -= L[j/i-1] - pi[i-2];
    }
  }
  return R[0];
}
