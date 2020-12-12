#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_E"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  double x, y, r;
  cin >> x >> y >> r;
  C c1(P(x,y),r);
  cin >> x >> y >> r;
  C c2(P(x,y),r);
  auto cps = intersection(c1,c2);
  if(cps[1] < cps[0]) swap(cps[0],cps[1]);
  cout << fixed << setprecision(8) << cps[0].X << ' ' << cps[0].Y << ' ' << cps[1].X << ' ' << cps[1].Y << '\n';
}

