#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_3_B"

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
  cout << is_convex(pol) << '\n';
}
