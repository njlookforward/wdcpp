#include <stdio.h>
#include <limits.h>

#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

int max_min(int *arr, int len, int *pmin) {
    int max = INT_MIN;
    *pmin = INT_MAX;
    for(int i = 0; i < len; ++i) {
        int cur = *(arr + i);
        max = cur > max ? cur : max;
        *pmin = cur < *pmin ? cur : *pmin;
    }

    return max;
}

double get_ave(int *arr, int len) {
    size_t i = len;
    int sum = 0;
    while (i--)
    {
        sum += *arr++;
    }
    
    return (double)sum / len;
}


// question_19
void find_two_largest(int arr[], int n, int *largest, int *second_largest) {
    if(arr[0] > arr[1]) {
        *largest = arr[0];
        *second_largest = arr[1];
    } else {
        *largest = arr[1];
        *second_largest = arr[0];
    }

    for(int i = 2; i < n; ++i) {
        if(arr[i] > *largest) {
            *second_largest = *largest;
            *largest = arr[i];
        } else if(arr[i] > *second_largest) {
            *second_largest = arr[i];
        }
    }
}

int main(void) {
    int darr[] = {1,2,3,5,8,13,21};
    int min;
    int max = max_min(darr, ARR_LEN(darr), &min);

    printf("max = %d, min = %d\n", max, min);

    printf("the average of array is %lf\n", get_ave(darr, ARR_LEN(darr)));

    int largest, second_largest;
    find_two_largest(darr, ARR_LEN(darr), &largest, &second_largest);
    printf("The largest number = %d, the second_largest number = %d\n", largest, second_largest);

    return 0;
}
