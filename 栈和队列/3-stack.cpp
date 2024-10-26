#include <stdbool.h>
#include <stdio.h>

bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize)
{
    int stack[pushedSize]; // 用数组模拟栈
    int top = -1;          // 栈顶指针初始化为 -1
    int j = 0;             // 指向 popped 数组的当前元素

    // 遍历 pushed 数组，模拟入栈操作
    for (int i = 0; i < pushedSize; i++)
    {
        stack[++top] = pushed[i]; // 元素入栈

        // 检查栈顶元素是否与 popped 当前元素匹配
        while (top != -1 && stack[top] == popped[j])
        {
            top--; // 出栈
            j++;   // 指向 popped 中的下一个元素
        }
    }

    // 如果栈为空，则表示成功匹配，返回 true；否则返回 false
    return top == -1;
}

// 测试代码
int main()
{
    int pushed1[] = {1, 2, 3, 4, 5};
    int popped1[] = {4, 5, 3, 2, 1};
    printf("测试1: %s\n", validateStackSequences(pushed1, 5, popped1, 5) ? "true" : "false");

    int pushed2[] = {1, 2, 3, 4, 5};
    int popped2[] = {4, 3, 5, 1, 2};
    printf("测试2: %s\n", validateStackSequences(pushed2, 5, popped2, 5) ? "true" : "false");

    return 0;
}
