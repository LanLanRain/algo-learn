// https://leetcode.cn/problems/number-of-arithmetic-triplets/description/

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ret = 0;
        for (int j = 0; j < nums.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (nums[j] - nums[i] == diff) {
                    for (int k = j + 1; k < nums.size(); k++) {
                        if (nums[k] - nums[j] == diff)
                            ret++;
                    }
                }
            }
        }
        return ret;
    }
};