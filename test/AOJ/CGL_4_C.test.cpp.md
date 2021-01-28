---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/geometry.cpp
    title: Geometry/geometry.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_C
  bundledCode: "#line 1 \"test/AOJ/CGL_4_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_C\"\
    \n#define ERROR 0.00001\n\n#include <iostream>\n#include <iomanip>\n\n#line 1\
    \ \"Geometry/geometry.cpp\"\n#include <algorithm>\n#line 3 \"Geometry/geometry.cpp\"\
    \n#include <complex>\n#include <cstdio>\n#include <cmath>\n#include <utility>\n\
    #include <vector>\nusing namespace std;\nusing W = double;\nusing P = complex<W>;\n\
    using L = pair<P,P>;\nusing C = pair<P,W>;\nusing Poly = vector<P>;\n#define X\
    \ real()\n#define Y imag()\nconst W EPS = (1e-10), pi = acos(-1);\n\nnamespace\
    \ std{\n  bool operator < (const P& a, const P& b){\n    return a.X != b.X ? a.X\
    \ < b.X : a.Y < b.Y;\n  }\n  bool cmp_y(const P &a, const P &b){\n    return a.Y\
    \ != b.Y ? a.Y < b.Y : a.X < b.X;\n  }\n  bool operator == (const P& a, const\
    \ P& b){\n    return abs(a-b) < EPS;\n  }\n}\n\ndouble dot(P a, P b){ return a.X\
    \ * b.X + a.Y * b.Y;}\nW cross(P a, P b){ return a.X * b.Y - a.Y * b.X;}\nP projection(P\
    \ a, P b){ return dot(a, b)/abs(b)/abs(b)*b;}\nP projection(P a, L l){ return\
    \ l.first + projection(a-l.first,l.second-l.first);}\n\n//\u76F4\u7DDAa\u3068\u76F4\
    \u7DDAb\u306E\u4EA4\u70B9\nP intersection(L a, L b){\n  P af = a.first, as = a.second,\
    \ bf = b.first, bs = b.second;\n  return af + cross(bs-bf,af-bf)/(-cross(bs-bf,as-bf)+cross(bs-bf,af-bf))*(as-af);\n\
    }\n\n//c\u304Ca/b\u3068\u91CD\u306A\u3063\u3066\u308B\u6642\u306F0\u3092\u8FD4\
    \u3059\n//c\u304Ca/b\u3068\u91CD\u306A\u3063\u3066\u308B\u6642+-2\u3092\u8FD4\u3057\
    \u3066\u6B32\u3057\u3044\u306A\u3089+-2\u306E\u3068\u3053\u308D\u306EEPS\u306E\
    \u7B26\u53F7\u3092\u9006\u306B\u3059\u308B\nint ccw(P a, P b, P c){\n  b -= a;\
    \ c -= a;\n  if(cross(b,c) > EPS) return +1;\n  if(cross(b,c) < -EPS) return -1;\n\
    \  if(dot(b,c) < -EPS) return +2;\n  if(norm(b) < norm(c)-EPS) return -2;\n  return\
    \ 0;\n}\n\n//\u7AEF\u70B9\u304C\u91CD\u306A\u3063\u3066\u3066\u3082true\u306B\u306A\
    \u308B\n//\u7B49\u53F7\u3092\u7121\u304F\u305B\u3070\u7AEF\u70B9\u304C\u91CD\u306A\
    \u3063\u3066\u308B\u6642\u306Ffalse\u306B\u3067\u304D\u308B\nbool is_cross(L a,\
    \ L b){\n  P af = a.first, as = a.second, bf = b.first, bs = b.second;\n  return\
    \ (ccw(af,as,bf)*ccw(af,as,bs) <= 0 && ccw(bf,bs,af)*ccw(bf,bs,as) <= 0);\n}\n\
    \nW ps_dist(P a, L s){\n  P sf = s.first, ss = s.second;\n  if(dot(ss-sf,a-sf)\
    \ >= 0 && dot(sf-ss,a-ss) >= 0)\n    return abs(cross(sf-ss,a-ss))/abs(sf-ss);\n\
    \  return min(abs(a-sf), abs(a-ss));\n}\n\nW pl_dist(P a, L s){\n  P sf = s.first,\
    \ ss = s.second;\n  return abs(cross(sf-ss,a-ss))/abs(sf-ss);\n}\n\nW ss_dist(L\
    \ a, L b){\n  if(is_cross(a,b)) return 0;\n  P af = a.first, as = a.second, bf\
    \ = b.first, bs = b.second;\n  return min({ps_dist(af,b),ps_dist(as,b),ps_dist(bf,a),ps_dist(bs,a)});\n\
    }\n\nW area(const Poly &p){\n  int n = p.size();\n  W s = 0;\n  for(int i = 0;\
    \ i < n; ++i) s += cross(p[i],p[(i+1)%n])/2;\n  return s;\n}\n\nbool is_convex(const\
    \ Poly &p){\n  int n = p.size();\n  for(int i = 0; i < n; ++i)\n    if(cross(p[(i+1)%n]-p[i],p[(i+2)%n]-p[(i+1)%n])\
    \ < 0) return false;\n  return true;\n}\n\nint in_poly(P a, const Poly &p){\n\
    \  int n = p.size(), c = 0;\n  for(int i = 0; i < n; ++i){\n    P s = p[i]-a,\
    \ t = p[(i+1)%n]-a;\n    if(!ccw(s,t,P(0,0))) return 1;//\u8FBA\u4E0A\n    if(s.Y\
    \ > t.Y + EPS) swap(s,t);\n    if((s.Y*t.Y < 0 || (s.Y*t.Y < EPS && t.Y > EPS))\
    \ && cross(s,t) < EPS) ++c;\n  }\n  if(c%2) return 2;//\u5185\u90E8\n  return\
    \ 0;//\u5916\u90E8\n}\n\nPoly convex_hull(Poly v){\n  int n = v.size(), k = 0;\n\
    \  sort(v.begin(), v.end(), cmp_y);\n  Poly r(2*n);\n  for(int i = 0; i < n; i++){\n\
    \    while(k>1 && cross(r[k-1]-r[k-2],v[i]-r[k-2]) < -EPS) k--;\n    r[k++] =\
    \ v[i];\n  }\n  for(int i = n-2, t = k; i >= 0; i--){\n    while(k>t && cross(r[k-1]-r[k-2],v[i]-r[k-2])\
    \ < -EPS) k--;\n    r[k++] = v[i];\n  }\n  r.resize(k-1);\n  return r;\n}\n\n\
    //\u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\nW convex_diam(Poly\
    \ p){\n  int n = p.size(), i = 0, j = 0;\n  if(n <= 1) return 0;\n  if(n == 2)\
    \ return abs(p[0]-p[1]);\n\n  for(int k = 0; k < n; ++k){\n    if(!(p[i] < p[k]))\
    \ i = k;\n    if(p[j] < p[k]) j = k;\n  }\n  \n  W res = 0;\n  int si = i, sj\
    \ = j;\n  while(i != sj || j != si){\n    res = max(res, abs(p[i]-p[j]));\n  \
    \  if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j]) < 0) i = (i+1)%n;\n    else j = (j+1)%n;\n\
    \  }\n  return res;\n}\n\n//\u5186\u3068\u5186\u306E\u4EA4\u70B9\nvector<P> intersection(C\
    \ a, C b){\n  P ca = a.first, cb = b.first;\n  W d = abs(ca-cb), ra = a.second,\
    \ rb = b.second;\n  W t = (ra*ra-rb*rb+d*d)/2/d, h = sqrt(ra*ra-t*t);\n  P m =\
    \ t/abs(cb-ca)*(cb-ca)+ca;\n  vector<P> cp(2,m);\n  P n = (ca-cb)*P(0,1);\n  n\
    \ *= h/abs(n);\n  cp[0] -= n;\n  cp[1] += n;\n  return cp;\n}\n\n//\u70B9p\u304B\
    \u3089\u5186c\u306B\u4F38\u3070\u3057\u305F\u63A5\u7DDA\u306E\u63A5\u70B9\u3092\
    \u6C42\u3081\u308B\n//intersection(C,C)\u304C\u5FC5\u8981\nvector<P> tangent_to_C(P\
    \ p, C c){\n  C c2 = C((p+c.first)/2.0,abs(p-c.first)/2.0);\n  return intersection(c,c2);\n\
    }\n\n//\u5186a,b\u306E\u5171\u901A\u63A5\u7DDA\u306E\u5186a\u306E\u63A5\u70B9\u3092\
    \u6C42\u3081\u308B\n//tangent_to_C\u304C\u5FC5\u8981\nvector<P> common_tangent(C\
    \ a, C b){\n  vector<P> ret, cp;\n  P af = a.first, bf = b.first;\n  W ar = a.second,\
    \ br = b.second;\n  if(abs(ar-br) < EPS){\n    P n = (bf-af)*P(0,1);\n    n /=\
    \ abs(n);\n    ret.push_back(af+ar*n);\n    ret.push_back(af-ar*n);\n  }\n  P\
    \ i = (af*br+bf*ar)/(ar+br);\n  if(abs(af-bf) > ar+br){//4\u672C\n    cp = tangent_to_C(i,a);\n\
    \    for(int i = 0; i < 2; ++i) ret.push_back(cp[i]);\n    if(abs(ar-br) > EPS){\n\
    \      P e = (af*br-bf*ar)/(br-ar);\n      cp = tangent_to_C(e,a);\n      for(int\
    \ i = 0; i < 2; ++i) ret.push_back(cp[i]);\n    }\n  }else if(abs(abs(af-bf)-(ar+br))\
    \ < EPS){//3\u672C\n    cp = tangent_to_C(i,a);\n    ret.push_back(cp[0]);\n \
    \   if(abs(ar-br) > EPS){\n      P e = (af*br-bf*ar)/(br-ar);\n      cp = tangent_to_C(e,a);\n\
    \      for(int i = 0; i < 2; ++i) ret.push_back(cp[i]);\n    }\n  }else if(abs(af-bf)\
    \ > abs(ar-br)){//2\u672C\n    if(abs(ar-br) > EPS){\n      P e = (af*br-bf*ar)/(br-ar);\n\
    \      cp = tangent_to_C(e,a);\n      for(int i = 0; i < 2; ++i) ret.push_back(cp[i]);\n\
    \    }\n  }else if(abs(abs(af-bf) - abs(ar-br)) < EPS){//1\u672C\n    P e = (af*br-bf*ar)/(br-ar);\n\
    \    cp = tangent_to_C(e,a);\n    ret.push_back(cp[0]);\n  }\n  return ret;//0\u672C\
    \n}\n\n//\u5186c\u3068\u76F4\u7DDAl\u306E\u4EA4\u70B9\n //\u63A5\u3059\u308B\u5834\
    \u5408\u306F\u540C\u4E00\u306E\u70B9\u3092\u4E8C\u3064\u8FD4\u3059\n//\u4EA4\u70B9\
    \u304C\u306A\u3044\u3068\u304D\u3053\u308F\u308C\u308B\n//pl_dist\u304C\u5FC5\u8981\
    \nvector<P> intersection(C c, L l){\n  W d = pl_dist(c.first,l), r = c.second;\n\
    \  P lf = l.first, ls = l.second;\n  P m = lf + projection(c.first-lf,ls-lf);\n\
    \  P x = sqrt(r*r-d*d)/abs(ls-lf)*(ls-lf);\n  vector<P> cp(2,m);\n  cp[0] -= x;\n\
    \  cp[1] += x;\n  return cp;\n}\n\n//\u4E09\u89D2\u5F62\u306E\u4E09\u8FBA\u306E\
    \u9577\u3055a, b, c\u304B\u3089\u9762\u7A4D\u3092\u6C42\u3081\u308B\nW Heron(W\
    \ a, W b, W c){\n  W s = (a+b+c)/2;\n  return sqrt(s*(s-a)*(s-b)*(s-c));\n}\n\n\
    //\u70B9p\u3068\u76F4\u7DDAl\u306B\u5BFE\u3057\u3066\u7DDA\u5BFE\u79F0\u306A\u70B9\
    \nP line_symmetry(L l, P p){\n  P lf = l.first, ls = l.second;\n  return p + (lf\
    \ - p + projection(p-lf,ls-lf))*2.0;\n}\n\nP line_symmetry(P p, L l){\n  return\
    \ line_symmetry(l,p);\n}\n\n// Projection \u3092\u5199\u3057\u305F\u304F\u306A\
    \u3044\u6642\u306F\u3053\u3063\u3061\n// P line_symmetry(L l, P p){\n//   P f\
    \ = l.first, s = l.second - f, q = p - f;\n//   if(abs(q) < EPS) return p;\n//\
    \   return f + norm(q/s)*s*s/q;\n// }\n\nL vertical_bisector(P a, P b){\n  P d\
    \ = (a-b);\n  P m = (a+b)/2.0;\n  return L(m,m+d*P(0.0,1.0));\n}\n\nL angle_bisector(P\
    \ a, P b, P c){\n  P p = b + (a-b)/abs(a-b) + (c-b)/abs(c-b);\n  return L(b,p);\n\
    }\n\n//\u5186\u3068\u5186\u306E\u5171\u901A\u9762\u7A4D\n//intersection(C,C)\u304C\
    \u5FC5\u8981\nW common_area(C a, C b){\n  if(a.second > b.second) swap(a,b);\n\
    \  P ca = a.first, cb = b.first;\n  W ra = a.second, rb = b.second;\n  if(ra <\
    \ EPS) return 0;\n  if(norm(ca - cb) < norm(ra - rb) + EPS)\n    return min(ra*ra,\
    \ rb*rb)*pi;\n  if(norm(ca - cb) > norm(ra + rb) + EPS)\n    return 0;\n  vector<P>\
    \ cp = intersection(a,b);\n  if(norm(cp[0] - cp[1]) < EPS) return 0;\n  P aa =\
    \ (cp[0]-ca)/(cp[1]-ca);\n  P bb = (cp[0]-cb)/(cp[1]-cb);\n  W theta_a = abs(atan2l(aa.Y,aa.X));\n\
    \  W theta_b = abs(atan2l(bb.Y,bb.X));\n\n  if(ccw(cp[0], cp[1], ca)*ccw(cp[0],\
    \ cp[1], cb) >= 0){\n    theta_a = max(2*pi - theta_a, theta_a);\n    theta_b\
    \ = min(2*pi - theta_b, theta_b);\n  }else{\n    theta_a = min(2*pi - theta_a,\
    \ theta_a);\n    theta_b = min(2*pi - theta_b, theta_b);\n  }\n  W sa = (theta_a-sinl(theta_a))*0.5,\
    \ sb = (theta_b-sinl(theta_b))*0.5;\n  W ans = ra*sa*ra + rb*sb*rb;\n  return\
    \ ans;\n}\n\n//\u51F8\u591A\u89D2\u5F62\u3092\u76F4\u7DDA\u3067\u5207\u308B\n\
    //l.first\u304B\u3089l.second\u3092\u898B\u3066\u5DE6\u5074\u304C\u6B8B\u308B\n\
    //ccw\u304C\u5FC5\u8981\nPoly convex_cut(const Poly &p, L l){\n  Poly ret;\n \
    \ int n = p.size();\n  for(int i = 0; i < n; ++i){\n    P cur = p[i], nex = p[(i+1)%n],\
    \ lf = l.first, ls = l.second;\n    if(ccw(lf, ls, cur) != -1)\n      ret.push_back(cur);\n\
    \    if((ccw(lf, ls, cur) != -1) ^ (ccw(lf, ls, nex) != -1))\n      ret.push_back(intersection(L(cur,\
    \ nex), l));\n  }\n  return ret;\n}\n\n//\u5186\u3068\u975E\u51F8\u591A\u89D2\u5F62\
    \u306E\u5171\u901A\u9762\u7A4D\n//ps_dist, intersection(C,L), ccw, \u304C\u5FC5\
    \u8981\nW common_area(C c, Poly p){\n  W ret = 0, r = c.second;\n  int n = p.size();\n\
    \  for(int i = 0; i < n; ++i) p[i] -= c.first;//\u3053\u308C\u306E\u5FC5\u8981\
    \u6027\u304C\u308F\u304B\u3089\u3093\n  for(int i = 0; i < n; ++i){\n    P cur\
    \ = p[i], nex = p[(i+1)%n];\n    if(abs(cur*nex) < EPS) continue;\n    W d = arg(nex/cur);\n\
    \    ret += r*r*d/2.0;\n    if(ps_dist(P(0,0),L(cur,nex)) < r - EPS){\n      vector<P>\
    \ cps = intersection(C(P(0,0),r),L(cur,nex));//\u3053\u3053\u304C\u5909\u308F\u308B\
    \u3060\u3051\uFF1F\n      P a, b;\n      if(ccw(cur,nex,cps[0]) == 0 &&\n    \
    \     ccw(cur,nex,cps[1]) == 0)\n        a = cps[0], b = cps[1];\n      else if(!ccw(cur,nex,cps[0]))\n\
    \        a = cps[0], b = nex;\n      else if(!ccw(cur,nex,cps[1]))\n        a\
    \ = cur, b = cps[1];\n      else\n        a = cur, b = nex;\n      if(abs(a*b)\
    \ < EPS) continue;\n      d = arg(b/a);\n      ret += cross(a,b)*0.5 - r*r*d*0.5;\n\
    \    }\n  }\n  return ret;\n}\n\n/*\n  \u30D4\u30C3\u30AF\u306E\u5B9A\u7406\n\
    \  \u9802\u70B9\u304C\u5168\u3066\u683C\u5B50\u70B9\u306B\u3042\u308B\u3088\u3046\
    \u306A\u5358\u7D14\u306A\u591A\u89D2\u5F62\u306E\u9762\u7A4D\u3092 S \u3068\u3057\
    ,\n  \u591A\u89D2\u5F62\u306E\u5185\u90E8\u306B\u3042\u308B\u683C\u5B50\u70B9\u306E\
    \u6570\u3092 i, \u8FBA\u4E0A\u306E\u683C\u5B50\u70B9\u306E\u6570\u3092 b \u3068\
    \u3059\u308B\u3068\n  S = i + b/2 - 1\n  \u304C\u6210\u308A\u7ACB\u3064\u3002\n\
    */\n#line 8 \"test/AOJ/CGL_4_C.test.cpp\"\n\nusing namespace std;\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\n  int n;\n  cin >> n;\n\
    \  Poly pol;\n  while(n--){\n    double x, y;\n    cin >> x >> y;\n    pol.emplace_back(x,y);\n\
    \  }\n  int q;\n  cin >> q;\n  while(q--){\n    double x1, y1, x2, y2;\n    cin\
    \ >> x1 >> y1 >> x2 >> y2;\n    L l(P(x1,y1),P(x2,y2));\n    cout << fixed <<\
    \ setprecision(8) << area(convex_cut(pol,l)) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_C\"\
    \n#define ERROR 0.00001\n\n#include <iostream>\n#include <iomanip>\n\n#include\
    \ \"Geometry/geometry.cpp\"\n\nusing namespace std;\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n\n  int n;\n  cin >> n;\n  Poly pol;\n  while(n--){\n\
    \    double x, y;\n    cin >> x >> y;\n    pol.emplace_back(x,y);\n  }\n  int\
    \ q;\n  cin >> q;\n  while(q--){\n    double x1, y1, x2, y2;\n    cin >> x1 >>\
    \ y1 >> x2 >> y2;\n    L l(P(x1,y1),P(x2,y2));\n    cout << fixed << setprecision(8)\
    \ << area(convex_cut(pol,l)) << '\\n';\n  }\n}\n"
  dependsOn:
  - Geometry/geometry.cpp
  isVerificationFile: true
  path: test/AOJ/CGL_4_C.test.cpp
  requiredBy: []
  timestamp: '2020-12-13 21:55:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_4_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_4_C.test.cpp
- /verify/test/AOJ/CGL_4_C.test.cpp.html
title: test/AOJ/CGL_4_C.test.cpp
---
