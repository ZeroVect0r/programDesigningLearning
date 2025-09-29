#include<stdio.h>

int main(){
    int input;
    int sum = 0;
    int i;
    scanf("%d",&input);
    for (i = 0 ; i <= input ; i++){
        if ( i%7 == 0 || i/7 == 10 || (i-7)%10 == 0 ){
            continue;
        }else{
            sum = sum + i*i;
        }
    }
    printf("%d",sum);
    return 0;
}