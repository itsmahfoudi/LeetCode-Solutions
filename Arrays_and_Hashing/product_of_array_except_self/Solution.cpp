class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeroCount = 0;
        for (int num : nums) {
            if (num != 0) {
                product *= num;
            } else {
                zeroCount++;
            }
        }
        if (zeroCount > 1) {
            return std::vector<int> (nums.size(),0);
        }
        std::vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount > 0) {
                result[i] = (nums[i] == 0) ? product : 0;
            } else {
                result[i] = product / nums[i];
            }
        }
        return result;
    }
};

