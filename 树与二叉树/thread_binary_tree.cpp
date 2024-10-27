#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义树节点结构
typedef struct Node {
    int key;             // 节点存储的值
    struct Node *lchild; // 指向左子节点的指针
    struct Node *rchild; // 指向右子节点的指针
} Node;

// 创建新节点并初始化
Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node)); // 动态分配内存
    p->key = key;                           // 设置节点值
    p->lchild = p->rchild = NULL;           // 左右子节点指针初始化为NULL
    return p;
}

// 在二叉树中插入新节点
Node *insert(Node *root, int key) {
    if (root == NULL) 
        return getNewNode(key);
    
    if (rand() % 2) 
        root->lchild = insert(root->lchild, key);
    else 
        root->rchild = insert(root->rchild, key);
    
    return root;
}

// 前序遍历
void pre_order(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->key);         // 访问根节点
    pre_order(root->lchild);           // 递归遍历左子树
    pre_order(root->rchild);           // 递归遍历右子树
}

// 中序遍历
void in_order(Node *root) {
    if (root == NULL)
        return;
    in_order(root->lchild);            // 递归遍历左子树
    printf("%d ", root->key);          // 访问根节点
    in_order(root->rchild);            // 递归遍历右子树
}

// 后序遍历
void post_order(Node *root) {
    if (root == NULL)
        return;
    post_order(root->lchild);          // 递归遍历左子树
    post_order(root->rchild);          // 递归遍历右子树
    printf("%d ", root->key);          // 访问根节点
}

// 释放二叉树占用的内存
void clear(Node *p) {
    if (p == NULL) 
        return;
    clear(p->lchild);
    clear(p->rchild);
    free(p);
}

// 主函数
int main() {
    srand(time(0)); // 使用当前时间作为随机种子
    Node *root = NULL; // 初始化根节点为空

    // 随机插入10个节点，值在0到99之间
    for (int i = 0; i < 10; i++)
        root = insert(root, rand() % 100);

    // 打印前序遍历结果
    printf("前序遍历结果:\n");
    pre_order(root);
    printf("\n");

    // 打印中序遍历结果
    printf("中序遍历结果:\n");
    in_order(root);
    printf("\n");

    // 打印后序遍历结果
    printf("后序遍历结果:\n");
    post_order(root);
    printf("\n");

    clear(root); // 释放动态分配的内存
    return 0;    // 结束程序
}
