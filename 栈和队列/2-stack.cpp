#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 用栈处理字符串，返回最终的处理结果
char *process(const char *str)
{
    int len = strlen(str);
    char *stack = (char *)malloc(len + 1); // 分配内存保存结果
    int top = -1;                          // 栈顶指针

    for (int i = 0; i < len; i++)
    {
        if (str[i] != '#')
            stack[++top] = str[i]; // 普通字符压入栈
        else if (top != -1)
            top--; // 遇到退格符，弹出栈顶字符
    }
    stack[top + 1] = '\0'; // 标记字符串的结束
    return stack;
}

// 比较两个经过退格处理后的字符串是否相等
bool backspaceCompare(char *s, char *t)
{
    char *processedS = process(s); // 处理字符串 s
    char *processedT = process(t); // 处理字符串 t

    bool result = strcmp(processedS, processedT) == 0; // 比较两者是否相等
    free(processedS);                                  // 释放内存
    free(processedT);                                  // 释放内存

    return result;
}

// 测试代码
int main()
{
    char *s1 = "ab#c";
    char *t1 = "ad#c";
    printf("测试1: %s 和 %s -> %s\n", s1, t1, backspaceCompare(s1, t1) ? "true" : "false");

    char *s2 = "ab##";
    char *t2 = "c#d#";
    printf("测试2: %s 和 %s -> %s\n", s2, t2, backspaceCompare(s2, t2) ? "true" : "false");

    char *s3 = "a#c";
    char *t3 = "b";
    printf("测试3: %s 和 %s -> %s\n", s3, t3, backspaceCompare(s3, t3) ? "true" : "false");

    return 0;
}
