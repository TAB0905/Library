#include <algorithm>
#include <vector>

template<typename T, typename F>
struct FoldableQueue {
private:
  const F f;
  const T ti;
  T v;
  std::vector<T> L, R;
public:
  FoldableQueue(F f, T ti) : f(f), ti(ti), v(ti) {}
  void push_back(T x){
    R.push_back(x);
    v = f(v,x);
  }
  void pop_front(){
    if(L.size()){
      L.pop_back();
      return;
    }
    std::swap(L,R);
    std::reverse(L.begin(), L.end());
    for(size_t i = 0; i+1 < L.size(); ++i)
      L[i+1] = f(L[i+1],L[i]);
    v = ti;
    L.pop_back();
  }
  T fold(){
    if(L.size()) return f(L.back(),v);
    return v;
  }
};
