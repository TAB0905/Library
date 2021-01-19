# -*- mode: snippet -*-
# name: power
# key: power
# --
template<typename T>
T power(T x, long long k){
  T ret{1};
  while(k > 0){
    if(k&1) ret *= x;
    x *= x;
    k /= 2;
  }
  return ret;
}

