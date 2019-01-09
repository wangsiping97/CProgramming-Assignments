// 描述
// 编写一个程序，输入一个圆的半径，输出相应的圆面积。

// 输入
// 输入一个实数，即圆的半径。

// 输出
// 输出一个实数，即圆的面积，保留小数点后2位。

// 输入样例
// 1
// 输出样例
// 3.14

#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

int main(){
    double r;
    scanf("%lf", &r);
    double size;
    size = r * r * M_PI;
    printf("%.2f\n", size);
    return 0;
}