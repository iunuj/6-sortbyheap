#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void resortHeap(int inputData[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && inputData[left] > inputData[largest])
        largest = left;

    if (right < n && inputData[right] > inputData[largest])
        largest = right;

    if (largest != i) {
        swap(&inputData[i], &inputData[largest]);
        resortHeap(inputData, n, largest); 
}

void BuildMaxHeap(int inputData[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        resortHeap(inputData, n, i);
    }
}

void BuildMaxHeapAndSort(int inputData[], int n) {
    BuildMaxHeap(inputData, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&inputData[0], &inputData[i]);

        resortHeap(inputData, i, 0);

        for (int j = 0; j < i; j++) {
            printf("%d ", inputData[j]);
        }
        printf("\n");
    }
}

int main() {
    int inputData[] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 35, 85, 29, 78, 41, 56, 86 };
    int size = sizeof(inputData) / sizeof(inputData[0]);

    printf("<Sort>\n");
    BuildMaxHeapAndSort(inputData, size);

    printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", inputData[i]);
    }
    printf("\n");

    return 0;
}