---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: DataStructure/BinaryTrie.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/BinaryTrie.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-24 14:01:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/BinaryTrie.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

