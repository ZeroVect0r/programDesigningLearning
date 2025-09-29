#include <stdio.h>
#include <ctype.h>
#include <string.h>

void processString(char type, int len, char str[]) {
    if (type == 'r') {
        
        int index = 0;
        for (int i = 0; i < len; i++) {
            if (!isdigit(str[i])) { 
                str[index++] = str[i];
            }
        }
        str[index] = '\0'; 
    } else if (type == 'c') {
        
        for (int i = 0; i < len; i++) {
            str[i] = tolower(str[i]);
        }
    } else if (type == 'C') {
        
        for (int i = 0; i < len; i++) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    int num = 0;
    char type;
    int len = 0;
    char str[101]; 

    
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        
        scanf(" %c %d %s", &type, &len, str);

        
        processString(type, len, str);

        
        printf("%s\n", str);
    }

    return 0;
}