#include <vector>

template<typename T>
std::vector<int> cartesian_tree(const std::vector<T>& A){
  const int n = A.size();
  std::vector<int> P(n);
  P[0] = -1;
  for(int i = 1; i < n; ++i){
    P[i] = i-1;
    int p = i-1, l = -1;
    while(p >= 0 and A[p] > A[i]){
      P[i] = P[p];
      P[p] = i;
      if(l >= 0) P[l] = p;
      l = p;
      p = P[i];
    }
  }
  return P;
}

