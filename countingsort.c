#include <stdio.h>

void countingSort(int array[], int size) {
    int max = array[0];
    int min = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
        if (array[i] < min) {
            min = array[i];
        }
    }

    int range = max - min + 1;
    int count[range];

    // Initialize count array with zeros
    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            array[index++] = i + min;
            count[i]--;
        }
    }
}

int main() {
    int array[] = {4, 2, 10, 8, 3, 1};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    countingSort(array, size);

    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}



