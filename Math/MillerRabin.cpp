#include <vector>

template<typename T, typename F>
T power(T x, long long k, F f, T ti){
  T ret = ti;
  while(k > 0){
    if(k&1) ret = f(ret,x);
    x = f(x,x);
    k /= 2;
  }
  return ret;
}

bool miller_rabin(long long n){
  using int128 = __int128_t;
  static const std::vector<long long> A = {2,3,5,7,11,13,17,19,23,29,31,37};
  if(n == 1) return false;

  long long m = n-1;
  m /= m&(-m);
  
  for(auto a: A){
    if(a%n == 0) continue;
    if(a >= n) continue;
    long long e = m;
    int128 t = power<int128>(a,e,[&](int128 x, long long y){
      return (x*y)%n;
    }, 1);
    
    while(e < n-1){
      int128 u = t*t%n;
      if(u == 1 and t != n-1 and t != 1)
        return false;
      t = u;
      e *= 2;
      if(t == 1) break;
    }

    if(t != 1) return false;
  }
  return true;
}
