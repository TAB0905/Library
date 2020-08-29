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


# :heavy_check_mark: test/library_checker_scc.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/library_checker_scc.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 04:56:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/SCCD.cpp.html">Graph/SCCD.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>

#include "../Graph/SCCD.cpp"
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
  }
  vector<int> C = scc_decompose(G);
  int n = *max_element(C.begin(), C.end()) + 1;
  vector<vector<int>> V(n);
  for(int i = 0; i < N; ++i){
    V[C[i]].emplace_back(i);
  }
  cout << n << '\n';
  for(auto v : V){
    cout << v.size();
    for(auto e : v)
      cout << ' ' << e;
    cout << '\n';
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/library_checker_scc.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>

#line 1 "Graph/SCCD.cpp"
#include <algorithm>
#include <cassert>
#line 5 "Graph/SCCD.cpp"
#include <set>

std::vector<int> scc_decompose(const std::vector<std::vector<int>>& G){
  int n = G.size();
  std::vector<int> P;
  {
    std::vector<int> visited(n,false);
    auto dfs = [&](auto dfs, int v) -> void {
      visited[v] = true;
      for(auto v_ : G[v]){
        if(visited[v_]) continue;
        dfs(dfs,v_);
      }
      P.push_back(v);
    };
    for(int i = 0; i < n; ++i){
      if(visited[i]) continue;
      dfs(dfs,i);
    }
    reverse(P.begin(), P.end());
  }
  std::vector<std::vector<int>> G_rev(n);
  for(int i = 0; i < n; ++i){
    for(auto j : G[i])
      G_rev[j].push_back(i);
  }
  std::vector<int> A(n,-1);
  int t = 0;
  auto dfs = [&](auto dfs, int v) -> void {
    A[v] = t;
    for(auto v_ : G_rev[v]){
      if(A[v_] >= 0) continue;
      dfs(dfs,v_);
    }
  };
  for(auto v : P){
    if(A[v] >= 0) continue;
    dfs(dfs,v);
    ++t;
  }
  return A;
}

#line 7 "test/library_checker_scc.test.cpp"
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
  }
  vector<int> C = scc_decompose(G);
  int n = *max_element(C.begin(), C.end()) + 1;
  vector<vector<int>> V(n);
  for(int i = 0; i < N; ++i){
    V[C[i]].emplace_back(i);
  }
  cout << n << '\n';
  for(auto v : V){
    cout << v.size();
    for(auto e : v)
      cout << ' ' << e;
    cout << '\n';
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

