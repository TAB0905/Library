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


# :warning: Math/FFT.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a49950aa047c2292e989e368a97a3aae">Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/FFT.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-24 14:01:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <iostream>
#include <complex>
#include <cmath>

std::vector<std::complex<double>> fft(std::vector<std::complex<double>> f, bool inv = false){
  if(f.size() == 1) return f;
  size_t n = f.size(), mid = (f.size()>>1);
  std::vector<std::complex<double>> f0(mid), f1(mid);
  for(size_t i = 0; i < mid; ++i) f0[i] = f[2*i];
  for(size_t i = 0; i < mid; ++i) f1[i] = f[2*i+1];
  f0 = fft(f0,inv);
  f1 = fft(f1,inv);
  const double pi = acos(-1);
  std::complex<double> zeta = std::polar(1.0, (inv ? -1 : 1)*2*pi/n), pow_zeta(1.0);
  for(size_t i = 0; i < n; ++i){
    f[i] = f0[i%mid] + pow_zeta*f1[i%mid];
    pow_zeta *= zeta;
  }
  return f;
}

std::vector<std::complex<double>> convolution(std::vector<std::complex<double>> g, std::vector<std::complex<double>> h){
  size_t sz = 1;
  while(sz <= g.size() + h.size()) sz *= 2;
  g.resize(sz), h.resize(sz);
  std::vector<std::complex<double>> gg = fft(g), hh = fft(h), ff(sz);
  for(size_t i = 0; i < sz; ++i) ff[i] = gg[i]*hh[i];
  std::vector<std::complex<double>> ret = fft(ff,true);
  for(size_t i = 0; i < sz; ++i) ret[i] /= sz;
  return ret;
}

using namespace std;

int main(){
  int N;
  cin >> N;
  vector< complex<double> > A(N+1), B(N+1);
  for(int i = 1; i <= N; ++i) cin >> A[i] >> B[i];
  vector< complex<double> > C = convolution(A,B);
  for(int i = 1; i <= 2*N; ++i) cout << (int)round(C[i].real()) << "\n";
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/FFT.cpp"
#include <vector>
#include <iostream>
#include <complex>
#include <cmath>

std::vector<std::complex<double>> fft(std::vector<std::complex<double>> f, bool inv = false){
  if(f.size() == 1) return f;
  size_t n = f.size(), mid = (f.size()>>1);
  std::vector<std::complex<double>> f0(mid), f1(mid);
  for(size_t i = 0; i < mid; ++i) f0[i] = f[2*i];
  for(size_t i = 0; i < mid; ++i) f1[i] = f[2*i+1];
  f0 = fft(f0,inv);
  f1 = fft(f1,inv);
  const double pi = acos(-1);
  std::complex<double> zeta = std::polar(1.0, (inv ? -1 : 1)*2*pi/n), pow_zeta(1.0);
  for(size_t i = 0; i < n; ++i){
    f[i] = f0[i%mid] + pow_zeta*f1[i%mid];
    pow_zeta *= zeta;
  }
  return f;
}

std::vector<std::complex<double>> convolution(std::vector<std::complex<double>> g, std::vector<std::complex<double>> h){
  size_t sz = 1;
  while(sz <= g.size() + h.size()) sz *= 2;
  g.resize(sz), h.resize(sz);
  std::vector<std::complex<double>> gg = fft(g), hh = fft(h), ff(sz);
  for(size_t i = 0; i < sz; ++i) ff[i] = gg[i]*hh[i];
  std::vector<std::complex<double>> ret = fft(ff,true);
  for(size_t i = 0; i < sz; ++i) ret[i] /= sz;
  return ret;
}

using namespace std;

int main(){
  int N;
  cin >> N;
  vector< complex<double> > A(N+1), B(N+1);
  for(int i = 1; i <= N; ++i) cin >> A[i] >> B[i];
  vector< complex<double> > C = convolution(A,B);
  for(int i = 1; i <= 2*N; ++i) cout << (int)round(C[i].real()) << "\n";
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

