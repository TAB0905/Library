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
    \ '-dD', '-E', '/home/runner/work/Library/Library/snippets/c++-mode/LCA.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: LCA\n# key: LCA\n# --\nstruct LCA {\nprivate:\n\
    \  vector<vector<int>> G;\n  size_t n, m;\n  vector<vector<int>> A;\n  vector<int>\
    \ D;\n  void dfs(int v, int p){\n    for(auto v_ : G[v]){\n      if(v_ == p) continue;\n\
    \      A[v_][0] = v;\n      D[v_] = D[v]+1;\n      dfs(v_,v);\n    }\n  }\n  void\
    \ build(int r){\n    dfs(r,-1);\n    A[r][0] = r;\n    for(size_t i = 1; i < m;\
    \ ++i){\n      for(size_t j = 0; j < n; ++j){\n        A[j][i] = A[A[j][i-1]][i-1];\n\
    \      }\n    }\n  }\npublic:\n  LCA(const vector<vector<int>>& Tree, int r) :\
    \ G(Tree), n(Tree.size()), m(1), D(n,0) {\n    size_t t = 1;\n    while(t < n)\
    \ ++m, t *= 2;\n    A = vector<vector<int>>(n,vector<int>(m,-1));\n    build(r);\n\
    \  }\n  size_t query(int u, int v){\n    if(D[u] < D[v]) swap(u,v);\n\n    for(size_t\
    \ i = m-1; i < m; --i){\n      size_t u_ = A[u][i];\n      if(D[u_] < D[v]) continue;\n\
    \      u = u_;\n    }\n\n    if(u == v) return u;\n    assert(D[u] == D[v]);\n\
    \    for(size_t i = m-1; i < m; --i){\n      if(A[u][i] != A[v][i])\n        u\
    \ = A[u][i], v = A[v][i];\n    }\n    return A[u][0];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/c++-mode/LCA.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/c++-mode/LCA.cpp
layout: document
redirect_from:
- /library/snippets/c++-mode/LCA.cpp
- /library/snippets/c++-mode/LCA.cpp.html
title: snippets/c++-mode/LCA.cpp
---
