#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"

#include <iostream>
#include "DataStructure/LazySegmentTree.cpp"
using namespace std;

int main(){
  using T = long long;
  using E = long long;
  T ti = (1LL<<31)-1;
  E ei = (1LL<<31)-1;
  function<T(T,T)> f = [](T a, T b){return min(a,b);};
  function<T(T,E)> g = [](T a, E b){return b;};
  function<E(E,E)> h = [](E a, E b){return b;};

  int n, q;
  cin >> n >> q;

  LazySegmentTree<T,E> st(f,g,h,ti,ei);
  st.build(n);

  while(q--){
    int t;
    cin >> t;
    if(t){
      int s, t;
      cin >> s >> t;
      cout << st.query(s,t+1) << endl;
    }else{
      int s, t, x;
      cin >> s >> t >> x;
      st.update(s,t+1,x);
    }
    // st.dump();
  }
}


