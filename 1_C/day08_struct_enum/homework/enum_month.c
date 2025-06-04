#include <stdio.h>

typedef enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

int days_in_month(Month month) {
    switch (month) {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return 31;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            return 28; // 不考虑闰年
        default:
            return -1; // 无效月份
    }
}

int main(void) {
    printf("Feberary has %d days.\n", days_in_month(FEBRUARY));
    printf("April has %d days.\n", days_in_month(APRIL));
    printf("June has %d days.\n", days_in_month(JUNE));
    printf("November has %d days.\n", days_in_month(NOVEMBER));
    printf("December has %d days.\n", days_in_month(DECEMBER));
    printf("Invalid month has %d days.\n", days_in_month(13)); // 测试无效月份
    return 0;
}