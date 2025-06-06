#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Please input a integer to malloc array: ");
    int size;
    scanf("%d", &size);

    int *parr = malloc(size);
    if(parr == NULL) {
        printf("malloc failed in main()!\n");
        return -1;
    }

    for(int i = 0; i < size; i++) 
        parr[i] = i + 1;
    
    int *old_parr = parr;
    for(int i = 0; i < size; i++)
        printf("%d ", *parr++);
    
    free(old_parr);

    return 0;
}