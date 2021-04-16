#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include <vector>
#include "Graph/MaximumIndependentSet.cpp"
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<long long> G(n);
  for(int i = 0; i < m; ++i){
    int a, b;
    cin >> a >> b;
    G[a] |= 1LL<<b;
    G[b] |= 1LL<<a;
  }
  long long ans = maximum_independent_set_size(G,0,0);
  int a = __builtin_popcountll(ans);
  cout << a << endl;
  for(int i = 0; i < n; ++i){
    if(ans>>i&1) cout << i << (--a ? ' ' : '\n');
  }
  cout << endl;
}
