# -*- mode: snippet -*-
# name: bisect
# key: bisect
# --

int ok = $1, ng = $2;
while(abs(ok-ng) > 1){
  int mid = (ok+ng)/2;
  if($3) ok = mid;
  else ng = mid;
}
