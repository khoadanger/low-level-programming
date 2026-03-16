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
        A->capacity += 1;
        A->data = realloc(A->data, A->capacity * sizeof(int));
    }
    A->data[A->size++] = element;
}

// deleteElement
void deleteElement(DynamicArray *A, size_t index) {
    if (index >= A->size) {
        printf("index %zu out of bounds.", index);
        return;
    }

    for (int i = index; i < A->size - 1; i++) {
        A->data[i] = A->data[i + 1];
    }
    A->size--;
    A->capacity--;
}

// free memory
void freeArray(DynamicArray *A) {
    free(A->data);
    A->data = NULL;
    A->size = A->capacity = 0;
}


void showinfo(DynamicArray *A) {
    printf("Element at index 3: %d\n", A->data[3]);
    printf("Current size %zu, Capacity: %zu\n", A->size, A->capacity);
    return;
}
int main() {
    DynamicArray arr;
    initArray(&arr, 2);

    for (int i = 0; i < 50; i++) {
        insertArray(&arr, i * 10);
    }

    showinfo(&arr);

    deleteElement(&arr, 3);

    showinfo(&arr);

    freeArray(&arr);

    return 0;
}