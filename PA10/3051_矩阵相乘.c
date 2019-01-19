// 描述
// 编写一个程序，实现两个矩阵的乘法。要求：
// (1)把矩阵存储在动态的二维数组中；
// (2)必须采用多函数的方法，至少应包含如下的函数：

// /* 创建一个矩阵，m和n为矩阵的行数和列数，函数的返回值为一个二维指针指向这个矩阵*/ 
// int** CreateMatrix(int m, int n);

// /* 输入一个矩阵的内容，m和n为矩阵的行数和列数，matrix是一个二维指针指向一个矩阵 */ 
// void InputMatrix(int m, int n, int** matrix);

// /* 输出一个矩阵的内容，m和n为矩阵的行数和列数，matrix是一个二维指针指向一个矩阵*/	
// void OutputMatrix(int m, int n, int** matrix);

// /* 将矩阵A和B相乘，结果保存在矩阵C中, ma 和na 是矩阵A的行数和列数，mb和nb是矩阵B的行数和列数*/ 
// void MultiMatrix(int ma, int na, int mb, int nb, int* * A, int* * B, int** C);

// /* 当矩阵使用完毕后，释放其所占用的内存空间，m和n为矩阵的行数和列数，matrix是一个二维指针指向一个矩阵 */ 
// void FreeMatrix(int m, int n, int** matrix);

// 输入
// 程序的输入：首先输入两个矩阵，在输入每个矩阵时，首先输入行数和列数，然后逐行输入这个矩阵；

// 输出
// 程序的输出：逐行输出这两个矩阵的乘积。

// 输入样例
// 3 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 4 3
// 1 0 0
// 0 1 0
// 0 0 1
// 1 0 0
// 输出样例
// 5 2 3
// 13 6 7
// 21 10 11
// 知识点
// 函数、指针、动态存储

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int **CreateMatrix(int m, int n)
{
    int **Matrix;
    Matrix = malloc(sizeof(int *) * m);
    for(int i = 0; i < m; i++){
        Matrix[i] = malloc(sizeof(int) * n);
    }
    return Matrix;
}

void InputMatrix(int m, int n, int **matrix)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void OutputMatrix(int m, int n, int **matrix)
{
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void MultiMatrix(int ma, int na, int mb, int nb, int* * A, int* * B, int** C)
{
    assert(na == mb);
    for(int i = 0; i < ma; i++){
        for(int j = 0; j < nb; j++){
            C[i][j] = 0;
            for(int k = 0; k < na; k++){
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
}

void FreeMatrix(int m, int n, int** matrix)
{
    for(int i = 0; i < m; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int ma, na, mb, nb;
    scanf("%d %d", &ma, &na);
    int **A = CreateMatrix(ma, na);
    InputMatrix(ma, na, A);
    scanf("%d %d", &mb, &nb);
    assert(na == mb);
    int **B = CreateMatrix(mb, nb);
    InputMatrix(mb, nb, B);
    int **C = CreateMatrix(ma, nb);
    MultiMatrix(ma, na, mb, nb, A, B, C);
    OutputMatrix(ma, nb, C);
    FreeMatrix(ma, na, A);
    FreeMatrix(mb, nb, B);
    FreeMatrix(ma, nb, C);
    return 0;
}