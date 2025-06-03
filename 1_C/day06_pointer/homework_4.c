#include <stdio.h>

void split_time(long total_sec, int *hour, int *minute, int *second) {
    // 先计算秒
    *second = total_sec % 60;
    // 再计算分钟
    *minute = (total_sec / 60) % 60;
    // 最后计算小时
    *hour = (total_sec / 60 / 60) % 24;
}

int main(void) {
    long total_sec;
    printf("Please input total_second that you want to be converted time: ");
    scanf("%ld", &total_sec);

    int hour, minute, second;
    split_time(total_sec, &hour, &minute, &second);
    // %02d表示如果整数小于两位数，那么就应该补0
    printf("after converting, the time is %02d:%02d:%02d\n", hour, minute, second);
}