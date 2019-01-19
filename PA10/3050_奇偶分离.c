// 描述
// 本题由三部分内容组成。

// (a) 编写一个函数CountEvensAndOdds，其功能是统计一个整型数组中奇数和偶数的个数。
// 该函数有四个参数：整型数组、数组长度、两个指针（用于返回奇、偶数的个数）。

// (b) 利用(a)中的CountEvensAndOdds函数，编写一个Partition函数，
// 其功能是对给定长度的一个整型数组，找出其中的所有奇数和偶数，并把它们分别保存在两个新的整型数组中（用malloc函数动态创建），
// 然后返回这两个新数组及其长度。该函数的参数有六个，即整型数组、数组长度、奇数数组及其长度、偶数数组及其长度。

// (c) 编写main函数，输入一个整形数组，然后调用(b)中的Partition函数，并将其返回结果显示出来。

// 输入
// 程序的输入：2行，第一行是数组的长度，第二行是整形数组中的元素，以空格分离；

// 输出
// 程序的输出：2行，第一行是奇数数组的元素，空格分隔；第二行偶数数组的元素，空格分隔；其中元素的先后关系与原数组一致。

// 输入样例
// 8
// 12 67 89 32 101 35 36 28
// 输出样例
// 67 89 101 35
// 12 32 36 28
// 知识点
// 函数、指针、动态存储

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<stdlib.h>

void CountEvensAndOdds(int *a, int N, int *peven, int *podd)
{
    *peven = *podd = 0;
    for(int i = 0; i < N; i++){
        if(a[i] % 2 == 0){
            *peven = *peven + 1;
        }
        else *podd = *podd + 1;
    }
}

void Partition(int *a, int N, int *odd, int *nodd, int *even, int *neven)
{
    CountEvensAndOdds(a, N, neven, nodd);
    int j = 0, k = 0;
    for(int i = 0; i < N; i++){
        if(a[i] % 2 == 0) even[j++] = a[i];
        else odd[k++] = a[i];
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int a[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    int *odd, *even;
    int nodd, neven;
    odd = malloc(sizeof(int) * N);
    even = malloc(sizeof(int) * N);

    Partition(a, N, odd, &nodd, even, &neven);
    
    for(int i = 0; i < nodd; i++){
        printf("%d ", odd[i]);
    }
    printf("\n");
    for(int i = 0; i < neven; i++){
        printf("%d ", even[i]);
    }
    printf("\n");
    return 0;
}