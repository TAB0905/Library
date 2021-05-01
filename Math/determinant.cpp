#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <cassert>

template<long long mod>
class modint{
private:
  using T = long long;
  T a;
public:
  constexpr modint(const long long x = 0) noexcept : a((x%mod+mod)%mod) {}
  constexpr T& value() noexcept { return a; }
  constexpr const T& value() const noexcept { return a; }
  constexpr modint operator-() const noexcept {
    return modint(0) -= *this;
  }
  constexpr modint operator+(const modint& rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint& rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint& rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint& rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint& rhs) noexcept {
    a += rhs.a;
    if(a >= mod) a -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint& rhs) noexcept {
    if(a < rhs.a) a += mod;
    a -= rhs.a;
    return *this;
  }
  constexpr modint& operator*=(const modint& rhs) noexcept {
    a = a*rhs.a%mod;
    return *this;
  }
  constexpr modint& operator/=(const modint& rhs) noexcept {
    return *this *= rhs.inv();
  }
  constexpr bool operator==(const modint& rhs) const noexcept {
    return a == rhs.a;
  }
  constexpr bool operator!=(const modint& rhs) const noexcept {
    return not (*this == rhs);
  }
  constexpr modint pow(long long k) const noexcept {
    modint ret(1);
    modint x = k > 0 ? *this : this->inv();
    k = abs(k);
    while(k > 0){
      if(k&1) ret *= x;
      x *= x;
      k >>= 1;
    }
    return ret;
  }
  constexpr modint inv() const noexcept {
    return pow(mod-2);
  }
  friend std::ostream& operator<<(std::ostream &os, const modint &X) noexcept {
    return os << X.a;
  }
  friend std::istream& operator>>(std::istream &is, modint &X) noexcept {
    is >> X.a;
    X.a %= mod;
    if(X.a < 0) X.a += mod;
    return is;
  }
};

template<typename T>
T determinant(vector<vector<T>> mat){
  int n = mat.size();
  T ret = 1;
  for(int i = 0; i < n; ++i){
    if(mat[i][i] == T(0)){
      for(int j = i+1; j < n; ++j){
        if(mat[j][i] != T(0)){
          ret *= -1;
          swap(mat[j],mat[i]);
          break;
        }
      }
    }
    if(mat[i][i] == T(0))
      return 0;

    ret *= mat[i][i];
    const T tmp = mat[i][i];
    for(int j = i; j < n; ++j)
      mat[i][j] /= tmp;

    for(int j = i+1; j < n; ++j){
      T x = mat[j][i];
      for(int k = i; k < n; ++k){
        mat[j][k] -= mat[i][k]*x;
      }
    }
  }
  return ret;
}

int main(){
  using mint = modint<998244353>;
  int n;
  cin >> n;
  vector<vector<mint>> A(n,vector<mint>(n));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> A[i][j];
    }
  }
  cout << determinant(A) << endl;
}
