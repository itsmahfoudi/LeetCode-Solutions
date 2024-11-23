#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        int difference;
        std::unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++) {
            difference = target - nums[i];
            if (mapping.find(difference) != mapping.end()) {
                result.push_back(mapping[difference]);
                result.push_back(i);
                break;
            } else {
                mapping[nums[i]] = i;
            }
        }
        return result;
    }
};
