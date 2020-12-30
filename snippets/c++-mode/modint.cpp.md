---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/Library/Library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/modint.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: modint\n# key: modint\n# --\ntemplate<long\
    \ long mod>\nclass modint{\nprivate:\n  long long a;\npublic:\n  constexpr modint(const\
    \ long long x = 0) noexcept : a(x%mod) {}\n  constexpr long long& value() noexcept\
    \ { return a; }\n  constexpr const long long& value() const noexcept { return\
    \ a; }\n  constexpr modint operator+(const modint rhs) const noexcept {\n    return\
    \ modint(*this) += rhs;\n  }\n  constexpr modint operator-(const modint rhs) const\
    \ noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr modint operator*(const\
    \ modint rhs) const noexcept {\n    return modint(*this) *= rhs;\n  }\n  constexpr\
    \ modint operator/(const modint rhs) const noexcept {\n    return modint(*this)\
    \ /= rhs;\n  }\n  constexpr modint& operator+=(const modint rhs) noexcept {\n\
    \    a += rhs.a;\n    if(a >= mod) a -= mod;\n    return *this;\n  }\n  constexpr\
    \ modint &operator-=(const modint rhs) noexcept {\n    if(a < rhs.a) a += mod;\n\
    \    a -= rhs.a;\n    return *this;\n  }\n  constexpr modint& operator*=(const\
    \ modint rhs) noexcept {\n    a = a*rhs.a%mod;\n    return *this;\n  }\n  constexpr\
    \ modint& operator/=(modint rhs) noexcept {\n    long long k = mod-2;\n    while(k\
    \ > 0){\n      if(k&1){\n        *this *= rhs;\n      }\n      rhs *= rhs;\n \
    \     k /= 2;\n    }\n    return *this;\n  }\n  friend ostream& operator<<(ostream\
    \ &os, const modint &X){\n    return os << X.a;\n  }\n  friend istream& operator>>(istream\
    \ &is, modint &X){\n    is >> X.a;\n    X.a %= mod;\n    if(X.a < 0) X.a += mod;\n\
    \    return is;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/modint.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/modint.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/modint.cpp
- /library/snippets/c++-mode/modint.cpp.html
title: snippets/c++-mode/modint.cpp
---
