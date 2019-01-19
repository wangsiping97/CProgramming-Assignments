// 描述
// 作为一名网络警察，你的任务是监视电子邮件，看其中是否有一些敏感的关键词。

// 不过，有些狡猾的犯罪嫌疑人会改变某些单词的字母顺序，以逃避检查。

// 请编写一个程序，发现这种调整过顺序的关键词。

// 输入
// 程序的输入有两行，第一行是关键词列表，第二行是待检查的句子。

// 输出
// 程序的输出为在该句子中，所找到的关键词对应的原关键词，仅有一行，
// 有多个关键词时，按照关键词在句子中的顺序输出，关键词之间用一个空格分隔； 
// 如果一个关键词多次出现，则多次输出。

// 输入样例
// guns mines missiles
// aameric ssell snug dan iimsssle ot sit neeemis
// 输出样例
// guns missiles
// 知识点
// 字符数组、指针

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<string.h>

int sensitive_judge(char *s_word, char *word)
{
    int bucket[26];
    memset(bucket, 0, sizeof(bucket));
    for(int i = 0; i < strlen(s_word); i++){
        bucket[s_word[i] - 'a']++;
    }
    for(int i = 0; i < strlen(word); i++){
        bucket[word[i] - 'a']--;
    }
    int count_zero = 0;
    for(int i= 0; i < 26; i++){
        if(bucket[i] == 0) count_zero++;
    }
    return count_zero; 
}

int main()
{
    char sensitive[1000];
    gets(sensitive);
    char s_words[1000][100];
    int i = 0;
    char *token_s = strtok(sensitive, " ");
    while(token_s != NULL){
        strcpy(s_words[i++], token_s);
        token_s = strtok(NULL, " ");
    }
    char sentence[1000];
    gets(sentence);
    char words[1000][100];
    int j = 0;
    char *token = strtok(sentence, " ");
    while(token != NULL){
        strcpy(words[j++], token);
        token = strtok(NULL, " ");
    }
    for(int t = 0; t < j; t++){
        for(int k = 0; k < i; k++){
            if(sensitive_judge(s_words[k], words[t]) == 26){
                printf("%s ", s_words[k]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}