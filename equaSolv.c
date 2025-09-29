#include<stdio.h>
#include<math.h>

int main() {

    //variables
    double a, b, c;
    double delta, x1, x2;

    //input
    printf("[A]Input a:");
    scanf("%lf", &a);
    printf("[B]Input b:");
    scanf("%lf", &b);
    printf("[C]Input c:");
    scanf("%lf", &c);

    //delta decision
    delta = b * b - 4 * a * c;

    //output
    if (delta < 0) {
        printf("[x]No real solution.\n");
        main();
    }
    else if (delta == 0) {
        x1 = -b / (2 * a);
        printf("[1]One real solution: x1 = x2 = %.2lf\n", x1);
        return 0;
    }
    else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("[2]Two real solutions: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
        return 0;
    }
}