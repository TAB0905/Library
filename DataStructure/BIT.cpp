#include <vector>
#include <cassert>

template<typename T>
struct BIT{//0-indexed
private:
  std::vector<T> data;
  const int n;
public:
  BIT(int sz) : data(sz+1,0), n(sz) {}

  T sum(size_t i) const noexcept {//sum[0,i)
    //++i;
    T s = 0;
    while(i > 0){
      s += data[i];
      i -= i&(-i);
    }
    return s;
  }

  T sum(size_t i, size_t j) const noexcept {// sum[i,j)
    return sum(j) - sum(i);
  }

  void add(int i, T x) noexcept {
    ++i;
    assert(i > 0);
    while(i <= n){
      data[i] += x;
      i += i&(-i);
    }
  }
};
