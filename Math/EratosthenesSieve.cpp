#include <algorithm>
#include <vector>
#include <utility>

template<typename T>
struct PrimeSieve {
  T sz;
  std::vector<T> min_div;
  std::vector<T> primes;

public:
  constexpr PrimeSieve(T sz) : sz(sz), min_div(sz+1,-1) {
    for(T i = 2; i*i <= sz; ++i){
      if(min_div[i] > 0) continue;
      for(T j = i; i*j <= sz; ++j){
        min_div[i*j] = i;
      }
    }
    for(T i = 2; i <= sz; ++i){
      if(min_div[i] < 0)
        primes.emplace_back(i);
    }
  }
  
  constexpr bool is_prime(T x) const noexcept {
    if(x <= 1) return false;
    if(x <= sz) min_div[x] < 0;
    for(auto p : primes){
      if(x%p == 0) return false;
      if(p*p > x) break;
    }
    return true;
  }

  constexpr int count(T x) const noexcept { // count p < x
    return std::lower_bound(primes.begin(), primes.end(), x) - primes.begin();
  }

  constexpr std::vector<std::pair<T,T>> factorize(T x) const noexcept {
    std::vector<std::pair<T,T>> factor;
    while(x > 1){
      T p = min_div[x];
      x /= p;
      if(factor.empty() or factor.back().first != p){
        factor.emplace_back(p,T(1));
      }else{
        ++factor.back().second;
      }
    }
    return factor;
  }
};
