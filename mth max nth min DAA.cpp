#include <stdio.h>

void findMthMax_NthMin(int arr[], int size, int M, int N) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int mthMax = arr[size - M];
    int nthMin = arr[N - 1];

    int sum = mthMax + nthMin;
    int diff = mthMax - nthMin;

    printf("Mth maximum: %d\n", mthMax);
    printf("Nth minimum: %d\n", nthMin);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
}

int main() {
    int size, M, N;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of M: ");
    scanf("%d", &M);
    printf("Enter the value of N: ");
    scanf("%d", &N);
    findMthMax_NthMin(arr, size, M, N);

    return 0;
}
