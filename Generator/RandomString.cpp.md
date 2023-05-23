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
  bundledCode: "#line 1 \"Generator/RandomString.cpp\"\n#include <random>\n\nclass\
    \ RandomStringGenerator {\n  std::string alphabet_;\n  std::mt19937 engine;\n\
    public:\n  RandomStringGenerator(std::string alphabet) : alphabet_(alphabet) {\n\
    \    std::random_device seed_gen;\n    engine = std::mt19937(seed_gen());\n  }\n\
    \  std::string generate(int min_len=1, int max_len=10) { // min_len <= len < max_len\n\
    \    int d = max_len - min_len;\n    int len = engine()%d + min_len;\n    std::string\
    \ ret(len,alphabet_[0]);\n    for(char& c: ret){\n      c += engine()%alphabet_.length();\n\
    \    }\n    return ret;\n  }\n};\n\nconst std::string lower_alphabet = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\nconst std::string upper_alphabet = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\n\nRandomStringGenerator\
    \ lower_string_generator(lower_alphabet);\nRandomStringGenerator upper_string_generator(upper_alphabet);\n"
  code: "#include <random>\n\nclass RandomStringGenerator {\n  std::string alphabet_;\n\
    \  std::mt19937 engine;\npublic:\n  RandomStringGenerator(std::string alphabet)\
    \ : alphabet_(alphabet) {\n    std::random_device seed_gen;\n    engine = std::mt19937(seed_gen());\n\
    \  }\n  std::string generate(int min_len=1, int max_len=10) { // min_len <= len\
    \ < max_len\n    int d = max_len - min_len;\n    int len = engine()%d + min_len;\n\
    \    std::string ret(len,alphabet_[0]);\n    for(char& c: ret){\n      c += engine()%alphabet_.length();\n\
    \    }\n    return ret;\n  }\n};\n\nconst std::string lower_alphabet = \"abcdefghijklmnopqrstuvwxyz\"\
    ;\nconst std::string upper_alphabet = \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\";\n\nRandomStringGenerator\
    \ lower_string_generator(lower_alphabet);\nRandomStringGenerator upper_string_generator(upper_alphabet);\n"
  dependsOn: []
  isVerificationFile: false
  path: Generator/RandomString.cpp
  requiredBy: []
  timestamp: '2023-05-23 20:32:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Generator/RandomString.cpp
layout: document
redirect_from:
- /library/Generator/RandomString.cpp
- /library/Generator/RandomString.cpp.html
title: Generator/RandomString.cpp
---
