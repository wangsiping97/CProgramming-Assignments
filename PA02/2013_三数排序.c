// 描述
// 编写一个程序，输入三个整数a、b和c，然后对这三个整数进行排序，使得a ≤ b，b ≤ c。

// 输入
// 输入只有一行，包括三个整数。

// 输出
// 输出也只有一行，包括三个整数，即排序后的结果。

// 输入样例
// 5 3 7
// 输出样例
// 3 5 7
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 2

#include<stdio.h>

int main(){
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    // insertion sorting method is applied
    int temp;
    for(int i = 1; i < 3; i++){
        for(int j = i; j > 0; j--){
            if(a[j] < a[j - 1]){
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("%d %d %d\n", a[0], a[1], a[2]);
    return 0;
}