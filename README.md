# CProgramming-Assignments
Assignment codes for C Language Programming Fundamentals, Tsinghua DCST, 2018 spring.
# Contents
## PA01
- 1007_税额计算
- 1008_摄氏转华氏温度
- 1009_计算圆面积
- 1010_三人平均分
## PA02
- 1011_字符转整数
- 1014_百分制转等级分
- 2013_三数排序
- QuadraticEquation
## PA03
- 1001_寻找倍数
- 2004_第二大整数
- 2015_判断完数
- 3007_黑色星期五
## PA04
- 3015_阿尔法乘积
- 3017_阶乘尾数
- 3025_小偷是谁
## PA05
- 2003_数组逆序排列
- 2009_大小写转换
- 3026_字符串进制转换
- 3028_Anagrams问题
## PA06
- 3013_两组数据合并
- 3014_单词重写
- 3040_网格路径数据之和
## PA07
- 3009_语言翻译
- 3010_寻找鞍点
- 3041_最长升序片段
- 3046_魔方矩阵
## PA08
- 2002_字符串比较
- 3029_单词复数
- 反置数
## PA09
- 3006_数位重排列
- 3030_字符串压缩
- 3039_后缀表达式
## PA10
- 3050_奇偶分离
- 3051_矩阵相乘
- 3052_敏感词检测
- 加法运算
## PA11
- 4007_学生信息管理
- 5006_多项式加法器
## PA12
- 2020_Fibonacsi数列
- 3053_假发表达式
- 上楼问题
# Description
- For numbered questions, the first number of the number is the difficulty factor of the title.
   - eg: The difficulty of `2015_判断完数` is 2, while the difficulty of `3015_阿尔法乘积` is 3. 
- In each code file, the initial comment part includes the description of the question and corresponding requirements.
   - eg: In `1007_税额计算.c`:
```
// 描述
// 税务局希望你帮他们编写一个征税程序，该程序的功能是：
// 首先输入某公司的年销售额sale和税率rate，
// 然后程序将计算出相应的税额tax，并把它显示在屏幕上。
// 计算公式是：tax = sale * rate。

// 输入
// 输入两个实数，即销售额和税率

// 输出
// 输出只有一个实数，即税额，保留小数点后两位

#include<stdio.h>
#include<stdlib.h>

int main() {
    double sale, rate;
    double tax; 
    scanf("%lf", &sale); 
    scanf("%lf", &rate);
    tax = sale * rate;
    printf("%.2f\n", tax);
    return 0;
}
```
- If you have a better solution to some of the questions, please feel free to inform me in the comments section, or contact me directly : )
# Author
- Github: [@wangsiping97](https://github.com/wangsiping97)