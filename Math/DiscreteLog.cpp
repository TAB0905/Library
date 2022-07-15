#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <map>
#include <numeric>

// ax + by = gcd(a,b)
long long extgcd(long long a, long long b, long long &x, long long &y){
  long long d = a;
  if(b){
    d = extgcd(b, a%b, y, x);
    y -= (a / b)*x;
  }else{
    x = 1;
    y = 0;
  }
  assert(a*x + b*y == d);
  return d;    
}

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

/*
  x^k == y (mod m) となる最小の k を返す
  0 <= k < m
  存在しない場合は -1 を返す
  O(b*log(b))
  b*b >= m となるような b を選ぶ必要がある
*/
template<long long b>
long long discrete_log_coprime(long long x, long long y, long long m){

  if(y == 1 or m == 1)
    return 0;
  
  if(x == 0){
    if(y == 1) return 0;
    if(y == 0) return 1;
    return -1;
  }

  std::map<long long,int> bs;
  long long xb = 1;
  for(int i = 0; i < b; ++i){
    if(xb == y) return i;
    if(!bs.count(xb))
      bs[xb] = i;
    xb *= x;
    xb %= m;
  }
    
  long long x_inv,z;
  long long g_ = extgcd(x,m,x_inv,z);
  assert(g_ == 1);
  if(x_inv < 0) x_inv %= m, x_inv += m;
  assert((x*x_inv)%m == 1);
  long long x_inv_b = power<long long>(x_inv,b,[&](long long p, long long q){return (p*q)%m;},1LL);

  for(int i = 0; i <= b; ++i){
    if(bs.count(y))
      return bs[y]+i*b;
    y *= x_inv_b;
    y %= m;
  }

  return -1;
}

template<long long b>
long long discrete_log(long long x, long long y, long long m){
  assert(b*b >= m);

  if(y == 1 or m == 1)
    return 0;
  
  if(x == 0){
    if(y == 1) return 0;
    if(y == 0) return 1;
    return -1;
  }

  int d = 1;
  while((1<<d) < m) ++d;

  long long xd = 1;
  for(int i = 0; i < d; ++i){
    if(xd == y) return i;
    xd *= x;
    xd %= m;
  }

  long long xd_inv,z;
  long long g = std::gcd(xd,m);
  xd /= g, m /= g;
  extgcd(xd,m,xd_inv,z);
  assert(xd*xd_inv+m*z == 1);
  if(xd_inv < 0) xd_inv %= m, xd_inv += m;
  if(y%g) return -1;
  y /= g;
  y *= xd_inv;
  y %= m;

  long long t = discrete_log_coprime<b>(x,y,m);
  
  return (t < 0 ? t : t+d);
}
