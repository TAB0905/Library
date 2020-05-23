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


# :heavy_check_mark: test/library_checker_suffix_array.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/library_checker_suffix_array.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 18:04:07+09:00


* see: <a href="https://judge.yosupo.jp/problem/suffixarray">https://judge.yosupo.jp/problem/suffixarray</a>


## Depends on

* :heavy_check_mark: <a href="../../library/String/SuffixArray.cpp.html">String/SuffixArray.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#include "String/SuffixArray.cpp"
using namespace std;

int main(){
  string s;
  cin >> s;
  SuffixArray sa(s);
  sa.construct();
  for(size_t i = 1; i <= s.length(); ++i){
    cout << sa.SA[i] << (i+1 <= s.length() ? " " : "\n");
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/library_checker_suffix_array.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <iostream>
#line 1 "String/SuffixArray.cpp"
#include <cassert>
#line 3 "String/SuffixArray.cpp"
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

#line 5 "test/library_checker_suffix_array.test.cpp"
using namespace std;

int main(){
  string s;
  cin >> s;
  SuffixArray sa(s);
  sa.construct();
  for(size_t i = 1; i <= s.length(); ++i){
    cout << sa.SA[i] << (i+1 <= s.length() ? " " : "\n");
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

