#include<stdio.h>
int main(){
    int m;
    int n;
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,89, 97};
    int ans[25];
    int count = 0;
    int max = 0;
    int var = 0;

    scanf("%d %d",&m,&n);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        if (arr[i] >= m && arr[i] <= n){
            ans[count++] = arr[i];
             
        }
    }

    for (int j = 0; j < count - 1; j++) {
        m = ans[j];
        n = ans[j + 1];
        if (n - m > max) {
            max = n - m;
            var = j;
        }
    }

    printf("%d %d %d", ans[var], ans[var + 1], max);
    return 0;
}