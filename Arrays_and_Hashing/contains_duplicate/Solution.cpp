#include <set>
#include <vector>
class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::set<int> array;
        for (int& ele : nums) {
            array.insert(ele);
        }
        return array.size() != nums.size();
    }
};
