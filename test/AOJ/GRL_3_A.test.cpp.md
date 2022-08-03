---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Graph/LowLink.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n#include <utility>\n\
    #include \"Graph/LowLink.cpp\"\nusing namespace std;\n\nint main(){\n  int n,\
    \ m;\n  cin >> n >> m;\n  vector<pair<int,int>> E;\n  for(int i = 0; i < m; ++i){\n\
    \    int u, v;\n    cin >> u >> v;\n    E.emplace_back(u,v);\n  }\n  auto ans\
    \ = TwoEdgeConnectedComponentsDeconposition(E,n).articulationPoints;\n  sort(ans.begin(),ans.end());\n\
    \  // ans.erase(unique(ans.begin(),ans.end()),ans.end());\n  for(size_t i = 0;\
    \ i < ans.size(); ++i){\n    // cout << ans[i] << (i+1 < ans.size() ? ' ' : '\\\
    n');\n    cout << ans[i] << '\\n';\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_3_A.test.cpp
- /verify/test/AOJ/GRL_3_A.test.cpp.html
title: test/AOJ/GRL_3_A.test.cpp
---
