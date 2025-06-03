#include <stdio.h>

/**
 * @brief 自己实现标准库函数中的字符串函数，要按照标准库的函数行为进行实现
 */

size_t my_strlen(const char *str) {
    // 统计字符串大小
    size_t size = 0;
    // 我竟然忘记让字符串指针进行移动，实在是不应该啊，可恶
    while (*str++)
    {
        ++size;
    }
    return size;
}

char *my_strcpy(char *dest, const char *src) {
    // strcpy是不管三七二十一，将源字符串的所有字符都拷贝到目标字符串中，完全替代
    char *origin_dest = dest;
    while (*dest++ = *src++);
    
    return origin_dest;
}

char *my_strncpy(char *dest, const char *src, size_t count) {
    // strncpy的逻辑是:
    // 1. count < strlen(src) + 1, 只复制前count个字符
    // 2. count == strlen(src) + 1, 正好复制count个字符
    // 3. count > strlen(src) + 1, 复制完src的字符后，后面都要补'\0'
    char *origin_dest = dest;
    // while (count-- && (*dest++ = *src++));
    // 出现问题，应该在while的条件表达式中尽量避免使用赋值表达式
    // while(count--)这样的写法是错误的，因为count是size_t类型，先进行count--操作的话
    // 会从0变成整数中的最大值，因此需要先判断count
    /**
     * @bug: 因为count是size_t类型，所以不能使用while(count-- && ..)+ while(count--)的形式，因为
     * size_t 会从0减到最大值，因此出现segmentaion fault, 仍然是逻辑问题，要么修改逻辑，要么将count的数据类型从
     * size_t 修改为int
     */
    while (count && *src)
    {
        *dest++ = *src++;
        count--;
    }

    while (count--)
    {
        *dest++ = '\0';
    }

    return origin_dest;
}

char *my_strcat(char *dest, const char *src) {
    // 我理解的strcat，也是不管三七二十一，就是将src指向的字符串直接添加到dest中
    char *origin_dest = dest;
    while(*dest) ++dest;
    while (*dest++ = *src++);
    
    return origin_dest;
}

/**
 * @brief 我自己理解的strncat的逻辑是
 * 1. count < strlen(src) + 1, 就是添加count个字符，然后后面添加一个'\0'
 * 2. count >= strlen(src) + 1, 就是添加strlen(src) + 1的字符
 */
char *my_strncat(char *dest, const char *src, size_t count) {
    char *origin_dest = dest;
    while(*dest) ++dest;
    while (count-- && *src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return origin_dest;
}

/**
 * @brief strcmp是比较两个字符串是否相等，因此从头比到尾就好了
 */
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2)
    {
        if(*str1 < *str2) return -1;
        else if(*str1 > *str2) return 1;
        else {
            ++str1;
            ++str2;
        } 
    }
    if(!*str1 && !*str2) return 0;
    else if(!*str1) return -1;
    else return 1;
}

int main() {
    char buf1[100] = "Hello";
    char buf2[100] = "World";
    char buf3[100] = "Hello";
    char buf4[100] = "Hello123";
    char buf5[100] = "Test";
    char buf6[100] = "abc";
    char buf7[100] = "ABC";
    char buf8[100] = "123";
    char buf9[100] = "Hello";

    // my_strlen
    printf("my_strlen(\"Hello\"): %zu\n", my_strlen("Hello"));

    // my_strcpy
    my_strcpy(buf5, "CopyTest");
    printf("my_strcpy: %s\n", buf5);

    // my_strncpy
    my_strncpy(buf6, "abcdef", 3);
    buf6[3] = '\0'; // 保证字符串结束
    printf("my_strncpy: %s\n", buf6);

    // my_strcat
    my_strcat(buf1, "World");
    printf("my_strcat: %s\n", buf1);

    // my_strncat
    my_strncat(buf3, "World", 3);
    printf("my_strncat: %s\n", buf3);

    // my_strcmp
    printf("my_strcmp(\"Hello\", \"Hello\"): %d\n", my_strcmp("Hello", "Hello"));
    printf("my_strcmp(\"Hello\", \"World\"): %d\n", my_strcmp("Hello", "World"));
    printf("my_strcmp(\"abc\", \"abcd\"): %d\n", my_strcmp("abc", "abcd"));
    printf("my_strcmp(\"abcd\", \"abc\"): %d\n", my_strcmp("abcd", "abc"));

    return 0;
}