#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_E"

#include <iostream>
#include <iomanip>
#include "DataStructure/LazySegmentTree.cpp"
using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  using T = pair<long long, long long>;
  using E = long long;
  T ti(0,0);
  E ei = 0;
  auto f = [](T a, T b) -> T { return {a.first+b.first,a.second+b.second};};
  auto g = [](T a, E b) -> T { return {a.first+b*a.second,a.second};};
  auto h = [](E a, E b) -> E { return a+b;};
  LazySegmentTree st(f,g,h,ti,ei);
  int n, q;
  cin >> n >> q;
  vector<T> v(n,T(0,1));
  st.build(v);
  while(q--){
    int t;
    cin >> t;
    if(t){
      int i;
      cin >> i;
      cout << st.query(i-1,i).first << "\n";
    }else{
      int s, t, x;
      cin >> s >> t >> x;
      st.update(s-1,t,x);
    }
  }
}

