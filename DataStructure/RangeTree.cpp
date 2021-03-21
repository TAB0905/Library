#include <vector>
#include <iostream>
#include <climits>
#include <functional>

template <typename data_type, typename ans_type, typename query_type, typename F, typename G, typename H>
struct RangeTree{
private:
  // using F = std::function<T(T,T)>;
  int n;
  F merge_data;
  G query_;
  H merge_ans;
  ans_type ti;
  std::vector<data_type> dat;
public:
  RangeTree(F f, G g, H h, ans_type ti) : merge_data(f), query_(g), merge_ans(h), ti(ti) {}
  void build(const std::vector<data_type> &v){
    n = v.size();
    dat.resize(2*n);
    for(int i = 0; i < n; ++i) dat[n+i] = v[i];
    for(int i = n-1; i >= 0; --i)
      dat[i] = merge_data(dat[2*i+0], dat[2*i+1]);
  }
  ans_type query(int a, int b, query_type q){
    if(a == b) return ti;
    ans_type vl = ti, vr = ti;
    for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1){
      if(l&1) vl = merge_ans(vl, query_(dat[l++],q));
      if(r&1) vr = merge_ans(query_(dat[--r],q), vr);
    }
    return merge_ans(vl, vr);
  }
};

