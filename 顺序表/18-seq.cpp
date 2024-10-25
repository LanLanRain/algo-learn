// https://leetcode.cn/problems/pascals-triangle-ii/description/

class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        int f[34][34] = {0}; // 初始化二维数组，默认所有值为0

        // 构建杨辉三角的前 rowIndex 行
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    f[i][j] = 1; // 边界元素为 1
                else
                    f[i][j] = f[i - 1][j] + f[i - 1][j - 1]; // 非边界元素为上两数之和
            }
        }

        // 将第 rowIndex 行元素填入返回结果
        vector<int> ret;
        for (int i = 0; i <= rowIndex; i++)
        {
            ret.push_back(f[rowIndex][i]);
        }
        return ret;
    }
};
