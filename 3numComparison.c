#include <stdio.h>

int main(void) {
    int a, b, c;
    int max;

    printf("[*]input intA:\n");
    scanf("%d", &a);

    printf("[*]input intB:\n");
    scanf("%d", &b);

    printf("[*]input intC:\n");
    scanf("%d", &c);

    // 先比较a和b
    if (a >= b) {
        max = a;
    } else {
        max = b;
    }

    // 再与c比较
    if (c > max) {
        max = c;
    }

    printf("[=]Max: %d\n", max);
    return 0;
}