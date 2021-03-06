#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include <iostream>
#include <iomanip>
#include "DataStructure/SegmentTree.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int n, q;
  cin >> n >> q;
  using T = long long;
  SegmentTree rsq([](T a, T b){return a+b;},0LL);
  rsq.build(n);
  while(q--){
    int c, x, y;
    cin >> c >> x >> y;
    if(c){
      --x,--y;
      cout << rsq.query(x,y+1) << '\n';
    }else{
      --x;
      long long t = rsq.query(x,x+1);
      rsq.set_val(x,t+y);
    }
  }
}
