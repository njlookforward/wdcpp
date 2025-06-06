#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

void display(int *parr, int n) {
    // bool isFirst = true;

    printf("[");

    for(int i = 0; i < n; i++) {
        printf("%d, ", parr[i]);
    }

    printf("\b\b]\n");
}

int main(void) {
    int *parr = calloc(10, sizeof(int));
    if(parr == NULL) {
        printf("calloc falied in main!\n");
        return -1;
    }
    
    display(parr, 10);

    int *new_parr = realloc(parr, 5 * sizeof(int));
    if(new_parr == NULL) {
        printf("realloc failed in main()!");
        free(parr);
        return -1;
    }
    display(new_parr, 5);

    int *new_parr_1 = realloc(new_parr, 10 * sizeof(int));
    if(new_parr_1 == NULL) {
        printf("realloc failed in main()!");
        free(new_parr);
        return -1;
    }
    for(int i = 5; i < 10; i++) {
        new_parr_1[i] = 888;
    }
    display(new_parr_1, 10);

    free(new_parr_1);

    return 0;
}