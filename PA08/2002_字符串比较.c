// 描述
// 在C语言中，有一个strcmp函数，它的函数原型为：
// int strcmp(char *s1, char *s2)，其功能是比较两个字符串。
// 如果s1 < s2，则返回一个负数；
// 如果s1＝s2，则返回一个0；
// 如果s1 > s2，则返回一个正数。
// 请编写一个你自己的字符串比较函数my_strcmp，来实现strcmp函数的功能。
// 要求：在主函数当中提示用户输入两个字符串，然后调用my_strcmp函数来进行比较，最后把结果显示出来
// （注：用户输入的字符串不会超过20个字符，但其中可能包含有空格）。

// 输入
// 输入有两行，每一行是一个字符串

// 输出
// 输出只有一行，即这两个字符串的比较结果：小于、大于或等于。

// 输入样例
// boy
// bad
// 输出样例
// 大于
// 知识点
// 字符串、字符类型

// 编程模式
// 无

// 难度系数
// 2

#include<stdio.h>
#include<string.h>

int my_strcmp(char s1[20], char s2[20])
{
    int a;
    int i;
    for(i = 0; i < 20; i++){
        if(s1[i] > s2[i]) {
            return a = 1;
        }
        else if(s1[i] < s2[i]){
            return a = -1;
        }
    }
    return a = 0;
}

int main()
{
    char s1[20], s2[20];
    gets(s1);
    gets(s2);
    int a = my_strcmp(s1, s2);
    if(a > 0) printf("大于\n");
    if(a < 0) printf("小于\n");
    if(a == 0) printf("等于\n");
    return 0;
}