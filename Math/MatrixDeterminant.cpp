#include <vector>

template<typename T>
T determinant(std::vector<std::vector<T>> mat){
  int n = mat.size();
  T ret = 1;
  for(int i = 0; i < n; ++i){
    if(mat[i][i] == T(0)){
      for(int j = i+1; j < n; ++j){
        if(mat[j][i] != T(0)){
          ret *= -1;
          swap(mat[j],mat[i]);
          break;
        }
      }
    }
    if(mat[i][i] == T(0))
      return 0;

    ret *= mat[i][i];
    const T tmp = mat[i][i];
    for(int j = i; j < n; ++j)
      mat[i][j] /= tmp;

    for(int j = i+1; j < n; ++j){
      T x = mat[j][i];
      for(int k = i; k < n; ++k){
        mat[j][k] -= mat[i][k]*x;
      }
    }
  }
  return ret;
}
