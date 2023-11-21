#include <stdio.h>

#define MAX 100

int count = 0;

void displaySubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void subsetSum(int arr[], int subset[], int n, int sum, int currIndex, int target) {
    if (sum == target) {
        displaySubset(subset, currIndex);
        count++;
        return;
    }

    for (int i = currIndex; i < n; i++) {
        subset[currIndex] = arr[i];
        subsetSum(arr, subset, n, sum + arr[i], currIndex + 1, target);
        subset[currIndex] = 0; 	
    }
}

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[MAX];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);
 
    int subset[MAX];
    printf("\nSubsets with sum equal to %d are:\n", target);
    subsetSum(arr, subset, n, 0, 0, target);

    printf("\nNumber of subsets: %d\n", count);

    return 0;
}
