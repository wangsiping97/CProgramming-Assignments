// 描述
// 编写一个程序，该程序输入一个字符串（长度不超过20），
// 然后把这个字符串内的每一个字符进行大小写变换，即将大写字母变成小写，小写字母变成大写，
// 然后把这个新的字符串输出。例如，如果输入“AeDb”，那么将输出“aEdB”。
// 假定输入的这个字符串当中只包含英文字母，不包含其他类型的字符。

// 输入
// 输入只有一行，即一个字符串。

// 输出
// 输出只有一行，即变换后的字符串。

// 输入样例
// AeDb
// 输出样例
// aEdB
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 2

#include<stdio.h>
#include<string.h>

int main(){
    char str[20];
    scanf("%s", str);
    int l = strlen(str);
    for(int i = 0; i < l; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 'a' - 'A';
        else if(str[i] >= 'a' && str[i] <= 'z')
        str[i] += 'A' - 'a';
    }
    printf("%s\n", str);
    return 0;
}