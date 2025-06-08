#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef int DataType;

typedef struct node {
    DataType data;
    struct node *next;
} Node;

void insert_after_tail(Node **head, DataType newVal);

// 使用快慢指针求解下面的两个问题
// question1: 求链表中间节点的值
DataType middle_In_LinkedList(Node *head);

// 判断单链表是否有环
bool isCircle(Node *head);

// 打印单链表
void print_linked_list(Node *head);

// 创建有环链表
void create_circled_list(Node *head);

// 反转单链表
Node *reverse_linked_list(Node *list);

// 合并两个单链表
Node *merge_two_list(Node *list1, Node *list2);
// 加头结点的合并两个单链表
Node *merge_two_list_dummyhead(Node *list1, Node *list2);

#endif  // !LINKEDLIST_H