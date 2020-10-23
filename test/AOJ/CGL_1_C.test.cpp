#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include <iostream>
#include <iomanip>
#include <map>

#include "Geometry/geometry.cpp"

using namespace std;

int main(){
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  L l(P(x1,y1), P(x2,y2));
  int q;
  cin >> q;
  
  const map<int,string> state{
    {0,"ON_SEGMENT"},
    {-1,"CLOCKWISE"},
    {1,"COUNTER_CLOCKWISE"},
    {-2,"ONLINE_FRONT"},
    {2,"ONLINE_BACK"}
  };

  while(q--){
    double x, y;
    cin >> x >> y;
    int ans = ccw(l.first,l.second,P(x,y));
    cout << state.at(ans) << endl;
  }
}
