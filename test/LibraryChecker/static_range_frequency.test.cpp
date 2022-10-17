#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include "DataStructure/RangeTree.cpp"

using namespace std;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> A(n,vector<int>(1));
  for(int i = 0; i < n; ++i)
    cin >> A[i][0];
  auto f = [](vector<int> a, vector<int> b){
    int m = a.size();
    a.insert(a.end(),b.begin(),b.end());
    inplace_merge(a.begin(),a.begin()+m,a.end());
    return a;
  };
  auto g = [](const vector<int>& a, int x) -> int {
    auto ub = upper_bound(a.begin(),a.end(),x);
    auto lb = lower_bound(a.begin(),a.end(),x);
    return ub - lb;
  };
  auto h = [](int a, int b){
    return a+b;
  };
  RangeTree<vector<int>,int,int,decltype(f),decltype(g),decltype(h)> rt(f,g,h,0);
  rt.build(A);
  while(q--){
    int l, r, x;
    cin >> l >> r >> x;
    cout << rt.query(l,r,x) << "\n";
  }
}
