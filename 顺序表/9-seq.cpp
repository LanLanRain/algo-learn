// https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/description/

// 对每个元素进行检查，如果当前元素大于 max1，则更新 max2 为 max1，并将 max1 更新为当前元素。
// 如果当前元素不大于 max1，但大于 max2，则更新 max2。
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        // 初始化最大和次大的值
        int max1 = 0, max2 = 0;
        
        // 遍历数组找到前两个最大值
        for (int num : nums) {
            if (num > max1) {
                max2 = max1; // 更新第二大为前大的值
                max1 = num;  // 更新最大值
            } else if (num > max2) {
                max2 = num; // 更新次大值
            }
        }

        // 返回最大乘积
        return (max1 - 1) * (max2 - 1);
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxIdx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }
        int subMaxIdx = (maxIdx == 0) ? 1 : 0; // 初始化次大值下标
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[subMaxIdx] && i != maxIdx)
                subMaxIdx = i;
        }
        return (nums[maxIdx] - 1) * (nums[subMaxIdx] - 1);
    }
};