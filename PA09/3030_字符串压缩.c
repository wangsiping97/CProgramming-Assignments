// 描述
// 编写一个程序，输入一个字符串，然后采用如下的规则对该字符串当中的每一个字符进行压缩：

// (1) 如果该字符是空格，则保留该字符；

// (2) 如果该字符是第一次出现或第三次出现或第六次出现，则保留该字符；

// (3) 否则，删除该字符。

// 例如，若用户输入“occurrence”，经过压缩后，字符c的第二次出现被删除，第一和第三次出现仍保留；
// 字符r和e的第二次出现均被删除，因此最后的结果为：“ocurenc”。

// 输入
// 输入一个字符串。

// 输出
// 输出压缩以后的结果。

// 输入样例
// occurrence
// 输出样例
// ocurenc
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    gets(str);
    int l = strlen(str);
    int count[l];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < l; i++){
        count[i]++;
        for(int j = i + 1; j < l; j++){
            if(str[i] == str[j]){
                count[j]++;
            }
        }
    }
    for(int i = 0; i < l; i++){
        if(count[i] != 1 && count[i] != 3 && count[i] != 6 && str[i] != ' '){
            for(int j = i; j < l; j++){
                str[j] = str[j + 1];
                count[j] = count[j + 1];
            }
        }
    }
    puts(str);
    return 0;
}