#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  L l(P(x1,y1), P(x2,y2));
  int q;
  cin >> q;
  while(q--){
    double x, y;
    cin >> x >> y;
    P ans = projection(P(x,y),l);
    cout << fixed << setprecision(10) << ans.X << " " << ans.Y << '\n';
  }
}
