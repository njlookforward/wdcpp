#include "linkedList.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

void test_reverse_list(void)
{
    // 测试空链表
    Node *empty = NULL;
    Node *result1 = reverse_linked_list(empty);
    assert(result1 == NULL);

    // 测试单节点链表
    Node *single = NULL;
    insert_after_tail(&single, 1);
    Node *result2 = reverse_linked_list(single);
    assert(result2->data == 1);
    assert(result2->next == NULL);

    // 测试多节点链表
    Node *multi = NULL;
    for(int i = 1; i <= 3; i++) {
        insert_after_tail(&multi, i);
    }
    Node *result3 = reverse_linked_list(multi);
    print_linked_list(result3); // 应该输出：3 2 1
}

int main(void) {
    // Node *head = NULL;
    // for(int i = 0; i < 10; i++) {
    //     insert_after_tail(&head, i + 1);
    // }

    // printf("the middle value of list is %d\n", middle_In_LinkedList(head));
    // printf("this list %s circle\n", (isCircle(head) ? "has" : "has not"));

    // create_circled_list(head);
    // printf("this list %s circle\n", (isCircle(head) ? "has" : "has not"));

    // // 单节点无环
    // Node *single = NULL;
    // insert_after_tail(&single, 100);
    // printf("单节点无环：%s\n", isCircle(single) ? "有环" : "无环");

    // // 单节点自环
    // single->next = single;
    // printf("单节点自环：%s\n", isCircle(single) ? "有环" : "无环");

    // // 空链表
    // Node *empty = NULL;
    // printf("空链表：%s\n", isCircle(empty) ? "有环" : "无环");

    // Node *newHead = reverse_linked_list(head);
    // print_linked_list(newHead);

    test_reverse_list();

    return 0;
}