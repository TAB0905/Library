#include <algorithm>
#include <vector>
#include <utility>

class PartiallyPersistentUnionFind{
  std::vector<int> data;
  std::vector<int> time;
  int now;
  std::vector<std::vector<std::pair<int,int>>> size_;
  std::vector<int> num_connected_components_;
public:
  PartiallyPersistentUnionFind(int n) :
    data(n, -1), time(n,-1), now(0), size_(n,std::vector<std::pair<int,int>>(1,{0,1})),
    num_connected_components_(n,0) {}
  bool unite(int x, int y) noexcept {
    ++now;
    x = find(now,x);
    y = find(now,y);
    if(x != y){
      if(data[y] < data[x]) std::swap(x,y);
      data[x] += data[y];
      size_[x].emplace_back(now,-data[x]);
      data[y] = x;
      time[y] = now;
    }
    return x != y;
  }
  bool same(int t, int x, int y) noexcept {
    return find(t,x) == find(t,y);
  }
  int find(int t, int x) noexcept {
    if(t < time[x]) return x;
    if(data[x] < 0) return x;
    return find(t,data[x]);
  }
  int size(int t, int x) noexcept {
    const int n = data.size();
    x = find(t,x);
    return std::prev(std::upper_bound(size_[x].begin(),size_[x].end(),std::make_pair(t,n+1)))->second;
  }
  int num_connected_components(int t) noexcept {
    return *std::prev(std::upper_bound(num_connected_components_.begin(),num_connected_components_.end(),t));
  }
};

