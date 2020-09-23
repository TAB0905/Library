---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"Math/FFT.cpp\"\n#include <vector>\n#include <iostream>\n\
    #include <complex>\n#include <cmath>\n\nstd::vector<std::complex<double>> fft(std::vector<std::complex<double>>\
    \ f, bool inv = false){\n  if(f.size() == 1) return f;\n  size_t n = f.size(),\
    \ mid = (f.size()>>1);\n  std::vector<std::complex<double>> f0(mid), f1(mid);\n\
    \  for(size_t i = 0; i < mid; ++i) f0[i] = f[2*i];\n  for(size_t i = 0; i < mid;\
    \ ++i) f1[i] = f[2*i+1];\n  f0 = fft(f0,inv);\n  f1 = fft(f1,inv);\n  const double\
    \ pi = acos(-1);\n  std::complex<double> zeta = std::polar(1.0, (inv ? -1 : 1)*2*pi/n),\
    \ pow_zeta(1.0);\n  for(size_t i = 0; i < n; ++i){\n    f[i] = f0[i%mid] + pow_zeta*f1[i%mid];\n\
    \    pow_zeta *= zeta;\n  }\n  return f;\n}\n\nstd::vector<std::complex<double>>\
    \ convolution(std::vector<std::complex<double>> g, std::vector<std::complex<double>>\
    \ h){\n  size_t sz = 1;\n  while(sz <= g.size() + h.size()) sz *= 2;\n  g.resize(sz),\
    \ h.resize(sz);\n  std::vector<std::complex<double>> gg = fft(g), hh = fft(h),\
    \ ff(sz);\n  for(size_t i = 0; i < sz; ++i) ff[i] = gg[i]*hh[i];\n  std::vector<std::complex<double>>\
    \ ret = fft(ff,true);\n  for(size_t i = 0; i < sz; ++i) ret[i] /= sz;\n  return\
    \ ret;\n}\n\nusing namespace std;\n\nint main(){\n  int N;\n  cin >> N;\n  vector<\
    \ complex<double> > A(N+1), B(N+1);\n  for(int i = 1; i <= N; ++i) cin >> A[i]\
    \ >> B[i];\n  vector< complex<double> > C = convolution(A,B);\n  for(int i = 1;\
    \ i <= 2*N; ++i) cout << (int)round(C[i].real()) << \"\\n\";\n  return 0;\n}\n"
  code: "#include <vector>\n#include <iostream>\n#include <complex>\n#include <cmath>\n\
    \nstd::vector<std::complex<double>> fft(std::vector<std::complex<double>> f, bool\
    \ inv = false){\n  if(f.size() == 1) return f;\n  size_t n = f.size(), mid = (f.size()>>1);\n\
    \  std::vector<std::complex<double>> f0(mid), f1(mid);\n  for(size_t i = 0; i\
    \ < mid; ++i) f0[i] = f[2*i];\n  for(size_t i = 0; i < mid; ++i) f1[i] = f[2*i+1];\n\
    \  f0 = fft(f0,inv);\n  f1 = fft(f1,inv);\n  const double pi = acos(-1);\n  std::complex<double>\
    \ zeta = std::polar(1.0, (inv ? -1 : 1)*2*pi/n), pow_zeta(1.0);\n  for(size_t\
    \ i = 0; i < n; ++i){\n    f[i] = f0[i%mid] + pow_zeta*f1[i%mid];\n    pow_zeta\
    \ *= zeta;\n  }\n  return f;\n}\n\nstd::vector<std::complex<double>> convolution(std::vector<std::complex<double>>\
    \ g, std::vector<std::complex<double>> h){\n  size_t sz = 1;\n  while(sz <= g.size()\
    \ + h.size()) sz *= 2;\n  g.resize(sz), h.resize(sz);\n  std::vector<std::complex<double>>\
    \ gg = fft(g), hh = fft(h), ff(sz);\n  for(size_t i = 0; i < sz; ++i) ff[i] =\
    \ gg[i]*hh[i];\n  std::vector<std::complex<double>> ret = fft(ff,true);\n  for(size_t\
    \ i = 0; i < sz; ++i) ret[i] /= sz;\n  return ret;\n}\n\nusing namespace std;\n\
    \nint main(){\n  int N;\n  cin >> N;\n  vector< complex<double> > A(N+1), B(N+1);\n\
    \  for(int i = 1; i <= N; ++i) cin >> A[i] >> B[i];\n  vector< complex<double>\
    \ > C = convolution(A,B);\n  for(int i = 1; i <= 2*N; ++i) cout << (int)round(C[i].real())\
    \ << \"\\n\";\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/FFT.cpp
  requiredBy: []
  timestamp: '2020-06-24 14:01:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/FFT.cpp
layout: document
redirect_from:
- /library/Math/FFT.cpp
- /library/Math/FFT.cpp.html
title: Math/FFT.cpp
---
