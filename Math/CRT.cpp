#include <vector>
#include <utility>

long long extgcd(long long a, long long b, long long &x, long long &y){
  long long d = a;
  if(b){
    d = extgcd(b, a%b, y, x);
    y -= (a/b)*x;
  }else{
    x = 1;
    y = 0;
  }
  return d;    
}

std::pair<long long, long long> CRT(const std::vector<std::pair<long long, long long>> &V){
  //x%V[i].second == V[i].first
  long long a = 0, t = 1;
  for(size_t i = 0; i < V.size(); ++i){
    long long r = V[i].first, m = V[i].second, x, y;
    long long g = extgcd(t,m,x,y);
    if((r-a)%g) return {-1,-1};
    a += ((((r-a)/g)%m+m)%m*(x%m+m)%m)*t;
    t *= (m/g);
    a %= t;
    if(a > 1e12) return {-1,-1};
  }
  return {a, t};
}
