#include <vector>

class UnionFind{
  std::vector<int> data;
public:
  UnionFind(int n) : data(n, -1) {}
  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y){
      if(data[y] < data[x]) std::swap(x,y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int find(int x){
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }
  int size(int x){
    return -data[find(x)];
  }
};

