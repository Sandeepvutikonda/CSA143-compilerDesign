 #include <stdio.h>

int main() {
    int a, b, c, d, e, result;
    printf("Enter values for a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);
    result = a + b;

    printf("Result 1: %d\n", result);
    printf("Result 2: %d\n", result);
    d = result * c;
    printf("Result 3: %d\n", d);
    e = result * c;
    printf("Result 4: %d\n", e);

    return 0;
}
