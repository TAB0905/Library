#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include <iostream>
#include "DataStructure/LazySegmentTree.cpp"
using namespace std;

int main(){
  using T = pair<long long, long long>;
  using E = long long;
  T ti(0,0);
  E ei = 0;
  function<T(T,T)> f = [](T a, T b) -> T { return {a.first+b.first,a.second+b.second};};
  function<T(T,E)> g = [](T a, E b) -> T { return {a.first+b*a.second,a.second};};
  function<E(E,E)> h = [](E a, E b) -> E { return a+b;};
  LazySegmentTree<T,E> st(f,g,h,ti,ei);
  int n, q;
  cin >> n >> q;
  vector<T> v(n,T(0,1));
  st.build(v);
  while(q--){
    int t;
    cin >> t;
    if(t){
      int s, t;
      cin >> s >> t;
      cout << st.query(s-1,t).first << "\n";
    }else{
      int s, t, x;
      cin >> s >> t >> x;
      st.update(s-1,t,x);
    }
  }
}
