#include <memory>

template<typename T>
class PersistentLeftistHeap {

  struct node {
    std::shared_ptr<node> l, r;
    // node* l;
    // node* r;
    int s;
    T val;
    node(T val) : l(nullptr), r(nullptr), s(1), val(val) {}
  };

public:
  using node_ptr = std::shared_ptr<node>;
  // using node_ptr = node*;

private:
  node_ptr meld(node_ptr a, node_ptr b){
    if(!a) return (b ? node_ptr(new node(*b)) : nullptr);
    if(!b) return (a ? node_ptr(new node(*a)) : nullptr);

    a = node_ptr(new node(*a));
    b = node_ptr(new node(*b));

    if(a->val > b->val) std::swap(a,b);

    a->r = meld(a->r,b);

    if(!(a->l) or (!(a->r) and a->r->s > a->l->s)) std::swap(a->l,a->r);
    return a;
  }

  
public:
  
  node_ptr root;
  
  PersistentLeftistHeap() : root(nullptr) {}
  PersistentLeftistHeap(node_ptr t) : root(t) {}
  PersistentLeftistHeap(const PersistentLeftistHeap<T>&) = default;
  PersistentLeftistHeap(PersistentLeftistHeap<T>&&) = default;
  PersistentLeftistHeap& operator=(PersistentLeftistHeap&&) = default;

  PersistentLeftistHeap meld(PersistentLeftistHeap a){
    return PersistentLeftistHeap(meld(root,a.root));
  }
  
  PersistentLeftistHeap insert(T x){
    return PersistentLeftistHeap(meld(root,node_ptr(new node(x))));
  }

  T top(){
    return root ? root->val : T();
  }
  
  
  PersistentLeftistHeap pop(){
    return PersistentLeftistHeap(meld(root->l,root->r));
  }

  bool empty(){
    return !root;
  }
};

