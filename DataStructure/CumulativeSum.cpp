#include <vector>

template<typename T>
struct CumSum{
private:
  size_t size;
  std::vector<T> data;
public:
  CumSum(std::vector<T> dat) : size(dat.size()), data(size+1) {
    for(size_t i = 0; i < size; ++i)
      data[i+1] = data[i] + dat[i];
  }
  T getsum(size_t l, size_t r){//0-indexed, [l,r)
    return data[r] - data[l];
  }
  T getsum(size_t r){//0-indexed, [0,r)
    return data[r];
  }
};
