---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Datastructure/UndoableUnionFind.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <algorithm>\n#include <iostream>\n#include <tuple>\n#include \"Datastructure/UndoableUnionFind.cpp\"\
    \nusing namespace std;\n\nint main(){\n  int n, q;\n  cin >> n >> q;\n  vector<vector<tuple<int,int,int>>>\
    \ Q(q+1);\n  vector<vector<tuple<int,int,int>>> G(q+1);\n  for(int i = 1; i <=\
    \ q; ++i){\n    int t, k, u, v;\n    cin >> t >> k >> u >> v;\n    ++k;\n    if(t){\n\
    \      Q[k].emplace_back(i,u,v);\n    }else{\n      G[k].emplace_back(i,u,v);\n\
    \    }\n  }\n  vector<tuple<int,int>> ans;\n  UndoableUnionFind uf(n);\n  auto\
    \ rec = [&](auto&& rec, int v) -> void {\n    for(auto [i,a,b]: Q[v]){\n     \
    \ ans.emplace_back(i,uf.same(a,b));\n    }\n    for(auto [u,a,b]: G[v]){\n   \
    \   uf.unite(a,b);\n      rec(rec,u);\n      uf.undo();\n    }\n  };\n  rec(rec,0);\n\
    \  sort(ans.begin(),ans.end());\n  for(auto [i,a]: ans)\n    cout << a << '\\\
    n';\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/persistent_unionfind.test.cpp
- /verify/test/LibraryChecker/persistent_unionfind.test.cpp.html
title: test/LibraryChecker/persistent_unionfind.test.cpp
---
