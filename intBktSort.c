#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VAL 1000000

int main() {
    size_t n;
    scanf("%zu", &n);

    int* counts = (int*)calloc(MAX_VAL + 1, sizeof(int));

    if (counts == NULL) {
	    exit(1); 
    }

    for (size_t i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        counts[num]++;
    }

    bool is_first_output = true;

    for (int i = MAX_VAL; i >= 0; i--) {
        for (int j = 0; j < counts[i]; j++) {
            if (is_first_output) {
                printf("%d", i);
                is_first_output = false;
            } else {
                printf(" %d", i);
            }
        }
    }
    printf("\n");

    free(counts);

    return 0;
}
