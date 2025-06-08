#include <stddef.h>

typedef int DataType;

typedef struct node_s {
    DataType data;
    struct node_s *next;
} Node;

void reverse_list(Node *head) {
    Node *newHead = NULL;
    while (head)
    {
        Node *old_next = head->next;
        head->next - newHead;
        newHead = head;
        head = old_next;
    }
    
    return newHead;
}