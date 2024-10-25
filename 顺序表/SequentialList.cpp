#include <iostream>
#include <stdexcept> // 添加头文件用于异常处理

using namespace std;

#define eleType int

// 定义顺序列表结构
struct SequentialList
{
    eleType *elements; // 存储元素的动态数组
    int size;          // 当前元素数量
    int capacity;      // 数组的容量
};

// 初始化顺序列表
void initializeList(SequentialList *list, int capacity)
{
    list->elements = new eleType[capacity]; // 分配初始内存
    list->capacity = capacity;              // 设置容量
    list->size = 0;                         // 初始化大小为0，修正为赋值语句
}

// 销毁顺序列表，释放内存
void destroyList(SequentialList *list)
{
    delete[] list->elements; // 释放动态数组内存
}

// 获取顺序列表的大小
int size(SequentialList *list)
{
    return list->size; // 返回当前元素数量
}

// 判断顺序列表是否为空
bool isEmpty(SequentialList *list)
{
    return list->size == 0; // 若大小为0，返回true
}

// 在指定位置插入新元素
void insert(SequentialList *list, int index, eleType element)
{
    if (index < 0 || index > list->size) // 检查索引是否有效
    {
        throw std::invalid_argument("Invalid index");
    }

    // 如果列表已满，扩展容量
    if (list->size == list->capacity)
    {
        int newCapacity = list->capacity * 2;            // 新容量为原来的两倍
        eleType *newElements = new eleType[newCapacity]; // 分配新数组
        for (int i = 0; i < list->size; i++)
        {
            newElements[i] = list->elements[i]; // 复制原数组元素
        }
        delete[] list->elements;      // 释放原数组内存
        list->elements = newElements; // 更新元素指针
        list->capacity = newCapacity; // 更新容量
    }

    // 移动元素以插入新元素
    for (int i = list->size; i > index; i--)
    {
        list->elements[i] = list->elements[i - 1]; // 向后移动元素
    }
    list->elements[index] = element; // 插入新元素
    list->size++;                    // 增加大小
}

// 删除指定位置的元素
void deleteElement(SequentialList *list, int index)
{
    if (index < 0 || index >= list->size) // 检查索引是否有效
    {
        throw std::invalid_argument("Invalid index");
    }

    // 移动元素以覆盖被删除的元素
    for (int i = index; i < list->size - 1; i++)
    {
        list->elements[i] = list->elements[i + 1]; // 向前移动元素
    }
    list->size--; // 减少大小
}

// 查找元素并返回其索引，未找到返回-1
int findElement(SequentialList *list, eleType element)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->elements[i] == element) // 找到元素
            return i;                     // 返回索引
    }
    return -1; // 未找到
}

// 获取指定位置的元素
eleType getElement(SequentialList *list, int index)
{
    if (index < 0 || index >= list->size) // 检查索引是否有效
    {
        throw std::invalid_argument("Invalid index");
    }
    return list->elements[index]; // 返回元素
}

// 更新指定位置的元素
void updateElement(SequentialList *list, int index, eleType value)
{
    if (index < 0 || index >= list->size) // 检查索引是否有效
    {
        throw std::invalid_argument("Invalid index");
    }
    list->elements[index] = value; // 更新元素
}

// 测试程序
int main()
{
    SequentialList list;
    initializeList(&list, 2); // 初始化容量为2

    // 插入元素
    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 1, 15); // 在索引1插入元素15

    // 打印当前元素
    for (int i = 0; i < size(&list); i++)
    {
        cout << getElement(&list, i) << " "; // 输出: 10 15 20
    }
    cout << endl;

    // 查找元素
    cout << "Index of 15: " << findElement(&list, 15) << endl; // 输出: 1

    // 更新元素
    updateElement(&list, 0, 5); // 更新索引0的元素为5

    // 删除元素
    deleteElement(&list, 1); // 删除索引1的元素

    // 打印最终元素
    for (int i = 0; i < size(&list); i++)
    {
        cout << getElement(&list, i) << " "; // 输出: 5 20
    }
    cout << endl;

    // 销毁列表
    destroyList(&list);

    return 0; 
}
