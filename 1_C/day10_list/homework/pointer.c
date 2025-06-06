#include <stdio.h>

void swap(int *pa, int *pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void swap2(int **ppa, int **ppb) {
    int tmp = **ppa;
    **ppa = **ppb;
    **ppb = tmp;
}

int main(void) {
    int a = 10;
    int b = 20;

    printf("before swap:\n");
    printf("a = %d, b = %d\n", a, b);
    int *pa = &a, *pb = &b;
    swap(pa, pb);
    printf("after swap:\n");
    printf("a = %d, b = %d\n", a, b);

    printf("before swap2:\n");
    printf("a = %d, b = %d\n", a, b);
    int **ppa = &pa, **ppb = &pb;
    swap2(ppa, ppb);
    printf("after swap2:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}