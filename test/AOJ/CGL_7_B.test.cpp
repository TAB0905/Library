#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_B"
#define ERROR 0.000001

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  double x, y;
  cin >> x >> y;
  P a(x,y);
  cin >> x >> y;
  P b(x,y);
  cin >> x >> y;
  P c(x,y);
  L l1 = angle_bisector(a,b,c);
  L l2 = angle_bisector(b,c,a);
  P center = intersection(l1,l2);
  double r = pl_dist(center,L(a,b));
  cout << fixed << setprecision(20) << center.X << ' ' << center.Y << ' ' << r << '\n';
}

