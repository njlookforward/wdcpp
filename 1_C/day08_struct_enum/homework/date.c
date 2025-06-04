#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

/**
 * @brief intervalBetweenDates()计算两个不同日期之间的差值
 * 1. 计算两个不同日期之间的差值，就是小日期增加多长时间才能到达大的日期
 * 例如 2023.2.26 - 2025.5.26: 
 * 可以分为 2023.2.26 - 2023.12.30； 2024； 2025.1.1-2025.5.26
 * 如果对于2023.2.26 - 2024.4.6
 * 可以分为2023.2.26 - 2023.12.30；2024.1.1 - 2024.4.6
 * 因此可以分为计算开始年的天数 + 中间完整年的天数 + 末尾年的天数
 * 继续拆分：计算开始年、末尾年的天数：开始月的天数+中间完整月的天数+末尾月的天数
 */

const Date *biggerDate(const Date *pdate1, const Date *pdate2) {
    const Date *bigger;
    if(pdate1->year > pdate2->year) {
        bigger = pdate1;
    } else if(pdate1->year == pdate2->year) {
        if(pdate1->month > pdate2->month) {
            bigger = pdate1;
        } else if(pdate1->month == pdate2->month) {
            if(pdate1->day > pdate2->day) {
                bigger = pdate1;
            } else if(pdate1->day == pdate2->day) {
                bigger = NULL;  // 如果返回NULL两个日期相等，就不需要再进行计算了
            } else 
                bigger = pdate2;
        } else 
            bigger = pdate2;
    } else 
        bigger = pdate2;

    // 这里是出现的bug，竟然忘记写返回值了
    return bigger;
}

int cal_intervals_same_year(const Date *pbeg, const Date *pend) {
    // 计算同一个月
    if(pbeg->month == pend->month)
        return pend->day - pbeg->day;
    
    // 计算不同月
    // 计算开始月
    int interval_first_month = 30 - pbeg->day;
    // 计算末尾月
    int interval_last_month = pend->day;
    // 计算中间完整月
    int interval_months = pend->month - pbeg->month - 1;
    int interval_whole_months = interval_months > 0 ? interval_months * 30
                                                    : 0;
    return interval_first_month + interval_last_month + interval_whole_months;
}

int intervalBetweenDates(const Date *pdate1, const Date *pdate2) {
    // 找到谁是大日期，谁是小日期
    const Date *p_bigDate, *p_smallDate;
    p_bigDate = biggerDate(pdate1, pdate2);
    if(p_bigDate == NULL) 
        return 0;
    p_bigDate == pdate1 ? (p_smallDate = pdate2)
                        : (p_smallDate = pdate1);
    
    // 计算同一年
    if(p_bigDate->year == p_smallDate->year)
        return cal_intervals_same_year(p_smallDate, p_bigDate);

    // 计算不同年
    // 计算开始年的天数
    Date small_year_tail = {p_smallDate->year, 12, 30};
    int interval_first_year = cal_intervals_same_year(p_smallDate, &small_year_tail);
    // 计算末尾年的天数
    Date big_year_front = {p_bigDate->year, 1, 1};
    int interval_last_year = cal_intervals_same_year(&big_year_front, p_bigDate) + 1;
    // 计算完整年的天数
    int interval_whole_years = 0;
    int interval_years = p_bigDate->year - p_smallDate->year - 1;
    interval_whole_years = interval_years > 0 ? interval_years * 360
                                          : 0;

    // 将每一年的天数相加
    return interval_first_year + interval_last_year + interval_whole_years;
}

int main(void) {
    Date d1 = {2023, 2, 26};
    Date d2 = {2025, 5, 26};
    printf("2023.2.26 - 2025.5.26: %d\n", intervalBetweenDates(&d1, &d2)); // 答案：810

    Date d3 = {2023, 2, 26};
    Date d4 = {2024, 4, 6};
    printf("2023.2.26 - 2024.4.6: %d\n", intervalBetweenDates(&d3, &d4)); // 答案：400

    Date d5 = {2023, 2, 26};
    Date d6 = {2023, 4, 6};
    printf("2023.2.26 - 2023.4.6: %d\n", intervalBetweenDates(&d5, &d6)); // 答案：40

    Date d7 = {2023, 2, 26};
    Date d8 = {2023, 2, 26};
    printf("2023.2.26 - 2023.2.26: %d\n", intervalBetweenDates(&d7, &d8)); // 答案：0

    return 0;
}

