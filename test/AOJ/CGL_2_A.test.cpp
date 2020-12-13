#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_2_A"

#include <iostream>
#include <iomanip>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int q;
  cin >> q;
  while(q--){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    L l1(P(x1,y1), P(x2,y2));
    cin >> x1 >> y1 >> x2 >> y2;
    L l2(P(x1,y1), P(x2,y2));
    
    P d1 = l1.second-l1.first, d2 = l2.second-l2.first;
    int ans = 0;
    if(abs(dot(d1,d2)) <= EPS){
      ans = 1;
    }
    if(abs(cross(d1,d2)) <= EPS){
      ans = 2;
    }
    cout << ans << "\n";
  }
}
