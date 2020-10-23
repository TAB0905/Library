#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_F"

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  double x, y, r;
  cin >> x >> y;
  P p(x,y);
  cin >> x >> y >> r;
  C c(P(x,y),r);
  auto cps = tangent_to_C(p,c);
  if(cps[1] < cps[0]) swap(cps[0],cps[1]);
  for(const auto& p : cps){
    double x = p.X, y = p.Y;
    if(abs(x) < EPS) x = 0;
    if(abs(y) < EPS) y = 0;
    cout << fixed << setprecision(10) << x << ' ' << y << '\n';
  }
}

