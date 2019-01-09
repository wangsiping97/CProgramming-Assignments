// 描述
// 税务局希望你帮他们编写一个征税程序，该程序的功能是：
// 首先输入某公司的年销售额sale和税率rate，
// 然后程序将计算出相应的税额tax，并把它显示在屏幕上。
// 计算公式是：tax = sale * rate。

// 输入
// 输入两个实数，即销售额和税率

// 输出
// 输出只有一个实数，即税额，保留小数点后两位

#include<stdio.h>
#include<stdlib.h>

int main(){
    double sale, rate;
    double tax;
    printf("Please enter sale and tax rate: \nSale: ");
    scanf("%lf", &sale);
    printf("Tax rate: ");
    scanf("%lf", &rate);
    tax = sale * rate;
    printf("The tax is: ");
    printf("%.2f\n", tax);
    return 0;
}