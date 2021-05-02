#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include <vector>

#include "Math/MatrixDeterminant.cpp"
#include "Math/modint.cpp"

using namespace std;

int main(){
  using mint = modint<998244353>;
  int n;
  cin >> n;
  vector<vector<mint>> A(n,vector<mint>(n));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> A[i][j];
    }
  }
  cout << determinant(A) << endl;
}
