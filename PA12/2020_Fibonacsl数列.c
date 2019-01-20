// 描述
// 计算Fibonacsl数列中的第n个元素的值。所谓Fibonacsl数列，即满足下列公式的整数序列：

// Fn = a * Fn-2 + b * Fn-1

// 其中，a、b是任意给定的整数常量，序列的初始值F1和F2也是任意给定的。
// 例如，如果F1=3、F2=1、a=2、b=-3，则相应的Fibonacsl数列为：

// 3, 1, 3, -7, 27, -95, 339, …

// 请编写一个程序，对于用于的参数，计算相应数列中第n个元素的值。

// 输入
// 输入只有一行，包括5个整数：F1、F2、a、b和n，其中n<100。

// 输出
// 输出相应数列的第n个元素。

// 输入样例
// 3 1 2 -3 5
// 输出样例
// 27
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 2

#include<stdio.h>
#include<assert.h>

long int Fib(int F1, int F2, int a, int b, int n)
{
    long int fib;
    for(int i = 3; i <= n; i++){
        fib = a * F1 + b * F2;
        F1 = F2;
        F2 = fib;
    }
    return fib;
}

int main()
{
    int F1, F2, a, b, n;
    scanf("%d %d %d %d %d", &F1, &F2, &a, &b, &n);
    assert(n < 100);
    printf("%ld\n", Fib(F1, F2, a, b, n));
    return 0;
}