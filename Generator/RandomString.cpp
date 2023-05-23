#include <random>

class RandomStringGenerator {
  std::string alphabet_;
  std::mt19937 engine;
public:
  RandomStringGenerator(std::string alphabet) : alphabet_(alphabet) {
    std::random_device seed_gen;
    engine = std::mt19937(seed_gen());
  }
  std::string generate(int min_len=1, int max_len=10) { // min_len <= len < max_len
    int d = max_len - min_len;
    int len = engine()%d + min_len;
    std::string ret(len,alphabet_[0]);
    for(char& c: ret){
      c += engine()%alphabet_.length();
    }
    return ret;
  }
};

const std::string lower_alphabet = "abcdefghijklmnopqrstuvwxyz";
const std::string upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

RandomStringGenerator lower_string_generator(lower_alphabet);
RandomStringGenerator upper_string_generator(upper_alphabet);
