// 描述
// 楼梯有N级台阶，上楼时一步可以走一级台阶，也可以走二级或三级台阶。请编写一个递归程序，计算共有多少种不同走法？

// 输入
// 输入N（5<N<30），台阶数。

// 输出
// 输出一个整数，不同的走法。

// 输入样例
// 8
// 输出样例
// 81
// 限制
// 无

// 提示
// 请使用合适的数据类型存储不同走法。

#include<stdio.h>
#include<assert.h>

int Count(int N)
{
    int count;
    if(N == 1) return 1;
    else if(N == 2) return 2; // 1 + 1; 2
    else if(N == 3) return 4; // 1 + 1 + 1; 1 + 2; 2 + 1; 3
    else{
        return Count(N - 1) + Count(N - 2) + Count(N - 3);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    assert(N > 5 && N < 30);
    printf("%d\n", Count(N));
    return 0;
}