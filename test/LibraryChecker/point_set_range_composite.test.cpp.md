---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: DataStructure/Segmenttree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include <utility>\n#include \"DataStructure/Segmenttree.cpp\"\
    \n#include \"Math/modint.cpp\"\n\nusing namespace std;\n\nint main(){\n  using\
    \ mint = modint<998244353>;\n  \n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  \n  using T = pair<mint,mint>;\n  auto f = [](T a, T b) -> T {\n    return\
    \ {a.first*b.first,a.second*b.first+b.second};\n  };\n  T ti(1,0);\n  \n  SegmentTree\
    \ st(f,ti);\n\n  int n, q;\n  cin >> n >> q;\n  vector<T> A(n);\n  for(int i =\
    \ 0; i < n; ++i){\n    mint a, b;\n    cin >> a >> b;\n    A[i] = {a,b};\n  }\n\
    \  st.build(A);\n  \n  while(q--){\n    int t;\n    cin >> t;\n    if(t){\n  \
    \    int l, r, x;\n      cin >> l >> r >> x;\n      auto p = st.query(l,r);\n\
    \      cout << p.first*x+p.second << '\\n';\n    }else{\n      int p, c, d;\n\
    \      cin >> p >> c >> d;\n      st.set_val(p,T(c,d));\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/LibraryChecker/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/LibraryChecker/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/LibraryChecker/point_set_range_composite.test.cpp
- /verify/test/LibraryChecker/point_set_range_composite.test.cpp.html
title: test/LibraryChecker/point_set_range_composite.test.cpp
---
