---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Graph/SCCD.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"../Graph/SCCD.cpp\"\nusing namespace std;\n\n\
    int main(){\n  int N, M;\n  cin >> N >> M;\n  vector<vector<int>> G(N);\n  for(int\
    \ i = 0; i < M; ++i){\n    int a, b;\n    cin >> a >> b;\n    G[a].emplace_back(b);\n\
    \  }\n  vector<int> C = scc_decompose(G);\n  int n = *max_element(C.begin(), C.end())\
    \ + 1;\n  vector<vector<int>> V(n);\n  for(int i = 0; i < N; ++i){\n    V[C[i]].emplace_back(i);\n\
    \  }\n  cout << n << '\\n';\n  for(auto v : V){\n    cout << v.size();\n    for(auto\
    \ e : v)\n      cout << ' ' << e;\n    cout << '\\n';\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/scc.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/scc.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/scc.test.cpp
- /verify/test/LibraryChecker/scc.test.cpp.html
title: test/LibraryChecker/scc.test.cpp
---
