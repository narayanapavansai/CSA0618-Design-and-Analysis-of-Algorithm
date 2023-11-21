#include <stdio.h>

int isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) sum += (i * i == num) ? i : (i + num / i);
    return (sum == num);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("First %d perfect numbers:\n", n);
    for (int count = 0, num = 2; count < n; num++)
        if (isPerfect(num)) printf("%d\n", num), count++;

    return 0;
}

