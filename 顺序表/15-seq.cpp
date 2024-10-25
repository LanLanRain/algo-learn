// https://leetcode.cn/problems/concatenation-of-array/description/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
               int n = nums.size();
        std::vector<int> ans(2 * n); // 预先设置大小为 2n
        
        // 填充前 n 个元素
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i]; // 直接填充后 n 个元素
        }
        
        return ans;

    }
};