// 描述
// 一个数如果恰好等于它的因子之和，这个数就称为“完数”。
// 例如，6的因子为1、2、3，而6＝1＋2＋3，因此6就是“完数”。
// 又如，28的因子为1、2、4、7、14，而28＝1＋2＋4＋7＋14，因此28也是“完数”。
// 编写一个程序，判断用户输入的一个数是否为“完数”。

// 输入
// 输入一个正整数。

// 输出
// 如果该整数是一个完数，则输出字符Y，否则输出字符N。

// 输入样例
// 28
// 输出样例
// Y
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 2

#include<stdio.h>
#include<math.h>
#include<assert.h>

int main(){
    int num;
    scanf("%d", &num);
    assert(num > 0);
    int sum = 0;
    for(int i = 1; i < num; i++){
        if(num % i == 0)
        sum += i;
    }
    if(sum == num) printf("Y\n");
    else printf("N\n");
    return 0;
}