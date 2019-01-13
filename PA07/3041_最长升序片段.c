// 描述
// 输入一个字符串，然后计算它内部的最长升序片段的长度。
// 所谓升序片段，即该字母序列中的每一个字母是按照从到大顺序排列的。
// 例如，如果输入一个字符串frscrndsvnyrsgtdy，那么在这个字符串当中，有8个升序片段，即frs、cr、n、dsv、ny、rs、gt和dy。
// 显然，最长的升序片段是frs，它的长度为3。

// 说明：相同的字母也可以视为升序片段的一部分，如aab也是一个升序片段。

// 输入
// 输入一个字符串。

// 输出
// 输出最长升序片段的长度。

// 输入样例
// frscrndsvnyrsgtdy
// 输出样例
// 3
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<string.h>

int main(){
    char *str;
    gets(str);
    int l = strlen(str);
    int max_count = 1;
    int count = 1;
    for(int i = 0; i < l; i++){
        int j = i + 1;
        while(str[j] >= str[j - 1]){
            count++;
            j++;
        }
        if(count > max_count){
            max_count = count;
        }
        count = 1;
    }
    printf("%d\n", max_count);
    return 0;
}