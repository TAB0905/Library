#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"

#include <array>
#include <vector>
#include <cstdio>
#include <climits>

#include "DataStructure/DualSegmentTree.cpp"

using namespace std;

int main(){
  using E = int;
  E ei = numeric_limits<E>::max();

  auto f = [&](E a, E b){
             if(b == ei) return a;
             return b;
           };
  
  int n, q;
  scanf("%d %d",&n,&q);

  DualSegmentTree st(f,ei);
  st.build(n);
  
  while(q--){
    int t;
    scanf("%d",&t);
    if(t){
      int i;
      scanf("%d",&i);
      printf("%d\n",st[i]);
    }else{
      int l, r;
      E x;
      scanf("%d %d %d",&l,&r,&x);
      ++r;
      st.update(l,r,x);
    }
  }
}
