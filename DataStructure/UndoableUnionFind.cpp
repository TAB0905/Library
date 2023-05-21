#include <vector>
#include <tuple>

class UndoableUnionFind{
  std::vector<int> data;
  int num_connected_components_;
  std::vector<std::tuple<int,int,int,int>> history;
public:
  UndoableUnionFind(int n) :
    data(n, -1), num_connected_components_(n),  history() {}
  bool unite(int x, int y) noexcept {
    x = find(x);
    y = find(y);
    history.emplace_back(x,data[x],y,data[y]);
    if(x != y){
      --num_connected_components_;
      if(data[y] < data[x]) std::swap(x,y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  void undo(){
    auto [x,y,z,w] = history.back();
    history.pop_back();
    data[x] = y;
    data[z] = w;
    if(x != z) ++num_connected_components_;
  }
  bool same(int x, int y) noexcept {
    return find(x) == find(y);
  }
  int find(int x) noexcept {
    if(data[x] < 0) return x;
    return find(data[x]);
  }
  int size(int x) noexcept {
    return -data[find(x)];
  }
  int num_connected_components() const noexcept {
    return num_connected_components_;
  }
};
