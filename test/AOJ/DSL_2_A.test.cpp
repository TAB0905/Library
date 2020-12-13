#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <iostream>
#include <iomanip>
#include "DataStructure/SegmentTree.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  SegmentTree rmq([](int a, int b){return min(a,b);}, INT_MAX);
  rmq.build(n);
  while(q--){
    int c, x, y;
    cin >> c >> x >> y;
    if(c){
      cout << rmq.query(x,y+1) << '\n';
    }else{
      rmq.set_val(x,y);
    }
  }
}
