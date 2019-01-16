// 描述
// 编写一个程序，计算一个后缀表达式的值。
// 该表达式中的运算符只有+（加法）、-（减法）、*（乘法）、/（除法）和^（指数），
// 每一个操作数都是一个小于10的非负整数，运算符和操作数之间用一个空格隔开。
// 例如，对于输入的后缀表达式“8 5 4 - * 2 /”，
// 它表示先计算“5 4 -”，即5-4，结果为1。
// 然后再计算“8 1 *”，结果为8。
// 然后再计算“8 2 /”，结果为4，
// 因此表达式的最后结果为4.

// 输入
// 输入一个字符串，即一个后缀表达式。

// 输出
// 输出一个整数，即该表达式的值。

// 输入样例
// 8 5 4 - * 2 /
// 输出样例
// 4
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<string.h>

int operate(int m, char operator, int n)
{
    if(operator == '+'){
        return (m + n);
    }
    else if(operator == '-'){
        return (m - n);
    }
    else if(operator == '*'){
        return (m * n);
    }
    else if(operator == '/'){
        return (m / n);
    }
    else{
        int a = 1;
        for(int i = 0; i < n; i++){
            a *= m;
        }
        return a;
    }
}

int main(){
    char str[100];
    gets(str);
    int i = 0;
    char c[100][10];
    char *token = strtok(str, " ");
    char operator[100];
    while(token != NULL){
        strcpy(c[i++], token);
        token = strtok(NULL, " ");
    }

    int left[i];
    int right[i];
    int k_l = 0, k_r = 0;

    for(int j = i - 1; j >= 0; j--){
        if(strcmp(c[j], "+") == 0 || strcmp(c[j], "-") == 0 || strcmp(c[j], "*") == 0 || strcmp(c[j], "/") == 0 || strcmp(c[j], "^") == 0){
            strcat(operator, c[j]);
            k_l++;
            k_r++;
        }
        else if(c[j + 1][0] >= '0' && c[j + 1][0] <= '9'){
            left[--k_l] = c[j][0] - '0';
        }
        else{
            right[k_r - 1] = c[j][0] - '0';
        }
    }

    for(int j = k_r - 1; j >= 1; j--){
        if(left[j - 1]) right[j - 1] = operate(left[j], operator[j], right[j]);
        else left[j - 1] = operate(left[j], operator[j], right[j]);
    }
    int output = operate(left[0], operator[0], right[0]);
    printf("%d\n", output);
    return 0;
}