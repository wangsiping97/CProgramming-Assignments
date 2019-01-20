// 描述
// 有一个由数字0,1, 2, ..., 9组成的数字串（其对应的十进制大小不超过int的最大范围），
// 问如何将M(M ≤ 10)个加号（"+"）插入到这个数字串中，使所形成的算术表达式的值最小。
// 注意：加号不能加在数字串的最前面或最末尾，也不应有两个或两个以上的加号相邻。在测试数据中，M保证小于数字串的长度。

// 输入
// 输入只有一行，包括一个数字串和M，中间用空格隔开。

// 输出
// 输出一个整数，算术表达式的最小值。

// 输入样例
// 79846 2
// 输出样例
// 133

#include<stdio.h>
#include<assert.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int FindMin(int *a, int left, int right, int M)
{
    int merge_sum; int min = 2147483647;
    if(left == right){ // base case 1
        return a[left];
    }
    else if(M == 0){ // base case 2
        int sum = 0;
        for(int j = left; j <= right; j++){
            sum += a[j];
            sum *= 10;
        }
        sum /= 10;
        return sum;
    }
    else{ // recursion
        for(int mid = left; mid < right; mid++){
            for(int i = 0; i <= min(mid - left, M - 1); i++){
                merge_sum = FindMin(a, left, mid, i) + FindMin(a, mid + 1, right, M - 1 - i);
                if(merge_sum < min){
                    min = merge_sum;
                }
            }
        }
        return min;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    int M;
    scanf("%d", &M);
    assert(M <= 10);
    int a[20];
    int i = 0;
    while(N / 10 != 0){
        a[i++] = N % 10;
        N /= 10;
    }
    a[i++] = N % 10;
    assert(M < i);
    int mid = i / 2, temp;
    for(int j = 0; j < mid; j++){
        temp = a[j];
        a[j] = a[i - j - 1];
        a[i - j - 1] = temp;
    }
    printf("%d\n", FindMin(a, 0, i - 1, M));
    return 0;
}

