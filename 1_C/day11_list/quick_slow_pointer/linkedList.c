#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

void insert_after_tail(Node **head, DataType newVal) {
    // 为新结点分配内存
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("insert_after_tail() failed.\n");
        exit(-1);
    }
    new_node->data = newVal;
    new_node->next = NULL;

    // 如果链表为空
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    // 如果链表非空，找到尾节点
    Node *end = *head;
    while (end->next != NULL)
    {
        end = end->next;
    }
    end->next = new_node;
}

DataType middle_In_LinkedList(Node *head)
{
    if(head == NULL) {
        printf("middle_In_LinkedList() failed.\n");
        exit(-1);
    }

    Node *slow = head,
         *quick = head;
    
    // 使用快慢指针的条件没有那么简单，需要考虑的更多一些
    while (quick != NULL && quick->next != NULL)
    {
        quick = quick->next->next;
        slow = slow->next;
    }

    return slow->data;
}

bool isCircle(Node *head)
{
    if(head == NULL) {
        printf("error.\n");
        exit(-1);
    }

    Node *quick = head;
    Node *slow = head;

    while (quick != NULL && quick->next != NULL)
    {
        quick = quick->next->next;
        slow = slow->next;

        if(quick == slow) return true;
    }
    
    return false;
}

void print_linked_list(Node *head)
{
    if (head == NULL)
    {
        printf("error.\n");
        exit(-1);
    }
    
    Node *cur_node = head;
    while (cur_node)
    {
        printf("%d ", cur_node->data);
        cur_node = cur_node->next;
    }

    printf("\n");
}

// 使用现成的一个单链表，只不过使末尾节点指向第二个节点，为了测试方便
// 我这里默认单链表的节点个数大于等于4
void create_circled_list(Node *head)
{
    if(head == NULL || head->next == NULL || head->next->next == NULL) {
        printf("the length of list isn't enough.\n");
        exit(-1);
    }
    Node *third_node = head->next->next;

    Node *end = head;
    while (end->next != NULL)
    {
        end = end->next;
    }
    
    end->next = third_node;
}

Node *reverse_linked_list(Node *list)
{
    if(list == NULL) {
        printf("list is null.\n");
        return NULL;
    }

    Node *prev = NULL;
    Node *current_code = list;
    Node *next = NULL;

    while (current_code != NULL)
    {
        next = current_code->next;
        current_code->next = prev;
        prev = current_code;
        current_code= next;
    }
    return prev;
}

// 加头结点版本
Node *merge_two_list_dummyhead(Node *list1, Node *list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    // 因为是使用尾插法才能保证按照顺序进行排列
    Node *dummyHead = calloc(1, sizeof(Node));
    if(dummyHead == NULL) {
        printf("merge_two_list_dummyhead() error: calloc failed.\n");
        return NULL;
    }
    Node *tail = dummyHead;

    while (list1 != NULL && list2 != NULL)
    {
        if(list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (list1 != NULL) ? list1 : list2;
    
    Node *head = dummyHead->next;
    free(dummyHead);
    return head;
}

// 不加头结点版本
Node *merge_two_list(Node *list1, Node *list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    Node *head = NULL,
         *tail = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        Node *target = NULL;
        if(list1->data <= list2->data) {
            target = list1;
            list1 = list1->next;
        } else {
            target = list2;
            list2 = list2->next;
        }

        if(head == NULL) {
            head = target;
            tail = target;
        } else {
            tail->next = target;
            tail = target;
        }
    }

    tail->next = (list1 != NULL) ? list1 : list2;
    
    return head;
}