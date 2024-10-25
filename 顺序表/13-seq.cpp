// https://leetcode.cn/problems/remove-element/description/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] == val) {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                r--;
            } else {
                l++;
            }
        }
        return r + 1;
    }
};