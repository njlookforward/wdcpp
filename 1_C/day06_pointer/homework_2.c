#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

// part_test_1
void build_arr(int *arr, int len) {
    srand((unsigned int)time(NULL));

    for(int i = 0; i < len; i++) {
        arr[i] = rand() % 20;
    }
}

// part_test_2
void displayArr(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

// part_1
void swap(int *arr, int i, int j) {
    // 假定传入的数组两个下标都是有效的
    int tmp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = tmp;
}

// part_2: 我理解错了，应该是将数组逆序
void print_reverse_order(int *arr, int len) {
    int *start = arr;
    int *end = arr + len - 1;

    for(int i = 0; i < len / 2; ++i) {
        // 交换首尾元素
        int tmp = *start;
        *start = *end;
        *end = tmp;

        // 移动指针
        start++;
        end--;
        char ch = "0";
    }
    
}

// part_3
int sumOfArray(int *arr, int len) {
    // 因为通过值传递数组已经将首元素地址赋值给arr，而arr不像数组民那样是指针常量，因此可以变化
    // 需要通过i进行标识，防止数组越界
    int sum = 0;
    for(int i = 0; i < len; ++i) {
        sum += *arr++;
    }
    return sum;
}

// part_4
void locate(int *arr, int len, int target, size_t *index) {
    for(int i = 0; i < len; ++i) {
        if(arr[i] == target) {
            *index = i;
            return;
        }
    }
}

// part_5
int isPalindrome(int *arr, int len) {
    size_t left = 0, right = len - 1;
    while (left < right && arr[left] == arr[right])
    {
        ++left;
        --right;
    }
    return left >= right ? 1 : 0;
}

// part_6
void copyArray(int *src, int len, int *dest) {
    int i = 0;
    while (i++ < len)
    {
        *dest++ = *src++;
    }
}

// part_7
/**
 * @brief 该函数将数组中所有奇数移到偶数的前面
 * @details 使用双指针法将所有奇数移到所有偶数的前面
 */
int isOdd(int num) {
    return num & 1;
}

void resetArray(int *arr, int len) {
    size_t left_odd = 0, right_even = len - 1;
    while (left_odd < right_even)
    {
        // 先找到左侧的偶数
        while (left_odd < right_even && isOdd(arr[left_odd]))
        {
            ++left_odd;
        }
        // 再找到右侧的奇数
        while (left_odd < right_even && !isOdd(arr[right_even]))
        {
            --right_even;
        }
        
        if(left_odd < right_even) {
            int tmp = arr[left_odd];
            arr[left_odd] = arr[right_even];
            arr[right_even] = tmp;
            ++left_odd;
            --right_even;
        }
    }
}


int main(void) {
    int arr[8] = {};
    build_arr(arr, ARR_LEN(arr));
    // int arr[8] = {1,1,2,3,5,8,13,21};

    // test_part_1
    // printf("before swap: ");
    // displayArr(arr, ARR_LEN(arr));
    // swap(arr, 0, ARR_LEN(arr)-1);
    // printf("\nafter swap: ");
    // displayArr(arr, ARR_LEN(arr));
    
    // test_part_2
    // printf("normal order: ");
    // displayArr(arr, ARR_LEN(arr));
    // printf("\nreversal order: ");
    // print_reverse_order(arr, ARR_LEN(arr));

    // test_part_3
    // printf("SUM of Array is %d\n", sumOfArray(arr, ARR_LEN(arr)));

    // test_part_4
    // size_t index = ARR_LEN(arr);
    // printf("Please input a number to locate in the array: ");
    // int target;
    // scanf("%d", &target);
    // locate(arr, index, target, &index);
    // if(index == ARR_LEN(arr)) 
    //     printf("Sorry, %d isn't in the array.", target);
    // else
    //     printf("Get it! %d is in the %d of array.", target, index);

    //test_part_5
    // int arr[] = {1,2,3,2,1};
    // if(isPalindrome(arr, ARR_LEN(arr)))
    //     printf("this array is palindrome.\n");
    // else    
    //     printf("Sorry, this array isn't palindrome.\n");

    // test_part_6
    // int src[8] = {};
    // build_arr(src, ARR_LEN(src));
    // int dest[8] = {1,1,2,3,5,8,13,21};
    // copyArray(src, ARR_LEN(src), dest);
    // printf("src's array is ");
    // displayArr(src, ARR_LEN(src));
    // printf("\ndest's array is ");
    // displayArr(dest, ARR_LEN(dest));

    // test_part_7
    printf("before resort: ");
    displayArr(arr, ARR_LEN(arr));
    resetArray(arr, ARR_LEN(arr));
    printf("\nafter resort: ");
    displayArr(arr, ARR_LEN(arr));

    return 0;
}