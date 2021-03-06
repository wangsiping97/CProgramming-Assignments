// 描述
// 公安人员审问甲、乙、丙、丁四个嫌疑犯，
// 已确知，这四个人当中仅有一人是偷窃者，
// 还知道这四个人的答话，要么完全诚实，要么完全说谎。
// 在回答公安人员的问话中： 
// 甲说：“乙没有偷，是丁偷的。” 
// 乙说：“我没有偷，是丙偷的。” 
// 丙说：“甲没有偷，是乙偷的。” 
// 丁说：“我没有偷，我用的那东西是我家里的。” 
// 请根据上述四人答话，判断谁是偷窃者。

// 输入
// 无输入

// 输出
// 输出小偷是谁。

// 说明：下列的样例输出仅仅是作为输出格式样例，并不一定是正确的结果。

// 输入样例

// 输出样例
// 甲
// 知识点
// 无

// 编程模式
// 无

// 难度系数
// 3

#include<stdio.h>
int main(){
    int a, b, c, d;
    int E_1, E_2, E_3, E_4;
    for(a = 0; a <= 1; a++){
        for(b = 0; b <= 1; b++){
            for(c = 0; c <= 1; c++){
                for(d = 0; d <= 1; d++){
                    E_1 = (b == 0) + (d == 1);
                    E_2 = (b == 0) + (c == 1);
                    E_3 = (a == 0) + (b == 1);
                    E_4 = (d == 0);
                    if((E_1 != 1) && (E_2 != 1) && (E_3 != 1) && (E_4 != 1)){
                        if(a == 1) printf("甲");
                        else if(b == 1) printf("乙");
                        else if(c == 1) printf("丙");
                        else if(d == 1) printf("丁");
                        else return 0;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}