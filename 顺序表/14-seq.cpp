// https://leetcode.cn/problems/build-array-from-permutation/description/
class Solution
{
  public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};