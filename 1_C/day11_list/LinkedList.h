#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * @brief C语言是一个面向过程的语言，他没有类，因此无法分门别类，一切都是函数
 * 对于自定义结构体的操作，仍然是一个又一个全局函数完成操作，没有成员函数的概念
 * 因此不要混淆；C就是自定义结构体+函数，没有基于对象的过程
 */

#include <stdbool.h>
#include <stddef.h>

typedef int DataType;

typedef struct node_s {
    DataType data;  // 数据域
    struct node_s *next;    // 指针域
} Node;

typedef struct {
    Node *head;     // 链表头指针
    Node *tail;     // 链表尾指针
    int size;       // 链表大小
} LinkedList;

// 创建链表
LinkedList *create_linked_list();
// 销毁链表
void destroy_linked_list(LinkedList *list);
// 打印链表 1 -> 2 -> 3 -> 4
void print_linked_list(LinkedList *list);
// insert
bool insert_by_idx(LinkedList *list, size_t idx, DataType val);
bool insert_before_head(LinkedList *list, DataType val);
bool insert_after_tail(LinkedList *list, DataType val);
// delete
bool delete_by_val(LinkedList *list, DataType target);
bool delete_by_idx(LinkedList *list, size_t idx);
// query，链表就是由一个又一个节点组成的，所以要是查找的话，应该查找的就是节点
Node *search_by_val(LinkedList *list, DataType target);
Node *search_by_idx(LinkedList *list, size_t idx);
// modify
void modify_by_val(LinkedList *list, DataType target, DataType newVal);




#endif  // !LINKED_LIST_H