#include <numeric> 
#include <iostream>

template<typename T>
struct Fraction{
private:
  T p, q;// p/q
  
  void reduce(){
    T g = std::gcd(p,q);
    p /= g;
    q /= g;
    if(q < 0) p *= -1, q *= -1;
  }
public:
  Fraction(T p, T q) : p(p), q(q) {
    reduce();
  }
  Fraction(T x) : p(x), q(1) {}

  constexpr Fraction inv(){
    return Fraction(q,p);
  }
  constexpr Fraction operator+(const Fraction &rhs) const noexcept{
    return Fraction(*this) += rhs;
  }
  constexpr Fraction operator-(const Fraction &rhs) const noexcept{
    return Fraction(*this) -= rhs;
  }
  constexpr Fraction operator*(const Fraction &rhs) const noexcept{
    return Fraction(*this) *= rhs;
  }
  constexpr Fraction operator/(const Fraction &rhs) const noexcept{
    return Fraction(*this) /= rhs;
  }
  constexpr Fraction& operator*=(const T &rhs) noexcept{
    p *= rhs;
    reduce();
    return *this;
  }
  constexpr Fraction& operator/=(const T &rhs) noexcept{
    p /= rhs;
    reduce();
    return *this;
  }
  constexpr Fraction& operator+=(const Fraction &rhs) noexcept{
    p = p*rhs.q + rhs.p*q;
    q *= rhs.q;
    reduce();
    return *this;
  }
  constexpr Fraction& operator-=(const Fraction &rhs) noexcept{
    p = p*rhs.q - rhs.p*q;
    q *= rhs.q;
    reduce();
    return *this;
  }
  constexpr Fraction& operator*=(const Fraction &rhs) noexcept{
    q *= rhs.q;
    p *= rhs.p;
    reduce();
    return *this;
  }
  constexpr Fraction& operator/=(const Fraction &rhs) noexcept{
    q *= rhs.p;
    p *= rhs.q;
    reduce();
    return *this;
  }
  constexpr bool operator==(const Fraction &rhs) const noexcept {
    return p*rhs.q == q*rhs.p;
  }
  constexpr bool operator<(const Fraction &rhs) const noexcept {
    assert(rhs.p != 0 or rhs.q != 0);
    return p*rhs.q < q*rhs.p;
  }
  constexpr bool operator>(const Fraction &rhs) const noexcept {
    assert(rhs.p != 0 or rhs.q != 0);
    return rhs < *this;
  }
  friend std::ostream& operator<<(std::ostream& os, const Fraction f){
    os << "(" << f.p << "/" << f.q << ")";
    return os;
  }
};
