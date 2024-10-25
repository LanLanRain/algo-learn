// https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/description/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        // int ret = 0;
        // while (k--) {
        //     int maxIdx = 0;
        //     for (int i = 1; i < nums.size(); i++) {
        //         if (nums[i] > nums[maxIdx]) {
        //             maxIdx = i;
        //         }
        //     }
        //     ret += nums[maxIdx];
        //     nums[maxIdx] += 1;
        // }
        // return ret;
        int maxIdx = 0, sum = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }
        // 累加 k 次，每次在当前最大值上加 1
        for (int i = 0; i < k; i++) {
            sum += nums[maxIdx];
            nums[maxIdx]++; // 更新最大值，每次递增 1
        }
        return sum;
    }
};