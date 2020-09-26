#include <vector>
#include <iostream>
#include <complex>
#include <cmath>

// std::vector<std::complex<double>> fft(std::vector<std::complex<double>> f, bool inv = false){
//   if(f.size() == 1) return f;
//   size_t n = f.size(), mid = (f.size()>>1);
//   std::vector<std::complex<double>> f0(mid), f1(mid);
//   for(size_t i = 0; i < mid; ++i) f0[i] = f[2*i];
//   for(size_t i = 0; i < mid; ++i) f1[i] = f[2*i+1];
//   f0 = fft(f0,inv);
//   f1 = fft(f1,inv);
//   const double pi = acos(-1);
//   std::complex<double> zeta = std::polar(1.0, (inv ? -1 : 1)*2*pi/n), pow_zeta(1.0);
//   for(size_t i = 0; i < n; ++i){
//     f[i] = f0[i%mid] + pow_zeta*f1[i%mid];
//     pow_zeta *= zeta;
//   }
//   return f;
// }

std::vector<std::complex<double>> fft(std::vector<std::complex<double>> f, bool inv = false){
  int n = f.size();
  int h = 0;
  for(int i = 0; (1<<i) < n; ++i) ++h;
  for(int i = 0; i < n; ++i){
    int k = 0;
    for(int j = 0; j < h; ++j)
      k |= (i>>j&1) << (h-1-j);
    if(i > k) std::swap(f[i],f[k]);
  }
  const double pi = acos(-1);
  for(int b = 1; b < n; b <<= 1){ // block size = b*2
    for(int i = 0; i < b; ++i){
      std::complex<double> zeta = std::polar(1.0, (inv ? -1 : 1)*pi*i/b);
      for(int j = 0; j < n; j += b*2){
        std::complex<double> s = f[i+j];
        std::complex<double> t = f[i+j+b]*zeta;
        f[i+j] = s+t;
        f[i+j+b] = s-t;
      }
    }
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
}
