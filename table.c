#include<stdio.h>
int main() {
    for (int i = 1; i <= 9 ; i++) {
        for (int j = 1; j < i; j++){
            printf("\t");
        }
        for (int k = i; k <= 9; k++) {
            printf("=%d\t", i * k);
        }
        printf("\n");
    }
    return 0;
}