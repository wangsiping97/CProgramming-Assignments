// 描述
// 一个魔方矩阵指的是一个N×N的矩阵，然后把1～N*N这些整数摆放在矩阵中，使得每一行之和等于每一列之和，并且等于对角线之和（有两条对角线）。
// 如果N是一个奇数，那么可以按照如下的规则来摆放：

// （1）把1摆放在第一行的正中间；

// （2）如果一个整数K已经被摆放在矩阵中，那么对于K+1来说，它的位置是位于K的右上方，即往右一列，再往上一行；

// （3）在情形（2）中，如果K已经是在最顶行，那么就把K+1摆放在最底行；

// （4）在情形（2）中，如果K已经是在最右列，那么就把K+1摆放在最左列；

// （5）在情形（2）中，如果该位置已经摆放了其他整数，或者K已经是摆放在矩阵的右上角，那么就把K+1直接放在K的正下方。

// 输入
// 输入一个奇数N。

// 输出
// 输出相应的魔方矩阵。

// 输入样例
// 3
// 输出样例
// 8 1 6
// 3 5 7
// 4 9 2
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()
{
    int N;
    scanf("%d", &N);
    assert(N % 2 == 1);
    int matrix[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix[i][j] = 0;
        }
    }
    matrix[0][N / 2] = 1;
    int address[N * N + 1][2]; // address[i][0] -- row; address[i][1] -- column
    address[1][0] = 0;
    address[1][1] = N / 2;
    for(int K = 2; K <= N * N; K++){
        if(address[K - 1][0] == 0 && address[K - 1][1] != N - 1){
            address[K][0] = N - 1;
            address[K][1] = address[K - 1][1] + 1;
        }
        else if(address[K - 1][1] == N - 1 && address[K - 1][0] != 0){
            address[K][1] = 0;
            address[K][0] = address[K - 1][0] - 1;
        }
        else if((address[K - 1][0] == 0 && address[K - 1][1] == N - 1) || matrix[address[K - 1][0] - 1][address[K - 1][1] + 1] != 0){
            address[K][0] = address[K - 1][0] + 1;
            address[K][1] = address[K - 1][1];
        }
        else{
            address[K][0] = address[K - 1][0] - 1;
            address[K][1] = address[K - 1][1] + 1;
        }
        matrix[address[K][0]][address[K][1]] = K;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}