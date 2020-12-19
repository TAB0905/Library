# -*- mode: snippet -*-
# name: chmin
# key: chmin
# --

template<typename T>
bool chmin(T& x, const T& y){
  if(x < y) return false;
  x = y;
  return true;
}

