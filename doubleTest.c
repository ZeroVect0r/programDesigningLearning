#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    double m;
    double n;
    scanf("%lf %lf",&m,&n);
    printf("%.1f\n",m + n);
    printf("%.2f",m * n);
    return 0;
}