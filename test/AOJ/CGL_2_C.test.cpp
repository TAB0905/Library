#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_C"
#define ERROR 0.00000001

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  int q;
  cin >> q;
  while(q--){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    L l1(P(x1,y1), P(x2,y2));
    cin >> x1 >> y1 >> x2 >> y2;
    L l2(P(x1,y1), P(x2,y2));
    P c = intersection(l1,l2);
    cout << fixed << setprecision(10) << c.X << " " << c.Y << '\n';
  }
}
