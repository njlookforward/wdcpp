#include "Vector.h"

// 通过在函数前面加上static，指出该函数只能在文件内部被访问，类似于C++中的
// private成员函数
static void vector_resize(Vector *pvec) {
    int old_capacity = pvec->capacity;
    int new_capacity = (old_capacity < THRESHOLD) 
            ? (old_capacity << 1)                   // 扩容两倍
            : old_capacity + (old_capacity >> 1);   // 扩容1.5倍
    
    ElementType *newTable = realloc(pvec->table, new_capacity * sizeof(ElementType));
    if(newTable == NULL) {
        printf("vector_resize() error!\n");
        exit(-1);
        // exit已经结束整个进程了，因此不需要再去释放堆空间
    }
    pvec->table = newTable;

    pvec->capacity = new_capacity;
}

Vector *vector_create(void)
{
    // 尽量使用calloc申请内存，这样可以直接初始化了
    Vector *pvec = calloc(1, sizeof(Vector));
    if(pvec == NULL) {
        printf("malloc failed in vector_create()!\n");
        return NULL;
    }

    pvec->table = calloc(DEFAULT_CAPACITY, sizeof(ElementType));
    if(pvec->table == NULL) {
        printf("malloc failed in vector_create()!\n");
        free(pvec);
        return NULL;
    }
    pvec->capacity = DEFAULT_CAPACITY;

    return pvec;
}

void vector_destroy(Vector *pvec)
{
    if(pvec == NULL) return;
    free(pvec->table);
    free(pvec);
}

// 只要涉及到增加，就需要判断需不需要扩容
// 在末尾增
void vector_push_back(Vector *pvec, ElementType val)
{
    if(pvec->capacity == pvec->size) {
        ElementType *newTable = realloc(pvec->table, 2 * pvec->capacity * sizeof(ElementType));
        if(newTable == NULL) {
            printf("realloc failed in vector_push_back!\n");
            vector_destroy(pvec);
            exit(-1);
        }

        pvec->table = newTable;
        pvec->capacity *= 2;
    }

    pvec->table[pvec->size++] = val;
}

// 在前面进行插入，需要将元素向后移
void vector_push_front(Vector *pvec, ElementType val)
{
    if(pvec->capacity == pvec->size) {
        ElementType *newTable = realloc(pvec->table, 2 * pvec->capacity * sizeof(ElementType));
        if(newTable == NULL) {
            printf("realloc failed in vector_push_front!\n");
            vector_destroy(pvec);
            exit(-1);
        }

        pvec->table = newTable;
        pvec->capacity *= 2;
    }

    for(int i = pvec->size; i > 0; i--) {
        pvec->table[i] = pvec->table[i-1];
    }

    pvec->table[0] = val;
    pvec->size++;
}

// 在数组的任意索引位置进行插入，也需要将元素向后移
void vector_insert(Vector *pvec, int idx, ElementType val)
{
    // 还需要判断索引位置是否正确
    if(idx < 0 || idx > pvec->size) {
        printf("Sorry, idx is invalid.\n");
        return;
    }

    if(pvec->capacity == pvec->size) {
        ElementType *newTable = realloc(pvec->table, 2 * pvec->capacity * sizeof(ElementType));
        if(newTable == NULL) {
            printf("realloc failed in vector_insert.\n");
            vector_destroy(pvec);
            exit(-1);
        }

        pvec->table = newTable;
        pvec->capacity *= 2;
    }

    for(int i = pvec->size; i > idx; i--)
        pvec->table[i] = pvec->table[i-1];
    
    pvec->table[idx] = val;

    pvec->size++;
}

void vector_print(Vector *pvec)
{
    printf("[");
    for(int i = 0; i < pvec->size; i++)
        printf("%d, ", pvec->table[i]);
    
    printf("\b\b]\n");
}

void vector_pop_back(Vector *pvec)
{
    if(pvec->size == 0) {
        printf("vector_pop_back(): vector is empty, cannot pop again.\n");
        return;
    }

    pvec->size--;
}

void vector_pop_front(Vector *pvec)
{
    if(pvec->size == 0) {
        printf("vector_pop_front(): vector is empty, cannot pop again.\n");
        return;
    }
    for(int i = 0; i < pvec->size - 1; i++)
        pvec->table[i] = pvec->table[i+1];
    
    pvec->size--;
}

void vector_pop_index(Vector *pvec, int idx)
{
    if(pvec == NULL) {
        printf("vector_pop_index() error: pvec is NULL.\n");
        return;
    }

    if(idx < 0 || idx >= pvec->size) {
        printf("vector_pop_index() error: idx is invalid.\n");
        return;
    }

    for(int i = idx; i < pvec->size - 1; i++) {
        pvec->table[i] = pvec->table[i+1];
    }

    pvec->size--;
}
