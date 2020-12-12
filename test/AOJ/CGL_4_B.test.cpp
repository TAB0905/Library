#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_B"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<P> points;
  while(n--){
    double x, y;
    cin >> x >> y;
    points.emplace_back(x,y);
  }
  Poly hull = convex_hull(points);
  cout << fixed << setprecision(12) << convex_diam(hull) << '\n';
}
