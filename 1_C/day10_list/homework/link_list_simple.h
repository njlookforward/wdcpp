#ifndef LINK_LIST_SIMPLE_H
#define LINK_LIST_SIMPLE_H

#include <stdio.h>
#include <stdlib.h>

// 实现弹性编程
typedef int ElementType;

typedef struct node_s {
    ElementType data;
    struct node_s *next;
} Node;

// 头插法
void insert_head(Node **head, ElementType new_val);
// 修改第一个元素的值
void modify_first_node(Node **head, ElementType new_val);
// 尾插法
void insert_tail(Node **head, ElementType new_val);
// 打印单链表 1 -> 2 -> 3
void print_list(Node *head);



#endif