#include "link_list_simple.h"

int main(void) {
    Node *head = NULL;
    insert_tail(&head, 5);
    insert_tail(&head, 6);
    insert_tail(&head, 7);
    insert_tail(&head, 8);
    printf("after insert at tail:\n");
    print_list(head);

    modify_first_node(&head, 12);
    insert_head(&head, 1);
    insert_head(&head, 2);
    insert_head(&head, 3);
    insert_head(&head, 4);
    printf("after insert at head:\n");
    print_list(head);

    // print_list(head);

    return 0;
}