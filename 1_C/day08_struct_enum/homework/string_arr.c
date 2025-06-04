#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

// question 1:
void display_matrix_string(char (*fruits)[10], int n) {
    for(int i = 0; i < n; ++i) {
        int j = 0;
        while (fruits[i][j])
        {
            printf("%c", fruits[i][j]);
            j++;
        }
        printf(" = %d\n", j);
    }
}

void display_pointer_string(char **fruits, int n) {
    for(int i = 0; i < n; ++i) {
        printf("%s = %d\n", fruits[i], strlen(fruits[i]));
    }
}

int main(void) {
    // 练习两种字符串数组的不同表示形式
    char fruits1[][10] = {
        "apple",
        "banana",
        "cherry"
    };

    char *fruits2[] = {
        "apple",
        "banana",
        "cherry"
    };

    // printf("用二维数组表示字符串数组：\n");
    // display_matrix_string(fruits1, ARR_LEN(fruits1));
    // printf("用指针数组表示字符串数组: \n");
    // display_pointer_string(fruits2, ARR_LEN(fruits2));

// question 2:
// 使用二维数组来表示字符串数组，使用="orange"不能完成字符串赋值操作，因为
// "orange"本质上是字符数组，作为赋值运算符右侧的操作数会退化成字符指针，因此永远是将指针赋值过去，永远无法修改栈中字符串内容
// 但是对于使用指针数组表示字符串数组，就可以使用 = "orange"来完成赋值操作
    strcpy(fruits1[0], "orange");
    fruits2[0] = "orange";

// question 3:
// 对于使用二维数组构成字符串数组可以使用=运算符，可以直接在栈上修改字符内容；但是对于使用指针数组表示字符串数组
// 来说，只能重新指向一个新的字符串字面值
    fruits1[1][0] = 'B';
    fruits2[1] = "Banana";
    printf("用二维数组表示字符串数组：\n");
    display_matrix_string(fruits1, ARR_LEN(fruits1));
    printf("用指针数组表示字符串数组: \n");
    display_pointer_string(fruits2, ARR_LEN(fruits2));

// question 4:
    char *pf1 = (char *)malloc(10);
    strcpy(pf1, "apple");
    char *pf2 = (char *)malloc(10);
    strcpy(pf2, "banana");
    char *pf3 = (char *)malloc(10);
    strcpy(pf3, "cherry");
    char *fruits3[] = {pf1, pf2, pf3};

    printf("question4=======before\n");
    display_pointer_string(fruits3, ARR_LEN(fruits3));

    char *pf4 = (char*)malloc(10);
    strcpy(pf4, "orange");
    fruits3[0] = pf4;
    fruits3[1][0] = 'B';

    printf("question4=======after\n");
    display_pointer_string(fruits3, ARR_LEN(fruits3));

    free(pf1);
    free(pf2);
    free(pf3);
    free(pf4);
    
    return 0;
}