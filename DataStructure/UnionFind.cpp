#include <vector>

class UnionFind{
  std::vector<int> data;
  int num_connected_components_;
public:
  UnionFind(int n) : data(n, -1), num_connected_components_(n) {}
  bool unite(int x, int y) noexcept {
    x = find(x);
    y = find(y);
    if(x != y){
      --num_connected_components_;
      if(data[y] < data[x]) std::swap(x,y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool same(int x, int y) noexcept {
    return find(x) == find(y);
  }
  int find(int x) noexcept {
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }
  int size(int x) noexcept {
    return -data[find(x)];
  }
  int num_connected_components() const noexcept {
    return num_connected_components_;
  }
};

