#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义树节点结构
typedef struct Node
{
    int key;                // 节点存储的值
    struct Node *lchild;    // 指向左子节点的指针
    struct Node *rchild;    // 指向右子节点的指针
} Node;

// 创建新节点并初始化
Node *getNewNode(int key)
{
    Node *p = (Node *)malloc(sizeof(Node)); // 动态分配内存
    p->key = key;                           // 设置节点值
    p->lchild = p->rchild = NULL;           // 左右子节点指针初始化为NULL
    return p;
}

// 在二叉树中插入新节点
Node *insert(Node *root, int key)
{
    // 如果当前树为空，则返回新节点作为根节点
    if (root == NULL)
        return getNewNode(key);
    
    // 随机选择将节点插入左子树或右子树
    if (rand() % 2)
        root->lchild = insert(root->lchild, key); // 插入左子树
    else
        root->rchild = insert(root->rchild, key); // 插入右子树
    
    return root; // 返回当前节点
}

// 释放二叉树占用的内存
void clear(Node *p)
{
    if (p == NULL) // 如果节点为空，直接返回
        return;
    clear(p->lchild); // 递归清除左子树
    clear(p->rchild); // 递归清除右子树
    free(p);         // 释放当前节点的内存
}

#define MAX_NODE 10 // 定义最大节点数

// 广度优先遍历需要的队列
Node *queue[MAX_NODE + 5]; // 用于存储节点的队列
int head = 0, tail = 0;     // 队列的头和尾

// 广度优先遍历 (BFS)
void bfs(Node *root)
{
    if (root == NULL) return; // 如果树为空，直接返回
    queue[tail++] = root;     // 将根节点入队
    while (head < tail)       // 当队列不为空时
    {
        Node *node = queue[head++]; // 出队
        printf("%d ", node->key);     // 打印当前节点的值
        if (node->lchild)
            queue[tail++] = node->lchild; // 如果有左子节点，将其入队
        if (node->rchild)
            queue[tail++] = node->rchild; // 如果有右子节点，将其入队
    }
}

// 深度优先遍历 (DFS)
void dfs(Node *root) {
    if (root == NULL) return; // 如果节点为空，直接返回
    printf("%d ", root->key);  // 打印当前节点的值
    dfs(root->lchild);         // 递归遍历左子树
    dfs(root->rchild);         // 递归遍历右子树
}

// 主函数
int main()
{
    srand(time(0)); // 使用当前时间作为随机种子
    Node *root = NULL; // 初始化根节点为空
    for (int i = 0; i < MAX_NODE; i++)
        root = insert(root, rand() % 100); // 随机插入10个节点，值在0到99之间

    // 打印广度优先遍历结果
    printf("广度优先遍历 (BFS) 结果:\n");
    bfs(root);
    printf("\n");

    // 打印深度优先遍历结果
    printf("深度优先遍历 (DFS) 结果:\n");
    dfs(root);
    printf("\n");

    clear(root);  // 释放动态分配的内存
    return 0;     // 结束程序
}
