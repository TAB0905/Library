#include <cassert>
#include <iostream>
#include <random>
#include <utility>
using namespace std;

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

template<typename T>
bool is_quadratic_residue(T x, T p){ // p must be odd prime
  T y = power(x,(p-1)/2,[&](T a, T b){ return (a*b)%p; },T(1));
  return y == 1;
}

// Lehmer's algorithm
// expected O(log p)
template<typename T>
T mod_sqrt(T a, T p){ // r*r === a mod p
  // cerr << "! " << a << ' ' << p << '\n';
  if(a%p == 0){
    return 0;
  }
  T c = [&](){
    static std::random_device seed_gen;
    static std::mt19937 engine(seed_gen());
    T c = engine()%p;
    while((c*c%p-a+p)%p == 0 or is_quadratic_residue((c*c%p-a+p)%p,p)){
      c = engine()%p;
    }
    return c;
  }(); // expected O(1)
  auto mul = [&](pair<T,T> A, pair<T,T> B){ // mod (x-c)^2 - a = x^2 - 2cx + c^2 - a
    auto [s,t] = A; // sx + t
    auto [u,v] = B; // ux + v
    // sux^2 + (sv+tu)x + tv
    T e = (s*v%p+t*u%p + 2*c%p*s%p*u%p)%p;
    T f = (t*v%p - s*u%p*(c*c%p-a)%p + p)%p;
    return pair(e,f);
  };
  auto [u,v] = power(pair<T,T>(1,0),(p-1)/2,mul,pair<T,T>(0,1));
  v -= 1;
  T t = (c + (v*power(u,p-2,[&](T x, T y){ return x*y%p; }, T(1))) + p)%p;
  if((t*t)%p == a) return t;
  t = p-t;
  assert((t*t)%p == a);
  return t;
}

