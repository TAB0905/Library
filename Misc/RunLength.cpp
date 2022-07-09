#include <vector>
#include <utility>
#include <string>

template<typename T>
std::vector<std::pair<T,int>> run_length(const std::vector<T>& A){
  std::vector<std::pair<T,int>> ret;
  for(auto e : A){
    if(ret.empty() or ret.back().first != e)
      ret.emplace_back(e,1);
    else
      ++ret.back().second;
  }
  return ret;
}

std::vector<std::pair<char,int>> run_length(const std::string& A){
  std::vector<std::pair<char,int>> ret;
  for(auto e : A){
    if(ret.empty() or ret.back().first != e)
      ret.emplace_back(e,1);
    else
      ++ret.back().second;
  }
  return ret;
}

