// 描述
// 编写一个程序，输入一个英文句子，然后使用如下规则对该句子中的每一个单词进行处理：

// （1）如果该单词是第一次出现，则保持其原样；

// （2）如果该单词是第二次出现，则将它复制一遍；

// （3）如果该单词是第三次或第三次以上出现，则将它删除。

// 经过上述处理之后，将会得到一个新的句子，然后将该句子打印出来。

// 说明：
// （1）必须将新生成的句子保存在一个字符数组中，然后再整体打印出来，不能一个单词一个单词地打印；
// （2）由于句子当中包含有空格，所以应该用gets函数来输入这个句子，不要用scanf； /* I think the teacher is wrong, since scanf() being repeated many times is equal to gets() */
// （3）输入的句子当中只包含英文字符和空格，单词之间用一个空格隔开；
// （4）不用考虑单词的大小写，假设输入的都是小写字符；
// （5）句子长度不超过500个字符，每个单词的长度不超过50个字符。

// 输入
// 输入只有一行，即一个英文句子。

// 输出
// 输出只有一行，即经过处理以后的句子。

// 输入样例
// jingle bells jingle bells jingle all the way
// 输出样例
// jingle bells jinglejingle bellsbells all the way
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[500];
    gets(str);
    // split the sentence into several words and store them in different arrays
    char word[500][50];
    char *token = strtok(str, " ");
    int i = 0;
    while(token != NULL){
        strcpy(word[i++], token);
        token = strtok(NULL, " ");
    }
    // count the times that each word appears in the sentence
    int count[i];
    memset(count, 0, sizeof(count)); 
    for(int j = 0; j < i; j++){
        count[j]++;
        for(int k = j + 1; k < i; k++){
            if(strncmp(word[j], word[k], 50) == 0){
                count[k]++;
            }
        }
    }
    // output the new sentence
    char new_str[1000];
    for(int j = 0; j < i; j++){
        if(count[j] == 1){
            strcat(new_str, word[j]);
            strcat(new_str, " ");
        }
        else if(count[j] == 2){
            strcat(new_str, word[j]);
            strcat(new_str, word[j]);
            strcat(new_str, " ");
        }
    }
    puts(new_str);
    return 0;
}

// New functions learned:
// gets(str); 字符串输入函数，包含空格
// puts(str); 字符串输出函数，包含空格
// memset(*array, val, length); 从参数1开始用参数2填充参数3个字节，一般只能用来清零和将数组初始化为0
// strtok(str, " "); 将字符串按" "分割
// strcat(Dest, Src); 把一个字符串连接到另一个字符串的后面
// strcpy(Dest, Src); 把一个字符串复制（替换）成另一个字符串
// strcmp(string1, string2); 比较两个字符串的大小（ASCII码值），若string1 < string2，返回一个负整数；相等则返回0；否则返回正整数
// strncmp(string1, string2, N); 比较两个字符串前N个字符