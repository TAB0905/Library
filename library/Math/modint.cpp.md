---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: Math/modint.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/modint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 16:33:09+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>

template<long long mod>
class modint{
private:
  long long a;
public:
  constexpr modint(const long long x = 0) noexcept : a(x%mod) {}
  constexpr long long& value() noexcept { return a; }
  constexpr const long long& value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if(a >= mod) a -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if(a < rhs.a) a += mod;
    a -= rhs.a;
    return *this;
  }
  constexpr modint& operator*=(const modint rhs) noexcept {
    a = a*rhs.a%mod;
    return *this;
  }
  constexpr modint& operator/=(modint rhs) noexcept {
    long long k = mod-2;
    while(k > 0){
      if(k&1){
        *this *= rhs;
      }
      rhs *= rhs;
      k /= 2;
    }
    return *this;
  }
  friend std::ostream& operator<<(std::ostream &os, const modint &X){
    return os << X.a;
  }
  friend std::istream& operator>>(std::istream &is, modint &X){
    is >> X.a;
    X.a %= mod;
    if(X.a < 0) X.a += mod;
    return is;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/modint.cpp"
#include <iostream>

template<long long mod>
class modint{
private:
  long long a;
public:
  constexpr modint(const long long x = 0) noexcept : a(x%mod) {}
  constexpr long long& value() noexcept { return a; }
  constexpr const long long& value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if(a >= mod) a -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if(a < rhs.a) a += mod;
    a -= rhs.a;
    return *this;
  }
  constexpr modint& operator*=(const modint rhs) noexcept {
    a = a*rhs.a%mod;
    return *this;
  }
  constexpr modint& operator/=(modint rhs) noexcept {
    long long k = mod-2;
    while(k > 0){
      if(k&1){
        *this *= rhs;
      }
      rhs *= rhs;
      k /= 2;
    }
    return *this;
  }
  friend std::ostream& operator<<(std::ostream &os, const modint &X){
    return os << X.a;
  }
  friend std::istream& operator>>(std::istream &is, modint &X){
    is >> X.a;
    X.a %= mod;
    if(X.a < 0) X.a += mod;
    return is;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

