# -*- mode: snippet -*-
# name: RMaxQ
# key: RMaxQ
# --
struct RMaxQ{
private:
  int n;
  vector<long long> data;
public:
  RMaxQ(vector<long long> V){
    int sz = V.size();
    n = 1;
    while(n < sz) n *= 2;
    data.resize(2*n-1,-INF);
    for(int i = 0; i < sz; ++i) data[n-1+i] = V[i];
    for(int i = n-2; i >= 0; --i) data[i] = max(data[2*i+1],data[2*i+2]);
  }
  void update(int idx, long long val){//0-indexed
    idx += n-1;
    data[idx] = val;
    while(idx > 0){
      idx = (idx-1)/2;
      data[idx] = max(data[2*idx+1],data[2*idx+2]);
    }
  }
  long long get_max(int a, int b, int k=0, int l=0, int r=-1){//[a,b)の区間の最大値
    if(r < 0) r = n;
    if(a <= l and b >= r) return data[k];
    if(l >= b or r <= a) return -INF;
    long long vl = get_max(a,b,2*k+1,l,(l+r)/2);
    long long vr = get_max(a,b,2*k+2,(l+r)/2,r);
    return max(vl,vr);
  }
};
