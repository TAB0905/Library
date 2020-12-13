#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_I"
#define ERROR 0.000001

#include <algorithm>
#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  double x, y, r;
  cin >> x >> y >> r;
  C c1(P(x,y),r);
  cin >> x >> y >> r;
  C c2(P(x,y),r);
  cout << fixed << setprecision(20) << common_area(c1,c2) << '\n';
}

