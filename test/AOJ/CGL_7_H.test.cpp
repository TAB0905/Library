#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_7_H"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  double r;
  cin >> n >> r;
  Poly pol;
  while(n--){
    double x, y;
    cin >> x >> y;
    pol.emplace_back(x,y);
  }
  C c(P(0,0),r);
  cout << fixed << setprecision(10) << common_area(c,pol) << '\n';
}
