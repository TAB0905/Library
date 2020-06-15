#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <utility>

template <typename E, typename H>
struct DualSegmentTree{
private:
  // using H = std::function<E(E,E)>;
  int n, height;
  H h;
  const E ei;
  std::vector<E> laz;
  void propagate(int k){
    if(laz[k] == ei) return;
    if(k >= n){
      return;
    }
    laz[k<<1|0] = h(laz[k<<1|0],laz[k]);
    laz[k<<1|1] = h(laz[k<<1|1],laz[k]);
    laz[k] = ei;
  }
  void thrust(int k){
    for(int i = height; i >= 0; --i)
      propagate(k>>i);
  }
public:
  DualSegmentTree(H h, E ei) :
    h(h), ei(ei) {}
  void build(int n_){
    n = n_;
    height = 2;
    while(n_ >>= 1) ++height;
    laz.assign(2*n,ei);
  }
  void update(int l_, int r_, E x){
    if(l_ >= r_) return;
    l_ += n, r_ += n;
    thrust(l_);
    thrust(r_-1);
    for(int l = l_, r = r_;l < r; l >>= 1, r >>= 1){
      if(l&1) laz[l] = h(laz[l],x), ++l;
      if(r&1) --r, laz[r] = h(laz[r],x);
    }
  }
  E operator[](int i){
    assert(i >= 0 and i < n);
    i += n;
    E ret = laz[i];
    while(i > 0){
      i /= 2;
      ret = h(ret,laz[i]);
    }
    return ret;
  }
};
