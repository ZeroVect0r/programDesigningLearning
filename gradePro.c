#include<stdio.h>
int main(){
    char grade;
    printf("[<]Input Character:");
    scanf("%d",&grade);

    switch(grade){
        case 'A':
            printf("[A]grade:90-100\n");
            break;
        case 'B':
            printf("[B]grade:80-89\n");
            break;
        case 'C':
            printf("[C]grade:70-79\n");
            break;
        case 'D':
            printf("[D]grade:60-69\n");
            break;
        case 'E':
            printf("[E]grade:0-59\n");
            break;
        default:
            printf("[x]Error input,try again.\n");
            main();
    }
}