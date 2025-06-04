#include <stdio.h>

int main(int argc, char *argv[]) {
    // question 1:
    printf("argc = %d\n", argc);
    for(int i = 0; i < argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    // question 2:
    int i;
    double d;
    sscanf(argv[1], "%d", &i);
    sscanf(argv[2], "%lf", &d);

    char output_str[50] = {0};
    sprintf(output_str, "%d + %.1lf = %.2lf%s\n", i, d, d + i, argv[3]);
    printf("%s", output_str);

    return 0;
}