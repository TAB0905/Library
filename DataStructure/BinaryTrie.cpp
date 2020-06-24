#include <array>
#include <memory>

template<int length>
class BinaryTrie {
private:
  struct Node {
    int size;
    std::array<std::unique_ptr<Node>,2> children;
  };
  Node root;
public:
  void insert();
  void erase();
  long long lower_bound();
  long long upper_bound();
};

int main(){
  
}
