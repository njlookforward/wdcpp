#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>

// 不管自己写成什么样，都要相信自己写的东西，我要先干完，再完善
void count_alpha_number_occurs(const char *str) {
    // 我需要忽略大小写字母，统计数字跟字母出现的次数
    // 都按照小写字母来吧，需要进行遍历
    size_t alnums[128] = {0};
    char ch;
    while (ch = *str)
    {
        if(isalnum(ch)) {
            if(isupper(ch)) {
                ch = ch - 'A' + 'a';
            }
            alnums[ch]++;
        }
        ++str;
    }
    
    // 打印每个字符的出现次数
    for(int i = '0'; i <= '9'; ++i) {
        if(alnums[i])
            printf("%c occurs %d times.\n", i, alnums[i]);
    }
    for(int i = 'a'; i <= 'z'; ++i) {
        if(alnums[i])
            printf("%c occurs %d times.\n", i, alnums[i]);
    }
}

void count_alnum_occurs_v2(const char *str) {
    // 每次遇到指针，都需要判断指针是否有效，要养成习惯
    if(!str) exit(-1);
    // 实际上只有36个字符，因此可以将计数数组缩短到36
    size_t alnums[36] = {0};
    char ch;
    while (ch = *str)
    {
        // 需要使用我之前的思路分别解决字母和数字，因为需要进行压缩数组
        if(isalpha(ch)) {
            if(isupper(ch))
                ch = ch - 'A' + 'a';
            alnums[ch - 'a']++;
        } else if(isdigit(ch)) {
            alnums[ch - '0' + 26]++;
        }

        str++;
    }

    // 打印我统计的数字和字母
    for(int i = 0; i < 26; ++i) {
        if(alnums[i])
            printf("%c occurs %d times.\n", i + 'a', alnums[i]);
    }
    
    for(int i = 26; i < 36; ++i) {
        if(alnums[i])
            printf("%c occurs %d times.\n", i - 26 + '0', alnums[i]);
    }
}

int main(void) {
    const char *test1 = "Hello123World321";
    printf("Test 1:\n");
    count_alpha_number_occurs(test1);
    count_alnum_occurs_v2(test1);

    const char *test2 = "AaBbCc123abc";
    printf("\nTest 2:\n");
    count_alpha_number_occurs(test2);
    count_alnum_occurs_v2(test2);

    const char *test3 = "WangDao2025!";
    printf("\nTest 3:\n");
    count_alpha_number_occurs(test3);
    count_alnum_occurs_v2(test3);

    return 0;
}