#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// 宏定义不需要;但是类型别名需要使用;
typedef int DataType;

typedef struct node_s {
    DataType date;
    struct node_s *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList *linkedlist_create();
void linkedlist_destroy(LinkedList *list);
void linkedlist_print(LinkedList *list);

// 头插法
bool add_before_head(LinkedList *list, DataType val);
// 尾插法
bool add_behind_tail(LinkedList *list, DataType val);
// 根据索引插入一个新节点
bool add_by_idx(LinkedList *list, int idx, DataType val);
// 根据索引搜索一个节点
Node *search_by_idx(LinkedList *list, int idx);
// 根据数据搜索一个节点
Node *search_by_data(LinkedList *list, DataType data);
// 根据数据删除一个节点
void linkedlist_delete_head(LinkedList *list);
void linkedlist_delete_tail(LinkedList *list);


#endif