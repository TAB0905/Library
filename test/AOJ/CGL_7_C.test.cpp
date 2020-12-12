#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_C"
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
  L l1 = vertical_bisector(a,b);
  L l2 = vertical_bisector(b,c);
  P center = intersection(l1,l2);
  double r = abs(a-center);
  cout << fixed << setprecision(20) << center.X << ' ' << center.Y << ' ' << r << '\n';
}

