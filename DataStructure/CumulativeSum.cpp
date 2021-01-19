#include <vector>
#include <numeric>

template<typename T>
struct CumSum{
private:
  const size_t size;
  std::vector<T> data;
public:
  CumSum(const std::vector<T>& dat) : size(dat.size()), data(dat) {
    data.emplace_back(0);
    exclusive_scan(data.begin(),data.end(),data.begin(),static_cast<T>(0));
  }
  T getsum(size_t l, size_t r) const noexcept {//0-indexed, [l,r)
    return data[r] - data[l];
  }
  T getsum(size_t r) const noexcept {//0-indexed, [0,r)
    return data[r];
  }
};
