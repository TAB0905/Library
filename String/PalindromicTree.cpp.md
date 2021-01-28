---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/PalindromicTree.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n#include <array>\n#include <iostream>\n\ntemplate<typename T, int\
    \ alphabetSize, T min_element>\nclass PalindromicTree {\n\n  struct Node {\n \
    \   const int suffix_link;\n    std::array<int,alphabetSize> ch;\n    const int\
    \ len;\n    int cnt;\n\n    Node(int suffix_link, int len) :\n      suffix_link(suffix_link),\
    \ ch(), len(len), cnt(1) {\n      std::fill(ch.begin(), ch.end(), -1);\n    };\n\
    \n    // void dump(){\n    //   std::cerr << \"cnt               : \" << cnt <<\
    \ \"\\n\";\n    //   std::cerr << \"suffix_link       : \" << suffix_link << \"\
    \\n\";\n    //   for(int j = 0; j < alphabetSize; ++j){\n    //     if(ch[j] >=\
    \ 0){\n    //       std::cout << std::string(1,'a'+j) << \" \" << ch[j] << std::endl;\n\
    \    //     }\n    //   }\n    //   std::cerr << \"\\n\";\n    // }\n  };\n\n\
    public:\n\n  std::vector<Node> nodes;\n  std::vector<T> dat;\n  int len;\n  std::vector<int>\
    \ A;\n\n  PalindromicTree() : nodes({Node(-1,-1), Node(0,0)}), dat(), len(0),\
    \ A() {}\n\n  bool push_back(T c){\n    dat.emplace_back(c);\n    ++len;\n   \
    \ int parent_idx = A.empty() ? 0 : A.back();\n    // std::cerr << parent_idx <<\
    \ \" \" << len-2-nodes[parent_idx].len << std::endl;\n    while(len-2-nodes[parent_idx].len\
    \ < 0 or dat[len-2-nodes[parent_idx].len] != c){\n      parent_idx = nodes[parent_idx].suffix_link;\n\
    \    }\n\n    int v_idx = nodes[parent_idx].ch[c-min_element];\n\n    if(v_idx\
    \ != -1){\n      ++nodes[v_idx].cnt;\n      A.emplace_back(v_idx);\n      return\
    \ false;\n    }\n\n    int suffix_link = nodes[parent_idx].suffix_link;\n    while(suffix_link\
    \ >= 0 and (len-2-nodes[suffix_link].len < 0 or dat[len-2-nodes[suffix_link].len]\
    \ != c)){\n      suffix_link = nodes[suffix_link].suffix_link;\n    }\n\n\n  \
    \  if(suffix_link >= 0 and len-2-nodes[suffix_link].len >= 0 and dat[len-2-nodes[suffix_link].len]\
    \ == c){\n      assert(nodes[suffix_link].ch[c-min_element] >= 0);\n      suffix_link\
    \ = nodes[suffix_link].ch[c-min_element];\n    }\n\n    if(suffix_link < 0) suffix_link\
    \ = 1;\n    \n    v_idx = nodes.size();\n    nodes[parent_idx].ch[c-min_element]\
    \ = v_idx;\n    nodes.emplace_back(suffix_link,nodes[parent_idx].len+2);\n   \
    \ A.emplace_back(v_idx);\n    \n    return true;\n  }\n\n  size_t num_unique_palindrome()\
    \ const noexcept {\n    return nodes.size()-2;\n  }\n};\n\n#line 85 \"String/PalindromicTree.cpp\"\
    \nusing namespace std;\n\nvoid solve(){\n  string s, t;\n  cin >> s >> t;\n  const\
    \ int alphabet_size = 26;\n  PalindromicTree<char,alphabet_size,'A'> S, T;\n\n\
    \  for(auto c : s)\n    S.push_back(c);\n  for(auto c : t)\n    T.push_back(c);\n\
    \  \n  for(int i = S.nodes.size()-1; i >= 0; --i){\n    int sl = S.nodes[i].suffix_link;\n\
    \    if(sl < 0) continue;\n    S.nodes[sl].cnt += S.nodes[i].cnt;\n  }\n  for(int\
    \ i = T.nodes.size()-1; i >= 0; --i){\n    int sl = T.nodes[i].suffix_link;\n\
    \    if(sl < 0) continue;\n    T.nodes[sl].cnt += T.nodes[i].cnt;\n  }\n  \n \
    \ auto solve = [&](auto&& solve, const int& vs, const int& vt) -> long long {\n\
    \    long long ret = 0;\n    if(S.nodes[vs].len > 0){\n      long long cnt = (long\
    \ long)(S.nodes[vs].cnt)*T.nodes[vt].cnt;\n      ret += cnt;\n    }\n    for(int\
    \ i = 0; i < alphabet_size; ++i){\n      int us = S.nodes[vs].ch[i], ut = T.nodes[vt].ch[i];\n\
    \      if(us < 0 or ut < 0)\n        continue;\n      ret += solve(solve,us,ut);\n\
    \    }\n    return ret;\n  };\n\n  long long ans = solve(solve,0,0) + solve(solve,1,1);\n\
    \  cout << ans << endl;\n}\n\n// void debug(){\n//   string s;\n//   cin >> s;\n\
    //   const int alphabet_size = 26;\n//   PalindromicTree<char,alphabet_size,'a'>\
    \ eerTree;\n//   for(auto c : s){\n//     eerTree.push_back(c);\n//   }\n//  \
    \ for(size_t i = 0; i < eerTree.nodes.size(); ++i){\n//     cerr << \"Node \"\
    \ << i << \"\\n\";\n//     eerTree.nodes[i].dump();\n//   }\n//   cout << eerTree.num_unique_palindrome()\
    \ << endl;\n// }\n\nint main(){\n  solve();\n  // debug();\n}\n"
  code: "#include <cassert>\n#include <vector>\n#include <array>\n#include <iostream>\n\
    \ntemplate<typename T, int alphabetSize, T min_element>\nclass PalindromicTree\
    \ {\n\n  struct Node {\n    const int suffix_link;\n    std::array<int,alphabetSize>\
    \ ch;\n    const int len;\n    int cnt;\n\n    Node(int suffix_link, int len)\
    \ :\n      suffix_link(suffix_link), ch(), len(len), cnt(1) {\n      std::fill(ch.begin(),\
    \ ch.end(), -1);\n    };\n\n    // void dump(){\n    //   std::cerr << \"cnt \
    \              : \" << cnt << \"\\n\";\n    //   std::cerr << \"suffix_link  \
    \     : \" << suffix_link << \"\\n\";\n    //   for(int j = 0; j < alphabetSize;\
    \ ++j){\n    //     if(ch[j] >= 0){\n    //       std::cout << std::string(1,'a'+j)\
    \ << \" \" << ch[j] << std::endl;\n    //     }\n    //   }\n    //   std::cerr\
    \ << \"\\n\";\n    // }\n  };\n\npublic:\n\n  std::vector<Node> nodes;\n  std::vector<T>\
    \ dat;\n  int len;\n  std::vector<int> A;\n\n  PalindromicTree() : nodes({Node(-1,-1),\
    \ Node(0,0)}), dat(), len(0), A() {}\n\n  bool push_back(T c){\n    dat.emplace_back(c);\n\
    \    ++len;\n    int parent_idx = A.empty() ? 0 : A.back();\n    // std::cerr\
    \ << parent_idx << \" \" << len-2-nodes[parent_idx].len << std::endl;\n    while(len-2-nodes[parent_idx].len\
    \ < 0 or dat[len-2-nodes[parent_idx].len] != c){\n      parent_idx = nodes[parent_idx].suffix_link;\n\
    \    }\n\n    int v_idx = nodes[parent_idx].ch[c-min_element];\n\n    if(v_idx\
    \ != -1){\n      ++nodes[v_idx].cnt;\n      A.emplace_back(v_idx);\n      return\
    \ false;\n    }\n\n    int suffix_link = nodes[parent_idx].suffix_link;\n    while(suffix_link\
    \ >= 0 and (len-2-nodes[suffix_link].len < 0 or dat[len-2-nodes[suffix_link].len]\
    \ != c)){\n      suffix_link = nodes[suffix_link].suffix_link;\n    }\n\n\n  \
    \  if(suffix_link >= 0 and len-2-nodes[suffix_link].len >= 0 and dat[len-2-nodes[suffix_link].len]\
    \ == c){\n      assert(nodes[suffix_link].ch[c-min_element] >= 0);\n      suffix_link\
    \ = nodes[suffix_link].ch[c-min_element];\n    }\n\n    if(suffix_link < 0) suffix_link\
    \ = 1;\n    \n    v_idx = nodes.size();\n    nodes[parent_idx].ch[c-min_element]\
    \ = v_idx;\n    nodes.emplace_back(suffix_link,nodes[parent_idx].len+2);\n   \
    \ A.emplace_back(v_idx);\n    \n    return true;\n  }\n\n  size_t num_unique_palindrome()\
    \ const noexcept {\n    return nodes.size()-2;\n  }\n};\n\n#include <iostream>\n\
    using namespace std;\n\nvoid solve(){\n  string s, t;\n  cin >> s >> t;\n  const\
    \ int alphabet_size = 26;\n  PalindromicTree<char,alphabet_size,'A'> S, T;\n\n\
    \  for(auto c : s)\n    S.push_back(c);\n  for(auto c : t)\n    T.push_back(c);\n\
    \  \n  for(int i = S.nodes.size()-1; i >= 0; --i){\n    int sl = S.nodes[i].suffix_link;\n\
    \    if(sl < 0) continue;\n    S.nodes[sl].cnt += S.nodes[i].cnt;\n  }\n  for(int\
    \ i = T.nodes.size()-1; i >= 0; --i){\n    int sl = T.nodes[i].suffix_link;\n\
    \    if(sl < 0) continue;\n    T.nodes[sl].cnt += T.nodes[i].cnt;\n  }\n  \n \
    \ auto solve = [&](auto&& solve, const int& vs, const int& vt) -> long long {\n\
    \    long long ret = 0;\n    if(S.nodes[vs].len > 0){\n      long long cnt = (long\
    \ long)(S.nodes[vs].cnt)*T.nodes[vt].cnt;\n      ret += cnt;\n    }\n    for(int\
    \ i = 0; i < alphabet_size; ++i){\n      int us = S.nodes[vs].ch[i], ut = T.nodes[vt].ch[i];\n\
    \      if(us < 0 or ut < 0)\n        continue;\n      ret += solve(solve,us,ut);\n\
    \    }\n    return ret;\n  };\n\n  long long ans = solve(solve,0,0) + solve(solve,1,1);\n\
    \  cout << ans << endl;\n}\n\n// void debug(){\n//   string s;\n//   cin >> s;\n\
    //   const int alphabet_size = 26;\n//   PalindromicTree<char,alphabet_size,'a'>\
    \ eerTree;\n//   for(auto c : s){\n//     eerTree.push_back(c);\n//   }\n//  \
    \ for(size_t i = 0; i < eerTree.nodes.size(); ++i){\n//     cerr << \"Node \"\
    \ << i << \"\\n\";\n//     eerTree.nodes[i].dump();\n//   }\n//   cout << eerTree.num_unique_palindrome()\
    \ << endl;\n// }\n\nint main(){\n  solve();\n  // debug();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/PalindromicTree.cpp
  requiredBy: []
  timestamp: '2020-12-13 02:05:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/PalindromicTree.cpp
layout: document
redirect_from:
- /library/String/PalindromicTree.cpp
- /library/String/PalindromicTree.cpp.html
title: String/PalindromicTree.cpp
---
