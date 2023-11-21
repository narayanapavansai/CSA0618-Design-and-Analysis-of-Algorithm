#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else if (L[i] > R[j]) {
            arr[k++] = R[j++];
        } else {
            arr[k++] = L[i++];
            j++;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n1, n2;

    printf("Enter the size of the first set: ");
    scanf("%d", &n1);

    printf("Enter the size of the second set: ");
    scanf("%d", &n2);

    int set1[n1], set2[n2];

    printf("Enter %d elements for the first set:\n", n1);
    for (int i = 0; i < n1; i++)
        scanf("%d", &set1[i]);

    printf("Enter %d elements for the second set:\n", n2);
    for (int i = 0; i < n2; i++)
        scanf("%d", &set2[i]);

    int combinedArray[n1 + n2];

    for (int i = 0; i < n1; i++)
        combinedArray[i] = set1[i];
    for (int i = 0; i < n2; i++)
        combinedArray[n1 + i] = set2[i];

    mergeSort(combinedArray, 0, n1 + n2 - 1);

    printf("Merged and sorted array without duplicates:\n");
    for (int i = 0; i < n1 + n2; i++) {
        while (i < n1 + n2 - 1 && combinedArray[i] == combinedArray[i + 1])
            i++;
        printf("%d ", combinedArray[i]);
    }

    return 0;
}
