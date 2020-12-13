#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_4_C"
#define ERROR 0.00001

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  Poly pol;
  while(n--){
    double x, y;
    cin >> x >> y;
    pol.emplace_back(x,y);
  }
  int q;
  cin >> q;
  while(q--){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    L l(P(x1,y1),P(x2,y2));
    cout << fixed << setprecision(8) << area(convex_cut(pol,l)) << '\n';
  }
}
