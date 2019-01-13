// 描述
// 科学家在外太空发现了一个新的星球NELLEX，上面居住着一些智能生物（外星人）。
// 经过艰苦的努力，科学家们破译了他们的一些语言文字，从而构造出了一部词典（如下所示），能够把一些简单的英文单词翻译为对方能够识别的符号。
// 请编写一个程序，利用这部词典，将一个简单的英文句子翻译为相应的NELLEX句子。

// 英文单词	      NELLEX单词
// I, WE	        !
// NELLEXIAN	    #
// HE, THEY	        &
// SHE	            $
// SAW	            %
// WENT	            >
// TO	            *
// THE   	        ^
// A	            <
// NELLEX	        ?
// PLANET	        [
// BIG	            +
// SMALL	        -
// EARTH	        "
// HAS, HAVE	    ]
// MOON	            :
// AND	            /
// IS, AM, ARE	    =
// OR	            ;

// 说明：
// （1）有些英文单词所对应的NELLEX单词是相同的，如“I”和“WE”，都对应于“!”；
// （2）输入的英文句子由一个个的单词组成，这些单词肯定出现在上述词典中，单词之间用一个空格隔开；
// （3）不用考虑单词的大小写，假设输入的都是大写字符；
// （4）由于输入的句子当中包含有空格，所以应该用gets函数来输入这个句子；
// （5）必须将新生成的NELLEX句子保存在一个字符数组中，然后再打印出来，不能一个符号一个符号地打印；
// （6）句子长度不超过100个字符。

// 输入
// 输入只有一行，即一个英文句子。

// 输出
// 输出只有一行，即翻译以后的NELLEX句子（各个符号之间不用加空格）。

// 输入样例
// NELLEX IS SMALL AND THE MOON IS BIG 
// 输出样例
// ?=-/^:=+
// 知识点
// 二维数组、字符串

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[100];
    gets(sentence);
    char *token = strtok(sentence, " ");
    char word[100][10];
    int i = 0;
    while(token){
        strcpy(word[i++], token);
        token = strtok(NULL, " ");
    }
    char Eng[24][10] = {{"I"}, {"WE"},
                        {"NELLEXIAN"}, 
                        {"HE"}, {"THEY"}, 
                        {"SHE"}, 
                        {"SAW"}, 
                        {"WENT"}, 
                        {"TO"}, 
                        {"THE"},
                        {"A"}, 
                        {"NELLEX"}, 
                        {"PLANET"}, 
                        {"BIG"}, 
                        {"SMALL"}, 
                        {"EARTH"}, 
                        {"HAS"}, {"HAVE"},
                        {"MOON"}, 
                        {"AND"}, 
                        {"IS"}, {"AM"}, {"ARE"},
                        {"OR"}};
    char Nellex[24][2] = {{"!"}, {"!"}, 
                          {"#"}, 
                          {"&"}, {"&"}, 
                          {"$"}, 
                          {"%%"}, 
                          {">"},
                          {"*"},
                          {"^"},
                          {"<"},
                          {"?"},
                          {"["},
                          {"+"},
                          {"-"},
                          {"\""},
                          {"]"}, {"]"},
                          {":"},
                          {"/"},
                          {"="}, {"="}, {"="},
                          {";"}};
    char new_sentence[200];
    for(int j = 0; j < i; j++){
        for(int k = 0; k < 24; k++){
            if(strncmp(word[j], Eng[k], 10) == 0)
            strcat(new_sentence, Nellex[k]);
        }
    }
    puts(new_sentence);
    return 0;
}