#include <stdio.h>

void find_min_max(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    int min1, max1, min2, max2;
    
   
    find_min_max(arr, low, mid, &min1, &max1);
    find_min_max(arr, mid + 1, high, &min2, &max2);

   
    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int size;

    
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int min_val, max_val;
    find_min_max(arr, 0, size - 1, &min_val, &max_val);

    printf("Minimum: %d\n", min_val);
    printf("Maximum: %d\n", max_val);

    return 0;
}
