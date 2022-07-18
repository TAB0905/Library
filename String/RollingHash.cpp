#include <array>
#include <vector>
#include <string>

class RollingHash{
  using ull = unsigned long long;

  static constexpr ull mask31 = (1LL<<31)-1;
  static constexpr ull mask30 = (1LL<<30)-1;
  static constexpr ull mask61 = (1LL<<61)-1;
  static constexpr ull mod = mask61;
  
  int n;
  ull base;
  std::vector<ull> hash, power;
  
  ull calc_mod(ull x){
    ull xu = x>>61;
    ull xd = x&mask61;
    ull ret = xu+xd;
    return ret < mod ? ret : ret-mod;
  }

  ull mul(ull a, ull b){
    ull au = a>>31;
    ull ad = a&mask31;
    ull bu = b>>31;
    ull bd = b&mask31;
    ull mid = ad*bu + au*bd;
    ull midu = mid>>30;
    ull midd = mid&mask30;
    return au*bu*2 + midu + (midd<<31) + ad*bd;
  }

public:
  
  RollingHash(const std::string& s) :
    n(s.length()),
    base(1e9+7),
    hash(n+1),
    power(n+1,1)
  {
    for(int i = 0; i < n; ++i){
      hash[i+1] = calc_mod(mul(hash[i],base)+s[i]);
      power[i+1] = calc_mod(mul(power[i],base));
    }
  }

  ull get(int l, int r){//[l,r)
    return calc_mod(mod*4 + hash[r]-mul(hash[l],power[r-l]));
  }
};

