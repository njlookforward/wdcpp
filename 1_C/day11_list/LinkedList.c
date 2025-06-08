#include "LinkedList.h"
// 哪里需要用到这里头文件，就将这些头文件放在哪里，不要一股脑放在头文件中
#include <stdio.h>
#include <stdlib.h>

// 对于链表中的指针，都必须先判断是否为空，再进行处理
// 对于每一个函数，进入函数，第一件事就是对形参进行检查，确定是否有效
// 创建链表
LinkedList *create_linked_list() {
    LinkedList *list = calloc(1, sizeof(LinkedList));
    if(list == NULL) {
        printf("LinkedList *create_linked_list() error: calloc failed!\n");
        return NULL;
    }

    return list;
}

// 销毁链表
void destroy_linked_list(LinkedList *list) {
    if(list == NULL) return;

    while (list->head != NULL)
    {
        Node *nextHead = list->head->next;
        free(list->head);
        list->head = nextHead;
    }
    
    free(list);
    return;
}

// 打印链表 1 -> 2 -> 3 -> 4
void print_linked_list(LinkedList *list) {
    if(list == NULL) return;
    Node *cur_node = list->head;
    while (cur_node != NULL)
    {
        printf("%d", cur_node->data);
        if(cur_node->next != NULL)
            printf(" -> ");
        cur_node = cur_node->next;    
    }   
}
// insert
bool insert_by_idx(LinkedList *list, size_t idx, DataType val) {
    if(list == NULL || idx < 0 || idx >list->size) return false;

    // 先创建节点，再根据未知的不同进行插入
    Node *new_node = calloc(1, sizeof(Node));
    if(new_node == NULL) {
        printf("bool insert_by_idx() error: calloc failed.\n");
        return false;
    }
    new_node->data = val;

    if(idx == 0) {
        new_node->next = list->head;
        list->head = new_node;
        if(list->tail == NULL)
            list->tail = new_node;
        
        list->size++;
        return true;
    }

    Node *pre_node = list->head;
    for(int i = 0; i < idx - 1; i++) {
        pre_node = pre_node->next;
    }
    new_node->next = pre_node->next;
    pre_node->next = new_node;
    if(new_node->next == NULL)
        list->tail = new_node;
    list->size++;
    return true;
}

bool insert_before_head(LinkedList *list, DataType val) {
    if(list == NULL) return false;
    Node *new_node = calloc(1, sizeof(Node));
    if(new_node == NULL) {
        printf("insert_before_head() failed: calloc.\n");
        return false;
    } 
    new_node->data = val;

    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL)
    {
        list->tail = new_node;
    }
    list->size++;
    
    return true;
}
bool insert_after_tail(LinkedList *list, DataType val) {
    if(list == NULL) return false;

    Node *new_node = calloc(1, sizeof(Node));
    if(new_node == NULL) {
        printf("insert_after_tail() failed.\n");
        return false;
    }
    new_node->data = val;

    if(list->tail == NULL) {
        list->tail = new_node;
        list->head = new_node;
        list->size++;
        return true;
    }
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;
    return true;
}

// delete
bool delete_by_val(LinkedList *list, DataType target) {
    if(list == NULL) return false;

    // 我需要进行遍历，找到目标节点的前驱结点，才能进行删除，还要注意是否为头结点还是尾结点
    Node *pre_node = NULL;
    Node *cur_node = list->head;
    while (cur_node != NULL)
    {
        if(cur_node->data == target) break;
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
    if(cur_node == NULL) return false;
    // 还没完呢，需要考虑控制器中的内容是否需要进行修改
    if(cur_node == list->head) {
        list->head = cur_node->next;
        if(list->tail == cur_node)
            list->tail = NULL;
        free(cur_node);
        list->size--;
        return true;
    }
    pre_node->next = cur_node->next;
    if(cur_node == list->tail)
        list->tail = pre_node;
    free(cur_node);
    list->size--;

    return true;
}

bool delete_by_idx(LinkedList *list, size_t idx) {
    if(list == NULL || idx < 0 || idx >= list->size) return false;
    // 根据idx所在位置的不同，进行不同的删除策略
    if(idx == 0) {
        // 删除头结点
        Node *target_node = list->head;
        list->head = target_node->next;
        if(list->tail == target_node) 
            list->tail = NULL;
        free(target_node);
        list->size--;
        return true;
    } 
    // 删除中间节点和尾节点，需要进行遍历，找到前驱结点
    Node *pre_node = NULL;
    Node *cur_node = list->head;
    while (idx--)
    {
        pre_node = cur_node;
        cur_node = cur_node->next;
    }
    pre_node->next = cur_node->next;
    if(list->tail == cur_node)
        list->tail = pre_node;
    free(cur_node);
    list->size--;
    return true;
}
// query，链表就是由一个又一个节点组成的，所以要是查找的话，应该查找的就是节点
Node *search_by_val(LinkedList *list, DataType target) {
    if(list == NULL) return NULL;
    Node *cur_node = list->head;
    while (cur_node != NULL)
    {
        if(cur_node->data == target) return cur_node;
        cur_node = cur_node->next;
    }

    return NULL;
}
Node *search_by_idx(LinkedList *list, size_t idx) {
    if(list == NULL || idx < 0 || idx >= list->size) return NULL;

    Node *cur_node = list->head;
    while (idx--)
    {
        cur_node = cur_node->next;
    }
    return cur_node;
}
// modify
void modify_by_val(LinkedList *list, DataType target, DataType newVal) {
    // 需要先查找目标值所在节点的位置，然后修改目标值
    Node *node = search_by_val(list, target);
    if(node == NULL) return;
    node->data = newVal;
}
