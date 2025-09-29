#include<stdio.h>
#include<math.h>

int main(){
    int a;
    int b;
    int c;
    printf("[<]Please enter three lenths:");
    scanf("%d %d %d",&a,&b,&c);
    printf("\n");
    if(a + b > c && a + c > b && b + c > a){
        if(a == b && b == c){
            printf("[>]Equilateral triangle\n");
        }else if(a == b || b == c || a == c){
            printf("[>]Isosceles triangle\n");
        }else if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
            printf("[>]Right triangle\n");
        }else{
            printf("[>]Ordinary triangle\n");
        }
    }else{
        printf("[!]Not a triangle\n");
    }
    return 0;
}
