#define PROBLEM "https://old.yosupo.jp/problem/range_kth_smallest"

#include <algorithm>
#include <iostream>
#include <vector>
#include "DataStructure/RangeTree.cpp"

using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  vector<vector<int>> A(n,vector<int>(1));
  for(int i = 0; i < n; ++i)
    cin >> A[i][0];
  auto f = [](const vector<int>& a, const vector<int>& b){
    vector<int> ret = a;
    int n = a.size();
    ret.insert(ret.end(),b.begin(),b.end());
    inplace_merge(ret.begin(),ret.begin()+n,ret.end());
    return ret;
  };

  auto g = [](const vector<int>& a, int q){
    return upper_bound(a.begin(),a.end(),q) - a.begin();
  };

  auto h = [](int a, int b){
    return a+b;
  };

  RangeTree<vector<int>,int,int,decltype(f),decltype(g),decltype(h)> rt(f,g,h,0);
  rt.build(A);

  const int INF = 1e9;
  while(q--){
    int l, r, k;
    cin >> l >> r >> k;
    ++k;
    int ok = INF, ng = -1;
    while(abs(ok-ng) > 1){
      int mid = (ok+ng)/2;
      if(rt.query(l,r,mid) >= k) ok = mid;
      else ng = mid;
    }
    cout << ok << '\n';
  }
}
