#include <iostream>
#include <vector>
using namespace std;

template<typename T>
T power(T x, long long k, long long mod){
  T ret{1};
  x %= mod;
  while(k > 0){
    if(k&1) ret *= x, ret %= mod;
    x *= x, x %= mod;
    k /= 2;
  }
  return ret;
}

long long primitive_root(long long prime){
  vector<long long> fac;
  long long v = prime-1;
  for(long long pp = 2; pp*pp <= v; ++pp){
    long long e = 0;
    while(v%pp == 0){
      ++e;
      v /= pp;
    }
    if(e)
      fac.emplace_back(pp);
  }
  if(v > 1)
    fac.emplace_back(v);

  for(long long g = 2; g < prime; ++g){
    if(power(g,(prime-1),prime) != 1){
      return -1;
    }
    bool ok = true;
    for(long long pp : fac){
      if(power(g,(prime-1)/pp,prime) == 1){
        ok = false;
        break;
      }
    }
    if(ok)
      return g;
  }
  return -1;
}
