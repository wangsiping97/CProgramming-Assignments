// 描述
// 编写一个程序，输入三位同学的考试成绩，然后计算他们的平均分。
// 在输出时，采用四舍五入的方式，只输出整数分数，不要保留小数。

// 输入
// 输入三个整数，即三位同学的成绩。

// 输出
// 输出一个整数，即三位同学的平均分。

// 输入样例
// 90 90 93
// 输出样例
// 91
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 1

#include<stdio.h>
#include<math.h>

int main(){
    int score_1, score_2, score_3;
    double mid;
    int mid_int;
    scanf("%d %d %d", &score_1, &score_2, &score_3);
    // 除法取小数部分，需预先用浮点型表示
    mid = (double)(score_1 + score_2 + score_3) / 3; 
    // 四舍五入保留整数，+ 0.5 后取整数部分即可
    mid_int = (int)(mid + 0.5);
    printf("%d\n", mid_int);
    return 0;
}