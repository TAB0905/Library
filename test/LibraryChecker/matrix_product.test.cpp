#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <iostream>
#include <iomanip>
#include "Math/Matrix.cpp"
#include "Math/modint.cpp"
using namespace std;

int main(){
  using mint = modint<998244353>;
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int n, m, k;
  cin >> n >> m >> k;
  Matrix<mint> A(n,m), B(m,k);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> A[i][j];
    }
  }
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < k; ++j){
      cin >> B[i][j];
    }
  }
  auto C = A*B;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < k; ++j){
      cout << C[i][j] << (j+1 < k ?  " " : "\n");
    }
  }
}
