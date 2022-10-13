#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880"

#include <algorithm>
#include <vector>
#include <iostream>
#include <tuple>
#include "DataStructure/IntervalSet.cpp"
using namespace std;

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int,int,int>> dab;
  for(int i = 0; i < m; ++i){
    int d, a, b;
    cin >> d >> a >> b;
    dab.emplace_back(d,a,b);
  }
  sort(dab.rbegin(),dab.rend());
  vector<tuple<int,int,int,int>> Q;
  for(int i = 0; i < q; ++i){
    int e, s, t;
    cin >> e >> s >> t;
    Q.emplace_back(e,s,t,i);
  }
  sort(Q.begin(),Q.end());
  vector<bool> ans(q);
  const int INF = 1e9+1;
  IntervalSet<int,INF> S;
  for(auto [e,s,t,i] : Q){
    while(dab.size() and get<0>(dab.back()) < e){
      auto [d,a,b] = dab.back();
      dab.pop_back();
      S.insert(a,b);
    }
    ans[i] = S.contained(s,t);
  }
  for(auto e : ans)
    cout << (e ? "Yes" : "No") << "\n";
}
