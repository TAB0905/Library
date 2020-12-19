# -*- mode: snippet -*-
# name: RMinQ
# key: RMinQ
# --
struct RMinQ{
private:
  int n;
  vector<long long> data;
public:
  RMinQ(vector<long long> V){
    int sz = V.size();
    n = 1;
    while(n < sz) n *= 2;
    data.resize(2*n-1,INF);
    for(int i = 0; i < sz; ++i) data[n-1+i] = V[i];
    for(int i = n-2; i >= 0; --i) data[i] = min(data[2*i+1],data[2*i+2]);
  }
  void update(int idx, long long val){//0-indexed
    idx += n-1;
    data[idx] = val;
    while(idx > 0){
      idx = (idx-1)/2;
      data[idx] = min(data[2*idx+1],data[2*idx+2]);
    }
  }
  long long get_min(int l, int r){//[l,r)の区間の最小値
    long long ret = INF;
    l += n-1, r += n-1;
    while(l < r){
      if((l&1) == 0){
        ret = min(ret,data[l]);
      }
      if((r&1) == 0){
        ret = min(ret,data[r-1]);
      }
      l /= 2;
      r = (r-1)/2;
    }
    return ret;
  }
};
