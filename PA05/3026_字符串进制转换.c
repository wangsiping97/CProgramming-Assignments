// 描述
// 编写一个程序，输入一个二进制的字符串（长度不超过32），然后计算出相应的十进制整数，并把它打印出来。

// 输入
// 输入一个二进制字符串。

// 输出
// 输出相应的十进制整数。

// 输入样例
// 1101
// 输出样例
// 13
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<string.h>

int main(){
    char str[32];
    scanf("%s", str);
    int n = 0, t = 1;
    for(int i = strlen(str) - 1; i >= 0; i--){
        str[i] -= '0';
        n += str[i] * t;
        t *= 2;
    }
    printf("%d\n", n);
    return 0;
}