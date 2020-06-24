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


# :warning: Graph/Dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/Dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-24 13:56:25+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = 1e18;

vector<long long> dijkstra(const vector<vector<pair<long long,int>>>& G, int s){
  const int n = G.size();
  vector<ll> D(n,INF);
  D[s] = 0;
  vector<int> pre(n,-1);
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
  pq.emplace(0,s);
  while(pq.size()){
    auto [d, v] = pq.top();
    pq.pop();
    if(D[v] < d) continue;
    for(auto [c, v_] : G[v]){
      ll d_ = d + c;
      if(D[v_] <= d_) continue;
      D[v_] = d_;
      pre[v_] = v;
      pq.emplace(d_,v_);
    }
  }
  return {D,pre};
}

int main(){
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  vector<vector<pair<ll,int>>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    G[a].emplace_back(c,b);
  }
  auto [D, pre] = dijkstra(G,s);
  if(D[t] >= INF){
    cout << -1 << endl;
    return 0;
  }
  auto P = restor_shortest_path(pre,s,t);
  cout << D[t] << " " << P.size()-1 << endl;
  for(int i = 0; i+1 < P.size(); ++i)
    cout << P[i] << " " << P[i+1] << "\n";
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/Dijkstra.cpp"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = 1e18;

vector<long long> dijkstra(const vector<vector<pair<long long,int>>>& G, int s){
  const int n = G.size();
  vector<ll> D(n,INF);
  D[s] = 0;
  vector<int> pre(n,-1);
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
  pq.emplace(0,s);
  while(pq.size()){
    auto [d, v] = pq.top();
    pq.pop();
    if(D[v] < d) continue;
    for(auto [c, v_] : G[v]){
      ll d_ = d + c;
      if(D[v_] <= d_) continue;
      D[v_] = d_;
      pre[v_] = v;
      pq.emplace(d_,v_);
    }
  }
  return {D,pre};
}

int main(){
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  vector<vector<pair<ll,int>>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    G[a].emplace_back(c,b);
  }
  auto [D, pre] = dijkstra(G,s);
  if(D[t] >= INF){
    cout << -1 << endl;
    return 0;
  }
  auto P = restor_shortest_path(pre,s,t);
  cout << D[t] << " " << P.size()-1 << endl;
  for(int i = 0; i+1 < P.size(); ++i)
    cout << P[i] << " " << P[i+1] << "\n";
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
