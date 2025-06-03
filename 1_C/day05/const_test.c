#include <stdio.h>

int main(void) {
    const int a = 1;
    scanf("%d", &a);

    printf("main======%d\n", a);

    int *pa = &a;
    *pa = 1222;

    printf("pointer main======%d\n", a);

    return 0;
}