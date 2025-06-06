#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

// 通过使用宏定义可以避免硬编码，会更好一些，方便后面进行修改
#define DEFAULT_CAPACITY 8
#define THRESHOLD 1024

typedef int ElementType;    // 可以方便更改vector中的保存的元素类型

// 要明确一点，C语言是面向过程的语言，尽管结构体，但是都是使用一个又一个函数
// 来实现对应的功能的

/**
 * @brief 该结构体是用来控制可变数组的，是一个控制器
 */
typedef struct {
    ElementType *table;
    int capacity;
    int size;
} Vector;

// 其实按照类的成员函数进行设计就好，基本函数：创建+销毁+增删改查
// 创建新的Vector变量
Vector *vector_create(void);
// 销毁Vector变量
void vector_destroy(Vector *pvec);
// 在后面添加新的元素
void vector_push_back(Vector *pvec, ElementType val);
// 在前面添加新的元素
void vector_push_front(Vector *pvec, ElementType val);
// 将元素val添加到索引为idx的位置
void vector_insert(Vector *pvec, int idx, ElementType val);
// 遍历打印整个Vector动态数组
void vector_print(Vector *pvec);
// 删除最后一个元素
void vector_pop_back(Vector *pvec);
// 删除第一个元素
void vector_pop_front(Vector *pvec);
// 删除索引为idx位置的元素
void vector_pop_index(Vector *pvec, int idx);

#endif