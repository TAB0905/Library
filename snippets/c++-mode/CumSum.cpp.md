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
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/CumSum.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: CumSum\n# key: CumSum\n# --\ntemplate<typename\
    \ T>\nstruct CumSum{\nprivate:\n  size_t size;\n  vector<T> data;\npublic:\n \
    \ CumSum(vector<T> dat){\n    size = dat.size();\n    data.resize(size+1,0);\n\
    \    for(size_t i = 0; i < size; ++i)\n      data[i+1] = data[i] + dat[i];\n \
    \ }\n  T getsum(size_t l, size_t r){//0-indexed, [l,r)\n    return data[r] - data[l];\n\
    \  }\n  T getsum(size_t r){//0-indexed, [0,r)\n    return data[r];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/CumSum.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/CumSum.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/CumSum.cpp
- /library/snippets/c++-mode/CumSum.cpp.html
title: snippets/c++-mode/CumSum.cpp
---
