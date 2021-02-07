# -*- mode: snippet -*-
# name: SegmentTree
# key: SegmentTree
# --

template <typename T>
struct SegmentTree{
private:
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
public:
  SegmentTree(){};
  SegmentTree(F f,T ti) : f(f),ti(ti) {}
  void build(int n_){
    n = n_;
    dat.assign(2*n,ti);
  }
  void build(const vector<T> &v){
    int n_ = v.size();
    build(n_);
    for(int i = 0; i < n; ++i) dat[n+i]=v[i];
    for(int i = n-1; i >= 0; --i)
      dat[i]=f(dat[2*i+0],dat[2*i+1]);
  }
  void set_val(int k,T x){
    dat[k+=n] = x;
    while(k > 0){
      k = k/2;
      dat[k]=f(dat[2*k+0],dat[2*k+1]);
    }
  }
  T query(int a,int b){
    T vl = ti, vr = ti;
    for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){
      if(l&1) vl = f(vl,dat[l++]);
      if(r&1) vr = f(dat[--r],vr);
    }
    return f(vl,vr);
  }
};

