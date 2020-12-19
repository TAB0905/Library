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
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/RMaxQ.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: RMaxQ\n# key: RMaxQ\n# --\nstruct RMaxQ{\n\
    private:\n  int n;\n  vector<long long> data;\npublic:\n  RMaxQ(vector<long long>\
    \ V){\n    int sz = V.size();\n    n = 1;\n    while(n < sz) n *= 2;\n    data.resize(2*n-1,-INF);\n\
    \    for(int i = 0; i < sz; ++i) data[n-1+i] = V[i];\n    for(int i = n-2; i >=\
    \ 0; --i) data[i] = max(data[2*i+1],data[2*i+2]);\n  }\n  void update(int idx,\
    \ long long val){//0-indexed\n    idx += n-1;\n    data[idx] = val;\n    while(idx\
    \ > 0){\n      idx = (idx-1)/2;\n      data[idx] = max(data[2*idx+1],data[2*idx+2]);\n\
    \    }\n  }\n  long long get_max(int a, int b, int k=0, int l=0, int r=-1){//[a,b)\u306E\
    \u533A\u9593\u306E\u6700\u5927\u5024\n    if(r < 0) r = n;\n    if(a <= l and\
    \ b >= r) return data[k];\n    if(l >= b or r <= a) return -INF;\n    long long\
    \ vl = get_max(a,b,2*k+1,l,(l+r)/2);\n    long long vr = get_max(a,b,2*k+2,(l+r)/2,r);\n\
    \    return max(vl,vr);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/RMaxQ.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/RMaxQ.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/RMaxQ.cpp
- /library/snippets/c++-mode/RMaxQ.cpp.html
title: snippets/c++-mode/RMaxQ.cpp
---
