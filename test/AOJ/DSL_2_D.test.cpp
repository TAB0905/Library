#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"

#include <algorithm>
#include <iostream>
#include <vector>
#include "DataStructure/LazySegmentTree.cpp"
using namespace std;

int main(){

  using T = int;
  using E = int;
  T ti = 0;
  E ei = -1;
  function<T(T,T)> f = [](T a, T b){ return max(a,b);};
  function<T(T,E)> g = [](T a, E b){ return b;};
  function<E(E,E)> h = [](E a, E b){ return b;};
  
  LazySegmentTree<T,E> st(f,g,h,ti,ei);
  
  int n, q;
  cin >> n >> q;
  vector<int> init(n,(1LL<<31)-1);
  st.build(init);

  cerr << n << " " << q << endl;
  while(q--){
    int t;
    cin >> t;
    if(t){
      int i;
      cin >> i;
      cout << st.query(i,i+1) << "\n";
    }else{
      int l, r, x;
      cin >> l >> r >> x;
      ++r;
      st.update(l,r,x);
    }
  }
}
