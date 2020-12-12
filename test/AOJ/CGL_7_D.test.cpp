#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_D"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  double x, y, r;
  cin >> x >> y >> r;
  C c(P(x,y),r);
  int q;
  cin >> q;
  while(q--){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    auto cps = intersection(c,L(P(x1,y1),P(x2,y2)));
    if(cps[0].X > cps[1].X) swap(cps[0],cps[1]);
    if(abs(cps[0].X-cps[1].X) < EPS and cps[0].Y > cps[1].Y) swap(cps[0],cps[1]);
    cout << fixed << setprecision(8) << cps[0].X << ' ' << cps[0].Y << ' ' << cps[1].X << ' ' << cps[1].Y << '\n';
  }
}

