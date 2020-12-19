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
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/LazySegmentTree.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: LazySegmentTree\n# key: LazySegmentTree\n\
    # --\ntemplate <typename T, typename E>\nstruct LazySegmentTree{\nprivate:\n \
    \ using F = function<T(T,T)>;\n  using G = function<T(T,E)>;\n  using H = function<E(E,E)>;\n\
    \  int n, height;\n  F f;\n  G g;\n  H h;\n  T ti;\n  E ei;\n  vector<T> dat;\n\
    \  vector<E> laz;\n  T reflect(int k){\n    return laz[k] == ei ? dat[k] : g(dat[k],laz[k]);\n\
    \  }\n  void propagate(int k){\n    if(laz[k] == ei) return;\n    if(k >= n){\n\
    \      dat[k] = reflect(k);\n      laz[k] = ei;\n      return;\n    }\n    laz[k<<1|0]\
    \ = h(laz[k<<1|0],laz[k]);\n    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);\n    dat[k]\
    \ = reflect(k);\n    laz[k] = ei;\n  }\n  void thrust(int k){\n    for(int i =\
    \ height; i >= 0; --i)\n      propagate(k>>i);\n  }\n  void recalc(int k){\n \
    \   while(k >>= 1){\n      dat[k] = f(reflect(k<<1|0),reflect(k<<1|1));\n    }\n\
    \  }\npublic:\n  LazySegmentTree(F f,G g, H h, T ti, E ei) :\n    f(f), g(g),\
    \ h(h), ti(ti), ei(ei) {}\n  void build(int n_){\n    n = n_;\n    height = 2;\n\
    \    while(n_ >>= 1) ++height;\n    dat.assign(2*n,ti);\n    laz.assign(2*n,ei);\n\
    \  }\n  void build(const vector<T> &v){\n    int n_ = v.size();\n    build(n_);\n\
    \    for(int i = 0; i < n; ++i) dat[n+i]=v[i];\n    for(int i = n-1; i >= 0; --i)\n\
    \      dat[i]=f(dat[i<<1|0],dat[i<<1|1]);\n  }\n  void update(int l_, int r_,\
    \ E x){\n    if(l_ >= r_) return;\n    l_ += n, r_ += n;\n    thrust(l_);\n  \
    \  thrust(r_-1);\n    for(int l = l_, r = r_;l < r; l >>= 1, r >>= 1){\n     \
    \ if(l&1) laz[l] = h(laz[l],x), ++l;\n      if(r&1) --r, laz[r] = h(laz[r],x);\n\
    \    }\n    recalc(l_);\n    recalc(r_-1);\n  }\n  void set_val(int a, T x){\n\
    \    thrust(a+=n);\n    dat[a] = x;\n    laz[a] = ei;\n    recalc(a);\n  }\n \
    \ T query(int l, int r){\n    if(l >= r) return ti;\n    l += n;\n    r += n;\n\
    \    thrust(l);\n    thrust(r-1);\n    T vl = ti, vr = ti;\n    for(; l < r; l\
    \ >>= 1, r >>= 1){\n      if(l&1) vl = f(vl,reflect(l++));\n      if(r&1) vr =\
    \ f(reflect(--r),vr);\n    }\n    return f(vl,vr);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/LazySegmentTree.cpp
- /library/snippets/c++-mode/LazySegmentTree.cpp.html
title: snippets/c++-mode/LazySegmentTree.cpp
---
