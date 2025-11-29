#include <stdio.h>
int sumCubes(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i * i * i);
    }
    return sum;
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Sum of cubes of first %d natural numbers is: %d\n", n, sumCubes(n));
    return 0;
}
