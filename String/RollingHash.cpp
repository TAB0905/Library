# -*- mode: snippet -*-
# name: RollingHash
# key: RollingHash
# --

struct RollingHash{
  int n;
  static constexpr int n_base = 2;
  static constexpr array<long long, n_base> base{1009,9973};
  static constexpr array<long long, n_base> mod{1000000007,1000000009};

  vector<array<long long, n_base>> hash, power;

  RollingHash(string s) : n(s.size()), hash(n+1), power(n+1) {
    for(int i = 0; i < n_base; ++i)
      power[0][i] = 1;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n_base; ++j){
        hash[i+1][j] = (hash[i][j]+s[i])*base[j]%mod[j];
        power[i+1][j] = power[i][j]*base[j]%mod[j];
      }
    }
  }
  array<long long,n_base> get(int l, int r){//[l,r)
    array<long long,n_base> ret;
    for(int i = 0; i < n_base; ++i)
      ret[i] = ((hash[r][i]-hash[l][i]*power[r-l][i])%mod[i]+mod[i])%mod[i];
    return ret;
  }
};


struct RollingHash_64{
  int n;
  unsigned long long base;
  vector<unsigned long long> hash, power;
  RollingHash_64(string s){
    base = 1e9 + 7;
    n = s.size();
    hash.assign(n+1,0);
    power.assign(n+1,1);
    for(int i = 0; i < n; ++i){
      hash[i+1] = (hash[i]+s[i])*base;
      power[i+1] = power[i]*base;
    }
  }
  unsigned long long get(int l, int r){//[l,r)
    return hash[r]-hash[l]*power[r-l];
  }
};
