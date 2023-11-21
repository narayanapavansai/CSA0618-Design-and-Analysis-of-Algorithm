#include <stdio.h>
#include <stdbool.h>

bool isPerfect(int n) {
    if (n <= 1) return false;

    int sum = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) sum += (i * i == n) ? i : (i + n / i);

    return (sum == n);
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("%d %s a perfect number.\n", n, (isPerfect(n)) ? "is" : "is not");

    return 0;
}
