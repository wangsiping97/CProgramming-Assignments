// 描述
// 编写一个程序，输入一个百分制成绩，输出相应的成绩等级。
// 规定：90或90分以上为‘A’，80～89分为‘B’，70～79分为‘C’，60～69分为‘D’，60分以下为‘F’。

// 输入
// 输入只有一个整数，即百分制成绩。

// 输出
// 输出只有一个字符，即相应的等级分。

// 输入样例
// 95
// 输出样例
// A
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 1

#include<stdio.h>

int main(){
    int score;
    scanf("%d", &score);
    if(score >= 90) printf("A\n");
    else if(score >= 80) printf("B\n");
    else if(score >= 70) printf("C\n");
    else if(score >= 60) printf("D\n");
    else printf("F");
    return 0;
}