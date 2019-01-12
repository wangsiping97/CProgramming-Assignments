// 描述
// Anagrams指的是具有如下特性的两个单词：
// 在这两个单词当中，每一个英文字母（不区分大小写）所出现的次数都是相同的。
// 例如，“Unclear”和“Nuclear”、“Rimon”和“MinOR”都是Anagrams。
// 编写一个程序，输入两个单词，然后判断一下，这两个单词是否是Anagrams。
// 每一个单词的长度不会超过80个字符，而且是大小写无关的。

// 输入
// 输入有两行，每行是一个英文单词。

// 输出
// 输出一个字符，“Y”表示是，“N”表示不是。

// 输入样例
// Unclear
// Nuclear
// 输出样例
// Y
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<string.h>

int main(){
    char str_1[80], str_2[80];
    scanf("%s", str_1);
    scanf("%s", str_2);
    int alphabet[26];
    for(int i = 0; i < 26; i++)
        alphabet[i] = 0;
    for(int i = 0; i < strlen(str_1); i++){
        if(str_1[i] >= 'A' && str_1[i] <= 'Z')
            str_1[i] -= 'A';
        else if(str_1[i] >= 'a' && str_1[i] <= 'z')
            str_1[i] -= 'a';
        alphabet[str_1[i]]++;
    }
    for(int j = 0; j < strlen(str_2); j++){
        if(str_2[j] >= 'A' && str_2[j] <= 'Z')
            str_2[j] -= 'A';
        else if(str_2[j] >= 'a' && str_2[j] <= 'z')
            str_2[j] -= 'a';
        alphabet[str_2[j]]--;
    }
    int count = 0;
    for(int k = 0; k < 26; k++){
        if(alphabet[k] == 0)
            count++;
    }
    if(count == 26) printf("Y\n");
    else printf("N\n");
    return 0;
}