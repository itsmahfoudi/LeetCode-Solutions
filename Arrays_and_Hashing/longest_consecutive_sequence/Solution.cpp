#include <list>
#include <vector>
#include <unordered_set>

class Solution {
  public:
    int longestConsecutive(std::vector<int>& nums) {
      int max = 0;
      std::list<int> Sequence;
      std::unordered_set<int> values(nums.begin(),nums.end(), nums.size());
      for (int i = 0; i < nums.size(); i++) {
        int val = nums[i];  
        while (values.count(val) > 0) {
          Sequence.push_back(val);
          val++;
        }
        max = (max >= Sequence.size()) ? max : Sequence.size();
        Sequence.clear();
      } 
      return max;
    }
};
