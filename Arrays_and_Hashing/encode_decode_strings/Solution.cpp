#include <string>
#include <vector>
#include <cctype>

class Solution {
  public:
    std::string encode(std::vector<std::string>& strs) {
      std::string result;
      for(std::string str : strs) {
        result += std::to_string(str.length()) + "#" + str;
      }
      return result;
    }
    std::vector<std::string> decode(std::string s) {
      std::vector<std::string>result;
      std::string len;
      for(int i = 0; i < s.length(); i++) {
        if (s[i] == '#') {
          result.push_back(s.substr(i+1,std::stoi(len)));
          s = s.erase(i,std::stoi(len)+1);
          len.clear();
        }
        if (std::isdigit(s[i])) {
          len += s[i];
        }
      }
      return result;
    }
};
