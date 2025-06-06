#include "Vector.h"

int main() {
    Vector *vec = vector_create();
    for (int i = 0; i < 15; i++) {
        vector_push_back(vec, i + 1);
    }
    printf("After push_back:\n");
    vector_print(vec);

    vector_push_front(vec, 100);
    printf("After push_front 100:\n");
    vector_print(vec);

    vector_insert(vec, 5, 200);
    printf("After insert 200 at index 5:\n");
    vector_print(vec);

    vector_pop_back(vec);
    printf("After pop_back:\n");
    vector_print(vec);

    vector_pop_front(vec);
    printf("After pop_front:\n");
    vector_print(vec);

    vector_pop_index(vec, 3);
    printf("After pop_index 3:\n");
    vector_print(vec);

    vector_destroy(vec);
    return 0;
}

