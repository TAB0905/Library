#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
using namespace std;
using W = double;
using P = complex<W>;
using L = pair<P,P>;
using C = pair<P,W>;
using Poly = vector<P>;
#define X real()
#define Y imag()
const W EPS = (1e-10), pi = acos(-1);

namespace std{
  bool operator < (const P& a, const P& b){
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
  bool cmp_y(const P &a, const P &b){
    return a.Y != b.Y ? a.Y < b.Y : a.X < b.X;
  }
  bool operator == (const P& a, const P& b){
    return abs(a-b) < EPS;
  }
}

double dot(P a, P b){ return a.X * b.X + a.Y * b.Y;}
W cross(P a, P b){ return a.X * b.Y - a.Y * b.X;}
P projection(P a, P b){ return dot(a, b)/abs(b)/abs(b)*b;}
P projection(P a, L l){ return l.first + projection(a-l.first,l.second-l.first);}

//直線aと直線bの交点
P intersection(L a, L b){
  P af = a.first, as = a.second, bf = b.first, bs = b.second;
  return af + cross(bs-bf,af-bf)/(-cross(bs-bf,as-bf)+cross(bs-bf,af-bf))*(as-af);
}

//cがa/bと重なってる時は0を返す
//cがa/bと重なってる時+-2を返して欲しいなら+-2のところのEPSの符号を逆にする
int ccw(P a, P b, P c){
  b -= a; c -= a;
  if(cross(b,c) > EPS) return +1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < -EPS) return +2;
  if(norm(b) < norm(c)-EPS) return -2;
  return 0;
}

//端点が重なっててもtrueになる
//等号を無くせば端点が重なってる時はfalseにできる
bool is_cross(L a, L b){
  P af = a.first, as = a.second, bf = b.first, bs = b.second;
  return (ccw(af,as,bf)*ccw(af,as,bs) <= 0 && ccw(bf,bs,af)*ccw(bf,bs,as) <= 0);
}

W ps_dist(P a, L s){
  P sf = s.first, ss = s.second;
  if(dot(ss-sf,a-sf) >= 0 && dot(sf-ss,a-ss) >= 0)
    return abs(cross(sf-ss,a-ss))/abs(sf-ss);
  return min(abs(a-sf), abs(a-ss));
}

W pl_dist(P a, L s){
  P sf = s.first, ss = s.second;
  return abs(cross(sf-ss,a-ss))/abs(sf-ss);
}

W ss_dist(L a, L b){
  if(is_cross(a,b)) return 0;
  P af = a.first, as = a.second, bf = b.first, bs = b.second;
  return min({ps_dist(af,b),ps_dist(as,b),ps_dist(bf,a),ps_dist(bs,a)});
}

W area(const Poly &p){
  int n = p.size();
  W s = 0;
  for(int i = 0; i < n; ++i) s += cross(p[i],p[(i+1)%n])/2;
  return s;
}

bool is_convex(const Poly &p){
  int n = p.size();
  for(int i = 0; i < n; ++i)
    if(cross(p[(i+1)%n]-p[i],p[(i+2)%n]-p[(i+1)%n]) < 0) return false;
  return true;
}

int in_poly(P a, const Poly &p){
  int n = p.size(), c = 0;
  for(int i = 0; i < n; ++i){
    P s = p[i]-a, t = p[(i+1)%n]-a;
    if(!ccw(s,t,P(0,0))) return 1;//辺上
    if(s.Y > t.Y + EPS) swap(s,t);
    if((s.Y*t.Y < 0 || (s.Y*t.Y < EPS && t.Y > EPS)) && cross(s,t) < EPS) ++c;
  }
  if(c%2) return 2;//内部
  return 0;//外部
}

Poly convex_hull(Poly v){
  int n = v.size(), k = 0;
  sort(v.begin(), v.end(), cmp_y);
  Poly r(2*n);
  for(int i = 0; i < n; i++){
    while(k>1 && cross(r[k-1]-r[k-2],v[i]-r[k-2]) < -EPS) k--;
    r[k++] = v[i];
  }
  for(int i = n-2, t = k; i >= 0; i--){
    while(k>t && cross(r[k-1]-r[k-2],v[i]-r[k-2]) < -EPS) k--;
    r[k++] = v[i];
  }
  r.resize(k-1);
  return r;
}

//凸多角形の直径を求める
W convex_diam(Poly p){
  int n = p.size(), i = 0, j = 0;
  if(n <= 1) return 0;
  if(n == 2) return abs(p[0]-p[1]);

  for(int k = 0; k < n; ++k){
    if(!(p[i] < p[k])) i = k;
    if(p[j] < p[k]) j = k;
  }
  
  W res = 0;
  int si = i, sj = j;
  while(i != sj || j != si){
    res = max(res, abs(p[i]-p[j]));
    if(cross(p[(i+1)%n]-p[i],p[(j+1)%n]-p[j]) < 0) i = (i+1)%n;
    else j = (j+1)%n;
  }
  return res;
}

//円と円の交点
vector<P> intersection(C a, C b){
  P ca = a.first, cb = b.first;
  W d = abs(ca-cb), ra = a.second, rb = b.second;
  W t = (ra*ra-rb*rb+d*d)/2/d, h = sqrt(ra*ra-t*t);
  P m = t/abs(cb-ca)*(cb-ca)+ca;
  vector<P> cp(2,m);
  P n = (ca-cb)*P(0,1);
  n *= h/abs(n);
  cp[0] -= n;
  cp[1] += n;
  return cp;
}

//点pから円cに伸ばした接線の接点を求める
//intersection(C,C)が必要
vector<P> tangent_to_C(P p, C c){
  C c2 = C((p+c.first)/2.0,abs(p-c.first)/2.0);
  return intersection(c,c2);
}

//円a,bの共通接線の円aの接点を求める
//tangent_to_Cが必要
vector<P> common_tangent(C a, C b){
  vector<P> ret, cp;
  P af = a.first, bf = b.first;
  W ar = a.second, br = b.second;
  if(abs(ar-br) < EPS){
    P n = (bf-af)*P(0,1);
    n /= abs(n);
    ret.push_back(af+ar*n);
    ret.push_back(af-ar*n);
  }
  P i = (af*br+bf*ar)/(ar+br);
  if(abs(af-bf) > ar+br){//4本
    cp = tangent_to_C(i,a);
    for(int i = 0; i < 2; ++i) ret.push_back(cp[i]);
    if(abs(ar-br) > EPS){
      P e = (af*br-bf*ar)/(br-ar);
      cp = tangent_to_C(e,a);
      for(int i = 0; i < 2; ++i) ret.push_back(cp[i]);
    }
  }else if(abs(abs(af-bf)-(ar+br)) < EPS){//3本
    cp = tangent_to_C(i,a);
    ret.push_back(cp[0]);
    if(abs(ar-br) > EPS){
      P e = (af*br-bf*ar)/(br-ar);
      cp = tangent_to_C(e,a);
      for(int i = 0; i < 2; ++i) ret.push_back(cp[i]);
    }
  }else if(abs(af-bf) > abs(ar-br)){//2本
    if(abs(ar-br) > EPS){
      P e = (af*br-bf*ar)/(br-ar);
      cp = tangent_to_C(e,a);
      for(int i = 0; i < 2; ++i) ret.push_back(cp[i]);
    }
  }else if(abs(abs(af-bf) - abs(ar-br)) < EPS){//1本
    P e = (af*br-bf*ar)/(br-ar);
    cp = tangent_to_C(e,a);
    ret.push_back(cp[0]);
  }
  return ret;//0本
}

//円cと直線lの交点
 //接する場合は同一の点を二つ返す
//交点がないときこわれる
//pl_distが必要
vector<P> intersection(C c, L l){
  W d = pl_dist(c.first,l), r = c.second;
  P lf = l.first, ls = l.second;
  P m = lf + projection(c.first-lf,ls-lf);
  P x = sqrt(r*r-d*d)/abs(ls-lf)*(ls-lf);
  vector<P> cp(2,m);
  cp[0] -= x;
  cp[1] += x;
  return cp;
}

//三角形の三辺の長さa, b, cから面積を求める
W Heron(W a, W b, W c){
  W s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

//点pと直線lに対して線対称な点
P line_symmetry(L l, P p){
  P lf = l.first, ls = l.second;
  return p + (lf - p + projection(p-lf,ls-lf))*2.0;
}

P line_symmetry(P p, L l){
  return line_symmetry(l,p);
}

// Projection を写したくない時はこっち
// P line_symmetry(L l, P p){
//   P f = l.first, s = l.second - f, q = p - f;
//   if(abs(q) < EPS) return p;
//   return f + norm(q/s)*s*s/q;
// }

L vertical_bisector(P a, P b){
  P d = (a-b);
  P m = (a+b)/2.0;
  return L(m,m+d*P(0.0,1.0));
}

L angle_bisector(P a, P b, P c){
  P p = b + (a-b)/abs(a-b) + (c-b)/abs(c-b);
  return L(b,p);
}

//円と円の共通面積
//intersection(C,C)が必要
W common_area(C a, C b){
  if(a.second > b.second) swap(a,b);
  P ca = a.first, cb = b.first;
  W ra = a.second, rb = b.second;
  if(ra < EPS) return 0;
  if(norm(ca - cb) < norm(ra - rb) + EPS)
    return min(ra*ra, rb*rb)*pi;
  if(norm(ca - cb) > norm(ra + rb) + EPS)
    return 0;
  vector<P> cp = intersection(a,b);
  if(norm(cp[0] - cp[1]) < EPS) return 0;
  P aa = (cp[0]-ca)/(cp[1]-ca);
  P bb = (cp[0]-cb)/(cp[1]-cb);
  W theta_a = abs(atan2l(aa.Y,aa.X));
  W theta_b = abs(atan2l(bb.Y,bb.X));

  if(ccw(cp[0], cp[1], ca)*ccw(cp[0], cp[1], cb) >= 0){
    theta_a = max(2*pi - theta_a, theta_a);
    theta_b = min(2*pi - theta_b, theta_b);
  }else{
    theta_a = min(2*pi - theta_a, theta_a);
    theta_b = min(2*pi - theta_b, theta_b);
  }
  W sa = (theta_a-sinl(theta_a))*0.5, sb = (theta_b-sinl(theta_b))*0.5;
  W ans = ra*sa*ra + rb*sb*rb;
  return ans;
}

//凸多角形を直線で切る
//l.firstからl.secondを見て左側が残る
//ccwが必要
Poly convex_cut(const Poly &p, L l){
  Poly ret;
  int n = p.size();
  for(int i = 0; i < n; ++i){
    P cur = p[i], nex = p[(i+1)%n], lf = l.first, ls = l.second;
    if(ccw(lf, ls, cur) != -1)
      ret.push_back(cur);
    if((ccw(lf, ls, cur) != -1) ^ (ccw(lf, ls, nex) != -1))
      ret.push_back(intersection(L(cur, nex), l));
  }
  return ret;
}

//円と非凸多角形の共通面積
//ps_dist, intersection(C,L), ccw, が必要
W common_area(C c, Poly p){
  W ret = 0, r = c.second;
  int n = p.size();
  for(int i = 0; i < n; ++i) p[i] -= c.first;//これの必要性がわからん
  for(int i = 0; i < n; ++i){
    P cur = p[i], nex = p[(i+1)%n];
    if(abs(cur*nex) < EPS) continue;
    W d = arg(nex/cur);
    ret += r*r*d/2.0;
    if(ps_dist(P(0,0),L(cur,nex)) < r - EPS){
      vector<P> cps = intersection(C(P(0,0),r),L(cur,nex));//ここが変わるだけ？
      P a, b;
      if(ccw(cur,nex,cps[0]) == 0 &&
         ccw(cur,nex,cps[1]) == 0)
        a = cps[0], b = cps[1];
      else if(!ccw(cur,nex,cps[0]))
        a = cps[0], b = nex;
      else if(!ccw(cur,nex,cps[1]))
        a = cur, b = cps[1];
      else
        a = cur, b = nex;
      if(abs(a*b) < EPS) continue;
      d = arg(b/a);
      ret += cross(a,b)*0.5 - r*r*d*0.5;
    }
  }
  return ret;
}

/*
  ピックの定理
  頂点が全て格子点にあるような単純な多角形の面積を S とし,
  多角形の内部にある格子点の数を i, 辺上の格子点の数を b とすると
  S = i + b/2 - 1
  が成り立つ。
*/
