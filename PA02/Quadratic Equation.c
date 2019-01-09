// 描述
// 求解方程ax^2+bx+c=0的根。要求a, b, c由用户输入，并且可以为任意非零实数（在双精度浮点数表示的范围之内）。

// 输入
// 输入只有一行，依次三个系数a, b, c，之间用空格格开。

// 输出
// 输出只有一行，包括两个根，以空格分开，保留小数点后两位。

// 若有两个不同的根，先输出小的，再输出大的

// 输入样例
// 2.5 7.5 1.0
// 输出样例
// -2.86 -0.14
// 限制
// 时间：2s

// 内存：256MB

// 系数a和b均不为0

// 保证输入的方程存在实根

#include<stdio.h>
#include<math.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double delta;
    double x_1, x_2;
    delta = b * b - 4.0 * a * c;
    assert(delta > 0);
    x_1 = (-b + sqrt(delta)) / (2 * a);
    x_2 = (-b - sqrt(delta)) / (2 * a);
    printf("%.2f %.2f", x_1, x_2);
    return 0;
}