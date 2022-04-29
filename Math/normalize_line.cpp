#include <numeric>
#include <tuple>
#include <utility>

template<typename T>
std::tuple<T,T,T> normalize_line(std::pair<T,T> p, std::pair<T,T> q){
  T a = q.second - p.second;
  T b = p.first - q.first;
  T c = a*p.first + b*p.second;
  T g = std::gcd(std::gcd(a,b),c);
  a /= g, b /= g, c /= g;
  if(a < 0) a *= -1, b *= -1, c *= -1;
  if(!a and b < 0) b *= -1, c *= -1;
  return std::tuple(a,b,c);
}

