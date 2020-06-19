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


# :heavy_check_mark: DataStructure/FoldableQueue.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/FoldableQueue.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-19 16:23:46+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/library_checker_queue_operate_all_composite.test.cpp.html">test/library_checker_queue_operate_all_composite.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <vector>

template<typename T, typename F>
struct FoldableQueue {
private:
  const F f;
  const T ti;
  T v;
  std::vector<T> L, R;
public:
  FoldableQueue(F f, T ti) : f(f), ti(ti), v(ti) {}
  void push_back(T x){
    R.push_back(x);
    v = f(v,x);
  }
  void pop_front(){
    if(L.size()){
      L.pop_back();
      return;
    }
    std::swap(L,R);
    std::reverse(L.begin(), L.end());
    for(size_t i = 0; i+1 < L.size(); ++i)
      L[i+1] = f(L[i+1],L[i]);
    v = ti;
    L.pop_back();
  }
  T fold(){
    if(L.size()) return f(L.back(),v);
    return v;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/FoldableQueue.cpp"
#include <algorithm>
#include <vector>

template<typename T, typename F>
struct FoldableQueue {
private:
  const F f;
  const T ti;
  T v;
  std::vector<T> L, R;
public:
  FoldableQueue(F f, T ti) : f(f), ti(ti), v(ti) {}
  void push_back(T x){
    R.push_back(x);
    v = f(v,x);
  }
  void pop_front(){
    if(L.size()){
      L.pop_back();
      return;
    }
    std::swap(L,R);
    std::reverse(L.begin(), L.end());
    for(size_t i = 0; i+1 < L.size(); ++i)
      L[i+1] = f(L[i+1],L[i]);
    v = ti;
    L.pop_back();
  }
  T fold(){
    if(L.size()) return f(L.back(),v);
    return v;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

