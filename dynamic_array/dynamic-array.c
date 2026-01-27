#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

// initialize the array
void initArray(DynamicArray *A, size_t intitialCapacity) {
    A->data = malloc(intitialCapacity * sizeof(int));
    A->size = 0;
    A->capacity = intitialCapacity;
}

// add element
void insertArray(DynamicArray *A, int element) {
    if (A->size == A->capacity) {
        A->capacity *= 2;
        A->data = realloc(A->data, A->capacity * sizeof(int));
    }
    A->data[A->size++] = element;
}

// free memory
void freeArray(DynamicArray *A) {
    free(A->data);
    A->data = NULL;
    A->size = A->capacity = 0;
}

int main() {
    DynamicArray arr;
    initArray(&arr, 2);

    for (int i = 0; i < 5; i++) {
        insertArray(&arr, i * 10);
    }

    printf("Element at index 3: %d\n", arr.data[3]);
    printf("Current size: %zu, Capacity: %zu\n", arr.size, arr.capacity);

    freeArray(&arr);

    return 0;
}