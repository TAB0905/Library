#include <vector>
#include <cassert>

template<typename T>
struct Combination {
private:
  int sz;
  vector<T> F, F_;
public:
  Combination(int sz) : sz(sz), F(sz+1), F_(sz+1) {
    F[0] = 1;
    for(int i = 0; i < sz; ++i) F[i+1] = F[i]*(i+1);
    F_.back() = (T)1/F.back();
    for(int i = sz-1; i >= 0; --i) F_[i] = F_[i+1]*(i+1);
  }
  T C(int n, int k){
    assert(n <= sz);
    if(n < 0 or k > n) return (T)0;
    return F[n]*F_[k]*F_[n-k];
  }
  T P(int n, int k){
    assert(n <= sz);
    if(n < 0 or k > n) return (T)0;
    return F[n]*F_[n-k];
  }
};

