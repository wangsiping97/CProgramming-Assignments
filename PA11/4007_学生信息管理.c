// 描述
// 编写一个程序，首先根据用户的输入信息创建一条链表LA，
// 每个链表结点的内容为学生的学号（正整数），各结点之间按学号升序排列。
// 然后再根据用户的输入信息创建另一条链表LB，
// 每个链表结点包括学生的学号S和一个运算符O，O的值为“增加”或“删除”。
// 接下来，程序将对LB的每个结点进行分析，如果O的值为“增加”，则在链表LA中新增一个结点，其学号即为S；
// 如果O的值为“删除”，则在链表LA中，找到学号为S的结点并将其删除。在经过上述处理后，要求LA中的结点依然按学号升序排列。

// 说明：
// （1）在创建链表时，为了减少内存空间的浪费，必须采用 动态链表 的方法，即每一个链表结点都是根据需要动态创建的；
// （2）为了增强程序的可读性，应采用多函数的形式来实现，至少应包含如下的函数：创建链表、打印链表等。

// 输入
// 第一行是一个整数M，表示链表LA的结点个数，
// 接下来有M行，每一行是一个整数si，表示第i个结点的学号（按照从小到大排序）。
// 接下来的一行是一个整数N，表示链表LB的结点个数，
// 再接下来有N行，每一行是两个整数si和oi，
// 其中，si表示第i个结点的学号，oi表示运算符，oi=1表示“增加”结点，oi =0表示“删除”结点。

// 输出
// 输出经过处理以后的链表LA的内容。
// 假设该链表共有K个结点，则输出有K行，每一行是一个整数，即相应的学号。

// 输入样例
// 4
// 1001
// 1003
// 1005
// 1007
// 2
// 1002 1
// 1007 0
// 输出样例
// 1001
// 1002
// 1003
// 1005
// 知识点
// 结构体、指针、链表

// 编程模式
// 无

// 难度系数
// 4

#include<stdio.h>
#include<stdlib.h>

struct LA;
struct LB;
typedef struct LA *position_a;
typedef struct LB *position_b;

struct LA{
    int num;
    position_a next;
};

struct LB{
    int num;
    int o;
    position_b next;
};

struct LA *CreateLA(int N)
{
    struct LA *head = NULL;
    struct LA *p = NULL;
    for(int i = 0; i < N; i++){
        if(p == NULL){
            head = p = malloc(sizeof(struct LA));
        }
        else{
            p->next = malloc(sizeof(struct LA));
            p = p->next;
        }
        scanf("%d", &p->num);
        p->next = NULL;
    }
    return head;
}

struct LB *CreateLB(int N)
{
    struct LB *head = NULL;
    struct LB *p = NULL;
    for(int i = 0; i < N; i++){
        if(p == NULL){
            head = p = malloc(sizeof(struct LB));
        }
        else{
            p->next = malloc(sizeof(struct LB));
            p = p->next;
        }
        scanf("%d %d", &p->num, &p->o);
        p->next = NULL;
    }
    return head;
}

void RetrieveLA(struct LA *head)
{
    position_a p;
    p = head;
    while(p){
        printf("%d\n", p->num);
        p = p->next;
    }
}

void AddNode(struct LA *head, int S)
{
    position_a p, q;
    p = q = head;
    int i = 0;
    while(p->num < S){
        p = p->next;
        i++;
    }
    for(int j = 0; j < i - 1; j++){
        q = q->next;
    }
    q->next = malloc(sizeof(struct LA));
    q->next->num = S;
    q->next->next = p;
}

void DeleteNode(struct LA *head, int S)
{
    position_a p, q;
    p = q = head;
    int i = 0;
    while(p->num != S){
        p = p->next;
        i++;
    }
    for(int j = 0; j < i - 1; j++){
        q = q->next;
    }
    q->next = p->next;
    p->next = NULL;
}

int main(){
    int na, nb;
    scanf("%d", &na);
    struct LA *A = CreateLA(na);
    scanf("%d", &nb);
    struct LB *B = CreateLB(nb);
    position_b p = B;
    while(p){
        if(p->o == 1){
            AddNode(A, p->num);
        }
        if(p->o == 0){
            DeleteNode(A, p->num);
        }
        p = p->next;
    }
    RetrieveLA(A);
}