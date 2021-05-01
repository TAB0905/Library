#include <vector>
#include <cassert>

template<typename T>
class Matrix{
private:
  using arr = std::vector<T>;
  using mat = std::vector<arr>;
  size_t r, c;
  mat dat;

public:

  Matrix() : r(0), c(0), dat(r,arr(c,T())) {}
  Matrix(size_t r, size_t c) : r(r), c(c), dat(r,arr(c,T())) {}
  Matrix(const mat& dat) : r(dat.size()), c(dat[0].size()), dat(dat) {}
  Matrix(const arr& vec) : r(1), c(vec.size()), dat(1,vec) {}
  
  size_t size() const {return dat.size();};
  bool empty() const {return size()==0;};
  arr& operator[](size_t k){return dat.at(k);};
  const arr& operator[](size_t k) const {return dat.at(k);};
  
  Matrix operator*(const Matrix &B) const noexcept {
    return Matrix(*this) *= B;
  }

  Matrix& operator*=(const Matrix &B) noexcept {
    assert((not dat.empty()) and
           (not B.empty()) and
           (dat[0].size() == B.size()));

    Matrix Bt = B.transposed();
    Matrix prod(dat.size(),B[0].size());
    for(size_t i = 0; i < dat.size(); ++i){
      for(size_t j = 0; j < B[0].size(); ++j){
        for(size_t k = 0; k < dat[0].size(); ++k){
          prod[i][j] += dat[i][k]*Bt[j][k];
        }
      }
    }

    *this = std::move(prod);
    return *this;
  };

  Matrix transposed() const noexcept {
    Matrix ret(c,r);
    for(size_t i = 0; i < c; ++i){
      for(size_t j = 0; j < r; ++j){
        ret[i][j] = dat[j][i];
      }
    }
    return ret;
  }

  static Matrix identity(size_t n, T ti){
    Matrix id(n,n);
    for(size_t i = 0; i < n; ++i)
      id[i][i] = ti;
    return id;
  }
};

