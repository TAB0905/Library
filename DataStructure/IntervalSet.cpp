#include <cassert>
#include <set>
#include <utility>
#include <vector>

template<typename T, T INF>
class IntervalSet {
private:
  using const_iterator = typename std::set<std::pair<T,T>>::const_iterator;
  std::set<std::pair<T,T>> data;
public:
  IntervalSet(){
    data.emplace(INF,INF);
    data.emplace(-INF,-INF);
  }
  const_iterator begin(){ return data.begin(); }
  const_iterator end(){ return data.end(); }
  const_iterator insert(T l, T r){ // [l,r)
    assert(l <= r);
    erase(l,r);
    auto itr = data.lower_bound(std::pair(l,r));// *itr == pair(l,r)
    if(itr->first == r){
      r = itr->second;
      data.erase(itr);
      itr = data.lower_bound(std::pair(l,r));
    }
    if(std::prev(itr)->second == l){
      l = std::prev(itr)->first;
      data.erase(std::prev(itr));
    }
    return data.emplace(l,r).first;
  }
  void erase(T l, T r){ // [l,r)
    assert(l <= r);
    auto itr = data.lower_bound(std::pair(l,r));
    --itr;
    std::vector<std::pair<T,T>> d;
    while(itr != data.end()){
      if(itr->first >= r) break;
      if(itr->second <= l){
        ++itr;
        continue;
      }
      d.emplace_back(*itr);
      ++itr;
    }
    for(auto [li,ri] : d){
      data.erase(std::pair(li,ri));
      if(l <= li and ri <= r){
        continue;
      }
      if(li < l){
        data.emplace(li,l);
      }
      if(r < ri){
        data.emplace(r,ri);
      }
    }
  }
  std::pair<T,T> range(T x){
    auto itr = data.upper_bound(std::pair(x,INF));
    --itr;
    if(itr->second > x) return *itr;
    return std::pair(x,x);
  }
  bool contained(T x){
    return x < range(x).second;
  }
  bool contained(T l, T r){ // [l,r)
    return r <= range(l).second;
  }
};

