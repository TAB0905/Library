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
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/SegmentTree.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: SegmentTree\n# key: SegmentTree\n# --\n\n\
    template <typename T>\nstruct SegmentTree{\nprivate:\n  using F = function<T(T,T)>;\n\
    \  int n;\n  F f;\n  T ti;\n  vector<T> dat;\npublic:\n  SegmentTree(){};\n  SegmentTree(F\
    \ f,T ti) : f(f),ti(ti) {}\n  void build(int n_){\n    n = n_;\n    dat.assign(2*n,ti);\n\
    \  }\n  void build(const vector<T> &v){\n    int n_ = v.size();\n    build(n_);\n\
    \    for(int i = 0; i < n; ++i) dat[n+i]=v[i];\n    for(int i = n-1; i >= 0; --i)\n\
    \      dat[i]=f(dat[2*i+0],dat[2*i+1]);\n  }\n  void set_val(int k,T x){\n   \
    \ dat[k+=n] = x;\n    while(k > 0){\n      k = k/2;\n      dat[k]=f(dat[2*k+0],dat[2*k+1]);\n\
    \    }\n  }\n  T query(int a,int b){\n    T vl = ti, vr = ti;\n    for(int l =\
    \ a+n, r = b+n; l < r; l >>= 1, r >>= 1){\n      if(l&1) vl = f(vl,dat[l++]);\n\
    \      if(r&1) vr = f(dat[--r],vr);\n    }\n    return f(vl,vr);\n  }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/SegmentTree.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/SegmentTree.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/SegmentTree.cpp
- /library/snippets/c++-mode/SegmentTree.cpp.html
title: snippets/c++-mode/SegmentTree.cpp
---
