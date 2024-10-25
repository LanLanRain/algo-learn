// https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k/description/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] - nums[j] == k)
                    ret++;
            }
        }
        return ret;
    }
};