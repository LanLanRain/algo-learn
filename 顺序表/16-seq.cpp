// https://leetcode.cn/problems/kids-with-the-greatest-number-of-candies/description/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ret;
        int maxCandy = 0;
        for (size_t i = 0; i < candies.size(); i++) {
            if (candies[i] > maxCandy) {
                maxCandy = candies[i];
            }
        }
        for (size_t i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxCandy)
                ret.push_back(true);
            else
                ret.push_back(false);
        }
        return ret;
    }
};