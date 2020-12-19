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
    , line 287, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/Library/Library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/Fraction.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: Fraction\n# key: Fraction\n# --\ntemplate<typename\
    \ T>\nstruct Fraction{\nprivate:\n  void reduce(){\n    T g = __gcd(p,q);\n  \
    \  p /= g;\n    q /= g;\n    if(q < 0) p *= -1, q *= -1;\n  }\npublic:\n  T p,\
    \ q;// p/q\n  Fraction(T P, T Q){\n    p = P;\n    q = Q;\n    reduce();\n  }\n\
    \  constexpr Fraction inv(){\n    return Fraction(q,p);\n  }\n  constexpr Fraction\
    \ operator+(const Fraction &rhs) const noexcept{\n    return Fraction(*this) +=\
    \ rhs;\n  }\n  constexpr Fraction operator-(const Fraction &rhs) const noexcept{\n\
    \    return Fraction(*this) -= rhs;\n  }\n  constexpr Fraction operator*(const\
    \ Fraction &rhs) const noexcept{\n    return Fraction(*this) *= rhs;\n  }\n  constexpr\
    \ Fraction operator/(const Fraction &rhs) const noexcept{\n    return Fraction(*this)\
    \ /= rhs;\n  }\n  constexpr Fraction& operator*=(const T &rhs) noexcept{\n   \
    \ p *= rhs;\n    reduce();\n    return *this;\n  }\n  constexpr Fraction& operator/=(const\
    \ T &rhs) noexcept{\n    p /= rhs;\n    reduce();\n    return *this;\n  }\n  constexpr\
    \ Fraction& operator+=(const Fraction &rhs) noexcept{\n    p = p*rhs.q + rhs.p*q;\n\
    \    q *= rhs.q;\n    reduce();\n    return *this;\n  }\n  constexpr Fraction&\
    \ operator-=(const Fraction &rhs) noexcept{\n    p = p*rhs.q - rhs.p*q;\n    q\
    \ *= rhs.q;\n    reduce();\n    return *this;\n  }\n  constexpr Fraction& operator*=(const\
    \ Fraction &rhs) noexcept{\n    q *= rhs.q;\n    p *= rhs.p;\n    reduce();\n\
    \    return *this;\n  }\n  constexpr Fraction& operator/=(const Fraction &rhs)\
    \ noexcept{\n    q *= rhs.p;\n    p *= rhs.q;\n    reduce();\n    return *this;\n\
    \  }\n  constexpr bool operator<(const Fraction &rhs) const {\n    assert(rhs.p\
    \ != 0 or rhs.q != 0);\n    return p*rhs.q < q*rhs.p;\n  }\n  constexpr bool operator>(const\
    \ Fraction &rhs) const {\n    assert(rhs.p != 0 or rhs.q != 0);\n    return rhs\
    \ < *this;\n  }\n  friend ostream& operator<<(ostream& os, const Fraction f){\n\
    \    os << \"(\" << f.p << \"/\" << f.q << \")\";\n    return os;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/Fraction.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/Fraction.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/Fraction.cpp
- /library/snippets/c++-mode/Fraction.cpp.html
title: snippets/c++-mode/Fraction.cpp
---
