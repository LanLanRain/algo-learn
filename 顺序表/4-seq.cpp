// https://leetcode.cn/problems/guess-numbers/
class Solution
{
  public:
    int game(vector<int> &guess, vector<int> &answer)
    {
        int ret = 0;
        for (int i = 0; i < 3; i++)
        {
            if (guess[i] == answer[i])
                ret++;
        }
        return ret;
    }
};
