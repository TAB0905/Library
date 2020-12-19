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
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/RMinQ.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: RMinQ\n# key: RMinQ\n# --\nstruct RMinQ{\n\
    private:\n  int n;\n  vector<long long> data;\npublic:\n  RMinQ(vector<long long>\
    \ V){\n    int sz = V.size();\n    n = 1;\n    while(n < sz) n *= 2;\n    data.resize(2*n-1,INF);\n\
    \    for(int i = 0; i < sz; ++i) data[n-1+i] = V[i];\n    for(int i = n-2; i >=\
    \ 0; --i) data[i] = min(data[2*i+1],data[2*i+2]);\n  }\n  void update(int idx,\
    \ long long val){//0-indexed\n    idx += n-1;\n    data[idx] = val;\n    while(idx\
    \ > 0){\n      idx = (idx-1)/2;\n      data[idx] = min(data[2*idx+1],data[2*idx+2]);\n\
    \    }\n  }\n  long long get_min(int l, int r){//[l,r)\u306E\u533A\u9593\u306E\
    \u6700\u5C0F\u5024\n    long long ret = INF;\n    l += n-1, r += n-1;\n    while(l\
    \ < r){\n      if((l&1) == 0){\n        ret = min(ret,data[l]);\n      }\n   \
    \   if((r&1) == 0){\n        ret = min(ret,data[r-1]);\n      }\n      l /= 2;\n\
    \      r = (r-1)/2;\n    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/RMinQ.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/RMinQ.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/RMinQ.cpp
- /library/snippets/c++-mode/RMinQ.cpp.html
title: snippets/c++-mode/RMinQ.cpp
---
