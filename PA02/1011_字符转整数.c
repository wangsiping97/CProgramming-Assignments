// 描述
// 进制转换。编写一个C程序，该程序提示用户读入三个字符，每个字符的取值范围是‘0’～‘9’、‘A’～‘F’。
// 然后程序会把这三个字符转换为相应的十六进制整数，并分别以十六进制和十进制的形式输出。

// 输入
// 输入三个字符。

// 输出
// 输出两个整数，即十六进制和十进制数。

// 输入样例
// 1AF
// 输出样例
// 0x1AF 431
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 1

#include<stdio.h>
#include<math.h>

int main(){
    char a[3];
    scanf("%s", a);
    int hex;
    int dec = 0, t = 1;
    for(int i = 2; i >= 0; i--){
        switch(a[i]){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': hex = a[i] - '0';
                      break;
            default: hex = a[i] - 'A' + 10;
        }
        dec += t * hex;
        t *= 16;
    }
    printf("0x%s %d\n", a, dec);
    return 0;
}