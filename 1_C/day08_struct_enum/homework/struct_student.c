#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

typedef struct student_s {
    int number;
    char name[25];
    char gender;
    int Chinese;
    int Math;
    int English;
} Student;

void display_student(const Student *pstu);
double average_single_grade(const Student *pstu);
void print_subject_averages(const Student stu_orders[], int n);

int main(void) {
    Student s1 = {1, "Jack", 'm', 100, 100, 100};

    // Student stu_orders[5] = {
    //     {1, "Jack", 'm', 100, 90, 80},
    //     {2, "Lucy", 'f', 95, 85, 75},
    //     {3, "Tom", 'm', 80, 70, 60},
    //     {4, "Lily", 'f', 88, 77, 66},
    //     {5, "Mike", 'm', 92, 82, 72}
    // };
    Student stu_orders[5] = {0};
    printf("Please input five students's information:\n");
    for(int i = 0; i < 5; ++i) {
        printf("Please input No.%d student's information:\n", i+1);
        printf("number: ");
        scanf("%d", &stu_orders[i].number);
        printf("name: ");
        scanf("%s", stu_orders[i].name);
        printf("gender: ");
        // @bug: 通过加上空格，可以跳过前导空白字符，否则的话可能会读取上一个输入后的换行字符
        scanf(" %c", &stu_orders[i].gender);
        printf("Chinese: ");
        scanf("%d", &stu_orders[i].Chinese);
        printf("Math: ");
        scanf("%d", &stu_orders[i].Math);
        printf("English: ");
        scanf("%d", &stu_orders[i].English);
    }

    for(int i = 0; i < 5; ++i) {
        display_student(&stu_orders[i]);
    }

    print_subject_averages(stu_orders, ARR_LEN(stu_orders));

    return 0;
}

void display_student(const Student *pstu)
{
    printf("number: %d\nname: %s\ngender: %c\nChinese: %d\nMath: %d\nEnglish: %d\nAverage: %lf\n",
            pstu->number, pstu->name, pstu->gender, pstu->Chinese, 
            pstu->Math, pstu->English, average_single_grade(pstu));
}

double average_single_grade(const Student *pstu)
{
    return ((double)pstu->Chinese + pstu->Math + pstu->English) / 3;
}

// 打印三个学科的平均分
void print_subject_averages(const Student stu_orders[], int n) {
    double chinese_sum = 0, math_sum = 0, english_sum = 0;
    for(int i = 0; i < n; ++i) {
        chinese_sum += stu_orders[i].Chinese;
        math_sum += stu_orders[i].Math;
        english_sum += stu_orders[i].English;
    }

    printf("Chinese average: %.2lf\n", chinese_sum / n);
    printf("Math average: %.2lf\n", math_sum / n);
    printf("English average: %.2lf\n", english_sum / n);
}