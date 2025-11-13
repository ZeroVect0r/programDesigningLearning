#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int inf, int mid, int sup);

void mergeSort(int arr[], int inf, int sup) {
    if (inf < sup) {
        int mid = inf + (sup - inf) / 2;
        mergeSort(arr, inf, mid);
        mergeSort(arr, mid + 1, sup);
        merge(arr, inf, mid, sup);
    }
}

void merge(int arr[], int inf, int mid, int sup) {
    int n1 = mid - inf + 1;
    int n2 = sup - mid;

    int left[n1];
    int right[n2];

    int numLeft;
    int numRight;
    int numOutput;

    for (numLeft = 0; numLeft < n1; numLeft++) {
        left[numLeft] = arr[inf + numLeft];
    }
    for (numRight = 0; numRight < n2; numRight++) {
        right[numRight] = arr[mid + 1 + numRight];
    }

    numLeft = 0;
    numRight = 0;
    numOutput = inf;

    while (numLeft < n1 && numRight < n2) {
        if (left[numLeft] >= right[numRight]) {
            arr[numOutput] = left[numLeft];
            numLeft++;
        } else {
            arr[numOutput] = right[numRight];
            numRight++;
        }
        numOutput++;
    }

    while (numLeft < n1) {
        arr[numOutput] = left[numLeft];
        numLeft++;
        numOutput++;
    }
    while (numRight < n2) {
        arr[numOutput] = right[numRight];
        numRight++;
        numOutput++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
