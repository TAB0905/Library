#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_G"
#define ERROR 0.00001

#include <algorithm>
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
  auto ans = common_tangent(c1,c2);
  sort(ans.begin(), ans.end());
  for(auto p : ans){
    double x = p.X, y = p.Y;
    if(abs(x) < EPS) x = 0;
    if(abs(y) < EPS) y = 0;
    cout << fixed << setprecision(10) << x << ' ' << y << '\n';
  }
}

