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
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 287, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-I', '/home/runner/work/Library/Library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/Library/Library/DataStructure/WeightedUnionFind.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: WeightedUnionFind\n# key: WeightedUnionFind\n\
    # --\nstruct WeightedUnionFind{\n  vector< pair<int, long long> > data;\n  WeightedUnionFind(int\
    \ n) : data(n, pair<int,long long>(-1,0LL)) {}\n  bool unite(int x, int y, long\
    \ long w){//weight(y)-weight(x) = w;\n    int x_ = find(x), y_ = find(y);\n  \
    \  if(x_ == y_) return false;\n    if(data[y_].first < data[x_].first){\n    \
    \  swap(x_,y_);\n      swap(x,y);\n      w *= -1LL;\n    }\n    data[x_].first\
    \ += data[y_].first;\n    data[y_].first = x_;\n    data[y_].second += w + rel_weight(x)\
    \ - rel_weight(y);\n    return true;\n  }\n  bool same(int x, int y){ return find(x)\
    \ == find(y); }\n  int find(int x){\n    if(data[x].first < 0) return x;\n   \
    \ int p = find(data[x].first);\n    data[x].second += data[data[x].first].second;\n\
    \    data[x].first = p;\n    return data[x].first;\n  }\n  long long rel_weight(int\
    \ x){\n    return data[x].second;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WeightedUnionFind.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/WeightedUnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/WeightedUnionFind.cpp
- /library/DataStructure/WeightedUnionFind.cpp.html
title: DataStructure/WeightedUnionFind.cpp
---
