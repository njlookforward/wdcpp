#include "link_list_simple.h"

// 头插法
void insert_head(Node **head, ElementType new_val) {
    // 需要先为新结点分配内存
    Node *new_node = calloc(1, sizeof(Node));
    if(new_node == NULL) {
        printf("insert_head(Node **, ElementType) error: calloc failed!\n");
        exit(-1);
    }
    new_node->data = new_val;

    // 在考虑如何插入到链表中，无论头结点是空还是非空，都是一个道理
    new_node->next = *head;
    *head = new_node;
}

// 修改第一个元素的值
void modify_first_node(Node **head, ElementType new_val) {
    if(*head == NULL) {
        Node *new_node = calloc(1, sizeof(Node));
        if(new_node == NULL) {
            printf("modify_first_node(Node **, ElementType) error: calloc failed!\n");
            exit(-1);
        }
        new_node->data = new_val;
        *head = new_node;
        return;
    }
    (*head)->data = new_val;
    return;
}

// 尾插法
void insert_tail(Node **head, ElementType new_val) {
    // 需要先为新结点分配内存
    Node *new_node = calloc(1, sizeof(Node));
    if(new_node == NULL) {
        printf("insert_tail(Node **, ELementType) error: calloc failed!\n");
        exit(-1);
    }
    new_node->data = new_val;
    // 判断是否为空链表，分情况插入
    if(*head == NULL) {
        *head = new_node;
        return;
    } 
    Node *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new_node;
    return;
}

// 打印单链表 1 -> 2 -> 3
void print_list(Node *head) {
    while (head != NULL)
    {
        if(head->next != NULL)
            printf("%d -> ", head->data);
        else 
            printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}