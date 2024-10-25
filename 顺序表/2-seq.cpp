#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 无限循环处理多组输入
    while (true)
    {
        int n;
        cin >> n; // 读取每组数据的数量

        // 当 n 为 0 时结束输入
        if (n == 0)
            break;

        vector<double> numbers(n); // 创建一个存储 n 个数的动态数组

        // 读取 n 个实数
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        int negativeCount = 0; // 负数计数
        int zeroCount = 0;     // 零计数
        int positiveCount = 0; // 正数计数

        // 统计负数、零和正数的个数
        for (double num : numbers)
        {
            if (num < 0)
                negativeCount++;
            else if (num > 0)
                positiveCount++;
            else
                zeroCount++;
        }

        // 输出结果
        cout << negativeCount << " " << zeroCount << " " << positiveCount << endl;
    }

    return 0;
}
