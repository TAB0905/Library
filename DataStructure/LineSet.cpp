#include <cassert>
#include <iostream>
#include <map>
#include <vector>

template<typename T>
class LineSet {
private:
  std::map<T,T> L;// 傾き→切片
  T max_a, min_a;
public:
  LineSet(T ai) : L(), max_a(-ai), min_a(ai) {}
  void push(T a, T b){// push ax + b
    min_a = std::min(min_a,a);
    max_a = std::max(max_a,a);
    
    if(L.empty()){
      L[a] = b;
      return;
    }
    
    if(L.size() == 1){
      if(L.find(a) != L.end())
        L[a] = std::min(L[a],b);
      else
        L[a] = b;
      return;
    }

    if(a == min_a or a == max_a){
      if(L.find(a) != L.end())
        L[a] = std::min(L[a],b);
      else
        L[a] = b;
    }

    if(L.find(a) == L.end()){
      auto ll = L.lower_bound(a);
      auto lr = prev(ll);
      if((a-lr->first)*(b-ll->second) >= (ll->first-a)*(lr->second-b))
        return;
      L[a] = b;
    }else{
      L[a] = std::min(L[a],b);
    }

    if(L.find(a) == L.end() or L[a] != b){
      return;
    }
    
    while(1){
      auto ll = L.find(a);
      if(ll == L.begin()) break;
      auto lm = prev(ll);
      if(lm == L.begin()) break;
      auto lr = prev(lm);
      if((lm->first-lr->first)*(lm->second-ll->second) < (ll->first-lm->first)*(lr->second-lm->second))
        break;
      L.erase(lm);
    }

    while(1){
      auto lr = L.find(a);
      auto lm = next(lr);
      if(lm == L.end()) break;
      auto ll = next(lm);
      if(ll == L.end()) break;
      if((lm->first-lr->first)*(lm->second-ll->second) < (ll->first-lm->first)*(lr->second-lm->second))
        break;
      L.erase(lm);
    }
  }
  T get(T x){
    // T ans = 2e18;
    // for(auto [a, b] : L){
    //   ans = std::min(ans,a*x+b);
    // }
    // return ans;
    if(L.size() == 1){
      auto [a, b] = *L.begin();
      return a*x + b;
    }
    T la = min_a, ra = max_a;
    while(ra-la > 1){
      T m = (la+ra)/2;
      auto r = L.upper_bound(m);
      assert(r != L.begin());
      assert(r != L.end());
      auto l = prev(r);
      if(l->first*x+l->second < r->first*x+r->second){
        ra = l->first;
      }else{
        la = r->first;
      }
    }
    auto [a, b] = *L.lower_bound(la);
    T ret = a*x+b;
    auto itr = L.lower_bound(la);
    if(itr != L.end() and next(itr) != L.end()){
      auto nex = next(itr);
      ret = std::min(ret,nex->first*x + nex->second);
    }
    if(itr != L.begin()){
      auto pre = prev(itr);
      ret = std::min(ret,pre->first*x + pre->second);
    }
    return ret;
  }
};

