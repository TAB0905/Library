#include <vector>
#include <utility>

struct WeightedUnionFind{
  vector<pair<int, long long>> data;
  WeightedUnionFind(int n) : data(n, pair<int,long long>(-1,0LL)) {}
  bool unite(int x, int y, long long w){//weight(y)-weight(x) = w;
    int x_ = find(x), y_ = find(y);
    if(x_ == y_) return false;
    if(data[y_].first < data[x_].first){
      swap(x_,y_);
      swap(x,y);
      w *= -1LL;
    }
    data[x_].first += data[y_].first;
    data[y_].first = x_;
    // data[y_].second += w + rel_weight(x) - rel_weight(y);
    data[y_].second += w + data[x].second - data[y].second;
    return true;
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int find(int x){
    if(data[x].first < 0) return x;
    int p = find(data[x].first);
    data[x].second += data[data[x].first].second;
    data[x].first = p;
    return data[x].first;
  }
  long long rel_weight(int x){
    find(x);
    return data[x].second;
  }
};
