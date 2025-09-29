#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, tries = 0;

    // 使用当前时间作为随机数种子
    srand(time(0));
    number = rand() % 10 + 1; // 生成 1 到 10 的随机数

    printf("Guess a number between 1 and 10:\n");
    do {
        scanf("%d", &guess);
        tries++;
        if (guess < number) {
            printf("Too low! Try again:\n");
        } else if (guess > number) {
            printf("Too high! Try again:\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d tries.\n", number, tries);
        }
    } while (guess != number && tries < 5);

    return 0;
}