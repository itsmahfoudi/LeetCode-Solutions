#include <string>
#include <vector>
#include <unordered_map>
#include <array>

class Solution {
  public:
    std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string>& strs) {
      std::vector<std::vector<std::string>> result;
      std::unordered_map<std::string, std::vector<std::string>> mapping;
      std::array<int, 26> occurences;
      occurences.fill(0);
      for (std::string str : strs) {
        for (char ch : str) {
          occurences[ch-'a']++;
        }
        std::string key = std::to_string(occurences[0]);
        for (int i = 1; i < 26; i++) {
          key += ", " + std::to_string(occurences[i]);
        }
        mapping[key].push_back(str); 
        occurences.fill(0);
      }
      
      for (const auto& pair : mapping) {
        result.push_back(pair.second);
      }
      return result;
    }
};
