#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_LEN(arr) ((sizeof(arr)) / sizeof(arr[0]))

typedef struct {
    char name[25];
    int score;
} Student;

void print_students(Student stus[], int n);
int sort_student_by_score(const void *p1, const void *p2);
int sort_student_by_score_name(const void *p1, const void *p2);

int main(void) {
    Student stus[] = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 85},
        {"David", 85},
        {"Eve", 92},
        {"Frank", 75},
        {"Grace", 85},
        {"Hannah", 95},
        {"Ivy", 78},
        {"Jack", 85}
    };
    
    // 我需要做的任务就是对这个学生结构体数组进行排序，将成绩
    // qsort(stus, ARR_LEN(stus), sizeof(Student), sort_student_by_score);
    // printf("sort students by score:\n");
    // print_students(stus, ARR_LEN(stus));

    qsort(stus, ARR_LEN(stus), sizeof(Student), sort_student_by_score_name);
    printf("sort students by score and name:\n");
    print_students(stus, ARR_LEN(stus));

    return 0;
}

void print_students(Student stus[], int n) {
    Student *cur_stu_p = stus;
    while (cur_stu_p < stus + n)
    {
        printf("%8s --- %d\n", cur_stu_p->name, cur_stu_p->score);
        cur_stu_p++;
    }
}

int sort_student_by_score(const void *p1, const void *p2) {
    // 对于const *指针需要使用const ##*指针来承接
    const Student *p_stu1 = p1,
                  *p_stu2 = p2;
    
    return p_stu2->score - p_stu1->score;
}

int sort_student_by_score_name(const void *p1, const void *p2) {
    const Student *p_stu1 = p1,
                  *p_stu2 = p2;
    
    return p_stu1->score == p_stu2->score
        ? strcmp(p_stu1->name, p_stu2->name)
        : p_stu1->score - p_stu2->score;
}