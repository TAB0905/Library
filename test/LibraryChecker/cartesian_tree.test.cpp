#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <iostream>
#include <vector>
#include "Graph/CartesianTree.cpp"
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; ++i)
    cin >> A[i];
  auto P = cartesian_tree(A);
  for(int i = 0; i < n; ++i){
    cout << (P[i] >= 0 ? P[i] : i) << (i+1 < n ? ' ' : '\n');
  }
}
