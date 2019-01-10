// 描述
// 有些西方人比较迷信，如果某个月的13号正好是星期五，他们就会觉得不太吉利，用古人的说法，就是“诸事不宜”。
// 请你编写一个程序，统计出在某个特定的年份中，出现了多少次既是13号又是星期五的情形，以帮助你的迷信朋友解决难题。

// 说明：（1）一年有365天，闰年有366天，所谓闰年，即能被4整除且不能被100整除的年份，或是既能被100整除也能被400整除的年份；
// （2）已知1998年1月1日是星期四，用户输入的年份肯定大于或等于1998年。

// 输入
// 输入只有一行，即某个特定的年份（大于或等于1998年）。

// 输出
// 输出只有一行，即在这一年中，出现了多少次既是13号又是星期五的情形。

// 输入样例
// 1998
// 输出样例
// 3
// 知识点
// 算术运算、循环语句

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
#include<assert.h>

int main(){
    int y;
    scanf("%d", &y);
    assert(y >= 1998);
    // calculate the number of days past from 1998/1/1 to y/1/1
    int num_of_days_past = -365;
    for(int i = 1997; i <y; i++){
        if((i % 4 == 0 && i % 100 != 0) || (i % 100 == 0 && i % 400 == 0)){ // year i is a leap year
            num_of_days_past += 366;
        }
        else num_of_days_past += 365; // year i is a  normal year
    }
    int NormalYear[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int LeapYear[12] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    // calculate the number of days from 1998/1/1 for 13th in each month in year y
    int thirteenth_of_each_month[12];
    for(int j = 0; j < 12; j++){
        thirteenth_of_each_month[j] = num_of_days_past + 13;
    }
    for(int month = 1; month <=12; month++){
        if((y % 4 == 0 && y % 100 != 0) || (y % 100 == 0 && y % 400 == 0)){ // year y is a leap year
            LeapYear[month] += LeapYear[month -1];
            thirteenth_of_each_month[month - 1] += LeapYear[month - 1];
        }
        else{ // year y is a normal year
            NormalYear[month] += NormalYear[month - 1];
            thirteenth_of_each_month[month - 1] += NormalYear[month - 1];
        }
    }
    // check if each 13th in each month is Friday and count
    int count = 0;
    for(int i = 0; i < 12; i++){
        if(thirteenth_of_each_month[i] % 7 + 3 == 5)
        count++;
    }
    printf("%d\n", count);
    return 0;
}
