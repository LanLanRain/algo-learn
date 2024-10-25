// https://leetcode.cn/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0, prev = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                prev = prev + 1;
                if (prev > ret)
                    ret = prev;
            } else {
                prev = 0;
            }
        }
        return ret;
    }
};