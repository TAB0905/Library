#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <array>
#include <cstdio>

#include "Datastructure/FoldableQueue.cpp"
#include "Math/modint.cpp"

using namespace std;

int main(){
  using mint = modint<998244353>;
  using T = array<mint,2>;
  
  auto f = [](const T& a, const T& b) -> T {
             return {b[0]*a[0],b[0]*a[1]+b[1]};
           };
  
  T ti = {1,0};
  
  FoldableQueue Q(f,ti);

  int q;
  scanf("%d",&q);
  while(q--){
    int t;
    scanf("%d",&t);
    if(t == 0){
      int a, b;
      scanf("%d %d",&a,&b);
      T g = {a,b};
      Q.push_back(g);
    }
    if(t == 1){
      Q.pop_front();
    }
    if(t == 2){
      long long x;
      scanf("%lld",&x);
      auto t = Q.fold();
      // cerr << t[0] << " " << t[1] << "\n";
      printf("%lld\n",(t[0]*x+t[1]).value());
    }
  }
}
