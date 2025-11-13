
#include <stdio.h>
#include <stdlib.h> // 为了使用 exit()

/* 你的 fo() 函数，现在更健壮*/
FILE* fo() {
    FILE* fp; // 声明一个“文件遥控器” fp

    // 1. 使用相对路径 "text.txt"，它将在程序运行的目录下创建文件
    // "w" 表示写入模式 (write)，如果文件已存在则清空，不存在则创建
    fp = fopen("text.txt", "w");

    // 2. 使用 if 语句进行错误检查，这比 assert 更友好
    if (fp == NULL) {
        // 如果遥控器是 NULL，说明文件打开失败
        perror("Error opening file"); // perror 会打印出具体的系统错误原因
        exit(1); // 退出程序，1 表示程序异常终止
    }

    return fp; // 返回可以正常使用的遥控器
}

int main() {
    // 从 fo() 函数获取一个有效的文件遥控器
    FILE* fp = fo();

    // 3. 使用 fprintf 向文件写入文本
    // 参数1: 往哪个文件写 (通过遥控器指定)
    // 参数2...: 和 printf 一样，是要写入的格式化字符串
    fprintf(fp, "This is a test line.\n");
    fprintf(fp, "Value is %d, string is %s.\n", 123, "hello");

    // 操作完成后，关闭文件以保存更改
    fclose(fp);

    printf("File 'text.txt' written successfully.\n");

    return 0;
}
