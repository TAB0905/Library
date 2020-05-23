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


# :heavy_check_mark: String/SuffixArray.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/SuffixArray.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 18:04:07+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/library_checker_suffix_array.test.cpp.html">test/library_checker_suffix_array.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cassert>
#include <iostream>
#include <vector>

//構築 : O(|S|log|S|)
struct SuffixArray {
private:
  std::string s;
  int size;
  void constructLCPArray(){
    for(int i = 0; i < size; ++i){
      rank[SA[i]] = i;
    }
    int l = 0;
    for(int i = 0; i < size; ++i){
      int idx = rank[i];
      int p1 = SA[idx];
      if(idx+1 == size){
        l = 0;
        LCP[idx] = l;
        continue;
      }
      int p2 = SA[idx+1];
      while(std::max(p1,p2)+l < size and s[p1+l] == s[p2+l]) ++l;
      LCP[idx] = l;
      --l;
      l = std::max(l,0);
    }
  }
public:
  std::vector<int> SA, LCP, rank;
  SuffixArray(std::string s_) : s(s_), size(s_.length()+1), SA(size+1), LCP(size+1), rank(size+1) {
    s += "$";
  }
  void construct(){
    std::vector<int> cnt(std::max(256,size),0);
    for(auto e : s){
      ++cnt[e];
    }
    for(size_t i = 1; i < cnt.size(); ++i)
      cnt[i] += cnt[i-1];
    std::vector<int> p(size);
    for(int i = 0; i < size; ++i){
      p[--cnt[s[i]]] = i;
    }
    std::vector<int> c(size);
    c[p[0]] = 0;
    for(int i = 1; i < size; ++i){
      c[p[i]] = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);
    }

    for(int k = 1; k < size; k *= 2){
      std::vector<int> p_(size), c_(size);
      for(int j = 0; j < size; ++j){
        p_[j] = p[j] - k;
        if(p_[j] < 0) p_[j] += size;
      }
      std::fill(cnt.begin(),cnt.end(),0);
      
      int max_e = 0;
      for(auto e : c){
        ++cnt[e], max_e = std::max(max_e,e);
      }
      for(int i = 0; i < max_e; ++i){
        cnt[i+1] += cnt[i];
      }
      
      for(int i = size-1; i >= 0; --i){
        p[--cnt[c[p_[i]]]] = p_[i];
      }
      
      c_[p[0]] = 0;
      int classes = 1;
      for(int i = 1; i < size; ++i){
        if((c[p[i]] != c[p[i-1]]) or (c[(p[i]+k)%size] != c[(p[i-1]+k)%size]))
          ++classes;
        c_[p[i]] = classes-1;
      }
      std::swap(c,c_);
    }

    SA = p;
    constructLCPArray();
  }
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/SuffixArray.cpp"
#include <cassert>
#include <iostream>
#include <vector>

//構築 : O(|S|log|S|)
struct SuffixArray {
private:
  std::string s;
  int size;
  void constructLCPArray(){
    for(int i = 0; i < size; ++i){
      rank[SA[i]] = i;
    }
    int l = 0;
    for(int i = 0; i < size; ++i){
      int idx = rank[i];
      int p1 = SA[idx];
      if(idx+1 == size){
        l = 0;
        LCP[idx] = l;
        continue;
      }
      int p2 = SA[idx+1];
      while(std::max(p1,p2)+l < size and s[p1+l] == s[p2+l]) ++l;
      LCP[idx] = l;
      --l;
      l = std::max(l,0);
    }
  }
public:
  std::vector<int> SA, LCP, rank;
  SuffixArray(std::string s_) : s(s_), size(s_.length()+1), SA(size+1), LCP(size+1), rank(size+1) {
    s += "$";
  }
  void construct(){
    std::vector<int> cnt(std::max(256,size),0);
    for(auto e : s){
      ++cnt[e];
    }
    for(size_t i = 1; i < cnt.size(); ++i)
      cnt[i] += cnt[i-1];
    std::vector<int> p(size);
    for(int i = 0; i < size; ++i){
      p[--cnt[s[i]]] = i;
    }
    std::vector<int> c(size);
    c[p[0]] = 0;
    for(int i = 1; i < size; ++i){
      c[p[i]] = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);
    }

    for(int k = 1; k < size; k *= 2){
      std::vector<int> p_(size), c_(size);
      for(int j = 0; j < size; ++j){
        p_[j] = p[j] - k;
        if(p_[j] < 0) p_[j] += size;
      }
      std::fill(cnt.begin(),cnt.end(),0);
      
      int max_e = 0;
      for(auto e : c){
        ++cnt[e], max_e = std::max(max_e,e);
      }
      for(int i = 0; i < max_e; ++i){
        cnt[i+1] += cnt[i];
      }
      
      for(int i = size-1; i >= 0; --i){
        p[--cnt[c[p_[i]]]] = p_[i];
      }
      
      c_[p[0]] = 0;
      int classes = 1;
      for(int i = 1; i < size; ++i){
        if((c[p[i]] != c[p[i-1]]) or (c[(p[i]+k)%size] != c[(p[i-1]+k)%size]))
          ++classes;
        c_[p[i]] = classes-1;
      }
      std::swap(c,c_);
    }

    SA = p;
    constructLCPArray();
  }
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

