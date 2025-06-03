
// 需要使用<stddef.h>才能使用size_t
#include <stddef.h>

// 实现我自己的strncat
char *my_strncat(char *dest, const char *src, size_t count) {
    char *origin_dest = dest;

    while(*dest) {
        ++dest;
    }

    while (count-- && *src) {
        *dest++ = *src++;
    }
    
    *dest = '\0';
    return origin_dest;
}