#include <vector>
#include <unordered_set>

class Solution {
  public:
    int longestConsecutive(std::vector<int>& nums) {
      int max = 0;
      std::unordered_set<int> values(nums.begin(),nums.end(), nums.size());
      for (int val : values) {
        if (values.find(val-1) == values.end()) {
            int length = 1;
            while (values.find(val+length) != values.end()) {
                length++;
            }
            max = (max > length) ? max : length;
        }
      } 
      return max;
    }
};
