#include <stdio.h>

// 打印一行星号的函数
void star() {
    printf("\t\t\t\t");
    for (int i = 0; i < 21; i++) {
        printf("* ");
    }
    printf("\n");
}

void small() {
    printf("\t\t\t\t");
    printf("*\t\t\t\t\t*\n");// 打印两端有星号的空行函数
}

int main2() {
    star(); // 显示一行星号
    small(); // 显示两端有星号的空行
    printf("\t\t\t\t");
    printf("*\t     姓名：陈舒雅\t\t*\n");
    small();
    printf("\t\t\t\t");
    printf("*\t     qq：3087609055\t\t*\n");
    small();
    printf("\t\t\t\t");
    printf("*\t     电话:13349700621    \t*\n");
    small();
    printf("\t\t\t\t");
    printf("*   人生名言:生活总是起起落落落落落落\t*\n");
    small();
    printf("\t\t\t\t");
    printf("*\t\t\"\\(^_^)/\"\t\t*\n");//反斜杠 \，双引号 "正常输出需用转义符 \\, \”
    small(); // 显示两端有星号的空行，连来两次
    small();
    star();
    return 0;
}