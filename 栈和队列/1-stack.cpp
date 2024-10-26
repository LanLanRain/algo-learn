// https://leetcode.cn/problems/valid-parentheses/description/
// 在任意一个位置上，左括号数量 >= 右括号数量
// 在最后一个位置上，左括号数量 == 右括号数量
// 程序中只需要记录左括号数量和右括号数量



// bool isValid(char *s)
// {
//     char *stack = (char *)malloc(strlen(s) * sizeof(char));
//     int top = -1;
//     if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//     {
//         top++;
//         stack[top] = s[i];
//     }
//     else
//     {
//         if (top == -1)
//             return false;
//         if ((s[i] == ')' && stack[top] == '(') || (s[i] == ']' && stack[top] == '[') ||
//             (s[i] == '}' && stack[top] == '{'))
//             top--;
//         else
//             return false;
//     }
//     free(stack);
//     return top == -1;
// }

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义栈结构
typedef struct Stack
{
    char *data; // 用于存储字符数据
    int size;   // 栈的容量
    int top;    // 栈顶索引，-1 表示栈为空
} Stack;

// 初始化栈
Stack *initStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));  // 分配栈的内存
    s->data = (char *)malloc(sizeof(char) * n); // 分配数据内存
    s->size = n;                                // 设置栈的大小
    s->top = -1;                                // 初始化栈顶索引
    return s;
}

// 检查栈是否为空
bool empty(Stack *s)
{
    return s->top == -1;
}

// 获取栈顶元素的值
char top(Stack *s)
{
    if (empty(s))
        return '\0'; // 返回 '\0' 表示错误
    return s->data[s->top];
}

// 向栈中插入元素
bool push(Stack *s, char val)
{
    if (s->top + 1 == s->size) // 检查栈是否已满
        return false;
    s->data[++s->top] = val; // 插入值并更新栈顶索引
    return true;
}

// 从栈中弹出元素
bool pop(Stack *s)
{
    if (empty(s))
        return false;
    s->top--; // 更新栈顶索引
    return true;
}

// 释放栈的内存
void clearStack(Stack *s)
{
    if (s == NULL)
        return;
    free(s->data);
    free(s);
}

// 判断括号字符串是否有效
bool isValid(char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++; // 计算字符串长度

    Stack *stack = initStack(len); // 初始化栈

    for (int i = 0; i < len; i++)
    {
        char ch = s[i];

        // 如果是左括号，压入栈
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(stack, ch);
        }
        else
        {
            // 如果是右括号，检查栈顶是否匹配
            if (empty(stack))
            {
                clearStack(stack);
                return false;
            }

            char topChar = top(stack);

            // 检查当前右括号是否匹配栈顶的左括号
            if ((ch == ')' && topChar != '(') || (ch == '}' && topChar != '{') || (ch == ']' && topChar != '['))
            {
                clearStack(stack);
                return false;
            }
            pop(stack);
        }
    }

    bool isValid = empty(stack); // 检查栈是否为空
    clearStack(stack);
    return isValid;
}

// 主函数测试
int main()
{
    char *test1 = "()";
    char *test2 = "()[]{}";
    char *test3 = "(]";
    char *test4 = "([])";

    printf("测试1: %s -> %s\n", test1, isValid(test1) ? "true" : "false");
    printf("测试2: %s -> %s\n", test2, isValid(test2) ? "true" : "false");
    printf("测试3: %s -> %s\n", test3, isValid(test3) ? "true" : "false");
    printf("测试4: %s -> %s\n", test4, isValid(test4) ? "true" : "false");

    return 0;
}
