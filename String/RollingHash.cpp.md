---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 287, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/Library/Library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/Library/Library/String/RollingHash.cpp']' returned\
    \ non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: RollingHash\n# key: RollingHash\n# --\n\n\
    struct RollingHash{\n  int n;\n  static constexpr int n_base = 2;\n  static constexpr\
    \ array<long long, n_base> base{1009,9973};\n  static constexpr array<long long,\
    \ n_base> mod{1000000007,1000000009};\n\n  vector<array<long long, n_base>> hash,\
    \ power;\n\n  RollingHash(string s) : n(s.size()), hash(n+1), power(n+1) {\n \
    \   for(int i = 0; i < n_base; ++i)\n      power[0][i] = 1;\n    for(int i = 0;\
    \ i < n; ++i){\n      for(int j = 0; j < n_base; ++j){\n        hash[i+1][j] =\
    \ (hash[i][j]+s[i])*base[j]%mod[j];\n        power[i+1][j] = power[i][j]*base[j]%mod[j];\n\
    \      }\n    }\n  }\n  array<long long,n_base> get(int l, int r){//[l,r)\n  \
    \  array<long long,n_base> ret;\n    for(int i = 0; i < n_base; ++i)\n      ret[i]\
    \ = ((hash[r][i]-hash[l][i]*power[r-l][i])%mod[i]+mod[i])%mod[i];\n    return\
    \ ret;\n  }\n};\n\n\nstruct RollingHash_64{\n  int n;\n  unsigned long long base;\n\
    \  vector<unsigned long long> hash, power;\n  RollingHash_64(string s){\n    base\
    \ = 1e9 + 7;\n    n = s.size();\n    hash.assign(n+1,0);\n    power.assign(n+1,1);\n\
    \    for(int i = 0; i < n; ++i){\n      hash[i+1] = (hash[i]+s[i])*base;\n   \
    \   power[i+1] = power[i]*base;\n    }\n  }\n  unsigned long long get(int l, int\
    \ r){//[l,r)\n    return hash[r]-hash[l]*power[r-l];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/RollingHash.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RollingHash.cpp
layout: document
redirect_from:
- /library/String/RollingHash.cpp
- /library/String/RollingHash.cpp.html
title: String/RollingHash.cpp
---
