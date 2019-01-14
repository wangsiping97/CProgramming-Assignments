// 描述
// 有一个函数RegularPlural，其功能是实现一个英文单词的复数形式。
// 复数的规则为：
// (1)如果单词末尾为s, x, z, ch或sh，则在后面加es；
// (2)如果单词末尾为y，且前一个字母为辅音（如b, c, d），则把y修改为ies；
// (3)如果是其他情形，一律在后面加s。

// 请编写一个程序，实现该函数，并在主函数中输入数据来测试该函数。

// 输入
// 输入一个单词。

// 输出
// 输出该单词的复数形式。

// 输入样例
// box
// 输出样例
// boxes
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* my_RegularPlural(char *str)
{
    char *str_plura;
    str_plura = malloc(sizeof(str) + 2);
    if(str[strlen(str) - 1] == 's' || str[strlen(str) - 1] == 'x' || str[strlen(str) - 1] == 'z'){
        strcpy(str_plura, str);
        strcat(str_plura, "es");
    }
    else if(str[strlen(str) - 1] == 'h' && (str[strlen(str) - 2] == 'c' || str[strlen(str) - 2] == 's')){
        strcpy(str_plura, str);
        strcat(str_plura, "es");
    }
    else if(str[strlen(str) - 1] == 'y'){
        memcpy(str_plura, str, (strlen(str) - 1));
        strcat(str_plura, "ies");
    }
    else{
        strcpy(str_plura, str);
        strcat(str_plura, "s");
    }
    return str_plura;
}

int main()
{
    char word[20];
    gets(word);
    char *word_plura= my_RegularPlural(word);
    puts(word_plura);
    return 0;
}