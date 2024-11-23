#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
      std::vector<int>result;
      int max = 1;
      std::unordered_map<int, int> mapping;
      for (int it: nums) {
        if (mapping.find(it) != mapping.end()) { 
          mapping[it] += 1;
        } else {
          mapping[it] = 1;
        }
      }
      std::vector<std::pair<int, int>> vec(mapping.begin(), mapping.end());
      std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
      });
      
      for (int i = 0; i < k && i < vec.size() ; ++i) {
        result.push_back(vec[i].first);
      }
      return result;
    }
};
