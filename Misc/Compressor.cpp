#include <algorithm>
#include <vector>

template<typename T>
class Complessor {
  std::vector<T> m_val;
public:
  Complessor(const std::vector<T> dat) : m_val(dat) {
    std::sort(m_val.begin(),m_val.end());
    m_val.erase(std::unique(m_val.begin(),m_val.end()),m_val.end());
  }
  int idx(T x){
    return std::lower_bound(m_val.begin(),m_val.end(), x) - m_val.begin();
  }
  int val(int i){
    return m_val[i];
  }
};
