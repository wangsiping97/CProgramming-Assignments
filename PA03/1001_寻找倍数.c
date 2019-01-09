// 描述
// 编写一个程序，输入三个正整数min，max和factor，其中min≤max，
// 然后对于从min到max之间的每一个整数（包括min和max），如果它能够被factor整除的话，就把它打印出来。

// 输入
// 输入只有一行，即三个正整数min、max和factor。

// 输出
// 输出有一行，符合条件的整数按照递增顺序排列，以空格分隔。

// 输入样例
// 1 10 3
// 输出样例
// 3 6 9
// 知识点
// 算术运算、循环语句

// 编程模式
// 无

// 难度系数
// 2

#include<stdio.h>
#include<math.h>

int main(){
    int min, max, factor;
    scanf("%d %d %d", &min, &max, &factor);
    for(int i = min; i <= max; i++){
        if(i % factor == 0)
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}