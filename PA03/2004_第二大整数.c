// 描述
// 编写一个程序，读入一组整数（不超过20个），当用户输入0时，表示输入结束。
// 然后程序将从这组整数中，把第二大的那个整数找出来，并把它打印出来。

// 说明
// （1）0表示输入结束，它本身并不计入这组整数中。
// （2）在这组整数中，既有正数，也可能有负数。
// （3）这组整数的个数不少于2个。

// 输入
// 输入有若干行，每一行是一个整数，最后一行是结束标记0。

// 输出
// 输出只有一行，即在这组整数中，排名第二大的那个数。

// 输入样例
// 100
// -100
// 200
// 0
// 输出样例
// 100
// 知识点
// 关系运算、循环语句

// 编程模式
// 求最大值

// 难度系数
// 2

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main(){
    int a[20];
    scanf("%d", &a[0]);
    int i = 0;
    while(a[i] != 0 && i < 19){
        scanf("%d", &a[i + 1]);
        i++;
    }
    assert(a[i] == 0);
    // bubble sorting method is applied
    // not OK if sorted with 0 (because the inputs might be minus integers)
    int temp;
    for(int pass = 1; pass <= 2; pass++){
        for(int j = 0; j < (i - pass); j++){
            if(a[j + 1] < a[j]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("%d\n", a[i - 2]);
    return 0;
}
