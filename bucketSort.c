#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    if (n <= 1) return;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n) {
    if (n <= 0) return;

    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int num_buckets = 10;
    int** buckets = (int**)calloc(num_buckets, sizeof(int*));
    int* bucket_counts = (int*)calloc(num_buckets, sizeof(int));

    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * num_buckets) / (max_val + 1);
        bucket_counts[bucket_index]++;
    }

    for (int i = 0; i < num_buckets; i++) {
        if (bucket_counts[i] > 0) {
            buckets[i] = (int*)malloc(bucket_counts[i] * sizeof(int));
        }
    }

    int* bucket_current_size = (int*)calloc(num_buckets, sizeof(int));
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * num_buckets) / (max_val + 1);
        buckets[bucket_index][bucket_current_size[bucket_index]] = arr[i];
        bucket_current_size[bucket_index]++;
    }

    for (int i = 0; i < num_buckets; i++) {
        if (bucket_counts[i] > 0) {
            insertionSort(buckets[i], bucket_counts[i]);
        }
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_counts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        if (buckets[i] != NULL) {
            free(buckets[i]);
        }
    }
    
    free(buckets);
    free(bucket_counts);
    free(bucket_current_size);
}

int main() {
    int arr[] = {89, 56, 65, 12, 66, 34, 45, 9, 78, 22, 5, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
