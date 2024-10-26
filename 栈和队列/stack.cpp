#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义栈结构
typedef struct Stack
{
    int *data; // 存储栈数据的指针
    int size;  // 栈的最大容量
    int top;   // 栈顶索引，-1 表示栈为空
} Stack;

// 初始化栈
Stack *initStack(int n)
{
    Stack *s = (Stack *)malloc(sizeof(Stack)); // 分配栈的内存
    s->data = (int *)malloc(sizeof(int) * n);  // 分配存储数据的内存
    s->size = n;                               // 设置栈的大小
    s->top = -1;                               // 初始化栈顶索引
    return s;
}

// 检查栈是否为空
int empty(Stack *s)
{
    return s->top == -1; // 如果栈顶索引为-1，表示栈为空
}

// 获取栈顶元素的值
int top(Stack *s)
{
    if (empty(s))
        return -1;          // 如果栈为空，返回-1表示错误
    return s->data[s->top]; // 返回栈顶元素
}

// 向栈中插入元素
int push(Stack *s, int val)
{
    // 检查栈是否已满
    if (s->top + 1 == s->size)
        return 0;          // 返回0表示插入失败
    s->top += 1;           // 增加栈顶索引
    s->data[s->top] = val; // 插入值
    return 1;              // 返回1表示插入成功
}

// 从栈中弹出元素
int pop(Stack *s)
{
    // 检查栈是否为空
    if (empty(s))
        return 0; // 返回0表示弹出失败
    s->top -= 1;  // 减少栈顶索引
    return 1;     // 返回1表示弹出成功
}

// 释放栈的内存
void clearStack(Stack *s)
{
    if (s == NULL)
        return;    // 如果指针为空，直接返回
    free(s->data); // 释放数据内存
    free(s);       // 释放栈的结构内存
    return;
}

// 主函数
int main()
{
    // 初始化一个大小为5的栈
    Stack *s = initStack(5);

    // 测试栈的操作
    printf("栈是否为空: %d\n", empty(s)); // 应该输出 1 (真)

    // 向栈中插入元素
    for (int i = 0; i < 5; i++)
    {
        if (push(s, i + 1))
        {
            printf("插入 %d 成功\n", i + 1);
        }
        else
        {
            printf("插入 %d 失败\n", i + 1);
        }
    }

    // 再次检查栈是否为空
    printf("栈是否为空: %d\n", empty(s)); // 应该输出 0 (假)

    // 输出栈顶元素
    printf("栈顶元素: %d\n", top(s)); // 应该输出 5

    // 从栈中弹出元素
    for (int i = 0; i < 5; i++)
    {
        if (pop(s))
        {
            printf("弹出成功\n");
        }
        else
        {
            printf("弹出失败\n");
        }
    }

    // 检查栈是否为空
    printf("栈是否为空: %d\n", empty(s)); // 应该输出 1 (真)

    // 释放栈内存
    clearStack(s);

    return 0;
}
